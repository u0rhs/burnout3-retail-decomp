// CB3TrafficSystem::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficSystem.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (lifter shape with element 0 given an int field_0 so 'field_0 = 0' becomes field_0[0].field_0 = 0 (declaration fix)).

// lifter variant 0
// CB3TrafficSystem::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficSystem.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3TrafficSystem;
struct UnkStruct_00166DB0_e2;
struct UnkStruct_00166DB0_e3;
struct UnkStruct_00166DB0_e4;
struct UnkStruct_00166DB0_e5;
struct UnkStruct_D_01D9BB10;
struct UnkStruct_theMemMgr;

struct UnkStruct_00166DB0_e2 {
    int field_0;
    unsigned char pad_4[0x114];
};

struct UnkStruct_00166DB0_e3 {
    unsigned char pad_0[0x180];
};

struct UnkStruct_00166DB0_e4 {
    unsigned char pad_0[0x50];
};

struct UnkStruct_00166DB0_e5 {
    unsigned char pad_0[0xB0];
};

struct UnkStruct_D_01D9BB10 {
    UnkStruct_00166DB0_e5 field_0[1];  // [G] element count unknown
};

struct UnkStruct_theMemMgr {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3TrafficSystem {
public:
    void Release();

    UnkStruct_00166DB0_e2 field_0[1];  // [G] element count unknown
    unsigned char pad_118[0x34278];
    unsigned long field_34390[1];  // [G] element count unknown
    unsigned char pad_34398[0x58];
    int field_343F0[1];  // [G] element count unknown
    unsigned char pad_343F4[0x5C];
    signed char field_34450;
    unsigned char pad_34451[0x1F5C];
    unsigned char field_363AD;
    unsigned char pad_363AE[0x114A];
    int field_374F8;
    int field_374FC;
};

extern UnkStruct_D_01D9BB10 D_01D9BB10;
extern UnkStruct_theMemMgr theMemMgr;

extern "C" void Release__15CB3TrafficValveFv(void *);  // CB3TrafficValve::Release()
extern "C" void Release__17CB3TrafficVehicleFv(void *);  // CB3TrafficVehicle::Release()
extern "C" void Release__24CB3VehiclePhysicsAttribsFv(void *);  // CB3VehiclePhysicsAttribs::Release()
extern "C" void func_00162BE0(void *);
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);

// 0x00166DB0
void CB3TrafficSystem::Release()
{
    for (int i = 0; (i < field_363AD); i++) {
        Release__15CB3TrafficValveFv(((char *)&field_0[i] + 0x4));
    }
    for (int i1 = 0; (i1 < 254); i1++) {
        Release__17CB3TrafficVehicleFv(((char *)((char *)this + ((i1 * 3) << 7)) + 0x127D0));
    }
    for (int i2 = 0; (i2 < 254); i2++) {
        func_00162BE0(((char *)((char *)this + ((i2 * 5) << 4)) + 0x2A4D0));
    }
    for (int i3 = 0; (i3 < field_34450); i3++) {
        Release__24CB3VehiclePhysicsAttribsFv(&D_01D9BB10.field_0[i3]);
    }
    for (int i4 = 0; (i4 < 12); i4++) {
        ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 2, i4);
        field_34390[i4] = 0;
        field_343F0[i4] = 0;
    }
    field_0[0].field_0 = 0;
    field_34450 = 0;
    field_374F8 = 24;
    field_374FC = 24;
}
