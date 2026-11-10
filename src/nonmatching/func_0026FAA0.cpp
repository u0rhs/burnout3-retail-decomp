// NONMATCHING: func_0026FAA0 -- retail 887 / ours 879 instructions, 507 in changed runs
// draft4: same calls; retail lays the announced-list memcpy block and the no-host resend loop out of line at the end; frame 0x130 vs 0x110; inlines on the global manager need pointer-cast virtual calls (else devirtualised)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm and Ghidra draft, every branch, store and call accounted for; same call multiset, two groups placed differently (calls.sh)

// func_0026FAA0 -- draft4 (breadth-first draft). [L] CB3NetworkManager's host migration step (this = the network
// manager, D_01E32AE0; it lies in B3NetworkManager.cpp's range, research/retail_names.csv 0x26CAB0-0x270ED0; name
// unknown). Types and field names are placeholders [G]. a1 = a bool argument (kept on the stack, sb 0xBF).

// [C] embedded at +0xA264 (D_01E3CD44 = D_01E32AE0 + 0xA264): a polymorphic object; slots 0x80 (host id), 0xAC, 0xD8.
struct UnkStruct_0026FAA0_A264 {
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
    virtual int vfunc_80();
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
    virtual bool vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual int vfunc_D8();
};
struct UnkStruct_0026FAA0_obs {
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
    virtual void vfunc_88(int oldHost, int newHost);
};
struct UnkStruct_D_0051BA88 {
    unsigned char pad_0[0x1B4];
    UnkStruct_0026FAA0_obs *field_1B4;  // [C] told about a host change (slot 0x88: old host, new host)
};
struct UnkStruct_0026FAA0_list { int a[8]; };

struct UnkStruct_0026FAA0 {
    unsigned char pad_0[0x28];
    int field_28;                          // [C] player slot count (func_002366D0 index bound)
    unsigned char pad_2C[0xA264 - 0x2C];
    UnkStruct_0026FAA0_A264 field_A264;
    unsigned char pad_A268[0x32980 - 0xA268];
    int field_32980[8];                    // [C] player ids in join order (-1 = empty) [L]
    unsigned char pad_329A0[4];
    unsigned short field_329A4;            // [C] last resend time (D_004E2A14 clock)
    unsigned short field_329A6;            // [C] host timeout deadline
    unsigned char field_329A8;             // [C] restart the timeout
    unsigned char pad_329A9[0x10];
    unsigned char field_329B9;             // [C] = D_01E65499: use GetHostPlayerID() rather than field_A264's slot 0x80
    unsigned char field_329BA;             // [C] = D_01E6549A
};
struct UnkStruct_D_8 { unsigned char value; unsigned char pad[0x100]; };
struct UnkStruct_D_snd { unsigned char pad_0[0x10]; };

extern UnkStruct_0026FAA0 D_01E32AE0;          // [C] the network manager instance
extern UnkStruct_0026FAA0_A264 D_01E3CD44;     // [C] = D_01E32AE0.field_A264 (addressed directly by the inlines)
extern UnkStruct_D_8 D_01E65499;               // [C] = D_01E32AE0.field_329B9
extern UnkStruct_D_8 D_01E6549A;               // [C] = D_01E32AE0.field_329BA
extern UnkStruct_D_snd D_01E653D0;             // [C] D_01E32AE0 + 0x328F0
extern UnkStruct_D_snd D_01E65450;             // [C] D_01E32AE0 + 0x32970
extern signed char D_004E2910;                 // [C] gp-relative byte: selects the shorter timeouts
extern unsigned short D_004E2A14;              // [C] gp-relative clock (0xFFFF reads as 0)

extern "C" void *memcpy(void *, const void *, unsigned int);
extern "C" int GetHostPlayerID__23CGtNetworkPlayerManagerFv(UnkStruct_0026FAA0 *);
extern "C" int GetMyPlayerID__23CGtNetworkPlayerManagerCFv(UnkStruct_0026FAA0 *);
extern "C" void *GetPlayerByID__23CGtNetworkPlayerManagerCFi(UnkStruct_0026FAA0 *, int);
extern "C" void *func_002366D0(UnkStruct_0026FAA0 *mgr, int index);  // [L] player slot -> player (or 0)
extern "C" int func_0022FBB0(void *player);                          // [L] the player's id
extern "C" int func_002F9930(void *msg, int *id);                    // [G] a host-claim message's Retrieve
extern "C" void func_002F9970(void *msg);                            // [G] its resend
extern "C" int Retrieve__24CB3NetworkNewHostMessageFPiPi(void *msg, int *id, int *list);
extern "C" void Prepare__24CB3NetworkNewHostMessageFiPi(void *msg, int id, int *list);
extern "C" void func_002351E0(UnkStruct_0026FAA0 *mgr, int host);    // [G] sets the new host
extern "C" void func_00240960(UnkStruct_D_snd *);
extern "C" void func_002409B0(UnkStruct_D_snd *);
extern "C" void func_00240B70(UnkStruct_D_snd *);
extern "C" void func_00240C00(UnkStruct_D_snd *);

