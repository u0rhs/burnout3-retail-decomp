// CB3ControllerMapping::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ControllerMappingPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a90: AnyInput inline as bool early-return helper).

class CGtInputDevicePS2DualShock {
public:
    bool IsConnected();
    float GetControlValue(int);
};
struct UnkStruct_0012FE90_1 {
    unsigned char pad_0[0x8];
    bool field_8;
};
struct UnkStruct_0012FE90 {
    unsigned char pad_0[0x4];
    CGtInputDevicePS2DualShock * field_4;
    UnkStruct_0012FE90_1 * field_8;
    unsigned char pad_C[0x11C];
    float field_128;
};
struct UnkStruct_D_004F50A0_x { float field_0; unsigned char pad[12]; };
extern UnkStruct_D_004F50A0_x D_004F50A0;
struct UnkStruct_D_004F509C { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004F509C D_004F509C;
extern float D_004E0B30;
static inline float fabsf(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
extern "C" float func_00443820(UnkStruct_0012FE90_1 *, int);
extern "C" void Update__12CB3MenuInputFfP20CB3ControllerMapping(void *, float, void *);

static inline bool AnyIn(UnkStruct_0012FE90 * self)
{
    if (self->field_4->IsConnected()) {
        for (int i = 0; i < 0x1C; i++) {
            if (fabsf(self->field_4->GetControlValue(i)) > D_004E0B30) {
                return 1;
            }
        }
    }
    UnkStruct_0012FE90_1 * t0 = self->field_8;
    bool b;
    if (t0 == 0) {
        b = false;
    } else {
        b = t0->field_8;
    }
    if (b) {
        for (int i = 0; i < 0x23; i++) {
            if (fabsf(func_00443820(self->field_8, i)) > D_004E0B30) {
                return 1;
            }
        }
    }
    return 0;
}
// 0x0012FE90
extern "C" void Update__20CB3ControllerMappingFv(UnkStruct_0012FE90 * self)
{
    if (AnyIn(self)) {
        self->field_128 = D_004F50A0.field_0;
    }
    Update__12CB3MenuInputFfP20CB3ControllerMapping((char *)self + 0xC, D_004F509C.field_0, self);
}
