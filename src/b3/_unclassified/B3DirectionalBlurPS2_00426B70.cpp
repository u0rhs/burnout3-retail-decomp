// CB3DirectionalBlur::SetRenderstates() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DirectionalBlurPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (GIF quads: lo-first pcpyld asm per quad into locals, zero half as an unsigned long declared early and assigned after the first quad (shares one daddu reg), end pointer t0 + 1).

// lifter variant 0
// CB3DirectionalBlur::SetRenderstates() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DirectionalBlurPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3DirectionalBlur;
struct UnkStruct_00426B70_1;
struct UnkStruct_farFogPlane;

struct UnkStruct_farFogPlane {
    UnkStruct_00426B70_1 * field_0;
};

struct UnkStruct_00426B70_1 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    u_long128 field_30;
    u_long128 field_40;
    u_long128 field_50;
};

class CB3DirectionalBlur {
public:
    void SetRenderstates();
};

extern UnkStruct_farFogPlane farFogPlane;


// 0x00426B70
void CB3DirectionalBlur::SetRenderstates()
{
    UnkStruct_00426B70_1 * t0 = farFogPlane.field_0;
    unsigned long z;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x1000000000000005), "r"(14));
    z = 0;
    t0->field_0 = q0;
    u_long128 q1;
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"(0x7FF000007FF0000), "r"(64));
    u_long128 q2;
    asm("pcpyld %0, %2, %1" : "=r"(q2) : "r"(z), "r"(24));
    t0->field_10 = q1;
    t0->field_20 = q2;
    u_long128 q3;
    asm("pcpyld %0, %2, %1" : "=r"(q3) : "r"(97), "r"(20));
    t0->field_30 = q3;
    u_long128 q4;
    asm("pcpyld %0, %2, %1" : "=r"(q4) : "r"(0x3F80000080808080), "r"(1));
    t0->field_40 = q4;
    u_long128 q5;
    asm("pcpyld %0, %2, %1" : "=r"(q5) : "r"(0x31001), "r"(71));
    t0->field_50 = q5;
    farFogPlane.field_0 = t0 + 1;
}
