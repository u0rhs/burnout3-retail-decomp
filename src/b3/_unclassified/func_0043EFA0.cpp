// Hand-written; the lifter refused it (re-queued after the jtbl_retarget 2-table fix (from build/vt/hand/func_0043EFA0_l243d.cpp)).

// func_0043EFA0 -- [L] DNAT: CB3DemoPauseState::Action(EGtStateAction,void*,void*,void*) (research/proto/new_names.csv, low: hint only).
// Hand-written (L243): state Action with the SetScene inline (cf. B3OnlineGameCreateState_003248F0.cpp) and two jump tables.

enum EGtStateAction {};
struct UnkStruct_FSM {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_r { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_s { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_D_01EA2974 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2980 { UnkStruct_s * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2984 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_F { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004E2918 { unsigned int field_0; };
extern UnkStruct_P D_01E96F5C;
extern UnkStruct_I D_01E96F60;
extern UnkStruct_I D_01E9020C;
extern UnkStruct_F D_01E90210;
extern UnkStruct_I D_01E90208;
extern UnkStruct_D_004E2918 D_004E2918;
extern UnkStruct_FSM D_01EA2970;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int func_0043F570(void *);

static inline void SetScene(unsigned long h)
{
    UnkStruct_r * r = (UnkStruct_r *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, h);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_FSM *)&D_01EA2970)->vfunc_18(r, 0);
    void * t = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_s * s = D_01EA2980.field_0;
    if (s != 0) {
        D_01EA2984.field_0 = s->field_20;
        if (r != 0) {
            r->field_8 = s->field_20;
        }
    }
    ((UnkStruct_FSM *)&D_01EA2970)->vfunc_1C(t, 0);
}

// 0x0043EFA0
extern "C" void func_0043EFA0(void * self, EGtStateAction p0, void * p1, void * p2, void * p3)
{
    switch (p0) {
    case 3:
        func_0043F570(&D_01E96F5C);
        break;
    case 5:
        switch ((int)p2) {
        case 1:
            switch (D_01E96F60.field_0) {
            case 0:
                D_01E9020C.field_0 = 0x997;
                D_01E90210.field_0 = 123.723732f;
                switch (D_004E2918.field_0) {
                default: case 0: case 1: D_01E90208.field_0 = 0x13; break;
                case 10: D_01E90208.field_0 = 0x12; break;
                case 11: D_01E90208.field_0 = 0x19; break;
                case 5: D_01E90208.field_0 = 0x18; break;
                case 3: D_01E90208.field_0 = 0x15; break;
                case 4: D_01E90208.field_0 = 0x14; break;
                case 6: D_01E90208.field_0 = 0x16; break;
                case 2: D_01E90208.field_0 = 0x17; break;
                }
                SetScene(0x94413FC178615E97UL);
                break;
            case 1:
                D_01E9020C.field_0 = 0x998;
                D_01E90210.field_0 = 98.4985046f;
                switch (D_004E2918.field_0) {
                default: case 0: case 1: D_01E90208.field_0 = 0xB; break;
                case 10: D_01E90208.field_0 = 0xA; break;
                case 11: D_01E90208.field_0 = 0x11; break;
                case 5: D_01E90208.field_0 = 0x10; break;
                case 3: D_01E90208.field_0 = 0xD; break;
                case 4: D_01E90208.field_0 = 0xC; break;
                case 6: D_01E90208.field_0 = 0xE; break;
                case 2: D_01E90208.field_0 = 0xF; break;
                }
                SetScene(0x94413FC178615E97UL);
                break;
            default:
                SetScene(0x94413FC035B0F871UL);
                break;
            }
            break;
        case 3:
            SetScene(0x94413FD6EF6E02D9UL);
            break;
        }
        break;
    }
}
