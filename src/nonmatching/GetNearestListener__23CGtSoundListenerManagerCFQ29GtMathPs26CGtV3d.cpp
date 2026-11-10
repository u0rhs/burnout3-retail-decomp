// NONMATCHING: GetNearestListener__23CGtSoundListenerManagerCFQ29GtMathPs26CGtV3d -- retail 72 / ours 71 instructions, 46 in changed runs
// near32: 46 off (71/72). Return tail now as retail via a static inline select (r = lb / r = la; move s2,s3; move v0,s2); unsigned field_8 gives sltiu; py/pz taken after the first call; A floats declared z,y,x. Left: retail la s3 / lb s2 / py s1 / pz s0 (ours s1/s0/s3/s2), early return out of line at the end, prologue store order. sreg 2 rounds no gain
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// ~47 instrs: structure right (N140 pad, *py/*pz pointers for a.y/a.z held in s-regs, scalar mula/madda squared lengths); remaining: s0-s3 assignment (retail s3=A,s2=B,s1=&a.y,s0=&a.z), f20-22 = A.x,y,z order, and retail's s2=s3 return tail (duplicated move). 5 rounds

#include "b3/GtMathPs2.h"
struct F3 { float x, y, z; };
class CGtSoundListener;
extern "C" int GetRWAListener__16CGtSoundListenerFv(void *);
struct UnkStruct_RwaListener { unsigned char pad_0[0x48]; F3 pos; };
struct UnkStruct_00384A60_pad {
    unsigned char field_0[0x10];
    UnkStruct_00384A60_pad() {}
    ~UnkStruct_00384A60_pad() {}
};
class CGtSoundListenerManager {
public:
    CGtSoundListener *GetNearestListener(GtMathPs2::CGtV3d p0) const;
    CGtSoundListener *field_0;
    CGtSoundListener *field_4;
    unsigned int field_8;
};
static inline CGtSoundListener *func_00384A60_inl1(float bl, float al, CGtSoundListener *la, CGtSoundListener *lb)
{
    CGtSoundListener *r;
    if (bl < al) r = lb;
    else r = la;
    return r;
}

CGtSoundListener *CGtSoundListenerManager::GetNearestListener(GtMathPs2::CGtV3d p0) const
{
    UnkStruct_00384A60_pad pad;
    GtMathPs2::CGtV3d c = p0;
    F3 a = *(F3 *)&c;
    float adz, ady, adx;
    CGtSoundListener *la = field_0;
    CGtSoundListener *lb = field_4;
    if (field_8 < 2) return la;
    UnkStruct_RwaListener *ra = (UnkStruct_RwaListener *)GetRWAListener__16CGtSoundListenerFv(la);
    float *py = &a.y;
    float *pz = &a.z;
    adx = ra->pos.x - a.x;
    ady = ra->pos.y - *py;
    adz = ra->pos.z - *pz;
    UnkStruct_RwaListener *rb = (UnkStruct_RwaListener *)GetRWAListener__16CGtSoundListenerFv(lb);
    float bdx = rb->pos.x - a.x;
    float bdy = rb->pos.y - *py;
    float bdz = rb->pos.z - *pz;
    float bl = bdy * bdy + bdx * bdx + bdz * bdz;
    float al = ady * ady + adx * adx + adz * adz;
    return func_00384A60_inl1(bl, al, la, lb);
}
