// Hand-written; the lifter refused it (near29: float local in cases 21/24, single func_0013B010/AE70 calls, tmp[2] = {0x20, 0} initialiser, case 1 break).

// func_003F1490: profile stat -> display string (30-case jump table). Hand-matched by near29 from the archived lift:
// cases 21/24 test a float local (keeps the fallback block inline), one call each to func_0013B010/func_0013AE70
// (the lift called them twice), the ' ' suffix as an aggregate-initialised local (.sdata template D_004E1EA8),
// case 1 ends with break (the shared return stub fills only the first branch to it).

// [G] profile stat -> display string (switch over 30 stats via jtbl_004CE0C0); sibling of the CB3MyBurnoutRewardsStatsPage functions
struct UnkStruct_D_o { unsigned char pad_0[0x10]; };
struct UnkStruct_D_p { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_i { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_u { unsigned int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_f { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_sh { short field_0; short field_2; unsigned char pad_4[0xC]; };
struct UnkStruct_3F1490_v { int field_0; };
extern UnkStruct_D_o D_0051BA44;
extern UnkStruct_D_p D_0051BF9C;
extern unsigned int D_004E2918;
extern float D_004E0C28;
extern unsigned short D_004CE0B8[];
extern int D_004A5520[];
extern "C" unsigned short * ustrFromInt(unsigned short *, int, int, int);
extern "C" void ustrFromFloat(unsigned short *, float, int, int);
extern "C" unsigned short * Copy__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" unsigned short * Append__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" int Length__10CGtUnicodeFPCUs(const unsigned short *);
extern "C" unsigned short * func_00271A00(void *, int);
extern "C" void func_00322620(unsigned short *, unsigned short *, const UnkStruct_3F1490_v *, const UnkStruct_3F1490_v *);
extern "C" void *func_001A3AA0(unsigned short *, unsigned short *, const UnkStruct_3F1490_v *);
extern "C" unsigned long GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(int);
extern "C" int func_003EB060(unsigned long);
extern "C" int func_003EAE40(int, int);
extern "C" void * FindTrack__21CB3HardCodedTrackListFUl(unsigned long);
extern "C" int func_003EAAE0(void *);
extern "C" int GetChallengeUnlockedCount__10CB3ProfileFv(void *);
extern "C" int func_0013B660(void *);
extern "C" int func_0013B570(void *);
extern "C" int func_0013ACF0(void *);
extern "C" int func_0013AD00(void *);
extern "C" int func_0013A880(void *);
extern "C" unsigned long func_0013A5C0(void *);
extern "C" int func_0013A650(void *);
extern "C" int func_0013A7F0(void *);
extern "C" int func_0013A7D0(void *);
extern "C" int func_0013A620(void *);
extern "C" int func_0013A5B0(void *);
extern "C" unsigned long func_0013B050(void *);
extern "C" unsigned long func_0013AEB0(void *);
extern "C" unsigned long func_0013AE70(void *);
extern "C" unsigned long func_0013B010(void *);
extern "C" int func_0013B1B0(void *, int);
extern "C" int func_0013AE20(void *, int);
extern "C" int func_0013ADD0(void *, int);
extern "C" int func_0013A890(void *, int);
extern "C" int func_0013B200(void *, unsigned long, int);
extern "C" int func_0013AB80(void *, int, int);
extern "C" int func_0013AA10(void *, int, int);
extern "C" int func_0013A8A0(void *, int, int);
extern "C" float func_0013B090(void *, unsigned long);
extern "C" float func_0013AEF0(void *, unsigned long);
// 0x003F1490
extern "C" bool func_003F1490(unsigned short * out, int stat, int mode)
{
    void * p = D_0051BF9C.field_0;
    if (mode == 0) {
        unsigned short * s = func_00271A00(&D_0051BA44, D_004A5520[stat]);
        if (s != 0) {
            Copy__10CGtUnicodeFPUsPCUs(out, s);
        } else {
            out[0] = 0x3F;
            out[1] = 0;
        }
        goto done;
    }
    switch (stat) {
    case 1:
        ustrFromInt(out, func_0013B660(p), 1, 0);
        break;
    case 2:
        ustrFromInt(out, func_0013B570(p), 1, 0);
        break;
    case 3:
        ustrFromInt(out, func_0013B200(p, 0, 0), 1, 0);
        break;
    case 4:
        ustrFromInt(out, func_0013B200(p, 0, 1), 1, 0);
        break;
    case 5:
        ustrFromInt(out, func_0013B1B0(p, 0), 1, 0);
        break;
    case 6:
        ustrFromInt(out, func_0013B1B0(p, 1), 1, 0);
        break;
    case 7:
        ustrFromInt(out, func_0013AE20(p, 0), 1, 0);
        break;
    case 8:
        ustrFromInt(out, func_0013AE20(p, 1), 1, 0);
        break;
    case 9:
        ustrFromInt(out, func_0013ADD0(p, 0), 1, 0);
        break;
    case 10:
        ustrFromInt(out, func_0013ADD0(p, 1), 1, 0);
        break;
    case 11:
        ustrFromInt(out, GetChallengeUnlockedCount__10CB3ProfileFv(p), 1, 0);
        break;
    case 12:
        {
            UnkStruct_3F1490_v v;
            UnkStruct_3F1490_v hi;
            hi.field_0 = 0xAD;
            v.field_0 = func_0013AD00(p);
            func_00322620(out, func_00271A00(&D_0051BA44, 0x3CA), &v, &hi);
        }
        break;
    case 13:
        ustrFromInt(out, func_0013ACF0(p), 1, 0);
        {
            UnkStruct_3F1490_v v;
            UnkStruct_3F1490_v hi;
            int s = func_0013AB80(p, 4, 0);
            s += func_0013AA10(p, 4, 0);
            int last = func_0013A8A0(p, 4, 0);
            hi.field_0 = last + s;
            v.field_0 = func_0013ACF0(p);
            func_00322620(out, func_00271A00(&D_0051BA44, 0x3CA), &v, &hi);
        }
        break;
    case 14:
        {
            UnkStruct_3F1490_v v;
            UnkStruct_3F1490_v hi;
            hi.field_0 = 0xA;
            v.field_0 = func_0013A880(p);
            func_00322620(out, func_00271A00(&D_0051BA44, 0x3CA), &v, &hi);
        }
        break;
    case 15:
        {
            UnkStruct_3F1490_v v;
            UnkStruct_3F1490_v hi;
            hi.field_0 = 0xAD;
            v.field_0 = func_0013A890(p, 0);
            func_00322620(out, func_00271A00(&D_0051BA44, 0x3CA), &v, &hi);
        }
        break;
    case 16:
        {
            UnkStruct_3F1490_v v;
            UnkStruct_3F1490_v hi;
            hi.field_0 = func_0013AB80(p, 4, 0);
            int s = func_0013AB80(p, 3, 0);
            s += func_0013AB80(p, 2, 0);
            int last = func_0013AB80(p, 1, 0);
            v.field_0 = last + s;
            func_00322620(out, func_00271A00(&D_0051BA44, 0x3CA), &v, &hi);
        }
        break;
    case 17:
        {
            UnkStruct_3F1490_v v;
            UnkStruct_3F1490_v hi;
            hi.field_0 = func_0013AA10(p, 4, 0);
            int s = func_0013AA10(p, 3, 0);
            s += func_0013AA10(p, 2, 0);
            int last = func_0013AA10(p, 1, 0);
            v.field_0 = last + s;
            func_00322620(out, func_00271A00(&D_0051BA44, 0x3CA), &v, &hi);
        }
        break;
    case 18:
        {
            UnkStruct_3F1490_v v;
            UnkStruct_3F1490_v hi;
            hi.field_0 = func_0013A8A0(p, 4, 0);
            int s = func_0013A8A0(p, 3, 0);
            s += func_0013A8A0(p, 2, 0);
            int last = func_0013A8A0(p, 1, 0);
            v.field_0 = last + s;
            func_00322620(out, func_00271A00(&D_0051BA44, 0x3CA), &v, &hi);
        }
        break;
    case 19:
        {
            const unsigned short * text = 0;
            unsigned long v = func_0013A5C0(p);
            if (v == 0) v = GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(0);
            if (v != 0) {
                int t = func_003EB060(v);
                if (t != -1) text = func_00271A00(&D_0051BA44, func_003EAE40(t, 1));
            }
            if (text == 0) Copy__10CGtUnicodeFPUsPCUs(out, D_004CE0B8);
            else Copy__10CGtUnicodeFPUsPCUs(out, text);
        }
        break;
    case 20:
        {
            float f = func_0013B090(p, 0);
            if (f <= 0.0f) {
                Copy__10CGtUnicodeFPUsPCUs(out, D_004CE0B8);
            } else {
            float f20;
            int id;
            if (D_004E2918 > 1) {
                f20 = f;
                id = 0x7EB;
            } else {
                f20 = D_004E0C28 * f;
                id = 0x7EC;
            }
            unsigned short * text = func_00271A00(&D_0051BA44, id);
            ustrFromFloat(out, f20, 0, 0);
            switch (D_004E2918) {
            case 5:
            case 3:
            case 4: {
                unsigned short tmp[2] = {0x20, 0};
                Append__10CGtUnicodeFPUsPCUs(out, tmp);
                break;
            }
            }
            Copy__10CGtUnicodeFPUsPCUs(out + Length__10CGtUnicodeFPCUs(out), text);
            }
        }
        break;
    case 21:
        {
            float f = func_0013B090(p, 0);
            if (f > 0.0f) {
                Copy__10CGtUnicodeFPUsPCUs(out, func_00271A00(&D_0051BA44, func_003EAAE0(FindTrack__21CB3HardCodedTrackListFUl(func_0013B050(p)))));
                break;
            }
            Copy__10CGtUnicodeFPUsPCUs(out, D_004CE0B8);
        }
        break;
    case 22:
        {
            const unsigned short * text = 0;
            if (func_0013B090(p, 0) > 0.0f) {
                unsigned long id = func_0013B010(p);
                if (id != 0) {
                    int t = func_003EB060(id);
                    if (t != -1) text = func_00271A00(&D_0051BA44, func_003EAE40(t, 1));
                }
            }
            if (text == 0) Copy__10CGtUnicodeFPUsPCUs(out, D_004CE0B8);
            else Copy__10CGtUnicodeFPUsPCUs(out, text);
        }
        break;
    case 23:
        {
            float f = func_0013AEF0(p, 0);
            if (f <= 0.0f) {
                Copy__10CGtUnicodeFPUsPCUs(out, D_004CE0B8);
            } else {
            float f20;
            int id;
            if (D_004E2918 > 1) {
                f20 = f;
                id = 0x7EB;
            } else {
                f20 = D_004E0C28 * f;
                id = 0x7EC;
            }
            unsigned short * text = func_00271A00(&D_0051BA44, id);
            ustrFromFloat(out, f20, 0, 0);
            switch (D_004E2918) {
            case 5:
            case 3:
            case 4: {
                unsigned short tmp[2] = {0x20, 0};
                Append__10CGtUnicodeFPUsPCUs(out, tmp);
                break;
            }
            }
            Copy__10CGtUnicodeFPUsPCUs(out + Length__10CGtUnicodeFPCUs(out), text);
            }
        }
        break;
    case 24:
        {
            float f = func_0013AEF0(p, 0);
            if (f > 0.0f) {
                Copy__10CGtUnicodeFPUsPCUs(out, func_00271A00(&D_0051BA44, func_003EAAE0(FindTrack__21CB3HardCodedTrackListFUl(func_0013AEB0(p)))));
                break;
            }
            Copy__10CGtUnicodeFPUsPCUs(out, D_004CE0B8);
        }
        break;
    case 25:
        {
            const unsigned short * text = 0;
            if (func_0013AEF0(p, 0) > 0.0f) {
                unsigned long id = func_0013AE70(p);
                if (id != 0) {
                    int t = func_003EB060(id);
                    if (t != -1) text = func_00271A00(&D_0051BA44, func_003EAE40(t, 1));
                }
            }
            if (text == 0) Copy__10CGtUnicodeFPUsPCUs(out, D_004CE0B8);
            else Copy__10CGtUnicodeFPUsPCUs(out, text);
        }
        break;
    case 26:
        {
            UnkStruct_3F1490_v v;
            UnkStruct_3F1490_v hi;
            hi.field_0 = 0x43;
            v.field_0 = func_0013A650(p);
            func_00322620(out, func_00271A00(&D_0051BA44, 0x3CA), &v, &hi);
        }
        break;
    case 27:
        {
            UnkStruct_3F1490_v v;
            UnkStruct_3F1490_v hi;
            hi.field_0 = 0x14;
            v.field_0 = func_0013A7F0(p);
            func_00322620(out, func_00271A00(&D_0051BA44, 0x3CA), &v, &hi);
        }
        break;
    case 28:
        {
            UnkStruct_3F1490_v v;
            UnkStruct_3F1490_v hi;
            hi.field_0 = 0xa;
            v.field_0 = func_0013A7D0(p);
            func_00322620(out, func_00271A00(&D_0051BA44, 0x3CA), &v, &hi);
        }
        break;
    case 29:
        {
            UnkStruct_3F1490_v v;
            UnkStruct_3F1490_v hi;
            hi.field_0 = 0x14;
            v.field_0 = func_0013A620(p);
            func_00322620(out, func_00271A00(&D_0051BA44, 0x3CA), &v, &hi);
        }
        break;
    case 0:
        {
            UnkStruct_3F1490_v v;
            v.field_0 = func_0013A5B0(p);
            func_001A3AA0(out, func_00271A00(&D_0051BA44, 0x3C9), &v);
        }
        break;
    }
done:
    return true;
}
