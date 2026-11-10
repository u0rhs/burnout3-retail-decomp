// NONMATCHING: func_00441D70 -- retail 409 / ours 407 instructions, 18 in changed runs
// logic+layout exact (407/409, 18 changed): only the two inlined GetTime reads differ -- retail reads the 8-byte result through 'addiu v0,sp,K; lw a3,0(v0)' scheduled before the D_0064D388 load; struct/array/ptr/ref/union/u64/by-value-return/RVO/inline-wrapper forms all fold to 'lw a3,K(sp)'; opt_propagation off breaks the rest
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00441D70 -- placeholder (unnamed in every table); a camera-state Action (p1 = the camera manager FSM) [L].
// Hand-written (L243) after B3PlayerCameraStateInactive_002E80A0.cpp / B3PlayerCameraStateCrashMode_00357600.cpp.

enum EGtStateAction {};
struct UnkStruct_00441D70_1 { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_00441D70_2 { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_00441D70_F {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_00441D70_2 *, int);
    virtual void vfunc_1C(void *, int);
    void * field_4;
    unsigned char pad_8[0x8];
    UnkStruct_00441D70_1 * field_10;
    float field_14;
    unsigned char pad_18[0x390];
    unsigned char field_3A8;
    unsigned char pad_3A9[0x3F];
    unsigned char field_3E8;
    unsigned char pad_3E9[0x3F];
    unsigned char field_428;
    unsigned char pad_429[0x497];
    unsigned char field_8C0[0x134];
    int field_9F4;
    unsigned char pad_9F8[0x188];
    unsigned long field_B80;
    unsigned char pad_B88[0xC];
    int field_B94;
    unsigned char pad_B98[0x4];
    int field_B9C;
};
struct UnkStruct_00441D70 {
    unsigned char pad_0[0x10];
    void * field_10;
    float field_14;
};
struct UnkStruct_00441D70_t { unsigned int field_0; int field_4; };
extern "C" void GetTime__19CGtHiResSystemTimerFv(UnkStruct_00441D70_t *);
struct UnkStruct_00441D70_Fl { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_00441D70_Fl D_0051BAC8;
extern void * D_0064D388[];  // [G] element count unknown
extern "C" UnkStruct_00441D70_2 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

extern "C" void SetActiveBehaviour__22CB3PlayerCameraManagerFi(void *, int);
extern "C" void SetParameters__23CB3BehaviourInterpolateF24EB3PlayerCameraBehaviour24EB3PlayerCameraBehaviourf20EB3InterpolationType24EB3InterpolationTimeMode(void *, int, int, float, int, int);

static inline void SetScene(UnkStruct_00441D70_F * fsm, unsigned long h, int k)
{
    UnkStruct_00441D70_2 * r1 = GetStateFromID__6CGtFSMFUl(fsm, h);
    if (fsm->field_4 == r1) return;
    fsm->vfunc_18(r1, k);
    void * t0 = fsm->field_4;
    fsm->field_4 = (void *)r1;
    UnkStruct_00441D70_1 * t1 = fsm->field_10;
    if (t1 != 0) {
        fsm->field_14 = t1->field_20;
        if (r1 != 0) {
            r1->field_8 = fsm->field_10->field_20;
        }
    }
    fsm->vfunc_1C(t0, k);
}

// [G] placeholder inline: timer-seeded pick of one of 12 views, repeated in two cases
static inline void func_00441D70_inl1(UnkStruct_00441D70 * self, UnkStruct_00441D70_F * m)
{
    UnkStruct_00441D70_t t;
    GetTime__19CGtHiResSystemTimerFv(&t);
    self->field_10 = D_0064D388[m->field_B94];
    int v = t.field_0;
    int x = ~v;
    x = (x << 16) + (x >> 16);
    x += v;
    m->field_3A8 = (unsigned int)x % 12;
    m->field_3E8 = m->field_3A8;
    m->field_428 = m->field_3A8;
    SetActiveBehaviour__22CB3PlayerCameraManagerFi(m, 0x11);
    SetParameters__23CB3BehaviourInterpolateF24EB3PlayerCameraBehaviour24EB3PlayerCameraBehaviourf20EB3InterpolationType24EB3InterpolationTimeMode(m->field_8C0, 0x11, 0x12, 1.4f, 3, 1);
}

extern "C" void func_00441D70(UnkStruct_00441D70 * self, EGtStateAction p0, void * p1, void * p2, void * p3)
{
    UnkStruct_00441D70_F * m = (UnkStruct_00441D70_F *)p1;
    switch (p0) {
    case 0:
        m->field_3A8 = 12;
        self->field_14 = -1.0f;
        break;
    case 3:
        func_00441D70_inl1(self, m);
        break;
    case 5:
        switch ((int)p2) {
        case 0x11:
            if (m->field_B9C != 2) {
                SetParameters__23CB3BehaviourInterpolateF24EB3PlayerCameraBehaviour24EB3PlayerCameraBehaviourf20EB3InterpolationType24EB3InterpolationTimeMode(m->field_8C0, 2, m->field_B9C, 0.5f, 1, 1);
            }
            SetScene(m, 0xBA38E6DCA6D42A7FUL, 0);
            break;
        case 0xF:
            SetScene(m, 0xBA38E6DCF8C737FFUL, 0);
            break;
        case 0x10:
            func_00441D70_inl1(self, m);
            break;
        case 0x14:
            SetScene(m, 0xBA38E82B9CC11F7FUL, 0);
            break;
        case 0x16:
            SetScene(m, 0xBA38E63A96099FBFUL, (int)p3);
            break;
        case 0xE:
            SetScene(m, 0xBA38E6DC828A38A1UL, (int)p3);
            break;
        case 0x12:
        case 0x13:
        case 0x15:
            break;
        default:
            goto out;
        }
        break;
    case 4:
        {
            unsigned long fl = m->field_B80 & 0x400;
            if (fl == 0 && m->field_9F4 == 0x12 && self->field_14 == -1.0f) {
                self->field_14 = 0.1f;
            } else if (fl == 0 && m->field_9F4 == 0x13 && self->field_14 == -1.0f) {
                self->field_14 = 0.1f;
            } else if (fl == 0 && m->field_9F4 == 0x12 && self->field_14 <= 0.0f) {
                SetActiveBehaviour__22CB3PlayerCameraManagerFi(m, 0x12);
                SetParameters__23CB3BehaviourInterpolateF24EB3PlayerCameraBehaviour24EB3PlayerCameraBehaviourf20EB3InterpolationType24EB3InterpolationTimeMode(m->field_8C0, 0x12, 0x13, 1.4f, 3, 1);
                self->field_14 = -1.0f;
            } else if (fl == 0 && m->field_9F4 == 0x13 && self->field_14 <= 0.0f) {
                SetParameters__23CB3BehaviourInterpolateF24EB3PlayerCameraBehaviour24EB3PlayerCameraBehaviourf20EB3InterpolationType24EB3InterpolationTimeMode(m->field_8C0, 0x13, 2, 1.0f, 3, 1);
                self->field_14 = -1.0f;
            } else if (self->field_14 > 0.0f) {
                self->field_14 -= D_0051BAC8.field_0;
            }
        }
        break;
    case 2:
        return;
    }
out:;
}
