// Hand-written; the lifter refused it (N182 pragma match (lead): archive source + scoped optimiser pragma).

// N182: retail compiled this function with `#pragma opt_optimizecontrolflow off` ([G] scoped to this function).
#pragma push
#pragma opt_optimizecontrolflow off

struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E90424 D_01E90424;
struct UnkStruct_D_16 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_16 D_004F50C0;
extern UnkStruct_D_16 D_01E90240;
extern UnkStruct_D_16 D_01E89800;
extern UnkStruct_D_16 D_01E7A800;
struct UnkStruct_D_01E89810 { unsigned long field_0; unsigned char pad_8[8]; };
extern UnkStruct_D_01E89810 D_01E89810;
extern "C" int GetMenuUp__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuDown__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuBack__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuConfirm__15CB3InputManagerFSc(void *, signed char);
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, int, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, int, bool);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);
struct UnkStruct_00454BF0_row { unsigned char field_0; unsigned char pad_1[7]; };
struct UnkStruct_00454BF0 {
    unsigned char pad_0[4];
    int field_4;
    unsigned char pad_8[2];
    unsigned short field_A;
    unsigned char pad_C[8];
    UnkStruct_00454BF0_row field_14[8];
};

// 0x00454BF0
extern "C" void func_00454BF0(UnkStruct_00454BF0 *self)
{
    if (D_01E90424.field_0 != 5) return;
    if (GetMenuConfirm__15CB3InputManagerFSc(&D_004F50C0, 0) != 0) {
        int sel = self->field_A;
        if (((UnkStruct_00454BF0_row *)((char *)self + sel * 8 + 0x14))->field_0 == 0) {
            self->field_4 = sel;
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 0, 0);
            return;
        }
    }
    if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0) != 0) goto back;
    if (GetMenuUp__15CB3InputManagerFSc(&D_004F50C0, 0) != 0) {
        if (func_00319360((char *)self + 0xA) != 0) goto act;
    }
    if (GetMenuDown__15CB3InputManagerFSc(&D_004F50C0, 0) != 0) goto dn;
    return;
act:
    if (((UnkStruct_00454BF0_row *)((char *)self + self->field_A * 8 + 0x14))->field_0 != 0) {
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 & ~16UL, 3);
    } else {
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 | 16, 3);
    }
    FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
    return;
back:
    StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, 0);
    return;
dn:
    if (func_00319330((char *)self + 0xA) == 0) return;
    goto act;
}

#pragma pop
