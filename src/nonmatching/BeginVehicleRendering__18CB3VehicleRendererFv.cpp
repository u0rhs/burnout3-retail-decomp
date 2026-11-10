// NONMATCHING: BeginVehicleRendering__18CB3VehicleRendererFv -- retail 229 / ours 229 instructions, 80 in changed runs
// gifq2: 229/229, 80 changed (was 193). SetCode = inline CGtVu0CodeManager::UploadVu0Code/WaitForUploadToFinish (E map names, Revenge types.h), exact layout; archive constants fixed (a, c.lo, d.lo, q5.lo), q5..q10 offsets fixed (p[1..6]); vu1/cam/src pointer locals. Left: quad-block register numbering (retail q6..q10 t5..t1) which also swaps this(s1)/vu1(s0). build/vt/gifq2/notes.txt
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


typedef unsigned int u_long128 __attribute__((mode(TI)));
class CB3VehicleRenderer;
struct UnkStruct_farFogPlane { u_long128 *field_0; };
struct UnkStruct_skyUserSwitch1 { void *field_0; };
struct UnkStruct_00666330 { u_long128 q[0x20]; };
struct UnkStruct_006662D8 { unsigned char pad_0[0x10]; };
struct UnkStruct_00666450 { u_long128 q[10]; };
extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_skyUserSwitch1 skyUserSwitch1;
class CGtVu0CodeManager {
public:
    static void *gmpCurrentVu0Code;
    static bool UploadVu0Code(void *code);
    static void WaitForUploadToFinish();
    static void *GetCurrentVu0CodePointer() { return gmpCurrentVu0Code; }
};
extern char vu_game_0047F6D0[];
extern char vu_game_0046BB80[];
extern u_long128 D_00666290;
extern u_long128 D_006662A0;
extern u_long128 D_006662B0;
extern u_long128 D_006662C0;
extern UnkStruct_00666330 D_00666330;
extern unsigned int D_006662D8;
extern UnkStruct_00666450 D_00666450;
extern "C" void _rwDMAOpenVIFPkt(int, int);
extern "C" void RpSkyRenderStateGet(int, int *);
extern "C" int sceDmaGetChan(int);
extern "C" int sceDmaSync(int, int, int);
// [L] CGtVu0CodeManager::UploadVu0Code / WaitForUploadToFinish: names from E B3O0PCH map (0x2294A0, 0x2293C0),
// signatures from Revenge types.h; bodies [G] from retail's inlined copies (gifq2 probes build/vt/gifq2/u*.cpp)
inline bool CGtVu0CodeManager::UploadVu0Code(void *code)
{
    if (gmpCurrentVu0Code == code) {
        return false;
    } else {
        gmpCurrentVu0Code = code;
        if (code) {
            *(volatile unsigned int *)0x10008020 = 0;
            *(volatile unsigned int *)0x10008030 = (unsigned int)code;
            *(volatile unsigned int *)0x10008000 = 0x145;
            return true;
        } else {
            return false;
        }
    }
}
inline void CGtVu0CodeManager::WaitForUploadToFinish()
{
    while (sceDmaSync(sceDmaGetChan(0), 1, 0) != 0) {}
}

class CB3VehicleRenderer {
public:
    void BeginVehicleRendering();

    unsigned char pad_0[0x30];
    u_long128 field_30;
    u_long128 field_40;
    u_long128 field_50;
    u_long128 field_60;
    unsigned char pad_70[0x80];
    int field_F0;
    int field_F4;
    unsigned char pad_F8[0x8];
    u_long128 *field_100;
};

