// NONMATCHING: func_003F1FC0 -- retail 188 / ours 186 instructions, 20 in changed runs
// near19: scoped opt_dead_assignments off [G] + a dead 'CGtV4d c(1,1,1,1);' keeps the 4 sw of the ctor temp at retail's sp+0x50/0x40 (186/188). Left: retail's dead lq v0 of the temp (c stays in a register) is still deleted, and c gets its own 2 frame slots (0x80 vs 0x60); field_720 store scheduled before the ctor stores
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// a83: everything matches except two dead CGtV4d(1,1,1,1) constructions (lui+4 sw+lq kept in retail, 16B frame slot each; b119 deletes dead ctor/copy/by-value-param/ret forms: ~25 spellings tried, volatile/asm uses change the frame wrongly); 176/188 instrs
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// func_003F1FC0 -- CB3MyBurnoutRewardsStatsPage::Update() [L] DNAT (research/proto/new_names.csv, medium)
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV4d;
enum EB3MenuFlowFSMEvents {};
class CB3InputManager {
public:
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);
    int GetMenuBack(signed char);
    unsigned char pad_0[0x10];
};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_003F1FC0_s { short field_0; unsigned char pad_2[0x36]; };
struct UnkStruct_003F1FC0_a { unsigned char pad_0[0x4]; UnkStruct_003F1FC0_s field_4; };
struct UnkStruct_003F1FC0_b { short field_0; unsigned char pad_2[0x56]; };
struct UnkStruct_003F1FC0 {
    UnkStruct_003F1FC0_a field_0[5];
    unsigned char pad_12C[0x2C0 - 0x12C];
    UnkStruct_003F1FC0_b field_2C0[5];
    unsigned char pad_478[0x720 - 0x478];
    int field_720;
};
extern CB3InputManager D_004F50C0;
extern UnkStruct_I D_01E90424;
extern UnkStruct_P D_01E90240, D_01E7A800, D_01E8D450;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);
extern "C" bool func_003F1490(void *, int, int);
extern "C" void func_0033F1B0(void *, int);

static inline void Nop4(CGtV4d c) {}

// [L] DNAT: CB3MyBurnoutRewardsStatsPage::Update() (research/proto/new_names.csv, medium)
#pragma push
#pragma opt_dead_assignments off
// 0x003F1FC0
extern "C" void func_003F1FC0(UnkStruct_003F1FC0 * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    if (D_004F50C0.GetMenuBack(0)) {
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        return;
    }
    if (D_004F50C0.GetMenuUp(0)) {
        if (self->field_720 > 0) {
            CGtV4d c(1.0f, 1.0f, 1.0f, 1.0f);
            self->field_720 = self->field_720 - 1;
            for (int i = 0; i < 5; i++) {
                int s0 = self->field_720 + i;
                if (s0 >= 0 && s0 < 30) {
                    func_003F1490(&self->field_2C0[i], s0, 0);
                    func_003F1490(&self->field_0[i].field_4, s0, 1);
                } else {
                    self->field_2C0[i].field_0 = 0;
                    self->field_0[i].field_4.field_0 = 0;
                }
            }
            FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
        }
    } else if (D_004F50C0.GetMenuDown(0)) {
        if (self->field_720 < 25) {
            CGtV4d c(1.0f, 1.0f, 1.0f, 1.0f);
            self->field_720 = self->field_720 + 1;
            for (int i = 0; i < 5; i++) {
                int s0 = self->field_720 + i;
                if (s0 >= 0 && s0 < 30) {
                    func_003F1490(&self->field_2C0[i], s0, 0);
                    func_003F1490(&self->field_0[i].field_4, s0, 1);
                } else {
                    self->field_2C0[i].field_0 = 0;
                    self->field_0[i].field_4.field_0 = 0;
                }
            }
            FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
        }
    }
    int v = self->field_720;
    if (v > 0) {
        if (v < 25) {
            func_0033F1B0(&D_01E8D450, 0);
        } else {
            func_0033F1B0(&D_01E8D450, 1);
        }
    } else if (v < 25) {
        func_0033F1B0(&D_01E8D450, 2);
    }
}
#pragma pop
