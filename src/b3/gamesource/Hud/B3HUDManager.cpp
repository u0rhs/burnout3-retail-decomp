// B3HUDManager.cpp -- translation unit regrouped by tools/tu_merge.py from 6 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3HUDManager.cpp, 3 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Hud, [L] Revenge (SLUS_212.42) GameSource/Hud/B4HUDManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3HUD.h"
#include "b3/classes/CB3HUDComponent.h"
#include "b3/classes/EHUDMode.h"
#include "b3/classes/UnkStruct_D_004B7650.h"
#include "b3/classes/UnkStruct_D_00665ECF.h"
#include "b3/classes/UnkStruct_D_00665F2B.h"

struct UnkStruct_001A0660;
struct UnkStruct_001A0790;
struct UnkStruct_001A0790_e0;
struct UnkStruct_001A08D0;
struct UnkStruct_001A08D0_e0;
struct UnkStruct_001A0930;
struct UnkStruct_001A0930_e0;

struct UnkStruct_001A0660 {
    unsigned char pad_0[0x48];
    float field_48;
    float field_4C;
    float field_50;
    float field_54;
    unsigned char pad_58[0x60];
    float field_B8;
    float field_BC;
    float field_C0;
    float field_C4;
    unsigned char pad_C8[0xA8];
    int field_170;
};

struct UnkStruct_001A0790_e0 {
    unsigned char pad_0[0x70];
};

struct UnkStruct_001A0790 {
    UnkStruct_001A0790_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_70[0x100];
    int field_170;
};

struct UnkStruct_001A08D0_e0 {
    unsigned char pad_0[0x70];
};

struct UnkStruct_001A08D0 {
    UnkStruct_001A08D0_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_70[0x100];
    int field_170;
};

struct UnkStruct_001A0930_e0 {
    unsigned char pad_0[0x70];
};

struct UnkStruct_001A0930 {
    UnkStruct_001A0930_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_70[0x100];
    int field_170;
};

extern float D_004E0C50;
extern int _kxHUDModeFlags[];  // [G] element count unknown
extern UnkStruct_D_00665ECF D_00665ECF;
extern UnkStruct_D_00665F2B D_00665F2B;
extern UnkStruct_D_004B7650 D_004B7650;
extern "C" void Render__10CGt2dSceneFv(void *);  // CGt2dScene::Render()
extern "C" void SetHUDMode__6CB3HUDF8EHUDMode(void *, EHUDMode);  // CB3HUD::SetHUDMode(EHUDMode)
extern "C" void Update__15CB3HUDComponentFv(void *);  // CB3HUDComponent::Update()
extern "C" void Update__6CB3HUDFf(void *, float);  // CB3HUD::Update(float)

// CB3HUD::Update(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDManager.cpp.
// 0x001A03A0
void CB3HUD::Update(float p0)
{
    UnkStruct_001A03A0_m * h = field_68;
    UnkStruct_001A03A0_m * m;
    if (field_0 != -1.0f) {
        field_0 = field_0 - p0;
        if (field_0 < 0.0f) {
            field_0 = 0.0f;
        }
        float k = 1.0f - field_0 / D_004E0C50;
        m = field_68;
        int fa = _kxHUDModeFlags[field_4];
        int fb = _kxHUDModeFlags[field_8];
        for (; m != 0; m = m->field_C) {
            bool in = (m->field_14 & fa) != 0;
            bool out = (m->field_14 & fb) != 0;
            if (in != out) {
                m->vfunc_C(in, field_4, field_8, k);
            } else if (in && k == 1.0f) {
                m->vfunc_C(in, field_4, field_8, k);
            }
        }
        if (field_0 == 0.0f) {
            if (field_C != 6) {
                SetHUDMode((EHUDMode)field_C);
            } else {
                field_0 = -1.0f;
            }
        }
    }
    for (; h != 0; h = h->field_C) {
        h->vfunc_8(p0);
    }
}

// func_001A0660 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001A0660
extern "C" void func_001A0660(UnkStruct_001A0660 * self, int p0)
{
    self->field_170 = p0;
    if (self->field_170 == 2) {
        if (D_00665ECF.field_0 != 0) {
            self->field_48 = 30.0f;
            self->field_4C = 22.0f;
            *(int *)&self->field_50 = 0x43910000;
            self->field_54 = 458.0f;
            self->field_B8 = 350.0f;
            self->field_BC = 22.0f;
            self->field_C0 = ((float)610);
            self->field_C4 = 458.0f;
        } else {
            self->field_48 = 30.0f;
            self->field_4C = 22.0f;
            self->field_50 = ((float)610);
            self->field_54 = 218.0f;
            self->field_B8 = 30.0f;
            self->field_BC = 262.0f;
            self->field_C0 = ((float)610);
            self->field_C4 = 458.0f;
        }
    } else {
        self->field_48 = 30.0f;
        self->field_4C = 22.0f;
        self->field_50 = ((float)610);
        self->field_54 = 458.0f;
        self->field_B8 = 0.0f;
        self->field_BC = 0.0f;
        self->field_C0 = 0.0f;
        self->field_C4 = 0.0f;
    }
}

// func_001A0760 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001A0760
// [L] returns the 8-byte element by value (a0 = hidden result pointer, a1 unread, a2 = index)
extern "C" UnkStruct_001A0760_e0 func_001A0760(int p0, int p1)
{
    return D_004B7650.field_0[p1];
}

// Render__13CB3HUDManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001A0790
extern "C" void Render__13CB3HUDManagerFv(UnkStruct_001A0790 * self)
{
    if (D_00665F2B.field_0 == 0) return;
    for (int i = 0; (i < self->field_170); i++) {
        Render__10CGt2dSceneFv(((char *)&self->field_0[i] + 0x14));
    }
}

// func_001A08D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001A08D0
extern "C" void func_001A08D0(UnkStruct_001A08D0 * self)
{
    for (int i = 0; (i < self->field_170); i++) {
        SetHUDMode__6CB3HUDF8EHUDMode(&self->field_0[i], (EHUDMode)1);
    }
}

// Update__13CB3HUDManagerFf -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001A0930
extern "C" void Update__13CB3HUDManagerFf(UnkStruct_001A0930 * self, float f0)
{
    Update__15CB3HUDComponentFv(self);
    for (int i = 0; (i < self->field_170); i++) {
        Update__6CB3HUDFf(&self->field_0[i], f0);
    }
}
