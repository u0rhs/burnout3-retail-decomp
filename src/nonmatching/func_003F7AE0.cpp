// NONMATCHING: func_003F7AE0 -- retail 344 / ours 342 instructions, 32 in changed runs
// 342/344, 32 changed: logic/layout/frame/slots exact; remaining = i/menu s1/s2 swap (retail menu s1,i s2; no decl-order/permutation/const/scoped fix works, 120 perms tried) and idx-first addu in flag branch + one nop; 5 vfunc_EC out-slots follow source order (flag site, flag loop2, B-site(mode0), A-site(mode1), loop2); loop2 written twice, not an inline; no-pad entry struct (pad_2A removed to avoid padding copy)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003F7AE0 -- race-results entry collection (sibling of func_003F8040 AddRaceTimes) [G]
#include "b3/_unclassified/B3NetworkManager.h"

struct UnkStruct_3F7AE0_s3 {
    unsigned char pad_0[0x8];
    int field_8;
    float field_C;
    unsigned char pad_10[0x2C];
    float field_3C;
};
struct UnkStruct_3F7AE0_p {
    unsigned char pad_0[0x16C0];
    UnkStruct_3F7AE0_s3 field_16C0;
    unsigned char pad_1700[0x1914 - 0x16C0 - sizeof(UnkStruct_3F7AE0_s3)];
    int field_1914;
};
struct UnkStruct_3F7AE0_pl {
    unsigned char pad_0[0x16C0];
    UnkStruct_3F7AE0_s3 field_16C0;
    unsigned char pad_1700[0x19AC - 0x16C0 - sizeof(UnkStruct_3F7AE0_s3)];
    signed char field_19AC;
};
struct UnkStruct_3F7AE0_e {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
    int field_4;
    float field_8;
    float field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    unsigned char field_28;
    unsigned char field_29;
    int field_2C;
    int field_30;
    const void * field_34;
};
struct UnkStruct_3F7AE0_rec {
    int field_0;
    unsigned short field_4[1];
    unsigned char pad_6[0xE];
    UnkStruct_3F7AE0_e field_14;
    unsigned char field_4C;
    unsigned char field_4D;
};
struct UnkStruct_3F7AE0_rec2 {
    unsigned char pad_0[0x4C];
    unsigned char field_4C;
    unsigned char field_4D;
};
struct UnkStruct_3F7AE0_page {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10(UnkStruct_3F7AE0_e *);
};
struct UnkStruct_3F7AE0_menu {
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
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual void vfunc_D8();
    virtual void vfunc_DC();
    virtual void vfunc_E0();
    virtual void vfunc_E4();
    virtual void vfunc_E8();
    virtual void vfunc_EC(int, UnkStruct_3F7AE0_s3 *, int *);
    virtual int vfunc_F0();
};
struct UnkStruct_3F7AE0_self {
    unsigned char pad_0[0x18];
    unsigned char field_18[8];
};
struct UnkStruct_3F7AE0_10 { short field_0[5]; };
struct UnkStruct_3F7AE0_game { unsigned char pad_0[0x1B4]; UnkStruct_3F7AE0_menu * field_1B4; };
struct UnkStruct_D_0051BA88_x { UnkStruct_3F7AE0_game * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_3F7AE0_i { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051BA88_x D_0051BA88;
extern UnkStruct_3F7AE0_i D_0064D37C;
extern UnkStruct_3F7AE0_i D_01E32B08;
extern UnkStruct_3F7AE0_i D_00522660;
extern UnkStruct_3F7AE0_pl D_0064D3B0;
extern CB3NetworkManager D_01E32AE0;
extern UnkStruct_3F7AE0_10 D_004D1CD0[];
extern UnkStruct_3F7AE0_i D_01E3D558;
extern "C" void func_00272DD0(UnkStruct_3F7AE0_e *, UnkStruct_3F7AE0_s3 *);
extern "C" void * func_002366D0(CB3NetworkManager *, int);
extern "C" int func_0022FBB0(void *);
extern "C" int GetMyPlayerID__23CGtNetworkPlayerManagerCFv(void *);

// 0x003F7AE0
extern "C" void func_003F7AE0(UnkStruct_3F7AE0_self * self, UnkStruct_3F7AE0_page * page, int flag)
{
    UnkStruct_3F7AE0_s3 * s3;
    UnkStruct_3F7AE0_menu * menu = D_0051BA88.field_0->field_1B4;
    int i;
    int n;
    UnkStruct_3F7AE0_e e;
    if (flag != 0) {
        UnkStruct_3F7AE0_pl * const pl = &D_0064D3B0;
        s3 = &pl->field_16C0;
        int a1 = s3->field_8 != 0;
        unsigned char * s0 = &self->field_18[pl->field_19AC];
        if (a1 != 0 && *s0 == 0) {
            int out;
            func_00272DD0(&e, s3);
            menu->vfunc_EC(GetMyPlayerID__23CGtNetworkPlayerManagerCFv(&D_01E32AE0), s3, &out);
            e.field_34 = &D_01E3D558;
            e.field_2C = out;
            e.field_30 = menu->vfunc_F0();
            page->vfunc_10(&e);
            *s0 = 1;
        }
        for (i = 0; i < D_01E32B08.field_0; i++) {
            void * pl = func_002366D0(&D_01E32AE0, i);
            if (pl != 0) {
                UnkStruct_3F7AE0_rec * rec = (UnkStruct_3F7AE0_rec *)D_01E32AE0.GetPlayerRecordByID(func_0022FBB0(pl));
                if (rec != 0 && rec->field_4C != 0 && rec->field_4D == 0) {
                    e = rec->field_14;
                    int out;
                    e.field_34 = &rec->field_4;
                    menu->vfunc_EC(rec->field_0, s3, &out);
                    page->vfunc_10(&e);
                    rec->field_4D = 1;
                }
            }
        }

    } else {
        n = D_0064D37C.field_0;
        for (i = 0; i < n; i++) {
            UnkStruct_3F7AE0_p * p = *(UnkStruct_3F7AE0_p **)((char *)&D_00522660 + i * 4 + 0x12AD28);
            int a1 = p->field_16C0.field_8 != 0;
            s3 = &p->field_16C0;
            int mode = p->field_1914;
            if (mode == 0) {
                unsigned char * s0 = &self->field_18[i];
                if (a1 != 0 && *s0 == 0) {
                    int out;
                    UnkStruct_3F7AE0_i * const pg = &D_01E3D558;
                    if (s3->field_3C > 10000.0f) s3->field_3C = s3->field_C;
                    func_00272DD0(&e, s3);
                    menu->vfunc_EC(GetMyPlayerID__23CGtNetworkPlayerManagerCFv(&D_01E32AE0), s3, &out);
                    e.field_34 = pg;
                    e.field_2C = out;
                    e.field_30 = menu->vfunc_F0();
                    page->vfunc_10(&e);
                    *s0 = 1;
                }
            }
            else if (mode == 1 && a1 != 0) {
                unsigned char * s0 = &self->field_18[i];
                if (*s0 == 0) {
                    int out;
                    func_00272DD0(&e, s3);
                    menu->vfunc_EC(0, s3, &out);
                    e.field_34 = &D_004D1CD0[i - 1];
                    e.field_2C = out;
                    e.field_30 = menu->vfunc_F0();
                    page->vfunc_10(&e);
                    *s0 = 1;
                }
            }
        }
        for (i = 0; i < D_01E32B08.field_0; i++) {
            void * pl = func_002366D0(&D_01E32AE0, i);
            if (pl != 0) {
                UnkStruct_3F7AE0_rec * rec = (UnkStruct_3F7AE0_rec *)D_01E32AE0.GetPlayerRecordByID(func_0022FBB0(pl));
                if (rec != 0 && rec->field_4C != 0 && rec->field_4D == 0) {
                    e = rec->field_14;
                    int out;
                    e.field_34 = &rec->field_4;
                    menu->vfunc_EC(rec->field_0, s3, &out);
                    page->vfunc_10(&e);
                    rec->field_4D = 1;
                }
            }
        }

    }
}
