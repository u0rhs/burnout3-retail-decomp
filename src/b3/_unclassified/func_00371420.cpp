// Hand-written; the lifter refused it (early status test as switch(s){case 2:case 0:return 0;default:break;}).

#include "b3/_unclassified/GtRandom.h"
struct UnkStruct_71420_file {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(long, int); virtual void vfunc_14();
    virtual void vfunc_18(long, int); virtual void vfunc_1C(); virtual void vfunc_20(); virtual int vfunc_24();
};
struct UnkStruct_71420_dict { unsigned char pad_0[0x8]; int field_8; };
struct UnkStruct_71420_row { unsigned char pad_0[0x8]; int field_8; int field_C; };
struct UnkStruct_71420 {
    UnkStruct_71420_row field_0[1];
    unsigned char pad_10[0x6B4];
    int field_6C4;
    unsigned char pad_6C8[0x40];
    UnkStruct_71420_dict *field_708;
    void *field_70C;
    UnkStruct_71420_file *field_710;
    signed char field_714;
    signed char field_715;
};
struct UnkStruct_D_00518680 { CGtRandom r; unsigned char pad[0x100]; };
struct UnkStruct_D_004F60C0 { void *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00518680 D_00518680;
extern UnkStruct_D_004F60C0 D_004F60C0;
extern char D_004C8200[];
extern "C" UnkStruct_71420_file *Open__13CGTFileSystemFPCcUi(void *, const char *, unsigned int);
extern "C" void FixUp__17CGtDictionaryBaseFv(void *);
extern "C" void FixUp__10CGtTextureFv(void *);
extern "C" void *func_00131AA0(void *, int);
// 0x00371420
extern "C" int func_00371420(UnkStruct_71420 * self)
{
    if (self->field_710 != 0) {
        int s = self->field_710->vfunc_24();
        switch (s) {
        case 2:
        case 0:
            return 0;
        default:
            break;
        }
    }
    switch (self->field_6C4) {
    case 0:
        self->field_710 = Open__13CGTFileSystemFPCcUi(D_004F60C0.field_0, D_004C8200, 0x11);
        if (self->field_710 != 0) self->field_6C4 = 1;
        break;
    case 1:
        if (self->field_715 == -1) {
            self->field_715 = D_00518680.r.Random() % self->field_714;
        }
        signed char t = self->field_715 + 1;
        self->field_715 = t;
        if (t == self->field_714) self->field_715 = 0;
        self->field_710->vfunc_18((long)(self->field_0[self->field_715].field_C + 0x800), 0);
        self->field_6C4 = 2;
        break;
    case 2:
        self->field_710->vfunc_10((long)(int)self->field_708, self->field_0[self->field_715].field_8);
        self->field_6C4 = 3;
        break;
    case 3: {
        self->field_710->vfunc_C();
        self->field_710 = 0;
        UnkStruct_71420_dict *d = self->field_708;
        FixUp__17CGtDictionaryBaseFv(d);
        for (int i = 0; i < d->field_8; i++) {
            FixUp__10CGtTextureFv(func_00131AA0(d, i));
        }
        self->field_70C = func_00131AA0(d, 0);
        self->field_6C4 = 0;
        return 1;
    }
    }
    return 0;
}
