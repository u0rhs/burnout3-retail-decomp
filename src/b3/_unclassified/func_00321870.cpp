// Hand-written; the lifter refused it (a125: sibling of func_003F0CE0 (func_00456780 event switch), cases 0/1/7 -> func_00321A50).

struct UnkStruct_D_vt { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_D_byte { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_gp { int field_0; int field_4; };
struct UnkStruct_D_big { unsigned char pad_0[0x10]; };
struct UnkStruct_00321870_2 { int field_0; };
extern UnkStruct_D_byte D_01E8D45A;
extern UnkStruct_D_vt D_01E8D450;
extern UnkStruct_D_byte D_01E8F94A;
extern UnkStruct_D_vt D_01E8F940;
extern UnkStruct_D_gp D_004E2D68;
extern UnkStruct_D_gp D_004E2D70;
extern UnkStruct_D_gp D_004E2D78;
extern UnkStruct_D_big D_01EA31C0;
extern UnkStruct_D_gp D_004E2D80;
extern UnkStruct_D_gp D_004E2D88;
extern "C" void func_00321A50(void *, int);
extern "C" int func_00456780(void *, UnkStruct_00321870_2 *, void *, void *, void *, void *, void *, void *, int);

// 0x00321870
extern "C" void func_00321870(void * self, int p0)
{
    UnkStruct_00321870_2 local;
    if (D_01E8D45A.field_0 != 0) {
        ((UnkStruct_D_vt *)&D_01E8D450)->vfunc_C();
    }
    if (D_01E8F94A.field_0 != 0) {
        ((UnkStruct_D_vt *)&D_01E8F940)->vfunc_C();
    }
    switch (p0) {
    case 0:
    case 1:
    case 7:
        func_00321A50(self, p0);
        break;
    case 3:
        local.field_0 = 133;
        func_00456780(&D_01E8F940, &local, &D_004E2D68, &D_004E2D70, &D_004E2D78, &D_01EA31C0, &D_004E2D80, &D_004E2D88, 1);
        break;
    case 4:
        local.field_0 = 134;
        func_00456780(&D_01E8F940, &local, &D_004E2D68, &D_004E2D70, &D_004E2D78, &D_01EA31C0, &D_004E2D80, &D_004E2D88, 1);
        break;
    case 5:
        local.field_0 = 135;
        func_00456780(&D_01E8F940, &local, &D_004E2D68, &D_004E2D70, &D_004E2D78, &D_01EA31C0, &D_004E2D80, &D_004E2D88, 1);
        break;
    case 2:
        local.field_0 = 137;
        func_00456780(&D_01E8F940, &local, &D_004E2D68, &D_004E2D70, &D_004E2D78, &D_01EA31C0, &D_004E2D80, &D_004E2D88, 1);
        break;
    case 6:
        break;
    }
}
