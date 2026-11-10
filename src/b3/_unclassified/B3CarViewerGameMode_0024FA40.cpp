// CB3CarViewerGameMode::UpdateHinges(CB3VehicleEssentialParams*,CB3VehicleParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CarViewerGameMode.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (mwperm: +'// N182: `#pragma opt_optimizecontrolflow off` ([G] scoped to this function; fou'; 'UnkStruct_0024FA40_e * e = ((UnkStruct_0024FA40_p *)p0)->fie' -> 'CB3VehicleEssentialParams * v0 = p0; float t6; unsigned int t3; float t0; int i;'; 'bool mv = !(fabsf(f) < D_004E0F5C.field_0); if (mv) {' -> 'bool t10 = fabsf(f) < (0, t5); unsigned char mv = !(fabsf(f) < D_004E0F5C.field_'; 'float t = D_0052267C.).

#include "b3/GtMath.h"
static inline float fabsf(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
struct UnkStruct_D_004E0F5C { float field_0; };
struct UnkStruct_D_0052267C { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004F6061 { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_004F50C0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004E0F5C D_004E0F5C;
extern UnkStruct_D_0052267C D_0052267C;
extern UnkStruct_D_004F6061 D_004F6061;
extern UnkStruct_D_004F50C0 D_004F50C0;
struct UnkStruct_0024FA40_rec { unsigned char pad_0[0x12C]; };
struct UnkStruct_0024FA40_D { unsigned char pad_0[0xD48]; UnkStruct_0024FA40_rec field_D48[1]; };
struct UnkStruct_0024FA40_e {
    unsigned char pad_0[0xC];
    signed char field_C;
    unsigned char pad_D[0xAEF];
    float field_AFC[1];
};
struct UnkStruct_0024FA40_p { unsigned char pad_0[0x40]; UnkStruct_0024FA40_e * field_40; };
struct UnkStruct_0024FA40_vp { unsigned char pad_0[0xF60]; float field_F60[1]; };
extern "C" float func_0012FC30(void *, int, int);
class CB3VehicleEssentialParams;
class CB3VehicleParams;
class CB3CarViewerGameMode {
public:
    void UpdateHinges(CB3VehicleEssentialParams *, CB3VehicleParams *);
    unsigned char pad_0[0x230];
    float field_230;
    int field_234;
};
// N182: `#pragma opt_optimizecontrolflow off` ([G] scoped to this function; found by mwperm).
#pragma push
#pragma opt_optimizecontrolflow off
static inline bool func_0024FA40_inl1(int a0, UnkStruct_0024FA40_e * a1)
{
    bool t7;
    t7 = a0 < a1->field_C;
    return t7;
}

static inline float func_0024FA40_inl2(float a0)
{
    float t4;
    t4 = (float)a0;
    return t4;
}

// 0x0024FA40
void CB3CarViewerGameMode::UpdateHinges(CB3VehicleEssentialParams * p0, CB3VehicleParams * p1)
{
    CB3VehicleEssentialParams * v0 = p0;
    float t6;
    unsigned int t3;
    float t0;
    int i;
    float t5;
    UnkStruct_0024FA40_e * e;
    float m;
    UnkStruct_0024FA40_e * t1 = (((UnkStruct_0024FA40_p *)(0, v0)))->field_40;
    e = t1;
    e = e;
    float f = func_0012FC30(&((UnkStruct_0024FA40_D *)&D_004F50C0)->field_D48[D_004F6061.field_0], 4, 0);
    bool t10 = fabsf(f) < (0, t5);
    unsigned char mv = !(fabsf(f) < D_004E0F5C.field_0);
    if (1) {
        t3 = t10;
    }
    if (!(mv)) {
    } else {
        switch (field_234) {
        case 2:
            field_234 = 3;
            break;
        case 0:
            field_234 = 1;
            break;
        }
    }
    switch (field_234) {
    case 1:
        if (field_230 < 1.0f) {
            float t14;
            const float * t9 = (const float *)&field_230;
            float t = ((t14 = D_0052267C.field_0 / 0.5f));
            t9 = t9;
            const float t2 = *t9 + t;
            t = t2;
            field_230 = GtMath::Min(GtMath::Max((func_0024FA40_inl2(t)), 0.0f), 1.0f);
        } else {
            field_234 = 2;
        }
        break;
    case 3:
        if (field_230 > 0.0f) {
            t0 = D_0052267C.field_0 / 0.5f;
            float t = t0;
            const float * t8 = (const float *)&field_230;
            if (!(t8 != 0)) {
            } else {
            }
            t = (*t8 + - t);
            m = GtMath::Max(t, 0.0f);
            field_230 = GtMath::Min(m, 1.0f);
        } else {
            field_234 = 0;
        }
        break;
    }
    i = 0;
    goto loop0_t;
loop0:
    t6 = e->field_AFC[i] * field_230;
    int t11 = (int)i;
    ((UnkStruct_0024FA40_vp *)p1)->field_F60[(t11)] = (t6);
    i++;
loop0_t:
    if (!(func_0024FA40_inl1((i ^ 0), e) != 0)) {
    } else {
        goto loop0;
    }
}
