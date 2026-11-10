// Hand-written; the lifter refused it (vptr class, int r=1 both arms).

// func_00336320
struct UnkStruct_00336320_3 { unsigned char pad_0[0x38]; signed char field_38; };
struct UnkStruct_D_004C5850 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C5910 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C5918 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004E2DAC { unsigned char * field_0; };
struct UnkStruct_00336320_1 { unsigned char pad_0[4]; char field_4; };
class UnkStruct_00336320 {
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
    virtual void vfunc_B0();
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
    UnkStruct_00336320_1 * field_134;
};
extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_D_004C5850 D_004C5850;
extern UnkStruct_D_004C5910 D_004C5910;
extern UnkStruct_D_004C5918 D_004C5918;
extern "C" void GameLeaveCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void*);
extern "C" void TagFieldSetString(unsigned char *, int, void *, void *);
extern "C" void LobbyApiRequestCB(int, int, unsigned char *, void *, UnkStruct_00336320 *);

// 0x00336320
extern "C" void func_00336320(UnkStruct_00336320 * self)
{
    D_004E2DAC.field_0[0] = 0;
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5850, ((char *)self->field_134 + 0x4));
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5910, &D_004C5918);
    int r;
    if (self->vfunc_AC() != 0) {
        LobbyApiRequestCB(self->field_104, 0x6764656C, D_004E2DAC.field_0, (void *)&GameLeaveCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, self);
        r = 1;
    } else {
        LobbyApiRequestCB(self->field_104, 0x676C6561, D_004E2DAC.field_0, (void *)&GameLeaveCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, self);
        r = 1;
    }
    self->field_110 = r;
    self->field_111 = 0;
    self->field_112 = 0;
    self->field_120 = 0;
    self->field_114 = 0;
    self->vfunc_14();
}
