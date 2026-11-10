// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// CB3PhysicsManager::UpdateNearMissArray() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PhysicsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it. [G] API: the squared length is GtMathPs2::DotProduct(CGtV3d, CGtV3d) (B3O0PCH map,
// 116 bytes) of the difference with itself, not CGtV3d::GetSquaredLength(): retail's loop has no GPR round trip, which
// the usual GetSquaredLength() keeps (N191; twoapi). Its 1.0 is hoisted out of the loops by the build compiler b119p as
// retail's compiler did (N184; was an explicit FAKEMATCH hoist, N163).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;


class CB3PhysicsManager;
struct UnkStruct_001B3EA0_m;
struct UnkStruct_001B3EA0_b;
struct UnkStruct_001B3EA0_e;
struct UnkStruct_D_0064D37C;

struct UnkStruct_D_0064D37C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
extern UnkStruct_D_0064D37C D_0064D37C;

struct UnkStruct_001B3EA0_m {          // [G] a body with its matrix: field_30 = the position row (mPos)
    unsigned char pad_0[0x30];
    CGtV3d field_30;
};

struct UnkStruct_001B3EA0_b {
    unsigned char pad_0[0x204];
    UnkStruct_001B3EA0_m * field_204;
};

struct UnkStruct_001B3EA0_e {
    unsigned char pad_0[0x4];
    UnkStruct_001B3EA0_m * field_4;
    unsigned char pad_8[0x28];
};

class CB3PhysicsManager {
public:
    void UpdateNearMissArray();

    unsigned char field_0[6][16];               // [G] per-car near-miss index lists (16 entries)
    unsigned char field_60[0x10];               // [G] per-car list lengths
    UnkStruct_001B3EA0_e field_70[6];           // [G] element count unknown
    unsigned char pad_190[0xE6100 - 0x190];
    UnkStruct_001B3EA0_b * field_E6100[67];     // [G] element count unknown
    int field_E620C;
};

// 0x001B3EA0
void CB3PhysicsManager::UpdateNearMissArray()
{
    int n = D_0064D37C.field_0;
    for (int i = 0; i < n; i++) {
        field_60[i] = 0;
        for (int j = 0; j < field_E620C; j++) {
            CGtV3d d = field_70[i].field_4->field_30 - field_E6100[j]->field_204->field_30;
            if (DotProduct(d, d) < 256.0f) {
                if (field_60[i] < 16) {
                    field_0[i][field_60[i]] = j;
                    field_60[i]++;
                }
            }
        }
    }
}
