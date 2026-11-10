// NONMATCHING: Update__19CB3SoundTrafficPassFfPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3df -- retail 460 / ours 447 instructions, 511 in changed runs
// fix2 (2026-11-01): taskB: field_10 written as one quad (w = p4.w, retail sqc2 0x2784D4); rand() % 4 (signed, 0x2781E8); a stray pad_20 byte put field_20..field_38 4 high (retail lw 0x20, lwc1 0x24..0x2C, lw 0x30..0x38) [C] retail 0x278068; the normalised a2 vector is written back through the pointer as retail 0x2784B4 (the draft normalised a local copy only) | Before: son7 first archive: pass-by state machine (cooldown, running voice update, new voice start with rand()&3 sample names, pitch/volume from distance) decoded with real field offsets; the Normalise/dot VU0 code is scalar math (retail uses inline vrsqrt/vmulq), the D_01E78Exx float table names are address-only; retail 460 vs ours 508 instrs
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)



// CB3SoundTrafficPass::Update -- hand-written (son7) first archive. Per traffic car pass-by: keeps a running voice
// (Doppler-ish pitch/volume from the approach direction), or, when a previous cooldown has expired and the car crosses the
// listener, starts a new pass-by sample ("pass_%d"-style names formatted with sprintf from rand() & 3). The Normalise /
// dot-product VU0 code is written as scalar math [G]. Field names are placeholders and every type is [G].
#include "b3/GtMathPs2.h"
extern "C" int sprintf(char *, const char *, ...);
extern "C" int rand(void);
extern "C" float sqrtf(float);
using namespace GtMathPs2;

struct UnkStruct_Traffic_params {
    float field_0[3]; unsigned char pad_C[0xC];
    int field_18; float field_1C; unsigned char pad_20[0x24];
    unsigned char field_44; unsigned char field_45; unsigned char pad_46[0xA];
};
struct UnkStruct_Traffic_voice { unsigned char pad_0[0xC]; int field_C; };
struct UnkStruct_Traffic_mat { float field_0[4]; };
struct UnkStruct_Traffic_cam { unsigned char pad_0[0x204]; UnkStruct_Traffic_mat *field_204; };
struct UnkStruct_Traffic_tab { UnkStruct_Traffic_cam *field_0; unsigned char pad_4[0x2C]; };
class CB3SoundTrafficPass {
public:
    void Update(float, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *, float);
    UnkStruct_Traffic_voice *field_0;
    unsigned char field_4;
    unsigned char field_5;
    unsigned char field_6;
    unsigned char pad_7;
    int field_8_i;
    int field_C_pad;
    float field_10[4];
    int field_20;                           // fix2: a stray pad_20 byte put field_20.. 4 high [C] retail 0x278068 lw 0x20
    float field_24;
    float field_28;
    float field_2C;
    float field_30;
    int field_34;
    int field_38;
};
extern float D_004E139C, D_004E1358;
extern float D_01E78E90, D_01E78E94, D_01E78E98, D_01E78E9C, D_01E78EA0, D_01E78EA4, D_01E78EAC, D_01E78EB0, D_01E78EB4,
    D_01E78EB8, D_01E78EBC, D_01E78EC0, D_01E78EC4;
extern int D_01E78E58;
extern int D_01E78E5C;
extern UnkStruct_Traffic_tab D_0055EFEC[];
extern char D_004BE370[], D_004BE378[], D_004BE388[], D_004BE398[];
extern unsigned char D_01E75648[];
extern unsigned char D_01E7569C[];
extern "C" unsigned long GtIDCompress__FPCc(const char *);
extern "C" int FindWave__19CGtSoundBankManagerCFRCUlb(void *, const void *, bool);
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);
extern "C" int IsPlaying__20CGtSoundVirtualVoiceFv(void *);
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" void Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(void *, const void *);
extern "C" int TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(void *, const void *);
extern "C" void SetPriority__20CGtSoundVirtualVoiceFf(void *, float);

static inline float func_00278020_len(const float *v) { return v[0] * v[0] + v[1] * v[1] + v[2] * v[2]; }
static inline float func_00278020_dot(const float *a, const float *b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }
static inline float func_00278020_abs(float x) { return x < 0.0f ? -x : x; }

