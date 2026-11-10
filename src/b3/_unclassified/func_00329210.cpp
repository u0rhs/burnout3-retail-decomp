// func_00329210 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (sig1: func_00235D90 takes only the manager (writes a1 before reading); local struct fields stored in offset order).



// [L] DNAT: CB3OnlineJoinGamePage::JoinGame(int) (research/proto/new_names.csv, low)
class CGtNetworkPlayerManager;
struct UnkStruct_00329210;
struct UnkStruct_00329210_3;
struct UnkStruct_00329210_e1;
struct UnkStruct_D_01E3CD44;
struct UnkStruct_D_01E90130;

class CGtNetworkPlayerManager {
public:
    void SetGameID(int);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00329210_e1 {  // [G] one 0x48-byte row of the table at self+0x1870; fields are named by their offset from self
    unsigned char pad_0[0x1870];
    unsigned long field_1870;
    unsigned char pad_1878[0x8];
    char field_1880[0x20];
    int field_18A0;
    unsigned char pad_18A4[0x8];
    int field_18AC;
};

struct UnkStruct_00329210_3 {
    int field_0;
    char * field_4;
    void * field_8;
    int field_C;
    int field_10;
    int field_14;
    void * field_18;
    void * field_1C;
    void * field_20;
    void * field_24;
    unsigned char pad_28[0x8];
};
struct UnkStruct_D_01E90130 {
    int field_0;
    int field_4;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3CD44 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38(UnkStruct_00329210_3 *);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00329210 {
    unsigned char pad_0[0x8];
    unsigned long field_8;
    char field_10[0x20];
    int field_30;
    int field_34;
    unsigned char pad_38[0x156C];
    unsigned char field_15A4[0x2CC];
    unsigned char pad_1870[0x298];
    int field_1B08;
};

extern UnkStruct_D_01E90130 D_01E90130;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern CGtNetworkPlayerManager D_01E32AE0;

extern "C" char * strcpy(char *, const char *);
extern "C" bool PlayerListChangedCallback__17CB3NetworkManagerFiPv(int, void*);  // CB3NetworkManager::PlayerListChangedCallback(int,void*), its address taken
extern "C" int PlayerBootedCallback__17CB3NetworkManagerF16ELobbyKickReasonPv(int, void*);  // CB3NetworkManager::PlayerBootedCallback(ELobbyKickReason,void*), its address taken
extern "C" void ClearAllPlayers__23CGtNetworkPlayerManagerFv(void *);
extern "C" void func_00235D90(void *);
extern "C" void func_0022D3F0();

// 0x00329210
extern "C" int func_00329210(UnkStruct_00329210 * self, int p0)
{
    UnkStruct_00329210_3 local;
    if (p0 >= self->field_1B08) {
        return 0;
    }
    int off = (p0 * 9) << 3;
    UnkStruct_00329210_e1 * e = (UnkStruct_00329210_e1 *)(off + (int)self);
    int * const pc = &e->field_18AC;
    self->field_8 = e->field_1870;
    self->field_30 = *pc;
    self->field_34 = e->field_18A0;
    strcpy(self->field_10, e->field_1880);
    ClearAllPlayers__23CGtNetworkPlayerManagerFv(&D_01E32AE0);
    local.field_0 = *pc;
    D_01E32AE0.SetGameID(self->field_30);
    local.field_4 = e->field_1880;
    local.field_8 = self->field_15A4;
    local.field_C = D_01E90130.field_0;
    local.field_10 = D_01E90130.field_4;
    local.field_14 = 0;
    local.field_18 = (void *)&PlayerListChangedCallback__17CB3NetworkManagerFiPv;
    local.field_1C = &D_01E32AE0;
    local.field_20 = (void *)&PlayerBootedCallback__17CB3NetworkManagerF16ELobbyKickReasonPv;
    local.field_24 = &D_01E32AE0;
    func_00235D90(&D_01E32AE0);
    func_0022D3F0();
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_38(&local);
    return 1;
}
