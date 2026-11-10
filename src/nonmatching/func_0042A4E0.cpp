// NONMATCHING: func_0042A4E0 -- retail 693 / ours 695 instructions, 240 in changed runs
// draftF: 693/695; calls, block layout, saved registers (s0-s2, self in s2) identical; states 0/1 exact except one ori; residue only in the tilt block (0x42A9C0..0x42ADE8): CGtV2d operator- lane order, CreateRotationMatrix3x4 by-value axis copy (lq+qmtc2 vs lqc2), mPos.SetZ placement around the inlined op*, op* result copy level (frame 0x6C0 vs 0x9F0)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: every branch, call and store accounted for; the three D_00522660 access forms (car pointer, combined-constant id/byte, folded-symbol id) reproduced [G] as written

// func_0042A4E0 -- hand-written (draftF) from the retail asm and the Ghidra draft. [L] CB3CarViewComponent::UpdateLoadState()
// (research/proto/new_names.csv, medium; DNAT B3CarViewComponent.cpp); placeholder name kept, types [G].
// Shape [C asm]: field_94 is the load state. 0: if the wanted car id (field_88) is not already in slot field_9C, take the other
// slot (field_9D = (field_9C + 1) % 2), set its car id, copy field_90 into the car, state 1. 1: release a slot whose id changed,
// wait for the car (vfunc_8 at the car's +0x1910 vtable), then register its two ValueDB floats (mass, max speed in boost) under
// "../Export/ValueDB/VehiclePhysics/<name>.cfg", reset its matrix (optionally tilted by the slope between two body points), set the
// view distance / height / target from its box, and swap the slots.
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;

extern "C" float atanf(float);
extern "C" int sprintf(char *, const char *, ...);

struct UnkStruct_0042A4E0_body {          // car->field_40 [G]
    unsigned char pad_0[0xD];
    signed char field_D;
    unsigned char pad_E[0x6];
    float field_14;
    float field_18;
    unsigned char pad_1C[0xB94];
    CGtV3d field_BB0;
    unsigned char pad_BC0[0x70];
    CGtV3d field_C30;
    unsigned char pad_C40[0x240];
    CGtV3d field_E80;
    CGtV3d field_E90;
};
struct UnkStruct_0042A4E0_car;
struct UnkStruct_0042A4E0_vt {
    unsigned char pad_0[0x8];
    int (*vfunc_8)(UnkStruct_0042A4E0_car *);
    unsigned char pad_C[0x4];
    void (*vfunc_10)(UnkStruct_0042A4E0_car *);
};
// one 0x2460-byte element of the array at D_00522660 + 0x12FCF0 (a CB3RaceCar: SetCarID is called on it [L])
struct UnkStruct_0042A4E0_car {
    CGtMatrix3x4 field_0;
    UnkStruct_0042A4E0_body * field_40;
    unsigned char pad_44[0x15];
    signed char field_59;
    unsigned char pad_5A[0x2];
    float field_5C;
    float field_60[8];
    unsigned char pad_80[0x4D0];
    float field_550;
    unsigned char pad_554[0x4];
    float field_558;
    unsigned char pad_55C[0x13B4];
    UnkStruct_0042A4E0_vt * field_1910;
    unsigned char pad_1914[0x4C];
    unsigned long field_1960;
    unsigned char pad_1968[0x2460 - 0x1968];
};
struct UnkStruct_0042A4E0_vdb { float field_0; float field_4; };
struct UnkStruct_0042A4E0 {
    unsigned char pad_0[0x10];
    UnkStruct_0042A4E0_vdb field_10[2];
    unsigned char pad_20[0x40];
    CGtV3d field_60;
    float field_70;
    float field_74;
    float field_78;
    unsigned char pad_7C[0xC];
    unsigned long field_88;
    signed char field_90;
    unsigned char pad_91[0x3];
    int field_94;
    int field_98;
    signed char field_9C;
    signed char field_9D;
    signed char field_9E;
    unsigned char pad_9F[0x35];
    unsigned char field_D4;
};
struct UnkStruct_0042A4E0_id { unsigned long field_0; unsigned char pad_8[0x2460 - 8]; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x12FCF0]; UnkStruct_0042A4E0_car field_12FCF0[1]; };   // [G] element count unknown
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_0042A4E0_id D_00653CB0[];
extern int mpToolBase__Q27GtComms16CGtCommsToolBase;
extern char D_004D1600[];
extern char D_004D1628[];
extern char D_004D1640[];
extern char D_004D1650[];
extern char D_004D1670[];
extern unsigned char D_01E7A800[];
extern unsigned char D_01E8EC30[];
extern "C" void SetCarID__10CB3RaceCarFUl(UnkStruct_0042A4E0_car *, unsigned long);
extern "C" void func_002842A0(void *);
extern "C" void func_0021AB40(unsigned long, char *);
extern "C" void RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(int, void *);
extern "C" void AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(int, void *, void *, void *, char *, int, int, float, float);
extern "C" int func_0042BC70(void *);
extern "C" int func_0042B5F0(void *, int);

// [G] unregisters one slot's two ValueDB floats (retail keeps self + 8*index in a saved register across both calls: an inline
// taking the index)
static inline void func_0042A4E0_inl1(UnkStruct_0042A4E0 * self, int i)
{
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, &self->field_10[i].field_0);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, &self->field_10[i].field_4);
}

