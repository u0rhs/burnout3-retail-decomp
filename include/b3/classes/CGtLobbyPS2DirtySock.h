// CGtLobbyPS2DirtySock -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTLOBBYPS2DIRTYSOCK_H
#define B3_CLASSES_CGTLOBBYPS2DIRTYSOCK_H

class CGtLobbyPS2DirtySock;
struct UnkStruct_003380D0_e0;
struct UnkStruct_00338D60_3;

struct UnkStruct_003380D0_e0 {
    unsigned char pad_0[0x10];
};

struct UnkStruct_00338D60_3 {
    unsigned char pad_0[0x114];
    int field_114;
};

class CGtLobbyPS2DirtySock {
public:
    unsigned char AmIInGame();
    void BroadcastLaunch();
    int CheckGameStillExists();
    void Construct(int p0);
    int ConvertDirtySockError(int);
    void Destruct();
    void * GetAlternateAccountName(int p0) const;
    int GetCurrentLobbyName();
    int GetGameID();
    int GetLastError();
    int GetMemoryRequirements(int p0);
    void GetNumPlayersInLobby();
    int GetNumberRankRecords();
    void * GetSessionKey();
    bool HasLaunched();
    unsigned char IsLoggedIntoLobby() const;
    void LaunchComplete();
    void LostAccountName(char* p0);
    void LostPassword(char* p0);
    int SendChatMessage(char* p0);

    UnkStruct_003380D0_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_10[0xF4];
    int field_104;
    int field_108;
    unsigned char pad_10C[0x4];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x4];
    unsigned char field_11C;
    unsigned char field_11D;
    unsigned char field_11E;
    unsigned char pad_11F[0x1];
    unsigned char field_120;
    unsigned char field_121;
    unsigned char pad_122[0x2];
    int field_124;
    unsigned char pad_128[0x4];
    int field_12C;
    int field_130;
    UnkStruct_00338D60_3 * field_134;
    unsigned char pad_138[0x124];
    int field_25C;
    unsigned char pad_260[0x4];
    unsigned char field_264;
    unsigned char pad_265[0x1DF];
    unsigned char field_444;
    unsigned char pad_445[0x113];
    int field_558;
    int field_55C;
    int field_560;
    int field_564;
    int field_568;
    int field_56C;
    unsigned char pad_570[0x9C];
    int field_60C;
    int field_610;
    int field_614;
    int field_618;
    void * field_61C;
    unsigned char pad_620[0x14];
    void * field_634;
    int field_638;
};

#endif
