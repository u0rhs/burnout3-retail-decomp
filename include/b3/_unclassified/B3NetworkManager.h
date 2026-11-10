// CB3NetworkManager -- declarations only, as call targets. Folder: _unclassified/ (docs/conventions.md: the E map
// names the file B3NetworkManager.cpp, but no evidence of its Area yet).
#ifndef B3_B3NETWORKMANAGER_H
#define B3_B3NETWORKMANAGER_H

// [L] a player record as func_0031A5D0 uses it: +0x4 is passed to a PrintString-style formatter.
struct UnkStruct_PlayerRecord {
    int field_0;
    unsigned short field_4[1];  // [G] the player's name (length unknown)
};

class CB3NetworkManager {
public:
    // 0x0026DDC0 (name: config/symbol_addrs_b3names.txt; E map: B3NetworkManager.cpp). Return type is not
    // in the mangled name; a record pointer here [L].
    UnkStruct_PlayerRecord *GetPlayerRecordByID(int);

    unsigned char pad0[0x28];
    int field_28;  // [C] loop bound in func_0031A5D0 (number of players [G])
    // Padded past the small-data threshold: retail addresses the instance (D_01E32AE0) absolutely (N51).
    unsigned char pad1[0x100];
};

#endif
