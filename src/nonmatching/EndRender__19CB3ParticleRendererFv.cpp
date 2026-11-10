// NONMATCHING: EndRender__19CB3ParticleRendererFv -- retail 251 / ours 249 instructions, 190 in changed runs
// draftAN C-first: with renderable arrays: textures collected (CB3TextureCollectionPS2 Initialise / AddTexture per array / Upload), the camera data's FOV scale and near clip into the statics, its 3x3 transposed into D_01D9CFD0/E0/F0 (w kept), a 14-qword VIF packet (microprogram call vu_game_0046D750 -> skyUserSwitch1, GS registers, the camera's four projection rows as (x,y,z,z), two parameter rows), each array dispatched, then a 6-qword GS restore (ALPHA/TEST/ZBUF/CLAMP); 249/251, calls identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; every qword's lo/hi halves (pcpyld operand order), each lane source of rows 7-12, the camera index re-read after the calls, the early exit (beqz) and both counted loops traced; behaviour_audit quiet

// EndRender__19CB3ParticleRendererFv -- draftAN (C-first draft). 0x254580, 0x3EC. [C] name: the mangled symbol (a static member:
// no this). Local names from Revenge STABS EndRender__19CB4ParticleRenderer (B4ParticleRendererPS2.cpp: lTexList, lpCameraData,
// lCamLTM, lnCount) [L]. Field names are placeholders; the camera data is retail's 0x230-byte element of the array at
// D_00665EC0 + 0x470, indexed by D_00667050 (as the matched B3DebrisRendererPS2_002F3B60.cpp addresses it).
// What it does [L]: with renderable arrays: their textures collected and uploaded, the camera's 3x3 transposed into the three
// static rows D_01D9CFD0/E0/F0 (w kept), the FOV scale / near clip statics, then a 14-qword VIF packet (VU1 microprogram call,
// GS registers, the camera's four projection rows as (x, y, z, z), two parameter rows), each array dispatched, and a 6-qword
// GS restore (ALPHA / TEST / ZBUF / CLAMP from the sky driver's defaults).
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct UnkStruct_00254580_cd {              // [L] CB3CameraData (Revenge CB4CameraData), 0x230 [C] stride
    unsigned char pad_0[0xA0];
    CGtV3d field_A0[3];                     // [C] lCamLTM rows (right, up, at) read at +0xA0/+0xB0/+0xC0
    unsigned char pad_D0[0x10];
    CGtV3d field_E0[4];                     // [C] projection rows, packed as (x, y, z, z)
    unsigned char pad_120[0x48];
    float field_168;                        // [C] packed as row 12's w
    unsigned char pad_16C[0x4];
    float field_170;                        // [C] row 12's x, y, z
    float field_174;
    float field_178;
    unsigned char pad_17C[0x20];
    float field_19C;                        // [C] -> mrMinNearClip
    unsigned char pad_1A0[0x60];
    float field_200;                        // [C] row 11's z
    float field_204;                        // [C] row 11's w
    float field_208;                        // [C] -> mrFOVScale
    unsigned char pad_20C[0xC];
    float field_218;                        // [C] row 11's x
    float field_21C;                        // [C] row 11's y
    unsigned char pad_220[0x10];
};
struct UnkStruct_D_00667050 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_00667050 D_00667050;     // [C] the current camera index
extern UnkStruct_D_00665EC0 D_00665EC0;
class CGtTexture;
struct UnkStruct_00254580_tex { unsigned char pad_0[0xE0]; CGtTexture *field_E0; };   // [C] a particle array (texture at +0xE0)
struct UnkStruct_00254580_e { UnkStruct_00254580_tex *field_0; unsigned char pad_4[0xC]; };   // [L] CB3ParticleRendererEntry (0x10)
extern UnkStruct_00254580_e D_01D9D010[];
extern CGtV3d D_01D9CFD0, D_01D9CFE0, D_01D9CFF0;   // [G] the transposed camera rotation (DispatchArray's rows)
extern "C" int mnNumRenderableArrays__19CB3ParticleRenderer;
extern "C" int mnDMANumQW__19CB3ParticleRenderer;
extern "C" float mrFOVScale__19CB3ParticleRenderer;
extern "C" float mrMinNearClip__19CB3ParticleRenderer;
struct UnkStruct_farFogPlane { u_long128 *field_0; };
extern UnkStruct_farFogPlane farFogPlane;   // [C] symbol name (the DMA packet cursor)
struct UnkStruct_skyUserSwitch1 { void *field_0; };
extern UnkStruct_skyUserSwitch1 skyUserSwitch1;   // [L] the VU1 microcode currently resident
extern char vu_game_0046D750[];             // the particle VU1 microprogram
extern unsigned long skyZbuf_1;
extern unsigned long skyAlpha_1;
extern unsigned long skyTest_1;
extern unsigned long skyClamp_1;
class CGtTexture;
class CB3TextureCollectionPS2 {            // [C] names: the mangled symbols; 0x30 bytes of stack [G]
public:
    void Initialise();
    void AddTexture(CGtTexture *);
    void Upload();
    unsigned char pad_0[0x30];
};
extern "C" void _rwDMAOpenVIFPkt(int, int);
extern "C" void DispatchArray__19CB3ParticleRendererFPQ219CB3ParticleRenderer24CB3ParticleRendererEntry(UnkStruct_00254580_e *);

