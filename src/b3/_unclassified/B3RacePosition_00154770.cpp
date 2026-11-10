// CB3RacePosition::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RacePosition.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (near28: i4 declared before m2; count loop: outer as goto entry-jump loop, tb = D_0064D388 pointer local per pass, (unsigned) i1 index, i2/m1 declared before i1).

class CB3Score;

class CB3RacePosition;
class CB3Score;
struct UnkStruct_00154770_10;
struct UnkStruct_00154770_17;
struct UnkStruct_00154770_19;
struct UnkStruct_00154770_21;
struct UnkStruct_00154770_2;
struct UnkStruct_00154770_7;
struct UnkStruct_00154770_9;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0064D37C;
struct UnkStruct_func_001549F0;

class CB3Score {
public:
    int IsAheadOfRoadRage(CB3Score*);
};

struct UnkStruct_D_0064D37C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00154770_2 {
    UnkStruct_00154770_7 * field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x1C];
    int field_20[1];  // [G] element count unknown
    unsigned char pad_24[0x1C];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12AD28];
    UnkStruct_00154770_17 * field_12AD28[1];  // [G] element count unknown
};

struct UnkStruct_00154770_7 {
    unsigned char pad_0[0x10C0];
    short field_10C0;
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_00154770_9 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00154770_9 {
    unsigned char pad_0[0x1B4];
    UnkStruct_00154770_10 * field_1B4;
};

struct UnkStruct_00154770_10 {
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
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual int vfunc_B8(int);
};

struct UnkStruct_00154770_17 {
    unsigned char pad_0[0x10C4];
    int field_10C4;
};

struct UnkStruct_00154770_19 {
    unsigned char pad_0[0x10C0];
    short field_10C0;
    unsigned char pad_10C2[0x852];
    int field_1914;
};

struct UnkStruct_func_001549F0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00154770_21 {
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
};

class CB3RacePosition {
public:
    void Update();

    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_00154770_21 * D_0064D388[];  // [G] element count unknown
extern UnkStruct_func_001549F0 func_001549F0;

extern "C" void qsort(UnkStruct_00154770_2 *, int, int, void *);

// 0x00154770
void CB3RacePosition::Update()
{
    UnkStruct_00154770_2 local;  // [G] the frame's one local (size: up to the frame top)
    if (field_18 == 0) {
        int t0 = D_0064D37C.field_0;
        for (int i = 0; (i < t0); i++) {
            local.field_0[i] = (UnkStruct_00154770_7 *)D_00522660.field_12AD28[i];
        }
        qsort(&local, t0, 4, &func_001549F0);
        int m0 = 0;
        while (m0 < t0) {
            local.field_0[m0]->field_10C0 = (m0 + 1);
            m0 = (m0 + 1);
        }
        UnkStruct_00154770_9 * t1 = D_0051BA88.field_0;
        if (t1 != 0) {
            UnkStruct_00154770_10 * t2 = t1->field_1B4;
            if (t2 != 0) {
                int r1 = t2->vfunc_B8(m0);
                if (r1 != 0) {
                    int i2;
                    int m1;
                    int i1 = 0;
                    goto t1;
                b1: {
                        UnkStruct_00154770_17 * t3 = D_00522660.field_12AD28[(unsigned int)i1];
                        m1 = 1;
                        i2 = 0;
                        UnkStruct_00154770_21 ** tb = D_0064D388;
                        for (; (i2 < t0); i2++) {
                            UnkStruct_00154770_21 * t4 = tb[i2];
                            if (t4 != (void *)t3) {
                                int r2 = t4->field_10C0.IsAheadOfRoadRage((CB3Score*)((char *)t3 + 4288));
                                if (r2 != 0) {
                                    m1 = (m1 + 1);
                                }
                            }
                        }
                        local.field_20[i1] = m1;
                    }
                    i1++;
                t1:
                    if (i1 < t0) goto b1;
                    for (int i3 = 0; (i3 < t0); i3++) {
                        D_00522660.field_12AD28[i3]->field_10C4 = local.field_20[i3];
                    }
                }
            }
        }
        int i4;
        int m2 = D_0064D37C.field_0;
        for (i4 = 0; (i4 < D_0064D37C.field_0); i4++) {
            UnkStruct_00154770_19 * t5 = (UnkStruct_00154770_19 *)D_00522660.field_12AD28[i4];
            if (t5->field_1914 == 0) {
                if (t5->field_10C0 < m2) {
                    field_1C = i4;
                    m2 = t5->field_10C0;
                }
            }
        }
    }
    field_18 = (field_18 + 1);
    if (field_18 >= 30) {
        field_18 = 0;
    }
}
