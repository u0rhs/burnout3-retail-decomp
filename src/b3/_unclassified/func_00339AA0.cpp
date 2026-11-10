// Hand-written; the lifter refused it (a245: two-entry unit: vfunc_14 thunk stub + unnamed func_00339AB0 body; needed a146_cmp.py to canonicalise relocs (it compared raw)).

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
    unsigned char pad_121[0x13];
    struct UnkStruct_134 * field_134;
};
struct UnkStruct_D_004E2DAC { unsigned char * field_0; };
struct UnkStruct_Dx { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_Dx D_004C5850, D_004C5998, D_004C59C8;
extern "C" void TagFieldSetString(unsigned char *, int, void *, const char *);
extern "C" void TagFieldSetFlags(unsigned char *, int, void *, int);
extern "C" void LobbyApiRequestCB(int, int, unsigned char *, void *, CGtLobbyPS2DirtySock *);
extern "C" int sprintf(char *, const void *, ...);
extern "C" char *strcat(char *, const char *);
extern "C" void *memset(void *, int, unsigned);
struct UnkStruct_134 { unsigned char pad_0[4]; char f4[4]; };
extern UnkStruct_Dx D_004C5910, D_004C5918, D_004C5A28;
extern "C" void GameLeaveCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void*);

// 0x00339AA0
extern "C" void func_00339AA0(CGtLobbyPS2DirtySock *self)
{
    self->vfunc_14();
}
extern "C" void func_00339AB0(CGtLobbyPS2DirtySock *self)
{
    self->vfunc_14();
    D_004E2DAC.field_0[0] = 0;
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5850, self->field_134->f4);
    int v;
    if (self->vfunc_AC() != 0) {
        TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5910, (char *)&D_004C5918);
        LobbyApiRequestCB(self->field_104, 0x6764656C, D_004E2DAC.field_0, (void *)&GameLeaveCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, self);
        v = 1;
    } else {
        TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5A28, (char *)&D_004C5918);
        LobbyApiRequestCB(self->field_104, 0x676C6561, D_004E2DAC.field_0, (void *)&GameLeaveCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, self);
        v = 1;
    }
    self->field_110 = v;
    self->field_111 = 0;
    self->field_112 = 0;
    self->field_120 = 0;
    self->field_114 = 0;
    self->vfunc_14();
}