static inline u_long128 func_00254580_q(unsigned long lo, unsigned long hi)
{
    u_long128 r;
    asm("pcpyld %0, %2, %1" : "=r"(r) : "r"(lo), "r"(hi));
    return r;
}
static inline UnkStruct_00254580_cd *func_00254580_cd()
{
    return (UnkStruct_00254580_cd *)((char *)&D_00665EC0 + D_00667050.field_0 * 0x230 + 0x470);
}
// [C] API: B3O0PCH map (CGtV3dPlus::SetPlus(ZAxisType), 80 bytes); body as the header's SetPlus(YAxisType) (header gap queued)
static inline void func_00254580_inl1(CGtV3dPlus &d, ZAxisType z)
{
    asm("vsubw.w %0, $vf0, $vf0w" "\n\t" "vaddz.w %0, %0, %1z" : "+j"(d.mData) : "j"(z.lVector));
}

// 0x00254580
extern "C" void EndRender__19CB3ParticleRendererFv()
{
    UnkStruct_00254580_cd *lpCameraData = func_00254580_cd();
    CGtV3d *lCamLTM = lpCameraData->field_A0;
    if (mnNumRenderableArrays__19CB3ParticleRenderer == 0)
        return;
    CB3TextureCollectionPS2 lTexList;
    lTexList.Initialise();
    for (int lnCount = 0; lnCount < mnNumRenderableArrays__19CB3ParticleRenderer; lnCount++)
        lTexList.AddTexture(D_01D9D010[lnCount].field_0->field_E0);
    lTexList.Upload();
    mrFOVScale__19CB3ParticleRenderer = lpCameraData->field_208;
    mrMinNearClip__19CB3ParticleRenderer = lpCameraData->field_19C;
    D_01D9CFD0.SetX(lCamLTM[0].X());
    D_01D9CFE0.SetX(lCamLTM[0].Y());
    D_01D9CFF0.SetX(lCamLTM[0].Z());
    D_01D9CFD0.SetY(lCamLTM[1].X());
    D_01D9CFE0.SetY(lCamLTM[1].Y());
    D_01D9CFF0.SetY(lCamLTM[1].Z());
    D_01D9CFD0.SetZ(lCamLTM[2].X());
    D_01D9CFE0.SetZ(lCamLTM[2].Y());
    D_01D9CFF0.SetZ(lCamLTM[2].Z());
    _rwDMAOpenVIFPkt(0, mnDMANumQW__19CB3ParticleRenderer + 0x14);
    u_long128 *p = farFogPlane.field_0;
    p[0] = func_00254580_q(0x50000000 | ((unsigned long)(unsigned int)vu_game_0046D750 << 32), 0x03000000 | (0x020000B4UL << 32));
    p[1] = func_00254580_q(0x10000000, 0x15000000UL << 32);
    p[2] = func_00254580_q(0x10000003, 0x50000003UL << 32);
    skyUserSwitch1.field_0 = vu_game_0046D750;
    p[3] = func_00254580_q(0x8002 | (0x10000000UL << 32), 0xE);
    p[4] = func_00254580_q(5, 8);
    p[5] = func_00254580_q(skyZbuf_1 | (1UL << 32), 0x4E);
    p[6] = func_00254580_q(0x10000007, 0x01000101 | (0x6C0703F9UL << 32));
    UnkStruct_00254580_cd *cd = func_00254580_cd();   // [C] re-read after the calls (lw D_00667050 again)
    CGtV3dPlus r0;
    r0.SetGtV3d(cd->field_E0[0]);
    func_00254580_inl1(r0, cd->field_E0[0].Z());
    *(CGtV3dPlus *)&p[7] = r0;
    CGtV3dPlus r1;
    r1.SetGtV3d(cd->field_E0[1]);
    func_00254580_inl1(r1, cd->field_E0[1].Z());
    *(CGtV3dPlus *)&p[8] = r1;
    CGtV3dPlus r2;
    r2.SetGtV3d(cd->field_E0[2]);
    func_00254580_inl1(r2, cd->field_E0[2].Z());
    *(CGtV3dPlus *)&p[9] = r2;
    CGtV3dPlus r3;
    r3.SetGtV3d(cd->field_E0[3]);
    func_00254580_inl1(r3, cd->field_E0[3].Z());
    *(CGtV3dPlus *)&p[10] = r3;
    CGtV4d r11;                             // [C] all four lanes set
    r11.SetX(cd->field_218);
    r11.SetY(cd->field_21C);
    r11.SetZ(cd->field_200);
    r11.SetA(cd->field_204);
    *(CGtV4d *)&p[11] = r11;
    CGtV4d r12;
    r12.SetX(cd->field_170);
    r12.SetY(cd->field_174);
    r12.SetZ(cd->field_178);
    r12.SetA(cd->field_168);
    *(CGtV4d *)&p[12] = r12;
    p[13] = func_00254580_q(6 | (0x10000000UL << 32), 0xE);
    farFogPlane.field_0 = p + 14;
    for (int i = 0; i < mnNumRenderableArrays__19CB3ParticleRenderer; i++)
        DispatchArray__19CB3ParticleRendererFPQ219CB3ParticleRenderer24CB3ParticleRendererEntry(&D_01D9D010[i]);
    u_long128 *q = farFogPlane.field_0;
    q[0] = func_00254580_q(0x10000005, 0x10000000 | (0x50000005UL << 32));
    q[1] = func_00254580_q(0x8004 | (0x10000000UL << 32), 0xE);
    q[2] = func_00254580_q(skyAlpha_1, 0x42);
    q[3] = func_00254580_q(skyTest_1, 0x47);
    q[4] = func_00254580_q(skyZbuf_1, 0x4E);
    q[5] = func_00254580_q(skyClamp_1, 8);
    farFogPlane.field_0 = q + 6;
}
