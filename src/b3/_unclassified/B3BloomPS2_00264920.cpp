// CB3Bloom::RestoreRenderstates(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BloomPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (pcpyld asm operands for the sky registers in instruction order (%1=const, %2=loaded value); farFogPlane.field_0 = t0 + 1).

// CB3Bloom::RestoreRenderstates(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BloomPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3Bloom;
struct UnkStruct_00264920_1;
struct UnkStruct_farFogPlane;
struct UnkStruct_skyAlpha_1;
struct UnkStruct_skyClamp_1;
struct UnkStruct_skyFrame_1;
struct UnkStruct_skyTest_1;
struct UnkStruct_skyTex1_1;
struct UnkStruct_skyXyoffset_1;
struct UnkStruct_skyZbuf_1;

struct UnkStruct_farFogPlane {
    UnkStruct_00264920_1 * field_0;
};

struct UnkStruct_00264920_1 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    u_long128 field_30;
    u_long128 field_40;
    u_long128 field_50;
    u_long128 field_60;
    u_long128 field_70;
    u_long128 field_80;
};

struct UnkStruct_skyXyoffset_1 {
    unsigned long field_0;
};

struct UnkStruct_skyFrame_1 {
    unsigned long field_0;
};

struct UnkStruct_skyZbuf_1 {
    unsigned long field_0;
};

struct UnkStruct_skyTest_1 {
    unsigned long field_0;
};

struct UnkStruct_skyTex1_1 {
    unsigned long field_0;
};

struct UnkStruct_skyAlpha_1 {
    unsigned long field_0;
};

struct UnkStruct_skyClamp_1 {
    unsigned long field_0;
};

class CB3Bloom {
public:
    void RestoreRenderstates(unsigned long p0);
};

extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_skyXyoffset_1 skyXyoffset_1;
extern UnkStruct_skyFrame_1 skyFrame_1;
extern UnkStruct_skyZbuf_1 skyZbuf_1;
extern UnkStruct_skyTest_1 skyTest_1;
extern UnkStruct_skyTex1_1 skyTex1_1;
extern UnkStruct_skyAlpha_1 skyAlpha_1;
extern UnkStruct_skyClamp_1 skyClamp_1;

// 0x00264920
void CB3Bloom::RestoreRenderstates(unsigned long p0)
{
    UnkStruct_00264920_1 * t0 = farFogPlane.field_0;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x1000000000008008), "r"(14));
    t0->field_0 = q0;
    u_long128 q1;
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"(p0), "r"(64));
    t0->field_10 = q1;
    u_long128 q2;
    asm("pcpyld %0, %1, %2" : "=r"(q2) : "r"(24), "r"(skyXyoffset_1.field_0));
    t0->field_20 = q2;
    u_long128 q3;
    asm("pcpyld %0, %1, %2" : "=r"(q3) : "r"(76), "r"(skyFrame_1.field_0));
    t0->field_30 = q3;
    u_long128 q4;
    asm("pcpyld %0, %1, %2" : "=r"(q4) : "r"(78), "r"(skyZbuf_1.field_0));
    t0->field_40 = q4;
    u_long128 q5;
    asm("pcpyld %0, %1, %2" : "=r"(q5) : "r"(71), "r"(skyTest_1.field_0));
    t0->field_50 = q5;
    u_long128 q6;
    asm("pcpyld %0, %1, %2" : "=r"(q6) : "r"(20), "r"(skyTex1_1.field_0));
    t0->field_60 = q6;
    u_long128 q7;
    asm("pcpyld %0, %1, %2" : "=r"(q7) : "r"(66), "r"(skyAlpha_1.field_0));
    t0->field_70 = q7;
    u_long128 q8;
    asm("pcpyld %0, %1, %2" : "=r"(q8) : "r"(8), "r"(skyClamp_1.field_0));
    t0->field_80 = q8;
    farFogPlane.field_0 = t0 + 1;
}