// 0x00220540
void CB3VehicleRenderer::BeginVehicleRendering()
{
    bool ch = false;
    void *vu1 = (void *)vu_game_0046BB80;
    if (CGtVu0CodeManager::GetCurrentVu0CodePointer() != (void *)vu_game_0047F6D0) {
        if (CGtVu0CodeManager::UploadVu0Code((void *)vu_game_0047F6D0)) ch = true;
    }
    field_30 = D_00666290;
    field_40 = D_006662A0;
    field_50 = D_006662B0;
    field_60 = D_006662C0;
    field_100 = (u_long128 *)0x70002000;
    u_long128 a;
    asm("pcpyld %0, %2, %1" : "=r"(a) : "r"(0x10000000), "r"(0x10000000));
    field_100[0x3C] = a;
    u_long128 b;
    asm("pcpyld %0, %2, %1" : "=r"(b) : "r"(0x10000008UL), "r"(0x6C0803EE01000404UL));
    field_100[0x3D] = b;
    u_long128 c;
    asm("pcpyld %0, %2, %1" : "=r"(c) : "r"(0x1000000000000003UL), "r"(14));
    field_100[0x3E] = c;
    u_long128 d;
    asm("pcpyld %0, %2, %1" : "=r"(d) : "r"(0x10000000), "r"(0x17000000));
    field_100[0x3F] = d;
    u_long128 e;
    asm("pcpyld %0, %2, %1" : "=r"(e) : "r"(0x50000000), "r"(0x17000000));
    field_100[0x3A] = e;
    RpSkyRenderStateGet(2, &field_F0);
    RpSkyRenderStateGet(3, &field_F4);
    u_long128 *cam = (u_long128 *)&D_00666330;
    _rwDMAOpenVIFPkt(0x80000000, 0xB);
    u_long128 q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x100000000000800AUL), "r"(14));
    *farFogPlane.field_0 = q0;
    asm("pcpyld %0, %1, %2" : "=r"(q1) : "r"(0x41), "r"((unsigned long)cam[0x1F]));
    *++farFogPlane.field_0 = q1;
    asm("pcpyld %0, %1, %2" : "=r"(q2) : "r"(0x19), "r"((unsigned long)cam[0x1E]));
    *++farFogPlane.field_0 = q2;
    asm("pcpyld %0, %2, %1" : "=r"(q3) : "r"((unsigned long)cam[0x1C] & 0xFFFFFFFFUL), "r"(0x4D));
    *++farFogPlane.field_0 = q3;
    asm("pcpyld %0, %1, %2" : "=r"(q4) : "r"(0x4F), "r"((unsigned long)cam[0x1D]));
    *++farFogPlane.field_0 = q4;
    u_long128 *p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(q5) : "r"((unsigned long)D_006662D8 | 0x620010000UL), "r"(7));
    asm("pcpyld %0, %2, %1" : "=r"(q6) : "r"(0x60), "r"(0x15));
    asm("pcpyld %0, %1, %2" : "=r"(q7) : "r"(8), "r"(0UL));
    p[1] = q5;
    asm("pcpyld %0, %1, %2" : "=r"(q8) : "r"(9), "r"(5));
    asm("pcpyld %0, %1, %2" : "=r"(q10) : "r"(0x48), "r"(0x51001));
    asm("pcpyld %0, %2, %1" : "=r"(q9) : "r"(0x50003), "r"(0x47));
    p[2] = q6;
    p[3] = q7;
    p[4] = q8;
    p[5] = q9;
    p[6] = q10;
    farFogPlane.field_0 = farFogPlane.field_0 + 7;
    if (skyUserSwitch1.field_0 != vu1) {
        _rwDMAOpenVIFPkt(0, 2);
        u_long128 *r = farFogPlane.field_0;
        skyUserSwitch1.field_0 = vu1;
        u_long128 s0;
        asm("pcpyld %0, %2, %1" : "=r"(s0) : "r"(((unsigned long)(unsigned int)vu1 << 32) | 0x50000000UL), "r"(0x0200009C03000000UL));
        u_long128 s1;
        asm("pcpyld %0, %2, %1" : "=r"(s1) : "r"(0x10000000), "r"(0x15000000));
        r[0] = s0;
        r[1] = s1;
        farFogPlane.field_0 = r + 2;
    }
    u_long128 *src = (u_long128 *)&D_00666450;
    _rwDMAOpenVIFPkt(0, 0xB);
    u_long128 *w = farFogPlane.field_0;
    u_long128 h;
    asm("pcpyld %0, %2, %1" : "=r"(h) : "r"(0x1000000A), "r"(0x6C0A03F601000404UL));
    *w = h;
    w++;
    for (int i = 0; i < 10; i++) {
        *w = src[i];
        w++;
    }
    farFogPlane.field_0 = w;
    if (ch) CGtVu0CodeManager::WaitForUploadToFinish();
}
