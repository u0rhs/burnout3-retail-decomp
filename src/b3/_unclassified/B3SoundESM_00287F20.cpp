// CB3SoundESMHigh::Update(const CB3RaceCar*,float,float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESM.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near15: six .lit4 literals + FP ordering; retail leaves D_0064F7E0 unlabelled).


// CB3SoundESMHigh::Update(const CB3RaceCar*, float, float, float) -- hand-written (a213 + near15). The rev-limiter
// wobble's six .lit4 constants (D_004E079C/07A0/06C0/07A4/07A8/07AC) are written as literals (.lit4 rule); the
// divisions in d-then-c order and the last arm as `a - (v - 0.35f) * e` with the w[2] store after it give retail's
// FP numbering. Types and fields are placeholders [G].

struct UnkStruct_00287F20_in { int w[7]; };
struct UnkStruct_00287F20_out { unsigned char pad_0[0x50]; };
// The 12-output block ESMStruct::Update fills, field_40 elements of it [C its loop 0x2FB770, i < field_40, p1[i] 0x50 apart].
// Typed as the whole block (not a pointer to one element) so the callee's write extent is visible: the port bounces a
// pointer to a host local as max(256, sizeof(T)) bytes, and with one 0x50 element outputs 3.. were never copied back
// (the native3 "uninitialized read" of this function; same object code, decomp1 2026-11-06).
struct UnkStruct_00287F20_outs { UnkStruct_00287F20_out a[12]; };
struct UnkStruct_00287F20_e0 { unsigned char pad_0[0xD]; unsigned char field_D; unsigned char pad_E[2]; };
struct UnkStruct_00287F20_st { unsigned char pad_0[0x3C]; UnkStruct_00287F20_e0 *field_3C; unsigned char field_40; };
struct UnkStruct_00287F20_g { unsigned char pad_0[0x146C]; float field_146C; unsigned char pad_1470[0x18]; float field_1488; };
struct UnkStruct_D_0064F7E0 { UnkStruct_00287F20_g *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BA94 { int field_0; unsigned char pad_4[0xC]; };
class CB3RaceCar { public: unsigned char pad_0[0x1998]; unsigned char field_1998; };
class CGtSoundRealVoice;
class CGtSoundVirtualVoice;
extern UnkStruct_D_0064F7E0 D_0064F7E0;
extern UnkStruct_D_0051BA94 D_0051BA94;
extern "C" int rand(void);
extern "C" void Construct__22CB3SoundESMGraphInputsFPC10CB3RaceCarf(UnkStruct_00287F20_in *, const CB3RaceCar *, float);
extern "C" void ApplyLag__22CB3SoundESMGraphInputsFRC22CB3SoundESMGraphInputsPC19CB3SoundESMInputLag(UnkStruct_00287F20_in *, const UnkStruct_00287F20_in *, void *);
extern "C" void Update__17CB3SoundESMStructCFRC22CB3SoundESMGraphInputsP23CB3SoundEsmGraphOutputs(UnkStruct_00287F20_st *, const UnkStruct_00287F20_in *, UnkStruct_00287F20_outs *);
extern "C" void Apply__23CB3SoundEsmGraphOutputsCFP17CGtSoundRealVoicePC10CB3RaceCarff(UnkStruct_00287F20_out *, CGtSoundRealVoice *, const CB3RaceCar *, float, float);
extern "C" void Apply__23CB3SoundEsmGraphOutputsCFUi(UnkStruct_00287F20_out *, unsigned int);
extern "C" void Apply__23CB3SoundEsmGraphOutputsCFP20CGtSoundVirtualVoicePC10CB3RaceCarf(UnkStruct_00287F20_out *, CGtSoundVirtualVoice *, const CB3RaceCar *, float);
class CB3SoundESMHigh;
extern "C" void ModulateRpm__11CB3SoundESMFR22CB3SoundESMGraphInputsPC10CB3RaceCar(CB3SoundESMHigh *, UnkStruct_00287F20_in *, const CB3RaceCar *);
extern "C" void func_00288480(CB3SoundESMHigh *, UnkStruct_00287F20_in *, const CB3RaceCar *);
class CB3SoundESMHigh {
public:
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    UnkStruct_00287F20_in field_4;
    unsigned char pad_20[0xC];
    UnkStruct_00287F20_st *field_2C;
    unsigned char pad_30[0x10];
    float field_40;
    unsigned char pad_44[0x10];
    unsigned char field_54[3];
    unsigned char field_57;
    unsigned char field_58;
    unsigned char pad_59[7];
    CGtSoundRealVoice *field_60[1];
    unsigned char pad_64[0x2C];
    CGtSoundVirtualVoice *field_90;
    void CalculateDoppler(const CB3RaceCar *, float *, float *);
    void Update(const CB3RaceCar *, float, float, float);
};
// N182: `#pragma opt_dead_assignments off` ([G] scoped to this function; found by mwperm).
#pragma push
#pragma opt_dead_assignments off
// 0x00287F20
void CB3SoundESMHigh::Update(const CB3RaceCar *car, float p0, float p1, float p2)
{
    float d1; float d0;
    UnkStruct_00287F20_outs outs;
    UnkStruct_00287F20_in in;
    if (car->field_1998 == 0) {
        if (field_57 != 0) vfunc_18();
        return;
    }
    if (field_57 == 0) vfunc_14();
    if (field_58 == 0) {
        Construct__22CB3SoundESMGraphInputsFPC10CB3RaceCarf(&in, car, p1);
        if (D_0051BA94.field_0 != -1) {
            field_40 += 0.016f;
            UnkStruct_00287F20_g *g = D_0064F7E0.field_0;
            float a = g->field_1488;
            float b = g->field_146C;
            float d = a / 0.1f;
            float c = a / 0.65f;
            float e = 0.1f + c;
            float lim = 0.75f + 0.0025f * (float)(rand() % 1000);
            if (!(field_40 <= lim)) field_40 = 0.00025f * (float)(rand() % 1000);
            float v = field_40;
            if (v < 0.25f) {
                *(float *)&in.w[0] = 1000.0f;
                *(float *)&in.w[2] = 0.25f;
            } else if (v < 0.35f) {
                *(float *)&in.w[2] = 1.0f;
                *(float *)&in.w[0] = b + (v - 0.25f) * d;
            } else {
                *(float *)&in.w[0] = a - (v - 0.35f) * e;
                *(float *)&in.w[2] = 0.0f;
            }
        }
        ApplyLag__22CB3SoundESMGraphInputsFRC22CB3SoundESMGraphInputsPC19CB3SoundESMInputLag(&in, &field_4, field_2C);
        ModulateRpm__11CB3SoundESMFR22CB3SoundESMGraphInputsPC10CB3RaceCar(this, &in, car);
        func_00288480(this, &in, car);
        Update__17CB3SoundESMStructCFRC22CB3SoundESMGraphInputsP23CB3SoundEsmGraphOutputs(field_2C, &in, &outs);
        unsigned int i;
        int j = 0;
        CalculateDoppler(car, &d1, &d0);
        for (i = 0; i < field_2C->field_40; i++) {
            switch (field_2C->field_3C[i].field_D & 0xF) {
            case 0:
                Apply__23CB3SoundEsmGraphOutputsCFP17CGtSoundRealVoicePC10CB3RaceCarff(&outs.a[i], field_60[i], car, p2 * (d1 * p0), d0);
                break;
            case 1:
                Apply__23CB3SoundEsmGraphOutputsCFUi(&outs.a[i], j++);
                break;
            case 2:
                Apply__23CB3SoundEsmGraphOutputsCFP20CGtSoundVirtualVoicePC10CB3RaceCarf(&outs.a[i], field_90, car, p0);
                break;
            }
        }
        field_4 = in;
    }
    return;
}
