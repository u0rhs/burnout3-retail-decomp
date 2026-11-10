// CB3LoadingScreenPage::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3LoadingScreenPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// CB3LoadingScreenPage has a header in include/ (pads and a few proven fields only): declared locally instead, as the
// hand-matched units of such classes do (B3AITarget_00149140.cpp) [lift3].
// Hand-finished from the lifted source (parkfix: tool-bug park fixed (N213)).

// CB3LoadingScreenPage::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3LoadingScreenPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a70: 0.8/0.2 are sdata globals D_004E0A40/D_004E0B14 (not literals); t = 0.0f + A; t += B*(c/7)).

// Update__20CB3LoadingScreenPageFv
#include "b3/gamesource/Menu/DebugMenu/Pages/B3LoadingScreenPage.h"

// Unnamed globals and functions, placeholders throughout; padded for N51 (absolute lui/lw addressing).
struct UnkStruct_D_01E91C3C {  // [L] a pending flag: set elsewhere, cleared here once func_00371420 reports done
    bool value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E91C3C D_01E91C3C;
struct UnkStruct_D_01E900B0 {  // the object N62 describes (initialised by func_0030D3B0); only its first word read here
    int field_0;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E900B0 D_01E900B0;
struct UnkStruct_D_0051A99C {  // an int, converted to float (lwc1 + cvt.s.w)
    int value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_0051A99C D_0051A99C;
struct UnkStruct_D_01E8E8A0 {  // field_A tested, then the object passed to func_003CA5D0
    unsigned char pad0[0xA];
    bool field_A;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E8E8A0 D_01E8E8A0;
struct UnkStruct_D_01EA4070;
extern UnkStruct_D_01EA4070 D_01EA4070;
struct UnkStruct_D_00665EC0;
extern UnkStruct_D_00665EC0 D_00665EC0;
struct UnkStruct_D_004E0A40 { float field_0; };
struct UnkStruct_D_004E0B14 { float field_0; };
extern UnkStruct_D_004E0A40 D_004E0A40;
extern UnkStruct_D_004E0B14 D_004E0B14;

extern "C" int func_00371420(UnkStruct_D_01EA4070 *self);        // [G] returns done (tested with beqz)
extern "C" void func_0019DD00(UnkStruct_D_00665EC0 *self, float f);
extern "C" void func_003CA5D0(UnkStruct_D_01E8E8A0 *self);

// 0x00321690
void CB3LoadingScreenPage::Update()
{
    if (D_01E91C3C.value) {
        if (func_00371420(&D_01EA4070)) {
            D_01E91C3C.value = false;
            func_00321500(this);
        }
    }
    if (D_01E900B0.field_0 == 0) {
        float t = 0.0f + D_004E0A40.field_0;
        t += D_004E0B14.field_0 * ((float)D_0051A99C.value / 7.0f);
        if (t > 1.0f)
            t = 1.0f;
        func_0019DD00(&D_00665EC0, t);
    }
    if (D_01E8E8A0.field_A)
        func_003CA5D0(&D_01E8E8A0);
}
