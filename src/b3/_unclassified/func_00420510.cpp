// Hand-written; the lifter refused it (a156: memcard flow update; switch(r){0,2,3,1} then second switch(state){6,7,8,0} in block form (if (x > K) {...} gives bc1t to exit); done: label inside the 0x10 error block, ok block shared with func_004201F0).

// Hand-written (a156): memory-card flow update (state in field_4), sibling of func_004201F0.
struct UnkStruct_004201F0 {
    unsigned char pad_0[0x4];
    int field_4;
    float field_8;
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

enum EB3MenuFlowFSMEvents {};
struct UnkStruct_D_01E90424 { int value; unsigned char pad[0x100]; };
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004F509C { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_Byte { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_SByte { signed char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_Byte D_0051A999;
extern UnkStruct_SByte D_004F507F;
extern UnkStruct_Byte D_01E6549A;
extern UnkStruct_Pad16 D_01E8F360;
extern "C" int func_00449150(void *, int, int);
extern "C" void StartSaveProfileFlow__24CB3MemCardControllerBaseFv(void *);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);

// 0x00420510
extern "C" void func_00420510(UnkStruct_004201F0 * self)
{
    UnkStruct_State8 * r0;
    UnkStruct_State8 * r1;
    int r;
    if (D_01E90424.value != 5) {
        return;
    }
    if (self->field_4 == 16) {
        int e = GetError__16CMemoryDevicePS2Fv(&D_005185A0);
        if (e == 0) goto ok;
        if (e == 13) goto ok;
    done:
        return;
    }
    r = func_00449150(&D_01E8F360, 0, 1);
    switch (r) {
    case 0:
        switch (self->field_4) {
        case 3:
            self->field_4 = 2;
            func_0041FE00(self, 0);
            StartSaveProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
            break;
        case 0:
            D_0051A999.field_0 = 1;
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)2, 0);
            break;
        case 1:
            D_004F507F.field_0 = 0;
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)2, 0);
            break;
        }
        break;
    case 2:
        switch (self->field_4) {
        case 8:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)2, 0);
            break;
        case 9:
            self->field_4 = 0;
            self->field_8 = 0.0f;
            func_0041FE00(self, 6);
            break;
        }
        break;
    case 3:
        switch (self->field_4) {
        case 9:
            self->field_8 = 0.0f;
            if (D_004F507F.field_0 != 0) {
                self->field_4 = 2;
                func_0041FE00(self, 0);
                StartSaveProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
            } else {
                self->field_4 = 0;
                func_0041FE00(self, 6);
            }
            break;
        }
        break;
    case 1:
        switch (self->field_4) {
        case 3:
            self->field_4 = 0;
            self->field_8 = 0.0f;
            func_0041FE00(self, 6);
            break;
        case 0:
            if (D_004F507F.field_0 != 0) goto st1;
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)2, 0);
            break;
        case 1:
            self->field_4 = 0;
            self->field_8 = 0.0f;
            func_0041FE00(self, 6);
            break;
        }
        break;
    }
fin:
    switch (self->field_4) {
    case 6:
        self->field_8 = self->field_8 + D_004F509C.field_0;
        break;
    case 7:
        self->field_8 = self->field_8 + D_004F509C.field_0;
        if (self->field_8 > 1.0f) {
            self->field_4 = 8;
            self->field_8 = 0.0f;
            func_0041FE00(self, 7);
        }
        break;
    case 8:
        if (D_01E6549A.field_0 != 0) {
            self->field_8 = self->field_8 + D_004F509C.field_0;
            if (self->field_8 > 3.0f) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)2, 0);
            }
        }
        break;
    case 0:
        if (D_01E6549A.field_0 != 0) {
            self->field_8 = self->field_8 + D_004F509C.field_0;
            if (self->field_8 > 3.0f) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)2, 0);
            }
        }
        break;
    }
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
    return;
st1:
    self->field_4 = 1;
    func_0041FE00(self, 1);
    goto fin;
}