#define CAR(i) (&D_00522660.field_12FCF0[i])
// [G] the car's vfunc_10 (retail computes the car address once for the vptr load and this)
static inline void func_0042A4E0_inl2(UnkStruct_0042A4E0_car * c) { c->field_1910->vfunc_10(c); }
// [G] byte-offset forms: retail adds the element offset first and folds the member offset into one %hi/%lo constant at these
// sites (car id at +0x1960 = 0x131650, byte +0x59 = 0x12FD49), unlike the car pointers above (lui/ori at) and the vdb id read
#define CARID(i) (*(unsigned long *)((char *)&D_00522660 + (i) * 0x2460 + 0x131650))
#define CAR59(i) (*((signed char *)&D_00522660 + (i) * 0x2460 + 0x12FD49))

// 0x0042A4E0
extern "C" void func_0042A4E0(UnkStruct_0042A4E0 * self)
{
    switch (self->field_94) {
    case 0:
        if (self->field_88 != CARID(self->field_9C)) {
            self->field_9D = (self->field_9C + 1) % 2;
            SetCarID__10CB3RaceCarFUl(CAR(self->field_9D), self->field_88);
            CAR59(self->field_9D) = self->field_90;
            self->field_94 = 1;
            self->field_98 = 3;
            func_002842A0(D_01E7A800);
        }
        break;
    case 1: {
        if (self->field_88 != CARID(self->field_9D)) {
            if (CARID(self->field_9D) != 0) {
                func_0042A4E0_inl1(self, self->field_9D);
                func_0042A4E0_inl2(CAR(self->field_9D));
                SetCarID__10CB3RaceCarFUl(CAR(self->field_9D), (unsigned long)-1);
            }
            if (self->field_88 == CARID(self->field_9C)) {
                self->field_94 = 0;
                self->field_98 = 1;
                self->field_9D = -1;
                break;
            }
            SetCarID__10CB3RaceCarFUl(CAR(self->field_9D), self->field_88);
        }
        UnkStruct_0042A4E0_car * car = CAR(self->field_9D);
        if (CARID(self->field_9D) == 0) {
            if (!self->field_D4) {
                if (self->field_98 != 0)
                    return;
                self->field_98 = 1;
            }
            if (self->field_9E != -1) {
                func_0042A4E0_inl1(self, self->field_9E);
                func_0042A4E0_inl2(CAR(self->field_9E));
                SetCarID__10CB3RaceCarFUl(CAR(self->field_9E), (unsigned long)-1);
                self->field_9E = -1;
            }
            self->field_9C = self->field_9D;
            self->field_9E = -1;
            self->field_9D = -1;
            self->field_94 = 0;
            break;
        }
        if (!car->field_1910->vfunc_8(car))
            return;
        car = CAR(self->field_9D);
        if (!self->field_D4) {
            if (self->field_98 != 0)
                return;
            self->field_98 = 1;
        }
        if (self->field_9E != -1) {
            func_0042A4E0_inl1(self, self->field_9E);
            func_0042A4E0_inl2(CAR(self->field_9E));
            self->field_9E = -1;
        }
        {
            int j = self->field_9D;
            char name[16];
            char file[0x130];
            func_0021AB40(CAR(j)->field_1960, name);
            sprintf(file, D_004D1600, name);
            AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, &self->field_10[j].field_0, D_004D1628, D_004D1640, file, 0, 0, 0.0f, 0.0f);
            AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, &self->field_10[j].field_4, D_004D1650, D_004D1670, file, 0, 0, 0.0f, 0.0f);
        }
        car->field_0.mPos.Zero();
        car->field_5C = 0.625f;
        car->field_60[0] = 0.4956515f;
        car->field_60[1] = -0.1862765f;
        car->field_60[2] = 0.3f;
        car->field_60[3] = 0.29375f;
        car->field_60[4] = -0.1703813f;
        car->field_60[5] = -0.1570656f;
        car->field_60[6] = -0.2375f;
        car->field_60[7] = 0.13125f;
        UnkStruct_0042A4E0_body * p = car->field_40;
        float y = p->field_18;
        if (p->field_D > 2 && car->field_550 < car->field_558) {
            CGtV2d a(p->field_BB0.Z(), car->field_550);
            CGtV2d b(p->field_C30.Z(), car->field_558);
            CGtV2d d = a - b;
            float ang = -(57.29578f * atanf(d.Y() / d.X()));
            CGtMatrix3x4 r = CreateRotationMatrix3x4(car->field_0.mRight, 0.017453292f * ang);
            car->field_0.mPos.SetZ(-b.X());
            car->field_0 = car->field_0 * r;
            car->field_0.mPos.SetZ(0.0f);
            float t = a.X() / d.X() * d.Y();
            y = y + t;
        }
        car->field_0.mPos.SetY(y);
        self->field_9C = self->field_9D;
        self->field_9E = self->field_9D;
        self->field_9D = -1;
        if (!self->field_D4)
            self->field_78 = 180.0f;
        else
            self->field_78 = 0.0f;
        CGtV3d size = car->field_40->field_E80 - car->field_40->field_E90;
        self->field_70 = size.Y() * 0.9f;
        self->field_60 = size * 0.2f;
        self->field_60.SetX(0.0f);
        self->field_60.SetZ(0.0f);
        float dist = 2.8f * car->field_40->field_14;
        self->field_74 = dist;
        if (dist > 8.0f && dist < 12.0f)
            self->field_74 = 8.0f;
        if (!self->field_D4) {
            int k = func_0042B5F0(D_01E8EC30, func_0042BC70(D_01E8EC30));
            if (self->field_9E > -1)
                CAR59(self->field_9E) = k;
        }
        self->field_94 = 0;
        break;
    }
    }
}
