// NONMATCHING: func_0043CCE0 -- retail 867 / ours 859 instructions, 271 in changed runs
// retail 867 / ours 859: all 22 cases + 3 nested grade->sound switches + 0xA/8 sprintf arms written from the asm; left: register allocation (retail self/a/b/flag in s2/s1/s0/s3 and case-17 string/id kept in s4/s5, frame 0x80; ours propagates the id constants and keeps flag in a temp, frame 0x60)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (all four jump tables decoded: 22-entry event switch and three 8-entry sound switches); every call, argument and store accounted for

// func_0043CCE0 -- hand-written (draft2) from the retail asm (Ghidra could not recover the jump table); never attempted
// before. Unnamed in every table, so a placeholder with C linkage. A 22-case event handler on a HUD/message object
// (calls func_00457B20 on its +0x10 sub-object with a message id); field names are placeholders, types [G].
struct UnkStruct_P16 { unsigned char pad_0[0x10]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };   // [G] size: absolute addressing needs > 8 bytes (N50)
struct UnkStruct_F { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_0043CCE0_car { unsigned char pad_0[0x27D0]; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x12C494]; int field_12C494; };   // [G] per-car int at +0x12C494, stride 0x27D0
extern UnkStruct_P16 D_01E7A800, D_01E89788, D_01E90438, D_004EE040;
extern UnkStruct_I D_0064EB08, D_006512D8;
extern UnkStruct_P16 D_0064ED24, D_006514F4;
extern UnkStruct_F D_004F50A0;
extern UnkStruct_B D_0064D33B;
extern float D_004D1E50[];
extern char D_0051BA44[];
extern unsigned char D_00522660[];
extern "C" int func_00271A00(void *, int);
extern "C" void func_00457B20(void *, void *, void *, void *, int, int, int);
extern "C" void func_00284400(void *, float, float);
extern "C" void func_00284BD0(void *);
extern "C" void func_00284B20(void *);
extern "C" void func_00284B60(void *);
extern "C" void func_00284C40(void *);
extern "C" void func_00284C80(void *);
extern "C" void func_002859F0(void *);
extern "C" void func_00285560(void *, int, int);
extern "C" void CrashModeMultiplier__18CB3HUDSoundManagerFv(void *);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_003B8840(void *, int);
extern "C" void func_003180A0(void *, void *, void *);
extern "C" void func_00458900(void *, int);
extern "C" int func_00458960(void *);
extern "C" int func_00131CA0(void *);
extern "C" void func_0031BD60(void *, int, int);
extern "C" void func_0031B640(void *);
struct UnkStruct_0043CCE0;
extern "C" void func_0043C960(UnkStruct_0043CCE0 *, int, int);
extern "C" int func_0043C8F0(UnkStruct_0043CCE0 *, int);

struct UnkStruct_0043CCE0_row { int field_0[5]; };
struct UnkStruct_0043CCE0 {
    unsigned char pad_0[0x10];
    unsigned char field_10[0x60];   // sub-object passed to func_00457B20
    int field_70;
    unsigned char pad_74[0x8];
    UnkStruct_0043CCE0_row field_7C[2];
    unsigned char pad_A4[0x1C];
    int field_C0;
    unsigned char pad_C4[0x8];
    int field_CC[2];
    float field_D4;
    float field_D8;
    int field_DC;
};

// bonus by grade
static inline void func_0043CCE0_inl1(int * v, int k)
{
    switch (k) {
    case 1:
        *v += 5000;
        break;
    case 2:
        *v += 10000;
        break;
    case 3:
        *v += 20000;
        break;
    case 4:
        *v += 5000;
        break;
    }
}

// sound by grade
static inline void func_0043CCE0_inl2(int k)
{
    switch (k) {
    case 1:
    case 2:
    case 3:
        func_00284BD0(&D_01E7A800);
        break;
    case 4:
        func_00284B20(&D_01E7A800);
        break;
    case 5:
    case 6:
        CrashModeMultiplier__18CB3HUDSoundManagerFv(&D_01E7A800);
        break;
    case 7:
        func_00284B60(&D_01E7A800);
        break;
    }
}

