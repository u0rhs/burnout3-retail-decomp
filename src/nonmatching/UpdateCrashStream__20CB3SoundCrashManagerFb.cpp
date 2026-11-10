// NONMATCHING: UpdateCrashStream__20CB3SoundCrashManagerFb -- retail 301 / ours 301 instructions, 19 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: 301/301 instrs; only diff: the c64 block (field_8DB = func_003865A0(...)) is inline after the GetStreamsPreparing test in ours, retail lays it out-of-line after the else block (0x444). Tried goto/else/early-return/bool-temps forms.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

namespace GtMath { inline float Max(float a, float b) { float r; asm("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
 inline float Min(float a, float b) { float r; asm("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; } }
struct UnkStruct_Pad16 { unsigned char pad[0x10]; };
struct UnkStruct_D_D3A0 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_5678 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_5680 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_D370 { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_D_D378 { unsigned char field_0; unsigned char field_1; unsigned char pad_2[0xE]; };
struct UnkStruct_Stream { unsigned char pad_0[0x1EC]; unsigned char field_1EC; };
class CB3SoundCrashManager {
public:
    void UpdateCrashStream(bool p0);
    unsigned char pad_0[0x4B0];
    char field_4B0[0x384];
    float field_834;
    float field_838;
    float field_83C;
    unsigned char pad_840[0x44];
    UnkStruct_Stream *field_884;
    UnkStruct_Stream *field_888;
    unsigned char pad_88C[4];
    unsigned char field_890;
    unsigned char field_891;
    unsigned char field_892;
    unsigned char pad_893[0x11];
    float field_8A4;
    float field_8A8;
    unsigned char pad_8AC[4];
    float field_8B0;
    float field_8B4;
    unsigned char pad_8B8[8];
    unsigned char field_8C0;
    unsigned char pad_8C1[0x1A];
    unsigned char field_8DB;
    unsigned char field_8DC;
    unsigned char pad_8DD;
    unsigned char field_8DE;
    unsigned char field_8DF;
    unsigned char field_8E0;
    unsigned char pad_8E1;
    unsigned char field_8E2;
};
extern UnkStruct_D_D3A0 D_0064D3A0;
extern UnkStruct_D_5678 D_00522678;
extern UnkStruct_D_5680 D_00522680;
extern UnkStruct_D_D370 D_0064D370;
extern UnkStruct_D_D378 D_0064D378;
extern UnkStruct_Pad16 D_004EE040;
extern UnkStruct_Pad16 D_01E774E0;
extern char D_004BED28[];
extern char D_004BED30[];
extern char D_004BED38[];
extern char D_004BED40[];
extern char D_004BED48[];
extern char D_004BED60[];
extern float D_004E1ADC;
extern "C" {
void Play__14CGtSoundStreamFb(UnkStruct_Stream *, bool);
void SetVolume__14CGtSoundStreamFfi(UnkStruct_Stream *, float, int);
int Release__14CGtSoundStreamFv(UnkStruct_Stream *);
int GetStreamsPreparing__21CGtSoundStreamManagerFv(void *);
int func_00131E40(void *);
int func_00385FD0(UnkStruct_Stream *);
int func_00385FE0(UnkStruct_Stream *);
int func_00386010(UnkStruct_Stream *);
unsigned char func_003865A0(UnkStruct_Stream *, char *, int, int, int, int);
void func_0021ADF0(unsigned long, char *);
char *strcpy(char *, const char *);
char *strcat(char *, const char *);
char *strncat(char *, const char *, unsigned);
int sprintf(char *, const char *, ...);
}
void CB3SoundCrashManager::UpdateCrashStream(bool p0)
{
    char buf60[0x10];
    char buf40[0x20];
    if (D_0064D3A0.field_0 < 2) {
        if (field_8E2 != 0) {
            if (field_888 != 0) {
                Play__14CGtSoundStreamFb(field_888, true);
                SetVolume__14CGtSoundStreamFfi(field_888, field_83C, 0);
                field_888->field_1EC = 2;
                field_8E2 = 0;
            }
        } else if (field_888 != 0) {
            SetVolume__14CGtSoundStreamFfi(field_888, field_83C, 0);
        }
        if (field_884 != 0) {
            if (p0) {
                if (func_00131E40(&D_004EE040) == 0) {
                    if (D_00522678.field_0 != 1) {
                        SetVolume__14CGtSoundStreamFfi(field_884, 0.0f, 0);
                        SetVolume__14CGtSoundStreamFfi(field_884, field_834 * D_004E1ADC, 1);
                        field_8DF = 1;
                    } else {
                        SetVolume__14CGtSoundStreamFfi(field_884, field_834 * D_004E1ADC, 0);
                        SetVolume__14CGtSoundStreamFfi(field_884, 0.0f, 1);
                        field_8DF = 0;
                    }
                } else {
                    if (field_8A8 > 15.0f) {
                        field_8A4 = 1.0f;
                    } else {
                        if (field_8A4 > 0.0f) {
                            field_8A4 = field_8A4 - 0.01f;
                        }
                        if (field_8A4 <= 0.0f && field_8DC != 0) {
                            field_8A4 = 0.0f;
                            Release__14CGtSoundStreamFv(field_884);
                            field_8E0 = 0;
                            field_8DC = 0;
                        }
                    }
                    float v = GtMath::Min(GtMath::Max(field_8A4, 0.0f), 1.0f);
                    SetVolume__14CGtSoundStreamFfi(field_884, v * field_838, 0);
                    SetVolume__14CGtSoundStreamFfi(field_884, 0.0f, 1);
                }
            } else if (func_00386010(field_884) != 0) {
                if (field_8DE == 0) {
                    float t = D_00522680.field_0;
                    float u = 0.5f + t;
                    field_8B0 = t;
                    field_8B4 = u;
                    if (D_00522678.field_0 != 1) {
                        field_8C0 = 1;
                    } else {
                        field_8C0 = 0;
                    }
                    field_8DE = 1;
                } else if (D_00522680.field_0 > field_8B4) {
                    Release__14CGtSoundStreamFv(field_884);
                    field_8DE = 0;
                    field_8DC = 0;
                } else {
                    SetVolume__14CGtSoundStreamFfi(field_884, ((field_8B4 - D_00522680.field_0) / 0.5f) * (field_834 * D_004E1ADC), field_8C0);
                }
            }
            if (func_00385FD0(field_884) != 0) {
a74:
                if (field_8DB == 0) {
                    if (func_00385FD0(field_884) != 0) goto c64;
                    if (GetStreamsPreparing__21CGtSoundStreamManagerFv(&D_01E774E0) == 0) goto c64;
                }
            } else {
                if (func_00385FE0(field_884) != 0) goto a74;
                if (func_00386010(field_884) == 0) return;
                if (field_8DB == 0) return;
                int c = field_891++;
                if (c % 5 == 0 && D_0064D378.field_0 == 0 && D_0064D378.field_1 == 0) {
                    int idx = field_892++ % 2 + 1;
                    unsigned long id = D_0064D370.field_0;
                    strcpy(field_4B0, D_004BED28);
                    func_0021ADF0(id, buf60);
                    strncat(field_4B0, buf60, 2);
                    strcat(field_4B0, D_004BED30);
                    strncat(field_4B0, buf60 + 3, 2);
                    strcat(field_4B0, D_004BED38);
                    strncat(field_4B0, D_004BED40, 2);
                    strcat(field_4B0, D_004BED30);
                    sprintf(buf40, D_004BED48, idx);
                    strcat(field_4B0, buf40);
                } else {
                    int e = field_890++;
                    sprintf(field_4B0, D_004BED60, e % 20 + 1);
                }
                field_8DB = 0;
                            }
            return;
c64:
            field_8DB = func_003865A0(field_884, field_4B0, 0, 0, 0, 4);
            return;
        }
    }
}
