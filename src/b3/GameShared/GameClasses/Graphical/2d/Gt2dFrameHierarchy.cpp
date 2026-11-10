// Gt2dFrameHierarchy.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py); 3 more added by hand (N151 pattern, below).
// [C]/[L] membership: 0 function(s) named in research/retail_names.csv -> Gt2dFrameHierarchy.cpp, 5 placed between two of them by address contiguity (N2).
// Area: src/b3/GameShared/GameClasses/Graphical/2d, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Graphical/2d/Gt2dFrameHierarchy.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

// Auto-inlining with deferred code generation (N151): retail's Clean (0x1D51C0) is itself recursively
// auto-inlined, and Prepare (0x1D4F90, lower address) and Destruct (0x1D5B10) inline it; Prepare inlining the
// later-defined Clean needs deferred codegen. The accessors func_001D4EB0/4E70/4E60 must be inlinable (defined first).
// a95 found the shape (build/vt/hand/*_a95*.cpp); tools/tu_merge.py leaves a file with pragmas alone (SKIP).
#pragma auto_inline on
#pragma defer_codegen on
// [G] N250/N237: CGt2dFrame::Sync's recursive auto-inline (retail's 8-level ladder) needs the auto-inline size budget
// raised from the default 15 statements to 17 (each inlined asm statement of CGtV4d::operator* counts one). The
// proven functions of this file compile identically with it (build/vt/cc1/ghA-C, build/vt/hand/use1_Gt2dFrameHierarchy.log).
#pragma inline_max_auto_size(17)

#include "b3/GtMathPs2.h"
struct GtLListTag;
extern "C" void RemoveAllLinks__11CGtFreeListFv(GtLListTag *);
struct GtLLLinkTag;
extern "C" void RemoveLink__11CGtFreeListFP15CGtFreeListLink(GtLListTag *, GtLLLinkTag *);
struct UnkStruct_Gt2dFrame;
struct UnkStruct_Gt2dLink;
struct UnkStruct_Gt2dList {
    int field_0;
    UnkStruct_Gt2dLink * field_4;
};
struct UnkStruct_Gt2dSpace {
    GtMathPs2::CGtV2d field_0;
    GtMathPs2::CGtV2d field_8;
    GtMathPs2::CGtV4d field_10;
    void SetIdentity() {
        field_0.Set(0.0f, 0.0f);
        field_8.Set(1.0f, 1.0f);
        field_10 = GtMathPs2::CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
    }
};
struct UnkStruct_Gt2dFrame {
    UnkStruct_Gt2dSpace field_0;
    UnkStruct_Gt2dSpace field_20;
    UnkStruct_Gt2dList field_40;
    UnkStruct_Gt2dFrame * field_48;
};
struct GtLListPoolTag;
extern "C" void SortFree__15CGtFreeListPoolFv(GtLListPoolTag *);
struct UnkStruct_Gt2dHier {
    unsigned char pad_0[0x14];
    UnkStruct_Gt2dFrame * field_14;
};
struct UnkStruct_Gt2dLink {
    UnkStruct_Gt2dLink * field_0;
    unsigned int field_4;
};
extern "C" void Clean__10CGt2dFrameFv(UnkStruct_Gt2dFrame * self);
typedef unsigned int u_long128 __attribute__((mode(TI)));


// func_001D4E60 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001D4E60
extern "C" UnkStruct_Gt2dLink * func_001D4E60(UnkStruct_Gt2dLink * l) { return l->field_0; }

// func_001D4E70 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001D4E70
extern "C" UnkStruct_Gt2dLink * func_001D4E70(UnkStruct_Gt2dList * f) { return f->field_4; }

// func_001D4E80 = GtMathPs2::CGtV4d::operator=(const CGtV4d&) [L] (E_B3INTERN 0x1C92C0, same order and size 0x10):
// no longer defined here -- the header's inline operator= is emitted out of line by this file (Sync's level-7 call),
// as __as__Q29GtMathPs26CGtV4dFRCQ29GtMathPs26CGtV4d. Its old extern "C" stand-in would duplicate it.

// __as__Q29GtMathPs26CGtV2dFRCQ29GtMathPs26CGtV2d (0x001D4E90) = CGtV2d's compiler-generated (implicit) operator=,
// emitted out of line by this file once Sync uses it [C]: an extern "C" stand-in under the same symbol makes b119
// fail with an internal error (ELFgen.c:468, build/vt/hand/use1_t1.cpp) because the two definitions collide.

// func_001D4EB0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001D4EB0
extern "C" UnkStruct_Gt2dFrame * func_001D4EB0(UnkStruct_Gt2dLink * l) { return (UnkStruct_Gt2dFrame *)((char *)l + 8); }

