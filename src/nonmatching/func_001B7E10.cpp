// NONMATCHING: func_001B7E10 -- retail 71 / ours 71 instructions, 13 in changed runs
// near35: [L] CB3PhysicsManager::InsertActiveBody (low name); rewritten with ExtractActiveBody's field_E5F0[3][0x990] entry array + element-pointer stores (count once per entry) + lane reads (float)*(const X/Y/ZAxisType*)&body.field (frame 0x40 exact, 71/71). Left: t1/t2 swap (body pointer vs hoisted sp+48 copy address) and Y-arm lwc1 order (retail lo then hi in b delay slot); arm/switch orders, body pointer local, decl orders tried
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// [L] retail_names.csv (low): CB3PhysicsManager::InsertActiveBody(int) -- B3PhysicsManager.cpp
#include "b3/GtMathPs2.h"

struct UnkStruct_001B7E10_e {
    float field_0;
    short field_4;
    unsigned char field_6;
    unsigned char pad_7;
};
struct UnkStruct_001B7E10_b {
    unsigned char pad_0[0x10];
    GtMathPs2::CGtV4d field_10;
    GtMathPs2::CGtV4d field_20;
};
class CB3PhysicsManager {
public:
    unsigned char pad_0[0x70];
    UnkStruct_001B7E10_b field_70[1];  // [G] count unknown
    unsigned char pad_A0[0xE5F0 - 0xA0];
    UnkStruct_001B7E10_e field_E5F0[3][0x990];
    int field_1CB70;
    int field_1CB74;
};

// 0x001B7E10
extern "C" void func_001B7E10(CB3PhysicsManager * self, int p0)
{
    for (int i = 0; i < 3; i++) {
        float hi;
        float lo;
        if (i == 0) {
            lo = (float)*(const GtMathPs2::XAxisType *)&self->field_70[p0].field_10;
            hi = (float)*(const GtMathPs2::XAxisType *)&self->field_70[p0].field_20;
        } else if (i == 1) {
            lo = (float)*(const GtMathPs2::YAxisType *)&self->field_70[p0].field_10;
            hi = (float)*(const GtMathPs2::YAxisType *)&self->field_70[p0].field_20;
        } else {
            lo = (float)*(const GtMathPs2::ZAxisType *)&self->field_70[p0].field_10;
            hi = (float)*(const GtMathPs2::ZAxisType *)&self->field_70[p0].field_20;
        }
        UnkStruct_001B7E10_e * e = &self->field_E5F0[i][self->field_1CB74];
        e->field_0 = lo;
        e->field_6 = 1;
        e->field_4 = p0;
        e = &self->field_E5F0[i][self->field_1CB74 + 1];
        e->field_0 = hi;
        e->field_6 = 0;
        e->field_4 = p0;
    }
    self->field_1CB74 += 2;
}
