// NONMATCHING: Update__16CB3SoundListenerFv -- retail 449 / ours 444 instructions, 569 in changed runs
// draftAO (2026-11-01): quaternion stand-in replaced by retail's CGtQuat::ConvertToMatrix (sqrt2 scale, (1-xx)-yy row order) into one declared-first matrix; owner +0x210 as CGtQuatPos; vfunc_B8 typed; setters get the row addresses as retail | Before: psweep: scoped #pragma inline_depth(3) [G] improves 1114 -> 1059
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm (0x28A450..0x28AB50): calls the same multiset with retail's arguments, non-stack stores (+0xC, +0x18) as retail, ConvertToMatrix lanes checked; behaviour_audit quiet

// CB3SoundListener::Update -- son7 first archive; draftAO (2026-11-01): the quaternion -> rows scalar stand-in replaced by
// retail's CGtQuat::ConvertToMatrix (GtMathPs2Quat.h; [C] the same sqrt(2) scale D_004E07B8 = 0x3FB504F3, lane products and
// (1-xx)-yy / (1-xx)-zz / (1-yy)-zz rows, retail 0x28A648..0x28A7B4 and 0x28A904..0x28AA70), assigned into one declared-first
// matrix (retail's 0x910 copy reached through 16-byte lb/sb loops; its row 3 copies ConvertToMatrix's never-written mPos).
// Picks the listener's pos/at/up from the active camera (key = the camera state's 64-bit id, as func_0027BCE0 / the
// PlayerCamera sources compare) and calls CGtSoundListener::SetAt / SetUp / SetPos. Field names are placeholders and every
// type is [G]; ids are the camera-state class hashes.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct UnkStruct_Cam {
    unsigned char pad_0[0x204];
    CGtMatrix3x4 *field_204;       // [L] camera matrix: rows up +0x10, at +0x20, pos +0x30 read
    unsigned char pad_208[8];
    unsigned char field_210;       // [G] nonzero: use the owner's orientation instead of the camera's
};
struct UnkStruct_Cam_tab { UnkStruct_Cam *field_0; unsigned char pad_4[0x2C]; };   // stride 0x30
struct UnkStruct_Owner_id { unsigned long field_0; };
struct UnkStruct_Owner {
    unsigned char pad_0[4];
    UnkStruct_Owner_id *field_4;
    unsigned char pad_8[0x208];
    CGtQuatPos field_210;          // [L] orientation +0x210 (quat), position +0x220 (retail lqc2 0x10(s1) / lq 0x20(s1), s1 = +0x200)
    unsigned char pad_230[0x958];
    float field_B88;
};
class CB3SoundListener {
public:
    void Update();
    unsigned char pad_0[0xC];
    unsigned char field_C;         // [G] 1 = listener follows the owner (chase views), 0 = the camera
    UnkStruct_Owner *field_10;
    int field_14;                  // camera table index (D_0055EFEC, stride 0x30)
    float field_18;                // [G] extra height for the 0xBA38E7C8878337FF view, grows by 1 per frame below 500
};
extern unsigned char D_0051BAA4;
extern long D_0064D370;
extern unsigned char D_004EE040[];
extern unsigned char D_00665EA0;
extern UnkStruct_Cam_tab D_0055EFEC[];
extern float D_004F50A0;
class UnkStruct_D_0051BA88_1B4 {
public:
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18();
    virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C();
    virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40();
    virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68();
    virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); virtual void vfunc_7C();
    virtual void vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90();
    virtual void vfunc_94(); virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4();
    virtual void vfunc_A8(); virtual void vfunc_AC(); virtual void vfunc_B0(); virtual void vfunc_B4();
    virtual int vfunc_B8();        // [C] retail 0x28A8A0: lw t9, 0(a0); lw t9, 0xB8(t9); jalr; result tested
};
struct UnkStruct_D_0051BA88 { unsigned char pad_0[0x1B4]; UnkStruct_D_0051BA88_1B4 *field_1B4; };
extern UnkStruct_D_0051BA88 *D_0051BA88;
extern "C" int func_00131E40(void *);
extern "C" void SetAt__16CGtSoundListenerFQ29GtMathPs26CGtV3d(CB3SoundListener *, CGtV3d *);
extern "C" void SetUp__16CGtSoundListenerFQ29GtMathPs26CGtV3d(CB3SoundListener *, CGtV3d *);
extern "C" void SetPos__16CGtSoundListenerFQ29GtMathPs26CGtV3df(CB3SoundListener *, CGtV3d *, float);

// 0x0028A450
void CB3SoundListener::Update()
{
    UnkStruct_Owner *o = field_10;
    CGtMatrix3x4 rot;
    CGtMatrix3x4 *m;
    CGtV3d pos;
    float f;
    if (o == 0) return;
    if (D_0051BAA4 == 0) return;
    if (D_0064D370 == 0) return;
    unsigned long key = o->field_4 != 0 ? o->field_4->field_0 : 0x6D6123044330FCCFUL;
    bool chase = key == 0xBA38E6DCF8C737FFUL || key == 0xBA38E82B9CC11F7FUL || key == 0xBA38E7C8878337FFUL;
    if (!chase && key == 0xBA38E5FB73BF9888UL && func_00131E40(D_004EE040) != 0) chase = true;
    if (!chase && key != 0xBA38E5FB73BFF1FFUL && D_00665EA0 == 0) {
        UnkStruct_Cam *c = D_0055EFEC[field_14].field_0;
        pos = c->field_204->mPos;
        if (c->field_210 == 0) {
            m = c->field_204;
            pos -= m->mAt;
            pos += c->field_204->mUp * 2.0f;
        } else {
            rot = o->field_210.mQuat.ConvertToMatrix();
            m = &rot;
            pos -= rot.mAt;
            pos += rot.mUp * 2.0f;
        }
        field_C = 0;
        f = D_004F50A0;
    } else {
        pos = o->field_210.mPos;
        rot = o->field_210.mQuat.ConvertToMatrix();
        m = &rot;
        pos -= rot.mAt;
        field_C = 1;
        f = field_10->field_B88;
        if (key == 0xBA38E7C8878337FFUL && D_0051BA88->field_1B4->vfunc_B8() != 0) {
            float y = pos.Y() + field_18;
            pos.SetY(y);
            if (y < 500.0f) field_18 += 1.0f;
        }
    }
    // [C] the three setters take the vectors by reference in practice (retail a1 = row address / &pos, 0x28A608..0x28A624)
    SetAt__16CGtSoundListenerFQ29GtMathPs26CGtV3d(this, &m->mAt);
    SetUp__16CGtSoundListenerFQ29GtMathPs26CGtV3d(this, &m->mUp);
    SetPos__16CGtSoundListenerFQ29GtMathPs26CGtV3df(this, &pos, f);
}

