// B3PageTextComponent.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3PageTextComponent.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Menu/DebugMenu/Pages, [G] domain word `Page` in the name: 6 of Revenge's 7 files with it are in GameSource/Menu/DebugMenu/Pages/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/GtMathPs2.h"

#include "b3/classes/CB3PageTextComponent.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01EA4994.h"
#include "b3/classes/UnkStruct_kB3PageTextBorder.h"

struct UnkStruct_00379450_obj {
    GtMathPs2::CGtV2d field_0;
    GtMathPs2::CGtV2d field_8;
};

struct UnkStruct_00379450 {
    unsigned char pad_0[0x14];
    float field_14;
    UnkStruct_00379450_obj * field_18;
    UnkStruct_00379450_obj * field_1C;
    UnkStruct_00379450_obj * field_20;
    UnkStruct_00379450_obj * field_24;
    float field_28;
};

extern UnkStruct_kB3PageTextBorder kB3PageTextBorder;
extern UnkStruct_D_01EA4994 D_01EA4994;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern "C" void Prepare__20CB3PageTextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPCUsUi(void *, const void *, const void *, const unsigned short*, unsigned int);  // CB3PageTextComponent::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const unsigned short*,unsigned int)
extern "C" int func_00271A00(void *, EGlobalStrings, const GtMathPs2::CGtV2d*, EGlobalStrings, unsigned int);
extern "C" void Construct__20CB3MenuComponentBaseFi(CB3PageTextComponent *, int);  // CB3MenuComponentBase::Construct(int)

// func_00379450 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00379450
extern "C" int func_00379450(UnkStruct_00379450 * self)
{
    GtMathPs2::CGtV2d pos;
    UnkStruct_00379450_obj * t0 = self->field_20;
    UnkStruct_00379450_obj * t1 = self->field_18;
    if (t1->field_8.Y() < t0->field_8.Y() - kB3PageTextBorder.field_4) {
        float y = 27.0f + self->field_28;
        if (y < t1->field_0.Y() + t1->field_8.Y()) {
            self->field_28 = y;
            GtMathPs2::CGtV2d p(self->field_24->field_0.X(), self->field_28);
            self->field_24->field_0 = p;
            return 1;
        }
        return 0;
    }
    if (27.0f + (self->field_28 + self->field_24->field_8.Y()) < t0->field_0.Y() + t0->field_8.Y()) {
        self->field_28 = self->field_28 + 27.0f;
        GtMathPs2::CGtV2d p(self->field_24->field_0.X(), self->field_28);
        self->field_24->field_0 = p;
        return 1;
    }
    pos = t1->field_0;
    if (pos.Y() <= self->field_1C->field_0.Y() - (t1->field_8.Y() - self->field_1C->field_8.Y())) {
        return 0;
    }
    pos.SetY(pos.Y() - 27.0f);
    t1->field_0 = pos;
    D_01EA4994.field_0 = (short)((self->field_14 - pos.Y()) / 27.0f) - 1;
    return 1;
}

// CB3PageTextComponent::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,EGlobalStrings,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PageTextComponent.cpp.
// 0x00379910
void CB3PageTextComponent::Prepare(const GtMathPs2::CGtV2d& p0, const GtMathPs2::CGtV2d& p1, EGlobalStrings p2, unsigned int p3)
{
    int r0 = func_00271A00(&D_0051BA44, p2, &p1, p2, p3);
    Prepare__20CB3PageTextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPCUsUi(this, &p0, &p1, (const unsigned short*)r0, p3);
}

// CB3PageTextComponent::Construct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PageTextComponent.cpp.
// 0x00379980
void CB3PageTextComponent::Construct()
{
    field_18 = 0;
    field_1C = 0;
    Construct__20CB3MenuComponentBaseFi(this, 2);
}
