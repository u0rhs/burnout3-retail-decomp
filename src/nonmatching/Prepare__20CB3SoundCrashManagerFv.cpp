// NONMATCHING: Prepare__20CB3SoundCrashManagerFv -- retail 830 / ours 827 instructions, 3 in changed runs
// a161: 827/830 instrs, 3 differ. All vdb tables/ stages exact; missing retail's separate 'li v0,1; b exit' block at 0x28261C (a lone return-true block reached by b from the out-of-line stage-3 OK block, while the dispatch default jumps to 0x282620 with the li copied into its delay slot). Dispatch must be an if-chain (3,2,then 0x18||1||0x17 positive) with 'goto RET1' else-arm; any variant that keeps RET1 reachable loses the dispatch regs (v1).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

class CGtSoundBank;
class CGtSoundVirtualVoice;
struct UnkStruct_00281C30_q { unsigned long l; unsigned char pad_8[8]; };
struct UnkStruct_00281C30_s { unsigned char pad_0[0x40]; };
struct UnkStruct_00281C30_b { unsigned char pad_0[0x10]; };
struct UnkStruct_00281C30_c { unsigned char c; unsigned char pad_1[0xF]; };
struct UnkStruct_00281C30_i { int i; unsigned char pad_4[0xC]; };
struct UnkStruct_00281C30_f { float f; unsigned char pad_4[0xC]; };
class CGtSoundBankManager {
public:
    int FindWave(const unsigned long &, bool) const;
    int LoadBank(const char *, bool, bool, int);
    unsigned char pad_0[0x10];
};
class CB3SoundCrashManager {
public:
    bool Prepare();

