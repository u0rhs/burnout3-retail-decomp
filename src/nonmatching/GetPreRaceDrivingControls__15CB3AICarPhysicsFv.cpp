// NONMATCHING: GetPreRaceDrivingControls__15CB3AICarPhysicsFv -- retail 352 / ours 349 instructions, 281 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: a139: logic believed right (349 vs 352 instrs, 287 in changed runs - mostly misaligned). Open: (1) the 5 type-case blocks: retail addresses every _grSpikeGen field with its own lui/addiu(sym+K)+addu idx*28, ours folds (tried byte-offset casts, [1]-array members, float*[idx*7]); (2) RNG: first draw s
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_Random { int field_0; int field_4; };
struct UnkStruct_spike { float field_0; float field_4; float field_8; float field_C; float field_10; float field_14; unsigned char field_18; unsigned char pad_19[3]; };
struct UnkStruct_D_00522680 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0052267C { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_pr_car {
    unsigned char pad_0[0x1340];
    float field_1340;
    unsigned char pad_1344[0x10BE];
    unsigned char field_2402;
};
struct UnkStruct_pr_car2 { unsigned char pad_0[0x19AC]; signed char field_19AC; };
extern UnkStruct_Random _gRandom;
extern UnkStruct_spike _grSpikeGen[];
#define SPF(off) (((float *)((char *)&_grSpikeGen + (off)))[idx * 7])
#define SPB(off) (((unsigned char *)((char *)&_grSpikeGen + (off)))[idx * 28])
extern int D_0066DE50[];
extern int D_0066DE70[];
extern float D_0066DE90[];
extern UnkStruct_D_00522680 D_00522680;
extern UnkStruct_D_0052267C D_0052267C;
extern "C" void Update__23CB3AiCarPreRaceRpmSpikeFv(void *);

struct UnkStruct_pr_self {
    unsigned char pad_0[0x1400];
    float field_1400;
    float field_1404;
    int field_1408;
    unsigned char pad_140C[0x8];
    float field_1414;
    unsigned char pad_1418[0x2E];
    unsigned char field_1446;
    unsigned char pad_1447[0xE1];
    unsigned char field_1528;
    unsigned char pad_1529[0x3F];
    UnkStruct_pr_car *field_1568;
};

static inline unsigned Rnd(int &a)
{
    int b = _gRandom.field_4;
    unsigned r = (a << 16) + (a >> 16);
    r += b;
    _gRandom.field_4 = b + r;
    a = r;
    return r;
}

extern "C" void GetPreRaceDrivingControls__15CB3AICarPhysicsFv(UnkStruct_pr_self * self)
{
    self->field_1408 = 0;
    UnkStruct_pr_car *car = self->field_1568;
    float u = -1.0f;
    float t = car->field_1340;
    if (!(t < 0.0f)) u = t - D_00522680.field_0;
    if (!(u < 0.0f) && u < 0.25f * t) {
        if (car->field_2402 == 0) return;
        self->field_1446 = 1;
        self->field_1528 = 1;
        self->field_1404 = 0.0f;
        self->field_1400 = 1.0f;
        self->field_1414 = 1.0f;
        return;
    }
    signed char idx = ((UnkStruct_pr_car2 *)car)->field_19AC;
    if ((idx & 1) == 0) return;
    {
        bool ok = false;
        if (SPF(4) <= 0.0f) {
            if (SPB(0x18) == 0) ok = true;
        }
        if (ok) {
            float *tm = &D_0066DE90[idx];
            float tv = *tm;
            if (!(tv <= 0.0f)) *tm = tv - D_0052267C.field_0;
            int sd = _gRandom.field_0;
            *tm = 1.5f * (2.3283064e-10f * (float)Rnd(sd));
            float rate = 1.5f * (2.3283064e-10f * (float)Rnd(sd));
            _gRandom.field_0 = sd;
            switch (D_0066DE50[idx]) {
            case 0:
                SPB(0x18) = 1; SPF(0x8) = 0.4f; SPF(0xC) = 0.2f; SPF(0x10) = 0.01f; SPF(0x14) = rate; SPF(0x4) = 0.2f;
                break;
            case 1:
                SPB(0x18) = 1; SPF(0x8) = 0.4f; SPF(0xC) = 0.24f; SPF(0x10) = 0.025f; SPF(0x14) = rate; SPF(0x4) = 0.24f;
                break;
            case 2:
                SPB(0x18) = 1; SPF(0x8) = 0.2f; SPF(0xC) = 0.4f; SPF(0x10) = 0.255f; SPF(0x14) = rate; SPF(0x4) = 0.4f;
                break;
            case 3:
                SPB(0x18) = 1; SPF(0x8) = 0.2f; SPF(0xC) = 0.25f; SPF(0x10) = 0.185f; SPF(0x14) = rate; SPF(0x4) = 0.25f;
                break;
            case 4:
                SPB(0x18) = 1; SPF(0x8) = 0.4f; SPF(0xC) = 0.75f; SPF(0x10) = 0.175f; SPF(0x14) = rate; SPF(0x4) = 0.75f;
                break;
            }
            int *c = &D_0066DE70[idx];
            if (*c == 0) {
                int sd2 = _gRandom.field_0;
                *c = Rnd(sd2) % 3;
                D_0066DE50[idx] = Rnd(sd2) % 5;
                _gRandom.field_0 = sd2;
            } else {
                *c = *c - 1;
            }
        }
    }
    Update__23CB3AiCarPreRaceRpmSpikeFv(&_grSpikeGen[self->field_1568->field_2402 * 0 + ((UnkStruct_pr_car2 *)self->field_1568)->field_19AC]);
    {
        float v = _grSpikeGen[((UnkStruct_pr_car2 *)self->field_1568)->field_19AC].field_0;
        self->field_1404 = 0.0f;
        self->field_1400 = v;
        self->field_1414 = v;
    }
}
