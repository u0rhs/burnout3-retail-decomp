// Hand-written; the lifter refused it (L271: TagFieldSet table; per-site if(t==-1)t=0; vcalls via placeholder virtual slot 0xF0; gp-rel float extern; 3-call sum in a static inline).

// func_0041C900 -- hand-written (L271) from the asm; the lifter refused it.
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction widths).
// [L] DNAT (low): ~CB3OnlineUploadResultsPage::Update() (research/proto/new_names.csv; neighbour of
// Release__26CB3OnlineUploadResultsPageFv).

struct UnkStruct_0041C900 {
    unsigned char pad_0[0x40];
    float field_40;
    unsigned char pad_44[0xC];
    int field_50;
    unsigned char pad_54[0xC];
    float field_60;
    unsigned char pad_64[0x4];
    float field_68;
    int field_6C;
};

struct UnkStruct_0041C900_obj {
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
    virtual void vfunc_EC();
    virtual int vfunc_F0();
    unsigned char pad_4[0xC];
};

struct UnkStruct_D_0064D38C {
    char * field_0;
    unsigned char pad_4[0xC];
};

struct UnkStruct_D_0051BF9C {
    void * field_0;
    unsigned char pad_4[0xC];
};

struct UnkStruct_D_01E900C0 {
    unsigned int field_0;
    unsigned char pad_4[0xC];
};

extern unsigned char D_01E3CD44[];
extern char D_004D1100[], D_004D1108[], D_004D1118[], D_004D1120[], D_004D1130[], D_004D1140[], D_004D1150[];
extern char D_004D1160[], D_004D1170[], D_004D1178[], D_004D1188[], D_004D1198[], D_004D11A8[], D_004D11B8[];
extern char D_004D11C8[], D_004D11D0[], D_004D11E0[], D_004D11F0[], D_004D1200[], D_004D1210[], D_004D1218[];
extern char D_004D1220[], D_004D1228[], D_004D1230[], D_004D1238[], D_004D1240[], D_004D1250[], D_004D1260[];
extern char D_004D1270[], D_004D1280[], D_004D1288[], D_004D1298[], D_004D12A0[], D_004D12B0[], D_004D12C0[];
extern char D_004D12D0[];
extern UnkStruct_D_01E900C0 D_01E900C0;
extern UnkStruct_0041C900_obj D_0051B788;
extern UnkStruct_0041C900_obj D_0051B714;
extern UnkStruct_0041C900_obj D_0051B7FC;
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_0064D38C D_0064D38C;
extern unsigned long D_01E90198[];
extern unsigned long D_01E90130[];
extern unsigned long D_01E90138[];
extern unsigned long D_01E901F0[];
extern float D_004E0C14;

extern "C" char * func_00335DD0(void *, int);
extern "C" void func_00335DB0(void *, char *);
extern "C" void func_00336410(void *, char *, char *, int);
extern "C" void * memset(void *, int, unsigned int);
extern "C" void TagFieldSetNumber(char *, int, const char *, int);
extern "C" void TagFieldSetString(char *, int, const char *, const char *);
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(char *, char *, int);
extern "C" int func_003EB060(unsigned long);
extern "C" unsigned long func_0013A5C0(void *);
extern "C" int func_0013AE20(void *, int);
extern "C" int func_0013ADD0(void *, int);
extern "C" int func_0013AB80(void *, int, int);
extern "C" int func_0013AA10(void *, int, int);
extern "C" int func_0013A8A0(void *, int, int);
extern "C" int func_0013ACF0(void *);
extern "C" int func_0013A7F0(void *);
extern "C" int func_0013A620(void *);
extern "C" int func_0013A890(void *, int);
extern "C" int FindCrashStage__26CB3HardCodedCrashStageListFUl(unsigned long);
extern "C" int FindTrack__21CB3HardCodedTrackListFUl(unsigned long);

#define VCALL(o) (((UnkStruct_0041C900_obj *)&(o))->vfunc_F0())

static inline int func_0041C900_inl1(void * p, int k)
{
    return func_0013AB80(p, 3, k) + func_0013AA10(p, 3, k) + func_0013A8A0(p, 3, k);
}

