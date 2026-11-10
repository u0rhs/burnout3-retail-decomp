// Prepare__15CB3DebugManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3AIDebug;
class CB3DebugManager;
class CB3PhysicsManagerDebug;
class CB3TrafficDebug;
struct UnkStruct_00130B00;
struct UnkStruct__gnDebugNumPoints;

class CB3AIDebug {
public:
    void Prepare();
};

class CB3PhysicsManagerDebug {
public:
    void Prepare();
};

class CB3TrafficDebug {
public:
    void Prepare();
};

struct UnkStruct__gnDebugNumPoints {
    int field_0;
};

class CB3DebugManager {
public:
    static unsigned char gmbRequestStopAll;
    static unsigned char gmbRequestStopUpdate;
    static unsigned char gmbRequestStepAll;
    static unsigned char gmbRequestStepCameras;
    static unsigned char gmbRequestPlayAll;
    static unsigned char gmbRequestPlayCameras;
};

struct UnkStruct_00130B00 {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
    unsigned char pad_4[0xC];
    CB3AIDebug field_10;
    unsigned char pad_11[0x6FF];
    CB3PhysicsManagerDebug field_710;
    unsigned char pad_711[0x1EDF];
    CB3TrafficDebug field_25F0;
    unsigned char pad_25F1[0x18];
    unsigned char field_2609;
    unsigned char pad_260A[0x2];
    int field_260C;
};

extern UnkStruct__gnDebugNumPoints _gnDebugNumPoints;

// 0x00130B00
extern "C" int Prepare__15CB3DebugManagerFv(UnkStruct_00130B00 * self)
{
    _gnDebugNumPoints.field_0 = 0;
    self->field_10.Prepare();
    self->field_710.Prepare();
    self->field_25F0.Prepare();
    self->field_2609 = 0;
    self->field_260C = 0;
    self->field_2 = 0;
    self->field_0 = 1;
    self->field_1 = 1;
    self->field_2 = 0;
    self->field_3 = 0;
    CB3DebugManager::gmbRequestStopAll = 0;
    CB3DebugManager::gmbRequestStopUpdate = 0;
    CB3DebugManager::gmbRequestStepAll = 0;
    CB3DebugManager::gmbRequestStepCameras = 0;
    CB3DebugManager::gmbRequestPlayAll = 0;
    CB3DebugManager::gmbRequestPlayCameras = 0;
    self->field_0 = 1;
    self->field_1 = 1;
    return 1;
}
