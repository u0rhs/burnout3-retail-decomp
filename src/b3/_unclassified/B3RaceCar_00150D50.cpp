// CB3RaceCar::UpdateLastPositions() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (header GetSquaredLength + local GetLength stand-in whose tail keeps 1.0 and the result in one GPR (header tail uses two)).

#include "b3/GtMathPs2.h"

class CB3RaceCar {
public:
    void UpdateLastPositions();

    unsigned char pad_0[0x30];
    GtMathPs2::CGtV3d field_30;
    unsigned char pad_40[0x18B8];
    int field_18F8;
    float field_18FC;
    float field_1900[4];
};

// [L] stand-in for CGtV3d::GetLength() (B3O0PCH map): the header body with the 1.0 and the result in ONE GPR
// (retail 0x150D84..0x150D94 qmfc2/qmtc2/qmfc2 all $a1); the header's two-output tail ("=r"(r), "=&r"(one))
// forces two registers (near9, 2 instrs off with the header form). Header fix for the lead.
static inline GtMathPs2::XAxisType func_00150D50_inl1(const GtMathPs2::CGtV3d &v)
{
    GtMathPs2::XAxisType l = v.GetSquaredLength();
    u_long128 r;
    asm(".set noreorder");
    asm("qmtc2.i %1, $vf1" "\n\t" "vsqrt $Q, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %0, $vf1" "\n\t"
        "vwaitq" "\n\t" "qmtc2.i %0, $vf1" "\n\t" "vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %0, $vf1" : "=&r"(r) : "r"(l.lVector));
    asm(".set reorder");
    return GtMathPs2::XAxisType(r);
}
// 0x00150D50
void CB3RaceCar::UpdateLastPositions()
{
    field_1900[field_18F8] = func_00150D50_inl1(field_30);
    field_18F8 = (field_18F8 + 1) % 4;
    float mx = field_1900[0];
    float mn = mx;
    for (int i = 1; i < 4; i++) {
        float v = field_1900[i];
        if (v < mn) {
            mn = v;
        } else if (v > mx) {
            mx = v;
        }
    }
    field_18FC = mx - mn;
}
