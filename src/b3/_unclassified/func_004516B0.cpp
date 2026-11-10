// Hand-written; the lifter refused it (near28: call result in its own idx local before the byte store (no andi/dsll32); third loop with its own counter j; declarations i, n, j, k, obj, id at the top).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_P16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_byte { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_byte D_01E65499;
extern UnkStruct_D_byte D_01ECDAC9;
extern UnkStruct_D_byte D_0051BA3B;
extern UnkStruct_D_int D_01E32B08;
extern UnkStruct_P16 D_01E32AE0;
extern UnkStruct_P16 D_004EE040;
extern signed char D_004E1E70[8];  // [G] element count: gp-relative, so at most 8 bytes
extern int D_01EA4B80[];  // [G] element count unknown
struct UnkStruct_004516B0_vo {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual void vfunc_D8();
    virtual void vfunc_DC();
    virtual void vfunc_E0();
    virtual void vfunc_E4();
    virtual void vfunc_E8();
    virtual void vfunc_EC();
    virtual int vfunc_F0();
};
struct UnkStruct_004516B0_pad { unsigned char pad_0[0x1B4]; UnkStruct_004516B0_vo *field_1B4; };
struct UnkStruct_D_0051BA88 { UnkStruct_004516B0_pad *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051BA88 D_0051BA88;
struct UnkStruct_004516B0_rec { unsigned char pad_0[0x44]; int field_44; };
struct UnkStruct_004516B0_frame { CGtV2d field_0; };
struct UnkStruct_004516B0_row {
    unsigned char pad_0[8];
    UnkStruct_004516B0_frame *field_8;
    unsigned char pad_C[0x18];
};
struct UnkStruct_004516B0 {
    unsigned char pad_0[0xC];
    UnkStruct_004516B0_row field_C[8];
    unsigned char pad_12C[8];
    int field_134;
    int field_138;
    unsigned char pad_13C[0xC1];
    unsigned char field_1FD;
};
extern "C" void func_00453560(void *);
extern "C" void func_00451950(void *, int, int, int);
extern "C" void *func_002366D0(void *, int);
extern "C" int func_0022FBB0(void *);
extern "C" UnkStruct_004516B0_rec *GetPlayerRecordByID__17CB3NetworkManagerFi(void *, int);
extern "C" int GetMyPlayerID__23CGtNetworkPlayerManagerCFv(const void *);
extern "C" int func_003900E0(UnkStruct_004516B0_vo *, int, int);
typedef int (*UnkFn_004516B0)(void *);

static inline void func_004516B0_inl1(UnkStruct_004516B0 *self, int from, int to, float base, float stride, float x)
{
    if (from != to) {
        float cnt = (float)(to - from - 1);
        float y = 0.0f + base - 0.5f * (cnt * stride);
        int i;
        for (i = from; i < to; i++) {
            self->field_C[i].field_8->field_0 = CGtV2d(x, y);
            y += stride;
        }
    }
}

// 0x004516B0
extern "C" int func_004516B0(UnkStruct_004516B0 *self)
{
    int i;
    int n;
    int j;
    int k;
    UnkStruct_004516B0_vo *obj;
    int id;
    func_00453560(self);
    unsigned char online = D_01E65499.field_0;
    if (online)
        n = D_01E32B08.field_0;
    else
        n = D_0051BA3B.field_0;
    self->field_134 = 2;
    self->field_1FD = 1;
    if (D_01ECDAC9.field_0 != 0)
        n = n / 2;
    if (online) {
        for (i = 0; i < n; i++) {
            func_00451950(self, self->field_138, i, D_004E1E70[i]);
            self->field_138 = self->field_138 + 1;
        }
    } else {
        for (i = 0; i < n; i++) {
            func_00451950(self, self->field_138, i, *((signed char *)&D_004EE040 + i + 0x2D9F0));
            self->field_138 = self->field_138 + 1;
        }
    }
    if (online) {
        obj = D_0051BA88.field_0->field_1B4;
        for (j = 0; j < n; j++) {
            void *p = func_002366D0(&D_01E32AE0, j);
            if (p != 0) {
                id = func_0022FBB0(p);
                UnkStruct_004516B0_rec *rec = GetPlayerRecordByID__17CB3NetworkManagerFi(&D_01E32AE0, id);
                if (rec != 0) {
                    k = rec->field_44;
                    if (k < 0)
                        k = D_01EA4B80[j];
                } else {
                    k = D_01EA4B80[j];
                }
            } else {
                id = GetMyPlayerID__23CGtNetworkPlayerManagerCFv(&D_01E32AE0);
                k = obj->vfunc_F0();
            }
            int idx = func_003900E0(obj, k, id);
            D_004E1E70[idx] = j;
        }
    }
    func_004516B0_inl1(self, 0, self->field_138, 232.0f, 38.0f, 0.0f);
    return 1;
}
