// Hand-written; the lifter refused it (a133: fill-row helper; D_00522660+idx*0x27D0+0x12C6FC byte (retail reloc as __moddi3+0x4C, same bytes: cf. B3SoundListener_0028AB60); enum diamond for flag; element-pointer addu order).

enum UnkEnum_003D2630 { E0 = 0, E1 = 1 };
struct UnkStruct_003D2630 {
    unsigned short field_0[9];
    unsigned char field_12;
    unsigned char field_13;
    signed char field_14;
    unsigned char field_15;
    unsigned char pad_16[6];
    unsigned short field_1C[9];
    unsigned char field_2E;
    unsigned char field_2F;
};
struct UnkStruct_gm_ent { unsigned long field_0; };
struct UnkStruct_gm_hdr { unsigned char pad_0[8]; UnkStruct_gm_ent field_8[2]; unsigned char pad_18[0x58]; int field_70[2]; };
struct UnkStruct_D_0051BA88_x { UnkStruct_gm_hdr *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_gen { unsigned char pad_0[0x10]; };
struct UnkStruct_D_byte { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x28DB4]; };
struct UnkStruct_D_00522660_x { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0064D388 { char *field_0[2]; unsigned char pad_8[8]; };
extern UnkStruct_D_byte D_01ECDAC6, D_01ECDAC9, D_01E65499;
extern UnkStruct_D_0051BA88_x D_0051BA88;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_00522660_x D_00522660;
extern UnkStruct_D_gen D_0064ED24;
extern UnkStruct_D_0064D388 D_0064D388;
extern "C" unsigned short *CopyN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, void *);
extern "C" unsigned char func_003EB060(unsigned long);
extern "C" void func_00436350(void *);
struct UnkStruct_003D2630_loc { unsigned short field_0; unsigned short field_2; unsigned short field_4; unsigned short field_6; unsigned short field_8; unsigned short field_A; unsigned short field_C; unsigned short field_E; };
// 0x003D2630
extern "C" void func_003D2630(UnkStruct_003D2630 *self, int p0)
{
    UnkStruct_003D2630_loc loc;
    if (D_01ECDAC6.field_0 != 0 && D_01ECDAC9.field_0 != 0) {
        CopyN__10CGtUnicodeFPUsiPCUs(self->field_0, 9, &D_0064ED24);
    } else {
        CopyN__10CGtUnicodeFPUsiPCUs(self->field_0, 9, (char *)&D_004EE040 + p0 * 36 + 0x28DB4);
    }
    UnkStruct_gm_hdr *g = D_0051BA88.field_0;
    self->field_12 = func_003EB060(g->field_8[p0].field_0);
    self->field_13 = g->field_70[p0];
    self->field_14 = p0;
    func_00436350(&loc);
    self->field_15 = loc.field_8 * 3 + loc.field_A;
    UnkEnum_003D2630 s1;
    if (*((signed char *)&D_00522660 + p0 * 0x27D0 + 0x12C6FC) == 0) s1 = E1; else s1 = E0;
    CopyN__10CGtUnicodeFPUsiPCUs(self->field_1C, 9, D_0064D388.field_0[s1] + 0x1974);
    UnkStruct_gm_hdr *g2 = D_0051BA88.field_0;
    unsigned long a0;
    if (D_01E65499.field_0 != 0) {
        a0 = *(unsigned long *)((char *)g2 + 0x40);
        self->field_2F = *(int *)((char *)g2 + 0x8C);
    } else {
        int v = g2->field_70[s1];
        a0 = g2->field_8[s1].field_0;
        self->field_2F = v;
    }
    self->field_2E = func_003EB060(a0);
}