// 0x00278020
void CB3SoundTrafficPass::Update(float vol, CGtV3d *p4, CGtV3d *p5, CGtV3d *p6, CGtV3d *p7, float dist)
{
    if (field_20 == 7) return;
    float k = D_004E139C;
    if (D_004E139C <= vol) k = vol;
    if (field_4 != 0 || dist <= -D_01E78E90) {
        if (field_4 != 1 || field_0 == 0) {
            if (field_6 > 0x3C) field_6 = 0x3C;
            if (field_6 != 0) {
                field_6--;
                return;
            }
        }
        if (field_4 == 1 && field_0 != 0) {
            if (IsPlaying__20CGtSoundVirtualVoiceFv(field_0) == 0 || field_34 != field_0->field_C) {
                field_6 = 0x3C;
                field_4 = 0;
                field_0 = 0;
                return;
            }
            UnkStruct_Traffic_params p;
            Construct__19CGtSoundVoiceParamsFv(&p);
            unsigned long name = GtIDCompress__FPCc(D_004BE370);
            p.field_18 = FindWave__19CGtSoundBankManagerCFRCUlb(D_01E75648, &name, false);
            union { float f[4]; u_long128 q; } pv;
            pv.q = p6->mData;
            p.field_0[0] = pv.f[0]; p.field_0[1] = pv.f[1]; p.field_0[2] = pv.f[2];
            Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(field_0, &p);
            field_5++;
        }
        float f21 = 0.0f, f22 = 0.0f, f20 = 0.0f;
        if (field_4 == 0) {
            union { float f[4]; u_long128 q; } a, b, c, d;
            a.q = p5->mData; b.q = p7->mData; c.q = p4->mData; d.q = p6->mData;
            float la = 1.0f / sqrtf(func_00278020_len(a.f));
            float lb = 1.0f / sqrtf(func_00278020_len(b.f));
            float na[3];   // taskB: element stores (an initializer list made ours zero-fill the array first)
            na[0] = a.f[0] * la;
            na[1] = a.f[1] * la;
            na[2] = a.f[2] * la;
            float nb[3];   // taskB: element stores (an initializer list made ours zero-fill the array first)
            nb[0] = b.f[0] * lb;
            nb[1] = b.f[1] * lb;
            nb[2] = b.f[2] * lb;
            f22 = func_00278020_abs(func_00278020_dot(na, nb));
            f22 = f22 * f22;
            f21 = f22 * D_01E78EB4;
            a.f[0] = na[0]; a.f[1] = na[1]; a.f[2] = na[2];
            p5->mData = a.q;                    // fix2: [C] retail 0x2784B4 writes the normalised vector back through a2 (w kept)
            // taskB: one quad store (sqc2 +0x10, 0x2784D4): xyz = p4 + n * field_30, w = p4's w (vadd.xyz keeps vf3.w) [C]
            field_10[0] = c.f[0] + na[0] * field_30;
            field_10[1] = c.f[1] + na[1] * field_30;
            field_10[2] = c.f[2] + na[2] * field_30;
            field_10[3] = c.f[3];
            float dv[3];   // taskB: element stores (an initializer list made ours zero-fill the array first)
            dv[0] = d.f[0] - field_10[0];
            dv[1] = d.f[1] - field_10[1];
            dv[2] = d.f[2] - field_10[2];
            float ld = 1.0f / sqrtf(func_00278020_len(dv));
            float nd[3];   // taskB: element stores (an initializer list made ours zero-fill the array first)
            nd[0] = dv[0] * ld;
            nd[1] = dv[1] * ld;
            nd[2] = dv[2] * ld;
            float cd = func_00278020_abs(func_00278020_dot(nd, (float *)D_0055EFEC[field_38].field_0->field_204));
            float m = f21 < cd ? f21 : cd;
            f21 = (f21 - m) / f21;
            float t = ((D_01E78E94 - D_01E78E90) - (dist - D_01E78E90)) / (D_01E78E94 - D_01E78E90);
            t = t > 0.0f ? t : 0.0f;
            t = t < 1.0f ? t : 1.0f;
            f20 = t * (D_01E78EB0 - D_01E78EAC) + D_01E78EAC + 0.0f;
            field_2C = t * (D_01E78E9C - D_01E78E98) + D_01E78E98 + 0.0f;
            D_01E78E58 = D_01E78E58 * 0x10000 + (D_01E78E58 >> 16) + D_01E78E5C;
            D_01E78E5C = D_01E78E5C + D_01E78E58;
            field_2C = (field_2C + ((float)((unsigned int)D_01E78E58 % 2000) / 10000.0f - D_004E1358)) *
                       (f21 * (D_01E78EB8 - D_01E78EBC) + (D_01E78EBC + 0.0f));
            field_30 = -(dist * (D_01E78EA0 / field_2C)) - D_01E78EA4 / 2.0f;
            field_28 = field_24;
            field_24 = func_00278020_dot(nd, na);
        }
        if (field_28 >= 0.0f && field_24 < 0.0f && field_4 == 0) {
            char name[16];
            float base;
            if ((unsigned int)(field_20 - 1) < 2) {
                sprintf(name, D_004BE378, rand() % 4 + 1);   // taskB: signed % 4 [C] 0x2781E8 bgez/andi/addiu -4
                base = D_01E78EC4;
            } else {
                sprintf(name, D_004BE388, rand() % 4 + 1);
                base = D_01E78EC0;
            }
            UnkStruct_Traffic_params p;
            Construct__19CGtSoundVoiceParamsFv(&p);
            unsigned long n1 = GtIDCompress__FPCc(name);
            p.field_18 = FindWave__19CGtSoundBankManagerCFRCUlb(D_01E75648, &n1, false);
            union { float f[4]; u_long128 q; } pp;
            pp.q = p4->mData;
            p.field_0[0] = pp.f[0]; p.field_0[1] = pp.f[1]; p.field_0[2] = pp.f[2];
            float vf = f20 * base * k * 2.0f * f22 * f21;
            p.field_1C = vf;
            *(float *)((char *)this + 8) = vf;
            p.field_44 = 10;
            p.field_45 = 0;
            unsigned long n2 = GtIDCompress__FPCc(D_004BE398);
            int w = FindWave__19CGtSoundBankManagerCFRCUlb(D_01E75648, &n2, false);
            *(float *)((char *)&p + 0x24) = field_2C * CalcFrequency__12CGtSoundWaveCFv((void *)w);
            field_0 = (UnkStruct_Traffic_voice *)TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(D_01E7569C, &p);
            field_5 = 0;
            if (field_0 != 0) {
                SetPriority__20CGtSoundVirtualVoiceFf(field_0, 1.0f);
                field_34 = field_0->field_C;
                field_4 = 1;
            }
        }
    }
}
