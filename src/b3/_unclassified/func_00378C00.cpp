// Hand-written; the lifter refused it (a84: CB3OnlineRecordsDisplayMenuPage::Prepare [L] DNAT; plain switch w/ jump table, struct from sibling func_003774D0).

// func_00378C00 -- CB3OnlineRecordsDisplayMenuPage::Prepare(EB3SelectedRecord) [L] DNAT (research/proto/new_names.csv, medium)
struct UnkStruct_00378C00 {
    unsigned char pad_0[0xB10];
    void * field_B10[7][5];
    unsigned char pad_B9C[0xC80 - 0xB9C];
    void * field_C80;
    unsigned char pad_C84[0xEE8 - 0xC84];
    long field_EE8;
    int field_EF0;
    unsigned char pad_EF4[0xF00 - 0xEF4];
    int field_F00;
    signed char field_F04;
};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004A4F54 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_P D_01E90438, D_01E3D1E8, D_01E89518, D_01E88A80, D_01E89800, D_01E894FC;
extern UnkStruct_D_004A4F54 D_004A4F54;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" void * AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(void *, void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);
extern "C" void func_003774D0(void *);
extern "C" void func_00378990(void *);

// [L] DNAT: CB3OnlineRecordsDisplayMenuPage::Prepare(EB3SelectedRecord) (research/proto/new_names.csv, medium)
// 0x00378C00
extern "C" int func_00378C00(UnkStruct_00378C00 * self, int rec, long a2)
{
    Prepare__15CB3MenuPageBaseFb(self, false);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 5; j++) {
            self->field_B10[i][j] = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
        }
    }
    self->field_C80 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(&D_01E3D1E8, self->field_B10[0][2], 32);
    self->field_F04 = rec;
    switch (self->field_F04) {
    case 0:
        func_00319C80(&D_01E89518, 0x29C, 14);
        D_004A4F54.field_0 = 0x2B7;
        break;
    case 1:
        func_00319C80(&D_01E89518, 0x29D, 14);
        D_004A4F54.field_0 = 0x2B8;
        break;
    case 2:
        func_00319C80(&D_01E89518, 0x29F, 14);
        D_004A4F54.field_0 = 0x2B9;
        break;
    case 3:
        func_00319C80(&D_01E89518, 0x2A2, 14);
        D_004A4F54.field_0 = 0x2BA;
        break;
    case 4:
        func_00319C80(&D_01E89518, 0x2A3, 14);
        D_004A4F54.field_0 = 0x2BA;
        break;
    case 5:
        func_00319C80(&D_01E89518, 0x2A7, 14);
        D_004A4F54.field_0 = 0x2BD;
        break;
    case 6:
        func_00319C80(&D_01E89518, 0x2A8, 14);
        D_004A4F54.field_0 = 0x2BE;
        break;
    case 7:
        func_00319C80(&D_01E89518, 0x2B1, 14);
        D_004A4F54.field_0 = 0x2B8;
        break;
    case 8:
        func_00319C80(&D_01E89518, 0x2B2, 14);
        D_004A4F54.field_0 = 0x2B8;
        break;
    }
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 0);
    func_0031ECD0(&D_01E89800, 0x145, 3);
    Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
    func_003774D0(self);
    self->field_EF0 = 0;
    self->field_F00 = 1;
    self->field_EE8 = a2;
    func_00378990(self);
    return 1;
}