// 0x0041C900
extern "C" void func_0041C900(UnkStruct_0041C900 * self)
{
    char name[16];
    char * buf = func_00335DD0(D_01E3CD44, 0x428);
    char * buf2 = func_00335DD0(D_01E3CD44, 0x47E);
    memset(buf, 0, 0x428);
    buf[0] = 0;
    TagFieldSetString(buf, 0x428, D_004D1100, D_004D1108);
    if (D_01E900C0.field_0 < 2) {
        TagFieldSetNumber(buf, 0x428, D_004D1118, self->field_50);
        TagFieldSetNumber(buf, 0x428, D_004D1120, 0);
    } else {
        TagFieldSetNumber(buf, 0x428, D_004D1118, 0);
        int v = 0;
        if (D_01E900C0.field_0 == 3) {
            v = VCALL(D_0051B788);
        } else if (D_01E900C0.field_0 == 2) {
            v = VCALL(D_0051B714);
        } else if (D_01E900C0.field_0 == 4) {
            v = VCALL(D_0051B7FC);
        }
        TagFieldSetNumber(buf, 0x428, D_004D1120, v);
    }
    int t = func_003EB060(func_0013A5C0(D_0051BF9C.field_0));
    if (t == -1) t = 0;
    TagFieldSetNumber(buf, 0x428, D_004D1130, t);
    TagFieldSetNumber(buf, 0x428, D_004D1140, self->field_6C);
    TagFieldSetNumber(buf, 0x428, D_004D1150, (int)self->field_60);
    t = FindTrack__21CB3HardCodedTrackListFUl(D_01E90198[0]);
    if (t == -1) t = 0;
    TagFieldSetNumber(buf, 0x428, D_004D1160, t);
    TagFieldSetNumber(buf, 0x428, D_004D1170, (int)self->field_68);
    t = func_003EB060(D_01E90130[0]);
    if (t == -1) t = 0;
    TagFieldSetNumber(buf, 0x428, D_004D1178, t);
    TagFieldSetNumber(buf, 0x428, D_004D1188, func_0013AE20(D_0051BF9C.field_0, 1));
    TagFieldSetNumber(buf, 0x428, D_004D1198, func_0013ADD0(D_0051BF9C.field_0, 1));
    TagFieldSetNumber(buf, 0x428, D_004D11A8, func_0041C900_inl1(D_0051BF9C.field_0, 1));
    TagFieldSetNumber(buf, 0x428, D_004D11B8, func_0041C900_inl1(D_0051BF9C.field_0, 2));
    TagFieldSetNumber(buf, 0x428, D_004D11C8, func_0013ACF0(D_0051BF9C.field_0));
    TagFieldSetNumber(buf, 0x428, D_004D11D0, func_0013A7F0(D_0051BF9C.field_0));
    TagFieldSetNumber(buf, 0x428, D_004D11E0, func_0013A620(D_0051BF9C.field_0));
    TagFieldSetNumber(buf, 0x428, D_004D11F0, func_0013A890(D_0051BF9C.field_0, 0));
    TagFieldSetNumber(buf, 0x428, D_004D1200, 0xAD);
    TagFieldSetNumber(buf, 0x428, D_004D1210, 0);
    TagFieldSetNumber(buf, 0x428, D_004D1218, 0);
    if (D_01E900C0.field_0 <= 1) {
        TagFieldSetNumber(buf, 0x428, D_004D1280, FindTrack__21CB3HardCodedTrackListFUl(D_01E90198[0]));
        float f = self->field_40;
        if (D_004E0C14 != f && 0.0f != f) {
            TagFieldSetNumber(buf, 0x428, D_004D1288, (int)(1000.0f * f));
            TagFieldSetNumber(buf, 0x428, D_004D1298, func_003EB060(D_01E90130[0]));
        }
        if (self->field_6C > 0) {
            TagFieldSetNumber(buf, 0x428, D_004D12A0, self->field_6C);
            TagFieldSetNumber(buf, 0x428, D_004D12B0, func_003EB060(D_01E90130[0]));
        }
        TagFieldSetNumber(buf, 0x428, D_004D12C0, 0);
    } else if (D_01E900C0.field_0 != 3) {
        TagFieldSetNumber(buf, 0x428, D_004D1220, FindCrashStage__26CB3HardCodedCrashStageListFUl(D_01E901F0[0]));
        if (D_01E900C0.field_0 == 2) {
            TagFieldSetNumber(buf, 0x428, D_004D1228, self->field_50);
            TagFieldSetNumber(buf, 0x428, D_004D1230, func_003EB060(D_01E90130[0]));
            TagFieldSetNumber(buf, 0x428, D_004D1238, 0);
            TagFieldSetNumber(buf, 0x428, D_004D1240, 0);
            TagFieldSetNumber(buf, 0x428, D_004D1250, 0);
            TagFieldSetString(buf, 0x428, D_004D1260, D_004D12D0);
        } else if (D_01E900C0.field_0 == 4) {
            TagFieldSetNumber(buf, 0x428, D_004D1228, 0);
            TagFieldSetNumber(buf, 0x428, D_004D1230, 0);
            TagFieldSetNumber(buf, 0x428, D_004D1238, self->field_50);
            TagFieldSetNumber(buf, 0x428, D_004D1240, func_003EB060(D_01E90130[0]));
            TagFieldSetNumber(buf, 0x428, D_004D1250, func_003EB060(D_01E90138[0]));
            ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_0064D38C.field_0 + 0x1974, name, 9);
            TagFieldSetString(buf, 0x428, D_004D1260, name);
        }
        TagFieldSetNumber(buf, 0x428, D_004D1270, 0);
    }
    func_00336410(D_01E3CD44, buf, buf2, 0x47E);
    func_00335DB0(D_01E3CD44, buf);
    func_00335DB0(D_01E3CD44, buf2);
}
