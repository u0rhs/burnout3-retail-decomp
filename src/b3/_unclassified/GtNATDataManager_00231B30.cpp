// CGtNATDataManager::RemoveAPortMapping(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNATDataManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a160: UPnP SOAP state machine; vtable class, unsigned n, find_digit inline w/ goto, min as ternary).

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
    unsigned char pad_AB4[0xC];
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
extern char D_004BAFB8[];
extern char D_004BAFD0[];
extern char D_01D7D700[];
extern char D_01D7F700[];
extern char D_01D7FF00[];
extern char kacDeletePortMapPacketBody1[];
extern char kacDeletePortMapPacketBody3[];
extern char kacDeletePortMapPacketBody4[];
extern char kacDeletePortMapPacketHeader3[];
extern char kacDeletePortMapPacketHeader4[];

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

extern "C" int RemoveAPortMapping__17CGtNATDataManagerFi(UnkStruct_00231B30 * self, int port)
{
    char buf80[0x40];
    char buf40[0x40];
    int st = self->field_AC4;
    switch (st) {
    case 0: {
        int r = self->field_524->vfunc_28(self->field_53C, self->field_540);
        if (r == 1) return self->field_AC4;
        if (r == 4) { self->field_AC4 = 4; return self->field_AC4; }
        memset(D_01D7F700, 0, 0x800);
        memset(D_01D7FF00, 0, 0x800);
        unsigned int n = 0x800;
        strncat(D_01D7FF00, kacDeletePortMapPacketBody1 + 0x50, n);
        n = n - strlen(kacDeletePortMapPacketBody1 + 0x50);
        strncat(D_01D7FF00, (char *)self + (self->field_AA4 << 7) + 0x8A4, n);
        n = n - strlen((char *)self + (self->field_AA4 << 7) + 0x8A4);
        strncat(D_01D7FF00, kacDeletePortMapPacketBody3, n);
        n = n - strlen(kacDeletePortMapPacketBody3);
        if (self->field_AC0 == 0) {
            sprintf(buf80, D_004BAF70, self->field_544);
            strncat(D_01D7FF00, buf80, n);
            n = n - strlen(buf80);
        }
        strncat(D_01D7FF00, kacDeletePortMapPacketBody3 + 0x50, n);
        n = n - strlen(kacDeletePortMapPacketBody3 + 0x50);
        if (self->field_AC1 != 0) sprintf(buf80, D_004BAF78);
        else sprintf(buf80, D_004BAF80, port);
        strncat(D_01D7FF00, buf80, n);
        n = n - strlen(buf80);
        strncat(D_01D7FF00, kacDeletePortMapPacketBody4 + 0x50, n);
        n = n - strlen(kacDeletePortMapPacketBody4 + 0x50);
        n = 0x800;
        strncat(D_01D7F700, D_004BA9B8, n);
        n = n - strlen(D_004BA9B8);
        strncat(D_01D7F700, (char *)self + (self->field_AA4 << 7) + 0x6A4, n);
        n = n - strlen((char *)self + (self->field_AA4 << 7) + 0x6A4);
        strncat(D_01D7F700, kacDeletePortMapPacketHeader3, n);
        n = n - strlen(kacDeletePortMapPacketHeader3);
        strncat(D_01D7F700, (char *)self + (self->field_AA4 << 7) + 0x8A4, n);
        n = n - strlen((char *)self + (self->field_AA4 << 7) + 0x8A4);
        strncat(D_01D7F700, kacDeletePortMapPacketHeader4 + 0x20, n);
        n = n - strlen(kacDeletePortMapPacketHeader4 + 0x20);
        sprintf(buf80, D_004BAF88, self->field_52C);
        strncat(D_01D7F700, buf80, n);
        n = n - strlen(buf80);
        sprintf(buf80, D_004BAFA0, strlen(D_01D7FF00));
        strncat(D_01D7F700, buf80, n);
        n = n - strlen(buf80);
        strncat(D_01D7F700, kacDeletePortMapPacketBody1 + 0x10, n);
        n = n - strlen(kacDeletePortMapPacketBody1 + 0x10);
        strncat(D_01D7F700, D_01D7FF00, n);
        n = n - strlen(D_01D7FF00);
        self->field_524->vfunc_30(D_01D7F700, 0x800 - n);
        self->field_AB0 = 0;
        memset(D_01D7D700, 0, 0x2000);
        self->field_AC4 = 1;
        break;
    }
    case 1: {
        int r = self->field_524->vfunc_34(D_01D7D700 + self->field_AB0, 0x2000 - self->field_AB0);
        if (r > 0) {
            self->field_AB0 += r;
            char * end = D_01D7D700 + self->field_AB0;
            char * p = find_digit(end, D_004BAF58);
            if (p != 0) {
                int len = atoi(p);
                char * q = func_00234FF0(D_01D7D700, D_01D7D700 + self->field_AB0, D_004BAF68);
                if (q != 0 && !((int)strlen(q) < len)) self->field_AC4 = 2;
            }
        }
        break;
    }
    case 2: {
        if (self->field_524->vfunc_2C() == 2) return self->field_AC4;
        {
        char * end = D_01D7D700 + self->field_AB0;
        char * p = find_digit(end, D_004BAFB8);
        if (p != 0) {
            atoi(p);
            char * q = func_00234FF0(D_01D7D700, end, D_004BAFD0);
            if (q != 0) {
                char * a = q + strlen(D_004BAFD0);
                char * b = a;
                while (*b != 0x3C && b < end) b++;
                int l = b - a;
                strncpy(buf40, a, l < 0x40 ? l : 0x40);
            }
            self->field_AC4 = 4;
            return self->field_AC4;
        }
        self->field_AC4 = 3;
        }
        break;
    }
    default:
        break;
    }
    return self->field_AC4;
}
