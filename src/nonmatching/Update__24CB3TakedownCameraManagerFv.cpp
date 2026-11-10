// NONMATCHING: Update__24CB3TakedownCameraManagerFv -- retail 266 / ours 267 instructions, 4 in changed runs
// 4 off: inline's (unsigned int)m->field_8 * 0x27D0 now blocks the car-product CSE (retail's recomputed mult, fixed); left: second cleanup's field_1524==4 store is inline in retail (bne skip; sw), ours beq out-of-line + b back (if/else, ==, goto, switch, pragmas tried)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: Update__24CB3TakedownCameraManagerFv -- retail 266 / ours 265 instructions, 8 in changed runs
// a151: 265/266 instrs, 8 changed. Logic+layout+s-regs right. Left: first cleanup block (beq out-of-line) recomputes car with fresh mult from reused a1 (ours reuses the product); second cleanup 'bne skip; sw' inline vs ours beq out-of-line. CSE of car vs cleanup address not blockable by array/byte/idx forms.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

struct UnkStruct_TC_row {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int *);
};
struct UnkStruct_TC_g1 { unsigned char pad_0[0x28E00]; UnkStruct_TC_row field_28E00[1]; };
struct UnkStruct_TC_hud { unsigned char pad_0[0x70]; };
struct UnkStruct_TC_huds { UnkStruct_TC_hud field_0[1]; };
struct UnkStruct_TC_6 {
    unsigned char pad_0[0x1353];
    unsigned char field_1353;
    unsigned char pad_1354[0x1D0];
    int field_1524;
};
struct UnkStruct_TC_e3 {
    unsigned char pad_0[0x2C];
    UnkStruct_TC_6 * field_2C;
};
struct UnkStruct_TC_car {
    unsigned char pad_0[0x11E1];
    unsigned char field_11E1;
    unsigned char pad_11E2[0x15A];
    int field_133C;
    unsigned char pad_1340[0x5AA];
    unsigned char field_18EA;
    unsigned char pad_18EB[0xC1];
    signed char field_19AC;
    unsigned char pad_19AD[0xA1B];
    unsigned char field_23C8;
    unsigned char pad_23C9[0x3E];
    unsigned char field_2407;
    unsigned char pad_2408[0x45];
    unsigned char field_244D;
    unsigned char pad_244E[0x37A];
    unsigned char field_27C8;
    unsigned char pad_27C9[7];
};
struct UnkStruct_TC_e4 { unsigned char pad_0[0x27D0]; };
class CGtTimer {
public:
    void SetSlowMo(int);
    UnkStruct_TC_e4 field_0[1];
    unsigned char pad_27D0[0x3A190];
    UnkStruct_TC_e3 field_3C960[1];
    unsigned char pad_3C990[0xEDFF0];
    unsigned char pad_12A980[0x3D0];
    UnkStruct_TC_car field_12AD50[1];
};
struct UnkStruct_D_004F509C { float field_0; unsigned char pad_4[0xC]; };
class CB3TakedownCameraManager {
public:
    void Update();
    UnkStruct_TC_car * field_0;
    float field_4;
    int field_8;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char field_E;
    unsigned char field_F;
};
extern CGtTimer D_00522660;
extern UnkStruct_TC_g1 D_004EE040;
extern UnkStruct_TC_huds D_0066A3D0;
extern UnkStruct_D_004F509C D_004F509C;
extern "C" void func_00150280(UnkStruct_TC_car *, bool);
extern "C" void SetHUDMode__6CB3HUDF8EHUDMode(void *, int);

static inline void func_00394C30_inl1(CB3TakedownCameraManager * m)
{
    UnkStruct_TC_car * c2 = (UnkStruct_TC_car *)((char *)&D_00522660 + (unsigned int)m->field_8 * 0x27D0 + 0x12AD50);
    c2->field_244D = 0;
    func_00150280(c2, 0);
    UnkStruct_TC_6 * t2 = D_00522660.field_3C960[c2->field_19AC].field_2C;
    if (t2->field_1524 == 4) {
        t2->field_1524 = 0;
    }
    D_00522660.SetSlowMo(1);
    m->field_C = 0;
    m->field_E = 0;
    m->field_4 = -1.0f;
    m->field_0 = 0;
}

// 0x00394C30
void CB3TakedownCameraManager::Update()
{
    bool s3;
    if (field_E == 0) return;
    field_4 = field_4 + D_004F509C.field_0;
    UnkStruct_TC_car * car = (UnkStruct_TC_car *)((char *)&D_00522660.field_0[field_8] + 0x12AD50);
    if (car->field_133C == 3 || car->field_18EA != 0) {
        func_00394C30_inl1(this);
        return;
    }
    int sp6C = -1;
    if (field_0 != 0) {
        sp6C = field_0->field_19AC;
    }
    if (!(field_4 < 4.8f)) {
        if (*(const unsigned char *)&car->field_18EA == 0) {
            UnkStruct_TC_car * c3 = &D_00522660.field_12AD50[field_8];
            c3->field_244D = 0;
            func_00150280(c3, 0);
            UnkStruct_TC_6 * t3 = D_00522660.field_3C960[c3->field_19AC].field_2C;
            if (t3->field_1524 != 4) {
            } else {
                t3->field_1524 = 0;
            }
            D_00522660.SetSlowMo(1);
            field_C = 0;
            field_E = 0;
            field_4 = -1.0f;
            field_0 = 0;
            return;
        }
    }
    bool s1 = field_4 < 4.8f;
    s3 = field_4 < 2.8f;
    bool s0 = field_4 < 2.8f;
    if (car->field_27C8 != 0 && !s3) {
        UnkStruct_TC_6 * t4 = D_00522660.field_3C960[car->field_19AC].field_2C;
        if (t4->field_1524 == 4) {
            t4->field_1524 = 0;
        }
    }
    func_00150280(car, s3);
    if (!s0) {
        D_00522660.SetSlowMo(1);
    } else {
        D_00522660.SetSlowMo(5);
    }
    if (field_D == 0 && !(field_4 < 2.5f) && sp6C != -1) {
        ((UnkStruct_TC_row *)((char *)&D_004EE040 + field_8 * 0xBB0 + 0x28E00))->vfunc_14(10, &sp6C);
        SetHUDMode__6CB3HUDF8EHUDMode(&D_0066A3D0.field_0[field_8], 1);
        field_D = 1;
    }
    if (field_C != 0 && !(field_4 < 2.5f) && sp6C != -1) {
        field_C = 0;
    }
    if (s3) {
        if (field_F != 0 && car->field_11E1 == 0) {
            car->field_2407 = 1;
        }
    }
    if (s3) {
        car->field_244D = s1;
    } else if (s1) {
        UnkStruct_TC_6 * t5 = D_00522660.field_3C960[car->field_19AC].field_2C;
        t5->field_1353 = t5->field_1353 | 0x10;
        t5->field_1353 = t5->field_1353 | 8;
    }
}
