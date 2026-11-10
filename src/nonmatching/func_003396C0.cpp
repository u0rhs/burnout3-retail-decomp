// NONMATCHING: func_003396C0 -- retail 92 / ours 92 instructions, 6 in changed runs
// a248: logic exact; first block inline via void* t0. Only diff: delay-slot fill at func_00405C60 call (retail move a2;jal;move a3 with sw gp earlier, ours move a2;move a3;jal). tried chained store, const local, param types
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003396C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003396C0;
struct UnkStruct_003396C0_3;
struct UnkStruct_D_004C59A8;
struct UnkStruct_D_004C5A10;
struct UnkStruct_D_004C5A18;
struct UnkStruct_D_004C5A20;
struct UnkStruct_D_004E1D2C;
struct UnkStruct_D_004E2DAC;

struct UnkStruct_D_004E1D2C {
    int field_0;
};

struct UnkStruct_D_004E2DAC {
    UnkStruct_003396C0_3 * field_0;
};

struct UnkStruct_003396C0_3 {
    unsigned char field_0;
};

struct UnkStruct_D_004C5A18 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5A10 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C59A8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5A20 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003396C0 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    unsigned char pad_4[0x100];
    int field_104;
    unsigned char pad_108[0x8];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x8];
    unsigned char field_120;
    unsigned char pad_121[0x447];
    int field_568;
    unsigned char pad_56C[0x8C];
    int field_5F8;
    int field_5FC;
    int field_600;
};

extern UnkStruct_D_004E1D2C D_004E1D2C;
extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_D_004C5A18 D_004C5A18;
extern UnkStruct_D_004C5A10 D_004C5A10;
extern UnkStruct_D_004C59A8 D_004C59A8;
extern UnkStruct_D_004C5A20 D_004C5A20;

extern "C" void SearchForGamesCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void*);  // CGtLobbyPS2DirtySock::SearchForGamesCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*), its address taken
extern "C" void LobbyApiListFree(int, int, int);
extern "C" int func_00405C60(int, int, int, int);
extern "C" void DispListClear(int);
extern "C" void DispListChange(int, int);
extern "C" void TagFieldSetNumber(UnkStruct_003396C0_3 *, int, void *, int);
extern "C" void LobbyApiRequestCB(int, int, UnkStruct_003396C0_3 *, void *, UnkStruct_003396C0 *);

// 0x003396C0
extern "C" void func_003396C0(UnkStruct_003396C0 * self, int p0, int p1, int p2, int p3, int p4)
{
    self->field_5F8 = -1;
    self->field_5FC = p3;
    self->field_600 = p4;
    void *t0 = (void*)self->field_568;
    if (t0 != 0) {
        LobbyApiListFree(self->field_104, D_004E1D2C.field_0, (int)t0);
        self->field_568 = 0;
    }
    int t1 = self->field_104;
    D_004E1D2C.field_0 = 4;
    int r1 = func_00405C60(t1, 4, 0, 0);
    self->field_568 = r1;
    DispListClear(self->field_568);
    DispListChange(self->field_568, 1);
    D_004E2DAC.field_0->field_0 = 0;
    TagFieldSetNumber(D_004E2DAC.field_0, 1024, &D_004C5A18, 0);
    TagFieldSetNumber(D_004E2DAC.field_0, 1024, &D_004C5A10, p0);
    if (p1 != -1) {
        TagFieldSetNumber(D_004E2DAC.field_0, 1024, &D_004C59A8, p1);
    } else {
    }
    if ((p2 & 255) == 1) {
        TagFieldSetNumber(D_004E2DAC.field_0, 1024, &D_004C5A20, 1);
    }
    LobbyApiRequestCB(self->field_104, 0x67736561, D_004E2DAC.field_0, (void *)&SearchForGamesCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, self);
    self->field_110 = 1;
    self->field_111 = 0;
    self->field_112 = 0;
    self->field_120 = 0;
    self->field_114 = 0;
    self->vfunc_14();
}