extern "C" void func_0043CCE0(UnkStruct_0043CCE0 * self, unsigned int ev, int a, int b)
{
    unsigned char flip = D_0064D33B.field_0;
    int i;
    int s;
    int s2;
    int id;
    self->field_D4 = D_004F50A0.field_0;
    self->field_D8 = D_004D1E50[ev];
    switch (ev) {
    case 0:
        func_00457B20(self->field_10, (void *)(self->field_70), (void *)(func_00271A00(D_0051BA44, 0x8BC)), (void *)(0), 0, 0, 0);
        func_00284400(&D_01E7A800, 1.0f, 1.0f);
        break;
    case 1:
    case 2:
    case 0x15:
        break;
    case 3:
        func_0043C960(self, a, b);
        break;
    case 4:
        s = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x10);
        func_0043CCE0_inl1(&self->field_CC[0], a);
        func_003B8840((void *)(s), self->field_CC[0]);
        func_00457B20(self->field_10, (void *)(self->field_70), (void *)(s), (void *)(0), 5, 0, 0);
        self->field_DC++;
        func_00458900(&self->field_7C[0].field_0[self->field_DC], 0x18);
        func_00284BD0(&D_01E7A800);
        break;
    case 5:
        s = 0;
        if (a != 0 || self->field_CC[0] > 0) {
            s = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x10);
            func_0043CCE0_inl1(&self->field_CC[0], a);
            func_003B8840((void *)(s), self->field_CC[0]);
        }
        s2 = 0;
        if (b != 0 || self->field_CC[1] > 0) {
            s2 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x10);
            func_0043CCE0_inl1(&self->field_CC[1], b);
            func_003B8840((void *)(s2), self->field_CC[1]);
        }
        func_00457B20(self->field_10, (void *)(self->field_70), (void *)(s), (void *)(s2), 6, 0, 0);
        self->field_DC++;
        for (i = 0; i < 2; i++) {
            if (func_00458960(&self->field_7C[i].field_0[self->field_DC])) {
                func_00458900(&self->field_7C[i].field_0[self->field_DC], 0x18);
            }
        }
        func_00284BD0(&D_01E7A800);
        break;
    case 6:
        for (i = 0; i < 2; i++) {
            int k;
            if (flip != 0) {
                if (i != 0) {
                    k = 0;
                } else {
                    k = 1;
                }
            } else {
                k = i;
            }
            int v = self->field_CC[k];
            if (v > 0) {
                func_0031BD60(&D_01E89788, ((UnkStruct_D_00522660 *)(D_00522660 + i * 0x27D0))->field_12C494 + v, k == 1);
            }
        }
        if (func_00131CA0(&D_004EE040)) {
            func_00457B20(self->field_10, (void *)(self->field_70), (void *)(0), (void *)(0), 6, 0, 0);
        } else {
            func_00457B20(self->field_10, (void *)(self->field_70), (void *)(0), (void *)(0), 5, 0, 0);
            func_00284BD0(&D_01E7A800);
        }
        break;
    case 7:
        func_00457B20(self->field_10, (void *)(self->field_70), (void *)(func_00271A00(D_0051BA44, 0x8BD)), (void *)(0), 0, 0, 0);
        func_00284400(&D_01E7A800, 1.0f, 1.0f);
        break;
    case 8:
        func_00457B20(self->field_10, (void *)(self->field_70), (void *)(func_00271A00(D_0051BA44, 0x8BE)), (void *)(0), 1, 0, 0);
        func_00284400(&D_01E7A800, 1.0f, 1.0f);
        break;
    case 9:
        func_00457B20(self->field_10, (void *)(self->field_70), (void *)(0), (void *)(0), 7, func_0043C8F0(self, a), 0);
        func_0043CCE0_inl2(a);
        break;
    case 10: {
        int v1 = func_0043C8F0(self, a);
        int v2 = func_0043C8F0(self, b);
        func_00457B20(self->field_10, (void *)(self->field_70), (void *)(0), (void *)(0), 8, v1, v2);
        func_0043CCE0_inl2(a);
        func_0043CCE0_inl2(b);
        break;
    }
    case 11: {
        int v1 = func_0043C8F0(self, a);
        int v2 = func_0043C8F0(self, b);
        func_00457B20(self->field_10, (void *)(self->field_70), (void *)(0), (void *)(0), 8, v1, v2);
        func_00457B20(self->field_10, (void *)(self->field_70), (void *)(0), (void *)(0), 0xA, 0, 0);
        func_00284400(&D_01E7A800, 1.0f, 1.0f);
        break;
    }
    case 12:
        if (a == b && a != 0 && b != 0) {
            int v1 = func_0043C8F0(self, a);
            int v2 = func_0043C8F0(self, b);
            func_00457B20(self->field_10, (void *)(self->field_70), (void *)(0), (void *)(0), 0xB, v1, v2);
            func_002859F0(&D_01E7A800);
        } else {
            func_00457B20(self->field_10, (void *)(self->field_70), (void *)(0), (void *)(0), 0xB, 0, 0);
            func_00284C80(&D_01E7A800);
        }
        break;
    case 13:
        if (flip != 0) {
            if (a != 0) func_0031BD60(&D_01E89788, D_006512D8.field_0, 0);
            if (b != 0) func_0031BD60(&D_01E89788, D_0064EB08.field_0, 1);
        } else {
            if (a != 0) func_0031BD60(&D_01E89788, D_0064EB08.field_0, 0);
            if (func_00131CA0(&D_004EE040) && b != 0) func_0031BD60(&D_01E89788, D_006512D8.field_0, 1);
        }
        func_00457B20(self->field_10, (void *)(self->field_70), (void *)(0), (void *)(0), 9, 0, 0);
        self->field_DC++;
        for (i = 0; i < 2; i++) {
            if (func_00458960(&self->field_7C[i].field_0[self->field_DC])) {
                func_00458900(&self->field_7C[i].field_0[self->field_DC], 0x18);
            }
        }
        break;
    case 14:
        func_00457B20(self->field_10, (void *)(self->field_70), (void *)(func_00271A00(D_0051BA44, 0x99C)), (void *)(0), 0xC, self->field_C0, 0);
        func_00284C40(&D_01E7A800);
        break;
    case 15:
        func_00457B20(self->field_10, (void *)(self->field_70), (void *)(0), (void *)(0), 0xD, 0, 0);
        func_00284400(&D_01E7A800, 1.0f, 1.0f);
        break;
    case 16:
        func_0031B640(&D_01E89788);
        func_00284400(&D_01E7A800, 1.0f, 1.0f);
        func_00284C40(&D_01E7A800);
        break;
    case 17:
        switch (a) {
        case 0xB:
            s = func_00271A00(D_0051BA44, 0x27A);
            func_00285560(&D_01E7A800, 2, 0);
            id = 4;
            break;
        case 0xC:
            s = func_00271A00(D_0051BA44, 0x27B);
            func_00285560(&D_01E7A800, 1, 0);
            id = 3;
            break;
        case 0xD:
            s = func_00271A00(D_0051BA44, 0x27C);
            func_00285560(&D_01E7A800, 0, 0);
            id = 2;
            break;
        }
        func_00457B20(self->field_10, (void *)(self->field_70), (void *)(s), (void *)(0), id, 0, 0);
        break;
    case 18:
        if (a == 0xA) {
            s = func_00271A00(D_0051BA44, 0xA1E);
        } else if (a == 8) {
            s = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x10);
            void * args = &D_0064ED24;
            func_003180A0((void *)(s), (void *)(func_00271A00(D_0051BA44, 0x305)), &args);
        } else {
            s = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x10);
            void * args = &D_006514F4;
            func_003180A0((void *)(s), (void *)(func_00271A00(D_0051BA44, 0x305)), &args);
        }
        func_00457B20(self->field_10, (void *)(self->field_70), (void *)(s), (void *)(0), 0, 0, 0);
        func_00284400(&D_01E7A800, 1.0f, 1.0f);
        break;
    case 19:
        func_00457B20(self->field_10, (void *)(self->field_70), (void *)(func_00271A00(D_0051BA44, 0x2F3)), (void *)(0), 0, 0, 0);
        s = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x10);
        func_003B8840((void *)(s), D_0064EB08.field_0);
        func_00457B20(self->field_10, (void *)(self->field_70), (void *)(s), (void *)(0), 5, 0, 0);
        func_00284400(&D_01E7A800, 1.0f, 1.0f);
        func_00284BD0(&D_01E7A800);
        break;
    case 20:
        func_00457B20(self->field_10, (void *)(self->field_70), (void *)(func_00271A00(D_0051BA44, 0x304)), (void *)(0), 0, 0, 0);
        s = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x10);
        func_003B8840((void *)(s), D_0064EB08.field_0 + D_006512D8.field_0);
        func_00457B20(self->field_10, (void *)(self->field_70), (void *)(s), (void *)(0), 5, 0, 0);
        func_00284400(&D_01E7A800, 1.0f, 1.0f);
        func_00284BD0(&D_01E7A800);
        break;
    }
}
