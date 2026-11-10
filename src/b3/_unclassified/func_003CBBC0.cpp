// func_003CBBC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (buffer address spelled two ways (member array for the call, byte offset from the stride-6 element for the store) so MWCC re-adds 0x80).

// func_003CBBC0 -- tiny-function batch (tools/tiny_batch.py, lifted; hand-matched).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths).

enum EB3BackgroundType {};
class CB3PromptBarComponent {
public:
    void Prepare();
    unsigned char pad_0[0x10];
};
struct UnkStruct_003CBBC0_e2 {
    unsigned short field_0[3];
};
struct UnkStruct_D_004F50C0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E89518 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E88A80 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E89800 { unsigned char pad_0[0x10]; };
struct UnkStruct_003CBBC0 {
    UnkStruct_003CBBC0_e2 field_0[1];
    unsigned char pad_6[0x72];
    short field_78;
    short field_7A;
    short field_7C;
    short field_7E;
    UnkStruct_003CBBC0_e2 field_80[3];
    unsigned char pad_92[0x2];
    void * field_94[3];
    unsigned char pad_A0[0x14];
    int field_B4;
    unsigned char field_B8;
};
extern int D_004CA498[];
extern UnkStruct_D_004F50C0 D_004F50C0;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);
extern "C" void PrintInt__10CGtUnicodeFPUsii(void *, int, int, int);
extern "C" int func_0022D1E0(void *);
extern "C" void func_00319C80(void *, int, int);
extern "C" void func_003CB900(UnkStruct_003CBBC0 *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
// 0x003CBBC0
// [G] the store spells the buffer address as a byte offset from the stride-6 element at self+i*6, the call as
// the member array: retail keeps self+i*6 in a saved register and re-adds 0x80 after the call, which only
// two different expression forms reproduce (the same form twice is CSE'd whole). The original spelling is unknown.
extern "C" int func_003CBBC0(UnkStruct_003CBBC0 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    for (int i = 0; i < 3; i++) {
        PrintInt__10CGtUnicodeFPUsii(self->field_80[i].field_0, D_004CA498[i], 0, 0);
        self->field_94[i] = ((char *)&self->field_0[i] + 0x80);
    }
    int r2 = func_0022D1E0(&D_004F50C0);
    self->field_B8 = ((((signed char)r2) < 2) ^ 1);
    self->field_78 = 2;
    self->field_7A = 8;
    self->field_7C = 1;
    self->field_7E = 5;
    func_00319C80(&D_01E89518, 356, 14);
    func_003CB900(self, 0);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 273, 3);
    D_01E894FC.Prepare();
    self->field_B4 = 0;
    return 1;
}
