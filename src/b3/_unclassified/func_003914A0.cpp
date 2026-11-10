// Hand-written; the lifter refused it (a131: RELOC only splat consts D_0012AD28/D_0012C08C (a107 exception); int i decl first fixes s0/s1).

struct UnkStruct_003914A0_car {
    unsigned char pad_0[0x10C0];
    unsigned char field_10C0[0xA0];
    unsigned char field_1160;
    unsigned char pad_1161[0x1DF];
    float field_1340;
};
struct UnkStruct_003914A0_g {
    unsigned char pad_0[0x12AD28];
    UnkStruct_003914A0_car * field_12AD28[1];
};
struct UnkStruct_003914A0_g2 {
    unsigned char pad_0[0x12C08C];
    int field_12C08C;
};
struct UnkStruct_003914A0_im { unsigned char pad_0[0x12C]; };
struct UnkStruct_D_004F6061 { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_0064D37C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064D3A0 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E32AE0_x { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E90430 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064ED5D { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_003914A0_g D_00522660;
extern UnkStruct_D_01E32AE0_x D_01E32AE0;
extern UnkStruct_003914A0_im D_004F50C0;
extern UnkStruct_D_004F6061 D_004F6061;
extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_01E90430 D_01E90430;
extern UnkStruct_D_0064ED5D D_0064ED5D;
extern UnkStruct_D_01E32AE0_x D_01E77540;
extern UnkStruct_D_01E32AE0_x D_01E94C94;
extern "C" void func_0026FAA0(void *, int);
extern "C" void Update__8CB3ScoreFv(void *);
extern "C" int func_0012FB10(void *, int);
extern "C" void func_00288F60(void *);
extern "C" void SetPause__15CB3InputManagerFb(void *, bool);
extern "C" int func_00342410(void *, int, int);

// 0x003914A0
extern "C" bool func_003914A0()
{
    func_0026FAA0(&D_01E32AE0, 0);
    int i;
    void * m = (char *)&D_004F50C0 + D_004F6061.field_0 * 300 + 0xD48;
    for (i = 0; i < D_0064D37C.field_0; i++) {
        UnkStruct_003914A0_car * c = D_00522660.field_12AD28[i];
        if (c->field_1340 < 0.0f) {
            if (c->field_1160 != 0) {
                *(int *)&c->field_1340 = 0x40E00000;
            } else {
                *(int *)&c->field_1340 = 0x40400000;
            }
        }
        Update__8CB3ScoreFv(c->field_10C0);
    }
    if (func_0012FB10(m, 1)) {
        if (D_01E90430.field_0 == 0) {
            func_00288F60(&D_01E77540);
            D_0064ED5D.field_0 = 0;
            SetPause__15CB3InputManagerFb(&D_004F50C0, true);
            func_00342410(&D_01E94C94, 1, 1);
        }
    }
    bool r = true;
    for (int j = 0; j < D_0064D3A0.field_0; j++) {
        if (((UnkStruct_003914A0_g2 *)((char *)&D_00522660 + j * 0x27D0))->field_12C08C != 3) {
            r = false;
        }
    }
    return r;
}
