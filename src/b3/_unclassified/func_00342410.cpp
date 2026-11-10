// Hand-written; the lifter refused it (bool params, unsigned field_44 index, byte-offset row view for variable entries, per-arm tail stores, str/s2 declarations at the top).

#include "b3/classes/UnkStruct_D_01E91C3E.h"
struct UnkStruct_00342410_q { unsigned char pad_0[0x10]; };
struct UnkStruct_00342410_iv { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00342410_bv { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_00342410_ent { int field_0; unsigned char field_4; unsigned char field_5; unsigned char pad_6[2]; };
struct UnkStruct_00342410_obj { unsigned char pad_0[0x1B4]; void *field_1B4; };
class UnkStruct_00342410_menu {
public:
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34();
    virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44();
    virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64();
    virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74();
    virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84();
    virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94();
    virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4();
    virtual void vfunc_A8(); virtual void vfunc_AC(); virtual void vfunc_B0(); virtual void vfunc_B4();
    virtual void vfunc_B8(); virtual void vfunc_BC(); virtual void vfunc_C0(); virtual void vfunc_C4();
    virtual void vfunc_C8(); virtual void vfunc_CC(); virtual void vfunc_D0(); virtual void vfunc_D4();
    virtual void vfunc_D8(); virtual int vfunc_DC();
};
struct UnkStruct_00342410_game { unsigned char pad_0[0x1B4]; UnkStruct_00342410_menu *field_1B4; };
struct UnkStruct_00342410_D_0051BA88 { UnkStruct_00342410_game *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00342410_D_0064D3B0 { unsigned char pad_0[0x10C8]; int field_10C8; };
struct UnkStruct_00342410 {
    unsigned char pad_0[4];
    unsigned short field_4;
    unsigned short field_6;
    UnkStruct_00342410_ent field_8[7];
    int field_40;
    int field_44[6];
    unsigned char pad_5C[4];
    unsigned char field_60;
    unsigned char field_61;
    unsigned char field_62;
};
extern UnkStruct_00342410_q D_0051BA44, D_004EE040, D_01E90438, D_01E89518, D_01E89544, D_01E89800, D_01E894FC, D_01E88A80;
extern UnkStruct_00342410_iv D_0051B938, D_0051BA94;
extern UnkStruct_00342410_bv D_0051BA39;
extern UnkStruct_00342410_D_0051BA88 D_0051BA88;
extern UnkStruct_00342410_D_0064D3B0 D_0064D3B0;
extern UnkStruct_D_01E91C3E D_01E91C3E;
extern "C" {
void Prepare__15CB3MenuPageBaseFb(void *, bool);
int func_00271A00(void *, int);
int func_00131D90(void *);
int func_00131CE0(void *);
int func_00131CA0(void *);
int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
void *func_001A3AA0(void *, void *, int *);
void Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(void *, void *, int);
void Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, const void *, void *, float);
bool func_0031ECD0(void *, unsigned long, int);
void Prepare__21CB3PromptBarComponentFv(void *);
int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
}
static inline int func_00342410_inl2(int a, int b) { int r; asm("pmaxw %0,%1,%2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline unsigned int func_00342410_inl3(int a) { unsigned int r; asm("pextlw %0,$0,%1" : "=r"(r) : "r"(a)); return r; }
// [G] an entry reached through a byte-offset view of self (retail's idx-first addu)
static inline UnkStruct_00342410_ent *func_00342410_inl1(UnkStruct_00342410 *self, int i)
{
    return (UnkStruct_00342410_ent *)((unsigned)(i << 3) + (unsigned)self + 8);
}
// 0x00342410
extern "C" int func_00342410(UnkStruct_00342410 *self, bool p1, bool p2)
{
    int str;
    int s3 = 0;
    int n;
    int r;
    UnkStruct_00342410_ent *e;
    int off;
    unsigned int s2;
    Prepare__15CB3MenuPageBaseFb(self, p2);
    self->field_60 = p1;
    self->field_61 = 0;
    self->field_62 = 0;
    if (p2) {
        D_01E91C3E.field_0 = 1;
    } else {
        s3 = self->field_4;
    }
    if (self->field_60 != 0) {
        off = 0x2DA04;
        r = func_00271A00(&D_0051BA44, 0x12F);
        e = &self->field_8[0];
        e->field_0 = r;
        e->field_4 = 0;
        e->field_5 = 0;
        r = func_00271A00(&D_0051BA44, 0x130);
        e = &self->field_8[1];
        e->field_0 = r;
        e->field_4 = 0;
        e->field_5 = 0;
        r = func_00271A00(&D_0051BA44, 0x198);
        e = &self->field_8[2];
        e->field_0 = r;
        e->field_4 = 0;
        e->field_5 = 0;
        r = func_00271A00(&D_0051BA44, 0xC7);
        e = &self->field_8[3];
        e->field_0 = r;
        e->field_4 = 0;
        e->field_5 = 0;
        r = func_00271A00(&D_0051BA44, 0x308);
        e = &self->field_8[4];
        e->field_0 = r;
        e->field_4 = 0;
        e->field_5 = 0;
        self->field_4 = s3;
        self->field_6 = 5;
    } else {
        off = 0x2DA04;
        n = 0;
        r = func_00271A00(&D_0051BA44, 0x12F);
        e = &self->field_8[0];
        e->field_0 = r;
        e->field_4 = 0;
        e->field_5 = 0;
        n++;
        self->field_44[0] = 0;
        if (func_00131D90(&D_004EE040) == 0) {
            r = func_00271A00(&D_0051BA44, 0x132);
            e = func_00342410_inl1(self, n);
            e->field_0 = r;
            e->field_4 = 0;
            e->field_5 = 0;
            self->field_44[(unsigned)(n)] = 1;
            n++;
            if (func_00131CE0(&D_004EE040) != 0 && D_0051B938.field_0 > 0) {
                r = func_00271A00(&D_0051BA44, 0x9DD);
                e = func_00342410_inl1(self, n);
                e->field_0 = r;
                e->field_4 = 0;
                e->field_5 = 0;
                self->field_44[(unsigned)(n)] = 2;
                n++;
            }
        }
        r = func_00271A00(&D_0051BA44, 0x198);
        e = func_00342410_inl1(self, n);
        e->field_0 = r;
        e->field_4 = 0;
        e->field_5 = 0;
        self->field_44[(unsigned)(n)] = 3;
        r = func_00271A00(&D_0051BA44, 0xC7);
        e = func_00342410_inl1(self, n + 1);
        e->field_0 = r;
        e->field_4 = 0;
        e->field_5 = 0;
        self->field_44[(unsigned)(n + 1)] = 4;
        if (D_0051BA88.field_0 != 0 && D_0051BA88.field_0->field_1B4->vfunc_DC() != 0) {
            self->field_61 = 1;
            UnkStruct_00342410_D_0064D3B0 *c = &D_0064D3B0;
            bool b = c != 0 && c->field_10C8 == 0;
            r = func_00271A00(&D_0051BA44, 0x131);
            e = func_00342410_inl1(self, n + 2);
            e->field_0 = r;
            e->field_4 = !b;
            e->field_5 = 0;
            self->field_44[(unsigned)(n + 2)] = 5;
            n += 3;
        } else {
            if (func_00131CE0(&D_004EE040) != 0) {
                r = func_00271A00(&D_0051BA44, 0x135);
                e = func_00342410_inl1(self, n + 2);
                e->field_0 = r;
                e->field_4 = 0;
                e->field_5 = 0;
            } else {
                r = func_00271A00(&D_0051BA44, 0x134);
                e = func_00342410_inl1(self, n + 2);
                e->field_0 = r;
                e->field_4 = 0;
                e->field_5 = 0;
            }
            self->field_44[(unsigned)(n + 2)] = 5;
            n += 3;
        }
        self->field_4 = s3;
        self->field_6 = n;
    }
    char *obj = (char *)&D_004EE040 + off;
    str = func_00271A00(obj, 0x12E);
    if (self->field_60 == 0 && func_00131CA0(&D_004EE040) != 0) {
        str = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x20);
        s2 = func_00342410_inl3(func_00342410_inl2(0, D_0051BA94.field_0));
        if (func_00131D90(&D_004EE040) != 0) s2 += D_0051BA39.field_0 * 2;
        int tmp = s2 + 1;
        func_001A3AA0((void *)(str), (void *)(func_00271A00(obj, 0xC11)), &tmp);
    }
    Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(&D_01E89518, (void *)(str), 5);
    Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, (char *)self + 4, (char *)self + 8, 640.0f);
    func_0031ECD0(&D_01E89800, 0x184, 3);
    Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 7);
    self->field_40 = 6;
    return 1;
}
