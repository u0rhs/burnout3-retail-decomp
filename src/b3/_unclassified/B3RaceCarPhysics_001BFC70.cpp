// CB3RaceCarPhysics::StartCrashing(int,CB3CrashStartInfo*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCarPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a94 match; lead: parameter typed CB3CrashStartInfo* so the symbol is retail's).

struct UnkStruct_StartCrashing_row {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int);
};
struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x28E00];
    UnkStruct_StartCrashing_row field_28E00[1];
};
struct UnkStruct_D_0064CE40 {
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_004F50C0 {
    unsigned char pad_0[0x10];
};
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_0064CE40 D_0064CE40;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_004F50C0 D_004F50C0;
extern char D_004B7D48[];
extern int D_004E1DA8;
extern float D_004E1DAC;
extern float D_004E1DB0;
extern float D_004E1DB4;

class UnkStruct_StartCrashing_x {
public:
    unsigned char pad_0[0x1910];
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(void *);
    void * field_1914;
    unsigned char pad_1918[0x48];
    unsigned long field_1960;
    unsigned char pad_1968[0xE58];
    int field_27C0;
};

extern "C" int func_00131E40(void *);
extern "C" void HandleCrashRaceCar__13CB3CrashScoreFP17CB3RaceCarPhysicsi(void *, int);
extern "C" void func_0021AB40(unsigned long, char *);
extern "C" int strncmp(const char *, const char *, unsigned int);
extern "C" void func_001CBC70(void *, int, void *);
extern "C" void SetRealisticMomentsOfInertia__16CB3CollidingBodyFv(void *);
extern "C" void RegisterPlayerCarCrash__17CB3NetworkManagerFv(void *);
extern "C" void func_0022C2F0(void *, int, int, int, float, float, float, float);

class CB3CrashStartInfo;

class CB3RaceCarPhysics {
public:
    void StartCrashing(int p0, CB3CrashStartInfo * p1);
    unsigned char pad_0[0x1F0];
    float field_1F0;
    unsigned char pad_1F4[0x1C];
    unsigned char field_210;
    unsigned char pad_211[0x7];
    unsigned char field_218;
    unsigned char pad_219[0x11DB];
    UnkStruct_StartCrashing_x * field_13F4;
    unsigned char pad_13F8[0x4C];
    unsigned char field_1444;
    unsigned char pad_1445;
    unsigned char field_1446;
    unsigned char pad_1447[0xDD];
    int field_1524;
    unsigned char pad_1528[0x8];
    int field_1530;
};

// 0x001BFC70
void CB3RaceCarPhysics::StartCrashing(int p0, CB3CrashStartInfo * p1)
{
    if (field_210 != 0) return;
    field_218 = p0;
    if (func_00131E40(&D_004EE040) != 0) {
        HandleCrashRaceCar__13CB3CrashScoreFP17CB3RaceCarPhysicsi(&D_0064CE40, (int)(this));
        char buf[16];
        func_0021AB40(field_13F4->field_1960, buf);
        if (strncmp(buf, D_004B7D48, 4) == 0) {
            field_1F0 = field_1F0 * 3.0f;
        }
    }
    if (field_13F4->field_1914 == 0) {
        ((UnkStruct_StartCrashing_row *)((char *)&D_004EE040 + field_13F4->field_27C0 * 0xBB0 + 0x28E00))->vfunc_14(0x15, 0);
        RegisterPlayerCarCrash__17CB3NetworkManagerFv(&D_01E32AE0);
        field_1530 = 0;
    }
    func_001CBC70(this, p0, p1);
    field_1524 = 0;
    field_1444 = 0;
    field_1446 = 0;
    field_13F4->vfunc_14(p1);
    SetRealisticMomentsOfInertia__16CB3CollidingBodyFv(this);
    if (field_13F4->field_1914 == 0) {
        func_0022C2F0(&D_004F50C0, D_004E1DA8, (signed char)field_13F4->field_27C0, 0xFFFF, D_004E1DB0, 0.0f, D_004E1DAC, D_004E1DB4);
    }
}
