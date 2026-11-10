// CB3OnlineLobbyPage::RebuildList() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (low); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (L276: lobby RebuildList; [G] inline helpers (row icon, selection clamp x2) give retail's argument-first evaluation; rotated while loop with explicit top/d locals; jtbl).

#include "b3/classes/UnkStruct_D_01E8D490.h"
#include "b3/classes/UnkStruct_D_01E8D49A.h"
#include "b3/classes/UnkStruct_D_01E8D450.h"

// [L] DNAT: CB3OnlineLobbyPage::RebuildList() (research/proto/new_names.csv, low).
struct UnkStruct_00312420_sel {
    unsigned short field_0;
    unsigned short field_2;
};
struct UnkStruct_00312420_row {
    void *field_0;   // 0x164 + row * 0x48: render callback
    void *field_4;   // size callback
    unsigned char pad_8[0x40];
};
struct UnkStruct_00312420 {
    unsigned char pad_0[0x4];
    UnkStruct_00312420_sel field_4;
    unsigned char pad_8[0x48];
    char field_50[0x114];
    UnkStruct_00312420_row field_164[6];
    unsigned char pad_314[0x1280 - 0x314];
    UnkStruct_00312420_sel field_1280;
    unsigned char pad_1284[0x1388 - 0x1284];
    int field_1388;
    int field_138C;
    int field_1390;
    unsigned char pad_1394[0x13A5 - 0x1394];
    unsigned char field_13A5;
    unsigned char field_13A6;
    unsigned char pad_13A7[3];
    unsigned char field_13AA;
    unsigned char field_13AB;
    signed char field_13AC;
};
struct UnkStruct_00312420_pl {
    char field_0[0x20];
    unsigned long field_20;
    int field_28;
    unsigned char pad_2C[4];
    unsigned char field_30;
    unsigned char field_31;
    bool field_32;
};
struct UnkStruct_00312420_info {
    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[0x30];
};
struct UnkStruct_00312420_int { int value; unsigned char pad_4[0xC]; };
struct UnkStruct_00312420_byte { unsigned char value; unsigned char pad_1[0xF]; };
struct UnkStruct_00312420_gen { unsigned char pad_0[0x10]; };

struct UnkStruct_00312420_vt {
    // vptr at +0x0: placeholder virtuals by slot offset [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC(UnkStruct_00312420_info *info);
    unsigned char pad_4[0xC];
};
extern UnkStruct_00312420_vt D_01E3CD44;
extern UnkStruct_00312420_gen D_01E32AE0;
extern UnkStruct_00312420_int D_01E32B08;
extern int D_004E2D5C;
extern UnkStruct_00312420_gen D_01E33A8C;
extern UnkStruct_00312420_gen D_01E3D390;
extern UnkStruct_00312420_byte D_01E3D4B0;
extern UnkStruct_00312420_pl D_01E3D558;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern UnkStruct_00312420_byte D_01E8D45A;
extern UnkStruct_00312420_int D_01E8D45C;
extern UnkStruct_D_01E8D490 D_01E8D490;
extern UnkStruct_D_01E8D49A D_01E8D49A;
extern char D_004C4FE8[];

extern "C" int strcasecmp(const char *, const char *);
extern "C" void *func_002366D0(void *mgr, int i);
extern "C" int func_003392C0(void *lobby, UnkStruct_00312420_pl *pl, int *out);
extern "C" int func_00339380(void *lobby, int *out);
extern "C" int func_00311EA0(UnkStruct_00312420 *self, unsigned long car, bool b);
extern "C" void SetPlayerName__18CB3OnlineLobbyPageFiPcbb(UnkStruct_00312420 *self, int i, char *name, bool a, bool b);
extern "C" void func_003137B0(UnkStruct_00312420 *self, int i, int v, bool a, bool b);
extern "C" void SetPlayerCar__18CB3OnlineLobbyPageFiUli(UnkStruct_00312420 *self, int i, unsigned long car, int c);
extern "C" void SetPlayerLatency__18CB3OnlineLobbyPageFii(UnkStruct_00312420 *self, int i, int l);
extern "C" void SetPlayerHeadsetStatus__18CB3OnlineLobbyPageFiUc(UnkStruct_00312420 *self, int i, unsigned char s);
extern "C" void IsWannaBeHisBuddy__22CGtBuddiesPS2DirtySockFPcPb(void *buddies, char *name, bool *out);
extern "C" int GetMyPlayerIndex__23CGtNetworkPlayerManagerCFv(void *mgr);
extern "C" int func_0041E900(void *);
extern "C" void RecalculateSize__17CB3TableComponentFv(void *);
extern "C" void Prepare__23CB3TableSelectComponentFiP16CGt2dObjectTablePC29CB3MenuComponentSelectionData(void *c, int n, void *table, void *sel);
extern "C" void RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(void *, void *, unsigned short *, void *, const void *);
extern "C" void GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, void *, const void *);

