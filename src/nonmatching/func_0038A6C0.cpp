// NONMATCHING: func_0038A6C0 -- retail 274 / ours 274 instructions, 160 in changed runs
// a151 CB3OnlineSingleRaceLogic::Update [L]: 274/274 instrs, logic + jump table + registers exact (9-case FSM, vcall via cast, state==8 as 'case 8: default: break' + trailing return). Only the D_0064EA70 -> D_01EA07D4 record copy (case 7, written as a struct assignment 'D_01EA07D4 = *p', no pad members) differs in load/store scheduling (160 changed): the same copy as func_00390D70 (archived, same note). The struct assignment reproduces retail's first 8-field order (8,C,0,2,4,10,14,18) and the int[8] 4x8-byte loop exactly; the 38-field tail's load order differs (ours 3C,48,4C,40,50,54,44.. vs retail 3C,48,40,50,44,4C,84,58). Hill-climbing memberwise statement orders (token-edit-distance objective) stalled at ~140/207.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00 { unsigned char pad_0[0x10]; };
struct UnkStruct_Arr8 { int v[8]; };
struct UnkStruct_00390D70_rec {
    short field_0;
    short field_2;
    int field_4;
    int field_8;
    float field_C;
    float field_10;
    int field_14;
    int field_18;
    UnkStruct_Arr8 field_1C;
    float field_3C;
    int field_40;
    int field_44;
    float field_48;
    int field_4C;
    float field_50;
    float field_54;
    float field_58;
    float field_5C;
    float field_60;
    float field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    unsigned char field_94;
    unsigned char field_95;
    int field_98;
    int field_9C;
    unsigned char field_A0;
    unsigned char field_A1;
    unsigned char field_A2;
    int field_A4;
    int field_A8;
    float field_AC;
    float field_B0;
    float field_B4;
    float field_B8;
    float field_BC;
    float field_C0;
    float field_C4;
};
extern UnkStruct_D_00 D_01E32AE0;
extern UnkStruct_D_int D_01E32B08;
extern UnkStruct_00390D70_rec D_0064EA70;
extern UnkStruct_00390D70_rec D_01EA07D4;
struct UnkStruct_D_sc { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_uc { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_00516E40 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_004F50C0 { unsigned char pad_0[0x10]; };
struct UnkStruct_0038A6C0 {
    unsigned char pad_0[0x60];
    int field_60;
};
extern UnkStruct_D_00 D_01E7A888;
extern UnkStruct_D_uc D_0064FB79;
extern UnkStruct_D_sc D_004F6061;
extern UnkStruct_D_00516E40 D_00516E40;
extern UnkStruct_D_004F50C0 D_004F50C0;
extern "C" void func_0026FAA0(void *, int);
extern "C" void func_003FA600(void *, int);
extern "C" int func_00391B80(void *, int, int);
extern "C" int UpdateLaunch__19CB3OnlineStageLogicFv(void *);
extern "C" void func_00391B20(void *);
extern "C" int AmIHost__17CB3NetworkManagerFv(void *);
extern "C" int func_00391820(void *);
extern "C" int func_003916D0(void *);
extern "C" int func_00391630(void *);
extern "C" int func_003914A0(void *);
extern "C" void func_003906F0(void *);
extern "C" int func_00390380(void *);
extern "C" int func_003910B0(void *, int);

// 0x0038A6C0
extern "C" void func_0038A6C0(UnkStruct_0038A6C0 * self)
{
    func_0026FAA0(&D_01E32AE0, 0);
    switch (self->field_60) {
    case 0:
        self->field_60 = 1;
        break;
    case 1:
        func_003FA600(&D_01E7A888, 4);
        if (func_00391B80(self, 1, 0) != 0) {
            self->field_60 = 2;
        }
        break;
    case 2:
        if (UpdateLaunch__19CB3OnlineStageLogicFv(self) != 0) {
            func_00391B20(self);
            if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) {
                self->field_60 = 3;
            } else {
                self->field_60 = 4;
            }
        }
        break;
    case 3:
        if (func_00391820(self) != 0) {
            self->field_60 = 5;
        }
        break;
    case 4:
        if (func_003916D0(self) != 0) {
            self->field_60 = 5;
        }
        break;
    case 5:
        func_00391630(self);
        break;
    case 6:
        func_003FA600(&D_01E7A888, 5);
        if (func_003914A0(self) != 0) {
            ((UnkStruct_D_00516E40 *)&D_00516E40)->vfunc_14(18, 0);
            D_0064FB79.field_0 = 1;
            func_003906F0(self);
            self->field_60 = 7;
        } else {
            func_00390380(self);
        }
        break;
    case 7: {
        int k = D_004F6061.field_0 * 15;
        *(short *)((char *)&D_004F50C0 + (k + k * 4) * 4 + 0xD8E) = 0;
        if (func_003910B0(self, k) != 0) {
            const UnkStruct_00390D70_rec * const p = &D_0064EA70;
            D_01EA07D4 = *p;
            self->field_60 = 8;
        }
        break;
    }
    case 8:
    default:
        break;
    }
    return;
}
