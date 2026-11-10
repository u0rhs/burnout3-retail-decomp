// Hand-written; the lifter refused it (a115: find unique lowest-field_10D4 car; early return on ==2; RELOC only on splat const D_0012AD28 (a107)).

#include "b3/classes/UnkStruct_D_0064D37C.h"

struct UnkStruct_0038BD30_car {
    unsigned char pad_0[0x10C8];
    int field_10C8;
    unsigned char pad_10CC[0x8];
    int field_10D4;
    unsigned char pad_10D8[0x83C];
    int field_1914;
    unsigned char pad_1918[0x80];
    unsigned char field_1998;
};

struct UnkStruct_0038BD30_tbl {
    UnkStruct_0038BD30_car * field_0[1];
    unsigned char pad_4[0xC];
};

struct UnkStruct_0038BD30_g {
    unsigned char pad_0[0x12AD28];
    UnkStruct_0038BD30_car * field_12AD28[1];
};

struct UnkStruct_0038BD30_p {
    unsigned char pad_0[0x4C];
    int field_4C;
};

struct UnkStruct_0038BD30_a {
    unsigned char pad_0[0x10];
};

extern UnkStruct_0038BD30_g D_00522660;
extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_0038BD30_tbl D_0064D388;
extern UnkStruct_0038BD30_a D_01E7A800;
extern "C" void func_0038BB70(void *, UnkStruct_0038BD30_car *);
extern "C" void func_00284AA0(void *);

// 0x0038BD30
extern "C" void func_0038BD30(UnkStruct_0038BD30_p * self, UnkStruct_0038BD30_car * p0)
{
    if (p0->field_10C8 == 2) return;
    {
        int best = 0x7FFFFFFF;
        int cnt = 0;
        int idx = -1;
        for (int i = 0; i < D_0064D37C.field_0; i++) {
            UnkStruct_0038BD30_car * c = D_00522660.field_12AD28[i];
            if (c->field_1998 != 0) {
                int v = c->field_10D4;
                if (v < best) {
                    best = v;
                    cnt = 1;
                    idx = i;
                } else if (v == best) {
                    cnt++;
                }
            }
        }
        if (cnt == 1) {
            func_0038BB70(self, D_0064D388.field_0[idx]);
        }
        if (p0->field_1914 == 0) {
            func_00284AA0(&D_01E7A800);
        }
    }
}