static inline int func_00312420_min(int a, int b) { int r; asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline unsigned int func_00312420_zx(int a) { unsigned int r; asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a)); return r; }


// [G] placeholder inline: sets a visible table row's icon callbacks (row = slot - first visible slot).
static inline void func_00312420_inl1(UnkStruct_00312420 *self, int slot, bool on)
{
    if (slot >= self->field_1390) {
        slot -= self->field_1390;
        if (slot < 6) {
            if (on) {
                self->field_164[slot].field_0 = (void *)RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                self->field_164[slot].field_4 = (void *)GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
            } else {
                self->field_164[slot].field_0 = 0;
                self->field_164[slot].field_4 = 0;
            }
        }
    }
}

// [G] placeholder inline: clamps a selection to a count.
static inline void func_00312420_inl2(UnkStruct_00312420_sel *sel, int cur, int count)
{
    if (count > cur) {
        sel->field_0 = cur;
        sel->field_2 = count;
    } else {
        sel->field_0 = count - 1;
        sel->field_2 = count;
    }
}
// [G] placeholder inline: the same clamp with the arms the other way round (retail lays the in-range arm out of line).
static inline void func_00312420_inl3(UnkStruct_00312420_sel *sel, int cur, int count)
{
    if (cur >= count) {
        sel->field_0 = count - 1;
        sel->field_2 = count;
    } else {
        sel->field_0 = cur;
        sel->field_2 = count;
    }
}

