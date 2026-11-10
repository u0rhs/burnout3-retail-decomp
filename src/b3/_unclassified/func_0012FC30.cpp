// Hand-written; the lifter refused it (a90: hand-written).

#include "b3/classes/UnkStruct_D_004F50A0.h"
class CGtInputDevicePS2DualShock {
public:
    int IsConnected();
    float GetControlValue(int);
};
struct UnkStruct_0012FC30_1 {
    unsigned char pad_0[0x8];
    unsigned char field_8;
    unsigned char field_9;
};
struct UnkStruct_0012FC30 {
    unsigned char pad_0[0x4];
    CGtInputDevicePS2DualShock * field_4;
    UnkStruct_0012FC30_1 * field_8;
    unsigned char pad_C[0x11C];
    float field_128;
};
extern UnkStruct_D_004F50A0 D_004F50A0;
extern int D_00487B60[];
extern int D_00487BD0[];
extern "C" bool IsControlJustPressed__26CGtInputDevicePS2DualShockFi(CGtInputDevicePS2DualShock *, int);
extern "C" bool func_004437F0(UnkStruct_0012FC30_1 *, int);
extern "C" float func_00443820(UnkStruct_0012FC30_1 *, int);

// 0x0012FC30
extern "C" float func_0012FC30(UnkStruct_0012FC30 * self, int p0, int p1)
{
    float r = 0.0f;
    if (self->field_4->IsConnected() != 0) {
        r = self->field_4->GetControlValue(p0);
        if (p1 != 0) {
            if (!IsControlJustPressed__26CGtInputDevicePS2DualShockFi(self->field_4, p0)) {
                r = 0.0f;
            }
        }
    }
    float k = 0.0f;
    UnkStruct_0012FC30_1 * t0 = self->field_8;
    if ((t0 == 0 ? 0 : t0->field_8) != 0) {
        int v4 = t0->field_9 != 0 ? D_00487B60[p0] : D_00487BD0[p0];
        if (v4 != -1) {
            k = func_00443820(t0, v4);
            if (p1 != 0) {
                if (!func_004437F0(self->field_8, v4)) {
                    k = 0.0f;
                }
            }
        }
    }
    r = r + k;
    if (r > 1.0f) {
        r = 1.0f;
    }
    if (r != 0.0f) {
        self->field_128 = D_004F50A0.field_0;
    }
    return r;
}
