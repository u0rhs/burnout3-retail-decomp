// Hand-written; the lifter refused it (re-queued after the jtbl_retarget 2-table fix (from build/vt/hand/func_0043FFB0_l264ff0.cpp)).

// func_0043FFB0 -- hand-written (a158): FSM action handler (action p0: 0 reset, 3 start, 5 confirm, 2 leave); flags +0x10/+0x11/+0x12 [G]
// [G] func_0043FFB0_inl1 = the inlined case-2 body (placeholder, brief inline-helper rule)
struct UnkStruct_D_0051BF9C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E900B4 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E900B8 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E9020C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E90208 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E90210 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_P16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E98478 { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_0043FFB0_6 { unsigned char pad_0[0x14]; int field_14; };
struct UnkStruct_0043FFB0 { unsigned char pad_0[0x10]; unsigned char field_10; unsigned char field_11; unsigned char field_12; };
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_01E900B4 D_01E900B4;
extern UnkStruct_D_01E900B8 D_01E900B8;
extern UnkStruct_D_01E9020C D_01E9020C;
extern UnkStruct_D_01E90208 D_01E90208;
extern UnkStruct_D_01E90210 D_01E90210;
extern UnkStruct_P16 D_01E7A888;
extern UnkStruct_P16 D_01E900B0;
extern UnkStruct_D_01E98478 D_01E98478;
extern UnkStruct_0043FFB0_6 * D_01E901DC[];
extern int D_004E2918;
extern "C" int func_0013AB80(void *, int, int);
extern "C" int func_0013AA10(void *, int, int);
extern "C" int func_0013A8A0(void *, int, int);
extern "C" void func_003FA600(void *, int);
extern "C" int func_00424750(void *, int, int, int, float);
extern "C" void RequestNewGameMode__14CB3MenuChoicesFv(void *);

static inline bool func_0043FFB0_inl1(UnkStruct_0043FFB0 *self)
{
    if (self->field_10 == 0) return false;
    ((UnkStruct_D_01E98478 *)&D_01E98478)->vfunc_C();
    func_003FA600(&D_01E7A888, 1);
    return true;
}

// 0x0043FFB0
extern "C" void func_0043FFB0(UnkStruct_0043FFB0 * self, int p0, int p1, int p2)
{
    switch (p0) {
    case 0:
        self->field_11 = 0;
        self->field_12 = 0;
        break;
    case 3: {
        int s0 = D_0051BF9C.field_0;
        int m = D_01E900B4.field_0;
        if (m == 4) {
            RequestNewGameMode__14CB3MenuChoicesFv(&D_01E900B0);
            break;
        }
        bool c;
        if (m == 0) {
            c = D_01E901DC[0]->field_14 == 6;
        } else {
            c = D_01E900B8.field_0 == 3;
        }
        self->field_10 = 0;
        if (c) {
            D_01E9020C.field_0 = 0x998;
            D_01E90210.field_0 = 98.49850464f;
            int sum = func_0013AB80((void *)(s0), 1, 2);
            sum += func_0013AB80((void *)(s0), 2, 2);
            sum += func_0013AB80((void *)(s0), 3, 2);
            sum += func_0013A8A0((void *)(s0), 1, 2);
            sum += func_0013A8A0((void *)(s0), 2, 2);
            sum += func_0013A8A0((void *)(s0), 3, 2);
            sum += func_0013AA10((void *)(s0), 1, 2);
            sum += func_0013AA10((void *)(s0), 2, 2);
            sum += func_0013AA10((void *)(s0), 3, 2);
            if (sum == 0) {
                self->field_10 = (self->field_12 != 0) ^ 1;
                self->field_12 = 1;
                switch (D_004E2918) {
                case 0: case 1: case 7: case 8: case 9:
                default: D_01E90208.field_0 = 0xB; break;
                case 10: D_01E90208.field_0 = 0xA; break;
                case 11: D_01E90208.field_0 = 0x11; break;
                case 5: D_01E90208.field_0 = 0x10; break;
                case 3: D_01E90208.field_0 = 0xD; break;
                case 4: D_01E90208.field_0 = 0xC; break;
                case 6: D_01E90208.field_0 = 0xE; break;
                case 2: D_01E90208.field_0 = 0xF; break;
                }
            }
        } else {
            D_01E9020C.field_0 = 0x997;
            D_01E90210.field_0 = 123.723732f;
            int sum = func_0013AB80((void *)(s0), 1, 1);
            sum += func_0013AB80((void *)(s0), 2, 1);
            sum += func_0013AB80((void *)(s0), 3, 1);
            sum += func_0013A8A0((void *)(s0), 1, 1);
            sum += func_0013A8A0((void *)(s0), 2, 1);
            sum += func_0013A8A0((void *)(s0), 3, 1);
            sum += func_0013AA10((void *)(s0), 1, 1);
            sum += func_0013AA10((void *)(s0), 2, 1);
            sum += func_0013AA10((void *)(s0), 3, 1);
            if (sum == 0) {
                self->field_10 = (self->field_11 != 0) ^ 1;
                self->field_11 = 1;
                switch (D_004E2918) {
                case 0: case 1: case 7: case 8: case 9:
                default: D_01E90208.field_0 = 0x13; break;
                case 10: D_01E90208.field_0 = 0x12; break;
                case 11: D_01E90208.field_0 = 0x19; break;
                case 5: D_01E90208.field_0 = 0x18; break;
                case 3: D_01E90208.field_0 = 0x15; break;
                case 4: D_01E90208.field_0 = 0x14; break;
                case 6: D_01E90208.field_0 = 0x16; break;
                case 2: D_01E90208.field_0 = 0x17; break;
                }
            }
        }
        if (self->field_10 != 0) {
            func_003FA600(&D_01E7A888, 3);
            func_00424750(&D_01E98478, D_01E90208.field_0, 0, D_01E9020C.field_0, D_01E90210.field_0);
        } else {
            RequestNewGameMode__14CB3MenuChoicesFv(&D_01E900B0);
        }
        break;
    }
    case 5:
        switch (p2) {
        case 0:
        case 2:
            RequestNewGameMode__14CB3MenuChoicesFv(&D_01E900B0);
            break;
        case 1:
            return;
        }
        break;
    case 2:
        func_0043FFB0_inl1(self);
        break;
    }
}
