// NONMATCHING: UpdateGameStates__23CB3SoundGameModeManagerFv -- retail 268 / ours 265 instructions, 192 in changed runs
// audit1 (2026-11-01): layout: field_52CD sat at 0x52CC (field_3348 one byte short) [C] retail lbu 0x52CD (behaviour_audit) | Before: a142: logic complete (4 inlined any-player flag loops, bank loop, aggressive-distance loop, flag word). Remaining: allocation only - retail keeps mode in v1 and the any-flag in a0 (ours swaps: mode a0, any v1); bank-loop shape (retail top-tested slt/beqz loop with null-or-pointer select; ours rotated) | classic-op fallback | guard: n/a (classic ops) | mwperm: 240 -> 208 ('if (any) field_0 |= 2;' -> 'if (any) field_0 |= 2;'; 'if (any) field_0 |= 4;' -> 'if (any) field_0 |= 4;'; 'if (any) field_0 |= 0x20;' -> 'if (any) field_0 |= 0x20;'; 'if (any) field_0 |= 0x40;' -> 'if (any) field_0 |= 0x40;'; 'if (any) field_0 |= 8;' -> 'if (any != 0) field_0 |= 8;'; 'signed char sel = *((signed char *)&D_00522660 + c * 0x27D0 ' -> ''; 'float d = *(float *)((char *)&D_00522660 +)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


struct UnkStruct_mode { unsigned char pad_0[0xA0]; int field_A0; int field_A4; unsigned char pad_A8[0x18]; };
struct UnkStruct_D_0051BA88 { UnkStruct_mode *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051A9E0 { UnkStruct_mode m; };
extern UnkStruct_mode D_0051A9E0;
extern UnkStruct_mode D_0051A6A8;
extern UnkStruct_D_0051BA88 D_0051BA88;
struct UnkStruct_D_00522660 { unsigned char pad_0[0x27D0]; };
struct UnkStruct_D_00522678 { int field_0; unsigned char pad_4[4]; float field_8; unsigned char pad_C[4]; };
struct UnkStruct_D_00645170 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_bank { unsigned char pad_0[0x4590]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_00522678 D_00522678;
extern float D_00522680;
extern UnkStruct_D_00645170 D_00645170;
extern UnkStruct_bank D_0055EF70;
extern char D_004F5075;
extern unsigned char D_00665E51;
extern unsigned char D_00665E50;
extern float krSoundDistToRaceCarToBeAggressive;
extern "C" int func_003F86B0(void *);
extern "C" int IsBoostPassPlaying__22CB3SoundTrafficManagerFv(void *);
extern UnkStruct_D_00522660 D_01E78E50;
class CB3SoundGameModeManager {
public:
    int field_0;
    unsigned char pad_4[8];
    float field_C;
    unsigned char pad_10[0x3338];
    unsigned char field_3348[0x1F85];   // audit1: was 0x1F84 (field_52CD read at 0x52CC) [C] retail lbu 0x52CD
    unsigned char field_52CD;
    void UpdateGameStates();
    void UpdateVoiceGroupModeMixer();
};
static inline float fabsf(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
#define ANYPLAYER(OFF) { for (int c = 0; c < mode->field_A0; c++) any = (any | *((unsigned char *)&D_00522660 + c * 0x27D0 + OFF)) != 0; }
void CB3SoundGameModeManager::UpdateGameStates()
{
    UnkStruct_mode *mode = D_0051BA88.field_0;
    bool lobby = mode == &D_0051A6A8;
    if (mode == &D_0051A9E0) return;
    int old = field_0;
    field_0 = 1;
    if (!lobby) {
        bool any = false;
        ANYPLAYER(0x12BF2E)
            if (any) field_0 |= 2;
        any = false;
        ANYPLAYER(0x12C1D9)
            if (any) field_0 |= 4;
        any = false;
        ANYPLAYER(0x12C1DA)
            if (any) field_0 |= 0x20;
        any = false;
        ANYPLAYER(0x12C1D8)
            if (any) field_0 |= 0x40;
        any = false;
        for (int i = 0; i < mode->field_A0; i++) {
            unsigned char *b = 0;
            if (i < D_00645170.field_0) b = (unsigned char *)&D_0055EF70 + i * 0x4590 + 0x1CB80;
            any = (any | b[0x210]) != 0;
        }
        if (any != 0) field_0 |= 8;
        float aggr = krSoundDistToRaceCarToBeAggressive;
        bool near = false;
        for (int c = 0; c < mode->field_A0; c++) {
            for (int j = 0; j < mode->field_A4; j++) {
                float d = *(float *)((char *)&D_00522660 + c * 0x27D0 + (*((signed char *)&D_00522660 + c * 0x27D0 + 0x12C6FC)) * 4 + j * 0x2460 + 0x131584);
                if (fabsf(d) < aggr) { near = true; break; }
            }
            if (near) break;
        }
        if (near) field_0 |= 0x80;
        if (D_00522678.field_0 != 1) field_0 |= 0x10;
        if (IsBoostPassPlaying__22CB3SoundTrafficManagerFv(&D_01E78E50)) field_0 |= 0x100;
        if (D_00522680 < field_C) field_0 |= 0x200;
        if (field_52CD != 0 || D_00665E51 != 0 || D_00665E50 != 0) field_0 = 0x800;
    }
    if (func_003F86B0(&field_3348) && D_004F5075 > 0) field_0 |= 0x400;
    if (field_0 != old) UpdateVoiceGroupModeMixer();
}
