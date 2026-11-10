// CB3OnScreenKeyboardComponent::Update(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (Update; [G] pun on field_30CC arg).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
extern "C" {
unsigned short *CopyN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, unsigned short *);
float GetStringWidth__9CGt2dFontCFPCUs(void *, const unsigned short *);
}
struct UnkStruct_D_00665ED8 { void *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00665ED8 D_00665ED8;
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E90424 D_01E90424;
class CB3OnScreenKeyboardComponent {
public:
    void Update(float);
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0xC];
    unsigned char field_1C;
    unsigned char pad_1D;
    unsigned char field_1E;
    unsigned char pad_1F;
    float field_20;
    unsigned char pad_24[0x6B4];
    CGtV2d field_6D8;
    unsigned char pad_6E0[0x29EC];
    unsigned short *field_30CC;
    unsigned short *field_30D0;
    unsigned short *field_30D4;
    unsigned short *field_30D8;
};
// 0x00351410
void CB3OnScreenKeyboardComponent::Update(float dt)
{
    unsigned short buf[0x40];
    if (D_01E90424.field_0 != 5) return;
    field_20 = field_20 + dt;
    if (field_20 > 0.5f) {
        field_1E = !field_1E;
        field_20 = field_20 - 0.5f;
    }
    int n = (field_30D0 - field_30CC) + 1;
    if (n > 0) {
        CopyN__10CGtUnicodeFPUsiPCUs(field_30D8, n, *(unsigned short *const *)&field_30CC);
        if (field_1C) {
            int i = 0;
            while (i < field_30D0 - field_30CC) {
                field_30D8[i] = 0x2A;
                i++;
            }
            field_30D8[i] = 0;
        }
    } else {
        *field_30D8 = 0;
    }
    CopyN__10CGtUnicodeFPUsiPCUs(buf, (field_C - (field_30CC - field_30D4)) + 1, field_30D8);
    float w;
    if (buf[0] != 0) w = 29.0f * GetStringWidth__9CGt2dFontCFPCUs(D_00665ED8.field_0, buf);
    else w = 0.0f;
    field_6D8 = CGtV2d(w, -2.0f);
    if (field_1E == 0) field_6D8 = CGtV2d(-1.0f, -1.0f);
}
