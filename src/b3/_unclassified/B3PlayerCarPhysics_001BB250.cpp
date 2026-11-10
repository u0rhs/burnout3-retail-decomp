// CB3PlayerCarPhysics::StartCrashing(int,CB3CrashStartInfo*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3PlayerCarPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a139: struct assignment self->field_3540 = *self->field_CC4 of a reconstructed 0x1034-byte record (u_long128 arrays/int[6] pair loops/separate bytes) then tail call to CB3RaceCarPhysics::StartCrashing).

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
struct UnkStruct_001BB250_self {
    unsigned char pad_0[0xCC4];
    UnkStruct_001BB250_rec *field_CC4;
    unsigned char pad_CC8[0x3540 - 0xCC8];
    UnkStruct_001BB250_rec field_3540;
};
struct CB3CrashStartInfo;
extern "C" void StartCrashing__17CB3RaceCarPhysicsFiP17CB3CrashStartInfo(void *, int, CB3CrashStartInfo *);

extern "C" void StartCrashing__19CB3PlayerCarPhysicsFiP17CB3CrashStartInfo(UnkStruct_001BB250_self * self, int p0, CB3CrashStartInfo * p1)
{
    self->field_3540 = *self->field_CC4;
    StartCrashing__17CB3RaceCarPhysicsFiP17CB3CrashStartInfo(self, p0, p1);
}
