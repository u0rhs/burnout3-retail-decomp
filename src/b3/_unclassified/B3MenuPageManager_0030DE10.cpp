// CB3MenuPageManager::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3MenuPageManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (N182 pragma match (lead): archive source + scoped optimiser pragma).

// Hand-written; lifter refused (a69). CB3MenuPageManager::Prepare() -- the class header does not declare it, so it is
// defined under its mangled name (extern "C").
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"
#include "b3/classes/CB3MenuStringBuffer.h"

// N182: retail compiled this function with `#pragma opt_dead_assignments off` (file-wide consistent: the file's other proven functions stay identical, build/vt/pragma/tucheck.py).
#pragma push
#pragma opt_dead_assignments off

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

// [G] two separate unnamed globals read through lui (an int each, converted with cvt.s.w): screen width/height [G]
struct UnkStruct_D_00665EC0 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00665EC4 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00665EC0 D_00665EC0;
extern UnkStruct_D_00665EC4 D_00665EC4;
extern CB3MenuPageManager D_01ECD9F0;  // placeholder type only for the address passed to func_0042FBC0
struct UnkStruct_D_01EA4070 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01EA4070 D_01EA4070;  // [G] a CB3MenuImages instance (this of CacheGlobalTextures)
extern "C" void CacheGlobalTextures__13CB3MenuImagesFv(void *);
extern "C" void Prepare__15CB3HUDComponentFv();
extern "C" void func_0042FBC0(void *);

extern "C" bool Prepare__18CB3MenuPageManagerFv(CB3MenuPageManager *self)
{
    CGtV2d scale;
    CGtV4d colour;
// 0x0030DE10
    self->field_1A0.Prepare();
    CGt2dFrame *f = self->field_1A0.field_14;
    f->field_0.SetIdentity();
    float w = (float)D_00665EC0.field_0;
    float h = (float)D_00665EC4.field_0;
    colour = CGtV4d(0.5f, 0.5f, 0.5f, 1.0f);
    f->field_0.field_10 = colour;
    scale.marValues[0] = 640.0f * w / 409600.0f;
    scale.marValues[1] = 480.0f * h / 230400.0f;
    f->field_0.field_8 = scale;
    CacheGlobalTextures__13CB3MenuImagesFv(&D_01EA4070);
    Prepare__15CB3HUDComponentFv();
    *(int *)((char *)self + 0x1E4) = 6;
    *(int *)((char *)self + 0x1F4) = 0x17;
    ((CB3MenuStringBuffer *)((char *)self + 0x1F8))->Prepare();
    func_0042FBC0(&D_01ECD9F0);
    return true;
}

#pragma pop
