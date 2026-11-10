// NONMATCHING: func_00230600 -- retail 404 / ours 408 instructions, 290 in changed runs
// a160: UPnP NAT top-level state machine (10-state jump table, calls FindGatewayDevice/GetGatewayExternalAddress/GetPortMappingDetails/RemoveAPortMapping/SetUpAPortMapping); 408/404 instrs, 290 in changed runs. Prologue, time-out check, case 0/1 and stack layout match (int c[4]/a[4]/b[4] declared in that order). Open: sscanf pointer temps &a[1..3] get s1,s0,s3 where retail s1,s3,s0 (loop var s1/entry s0 swapped); retail lays cases 2..6 'bne r,K -> ret0' with the body inline and the 'close session' tails (3 copies) out of line at the end; ours puts bodies out of line (goto-merged tail) -- inlining the tail 3x gives 421 instrs. self is UnkStruct with e0 entries (stride 0x90, same as func_002310B0)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_00230600_e0 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    float field_2C;
    int field_30;
    unsigned char field_34;
    unsigned char pad_35[0x1F];
    float field_54;
    unsigned char field_58;
    unsigned char field_59;
    unsigned char field_5A;
    unsigned char field_5B;
    unsigned char field_5C;
    unsigned char field_5D;
    unsigned char field_5E;
    unsigned char pad_5F[0x1];
    unsigned char field_60[0x10];
    unsigned char field_70[0x10];
    unsigned char field_80[0x10];
};

struct UnkStruct_00230600_net {
    virtual void vfunc_8();
    virtual void vfunc_C(void *, int, int, int);
    virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34();
    virtual void vfunc_38(int);
    unsigned char pad_4[0x18];
    char field_1C[0x10];
};

struct UnkStruct_00230600 {
    UnkStruct_00230600_e0 field_0[8];
    unsigned char pad_480[0xA4];
    UnkStruct_00230600_net * field_524;
    int field_528;
    unsigned char pad_52C[0x2C];
    int field_558;
    char field_55C[0x10];
    int field_56C;
    int field_570;
    int field_574;
    int field_578;
    unsigned char pad_57C[0x4];
    float field_580;
    int field_584;
    int field_588;
    int field_58C;
    int field_590;
    char field_594[4];
    int field_598;
    unsigned char pad_59C[0x4];
    int field_5A0;
    unsigned char pad_5A4[0x500];
    int field_AA4;
    unsigned char pad_AA8[0x4];
    int field_AAC;
    unsigned char pad_AB0[0x4];
    int field_AB4;
    int field_AB8;
    int field_ABC;
    unsigned char field_AC0;
    unsigned char field_AC1;
    unsigned char pad_AC2[0x2];
    int field_AC4;
};

extern "C" void * func_0022D2A0(UnkStruct_00230600_net *, void *);
extern "C" void func_0022D9F0(void *);
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" void * memset(void *, int, unsigned int);
extern "C" int sscanf(const char *, const char *, ...);
extern "C" int FindGatewayDevice__17CGtNATDataManagerFv(UnkStruct_00230600 *);
extern "C" int GetGatewayExternalAddress__17CGtNATDataManagerFv(UnkStruct_00230600 *);
extern "C" int GetPortMappingDetails__17CGtNATDataManagerFiPiPiPiPi(UnkStruct_00230600 *, int, int *, int *, int *, int *);
extern "C" int RemoveAPortMapping__17CGtNATDataManagerFi(UnkStruct_00230600 *, int);
extern "C" int SetUpAPortMapping__17CGtNATDataManagerFii(UnkStruct_00230600 *, int, int);
extern char D_004BA018[];
extern char D_004BA048[];

static inline void func_00230600_inl1(UnkStruct_00230600 * self)
{
    self->field_574 = 0;
    func_0022D2A0(self->field_524, (void *)(self->field_58C));
    self->field_524->vfunc_24();
    self->field_584 = 8;
}

