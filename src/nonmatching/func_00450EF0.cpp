// NONMATCHING: func_00450EF0 -- retail 495 / ours 485 instructions, 189 in changed runs
// a179: logic complete from m2c (stat-column text selector: kind switch 1/2/4/8/0x10/0x20/0x40/0x80/0x100/0x200, local/net/rec6 record pointers, nested switch on func_003CCFB0 result 4/5/6 -> 0x9E0/0x9DE/0x9DF), 485 vs 495 instrs, 189 changed. Not matched: s-register assignment (retail slot=s0,res=s1,net=s2,loc=s3,player=s4,kind=s5,rec6=s6,online=s7,id=fp; ours differs, declaration-order permutations had no effect), frame 0xA0 vs 0x90 (retail saves fp, ours one fewer register -> something extra is live: probably the id loop var and rec6/net/loc all live at once), and 10 fewer instructions (retail does not merge the repeated 'store kind to slot; return string 0x9E1' tails and keeps per-case null tests in separate blocks). Needs a different case-body shape (probably an inline helper per column kind).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_00450EF0_vo {
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
    virtual int vfunc_9C();
    unsigned char pad_4[0x6E];
    unsigned char field_72;
    unsigned char field_73;
};
struct UnkStruct_00450EF0_pad { unsigned char pad_0[0x1B4]; UnkStruct_00450EF0_vo * field_1B4; };
struct UnkStruct_D_0051BA88 { UnkStruct_00450EF0_pad * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00450EF0_loc {
    int field_0;
    unsigned char pad_4[8];
    float field_C;
    unsigned char pad_10[0x3C];
    int field_4C;
    unsigned char pad_50[0x18];
    int field_68;
    unsigned char pad_6C[0x18];
    int field_84;
    int field_88;
    unsigned char pad_8C[4];
    int field_90;
    unsigned char field_94;
    unsigned char pad_95[3];
    int field_98;
};
struct UnkStruct_00450EF0_net {
    unsigned char pad_0[0x1C];
    float field_1C;
    unsigned char pad_20[4];
    int field_24;
    unsigned char pad_28[4];
    int field_2C;
    int field_30;
    unsigned char pad_34[4];
    int field_38;
    unsigned char field_3C;
    unsigned char pad_3D[3];
    int field_40;
};
struct UnkStruct_00450EF0_rec { unsigned char pad_0[0x3C]; unsigned char field_3C; unsigned char pad_3D[3]; int field_40; };
struct UnkStruct_00450EF0 {
    unsigned char pad_0[0x1D8];
    short field_1D8[1][2];
};
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_byte { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_Pad16 D_01E32AE0;
extern UnkStruct_D_int D_01E32B08;
extern UnkStruct_Pad16 D_01E90438;
extern UnkStruct_Pad16 D_0051BA44;
extern UnkStruct_Pad16 D_00522660;
extern UnkStruct_Pad16 D_0064CE40;
extern UnkStruct_D_byte D_01E65499;
extern UnkStruct_D_byte D_01ECDAC1;
extern UnkStruct_D_byte D_01ECDAC9;
extern UnkStruct_D_byte D_0064EB04;
extern UnkStruct_D_int D_0051B978;
extern UnkStruct_D_int D_0051B97C;
extern UnkStruct_D_int D_006512D8;
extern "C" void * func_002366D0(void *, int);
extern "C" int func_0022FBB0(void *);
extern "C" UnkStruct_00450EF0_net * GetPlayerRecordByID__17CB3NetworkManagerFi(void *, int);
extern "C" int func_0026C8C0(void *);
extern "C" void * AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void ustrFromInt(void *, int, int, int);
extern "C" void PrintInt__10CGtUnicodeFPUsii(void *, int, int, int);
extern "C" void * func_00271A00(void *, int);
extern "C" void * func_003B8550(void *, float);
extern "C" void * func_003B84F0(void *, int);
extern "C" int func_003CCFB0(void *, int, int);

// 0x00450EF0
extern "C" void * func_00450EF0(UnkStruct_00450EF0 *self, int col, int kind, int player)
{
    UnkStruct_00450EF0_rec *s6 = 0;
    void *res = 0;
    unsigned char online = D_01E65499.field_0;
    short *slot = &self->field_1D8[col][player];
    UnkStruct_00450EF0_net *s2;
    UnkStruct_00450EF0_loc *s3;
    *slot = 0x400;
    if (online == 0) {
        s2 = 0;
        s3 = (UnkStruct_00450EF0_loc *)((char *)&D_00522660 + player * 0x27D0 + 0x12C410);
    } else {
        UnkStruct_00450EF0_vo *vo = D_0051BA88.field_0->field_1B4;
        if (vo->vfunc_9C() == 4 && (func_0026C8C0(&D_01E32AE0) == 0 || D_0051BA88.field_0->field_1B4->field_73 == 0)) {
            s2 = 0;
            s6 = 0;
            s3 = 0;
        } else if (player == 1) {
            int id = -1;
            int i;
            for (i = 0; i < D_01E32B08.field_0; i++) {
                void *p = func_002366D0(&D_01E32AE0, i);
                if (p != 0) id = func_0022FBB0(p);
            }
            s3 = 0;
            s2 = GetPlayerRecordByID__17CB3NetworkManagerFi(&D_01E32AE0, id);
        } else {
            s2 = 0;
            int id = -1;
            s3 = (UnkStruct_00450EF0_loc *)((char *)&D_00522660 + player * 0x27D0 + 0x12C410);
            if (D_01E32B08.field_0 == 2) {
                int i;
                for (i = 0; i < D_01E32B08.field_0; i++) {
                    void *p = func_002366D0(&D_01E32AE0, i);
                    if (p != 0) id = func_0022FBB0(p);
                }
                s6 = (UnkStruct_00450EF0_rec *)GetPlayerRecordByID__17CB3NetworkManagerFi(&D_01E32AE0, id);
            }
        }
    }
    switch (kind) {
    case 1: {
        int v = 0;
        res = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 16);
        if (D_01ECDAC1.field_0 != 0) v = D_0051B978.field_0;
        else if (s3 != 0) v = s3->field_4C;
        else if (s2 != 0) v = s2->field_40;
        ustrFromInt(res, v, 1, 0);
        return res;
    }
    case 2:
        return func_00271A00(&D_0051BA44, s3->field_0 + 0x25F);
    case 4:
        if (s3 != 0) return func_003B8550(&D_01E90438, s3->field_C);
        if (s2 != 0) return func_003B8550(&D_01E90438, s2->field_1C);
        *slot = kind;
        return func_00271A00(&D_0051BA44, 0x9E1);
    case 8: {
        int v = 0;
        res = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 16);
        if (D_01ECDAC1.field_0 != 0) v = D_0051B97C.field_0;
        else if (s3 != 0) v = s3->field_68;
        else if (s2 != 0) v = s2->field_24;
        PrintInt__10CGtUnicodeFPUsii(res, v, 1, 0);
        return res;
    }
    case 0x10:
        if (s3 != 0) return func_003B84F0(&D_01E90438, s3->field_84);
        if (s2 != 0) return func_003B84F0(&D_01E90438, s2->field_2C);
        *slot = kind;
        return func_00271A00(&D_0051BA44, 0x9E1);
    case 0x20:
        if (s3 != 0) return func_003B84F0(&D_01E90438, s3->field_90);
        if (s2 != 0) return func_003B84F0(&D_01E90438, s2->field_38);
        *slot = kind;
        return func_00271A00(&D_0051BA44, 0x9E1);
    case 0x40: {
        int a2 = 0;
        if (D_01ECDAC9.field_0 != 0) {
            if (online != 0) {
                if (player == 0) {
                    if (s6 != 0) a2 = s6->field_3C;
                    else a2 = 0xFF;
                } else {
                    a2 = D_0064EB04.field_0;
                }
            } else {
                int a0 = player == 0 ? 1 : 0;
                a2 = *((unsigned char *)&D_00522660 + a0 * 0x27D0 + 0x12C4A4);
            }
        }
        if ((a2 & 0xFF) != 0xFF) {
            int r;
            if (online != 0) {
                if (player == 0) {
                    if (s3 == 0) {
                        *slot = kind;
                        return func_00271A00(&D_0051BA44, 0x9E1);
                    }
                    r = func_003CCFB0(&D_0064CE40, s3->field_94, a2);
                } else {
                    if (s2 == 0) {
                        *slot = kind;
                        return func_00271A00(&D_0051BA44, 0x9E1);
                    }
                    r = func_003CCFB0(&D_0064CE40, s2->field_3C, a2);
                }
            } else {
                r = func_003CCFB0(&D_0064CE40, s3->field_94, a2);
            }
            int id;
            switch (r) {
            default:
                id = 0x9E1;
                break;
            case 4:
                id = 0x9E0;
                break;
            case 6:
                id = 0x9DF;
                break;
            case 5:
                id = 0x9DE;
                break;
            }
            return func_00271A00(&D_0051BA44, id);
        }
        *slot = kind;
        return func_00271A00(&D_0051BA44, 0x9E1);
    }
    case 0x80:
        if (s3 != 0) return func_003B84F0(&D_01E90438, s3->field_98);
        if (s2 != 0) return func_003B84F0(&D_01E90438, s2->field_40);
        *slot = kind;
        return func_00271A00(&D_0051BA44, 0x9E1);
    case 0x100:
        if (player == 0) {
            if (online != 0 && s6 == 0) {
                *slot = kind;
                return func_00271A00(&D_0051BA44, 0x9E1);
            }
            if (online != 0 && D_0051BA88.field_0->field_1B4->field_72 == 0) {
                *slot = kind;
                return func_00271A00(&D_0051BA44, 0x9E1);
            }
            int v;
            if (online != 0) v = s6->field_40;
            else v = D_006512D8.field_0;
            return func_003B84F0(&D_01E90438, s3->field_98 + v);
        }
        return 0;
    case 0x200:
        res = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 16);
        if (s3 != 0) {
            PrintInt__10CGtUnicodeFPUsii(res, s3->field_88, 1, 0);
            return res;
        }
        if (s2 != 0) {
            PrintInt__10CGtUnicodeFPUsii(res, s2->field_30, 1, 0);
            return res;
        }
        *slot = kind;
        return func_00271A00(&D_0051BA44, 0x9E1);
    }
    return res;
}
