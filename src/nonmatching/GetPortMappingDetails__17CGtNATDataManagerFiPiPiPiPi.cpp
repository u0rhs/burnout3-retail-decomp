// NONMATCHING: GetPortMappingDetails__17CGtNATDataManagerFiPiPiPiPi -- retail 641 / ours 641 instructions, 6 in changed runs
// s314: 169 -> 6 from the proven sibling SetUpAPortMapping: find_tag also clears e (e = 0), the D_004BB050 tag gets its own s6/e6 locals, and the IP parse is a static inline parse_ip (int a[4] below the tag buffers). Left: &a[3]/&a[2] held in s7/s5, retail s5/s7 (sscanf args t1/t0); sreg 2 rounds, element-pointer locals, p+k, array types, return forms all keep the swap
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// a160: 643/641 instrs, 162 in changed runs; logic complete (same state-machine shape as RemoveAPortMapping, find_tag inline, int a[4] sscanf). Retail params saved s0=port,s3=p1,s2=p2,s1=p3,s6=p4,s4=self, s7/s5/s0 for tags; ours needs a 9th saved reg (frame 0x2C0 vs 0x2B0) and self=s5. Needs saved-register-pressure work


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
    char field_544[0x560];
    int field_AA4;
    unsigned char pad_AA8[8];
    int field_AB0;
    unsigned char pad_AB4[0x4];
    int field_AB8;
    unsigned char pad_ABC[0x4];
    unsigned char field_AC0;
    unsigned char field_AC1;
};
extern "C" int atoi(const char *);
extern "C" char * func_00234FF0(char *, char *, const char *);
extern "C" void * memset(void *, int, unsigned int);
extern "C" int sprintf(char *, const char *, ...);
extern "C" unsigned int strlen(const char *);
extern "C" char * strncat(char *, const char *, int);
extern "C" char * strncpy(char *, const char *, int);
extern char D_004BAF58[];
extern char D_004BAF68[];
extern char D_004BAF70[];
extern char D_004BAF78[];
extern char D_004BAF80[];
extern char D_004BAFE8[];
extern char D_004BAFF8[];
extern char D_004BB010[];
extern char D_004BB028[];
extern char D_004BB040[];
extern char D_004BB050[];
extern char D_004BB068[];
extern char D_004BB080[];
extern char D_004BB1B0[];
extern char D_004BB1B8[];
extern char D_004BB1C0[];
extern char D_004BB1C8[];
extern char D_004BA018[];
extern char D_004BAF28[];
extern char kacSpecificPortMapPacketBody1[];
extern char kacSpecificPortMapPacketBody3[];
extern char kacSpecificPortMapPacketBody4[];
extern char kacSpecificPortMapPacketHeader2[];
extern char kacSpecificPortMapPacketHeader3[];
extern char kacSpecificPortMapPacketHeader4[];
extern "C" int snprintf(char *, unsigned int, const char *, ...);
extern "C" int sscanf(const char *, const char *, ...);
extern "C" char * strpbrk(const char *, const char *);
extern "C" int func_00234DB0(void *, const char *, const char *, char *);