    int field_0;
    unsigned char pad_4[0xC];
    UnkStruct_00281C30_s field_10[6];
    unsigned char pad_190[0x20];
    float field_1B0;
    float field_1B4;
    float field_1B8;
    float field_1BC;
    unsigned char pad_1C0[0x8];
    float field_1C8;
    float field_1CC;
    float field_1D0;
    float field_1D4;
    unsigned char pad_1D8[0x8];
    float field_1E0;
    float field_1E4;
    float field_1E8;
    float field_1EC;
    unsigned char pad_1F0[0x8];
    float field_1F8;
    float field_1FC;
    float field_200;
    float field_204;
    unsigned char pad_208[0x8];
    float field_210;
    float field_214;
    float field_218;
    float field_21C;
    unsigned char pad_220[0x8];
    float field_228;
    float field_22C;
    float field_230;
    float field_234;
    unsigned char pad_238[0x8];
    float field_240;
    float field_244;
    float field_248;
    float field_24C;
    unsigned char pad_250[0x80];
    char field_2D0[0x100];
    unsigned char pad_3D0[0xA0];
    char field_470[0x40];
    char field_4B0[0x32];
    char field_4E2[0x32];
    unsigned char field_514[8];
    unsigned char pad_51C[0x4];
    unsigned int field_520;
    unsigned int field_524;
    unsigned char pad_528[0x29C];
    int field_7C4;
    int field_7C8;
    unsigned char pad_7CC[0x78];
    int field_844;
    int field_848;
    int field_84C;
    unsigned char pad_850[0x4];
    int field_854;
    int field_858;
    int field_85C;
    CGtSoundVirtualVoice * field_860;
    CGtSoundVirtualVoice * field_864;
    CGtSoundVirtualVoice * field_868;
    CGtSoundVirtualVoice * field_86C;
    CGtSoundVirtualVoice * field_870;
    CGtSoundVirtualVoice * field_874;
    CGtSoundVirtualVoice * field_878;
    CGtSoundVirtualVoice * field_87C;
    CGtSoundBank * field_880;
    void * field_884;
    void * field_888;
    unsigned char pad_88C[0x4];
    unsigned char field_890;
    unsigned char pad_891[0x3];
    float field_894;
    int field_898;
    unsigned char pad_89C[0x10];
    int field_8AC;
    unsigned char pad_8B0[0x12];
    unsigned char field_8C2;
    unsigned char field_8C3;
    unsigned char field_8C4;
    unsigned char field_8C5;
    unsigned char field_8C6;
    unsigned char field_8C7;
    unsigned char pad_8C8[0x2];
    unsigned char field_8CA;
    unsigned char field_8CB;
    unsigned char field_8CC;
    unsigned char field_8CD;
    unsigned char field_8CE;
    unsigned char field_8CF;
    unsigned char pad_8D0[0x6];
    unsigned char field_8D6;
    unsigned char field_8D7;
    unsigned char field_8D8;
    unsigned char pad_8D9[0x2];
    unsigned char field_8DB;
    unsigned char field_8DC;
    unsigned char field_8DD;
    unsigned char field_8DE;
    unsigned char field_8DF;
    unsigned char pad_8E0[0x1];
    unsigned char field_8E1;
    unsigned char field_8E2;
    unsigned char field_8E3;
    unsigned char field_8E4;
    unsigned char pad_8E5[0x3];
    int field_8E8;
    unsigned char pad_8EC[0x30];
    int field_91C[4];
    int field_92C[4];
    unsigned char field_93C;
    unsigned char field_93D;
    unsigned char field_93E;
};
extern int kpcPropDirBarrier;
extern int kpcPropDirCardBox;
extern int kpcPropDirCone;
extern int kpcPropDirMetalBarrier;
extern int kpcPropDirMetalBox;
extern int kpcPropDirSignPost;
extern int kpcPropDirWoodBox;
extern int mpToolBase__Q27GtComms16CGtCommsToolBase;
extern char D_004BF118[];
extern char D_004BF128[];
extern char D_004BF138[];
extern char D_004BF148[];
extern char D_004BF0F0[];
extern char D_004BF160[];
extern char D_004BF178[];
extern char D_004BF180[];
extern char D_004BF190[];
extern char D_004BED60[];
extern char D_004BED28[];
extern char D_004BED30[];
extern char D_004BED38[];
extern char D_004BED40[];
extern UnkStruct_00281C30_q D_0064D370;
extern UnkStruct_00281C30_b D_004EE040, D_01E774E0;
extern CGtSoundBankManager D_01E75648;
extern UnkStruct_00281C30_c D_00665EA0;
extern UnkStruct_00281C30_i D_0064D3A0;
extern UnkStruct_00281C30_f D_00522680;
extern unsigned long kB3P1HornWaveID[], kB3CreakWaveID[], kB3AtmosWaveID[], kB3FireWaveID[], kB3HeartbeatWaveID[], kB3GlassDebriWaveID[];
extern char * D_004E1AC4;
extern "C" void AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(int, void *, void *, int, char *, int, float, float, int);
extern "C" void RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(int, void *);
extern "C" int sprintf(char *, const char *, ...);
extern "C" char * strcpy(char *, const char *);
extern "C" char * strcat(char *, const char *);
extern "C" char * strncat(char *, const char *, int);
extern "C" void func_0021AB40(unsigned long, char *);
extern "C" void func_0021ADF0(unsigned long, char *);
extern "C" int func_00131E40(void *);
extern "C" void func_00281890(void *);
extern "C" int func_00385FD0(void *);
extern "C" int func_003865A0(void *, char *, int, int, int, int);
extern "C" void GenerateVariantPath__13CGtSoundUtilsFPCcPCcPCcPcQ213CGtSoundUtils17ESoundVariantMode(const char *, const char *, const char *, char *, int);
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);
extern "C" void Stop__20CGtSoundVirtualVoiceFv(void *);
extern "C" int IsPlaying__20CGtSoundVirtualVoiceFv(void *);
extern "C" int Prepare__14CB3SoundScrapeFv(void *);
extern "C" int Release__14CGtSoundStreamFv(void *);
extern "C" void Stop__14CGtSoundStreamFv(void *);
extern "C" void * AllocStream__21CGtSoundStreamManagerFb(void *, bool);
extern "C" int GetStreamsPreparing__21CGtSoundStreamManagerFv(void *);

