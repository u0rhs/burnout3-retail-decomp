// CB3PlayerCarPhysics::StopCrashing() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PlayerCarPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a139: restore *self->field_CC4 = self->field_3540 (0x1034-byte record, same as StartCrashing), then goto-entry loop field_4B2[i]==3 -> 4).

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_001BB250_rec {
    u_long128 field_0[24];
    u_long128 field_180[24];
    u_long128 field_300[25];
    u_long128 field_490;
    int field_4A0;
    float field_4A4;
    float field_4A8;
    signed char field_4AC[6];
    signed char field_4B2[6];
    int field_4B8[6];
    int field_4D0[6];
    int field_4E8[6];
    u_long128 field_500[32];
    u_long128 field_700[32];
    u_long128 field_900[48];
    u_long128 field_C00[48];
    int field_F00[12];
    int field_F30[12];
    int field_F60[6];
    int field_F78[6];
    int field_F90[6];
    int field_FA8[6];
    int field_FC0[6];
    int field_FD8[6];
    u_long128 field_FF0;
    u_long128 field_1000;
    float field_1010;
    unsigned char field_1014;
    unsigned char field_1015;
    unsigned char field_1016;
    unsigned char field_1017;
    unsigned char field_1018;
    unsigned char field_1019;
    unsigned char field_101A;
    unsigned char field_101B;
    signed char field_101C[6];
    unsigned char field_1022;
    unsigned char field_1023;
    int field_1024;
    int field_1028;
    int field_102C;
    unsigned char field_1030;
    unsigned char field_1031;
    unsigned char field_1032;
    unsigned char field_1033;
};
struct UnkStruct_001BAD40_a { unsigned char pad_0[0x19AE]; unsigned char field_19AE; };
struct UnkStruct_001BAD40_c { unsigned char pad_0[0xC]; signed char field_C; };
struct UnkStruct_001BAD40_b { unsigned char pad_0[0x40]; UnkStruct_001BAD40_c *field_40; };
struct UnkStruct_001BAD40_self {
    unsigned char pad_0[0xCC0];
    UnkStruct_001BAD40_b *field_CC0;
    UnkStruct_001BB250_rec *field_CC4;
    unsigned char pad_CC8[0x1580 - 0xCC8];
    UnkStruct_001BAD40_a *field_1580;
    unsigned char pad_1584[0x3540 - 0x1584];
    UnkStruct_001BB250_rec field_3540;
    unsigned char pad_4580[0x4585 - 0x4580];
    unsigned char field_4585;
};
struct UnkStruct_D_00522660 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E75640 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_01E75640 D_01E75640;
extern "C" void StopCrashing__17CB3RaceCarPhysicsFv(void *);
extern "C" void SetSlowMo__8CGtTimerFi(void *, int);
extern "C" void SetMasterPitchScalar__15CB3SoundManagerFf(void *, float);

extern "C" void StopCrashing__19CB3PlayerCarPhysicsFv(UnkStruct_001BAD40_self * self)
{
    int i;
    if (self->field_1580->field_19AE == 0) return;
    StopCrashing__17CB3RaceCarPhysicsFv(self);
    SetSlowMo__8CGtTimerFi(&D_00522660, 1);
    SetMasterPitchScalar__15CB3SoundManagerFf(&D_01E75640, 1.0f);
    *self->field_CC4 = self->field_3540;
    i = 0;
    goto test;
body:
    if (self->field_CC4->field_4B2[i] == 3) self->field_CC4->field_4B2[i] = 4;
    i++;
test:
    if (i < self->field_CC0->field_40->field_C) goto body;
    self->field_4585 = 0;
}
