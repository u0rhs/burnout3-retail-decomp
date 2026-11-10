// CGtInputDevicePS2DualShock2::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputDevicePS2DualShock2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near27: flipped axes as { float m = -1.0f; float f = field * m; f += k255; field = f - k128; } -- the product in its own statement keeps the raw store + reload, m keeps mul operand order).

// CGtInputDevicePS2DualShock2::Update() -- [C] name: the mangled symbol in retail's tables. Hand-matched (a159, near27).
// Fields are placeholders; every type is [G] (instruction widths). The two flipped axes (ids 0x13 -> field_AC,
// 0x11 -> field_B4): the raw value is stored, re-read, multiplied by -1 held in a local, +255, then -128 in the store.
// a159: CGtInputDevicePS2DualShock2::Update()
enum EGtPS2InputPort {};
struct UnkStruct_DS2_self {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char field_8;
    unsigned char field_9;
    unsigned char field_A[0x1C];
    unsigned char field_26[0x1C];
    unsigned char pad_42[6];
    float field_48[24];
    float field_A8;
    float field_AC;
    float field_B0;
    float field_B4;
    float field_B8;
    float field_BC;
    float field_C0;
    float field_C4;
    float field_C8;
    unsigned char pad_CC[0x18];
    void * field_E4;
    EGtPS2InputPort field_E8;
};
extern "C" int GetConnectedDeviceID__22CGtInputManagerPS2Pad2F15EGtPS2InputPort(void *, EGtPS2InputPort);
extern "C" int GetSocketNumber__22CGtInputManagerPS2Pad2F15EGtPS2InputPort(void *, EGtPS2InputPort);
extern "C" int GetPadControls__22CGtInputManagerPS2Pad2F15EGtPS2InputPort(void *, EGtPS2InputPort);
extern "C" int scePad2GetButtonInfo(int, int, int);
extern "C" float DeadzoneButton__26CGtInputDevicePS2DualShockFf(void *, float);
extern "C" float DeadzoneTrigger__26CGtInputDevicePS2DualShockFf(void *, float);
extern "C" float DeadzoneAxis__26CGtInputDevicePS2DualShockFff(void *, float, float);