// func_001D4780 = CGt2dFrameHierarchy::Sync() [L] (E_B3INTERN 0x1C8BD0, size 0x6D0 vs retail 0x6D8; E_dnat file
// Gt2dFrameHierarchy.cpp). Copies the root frame's local space to its world space (the implicit
// CGt2dFrame::CGt2dFrameSpace::operator=, E_B3O0PCH: ld/sd, ld/sd, lq/sq) and syncs every child of the root.
// CGt2dFrame::Sync is auto-inlined into it recursively (see Sync below). use1, 2026-10-28.
extern "C" void Sync__10CGt2dFrameFRCQ210CGt2dFrame15CGt2dFrameSpace(UnkStruct_Gt2dFrame * self, const UnkStruct_Gt2dSpace & parent);
// 0x001D4780
extern "C" void func_001D4780(UnkStruct_Gt2dHier * self)
{
    self->field_14->field_20 = self->field_14->field_0;
    for (UnkStruct_Gt2dLink * l = func_001D4E70(&self->field_14->field_40); l != 0; l = func_001D4E60(l)) {
        Sync__10CGt2dFrameFRCQ210CGt2dFrame15CGt2dFrameSpace(func_001D4EB0(l), self->field_14->field_20);
    }
}

// Prepare__19CGt2dFrameHierarchyFv -- [C] name: retail tables; extern "C" under its mangled symbol with local placeholder structs (Gt2dFrame.h lacks
// Clean/field_20/field_48). Hand-matched by a95, installed by gt2d (N151 pattern).
// 0x001D4F90
extern "C" void Prepare__19CGt2dFrameHierarchyFv(UnkStruct_Gt2dHier * self)
{
    Clean__10CGt2dFrameFv(self->field_14);
    self->field_14->field_0.SetIdentity();
    self->field_14->field_20.SetIdentity();
    SortFree__15CGtFreeListPoolFv((GtLListPoolTag *)self);
}

// Clean__10CGt2dFrameFv -- [C] name: retail tables; extern "C" under its mangled symbol with local placeholder structs (Gt2dFrame.h lacks
// Clean/field_20/field_48). Hand-matched by a95, installed by gt2d (N151 pattern).
// 0x001D51C0
extern "C" void Clean__10CGt2dFrameFv(UnkStruct_Gt2dFrame * self)
{
    for (UnkStruct_Gt2dLink * l = func_001D4E70(&self->field_40); l != 0; l = func_001D4E60(l)) {
        Clean__10CGt2dFrameFv(func_001D4EB0(l));
    }
    RemoveAllLinks__11CGtFreeListFv((GtLListTag *)&self->field_40);
}

// Sync__10CGt2dFrameFRCQ210CGt2dFrame15CGt2dFrameSpace -- [C] name: retail tables (E_B3INTERN 0x1C97F0,
// CGt2dFrame::Sync(const CGt2dFrame::CGt2dFrameSpace&)). World space = local space combined with the parent's world
// space: position scaled by the parent's scale plus the parent's position, scale times scale, colour times colour
// (field roles [G]); then every child is synced against this frame's world space. With inline_max_auto_size(17)
// b119 auto-inlines the recursion like retail: levels 0-4 fully, then the CGtV2d/CGtV4d helpers drop out of line
// (__ct__CGtV2dFff / copy ctor at level 5, operators at 6-7, Sync itself at 7). use1, 2026-10-28.
// 0x001D53B0
extern "C" void Sync__10CGt2dFrameFRCQ210CGt2dFrame15CGt2dFrameSpace(UnkStruct_Gt2dFrame * self, const UnkStruct_Gt2dSpace & parent)
{
    self->field_20.field_0 = self->field_0.field_0 * parent.field_8 + parent.field_0;
    self->field_20.field_8 = self->field_0.field_8 * parent.field_8;
    self->field_20.field_10 = self->field_0.field_10 * parent.field_10;
    for (UnkStruct_Gt2dLink * l = func_001D4E70(&self->field_40); l != 0; l = func_001D4E60(l)) {
        Sync__10CGt2dFrameFRCQ210CGt2dFrame15CGt2dFrameSpace(func_001D4EB0(l), self->field_20);
    }
}

// Destruct__10CGt2dFrameFv -- [C] name: retail tables; extern "C" under its mangled symbol with local placeholder structs (Gt2dFrame.h lacks
// Clean/field_20/field_48). Hand-matched by a95, installed by gt2d (N151 pattern).
// 0x001D5B10
extern "C" void Destruct__10CGt2dFrameFv(UnkStruct_Gt2dFrame * self)
{
    Clean__10CGt2dFrameFv(self);
    RemoveLink__11CGtFreeListFP15CGtFreeListLink((GtLListTag *)&self->field_48->field_40, (GtLLLinkTag *)((char *)self - 8));
}
