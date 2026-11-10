// NONMATCHING: Prepare__25CB3OnlineSelNetConfigPageFv -- retail 292 / ours 287 instructions, 57 in changed runs
// a228: format local is an aggregate-initialised local 'short fmt[5]={0x25,0x31,0x2D,0x20,0}' (gives retail's lh/sh count-down copy loop; D_004A4D50 is that compiler template), int n=0 declared first, alloc-loop via &field_8[i] pointer. 76->57 changed (287 vs 292 instrs). Left: retail keeps 9 s-regs (fp=ell, s7=i*200 offset, s2=rec, s6=&field_8[n]); ours CSEs rec/base, frame 0x130 vs 0x140
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// NONMATCHING: Prepare__25CB3OnlineSelNetConfigPageFv -- retail 292 / ours 281 instructions, 76 in changed runs
// a149: logic complete, block layout matches (281/292). Open: retail uses 9 s-regs (fp=ellipsis ushort, s7=i*200, s2=rec for tests, s7 recomputed cfg+i*200 for the call args, s6=&field_8[n]) so frame is 0x140 with buf at sp+0xA0; ours CSEs the rec address into one s-reg (7 s-regs, frame 0x130). Records are cfg+i*200 with fields at +0x30/+0x34/+0x78/+0xB8 (count at cfg+0, selected id at cfg+4)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

