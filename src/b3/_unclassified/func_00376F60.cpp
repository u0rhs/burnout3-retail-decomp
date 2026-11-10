// Hand-written; the lifter refused it (sig1: Append__10CGtUnicodeFPUsPCUs separator is an aggregate-initialised local unsigned short tmp[2] = {0x20,0} (hidden template = D_004E1E38, a228 pattern); sigcheck RETURN flag was pointer-vs-int false positive).


struct UnkStruct_00376F60_fn { void * field_0; void * field_4; int field_8; };
struct UnkStruct_00376F60 {
    unsigned char pad_0[0xB10];
    unsigned short * field_B10;
    unsigned short * field_B14;
    unsigned char pad_B18[0x4];
    unsigned short * field_B1C;
    unsigned char pad_B20[0x80];
    unsigned long field_BA0;
    unsigned char pad_BA8[0x190];
    UnkStruct_00376F60_fn field_D38[5];
    unsigned char pad_D74[0x174];
    unsigned long field_EE8;
    unsigned char pad_EF0[0x14];
    signed char field_F04;
};
struct UnkStruct_rec1 { unsigned char pad_0[0x12]; unsigned char field_12; unsigned char pad_13[0x5]; float field_18; unsigned char pad_1C[0x82]; unsigned char field_9E; unsigned char pad_9F[0x5]; int field_A4; };
struct UnkStruct_rec2 { unsigned char pad_0[0x12]; unsigned char field_12; unsigned char pad_13[0x5]; int field_18; unsigned char pad_1C[0x82]; unsigned char field_9E; unsigned char pad_9F[0x5]; int field_A4; };
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_Ptr16 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004E2918 { unsigned int field_0; };
struct UnkStruct_D_004E0C28 { float field_0; };
struct UnkStruct_D_004E1E38 { short field_0; short field_2; };
class CGtLobbyPS2DirtySock {
public:
    int GetRankingData(int, int, char*, int);
    int GetUserRankingData(int, char*, int);
    unsigned char pad_0[0x10];
};
extern CGtLobbyPS2DirtySock D_01E3CD44;
extern UnkStruct_D_Pad16 D_0051BA44, D_004C9028, D_01EA7810;
extern UnkStruct_D_Ptr16 D_0051BF9C;
extern UnkStruct_D_004E2918 D_004E2918;
extern UnkStruct_D_004E0C28 D_004E0C28;
extern UnkStruct_D_004E1E38 D_004E1E38;
extern "C" int func_003367B0(void *);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(const char *, unsigned short *, int);
extern "C" unsigned short * ustrFromInt(unsigned short *, int, int, int);
extern "C" void ustrFromFloat(unsigned short *, float, int, int);
extern "C" unsigned short * Append__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" unsigned short * Copy__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" unsigned int Length__10CGtUnicodeFPCUs(const unsigned short *);
extern "C" int atoi(const char *);
extern "C" int func_0013B660(void *);
extern "C" unsigned long func_0013A5C0(void *);
extern "C" int func_0013B570(void *);
extern "C" void func_003B8840(unsigned short *, int);
extern "C" int func_0013B200(void *, unsigned long, int);
extern "C" float func_0013B090(void *, unsigned long);
extern "C" float func_0013AEF0(void *, unsigned long);
extern "C" unsigned long func_0013B010(void *);
extern "C" unsigned long func_0013AE70(void *);
extern "C" unsigned short * func_00271A00(void *, int);
extern "C" UnkStruct_rec1 * GetTrackRecords__10CB3RecordsFUl(void *, unsigned long);
extern "C" UnkStruct_rec2 * func_003D1000(void *, unsigned long);
extern "C" void func_003B8750(unsigned short *, float);
extern "C" unsigned long GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(int);
extern "C" void func_00376880(void *, int, unsigned short *, int);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const void *, const void *, unsigned short*, const void *, const void*);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, const void *, const void*);
extern "C" void func_0033F620(const void *, const void *, unsigned short*, const void *, const void*);
extern "C" float GetCarIconSize__17CB3TableComponentFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, const void *, const void*);

