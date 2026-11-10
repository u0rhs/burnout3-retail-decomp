// NONMATCHING: GetVehicleBeforeImpact__16CB3CrashAnalyserFv -- retail 67 / ours 67 instructions, 18 in changed runs
// near35: .lit4 D_004E0D6C -> 2.236936331f * W-lane read via *(const WAxisType*)& (frame 0x10 exact); type-in-{1..4} test as goto-yes stub (block layout exact). Left: a1/a2 swap of the hoisted sp-address (WAxisType copy) vs the per-iteration element temp; declaration order/types/copy forms inert
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_00354350_4 {
    unsigned char pad_0[0xB0];
    GtMathPs2::CGtV4d field_B0;
    unsigned char pad_C0[0x155];
    signed char field_215;
    unsigned char pad_216[0x2212];
    unsigned char field_2428;
};

struct UnkStruct_00354350_e0 {
    unsigned char pad_0[0x40];
    UnkStruct_00354350_4 * field_40;
    unsigned char pad_44[0xC];
    float field_50;
    float field_54;
    unsigned char pad_58[0x18];
};

class CB3CrashAnalyser {
public:
    UnkStruct_00354350_e0 * GetVehicleBeforeImpact();

    unsigned char pad_0[0x2E0];
    UnkStruct_00354350_e0 field_2E0[1];  // [G] element count unknown
    unsigned char pad_350[0xCE0];
    int field_1030;
};
// 0x00354350
UnkStruct_00354350_e0 * CB3CrashAnalyser::GetVehicleBeforeImpact()
{
    UnkStruct_00354350_e0 * best = 0;
    float m0 = 20.0f;
    for (int i = 0; i < field_1030; i++) {
        UnkStruct_00354350_e0 * e = &field_2E0[i];
        UnkStruct_00354350_4 * t2 = e->field_40;
        int t3 = t2->field_215;
        bool ok;
        if (t3 == 1) goto yes;
        if (t3 == 2) goto yes;
        if (t3 == 3) goto yes;
        if (t3 == 4) goto yes;
        ok = false;
    join:
        if (ok) {
        int v4;
        if (t3 == 4) {
            v4 = t2->field_2428;
        } else {
            v4 = 0;
        }
        if (v4 == 0) {
            if (e->field_50 > 0.0f) {
                if (e->field_54 < 1.5f) {
                    float s = 2.236936331f * (float)*(const GtMathPs2::WAxisType *)&t2->field_B0;
                    if (s > m0) {
                        best = e;
                        m0 = s;
                    }
                }
            }
        }
        }
        continue;
    yes:
        ok = true;
        goto join;
    }
    return best;
}
