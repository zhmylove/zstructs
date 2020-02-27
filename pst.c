#define __T_INTERNAL
#include "pst.h"

// will be undefined at the end
#define __T_CALLOC ((pst_node_t*)calloc(1, sizeof(struct t_node)))

static void _t_hash_init() {
#ifndef __T_NOHASH
    unsigned char _t_ok = 0;
#define _T_OK (_t_ok++)
#define _T_NOT (__T_VOCAB_LEN)
    _t_hash_values[0]   =  _T_OK ; // \0
    _t_hash_values[1]   =  _T_NOT; // (forbidden)
    _t_hash_values[2]   =  _T_NOT; // (forbidden)
    _t_hash_values[3]   =  _T_NOT; // (forbidden)
    _t_hash_values[4]   =  _T_NOT; // (forbidden)
    _t_hash_values[5]   =  _T_NOT; // (forbidden)
    _t_hash_values[6]   =  _T_NOT; // (forbidden)
    _t_hash_values[7]   =  _T_NOT; // (forbidden)
    _t_hash_values[8]   =  _T_NOT; // (forbidden)
    _t_hash_values[9]   =  _T_NOT; // (forbidden)
    _t_hash_values[10]  =  _T_NOT; // (forbidden)
    _t_hash_values[11]  =  _T_NOT; // (forbidden)
    _t_hash_values[12]  =  _T_NOT; // (forbidden)
    _t_hash_values[13]  =  _T_NOT; // (forbidden)
    _t_hash_values[14]  =  _T_NOT; // (forbidden)
    _t_hash_values[15]  =  _T_NOT; // (forbidden)
    _t_hash_values[16]  =  _T_NOT; // (forbidden)
    _t_hash_values[17]  =  _T_NOT; // (forbidden)
    _t_hash_values[18]  =  _T_NOT; // (forbidden)
    _t_hash_values[19]  =  _T_NOT; // (forbidden)
    _t_hash_values[20]  =  _T_NOT; // (forbidden)
    _t_hash_values[21]  =  _T_NOT; // (forbidden)
    _t_hash_values[22]  =  _T_NOT; // (forbidden)
    _t_hash_values[23]  =  _T_NOT; // (forbidden)
    _t_hash_values[24]  =  _T_NOT; // (forbidden)
    _t_hash_values[25]  =  _T_NOT; // (forbidden)
    _t_hash_values[26]  =  _T_NOT; // (forbidden)
    _t_hash_values[27]  =  _T_NOT; // (forbidden)
    _t_hash_values[28]  =  _T_NOT; // (forbidden)
    _t_hash_values[29]  =  _T_NOT; // (forbidden)
    _t_hash_values[30]  =  _T_NOT; // (forbidden)
    _t_hash_values[31]  =  _T_NOT; // (forbidden)
    _t_hash_values[32]  =  _T_NOT; // (forbidden)
    _t_hash_values[33]  =  _T_NOT; // (forbidden)
    _t_hash_values[34]  =  _T_NOT; // (forbidden)
    _t_hash_values[35]  =  _T_NOT; // (forbidden)
    _t_hash_values[36]  =  _T_NOT; // (forbidden)
    _t_hash_values[37]  =  _T_NOT; // (forbidden)
    _t_hash_values[38]  =  _T_NOT; // (forbidden)
    _t_hash_values[39]  =  _T_NOT; // (forbidden)
    _t_hash_values[40]  =  _T_NOT; // (forbidden)
    _t_hash_values[41]  =  _T_NOT; // (forbidden)
    _t_hash_values[42]  =  _T_NOT; // (forbidden)
    _t_hash_values[43]  =  _T_NOT; // (forbidden)
    _t_hash_values[44]  =  _T_NOT; // (forbidden)
    _t_hash_values[45]  =  _T_OK ; // -
    _t_hash_values[46]  =  _T_NOT; // (forbidden)
    _t_hash_values[47]  =  _T_NOT; // (forbidden)
    _t_hash_values[48]  =  _T_OK ; // 0
    _t_hash_values[49]  =  _T_OK ; // 1
    _t_hash_values[50]  =  _T_OK ; // 2
    _t_hash_values[51]  =  _T_OK ; // 3
    _t_hash_values[52]  =  _T_OK ; // 4
    _t_hash_values[53]  =  _T_OK ; // 5
    _t_hash_values[54]  =  _T_OK ; // 6
    _t_hash_values[55]  =  _T_OK ; // 7
    _t_hash_values[56]  =  _T_OK ; // 8
    _t_hash_values[57]  =  _T_OK ; // 9
    _t_hash_values[58]  =  _T_NOT; // (forbidden)
    _t_hash_values[59]  =  _T_NOT; // (forbidden)
    _t_hash_values[60]  =  _T_NOT; // (forbidden)
    _t_hash_values[61]  =  _T_NOT; // (forbidden)
    _t_hash_values[62]  =  _T_NOT; // (forbidden)
    _t_hash_values[63]  =  _T_NOT; // (forbidden)
    _t_hash_values[64]  =  _T_NOT; // (forbidden)
    _t_hash_values[65]  =  _T_OK ; // A
    _t_hash_values[66]  =  _T_OK ; // B
    _t_hash_values[67]  =  _T_OK ; // C
    _t_hash_values[68]  =  _T_OK ; // D
    _t_hash_values[69]  =  _T_OK ; // E
    _t_hash_values[70]  =  _T_OK ; // F
    _t_hash_values[71]  =  _T_OK ; // G
    _t_hash_values[72]  =  _T_OK ; // H
    _t_hash_values[73]  =  _T_OK ; // I
    _t_hash_values[74]  =  _T_OK ; // J
    _t_hash_values[75]  =  _T_OK ; // K
    _t_hash_values[76]  =  _T_OK ; // L
    _t_hash_values[77]  =  _T_OK ; // M
    _t_hash_values[78]  =  _T_OK ; // N
    _t_hash_values[79]  =  _T_OK ; // O
    _t_hash_values[80]  =  _T_OK ; // P
    _t_hash_values[81]  =  _T_OK ; // Q
    _t_hash_values[82]  =  _T_OK ; // R
    _t_hash_values[83]  =  _T_OK ; // S
    _t_hash_values[84]  =  _T_OK ; // T
    _t_hash_values[85]  =  _T_OK ; // U
    _t_hash_values[86]  =  _T_OK ; // V
    _t_hash_values[87]  =  _T_OK ; // W
    _t_hash_values[88]  =  _T_OK ; // X
    _t_hash_values[89]  =  _T_OK ; // Y
    _t_hash_values[90]  =  _T_OK ; // Z
    _t_hash_values[91]  =  _T_NOT; // (forbidden)
    _t_hash_values[92]  =  _T_NOT; // (forbidden)
    _t_hash_values[93]  =  _T_NOT; // (forbidden)
    _t_hash_values[94]  =  _T_NOT; // (forbidden)
    _t_hash_values[95]  =  _T_OK ; // _
    _t_hash_values[96]  =  _T_NOT; // (forbidden)
    _t_hash_values[97]  =  _T_OK ; // a
    _t_hash_values[98]  =  _T_OK ; // b
    _t_hash_values[99]  =  _T_OK ; // c
    _t_hash_values[100] =  _T_OK ; // d
    _t_hash_values[101] =  _T_OK ; // e
    _t_hash_values[102] =  _T_OK ; // f
    _t_hash_values[103] =  _T_OK ; // g
    _t_hash_values[104] =  _T_OK ; // h
    _t_hash_values[105] =  _T_OK ; // i
    _t_hash_values[106] =  _T_OK ; // j
    _t_hash_values[107] =  _T_OK ; // k
    _t_hash_values[108] =  _T_OK ; // l
    _t_hash_values[109] =  _T_OK ; // m
    _t_hash_values[110] =  _T_OK ; // n
    _t_hash_values[111] =  _T_OK ; // o
    _t_hash_values[112] =  _T_OK ; // p
    _t_hash_values[113] =  _T_OK ; // q
    _t_hash_values[114] =  _T_OK ; // r
    _t_hash_values[115] =  _T_OK ; // s
    _t_hash_values[116] =  _T_OK ; // t
    _t_hash_values[117] =  _T_OK ; // u
    _t_hash_values[118] =  _T_OK ; // v
    _t_hash_values[119] =  _T_OK ; // w
    _t_hash_values[120] =  _T_OK ; // x
    _t_hash_values[121] =  _T_OK ; // y
    _t_hash_values[122] =  _T_OK ; // z
    _t_hash_values[123] =  _T_NOT; // (forbidden)
    _t_hash_values[124] =  _T_NOT; // (forbidden)
    _t_hash_values[125] =  _T_NOT; // (forbidden)
    _t_hash_values[126] =  _T_NOT; // (forbidden)
    _t_hash_values[127] =  _T_NOT; // (forbidden)
    _t_hash_values[128] =  _T_NOT; // (forbidden)
    _t_hash_values[129] =  _T_NOT; // (forbidden)
    _t_hash_values[130] =  _T_NOT; // (forbidden)
    _t_hash_values[131] =  _T_NOT; // (forbidden)
    _t_hash_values[132] =  _T_NOT; // (forbidden)
    _t_hash_values[133] =  _T_NOT; // (forbidden)
    _t_hash_values[134] =  _T_NOT; // (forbidden)
    _t_hash_values[135] =  _T_NOT; // (forbidden)
    _t_hash_values[136] =  _T_NOT; // (forbidden)
    _t_hash_values[137] =  _T_NOT; // (forbidden)
    _t_hash_values[138] =  _T_NOT; // (forbidden)
    _t_hash_values[139] =  _T_NOT; // (forbidden)
    _t_hash_values[140] =  _T_NOT; // (forbidden)
    _t_hash_values[141] =  _T_NOT; // (forbidden)
    _t_hash_values[142] =  _T_NOT; // (forbidden)
    _t_hash_values[143] =  _T_NOT; // (forbidden)
    _t_hash_values[144] =  _T_NOT; // (forbidden)
    _t_hash_values[145] =  _T_NOT; // (forbidden)
    _t_hash_values[146] =  _T_NOT; // (forbidden)
    _t_hash_values[147] =  _T_NOT; // (forbidden)
    _t_hash_values[148] =  _T_NOT; // (forbidden)
    _t_hash_values[149] =  _T_NOT; // (forbidden)
    _t_hash_values[150] =  _T_NOT; // (forbidden)
    _t_hash_values[151] =  _T_NOT; // (forbidden)
    _t_hash_values[152] =  _T_NOT; // (forbidden)
    _t_hash_values[153] =  _T_NOT; // (forbidden)
    _t_hash_values[154] =  _T_NOT; // (forbidden)
    _t_hash_values[155] =  _T_NOT; // (forbidden)
    _t_hash_values[156] =  _T_NOT; // (forbidden)
    _t_hash_values[157] =  _T_NOT; // (forbidden)
    _t_hash_values[158] =  _T_NOT; // (forbidden)
    _t_hash_values[159] =  _T_NOT; // (forbidden)
    _t_hash_values[160] =  _T_NOT; // (forbidden)
    _t_hash_values[161] =  _T_NOT; // (forbidden)
    _t_hash_values[162] =  _T_NOT; // (forbidden)
    _t_hash_values[163] =  _T_NOT; // (forbidden)
    _t_hash_values[164] =  _T_NOT; // (forbidden)
    _t_hash_values[165] =  _T_NOT; // (forbidden)
    _t_hash_values[166] =  _T_NOT; // (forbidden)
    _t_hash_values[167] =  _T_NOT; // (forbidden)
    _t_hash_values[168] =  _T_NOT; // (forbidden)
    _t_hash_values[169] =  _T_NOT; // (forbidden)
    _t_hash_values[170] =  _T_NOT; // (forbidden)
    _t_hash_values[171] =  _T_NOT; // (forbidden)
    _t_hash_values[172] =  _T_NOT; // (forbidden)
    _t_hash_values[173] =  _T_NOT; // (forbidden)
    _t_hash_values[174] =  _T_NOT; // (forbidden)
    _t_hash_values[175] =  _T_NOT; // (forbidden)
    _t_hash_values[176] =  _T_NOT; // (forbidden)
    _t_hash_values[177] =  _T_NOT; // (forbidden)
    _t_hash_values[178] =  _T_NOT; // (forbidden)
    _t_hash_values[179] =  _T_NOT; // (forbidden)
    _t_hash_values[180] =  _T_NOT; // (forbidden)
    _t_hash_values[181] =  _T_NOT; // (forbidden)
    _t_hash_values[182] =  _T_NOT; // (forbidden)
    _t_hash_values[183] =  _T_NOT; // (forbidden)
    _t_hash_values[184] =  _T_NOT; // (forbidden)
    _t_hash_values[185] =  _T_NOT; // (forbidden)
    _t_hash_values[186] =  _T_NOT; // (forbidden)
    _t_hash_values[187] =  _T_NOT; // (forbidden)
    _t_hash_values[188] =  _T_NOT; // (forbidden)
    _t_hash_values[189] =  _T_NOT; // (forbidden)
    _t_hash_values[190] =  _T_NOT; // (forbidden)
    _t_hash_values[191] =  _T_NOT; // (forbidden)
    _t_hash_values[192] =  _T_NOT; // (forbidden)
    _t_hash_values[193] =  _T_NOT; // (forbidden)
    _t_hash_values[194] =  _T_NOT; // (forbidden)
    _t_hash_values[195] =  _T_NOT; // (forbidden)
    _t_hash_values[196] =  _T_NOT; // (forbidden)
    _t_hash_values[197] =  _T_NOT; // (forbidden)
    _t_hash_values[198] =  _T_NOT; // (forbidden)
    _t_hash_values[199] =  _T_NOT; // (forbidden)
    _t_hash_values[200] =  _T_NOT; // (forbidden)
    _t_hash_values[201] =  _T_NOT; // (forbidden)
    _t_hash_values[202] =  _T_NOT; // (forbidden)
    _t_hash_values[203] =  _T_NOT; // (forbidden)
    _t_hash_values[204] =  _T_NOT; // (forbidden)
    _t_hash_values[205] =  _T_NOT; // (forbidden)
    _t_hash_values[206] =  _T_NOT; // (forbidden)
    _t_hash_values[207] =  _T_NOT; // (forbidden)
    _t_hash_values[208] =  _T_NOT; // (forbidden)
    _t_hash_values[209] =  _T_NOT; // (forbidden)
    _t_hash_values[210] =  _T_NOT; // (forbidden)
    _t_hash_values[211] =  _T_NOT; // (forbidden)
    _t_hash_values[212] =  _T_NOT; // (forbidden)
    _t_hash_values[213] =  _T_NOT; // (forbidden)
    _t_hash_values[214] =  _T_NOT; // (forbidden)
    _t_hash_values[215] =  _T_NOT; // (forbidden)
    _t_hash_values[216] =  _T_NOT; // (forbidden)
    _t_hash_values[217] =  _T_NOT; // (forbidden)
    _t_hash_values[218] =  _T_NOT; // (forbidden)
    _t_hash_values[219] =  _T_NOT; // (forbidden)
    _t_hash_values[220] =  _T_NOT; // (forbidden)
    _t_hash_values[221] =  _T_NOT; // (forbidden)
    _t_hash_values[222] =  _T_NOT; // (forbidden)
    _t_hash_values[223] =  _T_NOT; // (forbidden)
    _t_hash_values[224] =  _T_NOT; // (forbidden)
    _t_hash_values[225] =  _T_NOT; // (forbidden)
    _t_hash_values[226] =  _T_NOT; // (forbidden)
    _t_hash_values[227] =  _T_NOT; // (forbidden)
    _t_hash_values[228] =  _T_NOT; // (forbidden)
    _t_hash_values[229] =  _T_NOT; // (forbidden)
    _t_hash_values[230] =  _T_NOT; // (forbidden)
    _t_hash_values[231] =  _T_NOT; // (forbidden)
    _t_hash_values[232] =  _T_NOT; // (forbidden)
    _t_hash_values[233] =  _T_NOT; // (forbidden)
    _t_hash_values[234] =  _T_NOT; // (forbidden)
    _t_hash_values[235] =  _T_NOT; // (forbidden)
    _t_hash_values[236] =  _T_NOT; // (forbidden)
    _t_hash_values[237] =  _T_NOT; // (forbidden)
    _t_hash_values[238] =  _T_NOT; // (forbidden)
    _t_hash_values[239] =  _T_NOT; // (forbidden)
    _t_hash_values[240] =  _T_NOT; // (forbidden)
    _t_hash_values[241] =  _T_NOT; // (forbidden)
    _t_hash_values[242] =  _T_NOT; // (forbidden)
    _t_hash_values[243] =  _T_NOT; // (forbidden)
    _t_hash_values[244] =  _T_NOT; // (forbidden)
    _t_hash_values[245] =  _T_NOT; // (forbidden)
    _t_hash_values[246] =  _T_NOT; // (forbidden)
    _t_hash_values[247] =  _T_NOT; // (forbidden)
    _t_hash_values[248] =  _T_NOT; // (forbidden)
    _t_hash_values[249] =  _T_NOT; // (forbidden)
    _t_hash_values[250] =  _T_NOT; // (forbidden)
    _t_hash_values[251] =  _T_NOT; // (forbidden)
    _t_hash_values[252] =  _T_NOT; // (forbidden)
    _t_hash_values[253] =  _T_NOT; // (forbidden)
    _t_hash_values[254] =  _T_NOT; // (forbidden)
    _t_hash_values[255] =  _T_NOT; // (forbidden)
#undef _T_OK
#undef _T_NOT
#endif // __T_NOHASH
    _t_hash_ready = 1;
}

