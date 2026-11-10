// Hand-written; the lifter refused it (lifter variant matched as-is).

// from build/vt/try_func_0033B4B0_best.cpp
// func_0033B4B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0033B4B0;
struct UnkStruct_0033B4B0_1;
struct UnkStruct_0033B4B0_3;
struct UnkStruct_D_004C5850;
struct UnkStruct_D_004C5910;
struct UnkStruct_D_004C5918;
struct UnkStruct_D_004E2DAC;

struct UnkStruct_0033B4B0_1 {
    unsigned char pad_0[0x38];
    signed char field_38;
};

struct UnkStruct_D_004E2DAC {
    UnkStruct_0033B4B0_3 * field_0;
};

struct UnkStruct_0033B4B0_3 {
    unsigned char field_0;
};

struct UnkStruct_D_004C5850 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5910 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5918 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0033B4B0 {
    unsigned char pad_0[0x104];
    int field_104;
    unsigned char pad_108[0x14];
    unsigned char field_11C;
    unsigned char field_11D;
    unsigned char pad_11E[0x3];
    unsigned char field_121;
    unsigned char pad_122[0x2];
    int field_124;
    unsigned char pad_128[0x4];
    int field_12C;
    int field_130;
    UnkStruct_0033B4B0_1 * field_134;
    unsigned char pad_138[0x30C];
    unsigned char field_444;
    unsigned char pad_445[0x113];
    int field_558;
    int field_55C;
};

extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_D_004C5850 D_004C5850;
extern UnkStruct_D_004C5910 D_004C5910;
extern UnkStruct_D_004C5918 D_004C5918;

extern "C" void GameLeaveCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void*);  // CGtLobbyPS2DirtySock::GameLeaveCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*), its address taken
extern "C" void TagFieldSetString(UnkStruct_0033B4B0_3 *, int, void *, void *);
extern "C" void LobbyApiRequestCB(int, int, UnkStruct_0033B4B0_3 *, void *, UnkStruct_0033B4B0 *);

// 0x0033B4B0
extern "C" int func_0033B4B0(UnkStruct_0033B4B0 * self)
{
    if (self->field_134->field_38 != 0) {
        self->field_130 = 0;
        return 1;
    }
    self->field_130 = (self->field_130 + 1);
    if (self->field_130 >= 1000) {
        D_004E2DAC.field_0->field_0 = 0;
        TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5850, ((char *)self->field_134 + 0x4));
        TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5910, &D_004C5918);
        LobbyApiRequestCB(self->field_104, 0x676C6561, D_004E2DAC.field_0, (void *)&GameLeaveCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, self);
        self->field_11C = 0;
        self->field_11D = 0;
        self->field_12C = -1;
        self->field_134 = 0;
        self->field_121 = 0;
        self->field_124 = 0;
        self->field_130 = 0;
        self->field_444 = 0;
        ((void (*)(int, int))self->field_558)(1, self->field_55C);
        return 0;
    }
    return 0;
}
