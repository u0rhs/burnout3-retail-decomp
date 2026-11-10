// Hand-written; the lifter refused it (N182 opt_repositioncode off + goto r1 return block after loop).

// N182: retail compiled this function with `#pragma opt_repositioncode off` ([G] scoped to this function).
#pragma push
#pragma opt_repositioncode off

// func_0012FDA0 [L] DNAT: CB3ControllerMapping::AnyInput() (research/proto/new_names.csv, low)
class CGtInputDevicePS2DualShock {
public:
    bool IsConnected();
    float GetControlValue(int);
};

struct UnkStruct_0012FDA0_1 {
    unsigned char pad_0[0x8];
    bool field_8;
};

struct UnkStruct_0012FDA0 {
    unsigned char pad_0[0x4];
    CGtInputDevicePS2DualShock * field_4;
    UnkStruct_0012FDA0_1 * field_8;
};

struct UnkStruct_D_004E1038 {
    float field_0;
};
extern UnkStruct_D_004E1038 D_004E1038;

static inline float fabsf(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
extern "C" float func_00443820(UnkStruct_0012FDA0_1 *, int);

// 0x0012FDA0
extern "C" bool func_0012FDA0(UnkStruct_0012FDA0 * self)
{
    UnkStruct_0012FDA0_1 * t0;
    if (self->field_4->IsConnected()) {
        for (int i = 0; i < 0x1C; i++) {
            if (fabsf(self->field_4->GetControlValue(i)) > D_004E1038.field_0) {
                goto r1;
            }
        }
        t0 = self->field_8;
        goto join;
r1:
        return 1;
    } else {
        t0 = self->field_8;
    }
join:
    bool b;
    if (t0 == 0) {
        b = false;
    } else {
        b = t0->field_8;
    }
    if (b) {
        for (int i = 0; i < 0x23; i++) {
            if (fabsf(func_00443820(self->field_8, i)) > D_004E1038.field_0) {
                return 1;
            }
        }
    }
    return 0;
}

#pragma pop