// [C] a pointer global (lw %lo(D_0051BA88)), padded so it stays lui/%lo (N50).
struct UnkStruct_D_0051BA88_ptr { UnkStruct_D_0051BA88 *p; unsigned char pad[0x100]; };
extern UnkStruct_D_0051BA88_ptr D_0051BA88;

// [L] inlines (repeated verbatim in retail at each use; names unknown):
// the clock, 0xFFFF read as 0
static inline unsigned short func_0026FAA0_inl1() { unsigned short t = D_004E2A14; if (t == 0xFFFF) t = 0; return t; }
// false when a comes first in field_32980, true when b does or neither is there
static inline bool func_0026FAA0_inl2(UnkStruct_0026FAA0 *self, int a, int b)
{
    for (int i = 0; i < 8; i++) {
        int v = self->field_32980[i];
        if (v == a)
            return false;
        if (v == b)
            return true;
    }
    return true;
}
// wrap-aware "t is before ref" on the 16-bit clock
static inline bool func_0026FAA0_inl3(unsigned short t, unsigned short ref)
{
    if (ref < 0x5555 && t > 0xAAAA)
        return true;
    if (t < 0x5555 && ref > 0xAAAA)
        return false;
    if (t < ref)
        return true;
    return false;
}
// wrap-aware t - ref
static inline unsigned short func_0026FAA0_inl4(unsigned short t, unsigned short ref)
{
    if (t < 0x5555 && ref > 0xAAAA)
        return t + (unsigned short)(-1 - ref);
    return t + (unsigned short)-ref;
}
// whether this machine is the host (on the global manager)
static inline bool func_0026FAA0_inl5()
{
    if (!((UnkStruct_0026FAA0_A264 *)&D_01E3CD44)->vfunc_D8() && !D_01E65499.value)
        return false;
    if (D_01E6549A.value)
        return ((UnkStruct_0026FAA0_A264 *)&D_01E3CD44)->vfunc_AC();
    if (GetHostPlayerID__23CGtNetworkPlayerManagerFv(&D_01E32AE0) == GetMyPlayerID__23CGtNetworkPlayerManagerCFv(&D_01E32AE0))
        return true;
    return false;
}
// the host's id (on the global manager)
static inline int func_0026FAA0_inl6()
{
    if (D_01E65499.value)
        return GetHostPlayerID__23CGtNetworkPlayerManagerFv(&D_01E32AE0);
    return ((UnkStruct_0026FAA0_A264 *)&D_01E3CD44)->vfunc_80();
}
// the host's id (on this)
static inline int func_0026FAA0_inl7(UnkStruct_0026FAA0 *self)
{
    if (self->field_329B9)
        return GetHostPlayerID__23CGtNetworkPlayerManagerFv(self);
    return ((UnkStruct_0026FAA0_A264 *)&self->field_A264)->vfunc_80();
}
// switch host: sounds/state before and after, observer told
static inline void func_0026FAA0_inl8(UnkStruct_0026FAA0 *self, int h)
{
    if (func_0026FAA0_inl5())
        func_00240B70(&D_01E65450);
    else
        func_00240960(&D_01E653D0);
    int old = func_0026FAA0_inl6();
    func_002351E0(self, h);
    if (D_0051BA88.p != 0) {
        UnkStruct_0026FAA0_obs *o = D_0051BA88.p->field_1B4;
        if (o != 0)
            o->vfunc_88(old, h);
    }
    if (func_0026FAA0_inl5())
        func_00240C00(&D_01E65450);
    else
        func_002409B0(&D_01E653D0);
}

