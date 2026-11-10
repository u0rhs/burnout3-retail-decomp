// NONMATCHING: UpdateActiveBodyList__17CB3PhysicsManagerFv -- retail 237 / ours 236 instructions, 22 in changed runs
// a227: 22 off. decl order i,o,e fixes s-regs; D_01E65499 as 16-byte struct (lui not gp); arr local. left: st==6 slot search temp regs (retail p=a1,slots=a3,key=a0,off=a2; ours swapped), 1 instr short
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: UpdateActiveBodyList__17CB3PhysicsManagerFv -- retail 237 / ours 234 instructions, 52 in changed runs
// a162: logic-complete, 234 vs 237 instrs, 52 changed. Retail regs s3=this s2=i s0=e s1=o (ours i=s1,e=s2,o=s0; decl-order permutations did not fix) and the st==6 slot search keeps the slots base (this+0xC3B20) and &D_00522660 in regs across the loop (a3/a1) with the store address rebuilt from the offset; ours recomputes. KillProp__14CB3PropManagerFP7CB3Propb returns an int used as index into D_00522660+0x128210 (the 'v0=6' is the call result, not a constant). st==4/6/7 are explicit compares, no body-state inline here.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// CB3PhysicsManager::UpdateActiveBodyList() -- hand-written
#include "b3/GtMathPs2.h"
extern "C" int KillProp__14CB3PropManagerFP7CB3Propb(void *, void *, bool);
class UnkStruct_001B7F30_obj {
public:
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    unsigned char pad_4[0x168];
    void *field_16C;
    unsigned char pad_170[0xB0];
    void *field_220;
    unsigned char pad_224[0x2205];
    unsigned char field_2429;
};
struct UnkStruct_001B7F30_e {
    signed char field_0;
    unsigned char field_1;
    unsigned char field_2;
    int field_4;
    int field_8;
    UnkStruct_001B7F30_obj *field_C;
    u_long128 field_10;
    u_long128 field_20;
};
struct UnkStruct_001B7F30_slot {
    void *field_0;
    unsigned char pad_4[0x77C];
};
struct UnkStruct_001B7F30_lane {
    void *field_0;
    unsigned char pad_4[0x17C];
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x1771C];
    UnkStruct_001B7F30_lane field_1771C[1];
    unsigned char pad_1789C[0x110974];
    void *field_128210[1];
};
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_D_01E65499 { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_01E65499 D_01E65499;
struct UnkStruct_D_0064A860 {
    int field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_0064A854 {
    unsigned char pad_0[0x10];
};
extern UnkStruct_D_0064A860 D_0064A860;
extern UnkStruct_D_0064A854 D_0064A854;
class CB3PhysicsManager {
public:
    void UpdateActiveBodyList();
    void ExtractActiveBody(int);
    unsigned char pad_0[0x70];
    UnkStruct_001B7F30_e field_70[2448];
    int field_1CB70;
    unsigned char pad_1CB74[0xA6FAC];
    UnkStruct_001B7F30_slot field_C3B20[32];
    unsigned char pad_D2B20[0x135E0];
    void *field_E6100[67];  // 0xE6100..0xE620C
    int field_E620C;
    unsigned char pad_E6210[0x3008];
    unsigned long field_E9218;
    unsigned long field_E9220;
};
// 0x001B7F30
void CB3PhysicsManager::UpdateActiveBodyList()
{
    int i = 0;
    UnkStruct_001B7F30_obj *o;
    UnkStruct_001B7F30_e *e;
    while (i < field_1CB70) {
        e = &field_70[i];
        if (e->field_1 != 1) {
            i++;
            continue;
        }
        field_1CB70--;
        int st = e->field_0;
        if (st == 4) {
            if (D_01E65499.field_0 != 0) {
                D_00522660.field_1771C[e->field_C->field_2429].field_0 = 0;
            }
            e->field_C->vfunc_14();
            void **arr = field_E6100;
            int c = field_E620C;
            int j;
            for (j = 0; j < c; j++) {
                if (arr[j] == e->field_C) {
                    break;
                }
            }
            field_E620C--;
            field_E6100[j] = field_E6100[field_E620C];
        } else if (st == 6) {
            o = e->field_C;
            int r = KillProp__14CB3PropManagerFP7CB3Propb(&D_0064A854, o->field_220, false);
            UnkStruct_D_00522660 *const p = &D_00522660;
            void **key = &p->field_128210[D_0064A860.field_0];
            int k;
            UnkStruct_001B7F30_slot *sl = field_C3B20;
            for (k = 0; k < 32; k++) {
                if (sl[k].field_0 == key) {
                    field_C3B20[k].field_0 = &p->field_128210[r];
                    break;
                }
            }
            field_E9220 &= ~(1UL << e->field_2);
            o->vfunc_C();
        } else if (st == 7) {
            field_E9218 &= ~(1UL << e->field_2);
            e->field_C->vfunc_C();
        }
        ExtractActiveBody(i);
        int n = field_1CB70;
        if (i != n) {
            *e = field_70[n];
            if (e->field_0 == 3) {
                ((UnkStruct_001B7F30_obj *)e->field_C)->field_16C = e;
            } else if (D_01E65499.field_0 != 0 && e->field_0 == 4) {
                D_00522660.field_1771C[e->field_C->field_2429].field_0 = e;
            }
        }
    }
}
