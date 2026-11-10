// NONMATCHING: Update__18CB3MenuPageManagerFv -- retail 361 / ours 361 instructions, 6 in changed runs
// psweep: scoped #pragma opt_scalarize off [G] improves 28 -> 6
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (a147).
#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_scalarize off
using namespace GtMathPs2;
struct UnkStruct_Float { float value; unsigned char pad[0xC]; };
struct UnkStruct_Int { int value; unsigned char pad[0xC]; };
struct UnkStruct_Byte { unsigned char value; unsigned char pad[0xF]; };
extern UnkStruct_Float D_004F509C;
extern UnkStruct_Int D_00665EC0;
extern UnkStruct_Int D_00665EC4;
extern UnkStruct_Byte D_004EB1E0;
extern UnkStruct_Int D_0051A9A0;
extern UnkStruct_Byte D_01E8E8AA;
extern UnkStruct_Byte D_01E65499;
extern UnkStruct_Int D_0051BACC;
extern UnkStruct_Int D_0051BA94;
extern UnkStruct_Int D_0051BA98;
extern signed char D_004F6061[];
struct UnkStruct_Rec { unsigned char pad_0[0x12C]; };
struct UnkStruct_D_004F50C0 { UnkStruct_Rec field_0[1]; };
extern UnkStruct_D_004F50C0 D_004F50C0;
struct UnkStruct_D_01E9583C { unsigned char pad[0x10]; };
extern UnkStruct_D_01E9583C D_01E9583C;

class CB3ControllerRemovedComponent {
public:
    virtual void vfunc_8(float);
    void Prepare();
    unsigned char pad_4[0xC];
};
extern CB3ControllerRemovedComponent D_01E8E8A0;

