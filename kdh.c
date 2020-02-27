#define __KDH_INTERNAL
#include "kdh.h"

kdh_root_t* kdh_create(uint64_t width, uint64_t height) {
    kdh_root_t* rc;

    if ((rc = malloc(sizeof(kdh_root_t))) == NULL) {
        D(801); // unable to allocate memory
        return NULL;
    }

    if ((rc->buckets = calloc(1, width * height * sizeof(bucket_t))) == NULL) {
        D(802); // unable to allocate memory
        return NULL;
    }

    rc->width = width;
    rc->height = height;

    // Extra (not needed) level of initialization
    uint64_t i;
    for (i = 0; i < width * height; i++) {
        LIST_INIT(&rc->buckets[i].chunks[KDH_LIST_CHUNK].list);
    }

    D(101); // create: success
    return rc;
}

void kdh_destroy(kdh_root_t **rootp) {
    kdh_root_t* root = *rootp;

    if (root == NULL) {
        D(901); // NPE
        return;
    }

    uint64_t i;
    listhead_t* curr_head;
    listentry_t* curr_entry;
    for (i = 0; i < root->width * root->height; i++) {
        curr_head = &root->buckets[i].chunks[KDH_LIST_CHUNK].list;
        while (!LIST_EMPTY(curr_head)) {
            curr_entry = LIST_FIRST(curr_head);
            LIST_REMOVE(curr_entry, entries);
            free(curr_entry);
        }
    }
    free(root->buckets);
    free(root);

    // Prevent segfault after kdh destroy
    *rootp = NULL;
    D(102); // destroy: success
    return;
}

void* kdh_insert(kdh_root_t *root, uint64_t x, uint64_t y, void *value) {
    if (root == NULL) {
        D(900); // NPE
        return NULL;
    }

    if (value == NULL) {
        D(903); // we MUST NOT insert NULLs
        return NULL;
    }

    bucket_t* bucket = root->buckets + __kdh_hash(root, x, y);

    uint64_t i;
    for (i = 0; i < KDH_LIST_CHUNK; i++) {
        if (bucket->chunks[i].ptr != NULL) {
            continue;
        }

        bucket->chunks[i].ptr = value;
        D(105); // insert: success into pre-allocated
        return value;
    }

    // i should be equal to KDH_LIST_CHUNK
    if (i != KDH_LIST_CHUNK) {
        D(1000); // something went wrong
        return NULL;
    }

    listhead_t* chunk = &bucket->chunks[i].list;
    listentry_t* entry;
    if ((entry = malloc(sizeof(listentry_t))) == NULL) {
        D(800); // unable to allocate memory
        return NULL;
    }

    entry->ptr = value;
    LIST_INSERT_HEAD(chunk, entry, entries);

    D(103); // insert: success to list
    return value;
}

void* kdh_remove(kdh_root_t *root, uint64_t x, uint64_t y, void *value) {
    uint64_t i, deleting = KDH_CHUNKS;
    bucket_t* bucket;
    listhead_t* chunk;
    listentry_t* entry;
    listentry_t* curr;

    if (root == NULL) {
        D(902); // NPE
        return NULL;
    }

    if (value == NULL) {
        D(904); // we MUST NOT insert NULLs
        return NULL;
    }

    bucket = root->buckets + __kdh_hash(root, x, y);

    for (i = 0; i < KDH_LIST_CHUNK; i++) {
        if (bucket->chunks[i].ptr == NULL) {
            D(405); // trying to remove non-existent object, LIST empty
            return NULL;
        }

        if (bucket->chunks[i].ptr != value) {
            continue; // The only way to break this for()
        }

        // We found value to remove.
        // save ID for this value and move last element to it's place
        deleting = i;

        // Find last element ptr, remove it from old location
        // either LIST or chunks[] and place it in bucket->chunks[deleting]

        chunk = &bucket->chunks[KDH_LIST_CHUNK].list;

        // If LIST is empty, we have to use (KDH_LIST_CHUNK - 1)
        if (LIST_EMPTY(chunk)) {
            // Find last not NULL id in chunks[]
            for(i = KDH_LIST_CHUNK - 1; bucket->chunks[i].ptr == NULL; i--);

            if (i < deleting) {
                D(1003); // possibly a bug here
                return NULL;
            } else if (i == deleting) {
                // Removing last element in chunks[], so no copy needed
                bucket->chunks[deleting].ptr = NULL;
                D(106); // remove: success last from chunks[]
                return value;
            }

            bucket->chunks[deleting].ptr = bucket->chunks[i].ptr;
            bucket->chunks[i].ptr = NULL;
            D(107); // remove: success not last from chunks[]
            return value;
        }

        // LIST is not empty, so we have to take any element from LIST,
        // put it instead of bucket->chunks[deleting], and LIST_REMOVE/free
        entry = LIST_FIRST(chunk);
        bucket->chunks[deleting].ptr = entry->ptr;
        LIST_REMOVE(entry, entries);
        free(entry);

        D(108); // remove: success from chunks[] and LIST
        return value;
    }

    // We didn't find value in chunks[], so it could be in LIST or missing.

    // i should be equal to KDH_LIST_CHUNK
    if (i != KDH_LIST_CHUNK) {
        D(1001); // something went wrong
        return NULL;
    }

    chunk = &bucket->chunks[i].list;
    entry = NULL;
    curr = NULL;

    LIST_FOREACH(curr, chunk, entries) {
        if (curr->ptr == value) {
            entry = curr;
            break;
        }
    }

    if (entry == NULL) {
        D(404); // trying to remove non-existent object
        return NULL;
    }

    LIST_REMOVE(entry, entries);
    free(entry);

    D(104); // remove: success absolutely from LIST
    return value;
}

static inline uint64_t __kdh_hash(kdh_root_t *root, uint64_t x, uint64_t y) {
    return root->width * (y % root->height) + (x % root->width);
}
