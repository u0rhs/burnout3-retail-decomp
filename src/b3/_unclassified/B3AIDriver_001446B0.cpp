// CB3AIDriver::GetCurrentMaxSpeed() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIDriver.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a91 hand-written; pminw/pmaxw helpers, vfunc_20).

// CB3AIDriver::GetCurrentMaxSpeed() -- hand-written (lifter refused).
#include "b3/GtMath.h"
struct UnkStruct_00144800_e { unsigned char pad_0[4]; float field_4; unsigned char pad_8[8]; };
struct UnkStruct_00144800_t { unsigned char pad_0[0x10]; unsigned int field_10; unsigned char pad_14[0xC]; UnkStruct_00144800_e arr[1]; };
struct UnkStruct_D_0064D344 { UnkStruct_00144800_t *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00144800_o {
    unsigned char pad_0[0x1B0];
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual int vfunc_20();
};
struct UnkStruct_D_0051BA88 { UnkStruct_00144800_o *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00144800_car { unsigned char pad_0[0x10D4]; int field_10D4; };
struct UnkStruct_D_float16 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004E0C6C { float field_0; };
extern UnkStruct_D_0064D344 D_0064D344;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_float16 D_01E754EC;
extern UnkStruct_D_float16 D_01E754F0;
extern UnkStruct_D_004E0C6C D_004E0C6C;
static inline int a91_pmaxw(int a, int b)
{
    int r;
    asm("pmaxw %0,%1,%2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline int a91_pminw(int a, int b)
{
    int r;
    asm("pminw %0,%1,%2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline unsigned int a91_pextlw0(int a)
{
    unsigned int r;
    asm("pextlw %0,$0,%1" : "=r"(r) : "r"(a));
    return r;
}
class CB3AIDriver {
public:
    float GetCurrentMaxSpeed();
    unsigned char pad_0[0x7A0];
    UnkStruct_00144800_car *field_7A0;
    unsigned char pad_7A4[0x1C];
    float field_7C0[8];
    unsigned char pad_7E0[0x224];
    float field_A04;
    unsigned char pad_A08[8];
    signed char field_A10;
};
// 0x001446B0
float CB3AIDriver::GetCurrentMaxSpeed()
{
    UnkStruct_00144800_t *t = D_0064D344.field_0;
    if (t == 0 || field_A10 < 0 || t->field_10 == 0) {
        return D_01E754EC.field_0;
    }
    unsigned int idx = a91_pextlw0(a91_pminw(field_A10, t->field_10 - 1));
    float *pf = &t->arr[idx].field_4;
    if (*pf == 0.0f) {
        return D_01E754EC.field_0;
    }
    unsigned int d;
    if (D_0051BA88.field_0->vfunc_20() == 0) {
        d = 0;
    } else {
        d = a91_pextlw0(a91_pminw(a91_pmaxw(field_7A0->field_10D4, 0), 7));
    }
    float lim = GtMath::Min(GtMath::Max(field_A04, -4.0f), 4.0f);
    float tb = *(float *)(d * 4 + ((idx << 5) + (int)this) + 0x7C0);
    float spd = tb + lim;
    if (spd < D_004E0C6C.field_0) {
        spd = D_004E0C6C.field_0;
    }
    return GtMath::Min(GtMath::Max(*pf / spd, D_01E754F0.field_0), D_01E754EC.field_0);
}
