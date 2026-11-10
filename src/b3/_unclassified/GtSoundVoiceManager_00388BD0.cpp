// CGtSoundVoiceManager::TriggerRealVoice(const CGtSoundVoiceParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVoiceManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (near2: voice pop written in place with gotos (zero stub between the pop's return-v stub and body); near1's link-name GetNearestListener + local sqlen/mtc1 stand-in [L] N185).

// CGtSoundVoiceManager::TriggerRealVoice(const CGtSoundVoiceParams *) -- hand-finished (near2, 2026-10-27; earlier
// v241/hdr7/near1 archive). [G] meaning: unless the params are flagged (field_45), a zero volume (field_1C) returns 0;
// a positional voice (flag bit 2 of field_18->field_8->field_54) farther than 50 from the nearest listener returns 0;
// otherwise pop a free real voice (field_1E24 stack, count field_1E3C), unmute/mute its dry sends and start it.
// [G] the voice pop is written in place with gotos (it was a static inline): retail lays the field_1C==0 return-0
// stub between the pop's return-v stub and its body, which only this goto order reproduces.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00388BD0_4 {
    unsigned char pad_0[0x54];
    int field_54;
};
struct UnkStruct_00388BD0_3 {
    unsigned char pad_0[0x8];
    UnkStruct_00388BD0_4 * field_8;
};
class CGtSoundVoiceParams {
public:
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0xC];
    UnkStruct_00388BD0_3 * field_18;
    float field_1C;
    unsigned char pad_20[0x25];
    unsigned char field_45;
};
class CGtSoundListener {
public:
    void GetPos(CGtV3d * p) const;
};
class CGtSoundListenerManager;
class CGtSoundRealVoice {
public:
    void MuteDryVoice(int, bool);
    void Start(const CGtSoundVoiceParams * p);
    unsigned char pad_0[0x20];
};
struct UnkStruct_00388BD0_self {
    unsigned char pad_0[0x1A04];
    CGtSoundRealVoice field_1A04[16];
    unsigned char pad_1C04[0x220];
    unsigned char field_1E24[16];
    CGtSoundListenerManager * field_1E34;
    int field_1E38;
    int field_1E3C;
};

// [L] N185: CGtV3d::GetSquaredLength() + XAxisType::operator float() stand-in (header body; the lane read from the
// result register, not through the temporary's address -- retail keeps no slot for it here)
static inline float func_00388BD0_inl5(const CGtV3d &v)
{
    u_long128 sq, one, t, d;
    asm("vmul.xyz %0, %1, %1" : "=j"(sq) : "j"(v.mData));
    asm("vaddw.x %0, $vf0, $vf0w" : "=j"(one));
    asm(".set noreorder");
    asm("vadday.x $ACC, %1, %1y" "\n\t" "vmaddz.x %0, %2, %1z" : "=j"(t) : "j"(sq), "j"(one));
    asm(".set reorder");
    asm("qmfc2 %0, %1" : "=r"(d) : "j"(t));
    float f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(d));
    return f;
}
static inline int func_00388BD0_inl3(const CGtSoundVoiceParams * p) { return (p->field_18->field_8->field_54 & 2) != 0; }
// [G] called by its link name with the vector by address: retail passes &pos itself (no caller copy; our header's
// CGtV3d has a user copy ctor, which forces one)
extern "C" CGtSoundListener * GetNearestListener__23CGtSoundListenerManagerCFQ29GtMathPs26CGtV3d(const CGtSoundListenerManager *, const CGtV3d &);

extern "C" CGtSoundRealVoice * TriggerRealVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(UnkStruct_00388BD0_self * self, const CGtSoundVoiceParams * p)
{
    CGtSoundRealVoice * v;
    if (p->field_45 == 0) {
        if (p->field_1C == 0.0f)
            goto zero;
        if (func_00388BD0_inl3(p)) {
            CGtV3d pos(p->field_0, p->field_4, p->field_8);
            CGtSoundListener * l = GetNearestListener__23CGtSoundListenerManagerCFQ29GtMathPs26CGtV3d(self->field_1E34, pos);
            CGtV3d lp;
            l->GetPos(&lp);
            pos -= lp;
            if (!(func_00388BD0_inl5(pos) <= (float)2500))
                return 0;
        }
    }
    v = 0;
    if (self->field_1E3C != 0) goto alloc;
ret:
    return v;
zero:
    return 0;
alloc:
    v = &self->field_1A04[self->field_1E24[--self->field_1E3C]];
    v->MuteDryVoice(0, false);
    v->MuteDryVoice(1, true);
    v->Start(p);
    goto ret;
}
