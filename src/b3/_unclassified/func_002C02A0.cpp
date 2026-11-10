// Hand-written; the lifter refused it (a244 exact; linker 16-byte padding between per-function sections (a146_cmp now pads)).


struct UnkStruct_002C02A0_b {
    unsigned char pad_0[0x14];
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual int vfunc_24();
};
struct UnkStruct_002C02A0 {
    unsigned char pad_0[0x4];
    UnkStruct_002C02A0_b * field_4;
};
// 0x002C02A0
extern "C" int func_002C02A0(UnkStruct_002C02A0 * self)
{
    return self->field_4->vfunc_24();
}
struct UnkStruct_002C02C0 {
    unsigned char pad_0[0x8180];
    float field_8180;
};
// 0x002C02C0
extern "C" float func_002C02C0(UnkStruct_002C02C0 * self)
{
    return self->field_8180;
}