// 0x00281C30
bool CB3SoundCrashManager::Prepare()
{
    char b140[0x10];
    char b130[0x10];
    char b30[0x100];
    int i;
    unsigned long s1;
    int st = field_0;
    if (st == 3) goto S3;
    if (st == 2) goto S2;
    if (st == 0x18 || st == 1 || st == 0x17) {
        if (field_880 == 0) goto LOADBANK;
    L94:
        if (field_8D8 != 0) goto UNREG;
    LCA0:
        func_0021AB40(D_0064D370.l, b140);
        sprintf(field_470, D_004BF0F0, b140);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1B4, &D_004BF118, kpcPropDirCone, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1B0, &D_004BF128, kpcPropDirCone, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1BC, &D_004BF138, kpcPropDirCone, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1B8, &D_004BF148, kpcPropDirCone, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_244, &D_004BF118, kpcPropDirCardBox, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_240, &D_004BF128, kpcPropDirCardBox, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_24C, &D_004BF138, kpcPropDirCardBox, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_248, &D_004BF148, kpcPropDirCardBox, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1E4, &D_004BF118, kpcPropDirMetalBox, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1E0, &D_004BF128, kpcPropDirMetalBox, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1EC, &D_004BF138, kpcPropDirMetalBox, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1E8, &D_004BF148, kpcPropDirMetalBox, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1CC, &D_004BF118, kpcPropDirWoodBox, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1C8, &D_004BF128, kpcPropDirWoodBox, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1D4, &D_004BF138, kpcPropDirWoodBox, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1D0, &D_004BF148, kpcPropDirWoodBox, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_22C, &D_004BF118, kpcPropDirSignPost, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_228, &D_004BF128, kpcPropDirSignPost, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_234, &D_004BF138, kpcPropDirSignPost, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_230, &D_004BF148, kpcPropDirSignPost, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1FC, &D_004BF118, kpcPropDirBarrier, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1F8, &D_004BF128, kpcPropDirBarrier, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_204, &D_004BF138, kpcPropDirBarrier, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_200, &D_004BF148, kpcPropDirBarrier, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_214, &D_004BF118, kpcPropDirMetalBarrier, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_210, &D_004BF128, kpcPropDirMetalBarrier, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_21C, &D_004BF138, kpcPropDirMetalBarrier, field_470, 0, 0.0f, 0.0f, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_218, &D_004BF148, kpcPropDirMetalBarrier, field_470, 0, 0.0f, 0.0f, 0);
        field_8D8 = 1;
        func_00281890(this);
        field_524 = 0x2B9D6F8;
        field_520 = 0xFD462907;
        field_524 = 0x24B04;
        field_520 = 0xFFFDB4FB;
        field_8C5 = 0;
        field_7C4 = 0;
        field_8C6 = 0;
        field_7C8 = 0;
        field_8C7 = 0;
        field_8CB = 0;
        field_8CC = 0;
        field_8CD = 0;
        field_8C3 = 0;
        field_8C4 = 0;
        field_8CE = 0;
        field_8CF = 0;
        field_8C2 = 0;
        field_8CA = 0;
        i = 0;
        do {
            field_514[i] = 0;
            i++;
        } while (i < 8);
        field_84C = D_01E75648.FindWave(kB3P1HornWaveID[0], false);
        field_844 = FindWave__12CGtSoundBankCFRCUlb(field_880, kB3CreakWaveID, false);
        field_848 = FindWave__12CGtSoundBankCFRCUlb(field_880, kB3AtmosWaveID, false);
        field_858 = FindWave__12CGtSoundBankCFRCUlb(field_880, kB3FireWaveID, false);
        field_85C = FindWave__12CGtSoundBankCFRCUlb(field_880, kB3HeartbeatWaveID, false);
        if (field_868 != 0) Stop__20CGtSoundVirtualVoiceFv(field_868);
        if (field_860 != 0) Stop__20CGtSoundVirtualVoiceFv(field_860);
        if (field_870 != 0) Stop__20CGtSoundVirtualVoiceFv(field_870);
        if (field_86C != 0) Stop__20CGtSoundVirtualVoiceFv(field_86C);
        if (field_874 != 0 && field_8AC == *(int *)((char *)field_874 + 0xC) && IsPlaying__20CGtSoundVirtualVoiceFv(field_874) != 0) {
            Stop__20CGtSoundVirtualVoiceFv(field_874);
        }
        if (field_878 != 0) Stop__20CGtSoundVirtualVoiceFv(field_878);
        if (field_87C != 0) Stop__20CGtSoundVirtualVoiceFv(field_87C);
        field_874 = 0;
        i = 0;
        field_868 = 0;
        field_860 = 0;
        field_870 = 0;
        field_86C = 0;
        field_878 = 0;
        field_87C = 0;
        field_8D6 = 0;
        field_8D7 = 0;
        do {
            Prepare__14CB3SoundScrapeFv(&field_10[i]);
            i++;
        } while (i < 6);
        field_854 = FindWave__12CGtSoundBankCFRCUlb(field_880, kB3GlassDebriWaveID, true);
        if (field_864 != 0) Stop__20CGtSoundVirtualVoiceFv(field_864);
        field_864 = 0;
        if (D_00665EA0.c != 0) goto Z884;
        if (D_0064D3A0.i == 1) {
            if (field_884 == 0) goto A884;
            Release__14CGtSoundStreamFv(field_884);
        L474:
            {
                unsigned char c = field_890;
                field_890 = c + 1;
                sprintf(field_4B0, D_004BED60, c % 20 + 1);
            }
            field_8DE = 0;
            field_8DD = 0;
        }
    L24A8:
        field_8DC = 0;
        field_8DB = 0;
        field_8E2 = 0;
        field_8E3 = 0;
        field_93E = 0;
        field_890 = field_890 + 1;
        field_8DF = 0;
        field_894 = D_00522680.f;
        field_898 = 0;
        field_8E8 = 0;
        field_8E4 = 0;
        field_93C = 0;
        field_93D = 0;
        i = 0;
        do {
            field_91C[i] = 0;
            field_92C[i] = 0;
            i++;
        } while (i < 4);
        field_0 = 2;
    } else {
        goto RET1;
    }
    S2:
    {
        if (func_00131E40(&D_004EE040) == 0) goto R17;
        if (field_888 == 0) goto A888;
        Stop__14CGtSoundStreamFv(field_888);
        Release__14CGtSoundStreamFv(field_888);
    L544:
        s1 = D_0064D370.l;
        strcpy(field_4E2, D_004BED28);
        func_0021ADF0(s1, b130);
        strncat(field_4E2, b130, 2);
        strcat(field_4E2, D_004BED30);
        strncat(field_4E2, b130 + 3, 2);
        strcat(field_4E2, D_004BED38);
        strncat(field_4E2, D_004BED40, 2);
        strcat(field_4E2, D_004BED30);
        strcat(field_4E2, D_004E1AC4);
        field_0 = 3;
    }
    S3:
    {
        if (func_00385FD0(field_888) == 0) goto GSP;
    L25F0:
        if (func_003865A0(field_888, field_4E2, 0, 0, 0, 4) != 0) goto OK3;
        return false;
    }
