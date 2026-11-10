// NONMATCHING: FindGatewayDevice__17CGtNATDataManagerFv -- retail 787 / ours 786 instructions, 41 in changed runs
// draftJ: 787/786, 41 in changed runs = one block: case 7's 'p == 0 -> field_598 = 9' fail block; retail emits it out of line after the service-type check block (with its own b epi; lw), ours at the function end. Calls, branch senses, registers otherwise identical. Tried: inline if+return (MWCC inverts the branch), goto fail at several spots, if/else around the tail, !p, while(p), do-while AA4 loop.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; every branch, call and store accounted for; codegen identical except the placement of one return block

// CGtNATDataManager::FindGatewayDevice() -- hand-written (draftJ) from the retail asm and the Ghidra draft.
// [C] name: retail tables. Shape [C asm]: UPnP gateway discovery state machine on field_598 (jump table, 8 states): 0 send the
// SSDP search, 1 wait, 2 read replies (gateway IP/port/path), 3 send the description request, 4 wait, 5 receive, 6 retry,
// 7 parse the description XML (services, control URLs). Returns field_598. Field names placeholders, types [G]; style of
// the matched sibling RemoveAPortMapping (find_digit inline, min as ternary).
struct UnkStruct_00233C50_sock {
    virtual void vfunc_8(); virtual int vfunc_C(char *, int, int, int); virtual int vfunc_10(char **, int *, int *); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual int vfunc_28(int, int); virtual int vfunc_2C(); virtual int vfunc_30(void *, int); virtual int vfunc_34(void *, int);
};
class CGtNATDataManager {
public:
    int FindGatewayDevice();
    unsigned char pad_0[0x524];
    UnkStruct_00233C50_sock * field_524;
    unsigned char pad_528[4];
    char field_52C[0x10];
    int field_53C;
    int field_540;
    char field_544[0x10];
    int field_554;
    unsigned char pad_558[0x40];
    int field_598;
    int field_59C;
    int field_5A0;
    char field_5A4[0x100];
    char field_6A4[4][0x80];
    char field_8A4[4][0x80];
    int field_AA4;
    int field_AA8;
    unsigned char pad_AAC[4];
    int field_AB0;
};
extern "C" int atoi(const char *);
extern "C" char * func_00234FF0(char *, char *, const char *);
extern "C" int func_00234DB0(char *, char *, const char *, char *);
extern "C" void * memset(void *, int, unsigned int);
extern "C" int sprintf(char *, const char *, ...);
extern "C" int snprintf(char *, unsigned int, const char *, ...);
extern "C" int sscanf(const char *, const char *, ...);
extern "C" unsigned int strlen(const char *);
extern "C" char * strncat(char *, const char *, int);
extern "C" char * strncpy(char *, const char *, int);
extern char D_004BA018[];
extern char D_004BA060[];
extern char D_004BA070[];
extern char D_004BAEA0[];
extern char D_004BAED0[];
extern char D_004BAFF8[];
extern char D_004BB010[];
extern char D_004BB0D8[];
extern char D_004BB0E8[];
extern char D_004BB0F0[];
extern char D_004BB0F8[];
extern char D_004BB108[];
extern char D_004BB118[];
extern char D_004BB128[];
extern char D_004BB138[];
extern char D_004BB148[];
extern char D_004BB158[];
extern char D_004BB160[];
extern char D_004BB170[];
extern char D_004BB1B0[];
extern char D_004BB1B8[];
extern char D_004BB1C0[];
extern char D_004BB1C8[];
extern char D_01D7D700[];
extern char D_01D7F700[];
extern char kacInfoPacketHeader3[];
extern char kacPortMapPacketHeader2[];