#ifndef __T_NOHASH
static inline unsigned char _t_hash(register char chr) {
    return _t_hash_values[(unsigned char)chr];
}
#endif // __T_NOHASH

extern pst_node_t* pst_create() {
    if (!_t_hash_ready) {
        _t_hash_init();
    }

    return __T_CALLOC;
}

static void __t_destructor(pst_node_t *root, char with_data) {
    // Let it be recursive for now
    int i;

    if (root == NULL) {
        return;
    }

    if (with_data && root->_t_leaves[0]) {
        free(root->_t_leaves[0]);
    }

    for (i = 1; i < __T_VOCAB_LEN; i++) {
        if (root->_t_leaves[i]) {
            __t_destructor(root->_t_leaves[i], with_data);
        }

        // Total clean-up
        root->_t_leaves[i] = NULL;
    }

    free(root);
}

void pst_destroy(pst_node_t *root) {
    __t_destructor(root, 0);
}

void pst_destroy_with_data(pst_node_t *root) {
    __t_destructor(root, 1);
}

static pst_node_t* __t_op(pst_node_t *root, __t_op_t op, char *key, void *val) {
    pst_node_t* prev;

    if (root == NULL || op == TOP_NOP) {
        D(998); // ARG CHECK
        return NULL;
    }

    switch (op) {
        case TOP_LKP:
        case TOP_ADD:
        case TOP_SET:
        case TOP_REM:
            if (key == NULL || *key == 0) {
                D(997); // ARG CHECK
                return NULL;
            }

            for (; root != NULL && *key != 0; key++) {
                if (_t_hash(*key) == __T_VOCAB_LEN) {
                    D(996); // INVALID KEY HASH
                    return NULL;
                }

                prev = root;
                root = root->_t_leaves[_t_hash(*key)];

                if (root == NULL) {
                    if (op == TOP_LKP || op == TOP_REM) {
                        D(101); // ENTRY NOT FOUND
                        return NULL;
                    } else if (op == TOP_ADD || op == TOP_SET) {
                        if ((root = __T_CALLOC) == NULL) {
                            D(999); // UNABLE TO ALLOC
                            return NULL;
                        }
                        prev->_t_leaves[_t_hash(*key)] = root;
                    } else {
                        D(1000); // OP NOT FOUND
                        return NULL;
                    }
                }
            }

            if (*key != 0) { // Must not be due to auto-allocation
                D(2000); // UNHANDLED PART
                return NULL;
            } else { // key exists
                switch(op) {
                    case TOP_LKP:
                        D(50); // LOOKUP SUCCESS
                        return root->_t_leaves[0];
                    case TOP_ADD:
                        if (root->_t_leaves[0]) {
                            D(103); // UNABLE TO OVERWRITE
                            return NULL;
                        }
                    case TOP_SET:
                        D(51); // SET SUCCESS
                        return root->_t_leaves[0] = val;
                    case TOP_REM:
                        prev = root->_t_leaves[0];
                        root->_t_leaves[0] = NULL;
                        D(52); // REMOVE SUCCESS
                        return prev;
                    default:
                        D(1003); // IMPOSSIBLE OP HERE
                        return NULL;
                }
            }
        default:
            D(1002); // OP NOT FOUND
            return NULL;
    }

    D(1001); // REACHED FATAL POINT
    return NULL;
}

pst_node_t* pst_lookup(pst_node_t *root, char *key) {
    return __t_op(root, TOP_LKP, key, NULL);
}

pst_node_t* pst_add(pst_node_t *root, char *key, void *val) {
    return __t_op(root, TOP_ADD, key, val);
}

pst_node_t* pst_set(pst_node_t *root, char *key, void *val) {
    return __t_op(root, TOP_SET, key, val);
}

pst_node_t* pst_remove(pst_node_t *root, char *key) {
    return __t_op(root, TOP_REM, key, NULL);
}

#undef __T_CALLOC
