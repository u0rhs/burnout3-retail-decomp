// Hand-written; the lifter refused it (a90: hand-written; f=d-e; f*=2; v+=f avoids madd).

class CGtInputDevicePS2DualShock {
public:
    float GetControlValue(int);
};
struct UnkStruct_0012F720_1 {
    unsigned char pad_0[0x8];
    bool field_8;
};
struct UnkStruct_0012F720 {
    unsigned char pad_0[0x4];
    CGtInputDevicePS2DualShock * field_4;
    UnkStruct_0012F720_1 * field_8;
};
static inline float fabsf(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
extern "C" float func_00443820(UnkStruct_0012F720_1 *, int);
extern "C" float func_0011E388(float, float);

// 0x0012F720
extern "C" float func_0012F720(UnkStruct_0012F720 * self)
{
    UnkStruct_0012F720_1 * t0 = self->field_8;
    bool b;
    if (t0 == 0) {
        b = false;
    } else {
        b = t0->field_8;
    }
    float v;
    if (b) {
        float a = func_00443820(*(UnkStruct_0012F720_1 * const *)&self->field_8, 33);
        v = a - func_00443820(t0, 34);
    } else {
        float c = self->field_4->GetControlValue(25);
        v = func_0011E388(fabsf(c), 2.5f);
        if (c < 0.0f) {
            v = v * -1.0f;
        }
        float d = self->field_4->GetControlValue(4);
        float e = self->field_4->GetControlValue(5);
        float f = d - e;
        f *= 2.0f;
        v += f;
    }
    if (v > 1.0f) {
        v = 1.0f;
    }
    if (v < -1.0f) {
        v = -1.0f;
    }
    return v;
}
