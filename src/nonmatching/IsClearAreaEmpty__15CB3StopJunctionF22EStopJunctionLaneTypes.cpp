// NONMATCHING: IsClearAreaEmpty__15CB3StopJunctionF22EStopJunctionLaneTypes -- retail 247 / ours 250 instructions, 106 in changed runs
// a142: logic complete (4 type checks + count loop via a 'lane/off/hi' inline sharing the D_00522660 base), 250/247 instrs, ~106 differ: register numbering (retail base t2/index t3, ours swapped) and the type-0 'field_1C==0 -> v0=1' materialised bool join (retail bnez v0; b ret0 shared block, ours beqz; li)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

enum EStopJunctionLaneTypes {};
struct UnkStruct_002B5270_S {
    int field_0[6];
    int field_18[4];
    int field_28[4];
    int field_38[4];
    unsigned char pad_48[0xC];
    int field_54;
};
struct UnkStruct_002B5270_p { unsigned char pad_0[0x30]; float field_30; unsigned char pad_34[0x1C]; };
struct UnkStruct_002B5270_l { unsigned char pad_0[4]; unsigned short field_4; unsigned char pad_6[0x46]; };
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x22C];
    UnkStruct_002B5270_l field_22C[1];
    unsigned char pad_278[0x2F038];
    UnkStruct_002B5270_p field_2F2B0[1];
};
struct UnkStruct_D_0055D7DC { unsigned char * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0055D7DC D_0055D7DC;
static inline UnkStruct_002B5270_p * func_002B5270_inl1(UnkStruct_D_00522660 * g, unsigned char i)
{
    if (i == 0xFF) {
        return 0;
    }
    return &g->field_2F2B0[i];
}
static inline bool func_002B5270_inl2(int lane, int off, int hi)
{
    UnkStruct_D_00522660 * const g = &D_00522660;
    unsigned char id = D_0055D7DC.field_0[g->field_22C[lane].field_4 + off];
    if (id == 0xFF) return true;
    return hi < (int)func_002B5270_inl1(g, id)->field_30;
}
class CB3StopJunction {
public:
    UnkStruct_002B5270_S * field_0;
    unsigned char pad_4[0x18];
    unsigned char field_1C;
    bool IsClearAreaEmpty(EStopJunctionLaneTypes);
};
bool CB3StopJunction::IsClearAreaEmpty(EStopJunctionLaneTypes p0)
{
    if (p0 == 0) {
        if (!func_002B5270_inl2(field_0->field_0[0], field_0->field_18[0], field_0->field_28[0])) return false;
        if (field_1C != 0) {
            if (!func_002B5270_inl2(field_0->field_0[1], field_0->field_18[1], field_0->field_28[1])) return false;
        }
    }
    if (p0 == 2) {
        if (!func_002B5270_inl2(field_0->field_0[2], field_0->field_18[2], field_0->field_28[2])) return false;
    }
    if (p0 == 3) {
        if (!func_002B5270_inl2(field_0->field_0[3], field_0->field_18[3], field_0->field_28[3])) return false;
    }
    int n = field_0->field_54;
    if (field_1C == 0) n = n + 1;
    for (int i = 0; i < n; i++) {
        if (i == 1 && field_1C == 0) continue;
        int off = 0;
        if (i < 4) off = field_0->field_28[i] + 1;
        if (!func_002B5270_inl2(field_0->field_0[i], off, field_0->field_38[i])) return false;
    }
    return true;
}
