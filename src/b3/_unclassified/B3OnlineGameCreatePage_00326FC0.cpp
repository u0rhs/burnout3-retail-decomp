// CB3OnlineGameCreatePage::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineGameCreatePage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a148: nested lobby-status switches (source order 2,0,1), ReportError inline, lp locals declared last (lowest slot), lp stores in order 0,C,10,14,8,18,1C,20,24, vptr objects padded to 0x10, int array D_01E90130).

struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_Lp { int field_0; int field_4; void * field_8; int field_C; int field_10; int field_14; void * field_18; void * field_1C; void * field_20; void * field_24; };
struct UnkStruct_Net {
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
    virtual void vfunc_38(UnkStruct_Lp *);
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual int vfunc_58();
    unsigned char pad_4[0xC];
};
struct UnkStruct_Dlg {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_I2 { int field_0; int field_4; unsigned char pad_8[0x8]; };
struct UnkStruct_D_004E2918 { int field_0; };
struct UnkStruct_GCP {
    unsigned char pad_0[0xC];
    unsigned short field_C[16];
    signed char field_2C;
};
extern UnkStruct_I D_01E90424;
extern UnkStruct_P D_01E32AE0;
extern int D_01E90130[];
extern char D_004C5530[];
extern UnkStruct_Net D_01E3CD44;
extern UnkStruct_Dlg D_01E8D4B0;
extern UnkStruct_P D_01E898E8;
extern UnkStruct_P D_01E7A800;
extern UnkStruct_P D_01E90240;
extern UnkStruct_P D_0051BA44;
extern UnkStruct_P D_01E3D390;
extern char * D_004D1B70[];
extern UnkStruct_D_004E2918 D_004E2918;
extern "C" bool PlayerListChangedCallback__17CB3NetworkManagerFiPv(int, void *);
extern "C" int PlayerBootedCallback__17CB3NetworkManagerF16ELobbyKickReasonPv(int, void *);
extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);
extern "C" int GetErrorString__17CB3NetworkManagerFi(void *, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int func_002351C0(void *);
extern "C" int GetMyPlayerIndex__23CGtNetworkPlayerManagerCFv(void *);
extern "C" void func_00284F10(void *);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, int, int);
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" void func_00310180(unsigned short *dst, const unsigned short *fmt, unsigned short *const &arg);
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(const unsigned short *, char *, int);
extern "C" void SetPresenceDetail__10CGtBuddiesFPcPcPc(void *, char *, char *, char *);
extern "C" int SetPresence__22CGtBuddiesPS2DirtySockF16EGtBuddyPresenceb(void *, int, bool);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, int, bool);

static inline void ReportError(UnkStruct_GCP * self)
{
    int e = ((UnkStruct_Net *)&D_01E3CD44)->vfunc_58();
    self->field_2C = 2;
    ((UnkStruct_Dlg *)&D_01E8D4B0)->vfunc_C();
    func_0032D080(&D_01E898E8, 2, GetErrorString__17CB3NetworkManagerFi(&D_01E32AE0, e), 0, 0);
}

extern "C" void Update__23CB3OnlineGameCreatePageFv(UnkStruct_GCP * self)
{
    unsigned short * p;
    unsigned short ubuf[100];
    char name[100];
    char status[100];
    UnkStruct_Lp lp;
    if (D_01E90424.field_0 != 5) {
        return;
    }
    switch (self->field_2C) {
    case 0:
        switch (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0)) {
        case 2: {
            lp.field_0 = -1;
            lp.field_C = D_01E90130[0];
            lp.field_10 = D_01E90130[1];
            lp.field_14 = 0;
            lp.field_8 = D_004C5530;
            lp.field_18 = (void *)PlayerListChangedCallback__17CB3NetworkManagerFiPv;
            lp.field_1C = &D_01E32AE0;
            lp.field_20 = (void *)PlayerBootedCallback__17CB3NetworkManagerF16ELobbyKickReasonPv;
            lp.field_24 = &D_01E32AE0;
            ((UnkStruct_Net *)&D_01E3CD44)->vfunc_38(&lp);
            self->field_2C = 1;
            break; }
        case 0:
            break;
        case 1:
            ReportError(self);
            break;
        }
        break;
    case 1:
        switch (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0)) {
        case 2:
            if (func_002351C0(&D_01E32AE0) != 0) {
                if (GetMyPlayerIndex__23CGtNetworkPlayerManagerCFv(&D_01E32AE0) > -1) {
                    func_00284F10(&D_01E7A800);
                    StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 1, 0);
                    p = self->field_C;
                    func_00310180(ubuf, func_00271A00(&D_0051BA44, 0xC07), p);
                    ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(ubuf, name, 100);
                    ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(func_00271A00(&D_0051BA44, 0xC08), status, 100);
                    SetPresenceDetail__10CGtBuddiesFPcPcPc(&D_01E3D390, name, status, D_004D1B70[D_004E2918.field_0]);
                    SetPresence__22CGtBuddiesPS2DirtySockF16EGtBuddyPresenceb(&D_01E3D390, 1, false);
                }
            }
            break;
        case 0:
            break;
        case 1:
            ReportError(self);
            break;
        }
        break;
    case 2:
        if (func_0032B2C0(&D_01E898E8, 0, 1) == 0) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, false);
        }
        break;
    }
}
