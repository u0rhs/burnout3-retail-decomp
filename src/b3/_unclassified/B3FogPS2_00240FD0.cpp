// CB3Fog::SetRenderstates() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3FogPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (each qword stored right after its pcpyld; farFogPlane.field_0 = t0 + 1; third pcpyld operands in instruction order (%1=24, %2=0) for evaluation order).

// lifter variant 0
// CB3Fog::SetRenderstates() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3FogPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3Fog;
struct UnkStruct_00240FD0_1;
struct UnkStruct_farFogPlane;

struct UnkStruct_farFogPlane {
    UnkStruct_00240FD0_1 * field_0;
};

struct UnkStruct_00240FD0_1 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
};

class CB3Fog {
public:
    void SetRenderstates();
};

extern UnkStruct_farFogPlane farFogPlane;

extern "C" void _rwDMAOpenVIFPkt(int, int);

// 0x00240FD0
void CB3Fog::SetRenderstates()
{
    _rwDMAOpenVIFPkt(0x80000000, 3);
    UnkStruct_00240FD0_1 * t0 = farFogPlane.field_0;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x1000000000008002), "r"(14));
    t0->field_0 = q0;
    u_long128 q1;
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"(1), "r"(20));
    t0->field_10 = q1;
    u_long128 q2;
    asm("pcpyld %0, %1, %2" : "=r"(q2) : "r"(24), "r"(0));
    t0->field_20 = q2;
    farFogPlane.field_0 = t0 + 1;
}
