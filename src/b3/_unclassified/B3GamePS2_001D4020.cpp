// CB3Game::CheckPowerOff() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3GamePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a95: hand-written extern C; vfunc pun on a padded extern, do-while chains, int-pun 1.0f store).

struct UnkStruct_001D4020_self {
    unsigned char pad_0[0x2DA80];
    unsigned char field_2DA80;
    unsigned char field_2DA81;
};
struct UnkStruct_D_00666124 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00666228 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E75640 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E3C620 {
    virtual void vfunc_8();
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_00666124 D_00666124;
extern UnkStruct_D_00666228 D_00666228;
extern UnkStruct_D_00665EC0 D_00665EC0;
extern UnkStruct_D_01E75640 D_01E75640;
extern UnkStruct_D_01E3C620 D_01E3C620;
extern char D_004B7F50[];
extern char D_004B7F70[];
extern "C" int sceDevctl(const char *, int, void *, int, void *, int);
extern "C" int sprintf(char *, const char *, ...);
extern "C" void func_001E1FF0(int, void *, int);
extern "C" void OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(void *, int);
extern "C" void CloseViewport__22CB3GraphicsManagerBaseFv(void *);
extern "C" void PresentDrawBuffer__18CB3GraphicsManagerFv(void *);
extern "C" void func_0028AEB0(void *);
extern "C" void SetMasterVolumeScalar__15CB3SoundManagerFf(void *, float);
extern "C" void func_0028B160(void *);
extern "C" bool func_0011F990(void *);

extern "C" void CheckPowerOff__7CB3GameFv(UnkStruct_001D4020_self * self)
{
    char buf20[0x88];
    int local_ac;
    if (self->field_2DA81 == 0) return;
    if (self->field_2DA80 == 0) return;
    D_00666124.field_0 = 0x3F800000;
    for (int i = 0; i < 30; i++) {
        char z[4] = {0};
        func_001E1FF0(D_00666228.field_0, z, 3);
        OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(&D_00665EC0, 0);
        CloseViewport__22CB3GraphicsManagerBaseFv(&D_00665EC0);
        PresentDrawBuffer__18CB3GraphicsManagerFv(&D_00665EC0);
    }
    func_0028AEB0(&D_01E75640);
    SetMasterVolumeScalar__15CB3SoundManagerFf(&D_01E75640, 0.0f);
    for (int j = 0; j < 32; j++) func_0028B160(&D_01E75640);
    ((UnkStruct_D_01E3C620 *)&D_01E3C620)->vfunc_8();
    int r;
    do {
        r = sceDevctl(D_004B7F50, 0x4402, 0, 0, 0, 0);
        if (r < 0) sprintf(buf20, D_004B7F70, r);
    } while (r < 0);
    do {
        while (!func_0011F990(&local_ac)) {}
    } while (local_ac != 0);
    for (;;) {}
}
