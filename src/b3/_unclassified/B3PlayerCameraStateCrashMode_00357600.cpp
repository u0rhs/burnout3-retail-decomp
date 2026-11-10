// CB3PlayerCameraStateCrashMode::Action(EGtStateAction,void*,void*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PlayerCameraStateCrashMode.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (camera-state Action, fsm SetScene(fsm,h,k) inline, crash analyser at D_00522660[idx]+0x128290 (p3 passed to JoinExistingCrash)).

// CB3PlayerCameraStateCrashMode::Action(EGtStateAction,void*,void*,void*)
// [C] name: the mangled symbol in retail's tables. Hand-written (L243) after B3PlayerCameraStateInactive_002E80A0.cpp
// (p1 = the camera manager FSM) and B3CrashCameraDirector_00357550.cpp (crash analyser at D_00522660[idx] + 0x128290).

enum EGtStateAction {};
struct UnkStruct_00357600_1 { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_00357600_2 { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_00357600_F {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_00357600_2 *, int);
    virtual void vfunc_1C(void *, int);
    void * field_4;
    unsigned char pad_8[0x8];
    UnkStruct_00357600_1 * field_10;
    float field_14;
    unsigned char field_18[0x33];
    unsigned char field_4B;
    unsigned char pad_4C[0x454];
    unsigned char field_4A0[0x6E0];
    unsigned long field_B80;
    unsigned char pad_B88[0x8];
    int field_B90;
};
struct UnkStruct_00357600_e0 { unsigned char pad_0[0x1050]; };
struct UnkStruct_D_00522660 { UnkStruct_00357600_e0 field_0[1]; };
struct UnkStruct_00357600_Fl { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_00357600_Fl D_0051BAC8;
extern bool mbLoadedReplay__22CB3PlayerCameraManager;
extern "C" UnkStruct_00357600_2 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void Prepare__22CB3CrashCameraDirectorFb(void *, bool);
extern "C" int JoinExistingCrash__16CB3CrashAnalyserFv(void *, void *);
extern "C" void Release__16CB3CrashAnalyserFv(void *);
extern "C" void func_00356FB0(void *, float);
extern "C" void func_00354F70(void *);
extern "C" void func_0032ED30(void *, int, int);
extern "C" void SetActiveBehaviour__22CB3PlayerCameraManagerFi(void *, int);

static inline void SetScene(UnkStruct_00357600_F * fsm, unsigned long h, int k)
{
    UnkStruct_00357600_2 * r1 = GetStateFromID__6CGtFSMFUl(fsm, h);
    if (fsm->field_4 == r1) return;
    fsm->vfunc_18(r1, k);
    void * t0 = fsm->field_4;
    fsm->field_4 = (void *)r1;
    UnkStruct_00357600_1 * t1 = fsm->field_10;
    if (t1 != 0) {
        fsm->field_14 = t1->field_20;
        if (r1 != 0) {
            r1->field_8 = fsm->field_10->field_20;
        }
    }
    fsm->vfunc_1C(t0, k);
}

extern "C" void Action__29CB3PlayerCameraStateCrashModeF14EGtStateActionPvPvPv(void * self, EGtStateAction p0, void * p1, void * p2, void * p3)
{
    UnkStruct_00357600_F * m = (UnkStruct_00357600_F *)p1;
    switch (p0) {
    case 3:
        Prepare__22CB3CrashCameraDirectorFb(m->field_18, false);
        JoinExistingCrash__16CB3CrashAnalyserFv((char *)&D_00522660.field_0[m->field_B90] + 0x128290, p3);
        break;
    case 4:
        if (m->field_4B != 0) {
            func_00356FB0(m->field_18, D_0051BAC8.field_0);
        }
        break;
    case 5:
        switch ((int)p2) {
        case 0xE:
            SetScene(m, 0xBA38E6DC828A38A1UL, 0);
            break;
        case 0x11:
            SetScene(m, 0xBA38E6DCA6D42A7FUL, 0);
            break;
        case 0x12:
            SetScene(m, 0xBA38E7C8878337FFUL, 0);
            break;
        case 0x14:
            SetScene(m, 0xBA38E82B9CC11F7FUL, 0);
            break;
        case 0x16:
            SetScene(m, 0xBA38E63A96099FBFUL, (int)p3);
            break;
        case 0xC:
            if (mbLoadedReplay__22CB3PlayerCameraManager) {
                SetActiveBehaviour__22CB3PlayerCameraManagerFi(m, 0xD);
                func_00354F70(m->field_18);
            }
            break;
        case 0xF:
            SetScene(m, 0xBA38E6DCF8C737FFUL, (int)p3);
            break;
        case 0x19:
            Prepare__22CB3CrashCameraDirectorFb(m->field_18, true);
            break;
        case 6:
            func_0032ED30(m->field_4A0, 0, 1);
            break;
        }
        break;
    case 2:
        m->field_B80 = 0;
        func_00354F70(m->field_18);
        Release__16CB3CrashAnalyserFv((char *)&D_00522660.field_0[m->field_B90] + 0x128290);
        break;
    }
}
