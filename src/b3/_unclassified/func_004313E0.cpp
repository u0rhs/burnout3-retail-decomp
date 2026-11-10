// Hand-written; the lifter refused it (a157: carousel page Update; switch default LAST (dead dup li s0,3), const D_004D19F4 hoists load, D_004D19F0/F4 as 0x10 structs (sibling func_00431D80 declares D_004D19F0[] array: header reconciliation)).

// Hand-written: carousel page Update (a157; state machine on D_01E90424 == 5).
struct CB3InputManager {
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);
    int GetMenuLeft(signed char);
    int GetMenuRight(signed char);
    int GetMenuConfirm(signed char);
    int GetMenuBack(signed char);
    unsigned char pad_0[0x10];
};
enum EB3MenuFlowFSMEvents {};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004F507A { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E7A974 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x7000]; unsigned char field_7000[1]; };
struct UnkStruct_004313E0_blk { unsigned char pad_0[0x4]; unsigned int field_4; unsigned char pad_8[0x58]; };
struct UnkStruct_004313E0_a { unsigned char pad_0[0x14]; int field_14; unsigned char pad_18[8]; };
struct UnkStruct_004313E0_b { unsigned char pad_0[0x4]; unsigned int field_4; unsigned char pad_8[0x4C]; unsigned char field_54; unsigned char pad_55[0xB]; };
struct UnkStruct_004313E0_c { unsigned char pad_0[0x60]; };
struct UnkStruct_004313E0 {
    unsigned char pad_0[0x938];
    int field_938;
    int field_93C;
    unsigned char pad_940[8];
    int field_948;
    unsigned char pad_94C[0x10];
    unsigned char field_95C;
    unsigned char pad_95D[0x5B];
    int field_9B8;
    UnkStruct_004313E0_b *field_9BC;
    int field_9C0;
};
extern CB3InputManager D_004F50C0;
extern UnkStruct_P D_01E90240;
extern UnkStruct_P D_01E89800;
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_004F507A D_004F507A;
extern UnkStruct_D_01E7A974 D_01E7A974;
extern UnkStruct_D_004EE040 D_004EE040;
struct UnkStruct_D_004D19F0 { unsigned int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004D19F0 D_004D19F0;
extern const UnkStruct_D_004D19F0 D_004D19F4;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" bool func_00213E20(CB3InputManager *, int, signed char);
extern "C" void func_003FBB50(void *, int, void *);
extern "C" void func_003FBB00(int, int, void *, void *, int, int);
extern "C" void func_003FBAA0(void *, int, void *, unsigned char);
extern "C" void func_003FBA00(void *, int);
extern "C" void func_003FB8B0(void *, int);
extern "C" void func_003FC470(void *);
extern "C" void func_003FBC20(int, int);
extern "C" void func_003FC520(void *);
extern "C" void func_00431160(void *);
extern "C" int func_00431050(void *, int, int);

// 0x004313E0
extern "C" void func_004313E0(UnkStruct_004313E0 * self)
{
    UnkStruct_004313E0_blk lb;
    UnkStruct_004313E0_a la;
    UnkStruct_004313E0_c lc;
    unsigned int i;
    int s0;
    if (D_01E90424.field_0 != 5) return;
    if (D_004F50C0.GetMenuConfirm(0)) {
        if (self->field_9C0 == 2) {
            D_004F507A.field_0 = 1;
        } else {
            D_004F507A.field_0 = 0;
        }
        func_003FBB50((void *)(self->field_9B8), 0, &lb);
        for (i = 0; i < lb.field_4; i++) {
            func_003FBB00(self->field_9B8, i, &lb, &la, 0, 0);
            D_004EE040.field_7000[i] = la.field_14;
        }
        func_003FBA00((void *)(self->field_9B8), D_004F507A.field_0 ? 2 : 1);
        func_003FB8B0((void *)(self->field_9B8), self->field_938);
        D_01E7A974.field_0 = self->field_93C;
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        return;
    }
    if (D_004F50C0.GetMenuBack(0)) {
        func_003FBB50((void *)(self->field_9B8), 0, &lc);
        for (i = 0; i < *(unsigned int *)((char *)&lc + 4); i++) {
            func_003FBAA0((void *)(self->field_9B8), i, &lc, D_004EE040.field_7000[i]);
        }
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        return;
    }
    if (func_00213E20(&D_004F50C0, 10, 0)) {
        if (self->field_9C0 == 1) {
            self->field_9C0 = 2;
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_004D19F4.field_0, 15);
        } else {
            self->field_9C0 = 1;
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_004D19F0.field_0, 15);
        }
    }
    if (D_004F50C0.GetMenuUp(0)) {
        if (self->field_938 > 0) {
            self->field_938 = self->field_938 - 1;
            s0 = self->field_938;
            func_003FC470((void *)(self->field_9B8));
            func_003FBC20(self->field_9B8, s0);
            func_003FBB00(self->field_9B8, s0, self->field_9BC, &self->field_948, 0, 0);
            func_003FC520((void *)(self->field_9B8));
            func_00431160(self);
        }
        return;
    }
    if (D_004F50C0.GetMenuDown(0)) {
        if ((unsigned int)self->field_938 < self->field_9BC->field_4 - 1) {
            self->field_938 = self->field_938 + 1;
            s0 = self->field_938;
            func_003FC470((void *)(self->field_9B8));
            func_003FBC20(self->field_9B8, s0);
            func_003FBB00(self->field_9B8, s0, self->field_9BC, &self->field_948, 0, 0);
            func_003FC520((void *)(self->field_9B8));
            func_00431160(self);
        }
        return;
    }
    if (self->field_9BC->field_54 != 0) {
        if (D_004F50C0.GetMenuLeft(0)) {
            switch (self->field_95C & 7) {
            case 7:
                s0 = 0;
                break;
            case 1:
                s0 = 1;
                break;
            case 4:
                s0 = 2;
                break;
            default:
                s0 = 3;
                break;
            }
            do {
                if (s0 == 0) s0 = 4;
                s0 = s0 - 1;
            } while (!func_00431050(self, self->field_938, s0));
        }
        if (D_004F50C0.GetMenuRight(0)) {
            switch (self->field_95C & 7) {
            case 7:
                s0 = 0;
                break;
            case 1:
                s0 = 1;
                break;
            case 4:
                s0 = 2;
                break;
            default:
                s0 = 3;
                break;
            }
            do {
                s0 = s0 + 1;
                if (s0 == 4) s0 = 0;
            } while (!func_00431050(self, self->field_938, s0));
        }
        func_00431160(self);
    }
}
