// Hand-written; the lifter refused it (sibling Inactive shape; intro-start inline used twice; case 4 merged || early return; fC stored before f8).

// func_002E8BD0 -- [L] DNAT: CB3PlayerCameraStateInGame::Action(EGtStateAction,void*,void*,void*) (research/proto/new_names.csv, low: hint only).
// Hand-written (L243) after the matched sibling B3PlayerCameraStateInactive_002E80A0.cpp (p1 = the camera manager FSM).

enum EGtStateAction {};
struct UnkStruct_002E8BD0_1 { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_002E8BD0_2 { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_002E8BD0_a1 {
    int field_0;
    int field_4;
    int field_8;
    unsigned char field_C;
};
struct UnkStruct_002E8BD0_F {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_002E8BD0_2 *, int);
    virtual void vfunc_1C(void *, int);
    void * field_4;
    unsigned char pad_8[0x8];
    UnkStruct_002E8BD0_1 * field_10;
    float field_14;
    unsigned char pad_18[0x38];
    unsigned char field_50[0xB57];
    unsigned char field_BA7;
};
struct UnkStruct_002E8BD0_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_002E8BD0_Fl { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_002E8BD0_B D_00665EA0;
extern UnkStruct_002E8BD0_Fl D_0051BAC8;
extern bool mbLoadedIntro__22CB3PlayerCameraManager;
extern int mgpCameraBuffer__22CB3PlayerCameraManager;
extern "C" UnkStruct_002E8BD0_2 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int func_004474A0(void *, UnkStruct_002E8BD0_a1 *);
extern "C" void func_004471A0(void *, float);
extern "C" void SetActiveBehaviour__22CB3PlayerCameraManagerFi(void *, int);

static inline void SetScene(UnkStruct_002E8BD0_F * fsm, unsigned long h, int k)
{
    UnkStruct_002E8BD0_2 * r1 = GetStateFromID__6CGtFSMFUl(fsm, h);
    if (fsm->field_4 == r1) return;
    fsm->vfunc_18(r1, k);
    void * t0 = fsm->field_4;
    fsm->field_4 = (void *)r1;
    UnkStruct_002E8BD0_1 * t1 = fsm->field_10;
    if (t1 != 0) {
        fsm->field_14 = t1->field_20;
        if (r1 != 0) {
            r1->field_8 = fsm->field_10->field_20;
        }
    }
    fsm->vfunc_1C(t0, k);
}

// [G] placeholder inline for the start-intro block repeated in two cases
static inline void func_002E8BD0_inl1(UnkStruct_002E8BD0_F * m)
{
    if (D_00665EA0.field_0 != 0 && mbLoadedIntro__22CB3PlayerCameraManager) {
        UnkStruct_002E8BD0_a1 l;
        l.field_0 = mgpCameraBuffer__22CB3PlayerCameraManager + 0x340;
        l.field_4 = 0x32;
        l.field_C = 1;
        l.field_8 = 1;
        func_004474A0(m->field_50, &l);
    } else {
        SetActiveBehaviour__22CB3PlayerCameraManagerFi(m, 2);
    }
    m->field_BA7 = 1;
}

// 0x002E8BD0
extern "C" void func_002E8BD0(void * self, EGtStateAction p0, void * p1, void * p2, void * p3)
{
    UnkStruct_002E8BD0_F * m = (UnkStruct_002E8BD0_F *)p1;
    switch (p0) {
    case 3:
        func_002E8BD0_inl1(m);
        break;
    case 5:
        switch ((int)p2) {
        case 0xD:
        case 7:
            return;
        case 0x11:
            SetScene(m, 0xBA38E6DCA6D42A7FUL, 0);
            break;
        case 0xF:
            func_002E8BD0_inl1(m);
            break;
        case 0x10:
            SetScene(m, 0xBA38E8350DC6A797UL, 0);
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
        }
        break;
    case 4:
        if (D_00665EA0.field_0 == 0 || !mbLoadedIntro__22CB3PlayerCameraManager) return;
        func_004471A0(m->field_50, D_0051BAC8.field_0);
        break;
    case 2:
        m->field_BA7 = 0;
        break;
    }
}
