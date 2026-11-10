// NONMATCHING: Action__26CB3PlayerCameraStateReplayF14EGtStateActionPvPvPv -- retail 395 / ours 393 instructions, 2 in changed runs
// s318: 2 off (was 91). N215 void* lever on the manager parameter (void *pm copied into UnkStruct_Mgr *mgr) fixed the s0/s1/s2 rotation; 'const int k' in case 0x15 fixed the k/r s1/s2 swap. Left: retail has a nop between 'lui v0,0x7F80' and 'lui at,0x3780' of the exponent test (both CalcTime sites); ours schedules the sltu-constant lui/ori into it. Compare forms, inline bool helpers and 7 opt_* pragmas unchanged
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// Action__26CB3PlayerCameraStateReplayF14EGtStateActionPvPvPv -- CB3PlayerCameraStateReplay::Action(EGtStateAction,void*,void*,void*)
// [L] DNAT: CB3PlayerCameraStateReplay::Action(EGtStateAction,void*,void*,void*) (research/proto/new_names.csv, high)

#include "b3/GtMath.h"

enum EGtStateAction {};

struct UnkStruct_r { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_s { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_a { unsigned char pad_0[0x54]; float field_54; };
struct UnkStruct_e { int field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_F { float field_0; unsigned char pad_4[0xC]; };

class UnkStruct_Mgr {
public:
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    UnkStruct_r * field_4;
    unsigned char pad_8[0x8];
    UnkStruct_s * field_10;
    float field_14;
    unsigned char pad_18[0xAA8];
    unsigned char field_AC0[0x20];
    unsigned char pad_AE0[0xB4];
    int field_B94;
};

class CB3PlayerCameraStateReplay {
public:
    unsigned char pad_0[0x10];
    float field_10;
    float field_14;
};

extern UnkStruct_a * D_0064D388[];
extern UnkStruct_e D_0055EFEC[];
extern UnkStruct_F D_0051BAC8;

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void SetParameters__21CB3BehaviourTrackSideF16EB3BehaviourTypeP19CB3AttribsTrackSidei(int, void *, int);
extern "C" void SetActiveBehaviour__22CB3PlayerCameraManagerFi(void *, int);

static inline void SetBehaviour(UnkStruct_Mgr * mgr, unsigned long h, int k)
{
    UnkStruct_r * r = (UnkStruct_r *)GetStateFromID__6CGtFSMFUl(mgr, h);
    if (mgr->field_4 == r) {
        return;
    }
    mgr->vfunc_18(r, k);
    UnkStruct_r * t = mgr->field_4;
    mgr->field_4 = r;
    if (mgr->field_10 != 0) {
        mgr->field_14 = mgr->field_10->field_20;
        if (r != 0) {
            r->field_8 = mgr->field_10->field_20;
        }
    }
    mgr->vfunc_1C(t, k);
}

static inline void CalcTime(CB3PlayerCameraStateReplay * self, UnkStruct_Mgr * mgr)
{
    UnkStruct_a * a = D_0064D388[mgr->field_B94];
    float v = a->field_54;
    float t = 2.0f * v;
    t = GtMath::Max(t, 15.0f);
    t = GtMath::Min(t, 50.0f);
    if ((*(unsigned int *)&a->field_54 & 0x7F800000) > 0x37800000) {
        self->field_14 = GtMath::Min(3.0f, 1.0f + t / v);
    } else {
        self->field_14 = 3.0f;
    }
}

// 0x00300BF0
extern "C" void Action__26CB3PlayerCameraStateReplayF14EGtStateActionPvPvPv(CB3PlayerCameraStateReplay * self, EGtStateAction p0, void * pm, long p2, int p3)
{
    UnkStruct_Mgr * mgr = (UnkStruct_Mgr *)pm;
    switch (p0) {
    case 3:
        CalcTime(self, mgr);
        SetParameters__21CB3BehaviourTrackSideF16EB3BehaviourTypeP19CB3AttribsTrackSidei((int)(mgr->field_AC0), (void *)(0), mgr->field_B94);
        SetActiveBehaviour__22CB3PlayerCameraManagerFi(mgr, 8);
        self->field_10 = 0.0f;
        *(int *)&self->field_14 = 0x40400000;
        break;
    case 4:
        self->field_10 = self->field_10 + D_0051BAC8.field_0;
        if (self->field_10 > self->field_14) {
            CalcTime(self, mgr);
            SetParameters__21CB3BehaviourTrackSideF16EB3BehaviourTypeP19CB3AttribsTrackSidei((int)(mgr->field_AC0), (void *)(0), mgr->field_B94);
            SetActiveBehaviour__22CB3PlayerCameraManagerFi(mgr, 8);
            self->field_10 = 0.0f;
        }
        break;
    case 5:
        switch (p2) {
        case 0xE:
            SetBehaviour(mgr, 0xBA38E6DC828A38A1UL, 0);
            break;
        case 0x15:
            {
                const int k = D_0055EFEC[mgr->field_B94].field_0;
                SetBehaviour(mgr, 0xBA38E5FB73BF9888UL, k);
            }
            break;
        case 0x11:
            SetBehaviour(mgr, 0xBA38E6DCA6D42A7FUL, 0);
            break;
        case 0x13:
        case 0xD:
        case 0x7:
            break;
        case 0x16:
            SetBehaviour(mgr, 0xBA38E63A96099FBFUL, p3);
            break;
        case 0xF:
            SetBehaviour(mgr, 0xBA38E6DCF8C737FFUL, p3);
            break;
        case 0x12:
            SetBehaviour(mgr, 0xBA38E7C8878337FFUL, p3);
            break;
        }
        break;
    }
}


