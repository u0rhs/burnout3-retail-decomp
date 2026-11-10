// func_00446970 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3PlayerCameraManager;
struct UnkStruct_00446970;
struct UnkStruct_00446970_e0;
struct UnkStruct_D_00522660;

struct UnkStruct_00446970_e0 {
    unsigned char pad_0[0x1050];
};

struct UnkStruct_D_00522660 {
    UnkStruct_00446970_e0 field_0[1];  // [G] element count unknown
};

class CB3PlayerCameraManager {
public:
    static int mgpCameraBuffer;
};

struct UnkStruct_00446970 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x24];
    void * field_30;
    unsigned char pad_34[0x15];
    unsigned char field_49;
};

extern UnkStruct_D_00522660 D_00522660;

extern "C" void Construct__18CB3CameraBehaviourFv(void *);  // CB3CameraBehaviour::Construct()

// 0x00446970
extern "C" void func_00446970(UnkStruct_00446970 * self, int p0)
{
    Construct__18CB3CameraBehaviourFv(self);
    self->field_30 = ((char *)&D_00522660.field_0[p0] + 0x128290);
    self->field_49 = 0;
    self->field_8 = (CB3PlayerCameraManager::mgpCameraBuffer + 12144);
}
