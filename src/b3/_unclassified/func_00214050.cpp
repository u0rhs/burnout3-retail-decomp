// func_00214050 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (member objects field_8F0 / field_938[2] (no CSE of self+K); state = (field_928[i] != -1) ? 5 : 0 as if/else).

// func_00214050 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EGtPS2InputPort {};
class CGtInputDevicePS2Pad2;

class CGtInputDevicePS2DualShock;
struct UnkStruct_00214050;

class CGtInputDevicePS2DualShock {
public:
    int GetPort();
};

struct UnkStruct_00214050_8F0 {
    unsigned char pad_0[0x38];
};

struct UnkStruct_00214050_938 {
    unsigned char pad_0[0x200];
    int field_200;
    unsigned char pad_204[0x4];
};

struct UnkStruct_00214050 {
    unsigned char pad_0[0x280];
    CGtInputDevicePS2DualShock field_280;
    unsigned char pad_281[0xEB];
    CGtInputDevicePS2DualShock field_36C;
    unsigned char pad_36D[0x583];
    UnkStruct_00214050_8F0 field_8F0;
    int field_928[2];
    unsigned char pad_930[0x8];
    UnkStruct_00214050_938 field_938[2];
};

extern "C" void Update__22CGtInputManagerPS2Pad2Fv(void *);  // CGtInputManagerPS2Pad2::Update()
extern "C" int GetConnectedDeviceID__22CGtInputManagerPS2Pad2F15EGtPS2InputPort(void *, EGtPS2InputPort);  // CGtInputManagerPS2Pad2::GetConnectedDeviceID(EGtPS2InputPort)
extern "C" void BindToPort__22CGtInputManagerPS2Pad2FP21CGtInputDevicePS2Pad215EGtPS2InputPort(void *, void *, EGtPS2InputPort);  // CGtInputManagerPS2Pad2::BindToPort(CGtInputDevicePS2Pad2*,EGtPS2InputPort)
extern "C" void UnbindFromPort__22CGtInputManagerPS2Pad2FP21CGtInputDevicePS2Pad215EGtPS2InputPort(void *, void *, EGtPS2InputPort);  // CGtInputManagerPS2Pad2::UnbindFromPort(CGtInputDevicePS2Pad2*,EGtPS2InputPort)
extern "C" void GenericUpdate__15CB3InputManagerFv(void *);  // CB3InputManager::GenericUpdate()
extern "C" void func_00442580(void *);
extern "C" bool func_00442470(void *, void *, int);
extern "C" void func_004423E0(void *, void *, int);

// 0x00214050
extern "C" void func_00214050(UnkStruct_00214050 * self)
{
    Update__22CGtInputManagerPS2Pad2Fv(self);
    func_00442580(&self->field_8F0);
    if (self->field_280.GetPort() == -1) {
        if (GetConnectedDeviceID__22CGtInputManagerPS2Pad2F15EGtPS2InputPort(self, (EGtPS2InputPort)0) == 4) {
            BindToPort__22CGtInputManagerPS2Pad2FP21CGtInputDevicePS2Pad215EGtPS2InputPort(self, (CGtInputDevicePS2Pad2*)&self->field_280, (EGtPS2InputPort)0);
        }
    }
    if (self->field_36C.GetPort() == -1) {
        if (GetConnectedDeviceID__22CGtInputManagerPS2Pad2F15EGtPS2InputPort(self, (EGtPS2InputPort)1) == 4) {
            BindToPort__22CGtInputManagerPS2Pad2FP21CGtInputDevicePS2Pad215EGtPS2InputPort(self, (CGtInputDevicePS2Pad2*)&self->field_36C, (EGtPS2InputPort)1);
        }
    }
    if (self->field_938[0].field_200 == -1) {
        int v;
        if (self->field_928[0] != -1) {
            v = 5;
        } else {
            v = 0;
        }
        if (v == 5) {
            func_00442470(&self->field_8F0, &self->field_938[0], 0);
        }
    }
    if (self->field_938[1].field_200 == -1) {
        int v;
        if (self->field_928[1] != -1) {
            v = 5;
        } else {
            v = 0;
        }
        if (v == 5) {
            func_00442470(&self->field_8F0, &self->field_938[1], 1);
        }
    }
    if (GetConnectedDeviceID__22CGtInputManagerPS2Pad2F15EGtPS2InputPort(self, (EGtPS2InputPort)0) != 4) {
        if (self->field_280.GetPort() != -1) {
            UnbindFromPort__22CGtInputManagerPS2Pad2FP21CGtInputDevicePS2Pad215EGtPS2InputPort(self, (CGtInputDevicePS2Pad2*)&self->field_280, (EGtPS2InputPort)self->field_280.GetPort());
        }
    }
    if (GetConnectedDeviceID__22CGtInputManagerPS2Pad2F15EGtPS2InputPort(self, (EGtPS2InputPort)1) != 4) {
        if (self->field_36C.GetPort() != -1) {
            UnbindFromPort__22CGtInputManagerPS2Pad2FP21CGtInputDevicePS2Pad215EGtPS2InputPort(self, (CGtInputDevicePS2Pad2*)&self->field_36C, (EGtPS2InputPort)self->field_36C.GetPort());
        }
    }
    {
    int t = self->field_938[0].field_200;
    if (t != -1) {
        int v;
        if (self->field_928[0] != -1) {
            v = 5;
        } else {
            v = 0;
        }
        if (v != 5) {
            func_004423E0(&self->field_8F0, &self->field_938[0], t);
        }
    }
    }
    {
    int t = self->field_938[1].field_200;
    if (t != -1) {
        int v;
        if (self->field_928[1] != -1) {
            v = 5;
        } else {
            v = 0;
        }
        if (v != 5) {
            func_004423E0(&self->field_8F0, &self->field_938[1], t);
        }
    }
    }
    GenericUpdate__15CB3InputManagerFv(self);
}
