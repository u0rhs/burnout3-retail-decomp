// CB3NetworkManager::ForEachNetworkOpponent(char*,int,bool,int,int,int,char*,bool,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a145: static 9-arg; w[4] array + p1=&w[1] frame, A264 object via array member in two sites and byte-offset in one so it isn't CSE'd; bool inline with early returns).

struct UnkStruct_F4C0_lob {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34();
    virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44();
    virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58(); virtual void vfunc_5C(void *); virtual void vfunc_60(); virtual void vfunc_64();
    virtual int vfunc_68();
};
struct UnkStruct_F4C0_net {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34();
    virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44();
    virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64();
    virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74();
    virtual void vfunc_78(); virtual void vfunc_7C(); virtual int vfunc_80(); virtual void vfunc_84();
    virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94();
    virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4();
    virtual void vfunc_A8(); virtual bool vfunc_AC(); virtual void vfunc_B0(); virtual void vfunc_B4();
    virtual void vfunc_B8(); virtual void vfunc_BC(); virtual void vfunc_C0(); virtual void vfunc_C4();
    virtual void vfunc_C8(); virtual void vfunc_CC(); virtual void vfunc_D0(); virtual void vfunc_D4();
    virtual int vfunc_D8();
};
struct UnkStruct_F4C0_pl {
    unsigned char pad_0[0x4B8];
    char field_4B8[0x10];
    char field_4C8[0x10];
    int field_4D8;
    int field_4DC;
    int field_4E0;
    int field_4E4;
    unsigned char field_4E8;
    unsigned char field_4E9;
    unsigned char field_4EA;
};
struct UnkStruct_F4C0_mgr {
    unsigned char pad_0[0x3297C];
    int field_3297C;
    unsigned char pad_32980[0x39];
    unsigned char field_329B9;
    unsigned char field_329BA;
};
struct UnkStruct_F4C0_hold { unsigned char pad_0[0xA264]; UnkStruct_F4C0_net field_A264[1]; };
struct UnkStruct_D_01E3CD44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E3353C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E32AE0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E32AE4 { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E3353C D_01E3353C;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_01E32AE4 D_01E32AE4;
extern char D_004BA018[];
extern "C" int sscanf(const char *, const char *, ...);
extern "C" char * strcpy(char *, const char *);
extern "C" void SetMyPlayerIndex__23CGtNetworkPlayerManagerFi(void *, int);
extern "C" void SetMyPlayerID__23CGtNetworkPlayerManagerFi(void *, int);
extern "C" void SetGameID__23CGtNetworkPlayerManagerFi(void *, int);
extern "C" void RegisterPlayer__23CGtNetworkPlayerManagerFPCciiPv(void *, const char *, int, int, void *);
extern "C" UnkStruct_F4C0_pl * GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);
extern "C" void func_0026C7A0(void *, const char *);
extern "C" void func_002351F0(void *);
extern "C" void func_002351E0(void *, int);
extern "C" int GetHostPlayerID__23CGtNetworkPlayerManagerFv(void *);
extern "C" int GetMyPlayerID__23CGtNetworkPlayerManagerCFv(void *);

static inline bool func_F4C0_inl(void * mgr)
{
    UnkStruct_F4C0_mgr * m = (UnkStruct_F4C0_mgr *)mgr;
    if (((UnkStruct_F4C0_net *)((UnkStruct_F4C0_hold *)mgr)->field_A264)->vfunc_D8() == 0 && m->field_329B9 == 0) return false;
    if (m->field_329BA) return ((UnkStruct_F4C0_net *)((char *)mgr + 0xA264))->vfunc_AC();
    int a = GetHostPlayerID__23CGtNetworkPlayerManagerFv(mgr);
    if (a == GetMyPlayerID__23CGtNetworkPlayerManagerCFv(mgr)) return true;
    return false;
}

// 0x0026F4C0 (static: 9 arguments, the 9th on the stack)
extern "C" int ForEachNetworkOpponent__17CB3NetworkManagerFPcibiiiPcbPv(char * a0, int a1, bool a2, int a3, int t0, int t1, char * t2, bool t3, void * mgr)
{
    char buf[16];
    int w[4];
    if (a2) {
        ((UnkStruct_F4C0_lob *)&D_01E3CD44)->vfunc_5C(buf);
        int * const p1 = &w[1];
        sscanf(buf, D_004BA018, &w[0], p1, &w[2], &w[3]);
        D_01E3353C.field_0 = (w[0] << 24) + (*p1 << 16) + (w[2] << 8) + w[3];
        *(int *)((char *)mgr + 0xAAB0) = 1;
        SetMyPlayerIndex__23CGtNetworkPlayerManagerFi(mgr, *(int *)((char *)mgr + 0x3297C));
        SetMyPlayerID__23CGtNetworkPlayerManagerFi(mgr, a1);
        SetGameID__23CGtNetworkPlayerManagerFi(&D_01E32AE0, ((UnkStruct_F4C0_lob *)&D_01E3CD44)->vfunc_68());
        D_01E32AE4.field_0 = 1;
        *(int *)((char *)mgr + 0xAAA4) = a1;
        strcpy((char *)mgr + 0xAA88, t2);
        *(int *)((char *)mgr + 0xAAA0) = (unsigned char)(t1 >> 24);
        strcpy((char *)mgr + 0xAA78, a0);
        *(int *)((char *)mgr + 0xAA98) = a3;
        *(int *)((char *)mgr + 0xAA9C) = t0;
        *((unsigned char *)mgr + 0xAAA8) = 0;
        *((unsigned char *)mgr + 0xAAA9) = (t1 & 1) == 1;
        *((unsigned char *)mgr + 0xAAAA) = (t1 & 2) == 2;
    } else {
        RegisterPlayer__23CGtNetworkPlayerManagerFPCciiPv(mgr, t2, 0xE4A, a1, 0);
        UnkStruct_F4C0_pl * pl = GetPlayerByID__23CGtNetworkPlayerManagerCFi(mgr, a1);
        pl->field_4E4 = a1;
        strcpy(pl->field_4C8, t2);
        pl->field_4E0 = (unsigned char)(t1 >> 24);
        strcpy(pl->field_4B8, a0);
        pl->field_4D8 = a3;
        pl->field_4DC = t0;
        pl->field_4E8 = 0;
        pl->field_4E9 = (t1 & 1) == 1;
        pl->field_4EA = (t1 & 2) == 2;
        func_0026C7A0((char *)mgr + 0xA9D4, a0);
    }
    UnkStruct_F4C0_mgr * m = (UnkStruct_F4C0_mgr *)mgr;
    m->field_3297C = m->field_3297C + 1;
    if (t3) {
        func_002351F0(mgr);
        int h;
        if (m->field_329B9) h = GetHostPlayerID__23CGtNetworkPlayerManagerFv(mgr);
        else h = ((UnkStruct_F4C0_net *)((UnkStruct_F4C0_hold *)mgr)->field_A264)->vfunc_80();
        func_002351E0(mgr, h);
        if (func_F4C0_inl(mgr)) *((unsigned char *)mgr + 0xAAB6) = 1;
    }
    return 1;
}
