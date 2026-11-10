// Hand-written; the lifter refused it (dead p[] store kept: separate local arrays, p[i] read back after the store (forwarded); compares written val[b] > val[a]).

#include "b3/classes/UnkStruct_D_01ECD520.h"
extern UnkStruct_D_01ECD520 D_01ECD520;
extern "C" void *func_00420FE0(UnkStruct_D_01ECD520 *, int);
extern "C" float func_0013A560(unsigned int *, void *);
struct UnkStruct_004480E0_p { unsigned char pad_0[0x49B]; signed char field_49B; };

// 0x004480E0
// [C] dead-code shape: p[i] stored, then read back through p[i] (retail keeps the store, the reads are forwarded)
extern "C" int func_004480E0()
{
    unsigned char fl[3];
    unsigned int tmp;
    UnkStruct_004480E0_p *p[3];
    unsigned int val[3];
    int i;
    int r;
    for (i = 0; i < 3; i++) {
        p[i] = (UnkStruct_004480E0_p *)func_00420FE0(&D_01ECD520, i);
        fl[i] = p[i]->field_49B != 0;
        func_0013A560(&tmp, p[i]);
        val[i] = tmp;
    }
    if (fl[0]) {
        if (fl[1]) {
            if (fl[2]) r = 0; else r = 2;
        } else if (fl[2]) {
            r = 1;
        } else {
            if (val[2] > val[1]) r = 2; else r = 1;
        }
    } else if (fl[1]) {
        if (fl[2]) r = 0;
        else { if (val[2] > val[0]) r = 2; else r = 0; }
    } else if (fl[2]) {
        if (val[1] > val[0]) r = 1; else r = 0;
    } else if (val[2] > val[1]) {
        if (val[2] > val[0]) r = 2; else r = 0;
    } else {
        if (val[1] > val[0]) r = 1; else r = 0;
    }
    return r;
}
