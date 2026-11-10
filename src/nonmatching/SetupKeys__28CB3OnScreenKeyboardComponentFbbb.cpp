// NONMATCHING: SetupKeys__28CB3OnScreenKeyboardComponentFbbb -- retail 342 / ours 338 instructions, 149 in changed runs
// audit1 (2026-11-01): layout: the pad after the key array was 0xE0 from 0x2FA0, not 0x80 from 0x3000, so field_3080/30DC/3208 read 0x60 high [C] retail 0x34F470 (behaviour_audit) | Before: ghvu19: logic/layout right (per-key inline: GetString char into key text, FindUTFChar in the allowed string -> flag + SetA 1.0/0.25; rows 1-3 cols 2..lim, rows 1-3 cols 12-14, key [4][13], Alphabet/Accents labels). const kB3OnScreenKeyboard*Key externs give retail's hoisted column limits. Left: retail hoists &D_0051BA44 per row into s7 and spills the &field_30DC[row][col] pointer (sq 0xC0); ours keeps the element pointer in s6 and rematerialises &D_0051BA44 per call; a const-pointer local hoists it but adds a zero-trip guard (k4g). Not-found arm out of line in retail. Pragma sweep: nothing.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// Hand-written (ghvu19, Ghidra draft + retail asm); the lifter refused it.
// Layout as HighlightKey / FindKey (B3OnScreenKeyboardComponent_0034EEB0.cpp, _0034D6F0.cpp): grid keys [5][15] of 0x90
// bytes at +0x5D0 (text colour +0x20, label +0x48), key flags [5][15] at +0x3080, key text pointers [5][15] at +0x30DC.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3OnScreenKeyboardCell { public: int field_0; int field_4; };
struct UnkStruct_kKey { CB3OnScreenKeyboardCell c; int pad[2]; };
extern const UnkStruct_kKey kB3OnScreenKeyboardAlphabetKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardAccentsKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardBackspaceKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardLeftArrowKey;
struct UnkStruct_D_0051BA44 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051BA44 D_0051BA44;
// [L] DNAT: CB3Strings::GetString(int) (research/proto/new_names.csv, medium)
extern "C" unsigned short *func_00271A00(void *, int);
extern "C" int FindUTFChar__15CGtUnicodeUtilsFPUsUs(unsigned short *, unsigned short);
struct UnkStruct_0034F300_key {
    unsigned char pad_0[0x20];
    CGtV4d field_20;
    unsigned char pad_30[0x18];
    unsigned short *field_48;
    unsigned char pad_4C[0x44];
};
class CB3OnScreenKeyboardComponent {
public:
    void SetupKeys(bool p0, bool p1, bool p2);
    unsigned char pad_0[0x5D0];
    UnkStruct_0034F300_key field_5D0[5][15];
    unsigned char pad_3000[0x80];   // audit1: was pad_2FA0[0xE0] -- the key array (75 x 0x90) ends at 0x3000; 0xE0 put field_3080..field_3208 0x60 high [C] retail 0x34F470 lw 0x3208
    unsigned char field_3080[5][15];
    unsigned char pad_30CB[0x11];
    unsigned short *field_30DC[5][15];
    int field_3208;
};
// [G] per-key setup inline (unnamed): the key's character from string table entry idx, flag and alpha from whether the
// allowed-character string contains it
static inline void func_0034F300_inl1(CB3OnScreenKeyboardComponent *self, int row, int col, int str, int idx)
{
    self->field_30DC[row][col][0] = func_00271A00(&D_0051BA44, str)[idx];
    self->field_30DC[row][col][1] = 0;
    if (FindUTFChar__15CGtUnicodeUtilsFPUsUs(func_00271A00(&D_0051BA44, self->field_3208), self->field_30DC[row][col][0])) {
        self->field_3080[row][col] = 1;
        self->field_5D0[row][col].field_20.SetA(1.0f);
    } else {
        self->field_3080[row][col] = 0;
        self->field_5D0[row][col].field_20.SetA(0.25f);
    }
}

// 0x0034F300
void CB3OnScreenKeyboardComponent::SetupKeys(bool p0, bool p1, bool p2)
{
    int str = 0x293;
    if (field_3208 == 0x297) str = 0x294;
    int idx;
    if (p1) {
        idx = 0x34;
    } else if (p2) {
        if (p0) idx = 0x68;
        else idx = 0x4E;
    } else {
        if (p0) idx = 0x1A;
        else idx = 0;
    }
    int row;
    int col;
    for (row = 1; row < 4; row++) {
        int n;
        if (row == 1) n = kB3OnScreenKeyboardLeftArrowKey.c.field_4;
        else if (row == 2) n = kB3OnScreenKeyboardLeftArrowKey.c.field_4 - 1;
        else n = kB3OnScreenKeyboardBackspaceKey.c.field_4;
        for (col = 2; col < n; col++) {
            func_0034F300_inl1(this, row, col, str, idx);
            idx++;
        }
    }
    idx = 0x82;
    for (row = 1; row < 4; row++) {
        for (col = 12; col < 15; col++) {
            func_0034F300_inl1(this, row, col, str, idx);
            idx++;
        }
    }
    func_0034F300_inl1(this, 4, 13, str, idx);
    if (p1) {
        field_5D0[kB3OnScreenKeyboardAlphabetKey.c.field_0][kB3OnScreenKeyboardAlphabetKey.c.field_4].field_48 = func_00271A00(&D_0051BA44, 0x28B);
    } else {
        field_5D0[kB3OnScreenKeyboardAlphabetKey.c.field_0][kB3OnScreenKeyboardAlphabetKey.c.field_4].field_48 = func_00271A00(&D_0051BA44, 0x28D);
    }
    if (p2) {
        field_5D0[kB3OnScreenKeyboardAccentsKey.c.field_0][kB3OnScreenKeyboardAccentsKey.c.field_4].field_48 = func_00271A00(&D_0051BA44, 0x28B);
    } else {
        field_5D0[kB3OnScreenKeyboardAccentsKey.c.field_0][kB3OnScreenKeyboardAccentsKey.c.field_4].field_48 = func_00271A00(&D_0051BA44, 0x28C);
    }
}
