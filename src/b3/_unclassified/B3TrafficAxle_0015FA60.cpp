// CB3TrafficAxle::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficAxle.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source ([G] placeholder VU inlines (likely CGtV4d::Zero / CGtV3d::Set(f,f,f)) with compiler-chosen registers).

// lifter variant 0
// CB3TrafficAxle::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficAxle.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CB3TrafficAxle;

class CB3TrafficAxle {
public:
    int Prepare();

    GtMathPs2::CGtV4d field_0;
    GtMathPs2::CGtV3d field_10;
    unsigned short field_20;
    unsigned short field_22;
    unsigned short field_24;
    unsigned short field_26;
    int field_28;
    short field_2C;
    unsigned char field_2E;
    unsigned char field_2F;
};

// [G] placeholder inlines standing in for GtMathPs2 inlines this header lacks in this form: inl1 is likely
// CGtV4d::Zero() with a compiler-chosen register (retail: vsub into $vf2, not the header's $vf1), inl2 likely
// CGtV3d::Set(float,float,float) (B3O0PCH map). Retail: x/z's 0.0 in $vf3, y's 1.0 in $vf1, the vector in $vf2.
static inline void func_0015FA60_inl1(GtMathPs2::CGtV4d & v)
{
    u_long128 t;
    asm("vsub.xyzw %0, $vf0, $vf0" : "=j"(t));
    v.mData = t;
}

static inline void func_0015FA60_inl2(GtMathPs2::CGtV3d & v, float x, float y, float z)
{
    u_long128 m = v.mData;
    asm("qmtc2.ni %1, $vf3" "
	" "qmtc2.ni %2, $vf1" "
	" "vaddx.x %0, $vf0, $vf3x" "
	" "vaddx.y %0, $vf0, $vf1x" "
	" "vaddx.z %0, $vf0, $vf3x"
        : "+j"(m) : "r"(x), "r"(y));
    v.mData = m;
}

// 0x0015FA60
int CB3TrafficAxle::Prepare()
{
    field_2E = 255;
    field_2C = -1;
    field_2F = 255;
    field_20 = 65535;
    field_22 = 65535;
    field_24 = 65535;
    field_26 = 65535;
    field_28 = 0;
    func_0015FA60_inl1(field_0);
    func_0015FA60_inl2(field_10, 0.0f, 1.0f, 0.0f);
    return 1;
}
