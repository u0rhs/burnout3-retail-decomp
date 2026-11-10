// Hand-written; the lifter refused it (case callees take self (a0 kept live, as sibling func_00398270) -> li a1,5 compare register).

struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_B { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_vt {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_0045B050 {
    unsigned char pad_0[0xD4D];
    signed char field_D4D;
};
extern UnkStruct_I D_01E90424;
extern UnkStruct_B D_01E8997C;
extern UnkStruct_P D_004F50C0, D_01E7A800, D_01E90240, D_01E32AE0;
extern UnkStruct_D_vt D_01E898E8;

extern "C" int GetMenuConfirm__15CB3InputManagerFSc(void *, signed char);
extern "C" void FESelect__18CB3HUDSoundManagerFv(void *);
extern "C" int AmIHost__17CB3NetworkManagerFv(void *);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, int, bool);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_0045A850(UnkStruct_0045B050 *);
extern "C" void func_0045A3E0(UnkStruct_0045B050 *);
extern "C" void func_0045A050(UnkStruct_0045B050 *);
extern "C" void func_0045A240(UnkStruct_0045B050 *);
extern "C" void func_0045AE20(UnkStruct_0045B050 *);
extern "C" void func_0045A9F0(void *);

// 0x0045B050
extern "C" void func_0045B050(UnkStruct_0045B050 * self)
{
    if (D_01E90424.field_0 != 5) return;
    if (self->field_D4D == 6) goto host;
    switch (self->field_D4D) {
    case 0: func_0045A850(self); break;
    case 1: func_0045A3E0(self); break;
    case 2:
        if (D_01E8997C.field_0 == 2) {
            if (GetMenuConfirm__15CB3InputManagerFSc(&D_004F50C0, 0) != 0) {
                func_0045A9F0(self);
                FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            }
        }
        break;
    case 3: func_0045AE20(self); break;
    case 5: func_0045A050(self); break;
    case 7: func_0045A240(self); break;
    case 4:
        if (func_0032B2C0(&D_01E898E8, 0, 1) == 0) {
            ((UnkStruct_D_vt*)&D_01E898E8)->vfunc_C();
            func_0045A9F0(self);
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
        }
    case 6: break;
    }
    return;
host:
    if (func_0032B2C0(&D_01E898E8, 0, (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) ^ 1) != 0) {} else
    StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, false);
}
