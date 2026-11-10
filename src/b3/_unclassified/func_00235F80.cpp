// Hand-written; the lifter refused it (a146: network rx dispatch loop; FindPlayer inline w/ for+continue stubs; 'UnkStruct*const s2' declared after the counter store fixes regs + jal delay slot; IP bytes via (unsigned char)((x&0xFF000000)>>24)).

struct UnkStruct_5F80_rx {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual int vfunc_10(void *, int *, int *);
};
struct UnkStruct_5F80_msg { unsigned char pad_0; unsigned char field_1; unsigned char pad_2[2]; int field_4; int field_8; };
struct UnkStruct_5F80 {
    unsigned char pad_0[4];
    unsigned char field_4;
    unsigned char pad_5[3];
    void *field_8[1];
    unsigned char pad_C[0x1C];
    int field_28;
    unsigned char pad_2C[0x4C];
    int field_78;
    UnkStruct_5F80_rx *field_7C;
    unsigned char pad_80[0xC];
    unsigned char field_8C;
    unsigned char pad_8D[3];
    void (*field_90)(void *, int, int);
    unsigned char pad_94[0x4E0 - 0x94];
    unsigned char field_4E0[0x53C];
    int field_A1C;
};
struct UnkStruct_5F80_pl { unsigned char pad_0[0x18]; int field_18; unsigned char pad_1C[8]; int field_24; };
extern int D_004E295C;
extern int D_004E2960;
extern char D_004BA008[];
extern "C" {
int func_0022D3B0();
int func_0022D920(void *, int);
void func_0022D850(void *);
int func_00235590(void *, void *);
int func_0022FBB0(void *);
void func_0022FEF0(void *, void *);
int func_002353D0(void *, void *);
void func_00235960(void *, void *, int, int);
void func_00235A80(void *, void *, int, int);
int func_00235770(void *, void *);
void func_0022FF90(void *, void *, int);
UnkStruct_5F80_pl *func_00231190(void *, int);
int snprintf(char *, unsigned int, const char *, ...);
}
#define IPB(x) (unsigned char)(((x) & 0xFF000000) >> 24), ((x) & 0xFF0000) >> 16, ((x) & 0xFF00) >> 8, (x) & 0xFF
static inline void *func_00235F80_inl1(UnkStruct_5F80 *self, int key)
{
    int i;
    if (key == self->field_78) return 0;
    for (i = 0; i < self->field_28; i++) {
        void **pp = &self->field_8[i];
        if (*pp == 0) continue;
        if (func_0022FBB0(*pp) != key) continue;
        return *pp;
    }
    return 0;
}
// 0x00235F80
extern "C" void func_00235F80(UnkStruct_5F80 *self)
{
    if (self->field_7C == 0) return;
    if (self->field_4 == 0) return;
    if (func_0022D3B0() == 0) return;
    D_004E295C = 0;
    D_004E2960 = 0;
    int s3;
    do {
        UnkStruct_5F80_msg *sp8C;
        int sp88, sp84;
        char buf[0x10];
        s3 = self->field_7C->vfunc_10(&sp8C, &sp88, &sp84);
        if (s3 > 0 && sp88 != self->field_A1C) {
            D_004E295C = D_004E295C + 1;
            UnkStruct_5F80_msg *const s2 = sp8C;
            if (func_0022D920(s2, s3) == 0) return;
            func_0022D850(s2);
            if (func_00235590(self, s2) != 0 || func_002353D0(self, s2) != 0) {
                int s0 = s2->field_8;
                void *a0 = func_00235F80_inl1(self, s0);
                if (a0 != 0) func_0022FEF0(a0, s2);
            } else if (s2->field_1 != self->field_8C) {
                func_00235960(self, s2, sp88, sp84);
            } else {
                int s5 = s2->field_4;
                void *s1 = func_00235F80_inl1(self, s5);
                if (s1 != 0) {
                    int s0 = ((UnkStruct_5F80_pl *)s1)->field_24;
                    if (s0 != sp88) {
                        snprintf(buf, 0x10, D_004BA008, IPB(sp88));
                        snprintf(buf, 0x10, D_004BA008, IPB(s0));
                        if (self->field_90 != 0) self->field_90(s1, sp88, s0);
                    } else {
                        D_004E2960 = D_004E2960 + 1;
                        func_00235A80(self, s2, sp88, sp84);
                        if (func_00235770(self, s2) == 0) func_0022FF90(s1, s2, s3);
                        func_00231190(self->field_4E0, s5)->field_18 = sp84;
                    }
                } else {
                    snprintf(buf, 0x10, D_004BA008, IPB(sp88));
                    func_00235960(self, s2, sp88, sp84);
                }
            }
        }
    } while (s3 > 0);
}