static inline char * func_00233C50_inl1(char * start, char * end, char * pat)
{
    char * p = func_00234FF0(start, end, pat);
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

static inline bool func_00233C50_inl2(char * from, char * to, char * tag, char *& vs, char *& ve)
{
    char buf[0x40];
    vs = 0;
    ve = 0;
    snprintf(buf, 0x40, D_004BB1C8, tag);
    char * p = func_00234FF0(from, to, buf);
    if (p != 0) {
        vs = func_00234FF0(p, to, D_004BB1C0) + strlen(D_004BB1B8);
        snprintf(buf, 0x40, D_004BB1B0, tag);
        ve = func_00234FF0(vs, to, buf);
        return true;
    }
    return false;
}

static inline int func_00233C50_inl3(char * s)
{
    int ip[4];
    sscanf(s, D_004BA018, &ip[0], &ip[1], &ip[2], &ip[3]);
    return (ip[0] << 24) + (ip[1] << 16) + (ip[2] << 8) + ip[3];
}

int CGtNATDataManager::FindGatewayDevice()
{
    switch (field_598) {
    case 0:
        field_524->vfunc_C(D_004BA070, 0x84, func_00233C50_inl3(D_004BA060), 0x76C);
        field_59C = 0;
        field_598 = 1;
        break;
    case 1:
        field_59C++;
        if (field_59C > 120) field_598 = 2;
        break;
    case 2: {
        int r;
        do {
            char * p;
            int a, b;
            r = field_524->vfunc_10(&p, &a, &b);
            if (r > 0 && func_00234FF0(p, p + r, D_004BAEA0) != 0) {
                func_00234DB0(p, p + r, D_004BB0D8, field_52C);
                field_53C = func_00233C50_inl3(field_52C);
                char * q = func_00233C50_inl1(p, p + r, field_52C);
                field_540 = atoi(q);
                char * x = func_00234FF0(q, p + r, D_004BB0E8);
                char * y = func_00234FF0(q, x, D_004BB0F0);
                strncpy(field_5A4, y, x - y);
                field_598 = 3;
                field_5A0 = 0;
                return field_598;
            }
        } while (r > 0);
        field_5A0++;
        if (field_5A0 < 4) field_598 = 0;
        else field_598 = 9;
        break;
    }
    case 3: {
        int r = field_524->vfunc_28(field_53C, field_540);
        if (r == 1) return field_598;
        if (r == 4) { field_598 = 9; return field_598; }
        char buf[0x100];
        memset(D_01D7F700, 0, 0x800);
        unsigned int n = 0x800;
        strncat(D_01D7F700, kacInfoPacketHeader3 + 8, n);
        n = n - strlen(kacInfoPacketHeader3 + 8);
        sprintf(buf, field_5A4);
        strncat(D_01D7F700, buf, n);
        n = n - strlen(buf);
        strncat(D_01D7F700, kacInfoPacketHeader3 + 0x10, n);
        n = n - strlen(kacInfoPacketHeader3 + 0x10);
        sprintf(buf, D_004BB0F8, field_52C, field_540);
        strncat(D_01D7F700, buf, n);
        n = n - strlen(buf);
        strncat(D_01D7F700, kacPortMapPacketHeader2 + 0x20, n);
        n = n - strlen(kacPortMapPacketHeader2 + 0x20);
        field_524->vfunc_30(D_01D7F700, 0x800 - n);
        field_59C = 0;
        field_598 = 4;
        break;
    }
    case 4:
        field_59C++;
        if (field_59C > 120) {
            field_AB0 = 0;
            memset(D_01D7D700, 0, 0x2000);
            field_598 = 5;
        }
        break;
    case 5: {
        int r = field_524->vfunc_34(D_01D7D700 + field_AB0, 0x2000 - field_AB0);
        field_AB0 += r;
        if (r > 0 && func_00234FF0(D_01D7D700, D_01D7D700 + field_AB0, D_004BAED0) != 0) {
            field_598 = 7;
            return field_598;
        }
        field_5A0++;
        if (field_5A0 < 4) {
            field_AA8 = 3;
            field_598 = 6;
        } else {
            field_AA8 = 9;
            field_598 = 6;
        }
        break;
    }
    case 6:
        if (field_524->vfunc_2C() == 2) return field_598;
        field_598 = field_AA8;
        break;
    case 7: {
        if (field_524->vfunc_2C() == 2) return field_598;
        char * end = D_01D7D700 + field_AB0;
        char * vs;
        char * ve;
        if (func_00233C50_inl2(D_01D7D700, end, D_004BAFF8, vs, ve)) {
            char err[0x40];
            atoi(vs);
            if (func_00233C50_inl2(D_01D7D700, end, D_004BB010, vs, ve)) {
                int n = ve - vs;
                strncpy(err, vs, n < 0x40 ? n : 0x40);
            }
            field_598 = 9;
            return field_598;
        }
        char * p = D_01D7D700;
        char * se;
        do {
            char * q = func_00234FF0(p, end, D_004BB108);
            if (q == 0) {
                field_598 = 9;
                return field_598;
            }
            p = q + strlen(D_004BB108);
            char * nx = func_00234FF0(p, end, D_004BB108);
            se = func_00234FF0(p, end, D_004BB118);
            if (nx == 0 || se < nx) {
                func_00233C50_inl2(p, se, D_004BB160, vs, ve);
                if (func_00234FF0(vs, ve, D_004BB170) != 0) break;
            }
        } while (p != 0);
        if (p == 0) goto fail;
        while (field_AA4 < 4) {
            if (!func_00233C50_inl2(p, se, D_004BB128, vs, ve)) break;
            p = vs;
            if (func_00234FF0(vs, ve, D_004BB138) != 0) {
                int n = ve - vs;
                strncpy(field_8A4[field_AA4], vs, n < 0x80 ? n : 0x80);
                char * s2;
                char * s3;
                func_00233C50_inl2(vs, se, D_004BB148, s2, s3);
                if (!func_00234FF0(s2, s3, D_004BB158)) {
                    int m = s3 - s2;
                    strncpy(field_6A4[field_AA4], s2, m < 0x80 ? m : 0x80);
                } else {
                    func_00234DB0(s2, s3, D_004BB158, field_544);
                    char * d = func_00233C50_inl1(s2, s3, field_52C);
                    field_540 = atoi(d);
                    field_554 = func_00233C50_inl3(field_544);
                    for (; *d > '/' && *d < ':' && d < s3; d++) {
                    }
                    int m = s3 - d;
                    strncpy(field_6A4[field_AA4], d, m < 0x80 ? m : 0x80);
                }
                field_AA4++;
            }
        }
        while (field_AA4 < 4) {
            field_8A4[field_AA4][0] = 0;
            field_6A4[field_AA4][0] = 0;
            field_AA4++;
        }
        field_AA4 = 0;
        field_598 = 8;
        return field_598;
    fail:
        field_598 = 9;
        return field_598;
    }
    }
    return field_598;
}