// 0x00312420
// [L] DNAT: CB3OnlineLobbyPage::RebuildList() (research/proto/new_names.csv, low): rebuilds the player rows of the lobby table.
extern "C" void func_00312420(UnkStruct_00312420 *self)
{
    bool buddy = false;
    UnkStruct_00312420_info info;
    int st;
    bool found = false;
    int i;
    int car;
    bool ok;
    UnkStruct_00312420_pl *pl;
    int n;

    ((UnkStruct_00312420_vt *)&D_01E3CD44)->vfunc_BC(&info);
    int total = D_004E2D5C + D_01E32B08.value;
    int top = self->field_1390;
    int d = total - top;
    while (top != 0 && d < 6) {
        self->field_1390--;
        top = self->field_1390;
        d = total - top;
    }
    self->field_1388 = 0;
    self->field_13A5 = 1;
    self->field_13A6 = 1;
    self->field_13AA = 0;
    self->field_13AB = 0;
    for (i = 0; i < 6; i++) {
        if (i != -1) {
            SetPlayerName__18CB3OnlineLobbyPageFiPcbb(self, i, D_004C4FE8, false, false);
            func_003137B0(self, i, -1, false, false);
            SetPlayerCar__18CB3OnlineLobbyPageFiUli(self, i, (unsigned long)-1, 0);
            SetPlayerHeadsetStatus__18CB3OnlineLobbyPageFiUc(self, i, 0);
            SetPlayerLatency__18CB3OnlineLobbyPageFii(self, i, -1);
            func_00312420_inl1(self, i, false);
        }
    }
    for (i = 0; i < D_01E32B08.value; i++) {
        ok = false;
        void *p = func_002366D0(&D_01E32AE0, i);
        if (p != 0) {
            pl = (UnkStruct_00312420_pl *)((char *)p + 0x4B8);
            if (func_003392C0(&D_01E3CD44, pl, &st) == 0)
                st = 0;
        } else {
            pl = &D_01E3D558;
            func_00339380(&D_01E3CD44, &st);
            self->field_138C = i;
        }
        if (pl->field_31 == 0 || func_00311EA0(self, pl->field_20, pl->field_32) == 0) {
            self->field_13A5 = 0;
            ok = true;
        }
        if (strcasecmp(pl->field_0, self->field_50) == 0)
            found = true;
        if (info.field_14 == 1) {
            if (pl->field_32) {
                self->field_13AA = 1;
                car = 6;
            } else {
                self->field_13AB = 1;
                car = 7;
            }
            SetPlayerName__18CB3OnlineLobbyPageFiPcbb(self, self->field_1388, pl->field_0, ok, pl->field_32);
            func_003137B0(self, self->field_1388, st, ok, pl->field_32);
        } else {
            SetPlayerName__18CB3OnlineLobbyPageFiPcbb(self, self->field_1388, pl->field_0, ok, false);
            func_003137B0(self, self->field_1388, st, ok, false);
            car = pl->field_28;
            self->field_13AB = 1;
            self->field_13AA = 1;
        }
        SetPlayerCar__18CB3OnlineLobbyPageFiUli(self, self->field_1388, pl->field_20, car);
        SetPlayerLatency__18CB3OnlineLobbyPageFii(self, self->field_1388, -1);
        SetPlayerHeadsetStatus__18CB3OnlineLobbyPageFiUc(self, self->field_1388, pl->field_30);
        if (D_01E3D4B0.value != 0)
            IsWannaBeHisBuddy__22CGtBuddiesPS2DirtySockFPcPb(&D_01E3D390, pl->field_0, &buddy);
        func_00312420_inl1(self, self->field_1388, buddy);
        self->field_1388++;
    }
    n = func_00312420_zx(func_00312420_min(self->field_1388 - self->field_1390, 6));
    if (self->field_13AB == 0 || self->field_13AA == 0)
        self->field_13A5 = 0;
    if (!found)
        self->field_50[0] = 0;
    if (GetMyPlayerIndex__23CGtNetworkPlayerManagerCFv(&D_01E32AE0) > -1) {
        switch (func_0041E900(&D_01E33A8C)) {
        default:
        case 0:
        case 1:
        case 3:
            SetPlayerHeadsetStatus__18CB3OnlineLobbyPageFiUc(self, self->field_138C, 0);
            break;
        case 2:
            SetPlayerHeadsetStatus__18CB3OnlineLobbyPageFiUc(self, self->field_138C, 1);
            break;
        case 4:
            SetPlayerHeadsetStatus__18CB3OnlineLobbyPageFiUc(self, self->field_138C, 4);
            break;
        case 5:
            SetPlayerHeadsetStatus__18CB3OnlineLobbyPageFiUc(self, self->field_138C, 2);
            break;
        }
    } else {
        SetPlayerHeadsetStatus__18CB3OnlineLobbyPageFiUc(self, self->field_138C, 0);
    }
    if (self->field_13AC == 1 && D_01E8D45A.value != 0)
        RecalculateSize__17CB3TableComponentFv(&D_01E8D450);
    if (self->field_1388 == 0) {
        self->field_1280.field_0 = 0;
        self->field_1280.field_2 = 1;
    } else {
        func_00312420_inl2(&self->field_1280, self->field_1280.field_0, self->field_1388);
    }
    if (self->field_1388 == 0 && self->field_13AC == 1) {
        if (D_01E8D49A.field_0 != 0)
            ((UnkStruct_D_01E8D490 *)&D_01E8D490)->vfunc_C();
        self->field_4.field_0 = 0;
        self->field_4.field_2 = 1;
    } else if (self->field_13AC == 1) {
        func_00312420_inl2(&self->field_4, self->field_4.field_0, n);
        Prepare__23CB3TableSelectComponentFiP16CGt2dObjectTablePC29CB3MenuComponentSelectionData(&D_01E8D490, 1, (void *)(D_01E8D45C.value), &self->field_4);
        int cur = self->field_1390 + self->field_4.field_0;
        func_00312420_inl3(&self->field_1280, cur, self->field_1388);
    }
}
