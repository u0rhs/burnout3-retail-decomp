// Hand-written; the lifter refused it (near36: _CalculateUV__15CB3MenuImageUVsFffffffUi declared in mangled order (hidden result, 6 floats, unsigned int flags last) -- the lifter's flags-second order changed argument setup/scheduling).

struct UnkStruct_uv { float field_0; float field_4; float field_8; float field_C; };
struct UnkStruct_F { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_L { unsigned long field_0; unsigned char pad_8[8]; };
struct UnkStruct_D_01E90438 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E90438 D_01E90438;
extern UnkStruct_F D_004C7070;
extern UnkStruct_F D_004C7074;
extern UnkStruct_F D_004C7078;
extern UnkStruct_F D_004C707C;
extern UnkStruct_F D_004C7080;
extern UnkStruct_F D_004C7084;
extern UnkStruct_F D_004C7088;
extern UnkStruct_F D_004C708C;
extern UnkStruct_F D_004C7090;
extern UnkStruct_F D_004C7094;
extern UnkStruct_F D_004C7098;
extern UnkStruct_F D_004C709C;
extern UnkStruct_F D_004C70A0;
extern UnkStruct_F D_004C70A4;
extern UnkStruct_F D_004C70A8;
extern UnkStruct_F D_004C70AC;
extern UnkStruct_F D_004C70B0;
extern UnkStruct_F D_004C70B4;
extern UnkStruct_F D_004C70B8;
extern UnkStruct_F D_004C70BC;
extern UnkStruct_F D_004C70C0;
extern UnkStruct_F D_004C70C4;
extern UnkStruct_F D_004C70C8;
extern UnkStruct_F D_004C70CC;
extern UnkStruct_L D_01EA3F40;
extern UnkStruct_F D_01EA3F48;
extern UnkStruct_F D_01EA3F4C;
extern UnkStruct_F D_01EA3F50;
extern UnkStruct_F D_01EA3F54;
extern UnkStruct_F D_01EA3F58;
extern UnkStruct_F D_01EA3F5C;
extern UnkStruct_F D_01EA3F60;
extern UnkStruct_F D_01EA3F64;
extern UnkStruct_F D_01EA3F68;
extern UnkStruct_F D_01EA3F6C;
extern UnkStruct_F D_01EA3F70;
extern UnkStruct_F D_01EA3F74;
extern UnkStruct_F D_01EA3F78;
extern UnkStruct_F D_01EA3F7C;
extern "C" void _CalculateUV__15CB3MenuImageUVsFffffffUi(UnkStruct_uv *out, float f0, float f1, float f2, float f3, float f4, float f5, unsigned int p0);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
class CB3OnScreenKeyboardComponent {
public:
    unsigned char pad_0[0x30D4];
    int field_30D4;
    int field_30D8;
    int field_30DC[5][15];
};
// 0x003517F0
extern "C" int func_003517F0(CB3OnScreenKeyboardComponent *self)
{
    UnkStruct_uv r0; _CalculateUV__15CB3MenuImageUVsFffffffUi(&r0, D_004C7070.field_0, D_004C7074.field_0, D_004C7090.field_0, D_004C7094.field_0, D_004C70B0.field_0, D_004C70B4.field_0, 0);
    D_01EA3F40.field_0 = *(unsigned long *)&r0;
    D_01EA3F48.field_0 = r0.field_8;
    D_01EA3F4C.field_0 = r0.field_C;
    UnkStruct_uv r1; _CalculateUV__15CB3MenuImageUVsFffffffUi(&r1, D_004C7078.field_0, D_004C707C.field_0, D_004C7098.field_0, D_004C709C.field_0, D_004C70B8.field_0, D_004C70BC.field_0, 0);
    D_01EA3F50.field_0 = r1.field_0;
    D_01EA3F54.field_0 = r1.field_4;
    D_01EA3F58.field_0 = r1.field_8;
    D_01EA3F5C.field_0 = r1.field_C;
    UnkStruct_uv r2; _CalculateUV__15CB3MenuImageUVsFffffffUi(&r2, D_004C7080.field_0, D_004C7084.field_0, D_004C70A0.field_0, D_004C70A4.field_0, D_004C70C0.field_0, D_004C70C4.field_0, 0);
    D_01EA3F60.field_0 = r2.field_0;
    D_01EA3F64.field_0 = r2.field_4;
    D_01EA3F68.field_0 = r2.field_8;
    D_01EA3F6C.field_0 = r2.field_C;
    UnkStruct_uv r3; _CalculateUV__15CB3MenuImageUVsFffffffUi(&r3, D_004C7088.field_0, D_004C708C.field_0, D_004C70A8.field_0, D_004C70AC.field_0, D_004C70C8.field_0, D_004C70CC.field_0, 0);
    D_01EA3F70.field_0 = r3.field_0;
    D_01EA3F74.field_0 = r3.field_4;
    D_01EA3F78.field_0 = r3.field_8;
    D_01EA3F7C.field_0 = r3.field_C;
    self->field_30D4 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x40);
    self->field_30D8 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x40);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 15; j++) {
            self->field_30DC[i][j] = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 2);
        }
    }
    return 1;
}
