// CB3SoundCrashManager::CarToCar(GtMathPs2::CGtV3d*,float,const CB3CollidingPair*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (near36: rewritten from retail -- real CB3SoundScrape::SetInfo member on field_10[idx], header CGtV4d::W() speed read, idx/speed locals before the f*=2.5 test, scoped opt_repositioncode off [G] (as sibling 0027F5E0)).

// CB3SoundCrashManager::CarToCar(GtMathPs2::CGtV3d*,float,const CB3CollidingPair*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// near36: rewritten from retail -- the same per-body block for field_24 then field_28 (body type 2 = car [G]),
// speed as the header W() lane read of the CGtV4d at +0xB0 (sq to a stack copy + lwc1 +0xC).

#include "b3/GtMathPs2.h"

enum ESoundWorldCrashSurfaceType {};

struct UnkStruct_0027F2A0_5 {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};

struct UnkStruct_0027F2A0_3 {
    unsigned char pad_0[0xB0];
    GtMathPs2::CGtV4d field_B0;
    unsigned char pad_C0[0x150];
    unsigned char field_210;
    unsigned char pad_211[0x11E3];
    UnkStruct_0027F2A0_5 * field_13F4;
};

struct UnkStruct_0027F2A0_1 {
    signed char field_0;
    unsigned char pad_1[0xB];
    UnkStruct_0027F2A0_3 * field_C;
};

class CB3CollidingPair {
public:
    unsigned char pad_0[0x24];
    UnkStruct_0027F2A0_1 * field_24;
    UnkStruct_0027F2A0_1 * field_28;
};

class CB3SoundScrape {
public:
    void SetInfo(ESoundWorldCrashSurfaceType, float, float, GtMathPs2::CGtV3d *);
    unsigned char pad_0[0x40];
};

class CB3SoundCrashManager {
public:
    void CarToCar(GtMathPs2::CGtV3d* p0, float p1, const CB3CollidingPair* p2);

    unsigned char pad_0[0x10];
    CB3SoundScrape field_10[1];  // [G] element count unknown
};

extern "C" void func_0027D380(CB3SoundCrashManager *, GtMathPs2::CGtV3d *, float);
extern "C" void func_0027DDD0(CB3SoundCrashManager *, GtMathPs2::CGtV3d *, float);

// 0x0027F2A0
// N182: [G] scoped to this function (as the proven sibling B3SoundCrashManager_0027F5E0.cpp); without it MWCC moves both
// per-car blocks out of line.
#pragma push
#pragma opt_repositioncode off
void CB3SoundCrashManager::CarToCar(GtMathPs2::CGtV3d* p0, float p1, const CB3CollidingPair* p2)
{
    float f = 1.0f;
    if (p2->field_24->field_0 == 2) {
        UnkStruct_0027F2A0_3 * car = p2->field_24->field_C;
        int idx = car->field_13F4->field_19AC;
        float speed = car->field_B0.W();
        if ((unsigned int)p2->field_28->field_0 < 3u) f *= 2.5f;
        field_10[idx].SetInfo((ESoundWorldCrashSurfaceType)0, f, speed, p0);
        if (car->field_210 != 0) func_0027D380(this, p0, p1);
        else func_0027DDD0(this, p0, p1);
    }
    if (p2->field_28->field_0 == 2) {
        UnkStruct_0027F2A0_3 * car = p2->field_28->field_C;
        int idx = car->field_13F4->field_19AC;
        float speed = car->field_B0.W();
        if ((unsigned int)p2->field_24->field_0 < 3u) f *= 2.5f;
        field_10[idx].SetInfo((ESoundWorldCrashSurfaceType)0, f, speed, p0);
        if (car->field_210 != 0) func_0027D380(this, p0, p1);
        else func_0027DDD0(this, p0, p1);
    }
    if ((unsigned int)(p2->field_24->field_0 - 3) < 2u && (unsigned int)(p2->field_28->field_0 - 3) < 2u)
        func_0027D380(this, p0, p1);
}
#pragma pop
