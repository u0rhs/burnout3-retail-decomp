// RenderFullScreenFlash__19CB3ExplosionManagerFf -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (16-byte float struct local copied into a separate u_long128 local (declared first) whose address is passed; .lit4 literals 0.025f/0.12f/8.333334f/1.6f; scale term computed before the stores).

// from build/vt\try_func_00399BA0_best.cpp
// RenderFullScreenFlash__19CB3ExplosionManagerFf -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_00399BA0_2;
struct UnkStruct_D_004E0BAC;
struct UnkStruct_D_004E0DB0;
struct UnkStruct_D_004E0F7C;
struct UnkStruct_D_004E1004;
struct UnkStruct_D_00665EC0;

struct UnkStruct_D_004E0DB0 {
    float field_0;
};

struct UnkStruct_D_004E0BAC {
    float field_0;
};

struct UnkStruct_00399BA0_2 {  // [G] 16-byte value, copied as one qword before the call
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};

struct UnkStruct_D_004E1004 {
    float field_0;
};

struct UnkStruct_D_004E0F7C {
    float field_0;
};

struct UnkStruct_D_00665EC0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_004E0DB0 D_004E0DB0;
extern UnkStruct_D_004E0BAC D_004E0BAC;
extern UnkStruct_D_004E1004 D_004E1004;
extern UnkStruct_D_004E0F7C D_004E0F7C;
extern UnkStruct_D_00665EC0 D_00665EC0;

extern "C" float func_002276C0(void *, void *, int);

// 0x00399BA0
extern "C" float RenderFullScreenFlash__19CB3ExplosionManagerFf(float f0)
{
    u_long128 copy;
    UnkStruct_00399BA0_2 local;
    float r = 0.0f;
    float x = f0 - 0.025f;
    if (x >= 0.0f) {
        r = 0.12f;
        if (x < 0.12f) {
            float t = 8.333334f * (0.12f - x);
            local.field_0 = 2.0f;
            local.field_8 = 1.0f;
            local.field_4 = 1.6f;
            local.field_C = t * t;
            copy = *(u_long128 *)&local;
            r = func_002276C0(&D_00665EC0, &copy, 1);
        }
    }
    return r;
}
