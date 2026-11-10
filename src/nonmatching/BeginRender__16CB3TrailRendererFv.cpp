// NONMATCHING: BeginRender__16CB3TrailRendererFv -- retail 105 / ours 105 instructions, 31 in changed runs
// stabs3: 40 -> 31. Revenge-driven: the VU code address in its own local (Revenge lpVUCode) read right before the skyUserSwitch1 test. Left: loop dest pointer v1 vs ours a0 (and D_00667050 base a0 vs v1); no-k-local, decl orders, dest-pointer local (Revenge lpu128CameraVU1Data), indexed copies 31-65
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (logic unchanged from the gif6 archive)

// gif3: *p++ form, D_00522680 as a 16-byte struct (lui/%lo, was gp), q4 hi-first, i declared after q4: 105/105, 54 changed. Left: register numbering of i/q0/q3/q4 (retail i=t2,q3=t1,q4=t0,q0=t0; ours t0,t2,t1) and the loop pointer (retail v1, ours a0); declaring i earlier is worse (64)

// un0 ipos2 loop0 if0 o41
typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_farFogPlane { u_long128 * field_0; };
struct UnkStruct_skyUserSwitch1 { void * field_0; };
struct UnkStruct_skyZbuf_1 { unsigned long field_0; };
struct UnkStruct_D_00667050 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x10]; };
class CB3TrailRenderer {
public:
// 0x002F38B0
    void BeginRender();
};
extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_skyUserSwitch1 skyUserSwitch1;
extern UnkStruct_skyZbuf_1 skyZbuf_1;
extern UnkStruct_D_00665EC0 D_00665EC0;
extern UnkStruct_D_00667050 D_00667050;
struct UnkStruct_D_00522680 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522680 D_00522680;
extern char vu_game_004771B0[];
extern "C" void _rwDMAOpenVIFPkt(int, int);

void CB3TrailRenderer::BeginRender()
{
    _rwDMAOpenVIFPkt(0, 0x14);
    union { u_long128 q[2]; float f[8]; } u;
    int i;
    u_long128 *p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10000000UL), "r"(0x10000000UL));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000000DUL), "r"(0x6C0D03F301000101UL));
    u.f[0] = 0.0f;
    u.f[1] = 0.0f;
    u.f[2] = 0.0f;
    u.f[3] = D_00522680.field_0;
    *p++ = u.q[0];
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x302E400000000000UL), "r"(0x412));
    int k = D_00667050.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0xAUL), "r"(0x300000000UL));
    u_long128 *s = (u_long128 *)((char *)&D_00665EC0 + k * 0x230 + 0x590);
    i = 0;
    do {
        *p++ = *s++;
        i++;
    } while (i < 10);
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10000002UL), "r"(0x5000000200000000UL));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000000000008001UL), "r"(0xEUL));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(skyZbuf_1.field_0 | 0x101000000UL), "r"(0x4EUL));
    char *code = vu_game_004771B0;
    unsigned long lo = 0x10000000UL;
    if (skyUserSwitch1.field_0 != code) {
        skyUserSwitch1.field_0 = code;
        lo = ((unsigned long)(unsigned int)code << 32) | 0x50000000UL;
    }
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(lo), "r"(0x20000D803000000UL));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10000000UL), "r"(0x15000000UL));
    farFogPlane.field_0 = p;
}




