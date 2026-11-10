// NONMATCHING: func_0026E460 -- retail 229 / ours 229 instructions, 20 in changed runs
// 229/229 instrs, 21 in changed runs, only s-register permutation: retail pLt(&Lt)=s1, r=found=s2, c=s4; ours pLt=s4, r=s1, c=s1. Logic exact; &Lt kept in a reg via float& local
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_26E460_fsm {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_26E460_state { unsigned char pad_0[8]; float field_8; };
struct UnkStruct_26E460_cur { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_D_01EA2974 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2980 { UnkStruct_26E460_cur * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2984 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2F0E { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01EA2F0D { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E90430 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E32B08 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051A6A8 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E32AE0 { unsigned char pad_0[0x10]; };
struct UnkStruct_26E460_pl { unsigned char pad_0[0xBBC]; unsigned char field_BBC; };
struct UnkStruct_26E460_msg { unsigned char pad_0[4]; int field_4; };
struct UnkStruct_26E460 {
    unsigned char pad_0[0x32978];
    float field_32978;
    unsigned char pad_3297C[4];
    int field_32980[8];
    unsigned char pad_329A0[0x24];
    float field_329C4;
    int field_329C8;
    unsigned char field_329CC;
};
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_26E460_fsm D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01EA2F0E D_01EA2F0E;
extern UnkStruct_D_01EA2F0D D_01EA2F0D;
extern UnkStruct_D_01E90430 D_01E90430;
extern UnkStruct_D_01E32B08 D_01E32B08;
extern UnkStruct_D_0051A6A8 D_0051A6A8;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern "C" void Retrieve__37CB3NetworkPlayerStartCountdownMessageFPiPfPi(void *, int *, float *, int *);
extern "C" void ReleaseCurrentMenu__18CB3MenuPageManagerFv(void *);
extern "C" void func_00130C20(void *, unsigned long);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_00131F10(void *, void *);
extern "C" UnkStruct_26E460_pl * func_002366D0(void *, int);
extern "C" int func_0022FBB0(void *);
extern "C" int func_001A85C0(void *, int, float, int *);

struct UnkStruct_26E460_blk { int a[8]; int pad[2]; };

static inline bool func_0026E460_inl1(UnkStruct_26E460 * s, float & v)
{
    if (s->field_329CC != 0) {
        v = s->field_329C4;
        return true;
    }
    v = -1.0f;
    return false;
}

// 0x0026E460
extern "C" void func_0026E460(UnkStruct_26E460_msg * msg, int p1, UnkStruct_26E460 * self)
{
    float Lt;
    int Lid;
    UnkStruct_26E460_blk Larr;
    if (self->field_329CC != 0) {
        float lt;
        bool has;
        if (self->field_329CC != 0) {
            lt = self->field_329C4;
            has = true;
        } else {
            lt = -1.0f;
            has = false;
        }
        if (has) {
            if (!(self->field_32978 < lt)) return;
        }
    }
    int s0 = msg->field_4;
    float & rLt = Lt;
    Retrieve__37CB3NetworkPlayerStartCountdownMessageFPiPfPi(msg, &Lid, (&rLt), Larr.a);
    if (self->field_329CC != 0) {
        bool ok;
        int a;
        int lid = Lid;
        int cid = self->field_329C8;
        for (a = 0; a < 8; a++) {
            int e = self->field_32980[a];
            if (e == lid) { ok = false; goto fin; }
            if (e == cid) { ok = true; goto fin; }
        }
        ok = true;
        fin:
        if (!ok) return;
    }
    if (self->field_32978 > *(&rLt)) {
        if (D_01E90430.field_0 != 0) ReleaseCurrentMenu__18CB3MenuPageManagerFv(&D_01E90240);
        D_01EA2F0E.field_0 = 0;
        D_01EA2F0D.field_0 = 0;
        func_00130C20(&D_0051A6A8, 0x94414018F8506BD2UL);
        void * r = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FA737AAA797UL);
        if (D_01EA2974.field_0 != r) {
            ((UnkStruct_26E460_fsm *)&D_01EA2970)->vfunc_18(r, 0);
            void * t0 = D_01EA2974.field_0;
            D_01EA2974.field_0 = r;
            UnkStruct_26E460_cur * t1 = D_01EA2980.field_0;
            if (t1 != 0) {
                D_01EA2984.field_0 = t1->field_20;
                if (r != 0) ((UnkStruct_26E460_state *)r)->field_8 = t1->field_20;
            }
            ((UnkStruct_26E460_fsm *)&D_01EA2970)->vfunc_1C(t0, 0);
        }
        func_00131F10(&D_004EE040, &D_0051A6A8);
        D_01EA2F0E.field_0 = 0;
    }
    int b;
    for (b = 0; b < 8; b++) {
        if (Larr.a[b] == -1) { Larr.a[b] = s0; break; }
    }
    for (s0 = 0; s0 < D_01E32B08.field_0; s0++) {
        UnkStruct_26E460_pl * pl = func_002366D0(&D_01E32AE0, s0);
        if (pl != 0) {
            int found = 0;
            int c;
            for (c = 0; c < 8; c++) {
                int ev = Larr.a[c];
                if (ev == func_0022FBB0(pl)) { found = 1; break; }
            }
            if (found == 0 && (pl->field_BBC & 1) != 1) {
                func_001A85C0(&pl->field_BBC, Lid, *(&rLt), Larr.a);
            }
        }
    }
    self->field_329C8 = Lid;
    self->field_329C4 = *(&rLt);
    self->field_329CC = 1;
}

