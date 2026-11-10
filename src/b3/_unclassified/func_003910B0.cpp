// func_003910B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (near23: UnkEnum_ idx diamond, if (a!=4 && b!=5) goto done, block-2 decl order rec/other/me2).

// Hand-finished by near23 from the archive: opponent index as an UnkEnum_ diamond (a66), final mode test as
// if (a != 4 && b != 5) goto done; (bne to the exit), block-2 locals declared rec (assigned late), other, me2 (s-registers).

// func_003910B0 -- hand-written from the retail structure (lifted draft failed to compile: GetPlayerRecordByID
// declared four times with different return types, "illegal function overloading").
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths).

class CGtNetworkPlayerManager {
public:
    int GetMyPlayerID() const;

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003910B0_4 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
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
    virtual void vfunc_EC(int, void *, int *);
    virtual int vfunc_F0();
    virtual void vfunc_F4(int);
};

struct UnkStruct_003910B0_3 {
    unsigned long field_0;
    unsigned char pad_8[0x1AC];
    UnkStruct_003910B0_4 * field_1B4;
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_003910B0_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003910B0_1 {
    unsigned char pad_0[0x2C];
    int field_2C;
    int field_30;
    unsigned char pad_34[0x8];
};

struct UnkStruct_D_01E32B08 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064ED5C {
    signed char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0065F3B8 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003910B0_m {
    unsigned char pad_0[0x84];
    int field_84;
    unsigned char pad_88[0x4];
    int field_8C;
    int field_90;
    unsigned char field_94;
    unsigned char pad_95[0x3];
    int field_98;
};

struct UnkStruct_003910B0_12 {
    unsigned char pad_0[0x16C0];
    UnkStruct_003910B0_m field_16C0;
};

struct UnkStruct_003910B0_r {
    unsigned char pad_0[0x14];
    unsigned char field_14[0x18];
    int field_2C;
    unsigned char pad_30[0x4];
    int field_34;
    int field_38;
    unsigned char field_3C;
    unsigned char pad_3D[0x3];
    int field_40;
    int field_44;
};

struct UnkStruct_D_0064EB08 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_01E32B08 D_01E32B08;
extern UnkStruct_D_0064ED5C D_0064ED5C;
extern UnkStruct_003910B0_12 * D_0064D388[];  // [G] element count unknown
extern UnkStruct_D_0065F3B8 D_0065F3B8;
extern UnkStruct_003910B0_m D_0064EA70;
extern UnkStruct_D_0064EB08 D_0064EB08;
extern CGtNetworkPlayerManager D_01E32AE0;
extern char D_0064D3B0[];
extern char D_0064CE40[];
extern char D_01ECD9F0[];

extern "C" UnkStruct_003910B0_r * GetPlayerRecordByID__17CB3NetworkManagerFi(void *, int);  // CB3NetworkManager::GetPlayerRecordByID(int)
extern "C" void func_0026FAA0(void *, int);
extern "C" void func_00272DD0(void *, void *);
extern "C" char * func_002366D0(void *, int);
extern "C" int func_00272C90(void *, UnkStruct_003910B0_1 *);
extern "C" int func_00155F00(void *, int, void *);
extern "C" int func_0022FBB0(void *);
extern "C" int func_003CCFB0(void *, unsigned char, unsigned char);
extern "C" int func_003CCEE0(void *, int, int, int);
extern "C" void func_0042F870(void *, int, unsigned long);

enum UnkEnum_003910B0 { UnkEnum_003910B0_0, UnkEnum_003910B0_1 };  // [G] placeholder (N148): keeps retail's bnez/b/li diamond
// 0x003910B0
extern "C" int func_003910B0()
{
    int tmp;
    UnkStruct_003910B0_1 local;
    UnkStruct_003910B0_m * const me = &D_0064EA70;
    func_0026FAA0(&D_01E32AE0, 0);
    int n = D_01E32B08.field_0;
    UnkStruct_003910B0_4 * mode = D_0051BA88.field_0->field_1B4;
    func_00272DD0(&local, me);
    mode->vfunc_EC(D_01E32AE0.GetMyPlayerID(), me, &tmp);
    local.field_2C = tmp;
    local.field_30 = mode->vfunc_F0();
    for (int i = 0; i < n; i++) {
        char * p = func_002366D0(&D_01E32AE0, i);
        if (p != 0) {
            func_00272C90(p + 0xB64, &local);
        }
    }
    if ((func_00155F00(&D_0064EA70, 1, D_0064D3B0) & 0xFF) != 0) {
        UnkEnum_003910B0 idx;
        if (D_0064ED5C.field_0 == 0) {
            idx = UnkEnum_003910B0_1;
        } else {
            idx = UnkEnum_003910B0_0;
        }
        UnkStruct_003910B0_r * rec;
        UnkStruct_003910B0_m * other = &D_0064D388[idx]->field_16C0;
        UnkStruct_003910B0_m * const me2 = &D_0064EA70;
        rec = GetPlayerRecordByID__17CB3NetworkManagerFi(&D_01E32AE0, func_0022FBB0((void *)(D_0065F3B8.field_0)));
        int o = other->field_98;
        rec->field_44 -= me2->field_98;
        rec->field_44 += o;
        int m = me2->field_98;
        D_0051BA88.field_0->field_1B4->vfunc_F4(-other->field_98);
        D_0051BA88.field_0->field_1B4->vfunc_F4(m);
        func_00272DD0(rec->field_14, other);
    }
    if (D_0051BA88.field_0->field_1B4->vfunc_9C() == 5) {
        int id = func_0022FBB0((void *)(D_0065F3B8.field_0));
        UnkStruct_003910B0_m * const me3 = &D_0064EA70;
        UnkStruct_003910B0_r * rec = GetPlayerRecordByID__17CB3NetworkManagerFi(&D_01E32AE0, id);
        if (rec != 0) {
            switch (func_003CCFB0(D_0064CE40, me3->field_94, rec->field_3C)) {
            case 4:
                me3->field_8C = -2;
                rec->field_34 = -2;
                break;
            case 5:
                me3->field_8C = 2;
                rec->field_34 = 2;
                break;
            case 6:
                me3->field_8C = 4;
                rec->field_34 = 4;
                break;
            default:
                me3->field_8C = 1;
                rec->field_34 = 1;
                break;
            }
            me3->field_98 = func_003CCEE0(D_0064CE40, me3->field_84, me3->field_90, me3->field_8C);
            rec->field_40 = func_003CCEE0(D_0064CE40, rec->field_2C, rec->field_38, rec->field_34);
            D_0051BA88.field_0->field_1B4->vfunc_F4(rec->field_40);
            D_0051BA88.field_0->field_1B4->vfunc_F4(me3->field_98);
        }
    }
    if (D_0051BA88.field_0->field_1B4->vfunc_9C() != 4 && D_0051BA88.field_0->field_1B4->vfunc_9C() != 5) goto done;
    {
        UnkStruct_003910B0_r * rec = GetPlayerRecordByID__17CB3NetworkManagerFi(&D_01E32AE0, func_0022FBB0((void *)(D_0065F3B8.field_0)));
        if (rec != 0) {
            unsigned long t = D_0051BA88.field_0->field_0;
            int v;
            if (D_0051BA88.field_0->field_1B4->vfunc_9C() == 5) {
                v = rec->field_40 + D_0064EB08.field_0;
            } else {
                v = D_0064EB08.field_0;
            }
            func_0042F870(D_01ECD9F0, v, t);
        }
    }
done:
    return 1;
}
