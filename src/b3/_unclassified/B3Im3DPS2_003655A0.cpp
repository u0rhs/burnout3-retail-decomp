// B3Im3d::EndRendering() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Im3DPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (field_20 copy before q2 asm; pointer advance as t0+0x40 (sibling SetRenderstates shape)).

// lifter variant 0
// B3Im3d::EndRendering() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Im3DPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class B3Im3d;
struct UnkStruct_003655A0_1;
struct UnkStruct_003655A0_3;
struct UnkStruct_farFogPlane;

struct UnkStruct_farFogPlane {
    UnkStruct_003655A0_1 * field_0;
};

struct UnkStruct_003655A0_1 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    u_long128 field_30;
};

struct UnkStruct_003655A0_3 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

class B3Im3d {
public:
    void EndRendering();
    static UnkStruct_003655A0_3 * _gpau128Registers;
    static unsigned char _gbIsReady;
};

extern UnkStruct_farFogPlane farFogPlane;

extern "C" void _rwDMAOpenVIFPkt(int, int);

// 0x003655A0
void B3Im3d::EndRendering()
{
    _rwDMAOpenVIFPkt(0, 4);
    UnkStruct_003655A0_1 * t0 = farFogPlane.field_0;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x10000003), "r"(0x5000000311000000));
    t0->field_0 = q0;
    u_long128 q1;
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"(0x1000000000008002), "r"(14));
    t0->field_10 = q1;
    t0->field_20 = B3Im3d::_gpau128Registers->field_10;
    u_long128 q2;
    asm("pcpyld %0, %2, %1" : "=r"(q2) : "r"(0x8000000044), "r"(66));
    t0->field_30 = q2;
    farFogPlane.field_0 = (UnkStruct_003655A0_1 *)((char *)t0 + 0x40);
    B3Im3d::_gbIsReady = 0;
}
