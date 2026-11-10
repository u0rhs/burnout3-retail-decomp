// Hand-written; the lifter refused it (s323: clone of func_0039FD90 (s323) minus the track-ID block; const pun on D_004E2918).

#include "b3/classes/CB3InputManager.h"
#include "b3/classes/EB3MenuFlowFSMEvents.h"
#include "b3/classes/UnkStruct_D_01E90240.h"

union UnkUnion_003A0050_p8 { long l; struct { int lo; int hi; } s; };
struct UnkStruct_003A0050_f0 {
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x4];
    int field_14;
    unsigned int field_18;
    unsigned int field_1C;
    int field_20;
    int field_24;
    int field_28;
};
struct UnkStruct_003A0050 {
    unsigned char pad_0[0x4];
    unsigned short field_4;
    unsigned char pad_6[0xE];
    unsigned char field_14;
    unsigned char pad_15[0x3];
    unsigned char * field_18;
    unsigned char pad_1C[0xD4];
    UnkStruct_003A0050_f0 * field_F0;
    unsigned char pad_F4[0x2C];
    long field_120[0xB8];
    unsigned char pad_6E0[0x4];
    int field_6E4;
    int field_6E8;
    int field_6EC;
    int field_6F0;
    int field_6F4;
    unsigned char pad_6F8[0x9];
    unsigned char field_701;
    unsigned char field_702;
};
static inline int func_003A0050_inl(UnkStruct_003A0050 * self)
{
    int i = self->field_6E4;
    unsigned char * p = self->field_18;
    if (p == 0 || i < 0 || self->field_14 < i) return 0;
    return p[i];
}
static inline int func_003A0050_inl2(UnkStruct_003A0050 * self)
{
    int i = self->field_6E4;
    unsigned char * p = self->field_18;
    if (p == 0 || i < 0 || i > self->field_14) return 0;
    return p[i];
}
struct UnkStruct_003A0050_a4 { unsigned char pad_0[0xC4]; int field_C4[1]; };
struct UnkStruct_003A0050_a8 { unsigned char pad_0[0x218]; long field_218[1]; };
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;
extern unsigned char D_004E2918;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);
extern "C" int func_00319330(void *);
extern "C" int func_00319360(void *);
extern "C" void func_0039F490(void *);

// 0x003A0050
extern "C" void func_003A0050(UnkStruct_003A0050 * self)
{
    if (D_004F50C0.GetMenuConfirm(0)) {
        if (func_003A0050_inl2(self) == 0) {
            self->field_701 = self->field_6E8 == 0;
            self->field_702 = self->field_6EC == 0;
            self->field_F0->field_14 = self->field_6E4;
            {
                UnkStruct_003A0050_f0 * q = self->field_F0;
                UnkUnion_003A0050_p8 a;
                a.l = self->field_120[self->field_6EC];
                q->field_C = a.s.lo;
                q->field_20 = a.s.hi;
            }
            {
                int v0 = self->field_6F0;
                UnkStruct_003A0050_f0 * q = self->field_F0;
                q->field_1C &= 0x00FFFFFF;
                q->field_1C |= v0 << 24;
            }
            {
                int idx = self->field_6F4;
                int w = ((int *)((char *)self + 0xC4))[idx];
                UnkStruct_003A0050_f0 * q = self->field_F0;
                q->field_1C &= 0xFFFF00FF;
                q->field_1C |= w << 8;
            }
            {
                unsigned int t = *(const unsigned char *)&D_004E2918;  // [G] const pun (as func_0039FA70)
                UnkStruct_003A0050_f0 * q = self->field_F0;
                q->field_18 &= 0x00FFFFFF;
                q->field_18 |= t << 24;
            }
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
            return;
        }
    }
    if (D_004F50C0.GetMenuBack(0)) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        return;
    }
    if (func_003A0050_inl2(self) == 0) {
        if (D_004F50C0.GetMenuUp(0) && func_00319360((char *)self + 4)) return;
        if (D_004F50C0.GetMenuDown(0) && func_00319330((char *)self + 4)) return;
    }
    if (*((unsigned char *)self + self->field_4 * 20 + 0x16) != 0) return;
    if (D_004F50C0.GetMenuLeft(0)) goto go;
    if (!D_004F50C0.GetMenuRight(0)) return;
go:
    func_0039F490(self);
}
