// func_00335E90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (a74: lifter draft matches as-is).

// from build/vt\try_func_00335E90_best.cpp
// func_00335E90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00335E90;
struct UnkStruct_00335E90_1;
struct UnkStruct_00335E90_3;
struct UnkStruct_D_004C5850;
struct UnkStruct_D_004C5858;
struct UnkStruct_D_004E2DAC;

struct UnkStruct_D_004E2DAC {
    UnkStruct_00335E90_1 * field_0;
};

struct UnkStruct_00335E90_1 {
    unsigned char field_0;
};

struct UnkStruct_00335E90_3 {
    unsigned char pad_0[0x114];
    int field_114;
};

struct UnkStruct_D_004C5850 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5858 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00335E90 {
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
    unsigned char pad_121[0x13];
    UnkStruct_00335E90_3 * field_134;
};

extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_D_004C5850 D_004C5850;
extern UnkStruct_D_004C5858 D_004C5858;

extern "C" void DefaultCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void*);  // CGtLobbyPS2DirtySock::DefaultCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*), its address taken
extern "C" void TagFieldSetString(UnkStruct_00335E90_1 *, int, void *, void *);
extern "C" void TagFieldSetNumber(UnkStruct_00335E90_1 *, int, void *, int);
extern "C" void LobbyApiRequestCB(int, int, UnkStruct_00335E90_1 *, void *, UnkStruct_00335E90 *);

// 0x00335E90
extern "C" void func_00335E90(UnkStruct_00335E90 * self)
{
    D_004E2DAC.field_0->field_0 = 0;
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5850, ((char *)self->field_134 + 0x4));
    TagFieldSetNumber(D_004E2DAC.field_0, 1024, &D_004C5858, (self->field_134->field_114 & -4097));
    LobbyApiRequestCB(self->field_104, 0x67736574, D_004E2DAC.field_0, (void *)&DefaultCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, self);
    self->field_110 = 1;
    self->field_111 = 0;
    self->field_112 = 0;
    self->field_120 = 0;
    self->field_114 = 0;
    self->vfunc_14();
}
