// CGtLobbyPS2DirtySock::KickPlayer(const char*,ELobbyKickReason) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (hand-written; vtable placeholder virtuals).

enum ELobbyKickReason { UnkKick0, UnkKick1, UnkKick2, UnkKick3 };
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
    void KickPlayer(const char *p0, ELobbyKickReason p1);
    unsigned char pad_4[0x100];
    int field_104;
    unsigned char pad_108[0x14];
    unsigned char field_11C;
    unsigned char pad_11D[0x17];
    int field_134;
};
struct UnkStruct_D_004E2DAC { unsigned char * field_0; };
struct UnkStruct_D_004C5978 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_D_004C5978 D_004C5970, D_004C5978, D_004C5980, D_004C5988, D_004C5850;
extern "C" void TagFieldSetString(unsigned char *, int, void *, const char *);
extern "C" void TagFieldSetFlags(unsigned char *, int, void *, int);
extern "C" void LobbyApiRequestCB(int, int, unsigned char *, void *, CGtLobbyPS2DirtySock *);
extern "C" void DefaultCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void*);

// 0x00337870
void CGtLobbyPS2DirtySock::KickPlayer(const char *p0, ELobbyKickReason p1)
{
    if (field_11C != 0 && vfunc_AC() != 0) {
        if (p1 == 3) {
            D_004E2DAC.field_0[0] = 0;
            TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5970, p0);
            TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5978, p0);
            TagFieldSetFlags(D_004E2DAC.field_0, 1024, &D_004C5980, 0x20014008);
            LobbyApiRequestCB(field_104, 0x6D657367, D_004E2DAC.field_0, 0, 0);
        }
        D_004E2DAC.field_0[0] = 0;
        TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5850, (char *)field_134 + 4);
        TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5988, p0);
        LobbyApiRequestCB(field_104, 0x67736574, D_004E2DAC.field_0, (void *)&DefaultCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, this);
    }
    vfunc_14();
}
