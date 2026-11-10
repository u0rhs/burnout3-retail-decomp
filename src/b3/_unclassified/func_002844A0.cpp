// func_002844A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (two CGtSoundVoiceParams-shaped locals and two vector temps (decl order pA,pB,vA,vB); ref local to params.field_18 assigned in the test (as func_002842A0)).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CGtSoundVoiceParams;

class CGtSoundVirtualVoice;
class CGtSoundVoiceManager;
struct UnkStruct_002844A0;
struct UnkStruct_002844A0_1;
struct UnkStruct_002844A0_3;
struct UnkStruct_002844A0_4;
struct UnkStruct_002844A0_5;
struct UnkStruct_D_004BF230;
struct UnkStruct_D_004BF238;
struct UnkStruct_D_0064F7E0;
struct UnkStruct_D_01E75648;

class CGtSoundVoiceManager {
public:
    int TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtSoundVirtualVoice {
public:
    void IgnoreGlobalPitch();
};

struct UnkStruct_002844A0_p {
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0xC];
    int field_18;
    float field_1C;
    unsigned char pad_20[0x4];
    float field_24;
    unsigned char pad_28[0x1C];
    unsigned char field_44;
    unsigned char field_45;
    unsigned char pad_46[0xA];
};
struct UnkStruct_002844A0_v {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};
struct UnkStruct_002844A0_1 {
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0x4];
    float field_10;
    float field_14;
    float field_18;
    unsigned char pad_1C[0x4];
    float field_20;
    float field_24;
    float field_28;
    unsigned char pad_2C[0xC];
    int field_38;
    float field_3C;
    unsigned char pad_40[0x4];
    float field_44;
    unsigned char pad_48[0x1C];
    unsigned char field_64;
    unsigned char field_65;
    unsigned char pad_66[0xA];
    float field_70;
    float field_74;
    float field_78;
    unsigned char pad_7C[0xC];
    int field_88;
    float field_8C;
    unsigned char pad_90[0x4];
    float field_94;
    unsigned char pad_98[0x1C];
    unsigned char field_B4;
    unsigned char field_B5;
    unsigned char pad_B6[0xA];
};

struct UnkStruct_D_0064F7E0 {
    UnkStruct_002844A0_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_002844A0_3 {
    unsigned char pad_0[0x204];
    UnkStruct_002844A0_4 * field_204;
};

struct UnkStruct_002844A0_4 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
};

struct UnkStruct_002844A0_5 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
};

struct UnkStruct_D_004BF230 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E75648 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BF238 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_002844A0 {
    unsigned char pad_0[0x8];
    CGtSoundVirtualVoice * field_8;
    CGtSoundVirtualVoice * field_C;
    unsigned char pad_10[0xC];
    int field_1C;
    unsigned char pad_20[0x28];
    int field_48;
};

extern UnkStruct_D_0064F7E0 D_0064F7E0;
extern UnkStruct_D_004BF230 D_004BF230;
extern UnkStruct_D_01E75648 D_01E75648;
extern CGtSoundVoiceManager D_01E7569C;
extern UnkStruct_D_004BF238 D_004BF238;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()
extern "C" int FindWave__19CGtSoundBankManagerCFRCUlb(void *, const void *, bool);  // CGtSoundBankManager::FindWave(const unsigned long&,bool) const
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);  // CGtSoundWave::CalcFrequency() const

// 0x002844A0
extern "C" void func_002844A0(UnkStruct_002844A0 * self)
{
    UnkStruct_002844A0_p pA;
    UnkStruct_002844A0_p pB;
    UnkStruct_002844A0_v vA;
    UnkStruct_002844A0_v vB;
    if (self->field_8 == 0) {
        Construct__19CGtSoundVoiceParamsFv(&pA);
        int & wpA = pA.field_18;
        if ((wpA = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &D_004BF230, 0)) != 0) {
            pA.field_1C = 1.0f;
            pA.field_24 = CalcFrequency__12CGtSoundWaveCFv((void *)wpA);
            UnkStruct_002844A0_3 * t = D_0064F7E0.field_0;
            pA.field_44 = 1;
            pA.field_45 = 1;
            *(u_long128 *)&vA = t->field_204->field_30;
            pA.field_0 = vA.field_0;
            pA.field_4 = vA.field_4;
            pA.field_8 = vA.field_8;
            self->field_8 = (CGtSoundVirtualVoice *)D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&pA);
            if (self->field_8 != 0) {
                self->field_8->IgnoreGlobalPitch();
            }
        }
        self->field_1C = 0;
    }
    if (self->field_C == 0) {
        Construct__19CGtSoundVoiceParamsFv(&pB);
        int & wpB = pB.field_18;
        if ((wpB = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &D_004BF238, 0)) != 0) {
            pB.field_1C = 1.0f;
            pB.field_24 = CalcFrequency__12CGtSoundWaveCFv((void *)wpB);
            UnkStruct_002844A0_3 * t = D_0064F7E0.field_0;
            pB.field_44 = 1;
            pB.field_45 = 1;
            *(u_long128 *)&vB = t->field_204->field_30;
            pB.field_0 = vB.field_0;
            pB.field_4 = vB.field_4;
            pB.field_8 = vB.field_8;
            self->field_C = (CGtSoundVirtualVoice *)D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&pB);
            if (self->field_C != 0) {
                self->field_C->IgnoreGlobalPitch();
            }
        }
        self->field_48 = 3600;
    }
}
