// CB3CrashActionDirector::StartTrafficCrashing(CB3TrafficPhysics*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashActionDirector.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (12-byte element struct at 0x278 via element pointer; inline RNG; (float)(unsigned) * 2^-32 > 0.5f if/else).

// lifter variant 0
// CB3CrashActionDirector::StartTrafficCrashing(CB3TrafficPhysics*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashActionDirector.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3TrafficPhysics;

class CB3CrashActionDirector;
struct CB3TrafficPhysics;
struct UnkStruct_001AE500_e0;
struct UnkStruct_001AE500_e1;
struct UnkStruct_001AE500_e2;
struct UnkStruct_D_0064517C;

struct CB3TrafficPhysics {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10(int, int);
};

struct UnkStruct_001AE500_e0 {
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0x2C];
};

struct UnkStruct_D_0064517C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_001AE500_e1 {
    int field_0;
    int field_4;
    unsigned char field_8;
    unsigned char field_9;
    unsigned char field_A;
    unsigned char pad_B[0x1];
};

struct UnkStruct_001AE500_e2 {
    unsigned char pad_0[0x8];
    int field_8;
};

class CB3CrashActionDirector {
public:
    void StartTrafficCrashing(CB3TrafficPhysics* p0, int p1);

    int field_0;
    int field_4;
    unsigned char pad_8[0x124];
    UnkStruct_001AE500_e0 field_12C[1];  // [G] element count unknown
    unsigned char pad_168[0x110];
    UnkStruct_001AE500_e1 field_278[1];  // [G] element count unknown
};

extern UnkStruct_D_0064517C D_0064517C;

// 0x001AE500
void CB3CrashActionDirector::StartTrafficCrashing(CB3TrafficPhysics* p0, int p1)
{
    p0->vfunc_10(p1, 0);
    field_12C[p1].field_C = 1.0f;
    UnkStruct_001AE500_e1 * e = &field_278[D_0064517C.field_0];
    e->field_4 = 0;
    e->field_0 = 0;
    e->field_9 = 0;
    e->field_A = 1;
    field_0 = (field_0 << 16) + (field_0 >> 16);
    field_0 += field_4;
    field_4 += field_0;
    if (2.3283064e-10f * (float)(unsigned int)field_0 > 0.5f) {
        e->field_8 = 1;
    } else {
        e->field_8 = 0;
    }
}
