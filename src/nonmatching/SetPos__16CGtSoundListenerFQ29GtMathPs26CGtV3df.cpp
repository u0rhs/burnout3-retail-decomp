// NONMATCHING: SetPos__16CGtSoundListenerFQ29GtMathPs26CGtV3df -- retail 92 / ours 92 instructions, 2 in changed runs
// near25: pos read into px/py/pz locals before the bits test + float decls 'vz,vy,vx; oz,oy,ox' fixed all FP registers (29 -> 2); left: 'mov.s f20,f12' (t into f20) scheduled 2 slots early (retail after the a.x/a.y lwc1s); statement-order, pun, helper-inline and pad-position variants all stay at 2. Uses the mfc1 asm (same idiom as proven func_00288480)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// 27-29 instrs, register-only: retail t=f20, old vel o=f23/22/21, new vel v=f24/25/26 (held across RwV3dLength); ours scrambles. float-bits test needs mfc1 (asm used here, unapproved; a plain *(unsigned*)&dt pun spills to stack). 40 decl-order permutations tried
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
struct F3 { float x, y, z; };
struct UnkStruct_Lis {
    unsigned char pad_0[0x48];
    F3 pos;
    F3 vel;
    unsigned char pad_60[0x24];
    unsigned int flags;
};
extern "C" float RwV3dLength(const F3 *);
class CGtSoundListener {
public:
    void SetPos(GtMathPs2::CGtV3d p0, float t);
    unsigned char pad_0[4];
    float field_4;
    UnkStruct_Lis *field_8;
};
struct UnkStruct_003847B0_pad {
    unsigned char field_0[0x10];
    UnkStruct_003847B0_pad() {}
    ~UnkStruct_003847B0_pad() {}
};
void CGtSoundListener::SetPos(GtMathPs2::CGtV3d p0, float t)
{
    UnkStruct_003847B0_pad pad;
    GtMathPs2::CGtV3d c = p0;
    F3 a = *(F3 *)&c;
    float vz, vy, vx; float oz, oy, ox;
    float dt = t - field_4;
    unsigned int bits;
    asm("mfc1 %0,%1" : "=r"(bits) : "f"(dt));
    UnkStruct_Lis *s = field_8;
    float px = s->pos.x; float py = s->pos.y; float pz = s->pos.z;
    if ((bits & 0x7F800000) >= 0x37800001) {
        vx = (a.x - px) / dt;
        vy = (a.y - py) / dt;
        vz = (a.z - pz) / dt;
        ox = s->vel.x;
        oy = s->vel.y;
        oz = s->vel.z;
        F3 d;
        d.x = vx - ox;
        d.y = vy - oy;
        d.z = vz - oz;
        if (RwV3dLength(&d) > 100.0f) {
            vx = ox;
            vy = oy;
            vz = oz;
        }
        s = field_8;
        s->vel.x = vx;
        s->vel.y = vy;
        s->vel.z = vz;
        field_8->flags |= 2;
    }
    field_8->pos = a;
    field_8->flags |= 1;
    field_4 = t;
}
