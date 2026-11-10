// NONMATCHING: func_001372B0 -- retail 484 / ours 484 instructions, 15 in changed runs
// psweep: scoped #pragma opt_arithtransformation off [G] improves 18 -> 15
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_arithtransformation off
// func_001372B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3HardCodedCrashStageList;
class CB3HardCodedRaceStageList;
class CB3HardCodedTrackList;
struct UnkStruct_001372B0;
struct UnkStruct_001372B0_13;
struct UnkStruct_001372B0_17;
struct UnkStruct_001372B0_35;
struct UnkStruct_001372B0_e10;
struct UnkStruct_001372B0_e11;
struct UnkStruct_001372B0_e12;
struct UnkStruct_001372B0_e17;
struct UnkStruct_001372B0_e18;
struct UnkStruct_001372B0_e19;
struct UnkStruct_D_00518690;
struct UnkStruct_D_0051BFA0;
struct UnkStruct_gCalculatedData;

class CB3HardCodedRaceStageList {
public:
    static int FindChallengeIndex(unsigned long);
};

class CB3HardCodedTrackList {
public:
    static int FindTrack(unsigned long);
};

class CB3HardCodedCrashStageList {
public:
    static int FindCrashStage(unsigned long);
};

struct UnkStruct_D_0051BFA0 {
    unsigned char pad_0[0x57];
    unsigned char field_57[1];  // [G] element count unknown
    unsigned char pad_58[0x48];
    unsigned char field_A0[1];  // [G] element count unknown
    unsigned char pad_A1[0x87];
    unsigned char field_128[1];  // [G] element count unknown
    unsigned char pad_129[0x9];
    unsigned char field_132[1];  // [G] element count unknown
    unsigned char pad_133[0x71];
    int field_1A4[1];  // [G] element count unknown
    unsigned char pad_1A8[0x10];
    int field_1B8[1];  // [G] element count unknown
    unsigned char pad_1BC[0x10];
    int field_1CC[1];  // [G] element count unknown
    unsigned char pad_1D0[0x10];
    int field_1E0[1];  // [G] element count unknown
    unsigned char pad_1E4[0x18];
    int field_1FC[1];  // [G] element count unknown
    unsigned char pad_200[0x10];
    int field_210[1];  // [G] element count unknown
    unsigned char pad_214[0x10];
    int field_224[1];  // [G] element count unknown
    unsigned char pad_228[0x10];
    int field_238[1];  // [G] element count unknown
    unsigned char pad_23C[0x10];
    int field_24C[1];  // [G] element count unknown
    unsigned char pad_250[0x10];
    int field_260[1];  // [G] element count unknown
};

struct UnkStruct_gCalculatedData {
    unsigned char pad_0[0x3C];
    int field_3C;
    unsigned char pad_40[0x10];
    int field_50;
    unsigned char pad_54[0x10];
    int field_64;
    unsigned char pad_68[0x10];
    int field_78;
    unsigned char pad_7C[0x10];
    int field_8C;
    int field_90;
    int field_94;
    unsigned char pad_98[0x10];
    int field_A8;
    unsigned char pad_AC[0x10];
    int field_BC;
    unsigned char pad_C0[0x10];
    int field_D0;
    unsigned char pad_D4[0x10];
    int field_E4;
    unsigned char pad_E8[0x10];
    int field_F8;
    unsigned char pad_FC[0x10];
    int field_10C;
};

