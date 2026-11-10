// CB3Profile::Evaluate() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3Profile.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (pass2a: copysign-0.5 union declared volatile (retail keeps its sw/lw through the 0x4C slot)).


struct UnkStruct_D_0051BFA0_ev { unsigned char field_0[67]; unsigned char field_43[20]; unsigned char pad_57[0xE5]; unsigned char field_13C[20]; unsigned char pad_150a[0]; };
struct UnkStruct_D_0051BFA0_ev2 { unsigned char field_0[0x43]; unsigned char field_43[20]; unsigned char pad_57[0xE5]; unsigned char field_13C[20]; unsigned char field_150[10]; };
struct UnkStruct_gCalcData_ev {
    unsigned char pad_0[0x24]; int field_24; int field_28; int field_2C; unsigned char pad_30[0x5C]; int field_8C; unsigned char pad_90[0x80]; int field_110;
};
class CB3Profile {
public:
    void Evaluate();
    void EvaluateFavourites();
    void EvaluateGameCounts();
    void EvaluateTrackUnlocking();
    bool WillPlayerCarUnlock(int);
    unsigned char pad_0[0x380];
    int field_380;
    signed char field_384;
    signed char field_385;
    signed char field_386[73];
    signed char field_3CF[100];
    unsigned char field_433[20];
    unsigned char field_447[10];
    unsigned char field_451[67];
    unsigned char field_494;
    unsigned char field_495;
    unsigned char field_496;
    unsigned char field_497;
    unsigned char field_498;
    unsigned char field_499;
    unsigned char field_49A;
};
extern UnkStruct_D_0051BFA0_ev2 D_0051BFA0;
extern UnkStruct_gCalcData_ev gCalculatedData;
extern "C" int func_0013C400(void *);
extern "C" void func_00138530(CB3Profile *);
extern "C" void func_001372B0(CB3Profile *);
extern "C" bool func_00137C40(CB3Profile *, int);
extern "C" void func_00137F20(CB3Profile *);
extern "C" void func_00137E00(CB3Profile *);
extern "C" float func_0011E388(float, float);
static inline int a137_max(int a, int b) { int r; asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline int a137_min(int a, int b) { int r; asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline unsigned int a137_zx(int a) { unsigned int r; asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a)); return r; }
static inline float a137_maxs(float a, float b) { float r; asm("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
// 0x00139C00
void CB3Profile::Evaluate()
{
    int ok;
    int t4;
    unsigned int j;
    unsigned char t2;
    func_0013C400(&D_0051BFA0);
    if (field_380 != -1) {
        if (field_385 != 0) {
            field_498 = field_386[field_380];
            field_386[field_380] = field_384;
            field_494 = field_380;
            signed char c = field_384;
            field_49A = 1;
            field_496 = c;
        } else {
            field_499 = field_386[field_380];
            field_3CF[field_380] = field_384;
            field_495 = field_380;
            signed char c = field_384;
            field_49A = 0;
            field_497 = c;
        }
        field_380 = -1;
        field_384 = 0;
    }
    func_00138530(this);
    func_001372B0(this);
    EvaluateFavourites();
    EvaluateGameCounts();
    int i = 0;
    while (i < 20) {
        D_0051BFA0.field_13C[i] = field_433[i];
        i++;
    }
    gCalculatedData.field_110 = 0;
    for (i = 0; i < 10; i++) {
        if (field_447[i] == 0) {
        } else {
            gCalculatedData.field_110++;
        }
        t2 = field_447[i];
        D_0051BFA0.field_150[i] = field_447[i];
    }
    gCalculatedData.field_2C = 0;
    for (i = 0; i < 20; i++) {
        ok = func_00137C40(this, i);
        D_0051BFA0.field_43[i] = ok;
        if (ok) gCalculatedData.field_2C++;
    }
    gCalculatedData.field_28 = 0;
    for (i = 0; i < 67; i++) {
        D_0051BFA0.field_0[i] = 0;
        if (field_451[i] != 0) D_0051BFA0.field_0[i] = 1;
        else D_0051BFA0.field_0[i] = WillPlayerCarUnlock(i);
        if (D_0051BFA0.field_0[i] != 0) gCalculatedData.field_28++;
    }
    EvaluateTrackUnlocking();
    func_00137F20(this);
    func_00137E00(this);
    t4 = gCalculatedData.field_8C;
    int t1 = t4;
    int t3 = gCalculatedData.field_28 - 3;
    const float t0 = a137_maxs((float)(t1 + (t3)), 0.0f);
    float f = t0;
    float x = 100.0f * func_0011E388(2.0f, (f / 237.0f)) - 100.0f;
    volatile union { float f; int u; } hs;
    union { float f; int u; } xs;
    hs.f = 0.5f;
    xs.f = x;
    hs.u = hs.u | (xs.u & 0x80000000);
    int n = (int)(x + hs.f);
    float fn = (float)n;
    gCalculatedData.field_24 = a137_zx(a137_min(a137_max((int)fn, 0), 100));
}
