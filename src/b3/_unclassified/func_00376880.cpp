// Hand-written; the lifter refused it (near3/near7 exact; .sdata initialiser retargeted (N228)).



struct UnkStruct_D_01E3CD44 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E3CD44 D_0051BA44;
extern unsigned int D_004E2918;
extern float D_004E0C28;
extern short D_004E1E38;
extern short D_004E1E3A;
extern char D_004C9028[];
extern "C" void GetRankingData__20CGtLobbyPS2DirtySockFiiPci(void *, int, int, char *, int);
extern "C" int strcmp(const char *, const char *);
extern "C" int atoi(const char *);
extern "C" unsigned short * ustrFromInt(unsigned short *, int, int, int);
extern "C" unsigned short * ustrFromFloat(unsigned short *, float, int, int);
extern "C" unsigned short * Append__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" int Length__10CGtUnicodeFPCUs(const unsigned short *);
extern "C" unsigned short * Copy__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, unsigned short *, int);
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" void func_003B8750(unsigned short *, float);
extern "C" void func_003B8840(unsigned short *);
// 0x00376880
extern "C" void func_00376880(void *p0_, int p1, unsigned short * out, unsigned int kind)
{
    int p0 = (int)p0_;
    char buf[32];
    GetRankingData__20CGtLobbyPS2DirtySockFiiPci(&D_01E3CD44, p1, 2, buf, 0x20);
    if (strcmp(buf, D_004C9028) != 0) {
        int v = atoi(buf);
        switch (kind) {
        case 0:
        case 2:
        case 5:
            ustrFromInt(out, v, 1, 0);
            break;
        case 3:
        case 4: {
            float f;
            int id;
            if (D_004E2918 > 1) {
                f = (float)v;
                id = 0x7EB;
            } else {
                f = D_004E0C28 * (float)v;
                id = 0x7EC;
            }
            const unsigned short * s = func_00271A00(&D_0051BA44, id);
            ustrFromFloat(out, f, 0, 0);
            switch (D_004E2918) {
            case 5:
            case 3:
            case 4: {
                unsigned short tmp[2] = {0x20, 0};
                Append__10CGtUnicodeFPUsPCUs(out, tmp);
                break;
            }
            }
            Copy__10CGtUnicodeFPUsPCUs(out + Length__10CGtUnicodeFPCUs(out), s);
            break;
        }
        case 6:
            func_003B8750(out, (float)v / 1000.0f);
            break;
        case 1:
        case 7:
        case 8:
            func_003B8840(out);
            break;
        }
    } else {
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, out, 0x20);
    }
}
