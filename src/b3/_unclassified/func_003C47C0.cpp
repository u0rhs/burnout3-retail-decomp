// Hand-written; the lifter refused it (a115: switch case order 0,1,2 + default 5; goto for out-of-line no-text arm).

struct UnkStruct_C47C0_pg {
    unsigned char pad_0[0x4];
    float field_4;
};
struct UnkStruct_C47C0_b { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_C47C0_i { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_C47C0_p { const unsigned short * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_C47C0_f { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_C47C0_s { unsigned char pad_0[0x10]; };
extern UnkStruct_C47C0_b D_01ECDAC5;
extern UnkStruct_C47C0_b D_01ECDAC9;
extern UnkStruct_C47C0_b D_01E65499;
extern UnkStruct_C47C0_f D_004F50A0;
extern UnkStruct_C47C0_i D_01ECDAB4;
extern UnkStruct_C47C0_p D_01ECD9F0;
extern UnkStruct_C47C0_s D_01E89518;
extern UnkStruct_C47C0_s D_01E8F090;
extern UnkStruct_C47C0_s D_01E894E0;
extern UnkStruct_C47C0_s D_01E88A80;
extern UnkStruct_C47C0_s D_01E894FC;
extern "C" void Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(void *, const unsigned short *, int);
extern "C" void Prepare__19CB3HeadingComponentFQ219CB3HeadingComponent12EHeadingType(void *, int);
extern "C" int func_00452630(void *);
extern "C" bool Prepare__25CB3EventFinishedComponentFv(void *);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);

// 0x003C47C0
// [G] goto notext/end: retail lays the no-text Prepare block and the 5.0f arm out of line after the main flow (a115)
extern "C" void func_003C47C0(UnkStruct_C47C0_pg * self)
{
    int type;
    const unsigned short * text;
    if (D_01ECDAC5.field_0 == 0 && D_01ECDAC9.field_0 == 0) {
        if (D_01E65499.field_0 != 0) {
            self->field_4 = 3.0f + D_004F50A0.field_0;
        } else {
            self->field_4 = -1.0f;
        }
        switch (D_01ECDAB4.field_0) {
        case 0:
            type = 0;
            break;
        case 1:
            type = 1;
            break;
        case 2:
            type = 2;
            break;
        default:
            type = 5;
            break;
        }
        text = D_01ECD9F0.field_0;
        if (text == 0) goto notext;
        Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(&D_01E89518, text, type);
    rest:
        func_00452630(&D_01E8F090);
        Prepare__25CB3EventFinishedComponentFv(&D_01E894E0);
        Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 8);
        Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
        return;
    } else {
        self->field_4 = 5.0f + D_004F50A0.field_0;
        goto end;
    }
notext:
    Prepare__19CB3HeadingComponentFQ219CB3HeadingComponent12EHeadingType(&D_01E89518, type);
    goto rest;
end:
    return;
}
