// func_003137B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (if-chain for p1 (-1 return / 0 utf8 / else int) then shared tail; else-if color chain; const &D_01E90240).

// lifter variant 0
// func_003137B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_003137B0;
struct UnkStruct_003137B0_e1;
struct UnkStruct_003137B0_e2;
struct UnkStruct_D_004C5010;
struct UnkStruct_D_01E90240;
struct UnkStruct_kB3OnlineLobbyRagerTextColour;
struct UnkStruct_kB3OnlineLobbyRagerTextDisabledColour;
struct UnkStruct_kB3OnlineLobbyRagerTextSelectedColour;

struct UnkStruct_003137B0_e1 {
    unsigned char pad_0[0x14];
    void * field_14;
    void * field_18;
    unsigned char pad_1C[0x2C];
};

struct UnkStruct_D_01E90240 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
};

struct UnkStruct_003137B0_e2 {
    unsigned char pad_0[0x20];
    u_long128 field_20;
    unsigned char pad_30[0x20];
};

struct UnkStruct_kB3OnlineLobbyRagerTextColour {
    u_long128 field_0;
};

struct UnkStruct_kB3OnlineLobbyRagerTextDisabledColour {
    u_long128 field_0;
};

struct UnkStruct_kB3OnlineLobbyRagerTextSelectedColour {
    u_long128 field_0;
};

struct UnkStruct_D_004C5010 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003137B0 {
    unsigned char pad_0[0x4];
    unsigned short field_4;
    unsigned char pad_6[0x162];
    UnkStruct_003137B0_e1 field_168[1];  // [G] element count unknown
    unsigned char pad_1B0[0x3A0];
    UnkStruct_003137B0_e2 field_550[1];  // [G] element count unknown
    unsigned char pad_5A0[0xDBC];
    int field_135C[1];  // [G] element count unknown
    unsigned char pad_1360[0x30];
    int field_1390;
    unsigned char pad_1394[0x18];
    signed char field_13AC;
};

extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_kB3OnlineLobbyRagerTextColour kB3OnlineLobbyRagerTextColour;
extern UnkStruct_kB3OnlineLobbyRagerTextDisabledColour kB3OnlineLobbyRagerTextDisabledColour;
extern UnkStruct_kB3OnlineLobbyRagerTextSelectedColour kB3OnlineLobbyRagerTextSelectedColour;
extern UnkStruct_D_004C5010 D_004C5010;

extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const void *, const void *, unsigned short*, const void *, const void*);  // CGt2dObjectTable::RenderText(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,unsigned short*,const CGt2dFrame&,const void*), its address taken
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, const void *, const void*);  // CGt2dObjectTable::GetTextSize(GtMathPs2::CGtV2d*,const CGt2dFrame&,const void*), its address taken
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(void *, int, int);
extern "C" void PrintInt__10CGtUnicodeFPUsii(int, int, int, int);

// 0x003137B0
extern "C" void func_003137B0(UnkStruct_003137B0 * self, int p0, int p1, int p2, int p3)
{
    UnkStruct_D_01E90240 * const d = &D_01E90240;
    int t0 = self->field_1390;
    if (p0 < t0) {
        return;
    }
    int i = p0 - t0;
    if (i >= 6) {
        return;
    }
    if (p1 == -1) {
        self->field_168[i].field_14 = 0;
        self->field_168[i].field_18 = 0;
        return;
    }
    if (p1 == 0) {
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(&D_004C5010, self->field_135C[i], 16);
    } else {
        PrintInt__10CGtUnicodeFPUsii(self->field_135C[i], p1, 0, 0);
    }
    self->field_168[i].field_14 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
    self->field_168[i].field_18 = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
    if (i == self->field_4 && self->field_13AC == 1) {
        if (p3 != 0) {
            self->field_550[i].field_20 = kB3OnlineLobbyRagerTextSelectedColour.field_0;
        } else {
            self->field_550[i].field_20 = d->field_10;
        }
    } else if (p2 != 0) {
        if (p3 != 0) {
            self->field_550[i].field_20 = kB3OnlineLobbyRagerTextDisabledColour.field_0;
        } else {
            self->field_550[i].field_20 = d->field_20;
        }
    } else {
        if (p3 != 0) {
            self->field_550[i].field_20 = kB3OnlineLobbyRagerTextColour.field_0;
        } else {
            self->field_550[i].field_20 = d->field_0;
        }
    }
}
