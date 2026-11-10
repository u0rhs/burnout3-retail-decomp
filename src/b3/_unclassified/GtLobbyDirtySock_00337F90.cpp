// CGtLobbyPS2DirtySock::UpdatePlayerParams(CGtLobbyJoinGameParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (hand-written).

class CGtLobbyJoinGameParams {
public:
    int field_0; char *field_4; int field_8; int field_C; int field_10; int field_14; int field_18; int field_1C; int field_20; int field_24;
};
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
    void UpdatePlayerParams(CGtLobbyJoinGameParams *p0);
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
    unsigned char pad_121[0x42F];
    int field_550;
    int field_554;
    int field_558;
    int field_55C;
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
extern "C" void PlayerParametersUpdateCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void*);

// 0x00337F90
void CGtLobbyPS2DirtySock::UpdatePlayerParams(CGtLobbyJoinGameParams *p0)
{
    int vals[3];
    char buf[0x30];
    char tmp[16];
    memset(vals, 0, 12);
    vals[0] = p0->field_C;
    vals[1] = p0->field_10;
    vals[2] = p0->field_14;
    buf[0] = 0;
    for (int i = 0; i < 3; i++) {
        sprintf(tmp, &D_004C5998, vals[i]);
        strcat(buf, tmp);
    }
    D_004E2DAC.field_0[0] = 0;
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5850, p0->field_4);
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C59C8, buf);
    field_550 = p0->field_18;
    field_554 = p0->field_1C;
    field_558 = p0->field_20;
    field_55C = p0->field_24;
    field_110 = 1;
    field_111 = 0;
    field_112 = 0;
    field_120 = 0;
    field_114 = 0;
    LobbyApiRequestCB(field_104, 0x67736574, D_004E2DAC.field_0, (void *)&PlayerParametersUpdateCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, this);
    vfunc_14();
}
