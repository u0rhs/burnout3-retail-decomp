// CB3SoundCrashManager::DeformSpoiler(GtMathPs2::CGtV3d,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a244: sibling shape of DeformFrontBumper + if(f)return; if(f){call;return;} return;).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_a165_cm { unsigned char pad_0[0x880]; int field_880; };
extern "C" void func_0027E900(UnkStruct_a165_cm *, CGtV3d *, float);
struct UnkStruct_0027EF90_pad {
    UnkStruct_0027EF90_pad() {}
    ~UnkStruct_0027EF90_pad() {}
};
// pass1: the mangled name's float (f12; UpdateFlyingBitsBones__16CB3VehicleDeformFff passes a scaled amount) goes to
// func_0027E900(self, v, float) untouched
extern "C" void DeformSpoiler__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(UnkStruct_a165_cm *self, CGtV3d v, float f) {
    UnkStruct_0027EF90_pad pad;
    CGtV3d w = v;
    CGtV3d * pw = &w;
    if (self->field_880 == 0) return;
    if (self->field_880 != 0) { func_0027E900(self, pw, f); return; }
    return;
}
