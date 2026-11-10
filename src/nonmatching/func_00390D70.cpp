// NONMATCHING: func_00390D70 -- retail 207 / ours 207 instructions, 184 in changed runs
// a151 [L] (state-sync check for online stage logic, twin of the copy in CB3OnlineSingleRaceLogic::Update): 207/207 instrs, logic exact; 184 changed = the 46-field D_0064EA70 -> D_01EA07D4 record copy written as a struct assignment ('const rec *const p = &D_0064EA70; D_01EA07D4 = *p;', no pad members, int[8] as a struct member). Reproduces retail's first 8-field order and the 4x8-byte int[8] loop exactly; the 38-field tail after it schedules differently (ours 3C,48,4C,40,50,54,44,58.. vs retail 3C,48,40,50,44,4C,84,58). Earlier memberwise form (separate extern per dest, natural order) was 175 changed; retail-store-order 213; random/greedy search plateaued.
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
extern "C" void func_0026FAA0(void *, int);
extern "C" void * func_002366D0(void *, int);
extern "C" float GetTimeSinceLastPacketArrived__16CB3NetworkPlayerCFv(void *);
extern "C" int func_0022FBB0(void *);
extern "C" void * GetPlayerRecordByID__17CB3NetworkManagerFi(void *, int);

// 0x00390D70
extern "C" int func_00390D70(void *a0 /* passed by every caller, not read here */)
{
    func_0026FAA0(&D_01E32AE0, 0);
    bool ok = true;
    int n = D_01E32B08.field_0;
    for (int i = 0; i < n; i++) {
        void * pl = func_002366D0(&D_01E32AE0, i);
        if (pl != 0) {
            if (GetTimeSinceLastPacketArrived__16CB3NetworkPlayerCFv(pl) <= 60.0f) {
                if (GetPlayerRecordByID__17CB3NetworkManagerFi(&D_01E32AE0, func_0022FBB0(pl)) == 0) {
                    ok = false;
                }
            }
        }
    }
    if (!ok) {
        return 0;
    }
    const UnkStruct_00390D70_rec * const p = &D_0064EA70;
    D_01EA07D4 = *p;
    return 1;
}
