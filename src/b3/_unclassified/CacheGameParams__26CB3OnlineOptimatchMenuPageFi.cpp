// Hand-written; the lifter refused it (a154: int off = p0*80; (off + (int)self) fixes addu operand order).


// CacheGameParams__26CB3OnlineOptimatchMenuPageFi -- [L] DNAT: CB3OnlineOptimatchMenuPage::CacheGameParams(int) (research/proto/new_names.csv, high)
struct UnkStruct_0037B5C0_b {
    int field_0;
    unsigned char pad_4[4];
    int field_8;
};
struct UnkStruct_0037B5C0_e {
    unsigned char pad_0[0x60];
    char field_60[0x20];
    unsigned long field_80;
    unsigned char pad_88[8];
    UnkStruct_0037B5C0_b field_90;
    unsigned char pad_9C[8];
    int field_A4;
    unsigned char pad_A8[8];
};
struct UnkStruct_0037B5C0 {
    unsigned char pad_0[8];
    unsigned long field_8;
    int field_10;
    int field_14;
    char field_18[0x20];
    int field_38;
    void *field_3C;
    void *field_40;
    int field_44;
    int field_48;
    int field_4C;
    void *field_50;
    void *field_54;
    void *field_58;
    void *field_5C;
    unsigned char pad_60[0x1864];
    int field_18C4;
    unsigned char pad_18C8[0x58];
    int field_1920;
};
struct UnkStruct_0037B5C0_g { int field_0; int field_4; unsigned char pad_8[8]; };
struct UnkStruct_0037B5C0_n { unsigned char pad_0[0x10]; };
extern UnkStruct_0037B5C0_g D_01E90130;
extern UnkStruct_0037B5C0_n D_01E32AE0;
extern UnkStruct_0037B5C0_n D_004C9218;
extern "C" char *strncpy(char *, const char *, unsigned int);
extern "C" void SetGameID__23CGtNetworkPlayerManagerFi(void *, int);
extern "C" bool PlayerListChangedCallback__17CB3NetworkManagerFiPv(int, void *);
extern "C" int PlayerBootedCallback__17CB3NetworkManagerF16ELobbyKickReasonPv(int, void *);

// 0x0037B5C0
extern "C" bool CacheGameParams__26CB3OnlineOptimatchMenuPageFi(UnkStruct_0037B5C0 * self, int p0)
{
    if (p0 >= self->field_1920) return false;
    int off = p0 * 80;
    UnkStruct_0037B5C0_e *e = (UnkStruct_0037B5C0_e *)(off + (int)self);
    UnkStruct_0037B5C0_b * const b = &e->field_90;
    self->field_18C4 = e->field_A4;
    self->field_8 = e->field_80;
    self->field_10 = b->field_0;
    self->field_14 = b->field_8;
    strncpy(self->field_18, e->field_60, 0x20);
    self->field_38 = b->field_0;
    SetGameID__23CGtNetworkPlayerManagerFi(&D_01E32AE0, self->field_10);
    self->field_44 = D_01E90130.field_0;
    self->field_48 = D_01E90130.field_4;
    self->field_4C = 0;
    self->field_3C = e->field_60;
    self->field_40 = &D_004C9218;
    self->field_50 = (void *)PlayerListChangedCallback__17CB3NetworkManagerFiPv;
    self->field_54 = &D_01E32AE0;
    self->field_58 = (void *)PlayerBootedCallback__17CB3NetworkManagerF16ELobbyKickReasonPv;
    self->field_5C = &D_01E32AE0;
    return true;
}
