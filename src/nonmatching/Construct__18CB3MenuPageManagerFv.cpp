// NONMATCHING: Construct__18CB3MenuPageManagerFv -- retail 256 / ours 256 instructions, 273 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: a189: all 26 colour constants decoded from the asm (script build/vt/hand/a189_cmgen.py reads the stack temps), 256 vs 258 instrs, ~316 in changed runs: same family as the open 'ctor temps + lq/sq copy' blocker -- ours spills into s1/t6-t9 and frame is 0x1E0 vs 0x1C0 (retail uses only t0-t5/a0-a3/v0/
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3MenuPageManager::Construct() -- hand-written (a189); the lifter refused it.
// [C] name: the mangled symbol in retail's tables. Layout [G] from instruction widths; field names are placeholders.
// 26 CGtV4d colours built by the CGtV4d(x,y,z,w) ctor (one 16-byte temp each, retail's 0x1C0 frame), then scaled by D_004C4AC0.
#include "b3/GtMathPs2.h"

struct UnkStruct_D_01E88A80 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E94F10 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E94F14 { int field_0; unsigned char pad_4[0xC]; };

class CB3MenuPageManager {
public:
    void Construct();

    GtMathPs2::CGtV4d field_0[26];
    unsigned char pad_1A0[0x38];
    int field_1D8;
    int field_1DC;
    unsigned char pad_1E0[0x4];
    int field_1E4;
    unsigned char pad_1E8[0x8];
    int field_1F0;
    int field_1F4;
    unsigned char pad_1F8[0x1805];
    unsigned char field_19FD;
    unsigned char field_19FE;
    unsigned char field_19FF;
};

extern GtMathPs2::CGtV4d D_004C4AC0;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E94F10 D_01E94F10;
extern UnkStruct_D_01E94F14 D_01E94F14;
extern unsigned char D_01E91C40[];

extern "C" void Construct__10CGt2dSceneFiiiPvUi(void *, int, int, int, void *, unsigned int);
extern "C" void func_00382CF0();
extern "C" void func_003B61F0();
extern "C" void Construct__17CB3MenuComponentsFv(void *);

// 0x0030DF10
void CB3MenuPageManager::Construct()
{
    Construct__10CGt2dSceneFiiiPvUi((char *)this + 0x1A0, 0x75, 0x64, 0xF, D_01E91C40, 0x3000);
    field_1E4 = 6;
    field_1DC = 0;
    field_1F0 = 0;
    field_1D8 = 0;
    field_19FF = 0;
    field_0[0] = GtMathPs2::CGtV4d(175.0f, 210.0f, 255.0f, 1.0f);
    field_0[1] = GtMathPs2::CGtV4d(212.0f, 231.0f, 255.0f, 1.0f);
    field_0[2] = GtMathPs2::CGtV4d(175.0f, 210.0f, 255.0f, 0.4f);
    field_0[3] = GtMathPs2::CGtV4d(88.0f, 147.0f, 180.0f, 1.0f);
    field_0[4] = GtMathPs2::CGtV4d(193.0f, 239.0f, 255.0f, 1.0f);
    field_0[5] = GtMathPs2::CGtV4d(36.0f, 62.0f, 78.0f, 1.0f);
    field_0[6] = GtMathPs2::CGtV4d(254.0f, 254.0f, 248.0f, 1.0f);
    field_0[7] = GtMathPs2::CGtV4d(106.0f, 79.0f, 7.0f, 1.0f);
    field_0[8] = GtMathPs2::CGtV4d(248.0f, 245.0f, 251.0f, 1.0f);
    field_0[9] = GtMathPs2::CGtV4d(129.0f, 138.0f, 152.0f, 1.0f);
    field_0[10] = GtMathPs2::CGtV4d(209.0f, 202.0f, 157.0f, 1.0f);
    field_0[11] = GtMathPs2::CGtV4d(160.0f, 101.0f, 10.0f, 1.0f);
    field_0[18] = GtMathPs2::CGtV4d(90.0f, 153.0f, 192.0f, 1.0f);
    field_0[19] = GtMathPs2::CGtV4d(34.0f, 42.0f, 53.0f, 1.0f);
    field_0[20] = GtMathPs2::CGtV4d(17.0f, 36.0f, 64.0f, 1.0f);
    field_0[21] = GtMathPs2::CGtV4d(54.0f, 89.0f, 145.0f, 1.0f);
    field_0[22] = GtMathPs2::CGtV4d(255.0f, 180.0f, 73.0f, 1.0f);
    field_0[23] = GtMathPs2::CGtV4d(255.0f, 106.0f, 32.0f, 1.0f);
    field_0[12] = GtMathPs2::CGtV4d(12.0f, 15.0f, 26.0f, 1.0f);
    field_0[13] = GtMathPs2::CGtV4d(90.0f, 153.0f, 192.0f, 1.0f);
    field_0[14] = GtMathPs2::CGtV4d(45.0f, 77.5f, 96.0f, 1.0f);
    field_0[15] = GtMathPs2::CGtV4d(128.0f, 128.0f, 128.0f, 0.2f);
    field_0[16] = GtMathPs2::CGtV4d(0.0f, 0.0f, 0.0f, 1.0f);
    field_0[17] = GtMathPs2::CGtV4d(255.0f, 255.0f, 255.0f, 1.0f);
    field_0[24] = GtMathPs2::CGtV4d(255.0f, 210.0f, 0.0f, 1.0f);
    field_0[25] = GtMathPs2::CGtV4d(255.0f, 0.0f, 0.0f, 1.0f);
    for (int i = 0; i < 26; i++) {
        field_0[i] = field_0[i] * D_004C4AC0;
    }
    func_00382CF0();
    func_003B61F0();
    Construct__17CB3MenuComponentsFv(&D_01E88A80);
    field_19FD = 0;
    field_19FE = 0;
    D_01E94F10.field_0 = 0;
    D_01E94F14.field_0 = 0;
    field_1F4 = 1;
}
