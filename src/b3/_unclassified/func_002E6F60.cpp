// Hand-written; the lifter refused it (int s = a <= b; goto-form join stub (done: return; other-arm goto done); was 7 off).


// func_002E6F60 -- hand-written (a69). Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown.
// [L] (no new_names.csv row) Switches between the two player viewports' objects: if func_00131CA0(&D_004EE040) it notifies
// both rows of D_004EE040 (stride 0xBB0 at +0x28E00, vfunc_14(0xC / 0xE, 0)) and sets the single-player viewport; else it
// notifies D_00516E40 only.
struct UnkStruct_row {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int);
};
struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
struct UnkStruct_D_00516E40 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0064B928 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064C978 { int field_0; unsigned char pad_4[0xC]; };

extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_00516E40 D_00516E40;
extern UnkStruct_D_00665EC0 D_00665EC0;
extern UnkStruct_D_0064B928 D_0064B928;
extern UnkStruct_D_0064C978 D_0064C978;
extern "C" int func_00131CA0(void *);
extern "C" void SetViewportsSinglePlayer__22CB3GraphicsManagerBaseFv(void *, int);  // a1 is a phantom (leftover s0)

// 0x002E6F60
extern "C" void func_002E6F60()
{
    if (!func_00131CA0(&D_004EE040)) goto other;
    {
        int a = D_0064B928.field_0;
        int b = D_0064C978.field_0;
        int s = a <= b;
        ((UnkStruct_row *)((char *)&D_004EE040 + s * 0xBB0 + 0x28E00))->vfunc_14(12, 0);
        int t = (s ^ 1) != 0;
        ((UnkStruct_row *)((char *)&D_004EE040 + t * 0xBB0 + 0x28E00))->vfunc_14(14, 0);
        SetViewportsSinglePlayer__22CB3GraphicsManagerBaseFv(&D_00665EC0, s);
    }
done:
    return;
other:
    ((UnkStruct_D_00516E40 *)&D_00516E40)->vfunc_14(12, 0);
    goto done;
}