enum EB3BackgroundType {};
enum EGlobalStrings {};
struct UnkStruct_P_a149 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C6E58_a149 { unsigned short field_0; unsigned char pad_2[0xE]; };
struct UnkStruct_a149_fmt { short s[5]; };
extern UnkStruct_a149_fmt D_004A4D50;
extern UnkStruct_D_004C6E58_a149 D_004C6E58;
extern UnkStruct_P_a149 D_01E90438, D_01E89518, D_01E88A80, D_01E89800, D_01E894FC, D_01E8D4F0, D_004C6E48, D_004C6E50, D_01E3C620, D_0051BA44, D_01E8970C, D_01E89788;
extern "C" {
void Prepare__15CB3MenuPageBaseFb(void *, bool);
int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
void func_00319C80(void *, int, int);
int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);
bool func_0031ECD0(void *, unsigned long, int);
void Prepare__21CB3PromptBarComponentFv(void *);
void Prepare__20CB3PageTextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d14EGlobalStringsUi(void *, const void *, const void *, EGlobalStrings, unsigned int);
void *func_0022E6B0(void *);
void *func_001A3AA0(void *, const void *, int *);
void ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(void *, void *, int);
int AppendN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, unsigned short *);
int Length__10CGtUnicodeFPCUs(unsigned short *);
int func_00271A00(void *, int);
int func_0039BCD0(void *, void *, void *, int, int, float);
void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short *, bool, float);
}
struct UnkStruct_00346950_rec {
    unsigned char pad_0[0x30];
    int field_30;
    int field_34;
    unsigned char pad_38[0x40];
    signed char field_78[0x40];
    char field_B8[0x10];
};
#define REC(c, i) (*(UnkStruct_00346950_rec *)((char *)(c) + (i) * 200))
struct UnkStruct_00346950_cfg {
    int field_0;
    int field_4;
};
struct UnkStruct_00346950_ent { int field_0; unsigned char field_4; unsigned char pad_5[3]; };
class CB3OnlineSelNetConfigPage {
public:
    int Prepare();
    unsigned char pad_0[4];
    int field_4;
    unsigned short *field_8[6];
    unsigned short *field_20[6];
    unsigned char field_38[8];
    UnkStruct_00346950_ent field_40[7];
    unsigned short field_78;
    unsigned short field_7A;
    signed char field_7C[8];
    int field_84;
    signed char field_88;
};
int CB3OnlineSelNetConfigPage::Prepare()
{
    int n = 0;
    int tmp1;
    int tmp2;
    short fmt[5] = { 0x25, 0x31, 0x2D, 0x20, 0 };
    unsigned short buf[0x40];
    int i;
    Prepare__15CB3MenuPageBaseFb(this, 0);
    i = 0;
    do {
        unsigned short *a0 = (unsigned short *)AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x1D);
        unsigned short **pp = &field_8[i];
        *pp = a0;
        field_20[i] = (unsigned short *)AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x40);
        i++;
    } while (i < 7);
    func_00319C80(&D_01E89518, 0x431, 0xE);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 0x105, 3);
    Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
    Prepare__20CB3PageTextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d14EGlobalStringsUi(&D_01E8D4F0, &D_004C6E48, &D_004C6E50, (EGlobalStrings)0x432, 0x67);
    field_4 = -1;
    UnkStruct_00346950_cfg *cfg = (UnkStruct_00346950_cfg *)func_0022E6B0(&D_01E3C620);
    for (i = 0; i < cfg->field_0; i++) {
        if (REC(cfg, i).field_78[0] != 0 && REC(cfg, i).field_34 != 3 && i + 1 == cfg->field_4) {
            UnkStruct_00346950_rec *rec = &REC(cfg, i);
            tmp1 = 1;
            func_001A3AA0((void *)((int)field_8[0]), fmt, &tmp1);
            ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(rec->field_78, buf, 0x40);
            AppendN__10CGtUnicodeFPUsiPCUs(field_8[0], 0x1D, buf);
            ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(rec->field_B8, field_20[0], 0x40);
            if (Length__10CGtUnicodeFPCUs(buf) >= 0x1D) {
                field_8[0][0x17] = D_004C6E58.field_0;
                field_8[0][0x18] = 0;
            }
            if (rec->field_30 == 0) {
                field_40[0].field_0 = (int)field_8[0];
                field_40[0].field_4 = 0;
                field_38[0] = 1;
            } else {
                field_40[0].field_0 = (int)field_8[0];
                field_40[0].field_4 = 1;
                field_38[0] = 0;
            }
            field_7C[0] = i;
            n++;
            break;
        }
    }
    unsigned short ell = D_004C6E58.field_0;
    for (i = 0; i < cfg->field_0; i++) {
        UnkStruct_00346950_rec *rec = &REC(cfg, i);
        if (rec->field_78[0] != 0 && rec->field_34 != 3 && i + 1 != cfg->field_4) {
            tmp2 = n + 1;
            unsigned short **pp = &field_8[n];
            func_001A3AA0((void *)((int)field_8[n]), fmt, &tmp2);
            ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi((char *)cfg + i * 200 + 0x78, buf, 0x40);
            AppendN__10CGtUnicodeFPUsiPCUs(*pp, 0x1D, buf);
            ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi((char *)cfg + i * 200 + 0xB8, field_20[n], 0x40);
            if (Length__10CGtUnicodeFPCUs(buf) >= 0x1D) {
                field_8[n][0x17] = ell;
                field_8[n][0x18] = 0;
            }
            if (rec->field_30 == 0) {
                field_40[n].field_0 = (int)*pp;
                field_40[n].field_4 = 0;
                field_38[n] = 1;
            } else {
                field_40[n].field_0 = (int)*pp;
                field_40[n].field_4 = 1;
                field_38[n] = 0;
            }
            field_7C[n] = i;
            n++;
        }
    }
    field_84 = n;
    UnkStruct_00346950_ent *e = &field_40[field_84];
    e->field_0 = func_00271A00(&D_0051BA44, 0x433);
    e->field_4 = 0;
    field_78 = 0;
    field_7A = field_84 + 1;
    func_0039BCD0(&D_01E8970C, &field_78, field_40, 2, 1, 516.0f);
    if (field_84 > 0) {
        Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, field_20[0], true, 80.0f);
    } else {
        int r = func_00271A00(&D_0051BA44, 0x434);
        Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short *)r, false, 80.0f);
    }
    field_88 = 0;
    return 1;
}
