// CGtNATDataManager::SetUpAPortMapping(int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNATDataManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (s313: a160 archive + find_tag inline zeroes both outputs (s=0; e=0;)).

// CGtNATDataManager::SetUpAPortMapping(int, int) -- hand-matched by s313 from the a160 archive (sibling RemoveAPortMapping, simfind 0.70):
// the find_tag inline zeroes both outputs (s = 0; e = 0;), which retail keeps for the second call and fixes the
// case-2 saved-register allocation. [C] name: mangled symbol; struct/field names placeholders, types [G].


struct UnkStruct_00231B30_sock {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual int vfunc_28(int, int); virtual int vfunc_2C(); virtual int vfunc_30(void *, int); virtual int vfunc_34(void *, int);
};
struct UnkStruct_00231B30_ent { unsigned char pad_0[0x5A0]; };
struct UnkStruct_00231B30 {
    unsigned char pad_0[0x524];
    UnkStruct_00231B30_sock * field_524;
    unsigned char pad_528[4];
    char field_52C[0x10];
    int field_53C;
    int field_540;
    char field_544[0x18];
    char field_55C[0x34];
    int field_590;
    unsigned char pad_594[0x510];
    int field_AA4;
    unsigned char pad_AA8[8];
    int field_AB0;
    unsigned char pad_AB4[0x8];
    int field_ABC;
    unsigned char field_AC0;
    unsigned char field_AC1;
    unsigned char pad_AC2[2];
    int field_AC4;
};
extern "C" int atoi(const char *);
extern "C" char * func_00234FF0(char *, char *, const char *);
extern "C" void * memset(void *, int, unsigned int);
extern "C" int sprintf(char *, const char *, ...);
extern "C" unsigned int strlen(const char *);
extern "C" char * strncat(char *, const char *, int);
extern "C" char * strncpy(char *, const char *, int);
extern char D_004BA9B8[];
extern char D_004BAF58[];
extern char D_004BAF68[];
extern char D_004BAF70[];
extern char D_004BAF78[];
extern char D_004BAF80[];
extern char D_004BAF88[];
extern char D_004BAFA0[];
extern char D_004BAFE8[];
extern char D_004BA1C0[];
extern char D_004BAFF8[];
extern char D_004BB010[];
extern char D_004BB1B0[];
extern char D_004BB1B8[];
extern char D_004BB1C0[];
extern char D_004BB1C8[];
extern char D_004BAFD0[];
extern char D_01D7D700[];
extern char D_01D7F700[];
extern char D_01D7FF00[];

static inline char * find_digit(char * end, char * pat)
{
    char * p = func_00234FF0(D_01D7D700, end, pat);
    if (p != 0) {
        p = p + strlen(pat);
        for (;;) {
            char c = *p;
            if (c < 0x30 || c >= 0x3A) {
                if (p < end) { p++; continue; }
            }
            break;
        }
        if (p >= end) goto nul;
        return p;
    }
nul:
    return 0;
}

extern char kacPortMapPacketBody1[];
extern char kacPortMapPacketBody3[];
extern char kacPortMapPacketBody4[];
extern char kacPortMapPacketBody5[];
extern char kacPortMapPacketBody6[];
extern char kacPortMapPacketHeader2[];
extern char kacPortMapPacketHeader3[];
extern "C" int snprintf(char *, unsigned int, const char *, ...);

static inline bool find_tag(char * end, const char * nm, char *& s, char *& e)
{
    char buf[0x40];
    s = 0;
    e = 0;
    snprintf(buf, 0x40, D_004BB1C8, nm);
    char * t = func_00234FF0(D_01D7D700, end, buf);
    if (t != 0) {
        char * u = func_00234FF0(t, end, D_004BB1C0);
        s = u + strlen(D_004BB1B8);
        snprintf(buf, 0x40, D_004BB1B0, nm);
        e = func_00234FF0(s, end, buf);
        return true;
    }
    return false;
}

