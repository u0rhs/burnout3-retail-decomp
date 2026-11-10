// Hand-written; the lifter refused it (near3: D-pad flag 'bool a2 = v == 0 || v == 1 || v == 7;' -- MWCC lowers the == chain to the sltiu 8 / sllv / andi 0x83 bit test and keeps the bool as andi a2 of the 1).


#include "b3/GtMath.h"
struct UnkStruct_00442F10 {
    virtual void vfunc_8();
    virtual void vfunc_C(int);
    unsigned char pad_4[4];
    unsigned char field_8;
    unsigned char field_9;
    signed char field_A[0x23];
    signed char field_2D[0x23];
    float field_50[0x23];
    unsigned char pad_DC[0x4];
    int field_E0;
    unsigned char pad_E4[0x102];
    short field_1E6;
    unsigned char pad_1E8[0xA];
    unsigned short field_1F2;
    unsigned short field_1F4;
    unsigned char field_1F6;
    unsigned char pad_1F7;
    unsigned int field_1F8;
    unsigned char pad_1FC[8];
    unsigned char field_204;
};
extern "C" int lgDevRead(int, int, void *);

static inline void func_00442F10_inl1(UnkStruct_00442F10 *self)
{
        self->field_50[0x80 / 4] = GtMath::Min((float)self->field_1E6 / (float)0x7FFF, 1.0f);
        self->field_50[0x84 / 4] = GtMath::Min((float)self->field_1F2 / (float)0xFFFF, 1.0f);
        self->field_50[0x88 / 4] = GtMath::Min((float)self->field_1F4 / (float)0xFFFF, 1.0f);
}

// 0x00442F10
extern "C" void func_00442F10(UnkStruct_00442F10 *self)
{
    if (self->field_8 != 0 && (lgDevRead(self->field_E0, 1, (char *)self + 0x1E4) & 0x80000000) == 0) {
    {
        signed char *src = self->field_2D;
        signed char *dst = self->field_A;
        int n = 0x23;
        do {
            *dst = *src;
            n--;
            src++;
            dst++;
        } while (n > 0);
    }
    if (self->field_9 != 0) {
        self->field_50[0] = GtMath::Min((float)(self->field_1F8 & 0x1), 1.0f);
        self->field_50[1] = GtMath::Min((float)(self->field_1F8 & 0x2), 1.0f);
        self->field_50[2] = GtMath::Min((float)(self->field_1F8 & 0x4), 1.0f);
        self->field_50[3] = GtMath::Min((float)(self->field_1F8 & 0x8), 1.0f);
        self->field_50[4] = GtMath::Min((float)(self->field_1F8 & 0x10), 1.0f);
        self->field_50[5] = GtMath::Min((float)(self->field_1F8 & 0x20), 1.0f);
            self->field_50[6] = 0.0f;
            self->field_50[7] = 0.0f;
            self->field_50[8] = 0.0f;
            self->field_50[9] = 0.0f;
            self->field_50[10] = 0.0f;
            self->field_50[11] = 0.0f;
            self->field_50[12] = 0.0f;
            self->field_50[13] = 0.0f;
            self->field_50[14] = 0.0f;
            self->field_50[15] = 0.0f;
            self->field_50[16] = 0.0f;
            self->field_50[17] = 0.0f;
            self->field_50[18] = 0.0f;
            self->field_50[19] = 0.0f;
            self->field_50[20] = 0.0f;
            self->field_50[21] = 0.0f;
            self->field_50[22] = 0.0f;
            self->field_50[23] = 0.0f;
            self->field_50[24] = 0.0f;
            self->field_50[25] = 0.0f;
            self->field_50[26] = 0.0f;
            self->field_50[27] = 0.0f;
            self->field_50[28] = 0.0f;
            self->field_50[29] = 0.0f;
            self->field_50[30] = 0.0f;
            self->field_50[31] = 0.0f;
        func_00442F10_inl1(self);
    } else {
        self->field_50[0] = 0.0f;
        self->field_50[1] = 0.0f;
        self->field_50[2] = 0.0f;
        self->field_50[3] = 0.0f;
        self->field_50[4] = 0.0f;
        self->field_50[5] = 0.0f;
        self->field_50[6] = 0.0f;
        self->field_50[7] = 0.0f;
        self->field_50[8] = 0.0f;
        self->field_50[9] = 0.0f;
        self->field_50[10] = 0.0f;
        self->field_50[11] = 0.0f;
        self->field_50[12] = 0.0f;
        self->field_50[13] = 0.0f;
        self->field_50[14] = 0.0f;
        self->field_50[15] = 0.0f;
        self->field_50[16] = GtMath::Min((float)(self->field_1F8 & 0x20000), 1.0f);
        self->field_50[17] = GtMath::Min((float)(self->field_1F8 & 0x10000), 1.0f);
        self->field_50[18] = GtMath::Min((float)(self->field_1F8 & 0x40000), 1.0f);
        self->field_50[19] = GtMath::Min((float)(self->field_1F8 & 0x80000), 1.0f);
        self->field_50[20] = GtMath::Min((float)(self->field_1F8 & 0x100000), 1.0f);
        self->field_50[21] = GtMath::Min((float)(self->field_1F8 & 0x200000), 1.0f);
        self->field_50[22] = GtMath::Min((float)(self->field_1F8 & 0x400000), 1.0f);
        self->field_50[23] = GtMath::Min((float)(self->field_1F8 & 0x800000), 1.0f);
        self->field_50[24] = GtMath::Min((float)(self->field_1F8 & 0x1000000), 1.0f);
        self->field_50[25] = GtMath::Min((float)(self->field_1F8 & 0x2000000), 1.0f);
        self->field_50[26] = GtMath::Min((float)(self->field_1F8 & 0x4000000), 1.0f);
        self->field_50[27] = GtMath::Min((float)(self->field_1F8 & 0x8000000), 1.0f);
        unsigned int v = self->field_1F6;
        if (v == 0xFF) {
            self->field_50[(0xC0 - 0x50) / 4] = 0.0f;
            self->field_50[(0xCC - 0x50) / 4] = 0.0f;
            self->field_50[(0xC4 - 0x50) / 4] = 0.0f;
            self->field_50[(0xC8 - 0x50) / 4] = 0.0f;
        } else {
            bool a2 = v == 0 || v == 1 || v == 7;
            self->field_50[(0xC0 - 0x50) / 4] = a2 ? 1.0f : 0.0f;
            self->field_50[(0xCC - 0x50) / 4] = (unsigned int)(self->field_1F6 - 1) < 3 ? 1.0f : 0.0f;
            self->field_50[(0xC4 - 0x50) / 4] = (unsigned int)(self->field_1F6 - 3) < 3 ? 1.0f : 0.0f;
            self->field_50[(0xC8 - 0x50) / 4] = (unsigned int)(self->field_1F6 - 5) < 3 ? 1.0f : 0.0f;
        }
        func_00442F10_inl1(self);
    }
    {
        float th = 0.25f;
        int one = 1;
        int i = 0;
        do {
            int r = one;
            if (self->field_50[i] <= th) r = 0;
            self->field_2D[i] = r;
            i++;
        } while (i < 0x23);
    }
    if (self->field_204 != 0) {
        self->vfunc_C(1);
    }
    }
}
