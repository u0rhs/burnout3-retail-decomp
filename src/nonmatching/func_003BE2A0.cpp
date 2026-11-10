// NONMATCHING: func_003BE2A0 -- retail 192 / ours 192 instructions, 120 in changed runs
// a83: 192/192 instrs, logic right (frame D4/D8 SetIdentity, objects loop, lerp(776,x,0) via adda/madd, CGtV2d temps); remaining = saved-reg assignment (retail s0 scene s1 entry s2 this s3 root s4 layer s5 sel/i s6 layer+1; ours rotated) + float reg numbers in the tail; decl order permutations do not change it
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003BE2A0 -- CB3VOptionsSelectComponent::Prepare(const CB3MenuComponentSelectionData*, CB3VOptionsSelectComponentEntryData*) [L] DNAT
// (research/proto/new_names.csv, medium); retail takes a leading float.
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"
using GtMathPs2::CGtV2d;
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_F { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_003BE2A0_sel {
    unsigned short field_0;
    unsigned short field_2;
};
struct UnkStruct_003BE2A0_ent {
    unsigned char pad_0[0xD];
    unsigned char field_D;
    unsigned char pad_E[6];
};
struct UnkStruct_003BE2A0_obj {
    unsigned char pad_0[0x8];
    float field_8;
};
struct UnkStruct_003BE2A0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[2];
    UnkStruct_003BE2A0_sel * field_C;
    UnkStruct_003BE2A0_ent * field_10;
    UnkStruct_003BE2A0_obj * field_14[9];
    int field_38[9];
    int field_5C[9];
    int field_80[9];
    unsigned char pad_A4[8];
    short * field_AC[9];
    UnkStruct_003BE2A0_obj * field_D0;
    CGt2dFrame * field_D4;
    CGt2dFrame * field_D8;
    int field_DC;
    float field_E0;
    float field_E4;
};
extern CGt2dScene D_01E903E0;
extern UnkStruct_P D_01E90438, D_01E90350;
extern UnkStruct_F D_004CA2A0, D_004CA2D0, D_004CA2C8, D_004CA298;
extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_003BD760(void *, int, int, float);
extern "C" void func_003BE040(void *, int, int, float);
extern "C" void func_00372400(void *, CGtV2d *, CGtV2d *, void *, float, float, float);

// [L] DNAT: CB3VOptionsSelectComponent::Prepare(const CB3MenuComponentSelectionData*,CB3VOptionsSelectComponentEntryData*) (research/proto/new_names.csv, medium)
// 0x003BE2A0
extern "C" int func_003BE2A0(UnkStruct_003BE2A0 * self, const UnkStruct_003BE2A0_sel * sel, UnkStruct_003BE2A0_ent * entry, float p)
{
    Prepare__20CB3MenuComponentBaseFv(self);
    CGt2dScene * const scene = &D_01E903E0;
    int layer = self->field_8;
    CGt2dFrame * root = scene->field_14;
    int layer1 = layer + 1;
    self->field_C = (UnkStruct_003BE2A0_sel *)sel;
    self->field_10 = entry;
    self->field_DC = -1;
    self->field_E0 = -1.0f;
    float h = 32.0f * (float)(int)self->field_C->field_2;
    self->field_E4 = p - 0.5f * h;
    self->field_D4 = root->ConstructChild();
    self->field_D4->field_0.SetIdentity();
    CGtV2d pos;
    CGtV2d ext;
    pos.Set(D_004CA2A0.field_0, self->field_E4 - 48.0f);
    ext.Set(D_004CA2D0.field_0 - 5.0f, 64.0f + h);
    self->field_D4->field_0.field_0 = pos;
    self->field_D4->field_0.field_8 = ext;
    scene->field_2c[layer + 3].field_c = self->field_D4;
    self->field_D8 = root->ConstructChild();
    self->field_D8->field_0.SetIdentity();
    float k = D_004CA2C8.field_0;
    for (int i = 0; i < self->field_C->field_2; i++) {
        self->field_14[i] = (UnkStruct_003BE2A0_obj *)scene->ConstructObject(layer1, self->field_D8);
        self->field_38[i] = 0;
        self->field_5C[i] = 0;
        self->field_80[i] = 0;
        unsigned char t = entry[i].field_D;
        if (t != 0) {
            if (t == 5 && self->field_AC[i] == 0) {
                self->field_AC[i] = (short *)AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 6);
                *self->field_AC[i] = 0;
            }
            func_003BD760(self, i, 0, k);
        }
        func_003BE040(self, i, 0, -252.0f);
    }
    self->field_D0 = (UnkStruct_003BE2A0_obj *)scene->ConstructObject(layer, self->field_D8);
    float x = D_004CA298.field_0 + self->field_14[self->field_C->field_0]->field_8;
    float lerp = 776.0f + (x - 776.0f) * 0.0f;
    float d = lerp - x;
    CGtV2d a;
    CGtV2d b;
    a.Set(0.0f, 0.5f);
    b.Set(-0.5f * d, self->field_E4 + 32.0f * (float)(int)self->field_C->field_0);
    func_00372400(self->field_D0, &b, &a, &D_01E90350, 640.0f + d, 68.0f, lerp);
    return 1;
}
