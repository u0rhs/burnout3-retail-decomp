// Hand-written; the lifter refused it (a132: else-if chain with explicit return after confirm/back/vertical arms (direct b to epilogue)).

enum EB3MenuFlowFSMEvents {};
struct UnkStruct_B630_e { unsigned char pad_0[0x22]; unsigned char field_22; };
struct UnkStruct_B630 {
    unsigned char pad_0[4];
    int field_4;
    int field_8;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char field_E;
    unsigned char pad_F[1];
    unsigned short field_10;
    unsigned char pad_12[0x10];
    unsigned char field_22;
    unsigned char pad_23[0x55];
    unsigned short field_78;
    unsigned char pad_7A[0x26];
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    unsigned char pad_B4[4];
    unsigned char field_B8;
};
class CB3InputManager {
public:
    int GetMenuConfirm(signed char);
    int GetMenuBack(signed char);
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);
    int GetMenuLeft(signed char);
    int GetMenuRight(signed char);
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_01E8961C {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E89626 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E89810 { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_Gen { unsigned char pad_0[0x10]; };
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E8961C D_01E8961C;
extern UnkStruct_D_01E89626 D_01E89626;
extern UnkStruct_D_01E89810 D_01E89810;
extern UnkStruct_Gen D_01E90240, D_01E89800, D_01E7A800;
extern int D_004CA470[];
extern int D_004CA480[];
extern int D_004CA498[];
extern "C" signed char func_0022D1E0(void *);
extern "C" void func_003CB900(void *, int);
extern "C" void func_003CB420(void *);
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);

// 0x003CB630
extern "C" void func_003CB630(UnkStruct_B630 *self)
{
    bool b = func_0022D1E0(&D_004F50C0) >= 2;
    if (b != self->field_B8) {
        self->field_B8 = b;
        if (self->field_B8 == 0) {
            self->field_A0 = 0;
            self->field_A8 = self->field_78;
        }
        if (D_01E89626.field_0 != 0) {
            ((UnkStruct_D_01E8961C *)&D_01E8961C)->vfunc_C();
        }
        func_003CB900(self, self->field_10);
        return;
    }
    if (D_004F50C0.GetMenuConfirm(0) != 0) {
        self->field_4 = D_004CA470[self->field_A0];
        self->field_8 = D_004CA480[self->field_A4];
        self->field_D = self->field_AC;
        self->field_E = (self->field_B0 != 0) ^ 1;
        if (D_004CA470[self->field_A0] == 1) {
            self->field_C = D_004CA498[self->field_A8];
        } else {
            self->field_C = self->field_A8;
        }
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0, 0);
        return;
    } else if (D_004F50C0.GetMenuBack(0) != 0) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        return;
    } else if ((D_004F50C0.GetMenuUp(0) != 0 && func_00319360((char *)self + 0x10) != 0) ||
               (D_004F50C0.GetMenuDown(0) != 0 && func_00319330((char *)self + 0x10) != 0)) {
        if (((UnkStruct_B630_e *)((char *)self + self->field_10 * 20))->field_22 != 0) {
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 & ~4UL, 3);
        } else {
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 | 4, 3);
        }
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
        return;
    } else if (D_004F50C0.GetMenuLeft(0) != 0) {
        func_003CB420(self);
    } else if (D_004F50C0.GetMenuRight(0) != 0) {
        func_003CB420(self);
    }
}
