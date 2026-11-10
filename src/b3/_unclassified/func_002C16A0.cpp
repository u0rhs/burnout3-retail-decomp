// Hand-written; the lifter refused it (y > 0xAAAA compares (slt at form) + differs inline as early returns with one && test (shared false block)).

// func_002C16A0 -- CGtNetworkHeadset per-frame update (a146 note: vptr-at-0x14 net object); placeholder name, C linkage.
// near12: ring-sequence tests as `y > 0xAAAA` (retail's li at/slt at form; `!(y < 0xAAAB)` gives slt v0); the
// "differs" inline as early returns with one `v > -1 && v != me` test (retail shares one out-of-line false block).

struct UnkStruct_16A0_net {
    unsigned char pad_0[0x14];
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10(int, int);
    virtual int vfunc_14();
    virtual void vfunc_18(float);
    virtual void vfunc_1C(int, int);
    virtual void vfunc_20();
    virtual int vfunc_24();
    virtual bool vfunc_28();
};
struct UnkStruct_16A0_pm { unsigned char pad_0[0x28]; int field_28; };
struct UnkStruct_16A0 {
    unsigned char pad_0[4];
    UnkStruct_16A0_net *field_4;
    int field_8;
    unsigned char field_C[4][0x200];
    int field_80C[4];
    int field_81C;
    int field_820;
    int field_824;
    unsigned char field_828;
    unsigned char field_829;
    unsigned char field_82A[60][0x200];
    unsigned char pad_802A[2];
    int field_802C[60];
    int field_811C;
    int field_8120;
    unsigned char pad_8124[4];
    unsigned char field_8128[60];
    int field_8164;
    short field_8168;
    unsigned char field_816A;
    unsigned char pad_816B;
    int field_816C;
    unsigned char pad_8170[8];
    int field_8178;
    unsigned char pad_817C[4];
    float field_8180;
    int field_8184;
    int field_8188;
    unsigned char pad_818C[0x48];
    int field_81D4;
    UnkStruct_16A0_pm *field_81D8;
};
extern "C" {
int GetMyPlayerID__23CGtNetworkPlayerManagerCFv(void *);
void *func_002366D0(void *, int);
int func_0022FBB0(void *);
unsigned char *GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);
unsigned char *func_0022F8C0(void *, int);
void func_002C0500(void *, unsigned short, int, void *, void **);
void func_002C09A0(void *, unsigned short);
void func_002C0DF0(void *, unsigned short, float);
void func_002C20C0(void *, void *);
void func_002C20D0(void *, void *);
void SetStatusToSend__17CGtNetworkHeadsetF25EHeadsetTalkControlStatusi(void *, int, int);
}
static inline bool func_002C16A0_inl1(int x, int y)
{
    if (x == y) return true;
    bool r;
    if (x < 0x5555 && y > 0xAAAA) r = true;
    else if (y < 0x5555 && x > 0xAAAA) r = false;
    else if (x > y) r = true;
    else r = false;
    return r;
}
static inline bool func_002C16A0_inl2(UnkStruct_16A0 *self, int me)
{
    if (me < 0) return false;
    int v = self->field_81D4;
    if (v > -1 && v != me) return true;
    return false;
}

// 0x002C16A0
extern "C" void func_002C16A0(UnkStruct_16A0 *self, int p1, float f)
{
    self->field_4->vfunc_18(f);
    int s0 = (unsigned short)p1;
    if (s0 == 0xFFFF) s0 = 0;
    if (self->field_4->vfunc_28()) {
        if (self->field_8 == 2) goto doit;
        if (self->field_8 != 1) goto skip;
    doit:
        self->field_81D4 = -1;
        self->field_8178 = 0;
        self->field_8 = 0;
        self->field_8184 = 0;
        self->field_8180 = 1.0f;
        SetStatusToSend__17CGtNetworkHeadsetF25EHeadsetTalkControlStatusi(self, 4, -1);
    skip:
        self->field_4->vfunc_10(self->field_816C, -1);
    }
    if (self->field_816A != 0) {
        self->field_816A = 0;
        self->field_8168 = s0;
    }
    if (self->field_4->vfunc_24() == 2 && self->field_8 == 2) {
        func_002C20D0(self->field_4, self->field_C[self->field_81C]);
        self->field_80C[self->field_81C] = self->field_4->vfunc_14();
        self->field_81C = (self->field_81C + 1) % 4;
        if (self->field_820 < 4) self->field_820++;
        if (self->field_820 == 4) func_002C09A0(self, p1);
    }
    int me = GetMyPlayerID__23CGtNetworkPlayerManagerCFv(self->field_81D8);
    if (func_002C16A0_inl2(self, me)) {
        for (s0 = 0; s0 < self->field_81D8->field_28; s0++) {
            void *pl = func_002366D0(self->field_81D8, s0);
            if (pl != 0) {
                int s1 = func_0022FBB0(pl);
                unsigned char *v = func_0022F8C0(GetPlayerByID__23CGtNetworkPlayerManagerCFi(self->field_81D8, s1), 2);
                void *loc[4];
                for (int k = 0; k < 4; k++) loc[k] = v + k * 66 + 0x20;
                func_002C0500(self, p1, s1, v, loc);
            }
        }
        if (!(self->field_8120 < 0x1A) || self->field_824 != 0xFFFF) self->field_829 = 1;
        if (self->field_829 != 0) {
            func_002C20C0(self->field_4, self->field_82A[self->field_811C]);
            if (self->field_8128[self->field_811C] != 0) {
                if (self->field_4->vfunc_24() == 2) self->field_4->vfunc_1C(self->field_802C[self->field_811C], 0);
                self->field_8128[self->field_811C] = 0;
                self->field_8120 = self->field_8120 - 1;
                if (self->field_8120 == 0) self->field_829 = 0;
            }
            self->field_811C = (self->field_811C + 1) % 60;
            self->field_8164 = self->field_8164 + 1;
        }
        if (self->field_824 != 0xFFFF) {
            if (func_002C16A0_inl1(*(unsigned short *)&self->field_8164, self->field_824 & 0xFFFF)) {
                self->field_81D4 = -1;
                self->field_8188 = -1;
                self->field_8164 = -1;
                self->field_8120 = 0;
                self->field_8 = 0;
                self->field_8184 = 0;
            }
        }
    }
    func_002C0DF0(self, p1, f);
    self->field_4->vfunc_20();
}
