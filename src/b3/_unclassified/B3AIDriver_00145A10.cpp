// CB3AIDriver::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIDriver.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (Ghidra draft; GetCurrentMinSpeed sibling's pmaxw/pminw/pextlw clamp + table address form; header Normalise; lim > field compare forms; N140 pad for the 0x60 frame).

// CB3AIDriver::Update() -- hand-written from the Ghidra draft (ghvu11).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIDriver.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G].
// Clamp helpers and the 0x8C0/0x7C0 table address form from the proven sibling GetCurrentMinSpeed (B3AIDriver_00144810).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00145A10_b {
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;
    unsigned char pad_C0[0x1493];
    unsigned char field_1553;
    unsigned char pad_1554[4];
    int field_1558;
};
struct UnkStruct_00145A10_car {
    unsigned char pad_0[0x10CC];
    float field_10CC;
    unsigned char pad_10D0[4];
    int field_10D4;
    unsigned char pad_10D8[0xB4];
    unsigned char field_118C[0x34];
    float field_11C0;
    unsigned char pad_11C4[0x126C];
    UnkStruct_00145A10_b *field_2430;
    unsigned char pad_2434[0x18];
    signed char field_244C;
};
struct UnkStruct_D_float16 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_float16 D_01E754EC;
extern UnkStruct_D_float16 D_00522680;
extern float D_004E0EC8;
extern "C" int func_001419B0(UnkStruct_00145A10_car *);
extern "C" UnkStruct_00145A10_car *func_001D0CB0(UnkStruct_00145A10_b *);
extern "C" void func_00144E70(void *);
extern "C" void Update__15CB3AIArbitratorFb(void *, bool);
extern "C" void AddBurn__7CB3BurnFf(void *, float);
static inline int func_00145A10_inl1(int a, int b)
{
    int r;
    asm("pmaxw %0,%1,%2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline int func_00145A10_inl2(int a, int b)
{
    int r;
    asm("pminw %0,%1,%2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline unsigned int func_00145A10_inl3(int a)
{
    unsigned int r;
    asm("pextlw %0,$0,%1" : "=r"(r) : "r"(a));
    return r;
}
// N140 pad [G]: one unused 16-byte frame slot retail has (0x60 frame).
struct UnkStruct_00145A10_pad { int x[4]; UnkStruct_00145A10_pad() {} ~UnkStruct_00145A10_pad() {} };

class CB3AIDriver {
public:
    void Update();
    float GetCurrentMinSpeed();
    float GetCurrentMaxSpeed();
    void CalculateSteerAngle();
    void CheckForDrift();
    unsigned char pad_0[0x770];
    CGtV3d field_770;
    unsigned char pad_780[4];
    float field_784;
    unsigned char pad_788[0x18];
    UnkStruct_00145A10_car *field_7A0;
    unsigned char pad_7A4[0xC];
    CGtV3d field_7B0;
    float field_7C0[8];
    unsigned char pad_7E0[0xE0];
    float field_8C0[8];
    unsigned char pad_8E0[0xE8];
    float field_9C8;
    unsigned char pad_9CC[0x30];
    float field_9FC;
    float field_A00;
    float field_A04;
    float field_A08;
    unsigned char pad_A0C[4];
    signed char field_A10;
    unsigned char pad_A11[6];
    unsigned char field_A17;
    unsigned char field_A18;
    unsigned char field_A19;
    unsigned char pad_A1A[0x12];
    float field_A2C;
    unsigned char pad_A30;
    unsigned char field_A31;
};

// 0x00145A10
void CB3AIDriver::Update()
{
    UnkStruct_00145A10_pad pad;
    float mn = GetCurrentMinSpeed();
    float mx = GetCurrentMaxSpeed();
    if (func_001419B0(field_7A0) != 0) {
        if (field_A31 == 0) {
            field_A08 = D_01E754EC.field_0;
        } else {
            UnkStruct_00145A10_car *c = func_001D0CB0(field_7A0->field_2430);
            field_A08 = GtMath::Max(c->field_2430->field_B0.W() - D_004E0EC8, mn);
        }
    } else if (field_7A0->field_2430->field_1558 == 2) {
        field_A08 = mn;
    } else {
        field_A08 = mx;
    }
    Update__15CB3AIArbitratorFb(this, false);
    UnkStruct_00145A10_car *car = field_7A0;
    unsigned int d = func_00145A10_inl3(func_00145A10_inl2(func_00145A10_inl1(car->field_10D4, 0), 7));
    if (field_A10 == -1) {
        field_A10 = car->field_244C;
    } else if (field_A10 != car->field_244C) {
        field_A04 = 0.0f;
        if (field_9FC < 0.0f) {
            field_9FC = field_7A0->field_10CC;
            field_A00 = field_7A0->field_10CC;
        } else {
            field_9FC += *(float *)(d * 4 + ((field_A10 << 5) + (int)this) + 0x8C0);
            if (field_7A0->field_10CC > field_9FC) field_A04 = field_9FC - field_7A0->field_10CC;
            field_A00 += *(float *)(d * 4 + ((field_A10 << 5) + (int)this) + 0x7C0);
            if (field_7A0->field_10CC < field_A00) field_A04 = field_A00 - field_7A0->field_10CC;
        }
        field_A10 = field_7A0->field_244C;
    }
    field_7B0 = field_770;
    field_9C8 = field_784;
    field_7B0.Normalise();
    CalculateSteerAngle();
    CheckForDrift();
    func_00144E70(this);
    if (field_A2C != -1.0f) {
        if (D_00522680.field_0 > field_A2C) field_A2C = -1.0f;
        field_A18 = 1;
    }
    if (field_A18 != 0) {
        AddBurn__7CB3BurnFf(field_7A0->field_118C, field_7A0->field_11C0);
        field_A19 = 1;
    } else if (field_A17 != 0) {
        field_A19 = 1;
    } else {
        field_A19 = 0;
    }
    field_A17 = 0;
    field_A18 = 0;
    if (field_A04 > 0.0f && field_A31 != 0) field_7A0->field_2430->field_1553 = 1;
}