extern "C" int func_00230600(UnkStruct_00230600 * self, UnkStruct_00230600_net * net, int p1, float now)
{
    int c[4];
    int a[4];
    int b[4];
    int st = self->field_584;
    if (st != 7 && st != 8 && st != 9) {
        float last = self->field_580;
        if (!(last == -1.0f) && !(now - last <= 60.0f)) {
            self->field_574 = 0;
            if (self->field_58C != 0) {
                func_0022D2A0(self->field_524, (void *)(self->field_58C));
            }
            self->field_524->vfunc_24();
            self->field_584 = 7;
            return 1;
        }
    }
    switch (st) {
    case 0: {
        self->field_58C = (int)func_0022D2A0(net, (void *)(0));
        net->vfunc_20();
        self->field_524 = net;
        self->field_528 = p1;
        strncpy(self->field_55C, self->field_524->field_1C, 0x10);
        sscanf(self->field_55C, D_004BA018, &a[0], &a[1], &a[2], &a[3]);
        self->field_56C = a[3] + ((a[2] << 8) + ((a[0] << 24) + (a[1] << 16)));
        self->field_588 = 0;
        self->field_584 = 1;
        for (int i = 0; i < 8; i++) {
            UnkStruct_00230600_e0 * e = &self->field_0[i];
            e->field_0 = 4;
            e->field_4 = -1;
            e->field_8 = -1;
            e->field_C = -1;
            e->field_10 = -1;
            e->field_14 = -1;
            e->field_18 = -1;
            e->field_1C = 0;
            e->field_20 = 0;
            e->field_24 = -1;
            e->field_28 = -1;
            e->field_2C = -1.0f;
            e->field_30 = 0;
            e->field_34 = 0;
            e->field_54 = -1.0f;
            e->field_58 = 0;
            e->field_59 = 0;
            e->field_5A = 0;
            e->field_5B = 0;
            e->field_5C = 0;
            e->field_5D = 0;
            e->field_5E = 0;
            func_0022D9F0(e->field_60);
            func_0022D9F0(e->field_70);
            func_0022D9F0(e->field_80);
        }
        self->field_AA4 = 0;
        self->field_AC0 = 1;
        self->field_AC1 = 0;
        self->field_580 = now;
        return 0;
    }
    case 1: {
        sscanf(D_004BA048, D_004BA018, &b[0], &b[1], &b[2], &b[3]);
        int v = b[3] + ((b[2] << 8) + ((b[0] << 24) + (b[1] << 16)));
        memset(self->field_594, 0, 4);
        self->field_524->vfunc_C(self->field_594, 4, v, 0x7F2);
        self->field_5A0 = 0;
        self->field_598 = 0;
        self->field_584 = 2;
        return 0;
    }
    case 2: {
        int r = FindGatewayDevice__17CGtNATDataManagerFv(self);
        if (r == 9) goto closing;
        if (r == 8) {
            self->field_578 = 1;
            self->field_574 = 1;
            self->field_AB4 = 0;
            self->field_AAC = 0;
            self->field_584 = 3;
        }
        return 0;
    }
    case 3: {
        int r = GetGatewayExternalAddress__17CGtNATDataManagerFv(self);
        if (r == 4) goto closing;
        if (r == 3) {
            self->field_570 = -1;
            self->field_590 = 0x2756;
            self->field_AB8 = 0;
            self->field_584 = 4;
        }
        return 0;
    }
    case 4: {
        int r = GetPortMappingDetails__17CGtNATDataManagerFiPiPiPiPi(self, self->field_590, &c[3], &c[2], &c[1], &c[0]);
        if (r == 4) {
            if (self->field_590 == 0xE4A) self->field_590 = 0x2756; else self->field_590 = self->field_590 + 1;
            self->field_AB8 = 0;
            if (self->field_590 >= 0x2761) {
                self->field_590 = 0x2756;
                self->field_ABC = 0;
                self->field_584 = 6;
            }
            return 0;
        }
        if (r == 3) {
            if (c[3] == self->field_56C) {
                self->field_AC4 = 0;
                self->field_584 = 5;
                return 0;
            }
            if (self->field_590 == 0xE4A) self->field_590 = 0x2756; else self->field_590 = self->field_590 + 1;
            self->field_AB8 = 0;
            if (self->field_590 >= 0x2761) {
                self->field_590 = 0x2756;
                self->field_ABC = 0;
                self->field_584 = 6;
            }
        }
        return 0;
    }
    case 5: {
        int r = RemoveAPortMapping__17CGtNATDataManagerFi(self, self->field_590);
        if (r == 4) {
            if (self->field_590 == 0xE4A) self->field_590 = 0x2756; else self->field_590 = self->field_590 + 1;
            self->field_AB8 = 0;
            if (self->field_590 >= 0x2761) {
                self->field_590 = 0x2756;
                self->field_ABC = 0;
                self->field_584 = 6;
            }
            return 0;
        }
        if (r == 3) {
            self->field_ABC = 0;
            self->field_584 = 6;
        }
        return 0;
    }
    case 6: {
        int r = SetUpAPortMapping__17CGtNATDataManagerFii(self, self->field_590, self->field_590);
        if (r == 4) {
            int pt = self->field_590;
            if (pt == 0xE4A) self->field_590 = 0x2756; else self->field_590 = pt + 1;
            self->field_ABC = 0;
            if (self->field_590 >= 0x2761) {
                self->field_574 = 0;
                func_0022D2A0(self->field_524, (void *)(self->field_58C));
                self->field_524->vfunc_24();
                self->field_584 = 8;
                return 1;
            }
        }
        if (r == 3) {
            self->field_570 = self->field_590;
            self->field_558 = self->field_590;
            self->field_524->vfunc_38(self->field_570);
            func_0022D2A0(self->field_524, (void *)(self->field_58C));
            self->field_524->vfunc_24();
            self->field_584 = 9;
            return 1;
        }
        return 0;
    }
    case 7:
    case 8:
    case 9:
        return 1;
    default:
        return 0;
    }
closing:
    self->field_574 = 0;
    func_0022D2A0(self->field_524, (void *)(self->field_58C));
    self->field_524->vfunc_24();
    self->field_584 = 8;
    return 1;
}
