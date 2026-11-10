// CB3AIAvoidanceMap::CalculateCarCoverage() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAvoidance.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near21: 0.3f lit4 literal; two-statement mula/madd; two DotProduct stand-ins (GPR-round-trip first, noreorder tail second) [L] N185).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
// [L] N185: file-local stand-ins for DotProduct in retail's two straight-line shapes (1.0 parked in a GPR):
static inline float n21_abs(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
static inline float n21_f(u_long128 x) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(x)); return f; }
static inline u_long128 n21_one() { u_long128 one; asm("vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %0, $vf1" : "=r"(one)); return one; }
// first dot: the product on a compiler-chosen register, moved through a GPR into a hard-coded $vf2 for the ACC tail
// (retail 0x13D92C: vmul.xyz $vf1; qmfc2 v1,$vf1; qmtc2 v1,$vf2; vadday $vf2)
static inline u_long128 n21_dot1(u_long128 a, u_long128 b)
{
    u_long128 one = n21_one();
    u_long128 m, mr, d;
    asm("vmul.xyz %0, %1, %2" : "=j"(m) : "j"(a), "j"(b));
    asm("qmfc2.i %0, %1" : "=r"(mr) : "j"(m));
    asm("qmtc2.i %1, $vf2" "\n\t" "vadday.x $ACC, $vf2, $vf2y" "\n\t" "qmtc2.i %2, $vf1" "\n\t" "vmaddz.x $vf1, $vf1, $vf2z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(d) : "r"(mr), "r"(one));
    return d;
}
// second dot: product + ACC sum on compiler-chosen registers, then the parked 1.0 tail in a noreorder region
// (N188: keeps the result's qmfc2 right after vmaddz, retail 0x13D970)
static inline u_long128 n21_dot2(u_long128 a, u_long128 b)
{
    u_long128 one = n21_one();
    u_long128 m, d;
    asm("vmul.xyz %0, %1, %2" "\n\t" "vadday.x $ACC, %0, %0y" : "=j"(m) : "j"(a), "j"(b));
    asm(".set noreorder");
    asm("qmtc2.i %1, $vf1" "\n\t" "vmaddz.x $vf1, $vf1, %2z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(d) : "r"(one), "j"(m));
    asm(".set reorder");
    return d;
}
struct UnkStruct_0013D910_car { unsigned char pad_0[0x20]; CGtV3d field_20; };
struct UnkStruct_0013D910_obj { unsigned char pad_0[0x204]; UnkStruct_0013D910_car *field_204; };
struct UnkStruct_0013D910_o {
    unsigned char pad_0[0x1AE0];
    CGtV3d field_1AE0;
    CGtV3d field_1AF0;
    unsigned char pad_1B00[0x930];
    UnkStruct_0013D910_obj *field_2430;
    float field_2434;
    float field_2438;
};
class CB3AIAvoidanceMap {
public:
    void CalculateCarCoverage();
    unsigned char pad_0[0x440];
    unsigned char field_440;
    unsigned char field_441;
    unsigned char field_442;
    unsigned char pad_443[0x11];
    UnkStruct_0013D910_o *field_454;
};
// 0x0013D910
void CB3AIAvoidanceMap::CalculateCarCoverage()
{
    UnkStruct_0013D910_o *o = field_454;
    u_long128 c = o->field_2430->field_204->field_20.mData;
    float a = n21_abs(n21_f(n21_dot1(o->field_1AE0.mData, c)));
    float b = n21_abs(n21_f(n21_dot2(o->field_1AF0.mData, c)));
    // 0.3f is .lit4 D_004E0AAC; two statements give retail's mula (0.3*b*f2438) / madd order
    float f = 0.3f * b * o->field_2438;
    f += 0.5f * a * o->field_2434;
    int i = (int)(5.0f * f);
    int v = i + 128;
    int x = v;
    x += 1;
    int y;
    if (x < 256) {
        int w = (int)(5.0f * -f) + 128;
        y = w;
        y -= 1;
        if (y < 0) {
            y = 0;
            x = i * 2;
        }
    } else {
        x = 255;
        y = 255 - i * 2;
    }
    field_441 = x;
    field_442 = y;
    field_440 = i * 2 + 2;
}