extern char D_004BAF70[];
extern char D_004BAF88[];
extern char D_004BAFA0[];
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
static inline int parse_ip(const char * b)
{
    int a[4];
    sscanf(b, D_004BA018, &a[0], &a[1], &a[2], &a[3]);
    return (a[0] << 24) + (a[1] << 16) + (a[2] << 8) + a[3];
}
extern "C" int GetPortMappingDetails__17CGtNATDataManagerFiPiPiPiPi(UnkStruct_00231B30 * self, int port, int * p1, int * p2, int * p3, int * p4)
{
    char buf270[0x40];
    char buf230[0x40];
    char buf220[0x10];
    int st = self->field_AB8;
    switch (st) {
    case 0: {
        int r = self->field_524->vfunc_28(self->field_53C, self->field_540);
        if (r == 1) return self->field_AB8;
        if (r == 4) { self->field_AB8 = 4; return self->field_AB8; }
        memset(D_01D7F700, 0, 0x800);
        memset(D_01D7FF00, 0, 0x800);
        unsigned int n = 0x800;
        strncat(D_01D7FF00, kacSpecificPortMapPacketBody1 + 0x50, n);
        n = n - strlen(kacSpecificPortMapPacketBody1 + 0x50);
        strncat(D_01D7FF00, (char *)self + (self->field_AA4 << 7) + 0x8A4, n);
        n = n - strlen((char *)self + (self->field_AA4 << 7) + 0x8A4);
        strncat(D_01D7FF00, kacSpecificPortMapPacketBody3, n);
        n = n - strlen(kacSpecificPortMapPacketBody3);
        if (self->field_AC0 == 0) {
            sprintf(buf270, D_004BAF70, self->field_544);
        strncat(D_01D7FF00, buf270, n);
        n = n - strlen(buf270);
        }
        strncat(D_01D7FF00, kacSpecificPortMapPacketBody3 + 0x50, n);
        n = n - strlen(kacSpecificPortMapPacketBody3 + 0x50);
        if (self->field_AC1 != 0) sprintf(buf270, D_004BAF78);
        else sprintf(buf270, D_004BAF80, port);
        strncat(D_01D7FF00, buf270, n);
        n = n - strlen(buf270);
        strncat(D_01D7FF00, kacSpecificPortMapPacketBody4 + 0x50, n);
        n = n - strlen(kacSpecificPortMapPacketBody4 + 0x50);
        n = 0x800;
        strncat(D_01D7F700, kacSpecificPortMapPacketHeader2 + 0x40, n);
        n = n - strlen(kacSpecificPortMapPacketHeader2 + 0x40);
        strncat(D_01D7F700, (char *)self + (self->field_AA4 << 7) + 0x6A4, n);
        n = n - strlen((char *)self + (self->field_AA4 << 7) + 0x6A4);
        strncat(D_01D7F700, kacSpecificPortMapPacketHeader3, n);
        n = n - strlen(kacSpecificPortMapPacketHeader3);
        strncat(D_01D7F700, (char *)self + (self->field_AA4 << 7) + 0x8A4, n);
        n = n - strlen((char *)self + (self->field_AA4 << 7) + 0x8A4);
        strncat(D_01D7F700, kacSpecificPortMapPacketHeader4 + 0x10, n);
        n = n - strlen(kacSpecificPortMapPacketHeader4 + 0x10);
        sprintf(buf270, D_004BAF88, self->field_52C);
        strncat(D_01D7F700, buf270, n);
        n = n - strlen(buf270);
        sprintf(buf270, D_004BAFA0, strlen(D_01D7FF00));
        strncat(D_01D7F700, buf270, n);
        n = n - strlen(buf270);
        strncat(D_01D7F700, kacSpecificPortMapPacketBody1 + 0x10, n);
        n = n - strlen(kacSpecificPortMapPacketBody1 + 0x10);
        strncat(D_01D7F700, D_01D7FF00, n);
        n = n - strlen(D_01D7FF00);
        self->field_524->vfunc_30(D_01D7F700, 0x800 - n);
        self->field_AB0 = 0;
        memset(D_01D7D700, 0, 0x2000);
        self->field_AB8 = 1;
        break;
    }
    case 1: {
        int r = self->field_524->vfunc_34(D_01D7D700 + self->field_AB0, 0x2000 - self->field_AB0);
        if (r > 0) {
            self->field_AB0 += r;
            char * t = func_00234FF0(D_01D7D700, D_01D7D700 + self->field_AB0, D_004BAFE8);
            if (t != 0) {
                char * p = strpbrk(t + strlen(D_004BAFE8), D_004BB028);
                if (p != 0) {
                    int len = atoi(p);
                    char * q = func_00234FF0(D_01D7D700, D_01D7D700 + self->field_AB0, D_004BAF68);
                    if (q != 0 && !((int)strlen(q) < len)) { self->field_AB8 = 2; return self->field_AB8; }
                }
            }
        }
        break;
    }
    case 2: {
        if (self->field_524->vfunc_2C() == 2) return self->field_AB8;
        char * end = D_01D7D700 + self->field_AB0;
        char * s5; char * e5; char * s2; char * e2;
        char * s6; char * e6;
        if (find_tag(end, D_004BAFF8, s5, e5)) {
            atoi(s5);
            if (find_tag(end, D_004BB010, s2, e2)) {
                int l = e2 - s2;
                strncpy(buf230, s2, l < 0x40 ? l : 0x40);
            }
            self->field_AB8 = 4;
            return self->field_AB8;
        }
        find_tag(end, D_004BB040, s5, e5);
        *p2 = atoi(s5);
        find_tag(end, D_004BB050, s6, e6);
        func_00234DB0(s6, e6, D_004BAF28, buf220);
        *p1 = parse_ip(buf220);
        find_tag(end, D_004BB068, s2, e2);
        *p3 = atoi(s2);
        find_tag(end, D_004BB080, s2, e2);
        *p4 = atoi(s2);
        self->field_AB8 = 3;
        return self->field_AB8;
    }
    default:
        break;
    }
    return self->field_AB8;
}
