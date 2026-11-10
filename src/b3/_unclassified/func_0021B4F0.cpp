// Hand-written; the lifter refused it (N182 opt_arithtransformation off + x=1; x=f?x:0).

// N182: retail compiled this function with `#pragma opt_arithtransformation off` ([G] scoped to this function).
#pragma push
#pragma opt_arithtransformation off

// func_0021B4F0 -- hand-written (a69; the lifter refused the 'movz' conditional move). Unnamed in every table, so a
// placeholder with C linkage (the asm label); file and Area unknown. [L] Applies the sound settings record (same layout as
// func_0028B220's p0: +0x34/+0x35 volumes (signed char), +0x39 flag, +0x2C a pair of flags) to two sound objects and to
// D_004EE040's byte flags at +0x8025. Layouts [G] from instruction widths.
struct UnkStruct_0021B4F0_a0 {
    unsigned char pad_0[0x2C];
    signed char field_2C[2];
    unsigned char pad_2E[6];
    signed char field_34;
    signed char field_35;
    unsigned char pad_36[3];
    signed char field_39;
};
struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x8025];
    unsigned char field_8025[2];
    unsigned char pad_8027[0x10];
};
struct UnkStruct_D_01E75640 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E7A888 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_01E75640 D_01E75640;
extern UnkStruct_D_01E7A888 D_01E7A888;
extern "C" void func_0028AC80(void *, float);
extern "C" float func_003F8890(void *, float);
extern "C" void func_003F8870(void *, int);

// 0x0021B4F0
extern "C" void func_0021B4F0(UnkStruct_0021B4F0_a0 *p0)
{
    func_0028AC80(&D_01E75640, (float)p0->field_34 * 0.01f);
    func_003F8890(&D_01E7A888, (float)p0->field_35 * 0.01f);
    if (p0->field_39 != 0) {
        func_003F8870(&D_01E7A888, 1);
    } else {
        func_003F8870(&D_01E7A888, 0);
    }
    for (signed char i = 0; i < 2; i++) {
        int x = 1;
        x = p0->field_2C[i] ? x : 0;
        D_004EE040.field_8025[i] = x == 1;
    }
}

#pragma pop
