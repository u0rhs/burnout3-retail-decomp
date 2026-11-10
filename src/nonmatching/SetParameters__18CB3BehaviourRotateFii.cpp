// NONMATCHING: SetParameters__18CB3BehaviourRotateFii -- retail 146 / ours 146 instructions, 4 in changed runs
// a123: 146/146 instrs, 6 changed. Layout exact (goto other/compute/noflag out-of-line blocks, extern C with extra p2=a3). Left: (1) retail's 'b l90; nop' has a nop in the delay slot, ours fills it with the target lw a0,4(s2); (2) a1/a2 swap and lw order in the two seg = field_8[s1] index computations (retail andi a3,s1 / sll a2,a3,2) | mwperm: 6 -> 4 (+'// N182: `#pragma opt_treetransformation off` ([G] scoped to this function; foun')
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_E5E40_seg { unsigned char pad_0[3]; unsigned char field_3; unsigned char field_4; unsigned char field_5; unsigned char pad_6[4]; };
struct UnkStruct_E5E40_ln4 { unsigned char pad_0[8]; UnkStruct_E5E40_seg * field_8; };
struct UnkStruct_E5E40_lane { unsigned char pad_0[4]; UnkStruct_E5E40_ln4 * field_4; };
struct UnkStruct_E5E40_X { unsigned char pad_0[0x18B4]; UnkStruct_E5E40_lane * field_18B4; unsigned short field_18B8; };
struct UnkStruct_E5E40_pos { unsigned char pad_0[0x30]; unsigned char field_30[16]; };
struct UnkStruct_E5E40_obj { unsigned char pad_0[0x204]; UnkStruct_E5E40_pos * field_204; unsigned char pad_208[0x1EC]; };
struct UnkStruct_E5E40_o2 { unsigned char pad_0[0x204]; UnkStruct_E5E40_pos * field_204; unsigned char pad_208[0x11EC]; UnkStruct_E5E40_X * field_13F4; };
struct UnkStruct_E5E40_e { UnkStruct_E5E40_o2 * field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_D_0055EFEC { UnkStruct_E5E40_e field_0[1]; };
extern UnkStruct_D_0055EFEC D_0055EFEC;

class CB3BehaviourRotate {
public:
    void SetParameters(int, int);
};
struct UnkStruct_E5E40_self {
    unsigned char pad_0[0x54];
    float field_54;
    float field_58;
    float field_5C;
    float field_60;
    float field_64;
    int field_68;
    int field_6C;
    unsigned char pad_70[4];
    unsigned char field_74;
};
extern "C" float GetTotalLeftFrac__9CB3AILaneCFUsQ29GtMathPs26CGtV3d(void *, unsigned short, const void *);
extern "C" int LaneIsDriveable__9CB3AILaneFUsUs(void *, unsigned short, unsigned short);

// N182: `#pragma opt_treetransformation off` ([G] scoped to this function; found by mwperm).
#pragma push
#pragma opt_treetransformation off
// 0x002E5E40
extern "C" void SetParameters__18CB3BehaviourRotateFii(UnkStruct_E5E40_self * self, int p0, int p1, int p2)
{
    self->field_6C = p0;
    self->field_60 = 2.0f;
    self->field_64 = 6.0f;
    self->field_68 = 0;
    self->field_74 = 1;
    UnkStruct_E5E40_o2 * o = D_0055EFEC.field_0[self->field_6C].field_0;
    UnkStruct_E5E40_X * x = o->field_13F4;
    UnkStruct_E5E40_lane * s2 = x->field_18B4;
    unsigned short s1 = x->field_18B8;
    float f21 = 0.0f;
    int s0;
    bool flag;
    UnkStruct_E5E40_ln4 * ln;
    if (p2 != 2) {
        goto other;
    }
    if ((s2->field_4->field_8[s1].field_3 & 7) == 5) {
        f21 = 90.0f;
    } else {
        f21 = 35.0f;
    }
    self->field_5C = 60.0f;
    s0 = 0;
l90:
    ln = s2->field_4;
l94:
    {
        UnkStruct_E5E40_seg * seg = &ln->field_8[s1];
        if (seg->field_4 == 0xFF) {
            goto noflag;
        } else if (seg->field_5 == 0xFF) {
            flag = true;
        } else {
            goto compute;
        }
    }
fin:
    if (s0 != 0) {
        self->field_54 = 0;
        if (flag) {
            self->field_54 = f21;
            self->field_58 = 1.0f;
        } else {
            self->field_54 = self->field_54 - f21;
            self->field_58 = -1.0f;
        }
    } else {
        self->field_54 = 180.0f;
        if (flag) {
            self->field_54 = self->field_54 - f21;
            self->field_58 = 1.0f;
        } else {
            self->field_54 = self->field_54 + f21;
            self->field_58 = -1.0f;
        }
    }
    return;
other:
    self->field_5C = f21;
    s0 = 0;
    if (p2 == 1) {
        ln = s2->field_4;
        goto l94;
    }
    f21 = 90.0f;
    goto l90;
noflag:
    flag = false;
    goto fin;
compute:
    {
        float f20 = GetTotalLeftFrac__9CB3AILaneCFUsQ29GtMathPs26CGtV3d(s2, s1, o->field_204->field_30);
        if (LaneIsDriveable__9CB3AILaneFUsUs(s2, s1, 1) != 0) {
            flag = f20 > 0.5f;
        } else {
            flag = f20 < 0.5f;
        }
        goto fin;
    }
}