struct UnkStruct_D_0051BFA0_all {
    unsigned char pad_0[0x57];
    unsigned char field_57[1];
    unsigned char pad_58[0x48];
    unsigned char field_A0[1];
    unsigned char pad_A1[0x87];
    unsigned char field_128[1];
    unsigned char pad_129[0x9];
    unsigned char field_132[1];
    unsigned char pad_133[0x6D];
    int field_1A0;  // gCalculatedData+0x3C
    int field_1A4[1];
    unsigned char pad_1A8[0xC];
    int field_1B4;  // gCalculatedData+0x50
    int field_1B8[1];
    unsigned char pad_1BC[0xC];
    int field_1C8;  // gCalculatedData+0x64
    int field_1CC[1];
    unsigned char pad_1D0[0xC];
    int field_1DC;  // gCalculatedData+0x78
    int field_1E0[1];
    unsigned char pad_1E4[0xC];
    int field_1F0;  // gCalculatedData+0x8C
    int field_1F4;  // gCalculatedData+0x90
    int field_1F8;  // gCalculatedData+0x94
    int field_1FC[1];
    unsigned char pad_200[0xC];
    int field_20C;  // gCalculatedData+0xA8
    int field_210[1];
    unsigned char pad_214[0xC];
    int field_220;  // gCalculatedData+0xBC
    int field_224[1];
    unsigned char pad_228[0xC];
    int field_234;  // gCalculatedData+0xD0
    int field_238[1];
    unsigned char pad_23C[0xC];
    int field_248;  // gCalculatedData+0xE4
    int field_24C[1];
    unsigned char pad_250[0xC];
    int field_25C;  // gCalculatedData+0xF8
    int field_260[1];
    unsigned char pad_264[0xC];
    int field_270;  // gCalculatedData+0x10C
};
struct UnkStruct_D_00518690 {
    UnkStruct_001372B0_13 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_001372B0_13 {
    unsigned char pad_0[0x4];
    UnkStruct_001372B0_e10 * field_4;
    int field_8;
};

struct UnkStruct_001372B0_e10 {
    UnkStruct_001372B0_e11 * field_0;
    int field_4;
};

struct UnkStruct_001372B0_e11 {
    unsigned char pad_0[0x10];
    UnkStruct_001372B0_e12 * field_10;
    int field_14;
};

struct UnkStruct_001372B0_e12 {
    unsigned char pad_0[0x34];
    UnkStruct_001372B0_17 * field_34;
    unsigned char pad_38[0x8];
};

struct UnkStruct_001372B0_17 {
    unsigned long field_0;
    unsigned long field_8;
};

struct UnkStruct_001372B0_e17 {
    UnkStruct_001372B0_e18 * field_0;
    int field_4;
};

struct UnkStruct_001372B0_e18 {
    unsigned char pad_0[0x10];
    UnkStruct_001372B0_e19 * field_10;
    int field_14;
};

struct UnkStruct_001372B0_e19 {
    unsigned char pad_0[0x34];
    UnkStruct_001372B0_35 * field_34;
    unsigned char pad_38[0x8];
};

struct UnkStruct_001372B0_35 {
    unsigned long field_0;
    unsigned long field_8;
};

struct UnkStruct_001372B0 {
    unsigned char pad_0[0x386];
    signed char field_386[1];  // [G] element count unknown
    unsigned char pad_387[0x48];
    signed char field_3CF[1];  // [G] element count unknown
};

extern UnkStruct_D_0051BFA0_all D_0051BFA0;

extern UnkStruct_D_00518690 D_00518690;

extern "C" int func_003EAA60(void *);
extern "C" int func_003F5ED0(int);

// 0x001372B0
extern "C" void func_001372B0(UnkStruct_001372B0 * self)
{
    int i3;
    UnkStruct_001372B0_e10 * a;
    UnkStruct_001372B0_e11 * b;
    UnkStruct_001372B0_e12 * e;
    for (int i = 0; i < 4; i++) {
        D_0051BFA0.field_1A4[i] = 0;
        D_0051BFA0.field_1B8[i] = 0;
        D_0051BFA0.field_1CC[i] = 0;
        D_0051BFA0.field_1E0[i] = 0;
        D_0051BFA0.field_1FC[i] = 0;
        D_0051BFA0.field_210[i] = 0;
        D_0051BFA0.field_224[i] = 0;
        D_0051BFA0.field_238[i] = 0;
        D_0051BFA0.field_24C[i] = 0;
        D_0051BFA0.field_260[i] = 0;
    }
    D_0051BFA0.field_1B4 = 0;
    D_0051BFA0.field_1C8 = 0;
    D_0051BFA0.field_1DC = 0;
    D_0051BFA0.field_1F0 = 0;
    D_0051BFA0.field_1F8 = 0;
    D_0051BFA0.field_1A0 = 0;
    D_0051BFA0.field_20C = 0;
    D_0051BFA0.field_220 = 0;
    D_0051BFA0.field_234 = 0;
    D_0051BFA0.field_248 = 0;
    D_0051BFA0.field_25C = 0;
    D_0051BFA0.field_270 = 0;
    for (int i1 = 0; i1 < D_00518690.field_0->field_8; i1++) {
        a = &D_00518690.field_0->field_4[i1];
        for (int i2 = 0; i2 < a->field_4; i2++) {
            b = &a->field_0[i2];
            for (int i3 = 0; i3 < b->field_14; i3++) {
                e = &b->field_10[i3];
                int ch = CB3HardCodedRaceStageList::FindChallengeIndex(e->field_34->field_8);
                if (ch == -1) continue;
                int tr = CB3HardCodedTrackList::FindTrack(e->field_34->field_0);
                if (tr == -1) continue;
                int ty = func_003EAA60((void *)(tr));
                switch (ty) {
                case 0:
                    D_0051BFA0.field_20C++;
                    D_0051BFA0.field_1B4++;
                    break;
                case 1:
                    D_0051BFA0.field_234++;
                    D_0051BFA0.field_1C8++;
                    break;
                case 2:
                    D_0051BFA0.field_25C++;
                    D_0051BFA0.field_1DC++;
                    break;
                }
                if (D_0051BFA0.field_57[ch] == 0) continue;
                for (int j = 0; j < 10; j++) {
                    if (ch == func_003F5ED0(j)) {
                        D_0051BFA0.field_128[j] = 1;
                        break;
                    }
                }
                signed char m = self->field_386[ch];
                if (m <= 0) continue;
                switch (ty) {
                case 0:
                    D_0051BFA0.field_1A4[m]++;
                    D_0051BFA0.field_1E0[m]++;
                    D_0051BFA0.field_1F0++;
                    D_0051BFA0.field_1F8++;
                    D_0051BFA0.field_1FC[m]++;
                    break;
                case 1:
                    D_0051BFA0.field_1B8[m]++;
                    D_0051BFA0.field_1E0[m]++;
                    D_0051BFA0.field_1F0++;
                    D_0051BFA0.field_1F8++;
                    D_0051BFA0.field_224[m]++;
                    break;
                case 2:
                    D_0051BFA0.field_1CC[m]++;
                    D_0051BFA0.field_1E0[m]++;
                    D_0051BFA0.field_1F0++;
                    D_0051BFA0.field_1F8++;
                    D_0051BFA0.field_24C[m]++;
                    break;
                default:
                    continue;
                }
                if (m != 3) continue;
                D_0051BFA0.field_1F4++;
                for (int k = 0; k < 10; k++) {
                    if (ch == func_003F5ED0(k)) {
                        D_0051BFA0.field_132[k] = 1;
                        D_0051BFA0.field_1A0++;
                        break;
                    }
                }
            }
        }
    }
    for (int i1 = 0; i1 < D_00518690.field_0->field_8; i1++) {
        a = &D_00518690.field_0->field_4[i1];
        for (int i2 = 0; i2 < a->field_4; i2++) {
            b = &a->field_0[i2];
            for (i3 = 0; i3 < b->field_14; i3++) {
                e = &b->field_10[i3];
                int cs = CB3HardCodedCrashStageList::FindCrashStage(e->field_34->field_8);
                if (cs == -1) continue;
                int tr = CB3HardCodedTrackList::FindTrack(e->field_34->field_0);
                if (tr == -1) continue;
                int ty = func_003EAA60((void *)(tr));
                switch (ty) {
                case 0:
                    D_0051BFA0.field_220++;
                    D_0051BFA0.field_1B4++;
                    break;
                case 1:
                    D_0051BFA0.field_248++;
                    D_0051BFA0.field_1C8++;
                    break;
                case 2:
                    D_0051BFA0.field_270++;
                    D_0051BFA0.field_1DC++;
                    break;
                }
                if (D_0051BFA0.field_A0[cs] == 0) continue;
                signed char m = self->field_3CF[cs];
                if (m <= 0) continue;
                switch (ty) {
                case 0:
                    D_0051BFA0.field_1A4[m]++;
                    D_0051BFA0.field_1E0[m]++;
                    D_0051BFA0.field_1F0++;
                    D_0051BFA0.field_1F8++;
                    D_0051BFA0.field_210[m]++;
                    break;
                case 1:
                    D_0051BFA0.field_1B8[m]++;
                    D_0051BFA0.field_1E0[m]++;
                    D_0051BFA0.field_1F0++;
                    D_0051BFA0.field_1F8++;
                    D_0051BFA0.field_238[m]++;
                    break;
                case 2:
                    D_0051BFA0.field_1CC[m]++;
                    D_0051BFA0.field_1E0[m]++;
                    D_0051BFA0.field_1F0++;
                    D_0051BFA0.field_1F8++;
                    D_0051BFA0.field_260[m]++;
                    break;
                default:
                    continue;
                }
                if (m == 3) D_0051BFA0.field_1F4++;
            }
        }
    }
}



#pragma pop
