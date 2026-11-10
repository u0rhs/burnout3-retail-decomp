// Hand-written; the lifter refused it (static callback 9 args; const ptr g=&D_01E90240; byte-offset row quad copy).

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_00396860_row {
    u_long128 field_0;
    unsigned char pad_10[0x40];
};
struct UnkStruct_00396860_obj {
    unsigned char pad_0[0x180];
    UnkStruct_00396860_row field_180[1];
    unsigned char pad_1D0[0x430 - 0x1D0];
    unsigned short *field_430[1];
    unsigned char pad_434[0x464 - 0x434];
    int field_464;
    int field_468;
};
struct UnkStruct_D_01E90240_q { u_long128 field_0; };
extern UnkStruct_D_01E90240_q D_01E90240;
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, unsigned short *, int);
// 0x00396860
extern "C" int func_00396860(char *p0, int p1, bool p2, int p3, int p4, int p5, char *p6, bool p7, UnkStruct_00396860_obj *p8)
{
    UnkStruct_D_01E90240_q * const g = &D_01E90240;
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(p0, p8->field_430[p8->field_468], 32);
    if (p2) {
        p8->field_464 = p8->field_468;
    }
    int i = p8->field_468;
    *(u_long128 *)((char *)p8 + 0x180 + i * 0x50) = g->field_0;
    p8->field_468 = p8->field_468 + 1;
    return 1;
}
