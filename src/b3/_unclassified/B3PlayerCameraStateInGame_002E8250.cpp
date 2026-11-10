// NOTE (lead, 2026-10-27): the function is CB3PlayerCameraStateIntro::Action -- its mangled symbol
// Action__25CB3PlayerCameraStateIntroF14EGtStateActionPvPvPv is [C]; retail_names.csv's low-confidence "InGame" row (which
// named this file) is wrong. File rename to B3PlayerCameraStateIntro_002E8250.cpp pending (needs the pipeline stopped).
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (camera-state Action cloned from CrashMode: SetScene(fsm,h,k), B9C behaviour-select inline, jump table in block order (0,3,4,5,2,1), case 0x15 reassigns p3 (keeps k in s1), DeactivateBehaviour gets the reused compare constant 0xF).

// CB3PlayerCameraStateIntro::Action(EGtStateAction,void*,void*,void*)
// [C] name: the mangled symbol in retail's tables. Area not evidenced, so _unclassified/ (docs/conventions.md).
// Hand-written (L254) from the asm after the matched sibling B3PlayerCameraStateCrashMode_00357600.cpp
// (p1 = the camera manager FSM, SetScene(fsm, h, k) inline). Field names are placeholders; types [G].

enum EGtStateAction {};
struct UnkStruct_002E8250_1 { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_002E8250_2 { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_002E8250_F {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_002E8250_2 *, int);
    virtual void vfunc_1C(void *, int);
    void * field_4;
    unsigned char pad_8[0x8];
    UnkStruct_002E8250_1 * field_10;
    float field_14;
    unsigned char pad_18[0x278];
    unsigned char field_290[0x210];
    unsigned char field_4A0[0x14];
    float field_4B4;
    unsigned char pad_4B8[0x408];
    unsigned char field_8C0[0x2C0];
    unsigned long field_B80;
    unsigned char pad_B88[0x8];
    int field_B90;
    int field_B94;
    unsigned char pad_B98[0x4];
    int field_B9C;
};
struct UnkStruct_002E8250 {
    unsigned char pad_0[0x10];
    int field_10;
    int field_14;
    float field_18;
    int field_1C;
    int field_20;
    int field_24;
    unsigned char field_28;
};
struct UnkStruct_002E8250_Id { unsigned long field_0; };
struct UnkStruct_002E8250_Row { int field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_002E8250_Car { unsigned char pad_0[0x118C]; unsigned char field_118C[4]; };
struct UnkStruct_002E8250_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_002E8250_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_002E8250_Fl { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_002E8250_P { unsigned char pad_0[0x10]; };
extern UnkStruct_002E8250_Row D_0055EFEC[];
extern unsigned char D_004F507D[];
extern UnkStruct_002E8250_Car * D_0064D388[];
extern UnkStruct_002E8250_B D_01E91C3E;
extern UnkStruct_002E8250_B D_0051BAD5;
extern UnkStruct_002E8250_B D_0051BAD6;
extern UnkStruct_002E8250_I D_0051BAC4;
extern UnkStruct_002E8250_Fl D_004F509C;
extern UnkStruct_002E8250_P D_01E77540;
extern UnkStruct_002E8250_P D_01D9D200;
extern UnkStruct_002E8250_P D_01E7A800;
extern "C" UnkStruct_002E8250_2 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void SetActiveBehaviour__22CB3PlayerCameraManagerFi(void *, int);
extern "C" void DeactivateBehaviour__22CB3PlayerCameraManagerFi(void *, int);
extern "C" void StartTakedownPitcher__23CB3SoundGameModeManagerFv(void *);
extern "C" void CancelTakedownPitcher__23CB3SoundGameModeManagerFv(void *);
extern "C" void SetParameters__23CB3BehaviourInterpolateF24EB3PlayerCameraBehaviour24EB3PlayerCameraBehaviourf20EB3InterpolationType24EB3InterpolationTimeMode(void *, int, int, float, int, int);
extern "C" void func_002E6F10(void *, int);
extern "C" void func_002E6F20(void *, int);
extern "C" void func_002E6F30(void *, int, int);
extern "C" void func_0032ED30(void *, int, int);
extern "C" void func_00255E60(void *);
extern "C" void func_00284770(void *);
extern "C" float func_0030B110(void *);

static inline void SetScene(UnkStruct_002E8250_F * fsm, unsigned long h, int k)
{
    UnkStruct_002E8250_2 * r1 = GetStateFromID__6CGtFSMFUl(fsm, h);
    if (fsm->field_4 == r1) return;
    fsm->vfunc_18(r1, k);
    void * t0 = fsm->field_4;
    fsm->field_4 = (void *)r1;
    UnkStruct_002E8250_1 * t1 = fsm->field_10;
    if (t1 != 0) {
        fsm->field_14 = t1->field_20;
        if (r1 != 0) {
            r1->field_8 = fsm->field_10->field_20;
        }
    }
    fsm->vfunc_1C(t0, k);
}

static inline void func_002E8250_inl1(UnkStruct_002E8250_F * m)  // [G] inlined behaviour select (name unknown)
{
    if (m->field_B9C == 2) {
        SetActiveBehaviour__22CB3PlayerCameraManagerFi(m, 2);
    } else {
        SetActiveBehaviour__22CB3PlayerCameraManagerFi(m, 5);
    }
}

#define SETPARAMS SetParameters__23CB3BehaviourInterpolateF24EB3PlayerCameraBehaviour24EB3PlayerCameraBehaviourf20EB3InterpolationType24EB3InterpolationTimeMode

extern "C" void Action__25CB3PlayerCameraStateIntroF14EGtStateActionPvPvPv(UnkStruct_002E8250 * self, EGtStateAction p0, void * p1, void * p2, void * p3)
{
    UnkStruct_002E8250_F * m = (UnkStruct_002E8250_F *)p1;
    switch (p0) {
    case 0:
        self->field_14 = 0x2B9D6F8;
        self->field_10 = 0xFD462907;
        break;
    case 3:
        self->field_28 = 0;
        if (((UnkStruct_002E8250_Id *)p2)->field_0 != 0xBA38E8350DC6A797UL) {
            func_002E8250_inl1(m);
        }
        self->field_1C = 0;
        break;
    case 4:
        if (self->field_1C == 2) {
            self->field_18 = 0.0f + self->field_18 + D_004F509C.field_0 * (float)D_0051BAC4.field_0;
            if (!(m->field_B80 & 0x400) && self->field_20 == 0) {
                self->field_20 = 1;
                D_0051BAD5.field_0 = 1;
                func_0032ED30(m->field_4A0, 1, 1);
                func_00255E60(&D_01D9D200);
                func_00284770(&D_01E7A800);
            } else if (self->field_18 > 1.5f && self->field_20 == 1) {
                self->field_20 = 2;
                func_002E6F10(m->field_290, self->field_24);
                SetActiveBehaviour__22CB3PlayerCameraManagerFi(m, 1);
                func_0032ED30(m->field_4A0, 1, 1);
                func_00255E60(&D_01D9D200);
                func_00284770(&D_01E7A800);
            }
        }
        if ((m->field_B80 & 0x10) && self->field_28 == 0) {
            func_002E8250_inl1(m);
        }
        self->field_28 = 0;
        break;
    case 5:
        switch ((int)p2) {
        case 0x14:
            SetScene(m, 0xBA38E82B9CC11F7FUL, (int)p3);
            break;
        case 0x15:
            p3 = (void *)D_0055EFEC[m->field_B94].field_0;
            SetScene(m, 0xBA38E5FB73BF9888UL, (int)p3);
            break;
        case 0xD:
            return;
        case 7:
            if (D_01E91C3E.field_0 == 0) {
                if (m->field_B80 & 4) {
                    m->field_B9C = 5;
                    D_004F507D[m->field_B90] = 0;
                    func_002E8250_inl1(m);
                } else if (m->field_B80 & 0x20) {
                    m->field_B9C = 2;
                    D_004F507D[m->field_B90] = 1;
                    func_002E8250_inl1(m);
                }
            }
            break;
        case 8:
            if (!(m->field_B80 & 0x10)) {
                SetActiveBehaviour__22CB3PlayerCameraManagerFi(m, 4);
            }
            self->field_28 = 1;
            break;
        case 9: {
            if (m->field_B80 & 0x8000) {
                DeactivateBehaviour__22CB3PlayerCameraManagerFi(m, 0xF);
            }
            StartTakedownPitcher__23CB3SoundGameModeManagerFv(&D_01E77540);
            self->field_24 = *(int *)p3;
            int beh;
            if (m->field_B80 & 4) {
                beh = 2;
            } else if (m->field_B80 & 0x20) {
                beh = 5;
            } else {
                beh = 4;
            }
            func_002E6F30(m->field_290, self->field_24, m->field_B94);
            SETPARAMS(m->field_8C0, beh, 1, 0.5f, 1, 1);
            break;
        }
        case 0xA:
            SETPARAMS(m->field_8C0, 1, m->field_B9C, 0.5f, 1, 1);
            if (self->field_1C == 2) {
                self->field_1C = 0;
                D_0051BAD6.field_0 = 1;
            }
            break;
        case 0xB: {
            if (m->field_B80 & 0x8000) {
                DeactivateBehaviour__22CB3PlayerCameraManagerFi(m, 0xF);
            }
            StartTakedownPitcher__23CB3SoundGameModeManagerFv(&D_01E77540);
            self->field_24 = *(int *)p3;
            int beh;
            if (m->field_B80 & 4) {
                beh = 2;
            } else if (m->field_B80 & 0x20) {
                beh = 5;
            } else {
                beh = 4;
            }
            func_002E6F20(m->field_290, self->field_24);
            SETPARAMS(m->field_8C0, beh, 1, 0.5f, 1, 1);
            self->field_1C = 2;
            self->field_20 = 0;
            self->field_18 = 0.0f;
            break;
        }
        case 0:
            if ((m->field_B80 & 4) || (m->field_B80 & 0x20)) {
                UnkStruct_002E8250_Car * car = D_0064D388[m->field_B94];
                func_0032ED30(m->field_4A0, 3, 0);
                m->field_4B4 = func_0030B110(car->field_118C);
            }
            break;
        case 0xF:
            SetScene(m, 0xBA38E6DCF8C737FFUL, (int)p3);
            break;
        case 0x12:
            SetScene(m, 0xBA38E7C8878337FFUL, (int)p3);
            break;
        case 0x16:
            SetScene(m, 0xBA38E63A96099FBFUL, (int)p3);
            break;
        case 0xE:
            SetScene(m, 0xBA38E6DC828A38A1UL, (int)p3);
            break;
        }
        break;
    case 2:
        CancelTakedownPitcher__23CB3SoundGameModeManagerFv(&D_01E77540);
        D_0051BAD6.field_0 = 1;
        break;
    case 1:
        break;
    }
}
