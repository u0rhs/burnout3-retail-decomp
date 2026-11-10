// CB3HUDScore::Prepare(int,EHUDAlign,int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3HUDScore.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a93: flag tests (p3&m)==m, r<=1, sub-struct at +0x2C).

#include "b3/classes/UnkStruct_D_0051BA88.h"

enum EHUDAlign {};
struct UnkStruct_D_00522660 { unsigned char pad_0[0x27D0]; };
struct UnkStruct_D_0064D378 {
    unsigned char field_0;
    unsigned char pad_1[0xF];
};
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051B934 {
    unsigned char * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_HS_sub {
    int field_0;
    void * field_4;
    unsigned char pad_8[0x80];
    int field_88;
};
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0064D378 D_0064D378;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_0051B934 D_0051B934;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern "C" void Prepare__15CB3HUDComponentFiiii9EHUDAligni(void *, int, int, int, int, EHUDAlign, int);
extern "C" void AdjustScalingForSplitScreen__15CB3HUDComponentFv(void *);
extern "C" void func_0019F350(void *);
extern "C" int func_00131CE0(void *);
extern "C" unsigned char func_003E9700(long);
extern "C" void * ConstructChild__10CGt2dFrameFv(void *);
extern "C" void SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(void *);

class CB3HUDScore {
public:
    int Prepare(int p0, EHUDAlign p1, int p2, int p3);

    unsigned char pad_0[0x8];
    void * field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0xE];
    int field_20[3];
    UnkStruct_HS_sub field_2C;
    unsigned char pad_B8[0x8];
    int field_C0;
    short field_C4;
    unsigned char pad_C6[0x2];
    void * field_C8;
    void * field_CC;
    int field_D0;
    int field_D4;
    int field_D8;
    int field_DC[2];
    int field_E4;
    unsigned char pad_E8[0x20];
    int field_108;
    int field_10C;
    float field_110;
    int field_114;
    float field_118;
    unsigned char field_11C;
    unsigned char field_11D;
    unsigned char field_11E;
    unsigned char field_11F;
    unsigned char field_120;
    unsigned char field_121;
    unsigned char pad_122[0x2];
    float field_124;
    unsigned char pad_128[0x8];
    float field_130;
    int field_134;
    unsigned char field_138[6];
    bool field_13E;
    bool field_13F;
    bool field_140;
    bool field_141;
    bool field_142;
};

// 0x001A37A0
int CB3HUDScore::Prepare(int p0, EHUDAlign p1, int p2, int p3)
{
    Prepare__15CB3HUDComponentFiiii9EHUDAligni(this, 2, 4, 2, p0, p1, p2);
    AdjustScalingForSplitScreen__15CB3HUDComponentFv(this);
    func_0019F350(this);
    field_D0 = p0;
    field_C8 = (char *)&D_00522660 + field_D0 * 0x27D0 + 0x12AD50;
    field_CC = (char *)field_C8 + 0x10C0;
    field_13E = (p3 & 0x10) != 0x10;
    field_13F = (p3 & 1) == 1;
    field_140 = (p3 & 2) == 2;
    field_141 = (p3 & 4) == 4;
    field_142 = (p3 & 8) == 8;
    field_121 = 0;
    if (func_00131CE0(&D_004EE040) != 0) {
        if (D_0051B934.field_0 != 0) {
            field_121 = func_003E9700(*(long *)(D_0051B934.field_0 + 8));
        }
    }
    int r = D_0051BA88.field_0->vfunc_20();
    if (D_0064D378.field_0 != 0 || r <= 1) {
        field_140 = false;
    }
    field_D4 = 0;
    field_D8 = 0;
    field_110 = -1.0f;
    field_108 = 0;
    field_10C = 0;
    field_114 = 0;
    field_11C = 0;
    field_11D = 0;
    field_11E = 0;
    field_11F = 0;
    field_120 = 0;
    field_124 = 5.0f;
    for (int i = 0; i < 3; i++) {
        field_20[i] = 0;
    }
    field_E4 = 0;
    for (int i = 0; i < 2; i++) {
        field_DC[i] = 0;
    }
    field_2C.field_0 = 0;
    UnkStruct_HS_sub * s = &field_2C;
    s->field_4 = ConstructChild__10CGt2dFrameFv(field_8);
    SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(s->field_4);
    s->field_88 = 0;
    field_C4 = field_10;
    field_C0 = 0;
    for (int i = 0; i < 6; i++) {
        field_138[i] = 0;
    }
    field_130 = -5.0f;
    field_134 = 0;
    field_118 = 20.0f;
    return 1;
}
