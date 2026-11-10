// Construct__15CB3DebugManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3AIDebug;
class CB3DebugMipMaps;
class CB3PhysicsManagerDebug;
class CB3TrafficDebug;
class CGtPerfMon;
struct UnkStruct_00130B80;
struct UnkStruct__gnDebugMaxNumPoints;
struct UnkStruct__gnDebugNumPoints;

class CB3AIDebug {
public:
    void Construct();
};

class CB3PhysicsManagerDebug {
public:
    void Construct();
};

class CB3TrafficDebug {
public:
    void Construct();
};

class CB3DebugMipMaps {
public:
    static void Construct();
};

struct UnkStruct__gnDebugMaxNumPoints {
    int field_0;
};

struct UnkStruct__gnDebugNumPoints {
    int field_0;
};

class CGtPerfMon {
public:
    static void * mfpDisplayCallback;
};

struct UnkStruct_00130B80 {
    unsigned char pad_0[0x10];
    CB3AIDebug field_10;
    unsigned char pad_11[0x6FF];
    CB3PhysicsManagerDebug field_710;
    unsigned char pad_711[0x1EDF];
    CB3TrafficDebug field_25F0;
    unsigned char pad_25F1[0xB];
    int field_25FC;
    unsigned char pad_2600[0x8];
    unsigned char field_2608;
};

extern UnkStruct__gnDebugMaxNumPoints _gnDebugMaxNumPoints;
extern UnkStruct__gnDebugNumPoints _gnDebugNumPoints;

extern "C" void RenderPerfMonDataCallback__15CB3DebugManagerFPCcfffb(const char*, float, float, float, bool);  // CB3DebugManager::RenderPerfMonDataCallback(const char*,float,float,float,bool), its address taken

// 0x00130B80
extern "C" void Construct__15CB3DebugManagerFv(UnkStruct_00130B80 * self)
{
    _gnDebugMaxNumPoints.field_0 = 64;
    _gnDebugNumPoints.field_0 = 0;
    self->field_10.Construct();
    self->field_710.Construct();
    self->field_25F0.Construct();
    CB3DebugMipMaps::Construct();
    CGtPerfMon::mfpDisplayCallback = (void *)&RenderPerfMonDataCallback__15CB3DebugManagerFPCcfffb;
    self->field_2608 = 1;
    self->field_25FC = -1;
}
