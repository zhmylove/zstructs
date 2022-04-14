/* Embeddable and simplified version of pst.c */
/* Each level of trie takes 2k = 256 * sizeof(void*) * sizeof(char) bytes */
#ifndef __EPST
#define __EPST

/* Mangle identifiers */
#define __M(x) _703855738_##x
#define _NOMANGLE_
#define __EPST_CALLOC ((epst_t*)calloc(1, sizeof(epst_t)))

/* For free(), calloc(), NULL */
#include <stdlib.h>

/* Typedef for trie */
typedef struct __M(epst) {
    struct __M(epst) *leaves[sizeof(char) * 256];
} _NOMANGLE_ epst_t;

/* Constructors */
_NOMANGLE_
static inline epst_t* epst_create(void) { return __EPST_CALLOC; }

/* All-in-one function */
static inline void* __M(epst_op)(epst_t *root, char *key, void *val, int set) {
    epst_t *prev;
    if (!root || !key || !*key)
        return NULL;
    for (; root && *key; key++) {
        prev = root;
        root = root->leaves[(unsigned char)*key];
        if (!root) {
            if (!set || !(root = __EPST_CALLOC))
                return NULL;
            prev->leaves[(unsigned char)*key] = root;
        }
    }
    return set ? root->leaves[0] = val : root->leaves[0];
}

/* Decorators */
_NOMANGLE_
static inline void* epst_set(epst_t *root, char *key, void *val) {
    return __M(epst_op)(root, key, val, 1);
}
_NOMANGLE_
static inline void* epst_get(epst_t *root, char *key) {
    return __M(epst_op)(root, key, NULL, 0);
}
_NOMANGLE_
static inline void* epst_del(epst_t *root, char *key) {
    return __M(epst_op)(root, key, NULL, 1);
}

/* Destructor */
_NOMANGLE_
static inline void epst_destroy(epst_t *root) {
    unsigned int i;
    if (!root)
        return;
    for (i = 1; i < sizeof(char) * 256; epst_destroy(root->leaves[i++]));
    free(root);
    return;
}

#undef __EPST_CALLOC
#undef __M
#undef _NOMANGLE_
#endif /* __EPST */
