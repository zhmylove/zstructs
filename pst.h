#ifndef __T_INCLUDED
#define __T_INCLUDED

#ifndef __T_INTERNAL

typedef struct t_node pst_node_t;
extern pst_node_t* pst_create(void);
extern void* pst_lookup(pst_node_t *root, char *key);
extern void* pst_add(pst_node_t *root, char *key, void *val);
extern void* pst_set(pst_node_t *root, char *key, void *val);
extern void* pst_remove(pst_node_t *root, char *key);
extern void pst_destroy(pst_node_t *root);
extern void pst_destroy_with_data(pst_node_t *root);

#else // __T_INTERNAL
#include <stdlib.h>
#include <sys/types.h>

// =========================================================
// USER-DEFINED PARAMETER, see below /Price
//#define __T_NOHASH
// This option is useful only on lookup/add >= 5 and
// intensive lookup operations. Use it only
// if you want to avoid excessive CPU cache fill on hashing.
// Price: memory consumption x4 and decreased performance on
// multiple insertions due to calloc's bzero()
#ifdef __T_NOHASH
#define _t_hash(x) ((unsigned char)(x))
//static inline unsigned char _t_hash(register char chr);
#else // __T_NOHASH
// r: key characters hashing function
static inline unsigned char _t_hash(register char chr);
#endif // __T_NOHASH

// =========================================================
// USER-DEFINED PARAMETER
// Just if we want to print the debug info
//#define __T_DEBUG
#ifdef __T_DEBUG
#include <stdio.h>
#define D(num) (fprintf(stderr, "D: %d\n", num))
#else
#define D(num)
#endif // __T_DEBUG

// m/[a-zA-Z0-9-_\0]/
// [a-zA-Z0-9-_\0] = 26 + 26 + 10 + 3 = 65
// 65 * 8 = 520 bytes per layer
// each layer size is 520 ** layer_depth
// _t_leaves[0] points to data due to 0 is for \0 in key (see _t_hash())
#ifndef __T_NOHASH
#define __T_VOCAB_LEN 65
#else
#define __T_VOCAB_LEN 256 // number of `char' values
#endif // __T_NOHASH

// is: node with leaves
typedef struct t_node {
    struct t_node* _t_leaves[__T_VOCAB_LEN];
} pst_node_t;

// is: fast hash algo for keys hashing
unsigned char _t_hash_values[256];
// is: global variable for initialization
static volatile unsigned char _t_hash_ready = 0;

// is: array initializer
static void _t_hash_init(void);

// r: ptr to new _t_
pst_node_t* pst_create(void);

// is: tree destructors
void pst_destroy(pst_node_t *root);
void pst_destroy_with_data(pst_node_t *root);
static void __t_destructor(pst_node_t *root, char with_data);

typedef enum __t_op {
    TOP_NOP,
    TOP_LKP,
    TOP_ADD,
    TOP_SET,
    TOP_REM,
    TOP_SIZE
} __t_op_t;

// is: internal function to implement CRUD
static pst_node_t* __t_op(pst_node_t *root, __t_op_t op, char *key, void *val);

// r: ptr to data || NULL
pst_node_t* pst_lookup(pst_node_t *root, char *key);

// r: val || NULL, thus no need to insert NULLs :)
pst_node_t* pst_add(pst_node_t *root, char *key, void *val);

// is: just like add, but replace if exists(key)
pst_node_t* pst_set(pst_node_t *root, char *key, void *val);

// r: val(!) || NULL, don't try to remove NULLs :)
// !!! this implementation doesn't call free() implicitly and must not
pst_node_t* pst_remove(pst_node_t *root, char *key);

#endif /* __T_INTERNAL */
#endif /* __T_INCLUDED */
