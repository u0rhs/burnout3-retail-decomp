// NONMATCHING: GetGatewayExternalAddress__17CGtNATDataManagerFv -- retail 527 / ours 526 instructions, 148 in changed runs
// a160: 526/527 instrs, logic complete (verified structure vs retail, frame size OK); remaining: self=s1 where retail has s0 (n/t/end and sscanf arg pointers &a[1..3] take s0 in ours; retail s1,s2,s3 with &a[1]=s2,&a[2]=s3,&a[3]=s1), plus 'move s2,zero' delay-slot placement in the two find_tag snprintf calls; two separate int[4] arrays (one per sscanf site)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


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
    char field_544[0x10];
    int field_554;
    unsigned char pad_558[0x54C];
    int field_AA4;
    unsigned char pad_AA8[4];
    int field_AAC;
    int field_AB0;
    int field_AB4;
    unsigned char pad_AB8[0x4];
    unsigned char pad_ABC[0xC];
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
extern char D_004BAFE8[];
extern char D_004BAFF8[];
extern char D_004BB010[];
extern char D_004BB028[];
extern char D_004BB0A0[];
extern char D_004BB0C0[];
extern char D_004BB1B0[];
extern char D_004BB1B8[];
extern char D_004BB1C0[];
extern char D_004BB1C8[];
extern char D_004BA018[];
extern char D_004BAF28[];
extern char kacGetExternalIPAddressPacket1[];
extern char kacGetExternalIPAddressPacketHeader2[];
extern char kacGetExternalIPAddressPacketHeader3[];
extern char kacGetExternalIPAddressPacketHeader4[];
extern char kacSearchReplySSDPPart[];
extern "C" int snprintf(char *, unsigned int, const char *, ...);
extern "C" int sscanf(const char *, const char *, ...);
extern "C" char * strpbrk(const char *, const char *);
extern "C" int func_00234DB0(void *, const char *, const char *, char *);

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
extern "C" int GetGatewayExternalAddress__17CGtNATDataManagerFv(UnkStruct_00231B30 * self)
{
    char buf170[0x40];
    char buf130[0x40];
    int b[4];
    int a[4];
    int st = self->field_AAC;
    switch (st) {
    case 0: {
        int r = self->field_524->vfunc_28(self->field_53C, self->field_540);
        if (r == 1) return self->field_AAC;
        if (r == 4) { self->field_AAC = 4; return self->field_AAC; }
        memset(D_01D7F700, 0, 0x800);
        memset(D_01D7FF00, 0, 0x800);
        unsigned int n = 0x800;
        strncat(D_01D7FF00, kacGetExternalIPAddressPacket1 + 0x50, n);
        n = n - strlen(kacGetExternalIPAddressPacket1 + 0x50);
        strncat(D_01D7FF00, (char *)self + (self->field_AA4 << 7) + 0x8A4, n);
        n = n - strlen((char *)self + (self->field_AA4 << 7) + 0x8A4);
        strncat(D_01D7FF00, kacSearchReplySSDPPart + 0x20, n);
        n = n - strlen(kacSearchReplySSDPPart + 0x20);
        n = 0x800;
        strncat(D_01D7F700, kacGetExternalIPAddressPacketHeader2 + 0x40, n);
        n = n - strlen(kacGetExternalIPAddressPacketHeader2 + 0x40);
        strncat(D_01D7F700, (char *)self + (self->field_AA4 << 7) + 0x6A4, n);
        n = n - strlen((char *)self + (self->field_AA4 << 7) + 0x6A4);
        strncat(D_01D7F700, kacGetExternalIPAddressPacketHeader3, n);
        n = n - strlen(kacGetExternalIPAddressPacketHeader3);
        strncat(D_01D7F700, (char *)self + (self->field_AA4 << 7) + 0x8A4, n);
        n = n - strlen((char *)self + (self->field_AA4 << 7) + 0x8A4);
        strncat(D_01D7F700, kacGetExternalIPAddressPacketHeader4 + 0x20, n);
        n = n - strlen(kacGetExternalIPAddressPacketHeader4 + 0x20);
        sprintf(buf170, D_004BAF88, self->field_52C);
        strncat(D_01D7F700, buf170, n);
        n = n - strlen(buf170);
        sprintf(buf170, D_004BAFA0, strlen(D_01D7FF00));
        strncat(D_01D7F700, buf170, n);
        n = n - strlen(buf170);
        strncat(D_01D7F700, kacGetExternalIPAddressPacket1 + 0x10, n);
        n = n - strlen(kacGetExternalIPAddressPacket1 + 0x10);
        strncat(D_01D7F700, D_01D7FF00, n);
        n = n - strlen(D_01D7FF00);
        self->field_524->vfunc_30(D_01D7F700, 0x800 - n);
        self->field_AB0 = 0;
        memset(D_01D7D700, 0, 0x2000);
        self->field_AAC = 1;
        break;
    }
    case 1: {
        self->field_AB0 += self->field_524->vfunc_34(D_01D7D700 + self->field_AB0, 0x2000 - self->field_AB0);
        char * t = func_00234FF0(D_01D7D700, D_01D7D700 + self->field_AB0, D_004BAFE8);
        if (t != 0) {
            char * p = strpbrk(t + strlen(D_004BAF58), D_004BB028);
            if (p != 0) {
                int len = atoi(p);
                char * q = func_00234FF0(D_01D7D700, D_01D7D700 + self->field_AB0, D_004BAF68);
                if (q != 0 && !((int)strlen(q) < len)) self->field_AAC = 2;
            }
        }
        break;
    }
    case 2: {
        if (self->field_524->vfunc_2C() == 2) return self->field_AAC;
        char * end = D_01D7D700 + self->field_AB0;
        char * s2; char * e2; char * s4; char * e4;
        if (find_tag(end, D_004BAFF8, s2, e2)) {
            atoi(s2);
            s4 = 0; e4 = 0;
            if (find_tag(end, D_004BB010, s4, e4)) {
                int l = e4 - s4;
                strncpy(buf130, s4, l < 0x40 ? l : 0x40);
            }
            self->field_AAC = 4;
            return self->field_AAC;
        }
        char * t = func_00234FF0(D_01D7D700, end, D_004BB0A0);
        if (t != 0) {
            if (!(func_00234DB0(t, end, D_004BAF28, self->field_544) & 0xFF)) {
                self->field_AB4 += 1;
                if (self->field_AB4 < 5) self->field_AAC = 0; else self->field_AAC = 4;
            } else {
                sscanf(self->field_544, D_004BA018, &a[0], &a[1], &a[2], &a[3]);
                self->field_554 = a[3] + ((a[2] << 8) + ((a[0] << 24) + (a[1] << 16)));
                self->field_AAC = 3;
            }
            return self->field_AAC;
        }
        s2 = 0; e2 = 0;
        find_tag(end, D_004BB0C0, s2, e2);
        if (s2 != e2) {
            if (!(func_00234DB0(s2, e2, D_004BAF28, self->field_544) & 0xFF)) {
                self->field_AB4 += 1;
                if (self->field_AB4 < 5) { self->field_AAC = 0; break; }
                self->field_AAC = 4;
                return self->field_AAC;
            }
            sscanf(self->field_544, D_004BA018, &b[0], &b[1], &b[2], &b[3]);
            self->field_554 = b[3] + ((b[2] << 8) + ((b[0] << 24) + (b[1] << 16)));
            self->field_AAC = 3;
            return self->field_AAC;
        }
        self->field_AA4 += 1;
        self->field_AAC = 0;
        break;
    }
    default:
        break;
    }
    return self->field_AAC;
}
