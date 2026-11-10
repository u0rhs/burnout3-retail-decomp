// Hand-written; the lifter refused it (a156: memcard flow handler; state switch 2/3/6, state-3 one-case switch(p0){case 0x38} gives beq+b, error test via goto ok to out-of-line block with two inlined FSM state swaps).

// Hand-written (a156): memory-card flow state handler (state in field_4: 2, 3, 6), shapes of func_003FF1D0 / Save__24CB3MemCardControllerBaseFUiPUsi.
struct UnkStruct_004201F0 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
};
struct UnkStruct_D_01EB5D04 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EB5D14 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_Obj20 { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_D_01EB5D10 { UnkStruct_Obj20 * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_State8 { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_D_01EB5D00 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_State8 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01ECD954 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01ECD964 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01ECD960 { UnkStruct_Obj20 * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01ECD950 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_State8 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01ECD520 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };

extern UnkStruct_D_01EB5D00 D_01EB5D00;
extern UnkStruct_D_01EB5D04 D_01EB5D04;
extern UnkStruct_D_01EB5D10 D_01EB5D10;
extern UnkStruct_D_01EB5D14 D_01EB5D14;
extern UnkStruct_D_01ECD950 D_01ECD950;
extern UnkStruct_D_01ECD954 D_01ECD954;
extern UnkStruct_D_01ECD960 D_01ECD960;
extern UnkStruct_D_01ECD964 D_01ECD964;
extern UnkStruct_D_01ECD520 D_01ECD520;
extern UnkStruct_Pad16 D_005185A0;

extern "C" UnkStruct_State8 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int GetError__16CMemoryDevicePS2Fv(void *);
extern "C" void Save__24CB3MemCardControllerBaseFUiPUsi(void *, int, void *, int);
extern "C" void func_0041FE00(UnkStruct_004201F0 *, int);

// 0x004201F0
extern "C" void func_004201F0(UnkStruct_004201F0 * self, int p0)
{
    UnkStruct_State8 * r0;
    UnkStruct_State8 * r1;
    switch (self->field_4) {
    case 2:
        switch (p0) {
        case 0x31:
        case 0x39:
        case 0x2F:
        case 0x2E:
        case 0x32:
        case 0x33:
        case 0x3A: {
            int e = GetError__16CMemoryDevicePS2Fv(&D_005185A0);
            if (e == 0) goto ok;
            if (e == 13) goto ok;
            self->field_4 = 16;
            break;
        }
        case 0x38:
            self->field_4 = 6;
            func_0041FE00(self, 5);
            Save__24CB3MemCardControllerBaseFUiPUsi(&D_01ECD520, D_01ECD520.field_0, (void *)(0), 0);
            self->field_8 = 0;
            break;
        }
        break;
    case 3:
        switch (p0) {
        case 0x38:
            self->field_4 = 6;
            Save__24CB3MemCardControllerBaseFUiPUsi(&D_01ECD520, D_01ECD520.field_0, (void *)(0), 0);
            func_0041FE00(self, 5);
            break;
        }
        break;
    case 6:
        switch (p0) {
        case 0x34:
            self->field_4 = 9;
            func_0041FE00(self, 8);
            break;
        case 0x35:
            self->field_4 = 7;
            break;
        }
        break;
    }
done:
    return;
ok:
    self->field_4 = 3;
    func_0041FE00(self, 2);
    r0 = GetStateFromID__6CGtFSMFUl(&D_01EB5D00, 0x93CB4D00AA95607FUL);
    if (D_01EB5D04.field_0 != r0) {
        ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_18(r0, 0);
        void * t0 = D_01EB5D04.field_0;
        D_01EB5D04.field_0 = (void *)r0;
        UnkStruct_Obj20 * t1 = D_01EB5D10.field_0;
        if (t1 != 0) {
            D_01EB5D14.field_0 = t1->field_20;
            if (r0 != 0) {
                r0->field_8 = t1->field_20;
            }
        }
        ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_1C(t0, 0);
    }
    r1 = GetStateFromID__6CGtFSMFUl(&D_01ECD950, 0x93D12267889D607FUL);
    if (D_01ECD954.field_0 != r1) {
        ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_18(r1, 0);
        void * t2 = D_01ECD954.field_0;
        D_01ECD954.field_0 = (void *)r1;
        UnkStruct_Obj20 * t3 = D_01ECD960.field_0;
        if (t3 != 0) {
            D_01ECD964.field_0 = t3->field_20;
            if (r1 != 0) {
                r1->field_8 = t3->field_20;
            }
        }
        ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_1C(t2, 0);
        goto done;
    }
}
