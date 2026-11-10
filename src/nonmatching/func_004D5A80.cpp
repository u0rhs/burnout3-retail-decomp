// NONMATCHING: func_004D5A80 -- retail 50 / ours 46 instructions, 40 in changed runs
// gaps1: hand-drafted from the asm (static initialiser)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1 (2026-11-02): hand-drafted from the retail asm (0x4D5A80..0x4D5B44). A C++ static initialiser (.init; called through the .ctor
// table): the constructor code of one translation unit's globals, kept as its asm label (retail's own symbol is a local
// __sinit_<file>). The environment-map view constants: window = tan(D_004E0A5C), rotate angle =
// D_004E069C * atan(sqrt(2) * tan(D_004E0A60)), shift = window - 1, and three axis vectors (w lanes unset in retail).
// TRACK: clean
// EQUIV: [L] written from the asm: every store and call accounted for; word 0x46000504 at 0x4D5AA8 = EE sqrt.s $f20, $f0 (spimdisasm leaves it raw)

extern "C" float tanf(float);
extern "C" float atanf(float);
extern "C" float sqrtf(float);
struct UnkStruct_004D5A80_q { unsigned int w[4]; };
extern float krEnvmapViewWindow;
extern float krEnvmapRotateAngle;
extern float krEnvmapShift;
extern float D_004E0A5C;          // [C] gp-relative
extern float D_004E0A60;
extern float D_004E069C;
extern UnkStruct_004D5A80_q D_004B9DC0;
extern UnkStruct_004D5A80_q D_004B9DD0;
extern UnkStruct_004D5A80_q kAtAxis;

// 0x004D5A80
extern "C" void func_004D5A80()
{
    krEnvmapViewWindow = tanf(D_004E0A5C);
    float r2 = sqrtf(2.0f);
    float a = atanf(r2 * tanf(D_004E0A60));
    UnkStruct_004D5A80_q x, y, z;   // lane 3 never written (retail copies uninitialised stack words)
    *(float *)&x.w[0] = 1.0f; *(float *)&x.w[1] = 0.0f; *(float *)&x.w[2] = 0.0f;
    *(float *)&y.w[0] = 0.0f; *(float *)&y.w[1] = 1.0f; *(float *)&y.w[2] = 0.0f;
    *(float *)&z.w[0] = 0.0f; *(float *)&z.w[1] = 0.0f; *(float *)&z.w[2] = 1.0f;
    krEnvmapRotateAngle = D_004E069C * a;
    float w = krEnvmapViewWindow;
    D_004B9DC0 = x;
    D_004B9DD0 = y;
    kAtAxis = z;
    krEnvmapShift = w - 1.0f;
}
