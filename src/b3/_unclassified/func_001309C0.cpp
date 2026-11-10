// Update__15CB3DebugManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3AIDebug;
class CB3DebugMipMaps;
class CB3PhysicsManagerDebug;
class CB3TrafficDebug;
struct UnkStruct_001309C0;

class CB3AIDebug {
public:
    void Update();
};

class CB3PhysicsManagerDebug {
public:
    void Update();
};

class CB3TrafficDebug {
public:
    void Update();
};

class CB3DebugMipMaps {
public:
    static void Update();
};

struct UnkStruct_001309C0 {
    unsigned char pad_0[0x10];
    CB3AIDebug field_10;
    unsigned char pad_11[0x6FF];
    CB3PhysicsManagerDebug field_710;
    unsigned char pad_711[0x1EDF];
    CB3TrafficDebug field_25F0;
};

struct UnkStruct_001309C0_pad {
    unsigned char field_0[0x4];
    UnkStruct_001309C0_pad() {}
    ~UnkStruct_001309C0_pad() {}
};

// 0x001309C0
extern "C" void Update__15CB3DebugManagerFv(UnkStruct_001309C0 * self)
{
    UnkStruct_001309C0_pad pad;  // [G] an unused local object: retail's frame keeps 0x10 unused bytes at its top (a scoped object with a constructor/destructor reserves its slot, known.md N140)
    self->field_10.Update();
    self->field_710.Update();
    self->field_25F0.Update();
    CB3DebugMipMaps::Update();
}
