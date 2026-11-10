// Hand-written; the lifter refused it (near3: the two timeouts are one condition '(v == 0 && s0 >= 30) || (v == 1 && field_44 >= 0x708)' with the fail block inline (no goto)).


struct UnkStruct_0022DB20_ba { unsigned char b[0x10]; };
struct UnkStruct_D_01D7AF04 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01D7AED0 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01D7AED4 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01D7AECC { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01D7AEA0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01D7B700 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01D6EE00 { unsigned char pad_0[0x1340]; };
extern UnkStruct_D_01D7AF04 D_01D7AF04;
extern UnkStruct_D_01D7AED0 D_01D7AED0;
extern UnkStruct_D_01D7AED4 D_01D7AED4;
extern UnkStruct_D_01D7AECC D_01D7AECC;
extern UnkStruct_D_01D7AEA0 D_01D7AEA0;
extern UnkStruct_D_01D7B700 D_01D7B700;
extern unsigned char D_01D7AE80[];
extern UnkStruct_D_01D6EE00 D_01D6EE00[];
extern "C" {
void sceSifMInitRpc(int);
int sceLibnetInitialize(void *, int, int, int);
int func_003D41B8(void *, void *);
int ezNetCtlInit();
int ezNetCtlSetProperties(void *);
int ezNetCtlUpInterface();
int ezNetCtlGetStatus(void *, void *, int);
void SleepThreadTillVBlank__12CGtThreadMgrFv();
int ezNetCtlExit(int);
int ezNetCtlDownInterface();
int sceLibnetWaitGetAddress(void *, void *, int *, int, void *, int);
void sceInetAddress2String(void *, void *, void *, int, void *);
void sceInsockInetAton(void *, void *);
void sceInetInterfaceControl(void *, void *, int, int, void *, int);
void sceInetGetInterfaceList(void *, void *, int *, int);
}
struct UnkStruct_0022DB20 {
    unsigned char pad_0[0x14];
    int field_14;
    int field_18;
    unsigned char field_1C[0x10];
    unsigned char field_2C[0x10];
    unsigned char pad_3C[8];
    int field_44;
    unsigned char pad_48[4];
    unsigned char field_4C;
    unsigned char field_4D;
    unsigned char pad_4E;
    unsigned char field_4F;
    unsigned char field_50[0x54];
    int field_A4;
    int field_A8;
    unsigned char pad_AC[0x65C];
    unsigned char field_708;
};
static inline void func_0022DB20_inl1(UnkStruct_0022DB20 *self, int code)
{
    self->field_14 = 3;
    self->field_18 = code;
    self->field_4F = 0;
}

// 0x0022DB20
extern "C" void func_0022DB20(UnkStruct_0022DB20 *self)
{
    int s0 = 0;
    int addr;
    unsigned char ifc[0x1C];
    unsigned char buf[0x80];
    unsigned char ife[0x10];
    sceSifMInitRpc(0);
    if (sceLibnetInitialize(self->field_50, 0x2000, 0x2000, 0x20) < 0) return;
    if (func_003D41B8(self->field_50, &D_01D7B700) < 0) return;
    if (self->field_4D == 0) {
        int idx;
        if (self->field_A4 == 0) idx = D_01D7AF04.field_0 - 1;
        else idx = self->field_A4 - 1;
        if (D_01D7AE80[idx] == 0) { func_0022DB20_inl1(self, 6); return; }
        UnkStruct_D_01D6EE00 *cfg = &D_01D6EE00[idx];
        if (ezNetCtlInit() < 0) { func_0022DB20_inl1(self, 7); return; }
        if (ezNetCtlSetProperties(cfg) < 0) {
            ezNetCtlExit(2);
            func_0022DB20_inl1(self, 2);
            return;
        }
        ezNetCtlUpInterface();
        self->field_44 = 0;
        for (;; self->field_44++) {
            if (self->field_44 % 60 == 0) {
                if (ezNetCtlGetStatus(&D_01D7AEA0, buf, 0x80) != 0) { func_0022DB20_inl1(self, 7); return; }
                int st = D_01D7AED0.field_0;
                if (st == 3) goto connected;
                if (st == 5) {
                    if (D_01D7AECC.field_0 == -0x12E) { func_0022DB20_inl1(self, 10); return; }
                    goto connected;
                }
                if (st == 0) { func_0022DB20_inl1(self, 8); return; }
                int v = D_01D7AED4.field_0;
                if ((v == 0 && s0 >= 30) || (v == 1 && self->field_44 >= 0x708)) {
                    ezNetCtlDownInterface();
                    ezNetCtlExit(2);
                    func_0022DB20_inl1(self, 9);
                    return;
                }
                if (v == 0) s0++;
            } else {
                SleepThreadTillVBlank__12CGtThreadMgrFv();
            }
        }
    connected:
        ezNetCtlExit(2);
        if (D_01D7AED0.field_0 != 3) { func_0022DB20_inl1(self, 7); return; }
        {
            if (sceLibnetWaitGetAddress(self->field_50, &D_01D7B700, &addr, 1, ifc, 0) < 0) { func_0022DB20_inl1(self, 7); return; }
            sceInetAddress2String(self->field_50, &D_01D7B700, self->field_1C, 16, ifc);
            sceInsockInetAton(self->field_1C, &self->field_A8);
            sceInetInterfaceControl(self->field_50, &D_01D7B700, addr, 13, self->field_2C, 16);
        }
    } else {
        sceInetGetInterfaceList(self->field_50, &D_01D7B700, &addr, 1);
        sceInetInterfaceControl(self->field_50, &D_01D7B700, addr, 9, ife, 16);
        sceInetAddress2String(self->field_50, &D_01D7B700, self->field_1C, 16, ife);
        sceInsockInetAton(self->field_1C, &self->field_A8);
        sceInetInterfaceControl(self->field_50, &D_01D7B700, addr, 13, self->field_2C, 16);
    }
    self->field_708 = 1;
    self->field_4C = 1;
}
