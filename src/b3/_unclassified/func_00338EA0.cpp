// Hand-written; the lifter refused it (a126: ForAllPlayers-like: two inlined player loops (field_134 re-read), shared params slot by ref, e assigned late).

class CGtLobbyPS2DirtySock;
struct UnkStruct_Pl_Row {
    int field_0;
    char field_4[0x10];
    int field_14;
    unsigned char pad_18[0x28];
    char field_40[0x24];
};
struct UnkStruct_Pl_Game {
    int field_0;
    unsigned char pad_4[0x1BC];
    UnkStruct_Pl_Row field_1C0[8];
};
struct UnkStruct_Pl_Cached { int a; int b; int c; };
typedef int (*PlayerCB)(char *, int, int, int, int, int, char *, bool, void *);
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
    unsigned char pad_4[0x118];
    unsigned char field_11C;
    unsigned char pad_11D[0x16];
    UnkStruct_Pl_Game *field_134;
    unsigned char pad_138[0x36C];
    char field_4A4[0x20];
    unsigned char pad_4C4[0xA0];
    int field_564;
    int field_568;
};
extern "C" int DispListCount(int);
extern "C" void DispListOrder(int);
extern "C" UnkStruct_Pl_Game *DispListIndex(int, int);
extern "C" void *memset(void *, int, unsigned);
extern "C" int strcasecmp(const char *, const char *);
extern "C" void LoadFromString__35CGtLobbyDirtySockCachedPlayerParamsFPc(void *, char *);
extern "C" char *SocketInAddrGetText(int);

// 0x00338EA0
static inline void func_00338EA0_inl0(CGtLobbyPS2DirtySock *self, PlayerCB cb, void *user, UnkStruct_Pl_Cached &params)
{
    for (int k = 0; k < 8; k++) {
        UnkStruct_Pl_Game *g = self->field_134;
        bool last;
        UnkStruct_Pl_Row *e;
        if (g->field_1C0[k].field_0 != 0) {
            e = &g->field_1C0[k];
            if (k == 7)
                last = true;
            else if (g->field_1C0[k + 1].field_0 == 0)
                last = true;
            else
                last = false;
            memset(&params, 0, 0xC);
            LoadFromString__35CGtLobbyDirtySockCachedPlayerParamsFPc(&params, e->field_40);
            int isSelf = (strcasecmp(self->field_4A4, e->field_4) != 0) ^ 1;
            cb(e->field_4, e->field_0, isSelf, params.a, params.b, params.c, SocketInAddrGetText(e->field_14), last, user);
        }
    }
}


static inline void func_00338EA0_inl1(CGtLobbyPS2DirtySock *self, UnkStruct_Pl_Game *g, PlayerCB cb, void *user, UnkStruct_Pl_Cached &params)
{
    for (int k = 0; k < 8; k++) {
        bool last;
        UnkStruct_Pl_Row *e;
        if (g->field_1C0[k].field_0 != 0) {
            e = &g->field_1C0[k];
            if (k == 7)
                last = true;
            else if (g->field_1C0[k + 1].field_0 == 0)
                last = true;
            else
                last = false;
            memset(&params, 0, 0xC);
            LoadFromString__35CGtLobbyDirtySockCachedPlayerParamsFPc(&params, e->field_40);
            int isSelf = (strcasecmp(self->field_4A4, e->field_4) != 0) ^ 1;
            cb(e->field_4, e->field_0, isSelf, params.a, params.b, params.c, SocketInAddrGetText(e->field_14), last, user);
        }
    }
}


extern "C" void func_00338EA0(CGtLobbyPS2DirtySock *self, int a1, int gameId, int a3, int t0, PlayerCB cb, void *user)
{
    UnkStruct_Pl_Game *g;
    UnkStruct_Pl_Cached params;
    int i;
    if (self->field_11C != 0) {
        if (self->field_134 == 0) {
            self->vfunc_14();
            return;
        }
        func_00338EA0_inl0(self, cb, user, params);
    } else {
        g = 0;
        DispListOrder(self->field_564);
        for (i = 0; i < DispListCount(self->field_564); i++) {
            g = DispListIndex(self->field_564, i);
            if (g != 0 && g->field_0 == gameId)
                break;
            g = 0;
        }
        if (g == 0) {
            for (i = 0; i < DispListCount(self->field_568); i++) {
                g = DispListIndex(self->field_568, i);
                if (g != 0 && g->field_0 == gameId)
                    break;
                g = 0;
            }
            if (g == 0) {
                self->vfunc_14();
                return;
            }
        }
        func_00338EA0_inl1(self, g, cb, user, params);
    }
    self->vfunc_14();
}