// 0x00376F60
extern "C" void func_00376F60(UnkStruct_00376F60 * self)
{
    int r = func_003367B0(&D_01E3CD44);
    unsigned short * txt = self->field_B14;
    if (r == -1) {
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi((const char *)&D_004C9028, self->field_B10, 0x20);
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi((const char *)&D_004C9028, self->field_B1C, 0x20);
        switch (self->field_F04) {
        case 0:
            ustrFromInt(txt, func_0013B660(D_0051BF9C.field_0), 1, 0);
            self->field_BA0 = func_0013A5C0(D_0051BF9C.field_0);
            break;
        case 1:
            func_003B8840(txt, func_0013B570(D_0051BF9C.field_0));
            self->field_BA0 = func_0013A5C0(D_0051BF9C.field_0);
            break;
        case 2:
            ustrFromInt(txt, func_0013B200(D_0051BF9C.field_0, 0, 1), 1, 0);
            self->field_BA0 = func_0013A5C0(D_0051BF9C.field_0);
            break;
        case 3: {
            float f = func_0013B090(D_0051BF9C.field_0, 0);
            float f20;
            int id;
            if (D_004E2918.field_0 > 1) { f20 = f; id = 0x7EB; } else { id = 0x7EC; f20 = D_004E0C28.field_0 * f; }
            unsigned short * s = func_00271A00(&D_0051BA44, id);
            ustrFromFloat(txt, f20, 0, 0);
            switch (D_004E2918.field_0) {
            case 5:
            case 3:
            case 4:
                goto cat3;
            default:
                break;
            }
        back3:
            Copy__10CGtUnicodeFPUsPCUs(txt + Length__10CGtUnicodeFPCUs(txt), s);
            self->field_BA0 = func_0013B010(D_0051BF9C.field_0);
            break;
        }
        case 4: {
            float f = func_0013AEF0(D_0051BF9C.field_0, 0);
            float f20;
            int id;
            if (D_004E2918.field_0 > 1) { f20 = f; id = 0x7EB; } else { id = 0x7EC; f20 = D_004E0C28.field_0 * f; }
            unsigned short * s = func_00271A00(&D_0051BA44, id);
            ustrFromFloat(txt, f20, 0, 0);
            switch (D_004E2918.field_0) {
            case 5:
            case 3:
            case 4:
                goto cat4;
            default:
                break;
            }
        back4:
            Copy__10CGtUnicodeFPUsPCUs(txt + Length__10CGtUnicodeFPCUs(txt), s);
            self->field_BA0 = func_0013AE70(D_0051BF9C.field_0);
            break;
        }
        case 5:
            ustrFromInt(txt, GetTrackRecords__10CB3RecordsFUl(&D_01EA7810, self->field_EE8)->field_A4, 1, 0);
            self->field_BA0 = GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(GetTrackRecords__10CB3RecordsFUl(&D_01EA7810, self->field_EE8)->field_9E);
            break;
        case 6:
            func_003B8750(txt, GetTrackRecords__10CB3RecordsFUl(&D_01EA7810, self->field_EE8)->field_18);
            self->field_BA0 = GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(GetTrackRecords__10CB3RecordsFUl(&D_01EA7810, self->field_EE8)->field_12);
            break;
        case 7:
            func_003B8840(txt, func_003D1000(&D_01EA7810, self->field_EE8)->field_18);
            self->field_BA0 = GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(func_003D1000(&D_01EA7810, self->field_EE8)->field_12);
            break;
        case 8:
            func_003B8840(txt, func_003D1000(&D_01EA7810, self->field_EE8)->field_A4);
            self->field_BA0 = GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(func_003D1000(&D_01EA7810, self->field_EE8)->field_9E);
            break;
        }
    } else {
        char buf[0x20];
        D_01E3CD44.GetUserRankingData(0, buf, 0x20);
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, self->field_B10, 0x20);
        func_00376880(self, r, txt, self->field_F04);
        self->field_BA0 = 0;
        if (D_01E3CD44.GetUserRankingData(3, buf, 0x20) == 2) {
            int v = atoi(buf);
            if (v >= 0 && v < 0x43) {
                self->field_BA0 = GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(v);
            }
        }
        if (self->field_F04 == 3) {
            D_01E3CD44.GetRankingData(r, 5, buf, 0x20);
        } else if (self->field_F04 == 8) {
            D_01E3CD44.GetRankingData(r, 6, buf, 0x20);
        } else {
            D_01E3CD44.GetRankingData(r, 4, buf, 0x20);
        }
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, self->field_B1C, 0x20);
    }
    if (self->field_BA0 != 0) {
        self->field_D38[4].field_0 = (void *)&func_0033F620;
        self->field_D38[4].field_4 = (void *)&GetCarIconSize__17CB3TableComponentFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
    } else {
        self->field_D38[4].field_0 = 0;
        self->field_D38[4].field_4 = 0;
    }
    self->field_D38[2].field_0 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
    self->field_D38[2].field_4 = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
    self->field_D38[0].field_0 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
    self->field_D38[0].field_4 = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
    self->field_D38[1].field_0 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
    self->field_D38[1].field_4 = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
    self->field_D38[3].field_0 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
    self->field_D38[3].field_4 = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
    return;
cat3: {
        unsigned short tmp[2] = { 0x20, 0 };
        Append__10CGtUnicodeFPUsPCUs(txt, tmp);
        goto back3;
    }
cat4: {
        unsigned short tmp[2] = { 0x20, 0 };
        Append__10CGtUnicodeFPUsPCUs(txt, tmp);
        goto back4;
    }
}
