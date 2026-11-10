// B3GraphicsManager.cpp -- translation unit regrouped by tools/tu_merge.py from 6 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> B3GraphicsManager.cpp, 2 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Graphics, [L] Revenge (SLUS_212.42) GameSource/Graphics/B4GraphicsManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3GraphicsManagerBase.h"
#include "b3/classes/CB3Viewport.h"
#include "b3/classes/CGtCamera.h"
#include "b3/classes/CGtViewport.h"
#include "b3/classes/EB3ViewportSelection.h"

struct UnkStruct_0019E9A0;
struct UnkStruct_0019EA30;
struct UnkStruct_0019EA30_1;

struct UnkStruct_0019E9A0 {
    unsigned char pad_0[0x70];
    float field_70[1];  // [G] element count unknown
};

struct UnkStruct_0019EA30_1 {
    unsigned char pad_0[0x58];
    int field_58;
};

struct UnkStruct_0019EA30 {
    unsigned char pad_0[0x3B0];
    UnkStruct_0019EA30_1 * field_3B0;
    int field_3B4;
};

extern float karDefaultLodSwitchDistances[];  // [G] element count unknown
extern "C" void SetViewportsSinglePlayer__22CB3GraphicsManagerBaseFv(void *, int);
extern "C" void RwCameraEndUpdate(int);
extern "C" void Update__11CB3ViewportFv(void *);  // CB3Viewport::Update()
extern "C" void SetCamera__11CGtViewportFP9CGtCamera(void *, void *);  // CGtViewport::SetCamera(CGtCamera*)

// Hand-written; the lifter refused it (tail call, a1=0).
// 0x0019E990
extern "C" void func_0019E990(void *self) { SetViewportsSinglePlayer__22CB3GraphicsManagerBaseFv(self, 0); }

// SetDefaultLODSwitchDistances__22CB3GraphicsManagerBaseFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0019E9A0
extern "C" void SetDefaultLODSwitchDistances__22CB3GraphicsManagerBaseFv(UnkStruct_0019E9A0 * self)
{
    for (int i = 0; (i < 5); i++) {
        self->field_70[i] = karDefaultLodSwitchDistances[i];
    }
}

// func_0019E9E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0019E9E0
extern "C" int func_0019E9E0(void *n0_, int p0)
{
    int n0 = (int)n0_;
    switch (p0) {
    case 0:
        return (n0 + 784);
    case 1:
        return (n0 + 144);
    case 2:
        return (n0 + 304);
    }
    return 0;
}

// CloseViewport__22CB3GraphicsManagerBaseFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0019EA30
extern "C" void CloseViewport__22CB3GraphicsManagerBaseFv(UnkStruct_0019EA30 * self)
{
    RwCameraEndUpdate(self->field_3B0->field_58);
    self->field_3B0 = 0;
    self->field_3B4 = 0;
}

// CB3GraphicsManagerBase::AttachCameraToViewport(EB3ViewportSelection,CGtCamera*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3GraphicsManager.cpp.
// 0x0019EA70
void CB3GraphicsManagerBase::AttachCameraToViewport(EB3ViewportSelection p0, CGtCamera* p1)
{
    void * v0;
    switch (p0) {
    default:
        v0 = (void *)this;
        break;
    case 0:
        v0 = ((char *)this + 0x310);
        break;
    case 1:
        v0 = ((char *)this + 0x90);
        break;
    case 2:
        v0 = ((char *)this + 0x130);
        break;
    }
    SetCamera__11CGtViewportFP9CGtCamera(v0, p1);
}

// UpdateViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelection -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0019EAC0
extern "C" void UpdateViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelection(void *n0_, int p0)
{
    int n0 = (int)n0_;
    int v0 = n0;
    switch (p0) {
    case 0:
        v0 = (n0 + 784);
        break;
    case 1:
        v0 = (n0 + 144);
        break;
    case 2:
        v0 = (n0 + 304);
        break;
    }
    Update__11CB3ViewportFv((void *)v0);
}
