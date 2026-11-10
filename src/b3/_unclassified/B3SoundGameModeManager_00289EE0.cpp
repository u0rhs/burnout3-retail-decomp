// CB3SoundGameModeManager::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundGameModeManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (mwperm: +'bool first;'; 'char b40[0x40]; bool first;' -> 'bool t0;'; +'char b40[0x40];'; 'if (field_52B8 != 0) {' -> 'if (field_52B8 == 0) { if (first) { unsigned long id = D_0064D370.field_0; strcp'; '} else if (first) { unsigned long id = D_0064D370.field_0; s' -> ''; 'if (field_52BC == 0) { field_52BC = D_01E75648.LoadBank((con' -> 't0 = field_52BC == 0; if (t0) { const char * t3 = (const char *)GetMod).

class CGtSoundBank;
class CGtSoundBankManager {
public:
    CGtSoundBank *LoadBank(const char *, bool, bool, int);
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_0064D370 { unsigned long field_0; unsigned char pad_8[8]; };
struct UnkStruct_D_01E75640 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E75688 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0064D370 D_0064D370;
extern UnkStruct_D_01E75640 D_01E75640;
extern UnkStruct_D_01E75688 D_01E75688;
extern CGtSoundBankManager D_01E75648;
extern int _gnLastSetRoomLevel;
extern char D_004EE040[];
struct UnkStruct_D_00665EA0 { unsigned char field_0; unsigned char pad_1[15]; };
extern UnkStruct_D_00665EA0 D_00665EA0;
extern char D_004BF718[];
extern char D_004BF720[];
extern char D_004BF728[];
extern char D_004BF730[];
extern char D_004BF738[];
extern "C" char *strcpy(char *, const char *);
extern "C" char *strcat(char *, const char *);
extern "C" char *strncat(char *, const char *, unsigned int);
extern "C" int sprintf(char *, const char *, ...);
extern "C" void SetMasterVolumeScalar__15CB3SoundManagerFf(void *, float);
extern "C" void SetMasterPitchScalar__15CB3SoundManagerFf(void *, float);
extern "C" int func_003FA5F0(void *);
extern "C" void func_003FA600(void *, int);
extern "C" int func_003FB0F0(void *, int);
extern "C" int func_003FA4A0(void *);
extern "C" void func_003FA510(void *);
extern "C" void func_003F8700(void *);
extern "C" int func_00131E40(void *);
extern "C" int func_002870D0(void *, int);
extern "C" int func_00383F00(CGtSoundBank *);
extern "C" void func_0028AEB0(void *);
extern "C" void func_0021ADF0(unsigned long, char *);
extern "C" void ReleaseStreams__20CB3SoundCrashManagerFv(void *);
extern "C" void Prepare__23CGtSoundListenerManagerFUi(void *, unsigned int);
extern "C" int Prepare__18CB3SoundESMManagerFv(void *);
extern "C" int Prepare__22CB3SoundRaceCarManagerFv(void *);
extern "C" int Prepare__25CB3SoundStaticPassManagerFv(void *);
extern "C" int Prepare__20CB3SoundCrashManagerFv(void *);
extern "C" int Prepare__22CB3SoundTrafficManagerFv(void *);
extern "C" int GetModeBankPath__23CB3SoundGameModeManagerCFv(void *);
class CB3SoundGameModeManager {
public:
    unsigned char pad_0[4];
    int field_4;
    unsigned int field_8;
    int field_C;
    unsigned char pad_10[0x34A8];
    int field_34B8;
    unsigned char pad_34BC[0x1DFC];
    CGtSoundBank *field_52B8;
    CGtSoundBank *field_52BC;
    int field_52C0;
    unsigned char pad_52C4[4];
    int field_52C8;
    unsigned char field_52CC;
    unsigned char field_52CD;
    bool Prepare();
};
// 0x00289EE0
bool CB3SoundGameModeManager::Prepare()
{
    bool first;
    char bC0[16];
    char b80[0x40];
    bool t0;
    if (D_0064D370.field_0 == 0) {
        first = false;
    } else {
        field_52CC = 0;
        SetMasterVolumeScalar__15CB3SoundManagerFf(&D_01E75640, 0.0f);
        first = true;
        if (func_003FA5F0(&pad_10[0x3338]) == 4) func_003FA600(&pad_10[0x3338], 5);
    }
    char b40[0x40];
    field_C = 0;
    field_52CD = 0;
    _gnLastSetRoomLevel = -0x2711;
    switch (field_4) {
    case 0x17:
    case 1:
    case 0x18:
        if (first && field_34B8 != 0x17) {
            if (func_003FB0F0(&pad_10[0x3338], 5) == 0) return false;
        }
        field_4 = 2;
    case 2:
        if (func_003FA4A0(&pad_10[0x3338]) == 0) {
            func_003FA510(&pad_10[0x3338]);
            return false;
        }
        ReleaseStreams__20CB3SoundCrashManagerFv(&pad_10[0xFC0]);
        if (func_00131E40(D_004EE040) != 0 && D_00665EA0.field_0 == 0) func_003F8700(&pad_10[0x3338]);
        field_4 = 3;
    case 3:
        if (first) {
            if ((func_002870D0(&pad_10[0x32B0], 1) & 0xFF) == 0) goto fail;
        }
        field_4 = 4;
    case 4:
        if (field_52B8 == 0) {
            if (first) {
                unsigned long id = D_0064D370.field_0;
                strcpy(b80, D_004BF718);
                func_0021ADF0(id, bC0);
                strncat(b80, bC0, 2);
                strcat(b80, D_004BF720);
                strncat(b80, bC0 + 3, 2);
                strcat(b80, D_004BF728);
                strncat(b80, D_004BF730, 2);
                strcat(b80, D_004BF720);
                sprintf(b40, D_004BF738, b80);
                field_52B8 = D_01E75648.LoadBank(b40, true, true, 0x1000);
                if (!field_52B8) goto fail;
            }
        } else {
            if (func_00383F00(field_52B8) == 0) return false;
        }
        if (first) {
            t0 = field_52BC == 0;
            if (t0) {
                const char * t3 = (const char *)GetModeBankPath__23CB3SoundGameModeManagerCFv(this);
                field_52BC = D_01E75648.LoadBank(t3, true, true, 0x1000);
                bool t1 = field_52BC == 0;
                if (t1) goto fail;
            } else if (func_00383F00(field_52BC) == 0) return false;
        }
        field_4 = 5;
    case 5:
        if (first) func_0028AEB0(&D_01E75640);
        field_52C8 = 0;
        Prepare__23CGtSoundListenerManagerFUi(&D_01E75688, field_8);
        field_4 = 6;
    case 6:
        if (first) {
            if ((Prepare__18CB3SoundESMManagerFv(&pad_10[0xC20]) & 0xFF) == 0) goto fail;
        }
        field_4 = 7;
    case 7:
        if (first) {
            if ((Prepare__22CB3SoundRaceCarManagerFv(&pad_10[0]) & 0xFF) == 0) goto fail;
        }
        field_4 = 8;
    case 8:
        if (first) {
            if ((Prepare__25CB3SoundStaticPassManagerFv(&pad_10[0x3330]) & 0xFF) == 0) goto fail;
        }
        field_4 = 9;
        goto fail;
    case 9:
        if (first) {
            if ((Prepare__20CB3SoundCrashManagerFv(&pad_10[0xFC0]) & 0xFF) == 0) goto fail;
        }
        field_4 = 10;
    case 10:
        if (first) {
            if ((Prepare__22CB3SoundTrafficManagerFv(&pad_10[0x1900]) & 0xFF) == 0) goto fail;
        }
        field_4 = 11;
    case 11:
        SetMasterPitchScalar__15CB3SoundManagerFf(&D_01E75640, 1.0f);
        field_52C0 = 0;
        SetMasterPitchScalar__15CB3SoundManagerFf(&D_01E75640, 1.0f);
        if (first) func_00131E40(D_004EE040);
        field_4 = 0x17;
        return true;
    default:
        goto fail;
    }
fail:
    return false;
}
