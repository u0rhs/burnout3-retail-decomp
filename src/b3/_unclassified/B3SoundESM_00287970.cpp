// CB3SoundESMHigh::CalculateDoppler(const CB3RaceCar*,float*,float*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESM.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (Ghidra draft; Normalise+1*Q stand-in, local mtc1 lane reads (no N129 slots), compiler-chosen vsub stand-ins (operand order sets VU numbering)).

// CB3SoundESMHigh::CalculateDoppler(const CB3RaceCar*, float*, float*) -- hand-written from the Ghidra draft (ghvu7).
// [C] name: the mangled symbol in retail's tables. Field names are placeholders and every type is [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00287970_l { unsigned char pad_0[0xC]; unsigned char field_C; };
class CB3RaceCar { public: unsigned char pad_0[0x20]; CGtV3d field_20; CGtV3d field_30; unsigned char pad_40[0x14]; float field_54; };
struct UnkStruct_00287970_d { int x; };
extern unsigned char D_01E75688[];
extern "C" UnkStruct_00287970_l *GetFixedListener__23CGtSoundListenerManagerCFv(const void *);
extern "C" void GetPos__16CGtSoundListenerCFPQ29GtMathPs26CGtV3d(const UnkStruct_00287970_l *, CGtV3d *);
extern "C" void GetAt__16CGtSoundListenerCFPQ29GtMathPs26CGtV3d(const UnkStruct_00287970_l *, CGtV3d *);
extern "C" void GetVelocity__16CGtSoundListenerCFPQ29GtMathPs26CGtV3d(const UnkStruct_00287970_l *, CGtV3d *);
extern "C" void Update__15CB3SoundDopplerFffffPfPf(UnkStruct_00287970_d *, float, float, float, float, float *, float *);
extern "C" double fabs(double);

// [L] N185: stands in for a missing GtMathPs2 inline (a Normalise on a compiler-chosen register that also forms 1.0*Q,
// result unused; perhaps CGtV3d::NormaliseFast, B3O0PCH 188 bytes [G]).
static inline void func_00287970_inl1(CGtV3d &v)
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

// [L] N185: XAxisType -> float without the address-taken read (operator float's N129 slot; retail's frame has none).
static inline float func_00287970_inl2(u_long128 x) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(x)); return f; }

// [L] N185: CGtV3d::operator-(const CGtV3d&) on compiler-chosen registers (N198's second vsub form) stand-in
static inline CGtV3d func_00287970_inl3(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
// [L] N185: the same vsub with the operands listed b-first (VU numbering: a on the lower register, result in place on it).
static inline CGtV3d func_00287970_inl10(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %2, %1" : "=j"(r) : "j"(b.mData), "j"(a.mData)); return CGtV3d(r); }
class CB3SoundESMHigh {
public:
    unsigned char pad_0[0x94];
    UnkStruct_00287970_d field_94;
    void CalculateDoppler(const CB3RaceCar *, float *, float *);
};

// 0x00287970
void CB3SoundESMHigh::CalculateDoppler(const CB3RaceCar *car, float *p1, float *p2)
{
    UnkStruct_00287970_l *l = GetFixedListener__23CGtSoundListenerManagerCFv(D_01E75688);
    if (l->field_C == 0) {
        *p1 = 1.0f;
        *p2 = 1.0f;
        return;
    }
    CGtV3d pos, at, vel;
    GetPos__16CGtSoundListenerCFPQ29GtMathPs26CGtV3d(l, &pos);
    GetAt__16CGtSoundListenerCFPQ29GtMathPs26CGtV3d(l, &at);
    GetVelocity__16CGtSoundListenerCFPQ29GtMathPs26CGtV3d(l, &vel);
    CGtV3d d = func_00287970_inl3(car->field_30, pos);
    float len = func_00287970_inl2(d.GetLength().lVector);
    func_00287970_inl1(d);
    float c = func_00287970_inl2(CosAngleBetweenNormalisedVectors(d, at).lVector);
    float a = (float)fabs(len * c);
    CGtV3d v = func_00287970_inl10(car->field_20 * car->field_54, vel);
    float s = func_00287970_inl2(v.GetLength().lVector);
    Update__15CB3SoundDopplerFffffPfPf(&field_94, a, c * s, car->field_54, 1.0f, p2, p1);
}
