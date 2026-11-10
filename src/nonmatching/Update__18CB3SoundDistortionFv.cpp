// NONMATCHING: Update__18CB3SoundDistortionFv -- retail 209 / ours 192 instructions, 98 in changed runs
// ghvu11 first draft: flow right (car via D_0055EFEC stride 0x30, listener pos/right, unit X/Y axes via compiler-chosen SetX/Y/Z, IsZero -> field_18E8=0 out of line, normalise right and car-listener delta (Normalise+1*Q stand-in), dot -> field_18E8, second dot -> CalculateGainPair, 65536 fixed-point gains, CalculateDistance, Sif RPC kick); left: retail passes copies of lpos/ax/ay/right/pos at sp+0xA0/0x90/0x80/0x70/0x60 (looks like by-value params of an inlined helper), a third normalise of ax with its result dead, VU numbering (dot on vf5/vf4), frame 0x100 vs 0xF0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3SoundDistortion::Update() -- hand-written from the Ghidra draft (ghvu11).
// [C] name: the mangled symbol in retail's tables (high). Field names are placeholders and every type is [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_002FCA60_b { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_002FCA60_car { unsigned char pad_0[0x204]; UnkStruct_002FCA60_b *field_204; };
struct UnkStruct_D_0055EFEC_r { UnkStruct_002FCA60_car *field_0; unsigned char pad_4[0x2C]; };
extern UnkStruct_D_0055EFEC_r D_0055EFEC[];
extern unsigned char D_01E75688[];
extern unsigned char D_01E75640[];
extern "C" void *GetFixedListener__23CGtSoundListenerManagerCFv(const void *);
extern "C" void GetPos__16CGtSoundListenerCFPQ29GtMathPs26CGtV3d(const void *, CGtV3d *);
extern "C" void GetRight__16CGtSoundListenerCFPQ29GtMathPs26CGtV3d(const void *, CGtV3d *);
extern "C" int GetSpeakerConfig__15CB3SoundManagerFv(void *);
extern "C" int sceSifCheckStatRpc(void *);
extern "C" int sceSifCallRpc(void *, unsigned int, unsigned int, void *, int, void *, int, void *, void *);
// [L] N185: Normalise that also forms 1.0*Q (result unused), as proven func_00287970_inl1
static inline void func_002FCA60_inl1(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 one;
    CGtV3d r;
    asm(".set noreorder");
    asm("qmtc2.i %2, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %1, $vf1" "\n\t"
        "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(v.mData), "=&r"(one) : "r"(l.lVector));
    asm("qmtc2.i %1, $vf1" "\n\t" "qmfc2.i %0, %2" "\n\t" "vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %1, $vf1" : "=r"(r.mData), "+r"(one) : "j"(v.mData));
    asm(".set reorder");
    v = r;
}
// [L] N185: compiler-chosen vsub stand-in
static inline CGtV3d func_002FCA60_inl2(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
static inline float func_002FCA60_inl3(u_long128 x) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(x)); return f; }

class CB3SoundDistortion {
public:
    void Update();
    void CalculateGainPair(float, float, bool, float *, float *);
    void CalculateDistance(CGtV3d *, CGtV3d *);
    unsigned char pad_0[0x1840];
    int field_1840;
    int field_1844;
    unsigned char pad_1848[7];
    bool field_184F;
    unsigned char pad_1850[0x80];
    int field_18D0;
    unsigned char pad_18D4[0xC];
    float field_18E0;
    float field_18E4;
    float field_18E8;
    unsigned char pad_18EC[0x14];
    unsigned char field_1900[4];
    unsigned char field_1904[0x3FC];
    int *field_1D00;
    void *field_1D04;
    unsigned char pad_1D08[8];
    unsigned char field_1D10[0x10];
};

// 0x002FCA60
void CB3SoundDistortion::Update()
{
    UnkStruct_002FCA60_car *car = D_0055EFEC[field_18D0].field_0;
    if (car == 0) return;
    CGtV3d pos = car->field_204->field_30;
    void *l = GetFixedListener__23CGtSoundListenerManagerCFv(D_01E75688);
    CGtV3d lpos;
    GetPos__16CGtSoundListenerCFPQ29GtMathPs26CGtV3d(l, &lpos);
    CGtV3d right;
    GetRight__16CGtSoundListenerCFPQ29GtMathPs26CGtV3d(l, &right);
    CGtV3d ax;
    ax.SetX(1.0f); ax.SetY(0.0f); ax.SetZ(0.0f);
    CGtV3d ay;
    ay.SetX(0.0f); ay.SetY(1.0f); ay.SetZ(0.0f);
    CGtV3d lp = lpos, a = ax, b = ay, r = right;
    GetSpeakerConfig__15CB3SoundManagerFv(D_01E75640);
    CGtV3d p = pos;
    if (pos.IsZero()) field_18E8 = 0.0f;
    CGtV3d d = func_002FCA60_inl2(p, lp);
    func_002FCA60_inl1(r);
    func_002FCA60_inl1(d);
    field_18E8 = func_002FCA60_inl3(DotProduct(r, d).lVector);
    func_002FCA60_inl1(a);
    CalculateGainPair(field_18E8, func_002FCA60_inl3(DotProduct(r, d).lVector), field_184F, &field_18E0, &field_18E4);
    field_1840 = (int)(65536.0f * field_18E0);
    field_1844 = (int)(65536.0f * field_18E4);
    CalculateDistance(&lpos, &pos);
    if (*field_1D00 != 0) {
        if (sceSifCheckStatRpc(field_1D10) != 1) {
            sceSifCallRpc(field_1D10, 0x150276, 1, field_1900, 0x400, 0, 0, 0, 0);
        }
        *field_1D00 = 0;
        field_1D04 = field_1904;
    }
}
