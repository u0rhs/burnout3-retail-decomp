// Hand-written; the lifter refused it (a117: menu component Prepare; i,j declared at top, inner j loop entry-jump goto [N24]).

struct UnkStruct_D_01E903F4 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E90438 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_00453560 {
    unsigned char pad_0[0x12C];
    void * field_12C;
    int field_130;
    int field_134;
    int field_138;
    int field_13C;
    int field_140[8];
    int field_160[8];
    int field_180[8];
    int field_1A0[8];
    unsigned char field_1C0[8];
    unsigned short field_1C8[1];
    unsigned char pad_1CA[0xE];
    unsigned short field_1D8[8][2];
    signed char field_1F8;
    signed char field_1F9;
    signed char field_1FA;
    unsigned char field_1FB;
    unsigned char field_1FC;
    unsigned char field_1FD;
    signed char field_1FE;
    unsigned char pad_1FF[5];
    unsigned char field_204;
};
extern UnkStruct_D_01E903F4 D_01E903F4;
extern UnkStruct_D_01E90438 D_01E90438;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" void * ConstructChild__10CGt2dFrameFv(void *);
extern "C" void SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(void *);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003D0960(void *, int, void *, int);

// 0x00453560
extern "C" void func_00453560(UnkStruct_00453560 * self)
{
    Prepare__20CB3MenuComponentBaseFv(self);
    self->field_12C = ConstructChild__10CGt2dFrameFv(D_01E903F4.field_0);
    SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(self->field_12C);
    self->field_134 = 7;
    self->field_138 = 0;
    self->field_13C = 0;
    self->field_204 = 0;
    self->field_1FC = 0;
    self->field_1FB = 0;
    self->field_1FD = 0;
    self->field_1F8 = -1;
    self->field_1F9 = -1;
    self->field_1FA = -1;
    self->field_1FE = -1;
    self->field_130 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x20);
    func_003D0960((void *)(self->field_130), 0x20, (void *)(func_00271A00(&D_0051BA44, 0x9C4)), 0);
    int i;
    int j;
    for (i = 0; i < 8; i++) {
        self->field_140[i] = 0;
        self->field_160[i] = 0;
        self->field_1C0[i] = 0;
        self->field_180[i] = 0;
        self->field_1A0[i] = 0;
    }
    for (i = 0; i < 8; i++) {
        j = 0;
        goto test;
    body:
        self->field_1D8[i][j] = 0x400;
        j++;
    test:
        if (j < 2) goto body;
    }
}
