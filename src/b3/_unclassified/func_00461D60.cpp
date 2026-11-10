// Hand-written; the lifter refused it (a118: abs.s via asm helper; sign pun through a copy 'dd' keeps d in a register, abs(d) lazy in compare).

struct UnkStruct_00461D60 {
    unsigned char pad_0[0xA4];
    float field_A4;
    float field_A8;
};
static inline float fabsf(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
extern "C" void func_00461A70(void *);
// 0x00461D60
extern "C" void func_00461D60(UnkStruct_00461D60 * self, float step)
{
    func_00461A70(self);
    float b = self->field_A8;
    float a = self->field_A4;
    if (a != b) {
        float d = b - a;
                float dd = d;
        int bits = *(int *)&dd;
        int sg = (bits & 0x80000000) | 0x3F800000;
        float m = step * *(float *)&sg;
        float am = fabsf(m);
        if (am > fabsf(d)) {
            self->field_A4 = b;
        } else {
            self->field_A4 = a + m;
        }
    }
}
