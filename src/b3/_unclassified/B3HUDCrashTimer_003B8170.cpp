// CB3HUDCrashTimer::PrepareCrashTimerObject() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDCrashTimer.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (fresh: written from asm; D_00522660.field_3C960[i].field_2C record, colour assigned (lq copy), size declared before t (f21/f22), size = 66 before the colour load; func_002848E0 takes 1.0f).

// CB3HUDCrashTimer::PrepareCrashTimerObject() -- hand-written (fresh2); the lifter refused it.
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDCrashTimer.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G].
// Callee signatures from proven callers (func_00435AB0.cpp: func_001D6970; func_002848E0.cpp; PrintInt__10CGtUnicodeFPUsii).

#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObjectText.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

class CB3HUDComponent {
public:
    static CGt2dObjectText::COutlineDropShadow maOutlineDropShadow[3];
};

struct UnkStruct_003B8170_car {
    unsigned char pad_0[0x210];
    unsigned char field_210;
};

// [G] 0x30-byte per-car records (D_0055EFEC; D_00522660 + 0x3C98C)
struct UnkStruct_003B8170_rec {
    UnkStruct_003B8170_car * field_0;
    unsigned char pad_4[0x2C];
};

struct UnkStruct_D_0066A4C0 {
    unsigned char pad_0[0x20];
    CGtV4d field_20;
};

struct UnkStruct_D_00665ED0 {
    CGt2dFont * field_0;
    unsigned char pad_4[0xC];
};

struct UnkStruct_D_0064D37C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064E740 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003B8170_e1 {
    unsigned char pad_0[0x2C];
    UnkStruct_003B8170_car * field_2C;
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x3C960];
    UnkStruct_003B8170_e1 field_3C960[1];  // [G] element count unknown
};

struct UnkStruct_D_0055E948 {
    unsigned char pad_0[0x10];
};

struct UnkStruct_D_01E7A800 {
    unsigned char pad_0[0x10];
};

class CB3HUDCrashTimer {
public:
    void PrepareCrashTimerObject();

    unsigned char pad_0[0x20];
    CGt2dObject * field_20;
    unsigned short field_24;
    unsigned short field_26;
    unsigned char pad_28[0x4];
    int field_2C;
    unsigned char field_30;
};

extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_0064E740 D_0064E740;
extern UnkStruct_D_0064E740 D_0064E47C;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0055E948 D_0055E948;
extern UnkStruct_D_01E7A800 D_01E7A800;
extern UnkStruct_003B8170_rec D_0055EFEC[];

extern "C" float GetRaceCarCrashTime__22CB3CrashActionDirectorFi(void *, int);
extern "C" void PrintInt__10CGtUnicodeFPUsii(void *, int, int, int);
extern "C" float floorf(float);
extern "C" void func_002848E0(void *, int, float);
extern "C" void func_001D6970(CGt2dObject *, const CGtV2d &, const CGtV2d &, float, CGtV4d, const CGt2dFont *,
                              const unsigned short *, const CGt2dObjectText::COutlineDropShadow *);

// 0x003B8170
void CB3HUDCrashTimer::PrepareCrashTimerObject()
{
    UnkStruct_D_0066A4C0 * const g = &D_0066A4C0;
    float size;
    bool found = false;
    float t = 3.402823466e+38f;
    float y;
    if (field_30 != 0) {
        y = 216.0f;
        for (int i = 0; i < D_0064D37C.field_0; i++) {
            if (D_00522660.field_3C960[i].field_2C->field_210 != 0) {
                float c = GetRaceCarCrashTime__22CB3CrashActionDirectorFi(&D_0055E948, i);
                if (c < t) {
                    t = c;
                }
                found = true;
            }
        }
        if (!found) {
            t = D_0064E740.field_0 - D_0064E47C.field_0;
        }
    } else {
        y = 80.0f;
        if (D_0055EFEC[field_2C].field_0->field_210 != 0) {
            t = GetRaceCarCrashTime__22CB3CrashActionDirectorFi(&D_0055E948, field_2C);
        } else {
            t = D_0064E740.field_0 - D_0064E47C.field_0;
        }
    }
    CGtV4d colour;
    size = 66.0f;
    colour = g->field_20;
    int secs = (int)t;
    if (secs < 6 && secs > 0) {
        PrintInt__10CGtUnicodeFPUsii(&field_24, secs, 1, 0);
        float a = 2.0f * (t - floorf(t)) - 1.0f;
        if (a < 0.0f) {
            a = 0.0f;
        }
        colour = CGtV4d(1.0f, 0.0f, 0.0f, a);
        size = size + 40.0f * (1.0f - a);
        func_002848E0(&D_01E7A800, secs, 1.0f);
    } else {
        field_24 = 0x20;
        field_26 = 0;
    }
    func_001D6970(field_20, CGtV2d(0.0f, y), CGtV2d(0.5f, 0.5f), size, colour, D_00665ED0.field_0,
                  &field_24, &CB3HUDComponent::maOutlineDropShadow[1]);
}
