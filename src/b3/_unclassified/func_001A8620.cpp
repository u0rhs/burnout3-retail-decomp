// Hand-written; the lifter refused it (found arm ends in 'return;' (no else): retail's out-of-line |=0x40 block + relay b).

#include "b3/classes/UnkStruct_D_0064D37C.h"

struct UnkStruct_001A8620_p {
    unsigned char pad_0[0x1914];
    int field_1914;
};

struct UnkStruct_001A8620_s {
    unsigned char pad_0[0x2D];
    unsigned char field_2D;
};

extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_001A8620_p * D_0064D388[];

// 0x001A8620
extern "C" void func_001A8620(UnkStruct_001A8620_s * self, unsigned char * p1, unsigned char * p2, int p3)
{
    int one = 1;
    bool tr = true;
    int i;
    int k;
    unsigned char r;
    int j;
    for (i = 0; i < 5; i++) {
        unsigned char bit = 1 << i;
        if ((bit & p1[p3]) == bit) {
            r = 0;
            break;
        }
        if ((bit & p2[p3]) == bit) {
            r = one;
            break;
        }
    }
    if (i < 5) {
        self->field_2D = p3;
        self->field_2D |= (unsigned char)((unsigned char)i << 3);
        if (r) {
            self->field_2D |= 0x40;
        }
        return;
    }
    int n = D_0064D37C.field_0;
    for (j = 0; j < 5; j++) {
        unsigned char bit = 1 << j;
        for (k = 0; k < n; k++) {
            if (k == p3) continue;
            if (D_0064D388[k]->field_1914 != 2) continue;
            if ((bit & p1[k]) == bit) {
                r = 0;
                break;
            }
            if ((bit & p2[k]) != bit) continue;
            r = tr;
            break;
        }
    }
    if (j < 5) {
        self->field_2D = k;
        self->field_2D |= (unsigned char)((unsigned char)j << 3);
        if (r) {
            self->field_2D |= 0x40;
        }
        return;
    }
    self->field_2D = 0;
    self->field_2D = self->field_2D | 0x28;
}