// 0x0026FAA0
extern "C" void func_0026FAA0(UnkStruct_0026FAA0 *self, bool b)
{
    bool handled = false;
    if (self->field_329A8) {
        short t = 500;
        self->field_329A8 = 0;
        if (D_004E2910 == 0)
            t = 600;
        self->field_329A6 = t + func_0026FAA0_inl1();
        if (self->field_329A6 == 0xFFFF)
            self->field_329A6 = 0;
    }
    void *hostPlayer = GetPlayerByID__23CGtNetworkPlayerManagerCFi(self, func_0026FAA0_inl7(self));
    int hostId;
    if (hostPlayer != 0)
        hostId = func_0022FBB0(hostPlayer);
    else
        hostId = GetMyPlayerID__23CGtNetworkPlayerManagerCFv(self);

    int claim = -1;
    int announced = -1;
    UnkStruct_0026FAA0_list got;
    UnkStruct_0026FAA0_list ann;
    for (int i = 0; i < self->field_28; i++) {
        void *p = func_002366D0(self, i);
        if (p == 0)
            continue;
        int id;
        if (func_002F9930((char *)p + 0xCD0, &id)) {
            self->field_329A6 = func_0026FAA0_inl1();
            if (func_0026FAA0_inl2(self, id, hostId)) {
                if (claim == -1 || func_0026FAA0_inl2(self, id, claim))
                    claim = id;
            }
        }
        if (Retrieve__24CB3NetworkNewHostMessageFPiPi((char *)p + 0xD18, &id, got.a) && id != hostId) {
            if (announced == -1 || func_0026FAA0_inl2(self, id, announced)) {
                memcpy(ann.a, got.a, sizeof(got.a));
                for (int j = 0; j < 8; j++) {
                    if (ann.a[j] == -1) {
                        ann.a[j] = func_0022FBB0(p);
                        break;
                    }
                }
                announced = id;
            }
        }
    }
    if (announced != -1) {
        for (int i = 0; i < self->field_28; i++) {
            void *p = func_002366D0(self, i);
            if (p != 0) {
                int j;
                for (j = 0; j < 8; j++) {
                    if (got.a[j] == func_0022FBB0(p))
                        break;
                }
                if (j == 8 && (*((unsigned char *)p + 0xCE4) & 1) != 1)
                    Prepare__24CB3NetworkNewHostMessageFiPi((char *)p + 0xCE4, announced, ann.a);
            }
        }
    }
    if (claim != -1 || announced != -1) {
        int h = announced;
        if (claim != -1) {
            h = claim;
            if (announced != -1) {
                h = announced;
                if (func_0026FAA0_inl2(self, claim, announced))
                    h = claim;
            }
        }
        if (func_0026FAA0_inl2(self, h, hostId)) {
            handled = true;
            self->field_329A6 = func_0026FAA0_inl1();
            func_0026FAA0_inl8(self, h);
        }
    }

    if (hostPlayer == 0) {
        unsigned short now = func_0026FAA0_inl1();
        unsigned short ref = self->field_329A4;
        if (!func_0026FAA0_inl3(now, ref)) {
            unsigned short lim = 10;
            if (D_004E2910 == 0)
                lim = 12;
            if (lim < func_0026FAA0_inl4(now, ref)) {
                self->field_329A4 = now;
                int n = D_01E32AE0.field_28;
                for (int i = 0; i < n; i++) {
                    void *p = func_002366D0(&D_01E32AE0, i);
                    if (p != 0)
                        func_002F9970((char *)p + 0xCBC);
                }
            }
        }
    } else if (!handled) {
        unsigned short now = func_0026FAA0_inl1();
        unsigned short ref = self->field_329A6;
        bool wait;
        if (func_0026FAA0_inl3(now, ref)) {
            wait = true;
        } else {
            unsigned short lim;
            if (!b) {
                lim = 60;
                if (D_004E2910 == 0)
                    lim = 72;
            } else {
                lim = 60;
                if (D_004E2910 == 0)
                    lim = 72;
            }
            if (lim < func_0026FAA0_inl4(now, ref))
                wait = false;
            else
                wait = true;
        }
        if (!wait) {
            int next = GetMyPlayerID__23CGtNetworkPlayerManagerCFv(self);
            int host = func_0026FAA0_inl7(self);
            int i = 0;
            bool go = true;
            while (go && self->field_32980[i] != host) {
                i++;
                go = i < 8;
            }
            bool last;
            if (i == 7)
                last = true;
            else if (self->field_32980[i + 1] == -1)
                last = true;
            else
                last = false;
            if (!last) {
                int j = 0;
                while (j < 8 && self->field_32980[j] != hostId)
                    j++;
                do {
                    j++;
                    if (j > 7 || self->field_32980[j] == next)
                        break;
                } while (GetPlayerByID__23CGtNetworkPlayerManagerCFi(self, self->field_32980[j]) == 0);
                next = self->field_32980[j];
            }
            UnkStruct_0026FAA0_list none;
            for (int k = 0; k < 8; k++)
                none.a[k] = -1;
            for (int k = 0; k < self->field_28; k++) {
                void *p = func_002366D0(&D_01E32AE0, k);
                if (p != 0 && (*((unsigned char *)p + 0xCE4) & 1) != 1)
                    Prepare__24CB3NetworkNewHostMessageFiPi((char *)p + 0xCE4, next, none.a);
            }
            self->field_329A6 = func_0026FAA0_inl1();
            func_0026FAA0_inl8(self, next);
        }
    }
}
