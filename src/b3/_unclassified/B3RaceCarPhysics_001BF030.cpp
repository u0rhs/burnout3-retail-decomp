// CB3RaceCarPhysics::DoPhysicalEffects(EB3CollisionSurface) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCarPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (b2src: adapted from Burnout 2 CRaceCarPhysics::DoPhysicalEffects (b3dllc/burnout2@61e466e) onto GtMathPs2; scaled vector in a named temp).

// Hand-written (the lifter had no candidate). Adapted from Burnout 2's CRaceCarPhysics::DoPhysicalEffects
// (github.com/b3dllc/burnout2 @ 61e466e295e34abf3de7816c220e4b09ba95022d, src/nodebug/CRaceCarPhysics.cpp): same case
// grouping and factors (-0.7/-0.9/-1.2/-1.5 times speed/44.7 times a mass-like field), rewritten on GtMathPs2 vectors.
// No Burnout 2 name is used for any Burnout 3 symbol, field or enumerator (provenance rule); cases are by value.
// [C] case->block map: retail jtbl_004B7D50 (12,13 / 14,15 / 16,18-20 / 17). The scaled vector is a named temporary
// before the += (the direct `field_F0 += field_C0 * k` numbers the VU registers differently).
#include "b3/GtMathPs2.h"

enum EB3CollisionSurface { UnkEnum_001BF030_dummy = 0 };  // [G] enumerator names not in our tables; cases by value
class CB3RaceCarPhysics {
public:
    void DoPhysicalEffects(EB3CollisionSurface);
    unsigned char pad_0[0xB0];
    GtMathPs2::CGtV4d field_B0;
    GtMathPs2::CGtV3d field_C0;
    unsigned char pad_D0[0x20];
    GtMathPs2::CGtV3d field_F0;
    unsigned char pad_100[0xF0];
    float field_1F0;
};

// 0x001BF030
void CB3RaceCarPhysics::DoPhysicalEffects(EB3CollisionSurface e)
{
    float speed = field_B0.W();
    switch (e) {
    case 17:
        {
            GtMathPs2::CGtV3d d = field_C0 * ((speed / 44.704f) * (-0.7f * field_1F0));
            field_F0 += d;
        }
        break;
    case 12:
    case 13:
        {
            GtMathPs2::CGtV3d d = field_C0 * ((speed / 44.704f) * (-0.9f * field_1F0));
            field_F0 += d;
        }
        break;
    case 14:
    case 15:
        {
            GtMathPs2::CGtV3d d = field_C0 * ((speed / 44.704f) * (-1.2f * field_1F0));
            field_F0 += d;
        }
        break;
    case 16:
    case 18:
    case 19:
    case 20:
        {
            GtMathPs2::CGtV3d d = field_C0 * ((speed / 44.704f) * (-1.5f * field_1F0));
            field_F0 += d;
        }
        break;
    }
}
