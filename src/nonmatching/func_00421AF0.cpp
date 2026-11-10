// NONMATCHING: func_00421AF0 -- retail 210 / ours 215 instructions, 103 in changed runs
// fix2 (2026-11-01): CopyN__10CGtUnicodeFPUsiPCUs declared extern "C" (retail's symbol is unmangled; the C++ declaration linked ustrncpy__FPUsiPUs) | Before: a156: 215 vs 210 instrs, 103 changed. Logic/control flow right (init block out of line via goto; 0x2C-byte signed char struct copy + 20 separate byte-global copies D_004F506C..507F into self+0xE350; profile slot self+0xE390+idx*0x49C: keep/fresh(name save via CopyN__10CGtUnicodeFPUsiPCUs)/copy 0x127 words; float fixup f4 += f18-f14; word checksum of 0x3C52 words stored at w[0x3C52]). Left: register allocation. Retail keeps only s0..s4 (p4=s0 which is reused for the profile pointer, name=s1, idx=s2, self=s3, hdr=s4) so the 20 byte-field copies run in t/a/v registers with lui's interleaved; ours puts p4=s7/hdr=s6 leaving s3-s5 free, hoists all 20 lui and spills temps into s3-s5 (frame 0xB0 vs 0x80, +5 instrs).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// Hand-written (a156): save-buffer builder -- fills the header/profile slots of the memory-card image and checksums it.
struct UnkStruct_UB { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_SB { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_Name2C { signed char b[0x2C]; };
struct UnkStruct_Hdr {
    UnkStruct_Name2C field_0;
    unsigned char field_2C;
    unsigned char field_2D;
    unsigned char field_2E;
    unsigned char field_2F;
    signed char field_30;
    signed char field_31;
    signed char field_32;
    signed char field_33;
    signed char field_34;
    signed char field_35;
    signed char field_36;
    signed char field_37;
    signed char field_38;
    signed char field_39;
    signed char field_3A;
    signed char field_3B;
    signed char field_3C;
    unsigned char field_3D;
    unsigned char field_3E;
    signed char field_3F;
};
struct UnkStruct_Profile { int w[0x127]; };
struct UnkStruct_Prof2 { int w[0x127]; };
struct UnkStruct_D_0051BF9C { UnkStruct_Profile * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_Blk8A { int w[0x9D8 * 2]; };
struct UnkStruct_Blk8B { int w[0x128E * 2]; };
struct UnkStruct_00421AF0 {
    unsigned char pad_0[0x14];
    float field_14;
    float field_18;
    int field_1C[1];
};
extern UnkStruct_Name2C D_004F5040;
extern UnkStruct_Blk8A D_01EA7810;
extern UnkStruct_Blk8B D_01EAC6D0;
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_UB D_004F506C;
extern UnkStruct_UB D_004F506D;
extern UnkStruct_UB D_004F506E;
extern UnkStruct_UB D_004F506F;
extern UnkStruct_SB D_004F5070;
extern UnkStruct_SB D_004F5071;
extern UnkStruct_SB D_004F5072;
extern UnkStruct_SB D_004F5073;
extern UnkStruct_SB D_004F5074;
extern UnkStruct_SB D_004F5075;
extern UnkStruct_SB D_004F5076;
extern UnkStruct_SB D_004F5077;
extern UnkStruct_SB D_004F5078;
extern UnkStruct_SB D_004F5079;
extern UnkStruct_SB D_004F507A;
extern UnkStruct_SB D_004F507B;
extern UnkStruct_SB D_004F507C;
extern UnkStruct_UB D_004F507D;
extern UnkStruct_UB D_004F507E;
extern UnkStruct_SB D_004F507F;
extern "C" int func_0013B820(void *);
extern "C" void func_0013B740(void *, unsigned short *);
extern "C" void func_0013A570(void *);
extern "C" unsigned short * func_0013B730(void *);
extern "C" unsigned short * CopyN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, unsigned short *);   // [C] retail symbol CopyN__10CGtUnicodeFPUsiPCUs (C linkage, as the matched func_0026D2A0)

// 0x00421AF0
extern "C" void func_00421AF0(UnkStruct_00421AF0 * self, int idx, unsigned short * name, int flag, int p4)
{
    unsigned short buf[9];
    UnkStruct_Hdr * h;
    UnkStruct_Profile * pr;
    self->field_1C[0] = 16;
    if (flag != 0) goto init;
back:
    h = (UnkStruct_Hdr *)((char *)self + 0xE350);
    h->field_0 = D_004F5040;
    h->field_2C = D_004F506C.field_0;
    h->field_2D = D_004F506D.field_0;
    h->field_2E = D_004F506E.field_0;
    h->field_2F = D_004F506F.field_0;
    h->field_30 = D_004F5070.field_0;
    h->field_31 = D_004F5071.field_0;
    h->field_32 = D_004F5072.field_0;
    h->field_33 = D_004F5073.field_0;
    h->field_34 = D_004F5074.field_0;
    h->field_35 = D_004F5075.field_0;
    h->field_36 = D_004F5076.field_0;
    h->field_37 = D_004F5077.field_0;
    h->field_38 = D_004F5078.field_0;
    h->field_39 = D_004F5079.field_0;
    h->field_3A = D_004F507A.field_0;
    h->field_3B = D_004F507B.field_0;
    h->field_3C = D_004F507C.field_0;
    h->field_3D = D_004F507D.field_0;
    h->field_3E = D_004F507E.field_0;
    h->field_3F = D_004F507F.field_0;
    if (p4 != 0) goto keep;
    pr = (UnkStruct_Profile *)((char *)self + 0xE390 + idx * 0x49C);
    if (name == 0) goto fresh;
    *pr = *D_0051BF9C.field_0;
fix:
    ((float *)pr)[1] = ((float *)pr)[1] + (self->field_18 - self->field_14);
join:
    if (name != 0) {
        func_0013B740(pr, name);
    }
    func_0013A570(pr);
    {
        int *w = self->field_1C;
        int sum = 0;
        unsigned int i = 0;
        do {
            sum += w[i];
            i++;
        } while (i < 0x3C52);
        w[0x3C52] = sum;
    }
    return;
init:
    {
        unsigned int k;
        for (k = 0; k < 3; k++) {
            func_0013B820((char *)self + 0xE390 + k * 0x49C);
        }
        *(UnkStruct_Blk8A *)((char *)self + 0x20) = D_01EA7810;
        *(UnkStruct_Blk8B *)((char *)self + 0x20 + 0x4EC0) = D_01EAC6D0;
    }
    goto back;
keep:
    pr = (UnkStruct_Profile *)((char *)self + 0xE390 + idx * 0x49C);
    func_0013B820(pr);
    goto join;
fresh:
    {
        unsigned short * nm = func_0013B730(pr);
        CopyN__10CGtUnicodeFPUsiPCUs(buf, 9, nm);
        *pr = *D_0051BF9C.field_0;
        func_0013B740(pr, buf);
    }
    goto fix;
}
