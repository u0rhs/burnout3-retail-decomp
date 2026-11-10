// ForEachLobby__24CB3OnlineLobbySelectPageFiPciibPv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (ForEachLobby [L] DNAT; t0 > field_1780 gives slt at).

struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E89788 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89788 D_01E89788;

struct UnkStruct_003835C0_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    char field_C[0x24];
};
struct UnkStruct_003835C0_e1 {
    int field_0;
    int field_4;
    unsigned char pad_8[0x28];
};
struct UnkStruct_003835C0_t1 {
    UnkStruct_003835C0_e0 field_0[1];
    UnkStruct_003835C0_e1 field_30[1];
    unsigned char pad_60[0x1268];
    int field_12C8[1];
    unsigned char pad_12CC[0x18C];
    int field_1458;
    unsigned char pad_145C[0x320];
    unsigned short field_177C;
    short field_177E;
    int field_1780;
    int field_1784;
    int field_1788;
};

extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" void SetString__19CB3HelpBarComponentFPCUsbbf(void *, const unsigned short*, bool, bool, float);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(int, int, int);
extern "C" int PrintInt__10CGtUnicodeFPUsii(int, int, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" int AppendN__10CGtUnicodeFPUsiPCUs(int, int, int);

// [L] DNAT: CB3OnlineLobbySelectPage::ForEachLobby(int,char*,int,int,bool,void*) (research/proto/new_names.csv, high)
// 0x003835C0
extern "C" int ForEachLobby__24CB3OnlineLobbySelectPageFiPciibPv(int n0, char * p0, int p1, int p2, bool p3, UnkStruct_003835C0_t1 * p4)
{
    p4->field_0[p4->field_1784].field_8 = n0;
    strncpy(p4->field_0[p4->field_1784].field_C, p0, 33);
    p4->field_30[p4->field_1784].field_0 = p1;
    p4->field_30[p4->field_1784].field_4 = p2;
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi((int)p0, p4->field_12C8[p4->field_1784], 16);
    p4->field_1784 = (p4->field_1784 + 1);
    int t0 = p4->field_1784;
    if (t0 > p4->field_1780) {
        p4->field_177C = 0;
        p4->field_177E = t0;
        p4->field_1780 = p4->field_1784;
    }
    if (p4->field_1784 == 100) {
        p4->field_1788 = 60;
        int r2 = PrintInt__10CGtUnicodeFPUsii(p4->field_1458, p4->field_30[p4->field_177C].field_0, 1, 0);
        int r3 = func_00271A00(&D_0051BA44, 933);
        int r4 = AppendN__10CGtUnicodeFPUsiPCUs(r2, 32, r3);
        PrintInt__10CGtUnicodeFPUsii(r4, p4->field_30[p4->field_177C].field_4, 1, 0);
        SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short*)p4->field_1458, 0, 0, 80.0f);
        return 0;
    }
    if (p3) {
        p4->field_1788 = 60;
        int r7 = PrintInt__10CGtUnicodeFPUsii(p4->field_1458, p4->field_30[p4->field_177C].field_0, 1, 0);
        int r8 = func_00271A00(&D_0051BA44, 933);
        int r9 = AppendN__10CGtUnicodeFPUsiPCUs(r7, 32, r8);
        PrintInt__10CGtUnicodeFPUsii(r9, p4->field_30[p4->field_177C].field_4, 1, 0);
        SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short*)p4->field_1458, 0, 0, 80.0f);
        return 1;
    }
    return 1;
}
