// CB3TrafficSystem::PrepareTrafficVehicleData() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficSystemLoadAndRender.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (case 1/24 falls through into case 2; case 23 break to final return 1 (no default); == arm first in case 3 tail).

// lifter variant 0
// CB3TrafficSystem::PrepareTrafficVehicleData() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficSystemLoadAndRender.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3VehicleData;

class CAsyncLoadManager;
class CB3TrafficSystem;
class CB3VehicleList;
class CB3VehicleRenderer;
struct UnkStruct_003093E0_3;
struct UnkStruct_D_004C49D0;
struct UnkStruct__gnPerfMonTrafficDraw;
struct UnkStruct_theMemMgr;

class CB3VehicleList {
public:
    int GetVehicleIndexFromID(unsigned long);
    void CreateVehiclePathFromIndex(int, char*, int);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CAsyncLoadManager {
public:
    int QueueLoadRequest(const char*, bool*, void*, unsigned int);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3VehicleRenderer {
public:
    void FixUpVehicleData(CB3VehicleData*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct__gnPerfMonTrafficDraw {
    int field_0;
};

struct UnkStruct_003093E0_3 {
    unsigned char pad_0[0x30];
};

struct UnkStruct_D_004C49D0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_theMemMgr {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3TrafficSystem {
public:
    int PrepareTrafficVehicleData();

    unsigned char pad_0[0x34390];
    unsigned long field_34390[1];  // [G] element count unknown
    unsigned char pad_34398[0x58];
    int field_343F0[1];  // [G] element count unknown
    unsigned char pad_343F4[0x5C];
    signed char field_34450;
    unsigned char pad_34451[0x309F];
    unsigned char field_374F0;
    signed char field_374F1;
    unsigned char pad_374F2[0x2];
    int field_374F4;
    unsigned char pad_374F8[0x4];
    int field_374FC;
};

extern UnkStruct__gnPerfMonTrafficDraw _gnPerfMonTrafficDraw;
extern CB3VehicleList D_005186A0;
extern UnkStruct_D_004C49D0 D_004C49D0;
extern UnkStruct_theMemMgr theMemMgr;
extern CAsyncLoadManager D_004F6100;
extern CB3VehicleRenderer gVehicleRenderer;

extern "C" char * strcat(char *, const char *);
extern "C" int GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(void *, int);

// 0x003093E0
int CB3TrafficSystem::PrepareTrafficVehicleData()
{
    UnkStruct_003093E0_3 local;  // [G] the frame's one local (size: up to the frame top)
    if (_gnPerfMonTrafficDraw.field_0 == -1) {
        _gnPerfMonTrafficDraw.field_0 = 0;
    }
    switch (field_374FC) {
    case 1:
    case 24:
        field_374F1 = 0;
        field_374F0 = 0;
        field_374F4 = 0;
        field_374FC = 2;
    case 2:
        if (field_374F1 < field_34450) {
            int r0 = D_005186A0.GetVehicleIndexFromID(field_34390[field_374F1]);
            D_005186A0.CreateVehiclePathFromIndex(r0, (char*)&local, 40);
            strcat((char *)&local, (const char *)&D_004C49D0);
            field_374F0 = 0;
            int r3 = GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(&theMemMgr, 2);
            field_374F4 = D_004F6100.QueueLoadRequest((const char*)&local, (bool*)((char *)this + 0x374F0), (void*)field_343F0[field_374F1], r3);
            field_374FC = 3;
            return 0;
        }
        field_374FC = 23;
        return 1;
    case 3:
        if (field_374F0 == 0) {
            return 0;
        }
        if (field_374F4 != 0) {
            gVehicleRenderer.FixUpVehicleData((CB3VehicleData*)field_343F0[field_374F1]);
        }
        field_374F4 = 0;
        field_374F1 = (field_374F1 + 1);
        if (field_374F1 == field_34450) {
            field_374FC = 23;
            return 1;
        } else {
            field_374FC = 2;
            return 0;
        }
    case 23:
        break;
    }
    return 1;
}
