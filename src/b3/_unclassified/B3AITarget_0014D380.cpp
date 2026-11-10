// CB3AITarget::ResetCornerStatus() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AITarget.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// CB3AITarget has a header in include/ (pads and a few proven fields only): declared locally instead, as the
// hand-matched units of such classes do (B3AITarget_00149140.cpp) [lift3].
// Hand-finished from the lifted source (a218: last VU zero store (field_250) moved to end so sqc2 lands in jr delay slot).


#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_a187_c {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char pad_3;
    unsigned short field_4;
    unsigned short field_6;
    unsigned short field_8;
    unsigned short field_A;
    int field_C;
    int field_10;
};
static inline void a187_zero(CGtV3d &v) { u_long128 t; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(t)); v.mData = t; }
class CB3AITarget {
public:
    void ResetCornerStatus();
    unsigned char pad_0[0x1D8];
    unsigned short field_1D8;
    unsigned char pad_1DA[0x19];
    unsigned char field_1F3;
    int field_1F4;
    int field_1F8;
    int field_1FC;
    unsigned char pad_200[0x10];
    unsigned short field_210;
    unsigned short pad_212;
    unsigned short field_214;
    unsigned short field_216;
    unsigned short field_218;
    unsigned char pad_21A[6];
    CGtV3d field_220;
    CGtV3d field_230;
    CGtV3d field_240;
    CGtV3d field_250;
    unsigned char field_260;
    unsigned char field_261;
    unsigned char field_262;
    unsigned char pad_263;
    unsigned short field_264;
    unsigned short field_266;
    unsigned short field_268;
    unsigned char pad_26A[2];
    int field_26C;
    int field_270;
    int field_274;
    unsigned char pad_278[0x2C];
    unsigned short field_2A4;
    unsigned short field_2A6;
};
// 0x0014D380
void CB3AITarget::ResetCornerStatus()
{
    field_1F8 = 2;
    field_1FC = 2;
        field_1F4 = 5;
    field_1F3 = 0;
    field_214 = 0xFFFF;
    field_216 = 0xFFFF;
        field_218 = field_1D8;
        field_210 = field_1D8;
        field_2A4 = 0xFFFF;
    field_2A6 = 0xFFFF;
    a187_zero(field_220);
    a187_zero(field_230);
    a187_zero(field_240);
    field_260 = 0xFF;
    field_264 = 0xFFFF;
    field_26C = 16;
    field_261 = 0xFF;
    field_266 = 0xFFFF;
    field_270 = 16;
    field_262 = 0xFF;
    field_268 = 0xFFFF;
    field_274 = 16;
    a187_zero(field_250);
}
