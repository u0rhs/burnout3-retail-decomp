// CB3PhysicsManager::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PhysicsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3PhysicsManager;
struct UnkStruct_001BA280_e3;
struct UnkStruct_001BA280_e4;
struct UnkStruct_001BA280_e5;
struct UnkStruct_001BA280_e6;
struct UnkStruct_001BA280_e7;
struct UnkStruct_001BA280_e8;
struct UnkStruct_001BA280_e9;
struct UnkStruct_D_01D9C350;

struct UnkStruct_001BA280_e9 {
    unsigned char pad_0[0x1D0];
};

struct UnkStruct_D_01D9C350 {
    UnkStruct_001BA280_e9 field_0[1];  // [G] element count unknown
    unsigned char pad_1D0[0x910];
    int field_AE0[1];  // [G] element count unknown
    unsigned char pad_AE4[0x14];
    int field_AF8[1];  // [G] element count unknown
};

struct UnkStruct_001BA280_e3 {
    unsigned char pad_0[0x4590];
};

struct UnkStruct_001BA280_e4 {
    unsigned char pad_0[0x1580];
};

struct UnkStruct_001BA280_e5 {
    unsigned char pad_0[0x1560];
};

struct UnkStruct_001BA280_e6 {
    unsigned char pad_0[0x2430];
};

struct UnkStruct_001BA280_e7 {
    unsigned char pad_0[0x780];
};

struct UnkStruct_001BA280_e8 {
    unsigned char pad_0[0x4E0];
};

class CB3PhysicsManager {
public:
    void Construct();

    UnkStruct_001BA280_e3 field_0[1];  // [G] element count unknown
    unsigned char pad_4590[0x185E0];
    int field_1CB70;
    int field_1CB74;
    unsigned char pad_1CB78[0xC9588];
    int field_E6100[1];  // [G] element count unknown
    unsigned char pad_E6104[0xFC];
    int field_E6200;
    int field_E6204;
    int field_E6208;
    int field_E620C;
    unsigned char pad_E6210[0x3000];
    int field_E9210;
    unsigned char pad_E9214[0x4];
    unsigned long field_E9218;
    unsigned long field_E9220;
};

extern UnkStruct_D_01D9C350 D_01D9C350;

extern "C" void Construct__19CB3PlayerCarPhysicsFv(void *);  // CB3PlayerCarPhysics::Construct()
extern "C" void Construct__15CB3AICarPhysicsFv(void *);  // CB3AICarPhysics::Construct()
extern "C" void Construct__20CB3NetworkCarPhysicsFv(void *);  // CB3NetworkCarPhysics::Construct()
extern "C" void Construct__17CB3TrafficPhysicsFv(void *);  // CB3TrafficPhysics::Construct()
extern "C" void Construct__14CB3PropPhysicsFv(void *);  // CB3PropPhysics::Construct()
extern "C" void Construct__18CB3BodyPartPhysicsFv(void *);  // CB3BodyPartPhysics::Construct()
extern "C" void Construct__24CB3RaceCarPhysicsAttribsFv(void *);  // CB3RaceCarPhysicsAttribs::Construct()

// 0x001BA280
void CB3PhysicsManager::Construct()
{
    for (int i = 0; (i < 2); i++) {
        Construct__19CB3PlayerCarPhysicsFv(((char *)&field_0[i] + 0x1CB80));
    }
    for (int i1 = 0; (i1 < 5); i1++) {
        Construct__15CB3AICarPhysicsFv(((char *)((char *)this + (i1 * 5504)) + 0x256A0));
    }
    for (int i2 = 0; (i2 < 5); i2++) {
        Construct__20CB3NetworkCarPhysicsFv(((char *)((char *)this + (i2 * 5472)) + 0x2C220));
    }
    for (int i3 = 0; (i3 < 64); i3++) {
        Construct__17CB3TrafficPhysicsFv(((char *)((char *)this + (i3 * 9264)) + 0x32D00));
    }
    for (int i4 = 0; (i4 < 32); i4++) {
        Construct__14CB3PropPhysicsFv(((char *)((char *)this + ((i4 * 15) << 7)) + 0xC3900));
    }
    for (int i5 = 0; (i5 < 64); i5++) {
        Construct__18CB3BodyPartPhysicsFv(((char *)((char *)this + ((i5 * 39) << 5)) + 0xD2900));
    }
    for (int i6 = 0; (i6 < 64); i6++) {
        field_E6100[i6] = 0;
    }
    field_1CB70 = 0;
    field_1CB74 = 0;
    field_E9210 = 0;
    field_E6200 = 0;
    field_E6204 = 0;
    field_E6208 = 0;
    field_E620C = 0;
    field_E9218 = 0;
    field_E9220 = 0;
    for (int i7 = 0; (i7 < 6); i7++) {
        Construct__24CB3RaceCarPhysicsAttribsFv(&D_01D9C350.field_0[i7]);
        D_01D9C350.field_AE0[i7] = 0;
        D_01D9C350.field_AF8[i7] = 0;
    }
}