struct UnkStruct_D_01EA2970 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01EA2974 { void *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_003C6DF0_4 { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_D_01EA2980 { UnkStruct_003C6DF0_4 *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2984 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_003C6DF0_6 { unsigned char pad_0[0x8]; float field_8; };
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void ApplyEvent__14CB3MenuFlowFSMFUiPv(void *, unsigned int, void *);
extern "C" int AreLockedPlayersConnected__15CB3InputManagerFv(void *);
extern "C" int PadIsValid__20CB3ControllerMappingFv(void *);
extern "C" int func_0012EF20(void *);
extern "C" void Prepare__19CB3MenuStringBufferFv(void *);

static inline void func_0030D7C0_inl1(unsigned long id)  // [G] inlined swap helper (name unknown)
{
    UnkStruct_003C6DF0_6 * r = (UnkStruct_003C6DF0_6 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, id);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
    void * t0 = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_003C6DF0_4 * t1 = D_01EA2980.field_0;
    if (t1 != 0) {
        D_01EA2984.field_0 = t1->field_20;
        if (r != 0) {
            r->field_8 = t1->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
}

struct UnkStruct_0030D7C0_scene { unsigned char pad_0[8]; CGtV2d field_8; };
class UnkStruct_0030D7C0_comp {
public:
    virtual void vfunc_8(float) = 0;
    virtual void vfunc_C();
    UnkStruct_0030D7C0_comp * field_4;
    short field_8;
    bool field_A;
    bool field_B;
};
class UnkStruct_0030D7C0_page {
public:
    virtual void vfunc_8();
    virtual void vfunc_C();
};
static inline bool func_0030D7C0_inl3(int d) { if (d == 0x17) return true; if (d == 0x18 || d == 1) return true; return false; }
struct UnkStruct_0030D7C0_v2 { float x; float y; };
class CB3StringBufferX { public: void Prepare() { Prepare__19CB3MenuStringBufferFv(this); } };

class CB3MenuPageManager {
public:
    void Update();
    unsigned char pad_0[0x1B4];
    UnkStruct_0030D7C0_scene * field_1B4;
    unsigned char pad_1B8[0x20];
    UnkStruct_0030D7C0_comp * field_1D8;
    float field_1DC;
    float field_1E0;
    int field_1E4;
    int field_1E8;
    void * field_1EC;
    UnkStruct_0030D7C0_page * field_1F0;
    unsigned char pad_1F4[0x4];
    unsigned char field_1F8[0x1805];
    unsigned char field_19FD;
    unsigned char pad_19FE;
    unsigned char field_19FF;
};

// 0x0030D7C0
void CB3MenuPageManager::Update()
{
    float dt = D_004F509C.value;
    UnkStruct_0030D7C0_scene * sc = field_1B4;
    sc->field_8 = CGtV2d(640.0f * (float)D_00665EC0.value / 409600.0f, 480.0f * (float)D_00665EC4.value / 230400.0f);
    if (D_004EB1E0.value) {
        bool done = false;
        switch (field_1E4) {
        case 0: {
            float t = field_1DC;
            float lim = 0.4f;
            if (t >= lim) {
                field_1E4 = 2;
                *(int *)&field_1DC = 0;
                *(int *)&field_1E0 = 0;
            } else {
                t += dt;
                field_1DC = t;
                if (t < lim) field_1E0 = 2.5f * t;
                else *(int *)&field_1E0 = 0x3F800000;
            }
            break;
        }
        case 2: {
            float t = field_1DC;
            float lim = 0.4f;
            if (t >= lim) {
                field_1E4 = 5;
            } else {
                t += dt;
                field_1DC = t;
                if (t < lim) field_1E0 = 2.5f * t;
                else *(int *)&field_1E0 = 0x3F800000;
            }
            break;
        }
        case 3:
        case 4: {
            float t = field_1DC;
            float z = 0.0f;
            if (t <= z) {
                if (field_19FF) {
                    field_1DC = 0.4f;
                    *(int *)&field_1E0 = 0x3F800000;
                    field_1E4 = 1;
                    field_19FF = 0;
                } else {
                    field_1DC = z;
                    done = true;
                }
            } else {
                t -= dt;
                field_1DC = t;
                if (t <= z) field_1E0 = z;
                else field_1E0 = 2.5f * t;
            }
            break;
        }
        case 1: {
            float t = field_1DC;
            float z = 0.0f;
            if (t <= z) {
                field_1DC = z;
                done = true;
            } else {
                t -= dt;
                field_1DC = t;
                if (t <= z) field_1E0 = z;
                else field_1E0 = 2.5f * t;
            }
            break;
        }
        case 5:
            break;
        default:
            break;
        }
        if (field_19FD == 0) {
            int d = D_0051A9A0.value;
            if (func_0030D7C0_inl3(d) && done) {
                field_1E4 = 6;
                field_1F0->vfunc_C();
                field_1F0 = 0;
                for (UnkStruct_0030D7C0_comp * p = field_1D8; p != 0; p = p->field_4) {
                    if (p->field_A != false) {
                        p->vfunc_C();
                    }
                }
                Prepare__19CB3MenuStringBufferFv(&field_1F8);
                ApplyEvent__14CB3MenuFlowFSMFUiPv(&D_01EA2970, field_1E8, field_1E8 < 3 ? field_1EC : 0);
            }
        }
        if (field_1F0) {
            field_1F0->vfunc_8();
            for (UnkStruct_0030D7C0_comp * p = field_1D8; p != 0; p = p->field_4) {
                if (p->field_A != false) {
                    p->vfunc_8(dt);
                }
            }
        } else {
            if (D_01E8E8AA.value) ((CB3ControllerRemovedComponent *)&D_01E8E8A0)->vfunc_8(dt);
        }
        if (!(AreLockedPlayersConnected__15CB3InputManagerFv(&D_004F50C0) || (void *)field_1F0 == (void *)&D_01E9583C || D_0051BACC.value == 4)) {
            if (D_01E65499.value == 0) {
                if (D_01E8E8AA.value == 0) D_01E8E8A0.Prepare();
                if (D_0051BA94.value == -1 && field_1F0 == 0) {
                    void * pad = (char *)&D_004F50C0.field_0[D_004F6061[0]] + 0xD48;
                    int r;
                    if (PadIsValid__20CB3ControllerMappingFv(pad) || func_0012EF20(pad)) r = 1;
                    else r = 0;
                    D_0051BA98.value = r;
                }
            } else {
                if (D_01E8E8AA.value == 0) D_01E8E8A0.Prepare();
            }
        }
    }
    if (field_19FD) {
        if (field_1F0 == 0) {
            func_0030D7C0_inl1(0x94413FA737AAA797);
            field_19FD = 0;
        } else {
            field_19FD = 0;
        }
    }
}

#pragma pop
