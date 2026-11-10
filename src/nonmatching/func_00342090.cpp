// NONMATCHING: func_00342090 -- retail 221 / ours 221 instructions, 1 in changed runs
// pass3b: 'short idx' gives retail's shared break stub but lh; unsigned short/int/unsigned idx give lhu but break to a separate stub (13 target diffs). Scoped opt_treetransformation off [G] + unsigned short gives layout AND lhu but swaps addu operands of field_8[idx]/field_44[idx] (2 off: idx[arr], *(idx+arr), (char*)(idx*8)+self, unsigned sums all keep self first or break layout). Also ruled out: f61 inline arm, goto out joins, short copy for the switch.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// a149: logic+layout exact (221/221, 13 branch-target diffs): retail's switch breaks all jump to ONE end stub placed after the out-of-line field_61 block; ours keeps a separate stub after the jump-table arm | mwperm: 13 -> 1 (+'short idx;'; 'unsigned short idx = self->field_4;' -> 'idx = self->field_4;')

enum EB3MenuFlowFSMEvents {};
struct UnkStruct_P_a149 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E898E8_a149 { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_00342090_ent { int field_0; unsigned char field_4; unsigned char field_5; unsigned char pad_6[2]; };
struct UnkStruct_00342090_m {
    unsigned char pad_0[0x2C];
    short field_2C;
    unsigned char pad_2E[0xA];
    short field_38;
    unsigned char pad_3A[0x16];
    short field_50;
};
struct UnkStruct_00342090 {
    unsigned char pad_0[4];
    unsigned short field_4;
    unsigned short field_6;
    UnkStruct_00342090_ent field_8[7];
    int field_40;
    int field_44[6];
    unsigned char pad_5C[4];
    unsigned char field_60;
    unsigned char field_61;
    unsigned char field_62;
};
extern UnkStruct_P_a149 D_01E90240, D_01E7A800, D_004EE040;
extern UnkStruct_D_01E898E8_a149 D_01E898E8;
extern "C" {
void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);
void FESelect__18CB3HUDSoundManagerFv(void *);
void func_0032D080(void *, int, int, int, int);
int func_00131CE0(void *);
int func_00319360(void *);
int func_00319330(void *);
int func_0012FB10(void *, int);
}
extern "C" void func_00342090(UnkStruct_00342090 *self, UnkStruct_00342090_m *m)
{
    short idx;
    if (m->field_50 == 0) {
        if (m->field_2C != 0) goto c1;
    c38:
        if (m->field_38 != 0) goto c2;
    c3:
        if (func_0012FB10(m, 1) != 0) goto lead;
        return;
    }
    idx = self->field_4;
    if (self->field_8[idx].field_4 != 0) return;
    if (self->field_60 == 0) {
        switch (self->field_44[idx]) {
        case 0:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)6, 1);
            break;
        case 1:
            self->field_40 = 2;
            func_0032D080(&D_01E898E8, 7, 0x136, 5, 0);
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        case 2:
            self->field_40 = 3;
            func_0032D080(&D_01E898E8, 7, 0x151, 5, 0);
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        case 3:
            self->field_62 = 1;
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x4C, 0);
            break;
        case 4:
            self->field_62 = 1;
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x4D, 0);
            break;
        case 5:
            if (self->field_61 != 0) goto f61;
            {
                int s1 = 0x144;
                if (func_00131CE0(&D_004EE040)) s1 = 0x145;
                self->field_40 = 0;
                func_0032D080(&D_01E898E8, 7, s1, 5, 0);
                FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            }
            break;
        }
    } else {
        switch (idx) {
        case 0:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)6, 1);
            break;
        case 4:
            self->field_40 = 0;
            func_0032D080(&D_01E898E8, 7, 0x138, 5, 0);
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        case 1:
            self->field_40 = 1;
            func_0032D080(&D_01E898E8, 7, 0x137, 5, 0);
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        case 2:
            self->field_62 = 1;
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x4C, 0);
            break;
        case 3:
            self->field_62 = 1;
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x4D, 0);
            break;
        }
    }
    return;
f61:
    self->field_40 = 4;
    func_0032D080(&D_01E898E8, 7, 0x146, 5, 0);
    FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
    return;
c1:
    if (func_00319360((char *)self + 4) == 0) goto c38;
    return;
c2:
    if (func_00319330((char *)self + 4) == 0) goto c3;
    return;
lead:
    StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)6, 1);
}
