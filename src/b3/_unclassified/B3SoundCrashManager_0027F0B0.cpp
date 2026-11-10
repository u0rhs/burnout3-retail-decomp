// CB3SoundCrashManager::DealWithObjectObjectCollision(const CB3CollidingPair*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (re-queued after the jtbl_retarget 2-table fix (from build/vt/hand/DealWithObjectObjectCollision__2_cdff264_a122a.cpp)).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
enum EB3PropType {};
enum EVehicleFlyingBit {};
class CB3CollidingPair;
struct UnkStruct_0027F0B0_pad { unsigned char field_0[4]; UnkStruct_0027F0B0_pad() {} ~UnkStruct_0027F0B0_pad() {} };
struct UnkStruct_0027F0B0_prop { unsigned char pad_0[2]; unsigned char field_2; };
struct UnkStruct_0027F0B0_w { unsigned char pad_0[0x30]; };
struct UnkStruct_0027F0B0_b {
    unsigned char pad_0[0x194]; float field_194; unsigned char pad_198[0x6C]; char *field_204;
    unsigned char pad_208[0xB0]; short field_2B8; unsigned char field_2BA;
};
struct UnkStruct_0027F0B0_a { unsigned char pad_0[0x220]; UnkStruct_0027F0B0_prop *field_220; };
struct UnkStruct_0027F0B0_o {
    signed char field_0;
    unsigned char pad_1[0xB];
    void *field_C;
};
struct UnkStruct_D_0064A85C { unsigned char *field_0; unsigned char pad_4[12]; };
extern UnkStruct_D_0064A85C D_0064A85C;
class CB3CollidingPair {
public:
    CGtV3d field_0;
    unsigned char pad_10[0x10];
    float field_20;
    UnkStruct_0027F0B0_o *field_24;
    UnkStruct_0027F0B0_o *field_28;
};
class CB3SoundCrashManager;
extern "C" void CarToCar__20CB3SoundCrashManagerFPQ29GtMathPs26CGtV3dfPC16CB3CollidingPair(CB3SoundCrashManager *, CGtV3d *, float, const CB3CollidingPair *);
extern "C" void PropImpact__20CB3SoundCrashManagerFb11EB3PropTypeQ29GtMathPs26CGtV3df(CB3SoundCrashManager *, bool, EB3PropType, const void *, float);
extern "C" void WheelImpact__20CB3SoundCrashManagerFbQ29GtMathPs26CGtV3df(CB3SoundCrashManager *, bool, const void *, float);
extern "C" void BodyPartImpact__20CB3SoundCrashManagerFb17EVehicleFlyingBitQ29GtMathPs26CGtV3df(CB3SoundCrashManager *, bool, EVehicleFlyingBit, const void *, float);
class CB3SoundCrashManager {
public:
    void DealWithObjectObjectCollision(const CB3CollidingPair *);
};
// 0x0027F0B0
void CB3SoundCrashManager::DealWithObjectObjectCollision(const CB3CollidingPair *pair)
{
    UnkStruct_0027F0B0_pad pad;
    CGtV3d pos;
    pos = pair->field_0;
    int t0 = pair->field_24->field_0;
    switch (t0) {
    case 0: case 1: case 2: case 3: case 4: {
        UnkStruct_0027F0B0_o *o2 = pair->field_28;
        switch (o2->field_0) {
        case 0: case 1: case 2: case 3: case 4:
            CarToCar__20CB3SoundCrashManagerFPQ29GtMathPs26CGtV3dfPC16CB3CollidingPair(this, &pos, pair->field_20, pair);
            break;
        case 5: case 6:
            if (t0 != 0) {
                UnkStruct_0027F0B0_prop *pr = ((UnkStruct_0027F0B0_a *)o2->field_C)->field_220;
                if (pr != 0) {
                    PropImpact__20CB3SoundCrashManagerFb11EB3PropTypeQ29GtMathPs26CGtV3df(this, false, (EB3PropType)D_0064A85C.field_0[pr->field_2], &pos, pair->field_20);
                }
            }
            break;
        case 7: {
            UnkStruct_0027F0B0_b *b = (UnkStruct_0027F0B0_b *)o2->field_C;
            if (b->field_2BA == 0) {
                WheelImpact__20CB3SoundCrashManagerFbQ29GtMathPs26CGtV3df(this, false, b->field_204 + 0x30, b->field_194);
            } else {
                BodyPartImpact__20CB3SoundCrashManagerFb17EVehicleFlyingBitQ29GtMathPs26CGtV3df(this, false, (EVehicleFlyingBit)b->field_2B8, b->field_204 + 0x30, b->field_194);
            }
            break;
        }
        }
        break;
    }
    case 5: case 6: {
        UnkStruct_0027F0B0_o *o2 = pair->field_28;
        int t1 = o2->field_0;
        switch (t1) {
        case 0: case 1: case 2: case 3: case 4:
            CarToCar__20CB3SoundCrashManagerFPQ29GtMathPs26CGtV3dfPC16CB3CollidingPair(this, &pos, pair->field_20, pair);
            break;
        case 5: case 6:
            if (t1 != 0) {
                UnkStruct_0027F0B0_prop *pr = ((UnkStruct_0027F0B0_a *)o2->field_C)->field_220;
                if (pr != 0) {
                    PropImpact__20CB3SoundCrashManagerFb11EB3PropTypeQ29GtMathPs26CGtV3df(this, false, (EB3PropType)D_0064A85C.field_0[pr->field_2], &pos, pair->field_20);
                }
            }
            break;
        case 7: {
            UnkStruct_0027F0B0_b *b = (UnkStruct_0027F0B0_b *)o2->field_C;
            if (b->field_2BA == 0) {
                WheelImpact__20CB3SoundCrashManagerFbQ29GtMathPs26CGtV3df(this, false, b->field_204 + 0x30, b->field_194);
            } else {
                BodyPartImpact__20CB3SoundCrashManagerFb17EVehicleFlyingBitQ29GtMathPs26CGtV3df(this, false, (EVehicleFlyingBit)b->field_2B8, b->field_204 + 0x30, b->field_194);
            }
            break;
        }
        }
        break;
    }
    }
}
