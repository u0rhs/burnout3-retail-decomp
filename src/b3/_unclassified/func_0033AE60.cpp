// Hand-written; the lifter refused it (a126: account register request; !(strlen>12) gives sltiu at).

class CGtLobbyAcctParams { public: char *f0; char *f4; char *f8; char *fC; char *f10; char *f14; char *f18; char *f1C; unsigned char f20; unsigned char f21; };
class CGtLobbyCreateGameParams {
public:
    char *field_0; char *field_4; int field_8; int field_C[8]; int field_2C[4];
};
struct UnkStruct_25C { int field_0; };
class CGtLobbyPS2DirtySock {
public:
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual int vfunc_AC();
    unsigned char pad_4[0x100];
    int field_104;
    unsigned char pad_108[0x8];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x8];
    unsigned char field_120;
    unsigned char field_121;
    unsigned char pad_122[6];
    int field_128;
    unsigned char pad_12C[8];
    int field_134;
    unsigned char pad_138[0x124];
    UnkStruct_25C *field_25C;
    unsigned char pad_260[0x1E4];
    char field_444[0x20];
    char field_464[0x20];
    unsigned char pad_484[0x40];
    unsigned char field_4C4;
    unsigned char pad_4C5[0x8B];
    int field_550;
    int field_554;
    int field_558;
    int field_55C;
};
struct UnkStruct_D_004E2DAC { unsigned char * field_0; };
struct UnkStruct_Dy { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_Dy D_004C5B08, D_004C5B10, D_004C5B18, D_004C5960, D_004C5B20, D_004C5B28, D_004C5A88, D_004C5AD8, D_004C5A08, D_004C5858, D_004C5850, D_004C5998, D_004C59A0, D_004C59A8, D_004C59B0, D_004C59B8, D_004C59C0;
extern "C" void TagFieldSetString(unsigned char *, int, void *, const char *);
extern "C" void TagFieldSetNumber(unsigned char *, int, void *, int);
extern "C" void LobbyApiRequestCB(int, int, unsigned char *, void *, CGtLobbyPS2DirtySock *);
extern "C" int sprintf(char *, const void *, ...);
extern "C" char *strcat(char *, const char *);
extern "C" char *strcpy(char *, const char *);
extern "C" void *memset(void *, int, unsigned);
extern "C" void AccountRegisterCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void*);
extern "C" unsigned int strlen(const char *);
extern "C" void GameCreatedCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void*);
extern "C" void DefaultCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void*);

// 0x0033AE60
extern "C" void func_0033AE60(CGtLobbyPS2DirtySock *self, CGtLobbyAcctParams *p)
{
    char yn[3];
    D_004E2DAC.field_0[0] = 0;
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5850, p->f0);
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C59A0, p->f4);
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5A08, p->f8);
    if (p->fC != 0)
        TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5B08, p->fC);
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5B10, p->f10);
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5B18, p->f14);
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5960, p->f18);
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5B20, p->f1C);
    if (!(strlen(p->f0) > 12))
        TagFieldSetNumber(D_004E2DAC.field_0, 1024, &D_004C5B28, 1);
    if (p->f20 != 0) yn[0] = 'Y'; else yn[0] = 'N';
    if (p->f21 != 0) yn[1] = 'Y'; else yn[1] = 'N';
    yn[2] = 0;
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5A88, yn);
    TagFieldSetNumber(D_004E2DAC.field_0, 1024, &D_004C5AD8, 5);
    self->field_110 = 1;
    self->field_111 = 0;
    self->field_112 = 0;
    self->field_120 = 0;
    self->field_114 = 0;
    LobbyApiRequestCB(self->field_104, 0x61636374, D_004E2DAC.field_0, (void *)&AccountRegisterCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, self);
    self->vfunc_14();
}