extern "C" void Update__27CGtInputDevicePS2DualShock2Fv(UnkStruct_DS2_self * self)
{
    if (self->field_E4 == 0) return;
    self->field_8 = GetConnectedDeviceID__22CGtInputManagerPS2Pad2F15EGtPS2InputPort(self->field_E4, self->field_E8) == 4;
    if (self->field_8 == 0) {
        self->field_9 = 0;
        return;
    }
    int s1 = GetSocketNumber__22CGtInputManagerPS2Pad2F15EGtPS2InputPort(self->field_E4, self->field_E8);
    int s0 = GetPadControls__22CGtInputManagerPS2Pad2F15EGtPS2InputPort(self->field_E4, self->field_E8);
    self->field_48[0] = DeadzoneButton__26CGtInputDevicePS2DualShockFf(self, (float)scePad2GetButtonInfo(s1, s0, 0x18) / 255.0f);
    self->field_48[1] = DeadzoneButton__26CGtInputDevicePS2DualShockFf(self, (float)scePad2GetButtonInfo(s1, s0, 0x1B) / 255.0f);
    self->field_48[2] = DeadzoneButton__26CGtInputDevicePS2DualShockFf(self, (float)scePad2GetButtonInfo(s1, s0, 0x1A) / 255.0f);
    self->field_48[3] = DeadzoneButton__26CGtInputDevicePS2DualShockFf(self, (float)scePad2GetButtonInfo(s1, s0, 0x19) / 255.0f);
    self->field_48[4] = DeadzoneButton__26CGtInputDevicePS2DualShockFf(self, (float)scePad2GetButtonInfo(s1, s0, 0x16) / 255.0f);
    self->field_48[5] = DeadzoneButton__26CGtInputDevicePS2DualShockFf(self, (float)scePad2GetButtonInfo(s1, s0, 0x17) / 255.0f);
    self->field_48[6] = DeadzoneButton__26CGtInputDevicePS2DualShockFf(self, (float)scePad2GetButtonInfo(s1, s0, 0x15) / 255.0f);
    self->field_48[7] = DeadzoneButton__26CGtInputDevicePS2DualShockFf(self, (float)scePad2GetButtonInfo(s1, s0, 0x14) / 255.0f);
    self->field_48[8] = DeadzoneButton__26CGtInputDevicePS2DualShockFf(self, (float)scePad2GetButtonInfo(s1, s0, 0x14) / 255.0f);
    self->field_48[8] = (float)scePad2GetButtonInfo(s1, s0, 3);
    self->field_48[9] = (float)scePad2GetButtonInfo(s1, s0, 0);
    self->field_48[10] = DeadzoneTrigger__26CGtInputDevicePS2DualShockFf(self, (float)scePad2GetButtonInfo(s1, s0, 0x1C) / 255.0f);
    self->field_48[11] = DeadzoneTrigger__26CGtInputDevicePS2DualShockFf(self, (float)scePad2GetButtonInfo(s1, s0, 0x1E) / 255.0f);
    self->field_48[12] = DeadzoneTrigger__26CGtInputDevicePS2DualShockFf(self, (float)scePad2GetButtonInfo(s1, s0, 0x1D) / 255.0f);
    self->field_48[13] = DeadzoneTrigger__26CGtInputDevicePS2DualShockFf(self, (float)scePad2GetButtonInfo(s1, s0, 0x1F) / 255.0f);
    self->field_48[14] = (float)scePad2GetButtonInfo(s1, s0, 1);
    self->field_48[15] = (float)scePad2GetButtonInfo(s1, s0, 2);
    float k255 = 255.0f;
    float k128 = 128.0f;
    self->field_AC = (float)scePad2GetButtonInfo(s1, s0, 0x13);
    { float m = -1.0f; float f = self->field_AC * m; f += k255; self->field_AC = f - k128; }
    if (!(self->field_AC <= 0.0f)) {
        self->field_AC = self->field_AC / 127.0f;
        if (self->field_9 == 0) {
            float v = self->field_AC;
            self->field_B8 = v;
            if (!(v <= 0.25f)) self->field_B8 = 0.25f;
        }
        self->field_AC = DeadzoneAxis__26CGtInputDevicePS2DualShockFff(self, self->field_AC, self->field_B8);
        self->field_48[16] = self->field_AC;
        self->field_48[17] = 0;
    } else {
        self->field_AC = self->field_AC / k128;
        if (self->field_9 == 0) {
            float v = -self->field_AC;
            self->field_B8 = v;
            if (!(v <= 0.25f)) self->field_B8 = 0.25f;
        }
        self->field_AC = DeadzoneAxis__26CGtInputDevicePS2DualShockFff(self, self->field_AC, self->field_B8);
        self->field_48[16] = 0;
        self->field_48[17] = -self->field_AC;
    }
    self->field_A8 = (float)scePad2GetButtonInfo(s1, s0, 0x12);
    self->field_A8 = self->field_A8 - k128;
    if (!(self->field_A8 <= 0.0f)) {
        self->field_A8 = self->field_A8 / 127.0f;
        if (self->field_9 == 0) {
            float v = self->field_A8;
            self->field_BC = v;
            if (!(v <= 0.25f)) self->field_BC = 0.25f;
        }
        self->field_A8 = DeadzoneAxis__26CGtInputDevicePS2DualShockFff(self, self->field_A8, self->field_BC);
        self->field_48[19] = self->field_A8;
        self->field_48[18] = 0;
    } else {
        self->field_A8 = self->field_A8 / k128;
        if (self->field_9 == 0) {
            float v = -self->field_A8;
            self->field_BC = v;
            if (!(v <= 0.25f)) self->field_BC = 0.25f;
        }
        self->field_A8 = DeadzoneAxis__26CGtInputDevicePS2DualShockFff(self, self->field_A8, self->field_BC);
        self->field_48[19] = 0;
        self->field_48[18] = -self->field_A8;
    }
    self->field_B4 = (float)scePad2GetButtonInfo(s1, s0, 0x11);
    { float m = -1.0f; float f = self->field_B4 * m; f += k255; self->field_B4 = f - k128; }
    if (!(self->field_B4 <= 0.0f)) {
        self->field_B4 = self->field_B4 / 127.0f;
        if (self->field_9 == 0) {
            float v = self->field_B4;
            self->field_C0 = v;
            if (!(v <= 0.25f)) self->field_C0 = 0.25f;
        }
        self->field_B4 = DeadzoneAxis__26CGtInputDevicePS2DualShockFff(self, self->field_B4, self->field_C0);
        self->field_48[20] = self->field_B4;
        self->field_48[21] = 0;
    } else {
        self->field_B4 = self->field_B4 / k128;
        if (self->field_9 == 0) {
            float v = -self->field_B4;
            self->field_C0 = v;
            if (!(v <= 0.25f)) self->field_C0 = 0.25f;
        }
        self->field_B4 = DeadzoneAxis__26CGtInputDevicePS2DualShockFff(self, self->field_B4, self->field_C0);
        self->field_48[20] = 0;
        self->field_48[21] = -self->field_B4;
    }
    self->field_B0 = (float)scePad2GetButtonInfo(s1, s0, 0x10);
    self->field_B0 = self->field_B0 - k128;
    if (!(self->field_B0 <= 0.0f)) {
        self->field_B0 = self->field_B0 / 127.0f;
        if (self->field_9 == 0) {
            float v = self->field_B0;
            self->field_C4 = v;
            if (!(v <= 0.25f)) self->field_C4 = 0.25f;
        }
        self->field_B0 = DeadzoneAxis__26CGtInputDevicePS2DualShockFff(self, self->field_B0, self->field_C4);
        self->field_48[23] = self->field_B0;
        self->field_48[22] = 0;
    } else {
        self->field_B0 = self->field_B0 / k128;
        if (self->field_9 == 0) {
            float v = -self->field_B0;
            self->field_C4 = v;
            if (!(v <= 0.25f)) self->field_C4 = 0.25f;
        }
        self->field_B0 = DeadzoneAxis__26CGtInputDevicePS2DualShockFff(self, self->field_B0, self->field_C4);
        self->field_48[23] = 0;
        self->field_48[22] = -self->field_B0;
    }
    for (int i = 0; i < 28; i++) {
        self->field_A[i] = self->field_26[i];
        switch (i) {
        case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
        case 16: case 17: case 18: case 19: case 20: case 21: case 22: case 23:
            if (self->field_48[i] > self->field_C8) self->field_26[i] = 1;
            else self->field_26[i] = 0;
            break;
        case 24: case 25: case 26: case 27:
            self->field_26[i] = 0;
            break;
        }
    }
    self->field_9 = 1;
}
