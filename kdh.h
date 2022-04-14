#ifndef __KDH_INCLUDED
#define __KDH_INCLUDED

// Read this code with xkdh.c (eXtentions for k-D hash)
// Original purpose: put some objects into k-D spatial hash index and get
// pointers to them by their k-D coordinates.

#include <stdint.h>

#ifndef __KDH_INTERNAL

typedef struct kdh_root kdh_root_t;
extern kdh_root_t* kdh_create(uint64_t width, uint64_t height);
extern void kdh_destroy(kdh_root_t **root);
extern void* kdh_insert(kdh_root_t *root, uint64_t x, uint64_t y, void *value);
extern void* kdh_remove(kdh_root_t *root, uint64_t x, uint64_t y, void *value);

#else // __KDH_INTERNAL
#include <stdlib.h>
#include <sys/types.h>

// This header is probably missing on Windows and in musl libc...
// May be we should bundle it into the project tree?
#include <sys/queue.h>

// =========================================================
// USER-DEFINED PARAMETER
// Number of chunks per bucket. All but last chunks are ptrs to real data
// unless NULL. The last one is listhead unless NULL.
#define KDH_CHUNKS 8
#if KDH_CHUNKS < 2
#error KDH_CHUNKS should be greater than 2
#endif
#define KDH_LIST_CHUNK (KDH_CHUNKS - 1)

// =========================================================
// USER-DEFINED PARAMETER
// Just if we want to print the debug info
//#define __KDH_DEBUG
#ifdef __KDH_DEBUG
#include <stdio.h>
#define D(num) (fprintf(stderr, "D: %d\n", num))
#else
#define D(num)
#endif // __KDH_DEBUG

// is: list entry structure: ptr is pointer to object in k-D
typedef struct listentry {
    LIST_ENTRY(listentry) entries;
    void *ptr;
} listentry_t;

// is: list head structure
typedef LIST_HEAD(listhead, listentry) listhead_t;

// is: union for sizeof macro
typedef union chunk {
    void *ptr;          // same as in listentry, but directly in hash table
    listhead_t list;    // last element in chunks[] is listhead unless NULL
} chunk_t;

// is: bucket. Consists of array of chunks. The last one is list head
typedef struct bucket {
    chunk_t chunks[KDH_CHUNKS];
} bucket_t;

// is: KDH descriptor (actually 2D hash of lists)
// The initial intention had been to implement k-D here, but this was 
// considered quite ineffectve. So only 2-D hash here.
// Justification: each index operation would result into huge amount of 
// math operation with dynamic-lenght arrays.
// Plase mind reading xkdh (x3dh_create) for further info.
typedef struct kdh_root {
    uint64_t width;
    uint64_t height;
    bucket_t* buckets;
} kdh_root_t;

// is: KDH constructor
// r: ptr to new KDH
kdh_root_t* kdh_create(uint64_t width, uint64_t height);

// is: KDH destructor
void kdh_destroy(kdh_root_t **root);

// is: add smth to KDH
// r: value or NULL
void* kdh_insert(kdh_root_t *root, uint64_t x, uint64_t y, void *value);

// is: remove smth to KDH
// r: value or NULL
void* kdh_remove(kdh_root_t *root, uint64_t x, uint64_t y, void *value);

// is: hash function for bucket selection
static inline uint64_t __kdh_hash(kdh_root_t *root, uint64_t x, uint64_t y);

#endif /* __KDH_INTERNAL */
#endif /* __KDH_INCLUDED */
