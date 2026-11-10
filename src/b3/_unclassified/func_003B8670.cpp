// Hand-written; the lifter refused it (near3/near7 exact; .sdata initialiser retargeted (N228)).




struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004E1E88 { short field_0; short field_2; };
extern UnkStruct_D_0051BA44 D_0051BA44;
extern unsigned int D_004E2918;
extern float D_004E0C28;
extern UnkStruct_D_004E1E88 D_004E1E88;
extern "C" unsigned short *ustrFromInt(unsigned short *, int, int, int);
extern "C" unsigned short *Append__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" unsigned short *func_00271A00(void *, int);
// 0x003B8670
extern "C" unsigned short *func_003B8670(unsigned short *buf, float f)
{
    int id;
    int n;
    if (D_004E2918 > 1) {
        id = 0x7D9;
        n = (int)f;
    } else {
        id = 0x7DA;
        n = (int)(D_004E0C28 * f);
    }
    unsigned short *s = ustrFromInt(buf, n, 1, 0);
    switch (D_004E2918) {
    case 5: case 3: case 4: {
        unsigned short sep[2] = { 0x20, 0 };
        Append__10CGtUnicodeFPUsPCUs(s, sep);
    }
    }
    return Append__10CGtUnicodeFPUsPCUs(s, func_00271A00(&D_0051BA44, id));
}
