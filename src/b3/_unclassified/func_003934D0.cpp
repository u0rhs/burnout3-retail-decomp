// OnNonFatalCollision__26CB3OfflineSingleCrashLogicFP17CB3RaceCarPhysicsP17CB3TrafficVehicle -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (void return (v0 never set; callee result unused); && guard; .lit4 externs as 1.6f / 0.05f literals).

// lifter variant 0
// OnNonFatalCollision__26CB3OfflineSingleCrashLogicFP17CB3RaceCarPhysicsP17CB3TrafficVehicle -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3TrafficVehicle;
class CB3VehiclePhysics;

class CB3PhysicsManager;
struct UnkStruct_003934D0;
struct UnkStruct_003934D0_a1;
struct UnkStruct_003934D0_a2;
struct UnkStruct_D_004E0F7C;
struct UnkStruct_D_004E1018;
struct UnkStruct_D_00522680;

class CB3PhysicsManager {
public:
    int InduceTrafficVehicleCrash(CB3TrafficVehicle*, CB3VehiclePhysics*, bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003934D0_a1 {
    unsigned char pad_0[0x13F4];
    int field_13F4;
};

struct UnkStruct_003934D0_a2 {
    unsigned char pad_0[0x174];
    unsigned char field_174;
};

struct UnkStruct_D_004E0F7C {
    float field_0;
};

struct UnkStruct_D_00522680 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E1018 {
    float field_0;
};

struct UnkStruct_003934D0 {
    unsigned char pad_0[0x44];
    float field_44;
    unsigned char pad_48[0xA];
    unsigned char field_52;
};

extern UnkStruct_D_004E0F7C D_004E0F7C;
extern UnkStruct_D_00522680 D_00522680;
extern UnkStruct_D_004E1018 D_004E1018;
extern CB3PhysicsManager D_0055EF70;

extern "C" void SetTempTrafficInvulnerable__17CB3RaceCarPhysicsFv(void *);  // CB3RaceCarPhysics::SetTempTrafficInvulnerable()
extern "C" void HandleNonFatalCollision__8CB3ScoreFP17CB3TrafficVehicle(void *, UnkStruct_003934D0_a2 *);
extern "C" void func_001CC4C0(int, int, int, float);
extern "C" void func_001CC520(int, int, int, float);

// 0x003934D0
extern "C" void OnNonFatalCollision__26CB3OfflineSingleCrashLogicFP17CB3RaceCarPhysicsP17CB3TrafficVehicle(UnkStruct_003934D0 * self, UnkStruct_003934D0_a1 * p0, UnkStruct_003934D0_a2 * p1)
{
    HandleNonFatalCollision__8CB3ScoreFP17CB3TrafficVehicle((void *)((p0->field_13F4 + 4288)), p1);
    if ((p1->field_174 & 8) != 0 && (p1->field_174 & 2) == 0) {
        SetTempTrafficInvulnerable__17CB3RaceCarPhysicsFv(p0);
        int r2 = D_0055EF70.InduceTrafficVehicleCrash((CB3TrafficVehicle*)p1, (CB3VehiclePhysics*)p0, 0);
        func_001CC4C0(r2, 16, 1, 0.5f);
        func_001CC520(r2, 128, 1, 1.6f);
        self->field_44 = 0.05f + D_00522680.field_0;
        self->field_52 = 1;
    }
}