LOADBANK:
    if (field_8E1 == 0) {
        if (func_00131E40(&D_004EE040) != 0) {
            strcpy(field_2D0, D_004BF160);
        } else {
            GenerateVariantPath__13CGtSoundUtilsFPCcPCcPCcPcQ213CGtSoundUtils17ESoundVariantMode(D_004BF178, D_004BF180, D_004BF190, b30, 2);
            strcpy(field_2D0, b30);
        }
    }
    field_880 = (CGtSoundBank *)D_01E75648.LoadBank(field_2D0, true, true, 0x2000);
    if (field_880 == 0) {
        field_8E1 = 1;
        return false;
    }
    field_8E1 = 0;
    goto L94;
UNREG:
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1B4);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1B0);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1BC);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1B8);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1CC);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1C8);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1D4);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1D0);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1E4);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1E0);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1EC);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1E8);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1FC);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_1F8);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_204);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_200);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_214);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_210);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_21C);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_218);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_22C);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_228);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_234);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_230);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_244);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_240);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_24C);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase + 16, &field_248);
    field_8D8 = 0;
    goto LCA0;
A884:
    field_884 = AllocStream__21CGtSoundStreamManagerFb(&D_01E774E0, false);
    goto L474;
Z884:
    field_884 = 0;
    goto L24A8;
A888:
    field_888 = AllocStream__21CGtSoundStreamManagerFb(&D_01E774E0, false);
    goto L544;
R17:
    field_0 = 0x17;
    return true;
GSP:
    if (GetStreamsPreparing__21CGtSoundStreamManagerFv(&D_01E774E0) == 0) goto L25F0;
    return false;
OK3:
    field_8E2 = 1;
    field_0 = 0x17;
RET1:
    return true;
}
