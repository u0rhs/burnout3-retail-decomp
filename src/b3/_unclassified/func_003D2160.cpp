// Hand-written; the lifter refused it (a133: int-key record Update; same shape as 003D23A0/1AA0 (inline cmp b>a, nested-if end)).

enum UnkEnum_003D2160 { E0 = 0, E1 = 1, E2 = 2, E3 = 3 };
struct UnkStruct_003D2160_row {
    unsigned short field_0[9];
    unsigned char field_12;
    unsigned char field_13;
    signed char field_14;
    unsigned char field_15;
    float field_18;
};
struct UnkStruct_003D2160_tbl { UnkStruct_003D2160_row field_0[5]; };
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
struct UnkStruct_003D2160_loc { unsigned short field_0; unsigned short field_2; unsigned short field_4; unsigned short field_6; unsigned short field_8; unsigned short field_A; unsigned short field_C; unsigned short field_E; };
static inline UnkEnum_003D2160 func_003D2160_inl1(int a, int b)
{
    UnkEnum_003D2160 r;
    if (b > a) r = E3;
    else if (a > b) r = E0;
    else r = E1;
    return r;
}
// 0x003D2160
extern "C" void func_003D2160(UnkStruct_003D2160_tbl *self, int p0, int p1, int p2)
{
    UnkStruct_003D2160_loc loc;
    UnkStruct_003D2160_row *found = 0;
    unsigned int j = 0;
    for (; j < 5; j++) {
        if (p2 == func_003D2160_inl1(*(int *)&self->field_0[j].field_18, p0)) { found = &self->field_0[j]; break; }
    }
    if (found != 0) {
    for (unsigned int m = 4; j < m; m--) {
        self->field_0[m] = self->field_0[m - 1];
    }
    if (p2 == func_003D2160_inl1(*(int *)&found->field_18, p0)) {
    if (D_01ECDAC6.field_0 != 0 && D_01ECDAC9.field_0 != 0) {
        CopyN__10CGtUnicodeFPUsiPCUs(found->field_0, 9, &D_0064ED24);
    } else {
        CopyN__10CGtUnicodeFPUsiPCUs(found->field_0, 9, (char *)&D_004EE040 + p1 * 36 + 0x28DB4);
    }
    UnkStruct_gm_hdr *g = D_0051BA88.field_0;
    found->field_12 = func_003EB060(g->field_8[p1].field_0);
    found->field_13 = g->field_70[p1];
    found->field_14 = p1;
    func_00436350(&loc);
    found->field_15 = loc.field_8 * 3 + loc.field_A;
    *(int *)&found->field_18 = p0;
    }
    }
}
