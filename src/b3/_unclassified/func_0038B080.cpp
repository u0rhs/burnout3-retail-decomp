// func_0038B080 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (flag D_0064D378 read through D_00522660+0x12AD18 (same object) keeps the sw ahead of the lbu).

// lifter variant 0
// func_0038B080 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3StageLogic;
struct UnkStruct_0038B080_e0;
struct UnkStruct_0038B080_e1;
struct UnkStruct_D_004A4F9C;
struct UnkStruct_D_004A4FA0;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_00522660;
struct UnkStruct_D_006481A0;
struct UnkStruct_D_0064D3A0;
struct UnkStruct__garLapTimes;

struct UnkStruct_D_0064D3A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0038B080_e0 {
    unsigned char pad_0[0x150C];
    void * field_150C;
    unsigned char pad_1510[0x244];
    int field_1754;
    unsigned char pad_1758[0x1078];
};

struct UnkStruct_0038B080_e1 {
    unsigned char pad_0[0x27D0];
};

struct UnkStruct_0038B080_car { unsigned char pad_0[0x113C]; void * field_113C; unsigned char pad_1140[0x244]; int field_1384; unsigned char pad_1388[0x2450]; };
struct UnkStruct_D_00522660 {
    UnkStruct_0038B080_e1 field_0[1];  // [G] element count unknown
    unsigned char pad_27D0[0x1281B0];
    UnkStruct_0038B080_e0 field_12A980[1];  // [G] element count unknown
};

struct UnkStruct_D_006481A0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct__garLapTimes {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004A4F9C {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004A4FA0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3StageLogic {
public:
    void OnWorldPrepared();
};

extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_006481A0 D_006481A0;
extern UnkStruct__garLapTimes _garLapTimes;
extern UnkStruct_D_004A4F9C D_004A4F9C;
extern UnkStruct_D_004A4FA0 D_004A4FA0;
extern UnkStruct_D_004EE040 D_004EE040;

extern "C" void SetNumExtraBoostBarSegments__7CB3BurnFi(void *, int);  // CB3Burn::SetNumExtraBoostBarSegments(int)
extern "C" void func_0014E830(void *, void *, void *, void *);
extern "C" int func_00131CE0(void *);

// 0x0038B080
extern "C" void func_0038B080(CB3StageLogic * self)
{
    self->OnWorldPrepared();
    func_0014E830(&D_006481A0, &_garLapTimes, &D_004A4F9C, &D_004A4FA0);
    for (int i = 0; (i < D_0064D3A0.field_0); i++) {
        char * p = (char *)&D_00522660 + i * 0x27D0 + 0x12AD50;
        SetNumExtraBoostBarSegments__7CB3BurnFi(p + 0x118C, 3);
        if (func_00131CE0(&D_004EE040) != 0) {
            *(void **)(p + 0x113C) = &_garLapTimes;
            continue;
        }
        *(void **)(p + 0x113C) = 0;
        // [C] D_0064D378 == D_00522660 + 0x12AD18 (same object): read through it so the 0x113C store
        // may alias the flag and stays ahead of the lbu, as in retail.
        if (*((unsigned char *)&D_00522660 + 0x12AD18) == 0) {
            *(int *)(p + 0x1384) = 0;
        }
    }
}
