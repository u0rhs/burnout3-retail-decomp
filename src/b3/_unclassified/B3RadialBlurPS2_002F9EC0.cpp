// CB3RadialBlur::RestoreRenderstates(const CB3CameraData*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RadialBlurPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (pcpyld operands (%1=const, %2=value) as CB3Bloom; camera-data fields stored directly (no temps; const p0 lets MWCC CSE 0x1C0); farFogPlane.field_0 = t0 + 1).

// lifter variant 0
// CB3RadialBlur::RestoreRenderstates(const CB3CameraData*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RadialBlurPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3CameraData;

class CB3RadialBlur;
struct CB3CameraData;
struct UnkStruct_002F9EC0_2;
struct UnkStruct_farFogPlane;
struct UnkStruct_skyAlpha_1;
struct UnkStruct_skyClamp_1;
struct UnkStruct_skyTest_1;
struct UnkStruct_skyTex1_1;

struct UnkStruct_farFogPlane {
    UnkStruct_002F9EC0_2 * field_0;
};

struct CB3CameraData {
    unsigned char pad_0[0x1C0];
    u_long128 field_1C0;
    u_long128 field_1D0;
    u_long128 field_1E0;
};

struct UnkStruct_002F9EC0_2 {
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

class CB3RadialBlur {
public:
    void RestoreRenderstates(const CB3CameraData* p0);
};

extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_skyTest_1 skyTest_1;
extern UnkStruct_skyTex1_1 skyTex1_1;
extern UnkStruct_skyAlpha_1 skyAlpha_1;
extern UnkStruct_skyClamp_1 skyClamp_1;

// 0x002F9EC0
void CB3RadialBlur::RestoreRenderstates(const CB3CameraData* p0)
{
    UnkStruct_002F9EC0_2 * t0 = farFogPlane.field_0;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x1000000000008008), "r"(14));
    t0->field_0 = q0;
    t0->field_10 = p0->field_1C0;
    t0->field_20 = p0->field_1E0;
    t0->field_30 = p0->field_1C0;
    t0->field_40 = p0->field_1D0;
    u_long128 q1;
    asm("pcpyld %0, %1, %2" : "=r"(q1) : "r"(71), "r"(skyTest_1.field_0));
    t0->field_50 = q1;
    u_long128 q2;
    asm("pcpyld %0, %1, %2" : "=r"(q2) : "r"(20), "r"(skyTex1_1.field_0));
    t0->field_60 = q2;
    u_long128 q3;
    asm("pcpyld %0, %1, %2" : "=r"(q3) : "r"(66), "r"(skyAlpha_1.field_0));
    t0->field_70 = q3;
    u_long128 q4;
    asm("pcpyld %0, %1, %2" : "=r"(q4) : "r"(8), "r"(skyClamp_1.field_0));
    t0->field_80 = q4;
    farFogPlane.field_0 = t0 + 1;
}
