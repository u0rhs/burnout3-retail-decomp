// Hand-written; the lifter refused it (space suffix as aggregate-initialised local {0x20,0} (one .sdata template); cases 8/10 and 12/14 as static inlines for the single template and slot order).

// near13: the space suffix is an aggregate-initialised local (L" " as {0x20, 0}); retail's single 4-byte template at
// D_004E25F4 (this unit's whole .sdata) is shared by cases 8 and 10, so their common body is one static inline [G];
// cases 12 and 14 are inlines too, which puts every address-taken local in retail's slot order [G].

// Hand-written (a157): stat-string formatter (15-way jump table on the stat type).
struct UnkStruct_0043A420 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
};
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0051BA44 D_0051BA44;
extern int D_004E2918;
extern float D_004E0C28;
extern short D_004E25F4;
extern short D_004E25F6;
extern int D_004B0370[];
extern unsigned short D_004D1C58[];
extern "C" unsigned short * ustrFromInt(unsigned short *, int, int, int);
extern "C" unsigned short * ustrFromFloat(unsigned short *, float, int, int);
extern "C" unsigned short * Copy__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" unsigned short * Append__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" unsigned short * CopyN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, const unsigned short *);
extern "C" int Length__10CGtUnicodeFPCUs(const unsigned short *);
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" void func_003B8840(unsigned short *, int);
extern "C" void func_00322620(unsigned short *, const unsigned short *, const int *, const int *);
extern "C" unsigned short * func_001A3AA0(unsigned short *, const unsigned short *, const int *);
extern "C" int func_003EB060(unsigned long);
extern "C" int func_003EAE40(int, int);
extern "C" unsigned long GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(int);
extern "C" int GetTrackString__21CB3HardCodedTrackListFib(int, bool);

// [G] placeholder: cases 8 and 10 share one body (one data template for the space suffix in retail)
static inline void func_0043A420_inl1(unsigned short * s1, int v)
{
    if (v <= 0) {
        Copy__10CGtUnicodeFPUsPCUs(s1, D_004D1C58);
        return;
    }
    float f;
    int id;
    if (D_004E2918 > 1u) {
        f = (float)v;
        id = 0x7EB;
    } else {
        f = D_004E0C28 * (float)v;
        id = 0x7EC;
    }
    const unsigned short * s0 = func_00271A00(&D_0051BA44, id);
    ustrFromFloat(s1, f, 0, 0);
    switch (D_004E2918) {
    case 5:
    case 3:
    case 4: {
        unsigned short sfx[2] = {0x20, 0};
        Append__10CGtUnicodeFPUsPCUs(s1, sfx);
        break;
    }
    }
    Copy__10CGtUnicodeFPUsPCUs(s1 + Length__10CGtUnicodeFPCUs(s1), s0);
}

// [G] placeholder: case 12's body
static inline void func_0043A420_inl2(unsigned short * s1, UnkStruct_0043A420 * t0)
{
    int v;
    int k;
    k = 20;
    v = t0->field_38;
    func_00322620(s1, func_00271A00(&D_0051BA44, 0x3CA), &v, &k);
}

// [G] placeholder: case 14's body
static inline void func_0043A420_inl3(unsigned short * s1, UnkStruct_0043A420 * t0)
{
    int v = t0->field_40;
    func_001A3AA0(s1, func_00271A00(&D_0051BA44, 0x3C9), &v);
}

// 0x0043A420
extern "C" int func_0043A420(UnkStruct_0043A420 * t0, unsigned short * s1, int type, int flag)
{
    if (flag == 0) {
        const unsigned short * p = func_00271A00(&D_0051BA44, D_004B0370[type]);
        if (p != 0) {
            Copy__10CGtUnicodeFPUsPCUs(s1, p);
        } else {
            s1[0] = 0x3F;
            s1[1] = 0;
        }
        goto done;
    }
    switch (type) {
    case 0:
        ustrFromInt(s1, t0->field_4, 1, 0);
        goto done;
    case 1:
        func_003B8840(s1, t0->field_8);
        break;
    case 2:
        ustrFromInt(s1, t0->field_10, 1, 0);
        break;
    case 3:
        ustrFromInt(s1, t0->field_24, 1, 0);
        break;
    case 4:
        ustrFromInt(s1, t0->field_28, 1, 0);
        break;
    case 5: {
        int sum;
        int k;
        k = 173;
        sum = t0->field_2C + t0->field_30;
        func_00322620(s1, func_00271A00(&D_0051BA44, 0x3CA), &sum, &k);
        break;
    }
    case 6:
        ustrFromInt(s1, t0->field_34, 1, 0);
        break;
    case 7: {
        const unsigned short * s0 = 0;
        unsigned long id = GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(t0->field_C);
        if (id == 0) id = GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(0);
        if (id != 0) {
            int x = func_003EB060(id);
            if (x != -1) {
                s0 = func_00271A00(&D_0051BA44, func_003EAE40(x, 1));
            }
        }
        if (s0 == 0) {
            Copy__10CGtUnicodeFPUsPCUs(s1, D_004D1C58);
        } else {
            Copy__10CGtUnicodeFPUsPCUs(s1, s0);
        }
        break;
    }
    case 8:
        func_0043A420_inl1(s1, t0->field_14);
        break;
    case 9: {
        int a;
        if (t0->field_14 <= 0 || (a = t0->field_18) <= -1 || a >= 0x24) {
            Copy__10CGtUnicodeFPUsPCUs(s1, D_004D1C58);
            break;
        }
        CopyN__10CGtUnicodeFPUsiPCUs(s1, 0x18, func_00271A00(&D_0051BA44, GetTrackString__21CB3HardCodedTrackListFib(a, 0)));
        break;
    }
    case 10:
        func_0043A420_inl1(s1, t0->field_1C);
        break;
    case 11: {
        const unsigned short * r = 0;
        if (t0->field_1C > 0) {
            int a = t0->field_20;
            if (a > -1 && a < 0x43) {
                r = func_00271A00(&D_0051BA44, func_003EAE40(a, 1));
            }
        }
        if (r == 0) {
            Copy__10CGtUnicodeFPUsPCUs(s1, D_004D1C58);
        } else {
            Copy__10CGtUnicodeFPUsPCUs(s1, r);
        }
        break;
    }
    case 12:
        func_0043A420_inl2(s1, t0);
        break;
    case 13:
        ustrFromInt(s1, t0->field_3C, 1, 0);
        break;
    case 14:
        func_0043A420_inl3(s1, t0);
        break;
    }
done:
    return 1;
}