extern "C" int SetUpAPortMapping__17CGtNATDataManagerFii(UnkStruct_00231B30 * self, int port, int arg1)
{
    char buf120[0x40];
    char bufE0[0x40];
    int st = self->field_ABC;
    switch (st) {
    case 0: {
        int r = self->field_524->vfunc_28(self->field_53C, self->field_540);
        if (r == 1) return self->field_ABC;
        if (r == 4) { self->field_ABC = 4; return self->field_ABC; }
        memset(D_01D7F700, 0, 0x800);
        memset(D_01D7FF00, 0, 0x800);
        unsigned int n = 0x800;
        strncat(D_01D7FF00, kacPortMapPacketBody1 + 0x50, n);
        n = n - strlen(kacPortMapPacketBody1 + 0x50);
        strncat(D_01D7FF00, (char *)self + (self->field_AA4 << 7) + 0x8A4, n);
        n = n - strlen((char *)self + (self->field_AA4 << 7) + 0x8A4);
        strncat(D_01D7FF00, kacPortMapPacketBody3, n);
        n = n - strlen(kacPortMapPacketBody3);
        if (self->field_AC0 == 0) {
            sprintf(buf120, D_004BAF70, self->field_544);
        strncat(D_01D7FF00, buf120, n);
        n = n - strlen(buf120);
        }
        strncat(D_01D7FF00, kacPortMapPacketBody3 + 0x50, n);
        n = n - strlen(kacPortMapPacketBody3 + 0x50);
        if (self->field_AC1 != 0) sprintf(buf120, D_004BAF78);
        else sprintf(buf120, D_004BAF80, port);
        strncat(D_01D7FF00, buf120, n);
        n = n - strlen(buf120);
        strncat(D_01D7FF00, kacPortMapPacketBody4 + 0x50, n);
        n = n - strlen(kacPortMapPacketBody4 + 0x50);
        sprintf(buf120, D_004BAF80, arg1);
        strncat(D_01D7FF00, buf120, n);
        n = n - strlen(buf120);
        strncat(D_01D7FF00, kacPortMapPacketBody5 + 0x50, n);
        n = n - strlen(kacPortMapPacketBody5 + 0x50);
        sprintf(buf120, D_004BAF70, self->field_55C);
        strncat(D_01D7FF00, buf120, n);
        n = n - strlen(buf120);
        strncat(D_01D7FF00, kacPortMapPacketBody6 + 0x50, n);
        n = n - strlen(kacPortMapPacketBody6 + 0x50);
        n = 0x800;
        strncat(D_01D7F700, kacPortMapPacketHeader2 + 0x40, n);
        n = n - strlen(kacPortMapPacketHeader2 + 0x40);
        strncat(D_01D7F700, (char *)self + (self->field_AA4 << 7) + 0x6A4, n);
        n = n - strlen((char *)self + (self->field_AA4 << 7) + 0x6A4);
        strncat(D_01D7F700, kacPortMapPacketHeader3, n);
        n = n - strlen(kacPortMapPacketHeader3);
        strncat(D_01D7F700, (char *)self + (self->field_AA4 << 7) + 0x8A4, n);
        n = n - strlen((char *)self + (self->field_AA4 << 7) + 0x8A4);
        strncat(D_01D7F700, D_004BA1C0, n);
        n = n - strlen(D_004BA1C0);
        sprintf(buf120, D_004BAF88, self->field_52C);
        strncat(D_01D7F700, buf120, n);
        n = n - strlen(buf120);
        sprintf(buf120, D_004BAFA0, strlen(D_01D7FF00));
        strncat(D_01D7F700, buf120, n);
        n = n - strlen(buf120);
        strncat(D_01D7F700, kacPortMapPacketBody1 + 0x10, n);
        n = n - strlen(kacPortMapPacketBody1 + 0x10);
        strncat(D_01D7F700, D_01D7FF00, n);
        n = n - strlen(D_01D7FF00);
        self->field_524->vfunc_30(D_01D7F700, 0x800 - n);
        self->field_AB0 = 0;
        memset(D_01D7D700, 0, 0x2000);
        self->field_ABC = 1;
        break;
    }
    case 1: {
        int r = self->field_524->vfunc_34(D_01D7D700 + self->field_AB0, 0x2000 - self->field_AB0);
        if (r > 0) {
            self->field_AB0 += r;
            char * end = D_01D7D700 + self->field_AB0;
            char * p = find_digit(end, D_004BAFE8);
            if (p != 0) {
                int len = atoi(p);
                char * q = func_00234FF0(D_01D7D700, D_01D7D700 + self->field_AB0, D_004BAF68);
                if (q != 0 && !((int)strlen(q) < len)) self->field_ABC = 2;
            }
        }
        break;
    }
    case 2: {
        if (self->field_524->vfunc_2C() == 2) return self->field_ABC;
        char * end = D_01D7D700 + self->field_AB0;
        char * s2; char * e2; char * s4; char * e4;
        if (!find_tag(end, D_004BAFF8, s2, e2)) { self->field_ABC = 3; break; }
        int v = atoi(s2);
        if (find_tag(end, D_004BB010, s4, e4)) {
            int l = e4 - s4;
            strncpy(bufE0, s4, l < 0x40 ? l : 0x40);
            if (v == 0x2D6) {
                self->field_AC0 = 1;
                self->field_590 = 0x2756;
                self->field_ABC = 0;
                return self->field_ABC;
            }
        }
        self->field_ABC = 4;
        return self->field_ABC;
    }
    default:
        break;
    }
    return self->field_ABC;
}
