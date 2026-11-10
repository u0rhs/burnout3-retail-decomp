// NONMATCHING: func_0022E200 -- retail 296 / ours 288 instructions, 48 in changed runs
// draftAO (2026-11-01): reviewed complete against retail (three thread functions: 0x22E200 connect/shutdown state machine, 0x22E300 receive ring, 0x22E560 send ring); receive-ring positions made unsigned (retail sltu at 0x22E3B4 / 0x22E4DC); scored whole-unit (the header's 63 was the first entry only) | Before: psweep: scoped #pragma inline_depth(3) [G] improves 1165 -> 78
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: calls and arguments identical (Recvfrom/Sendto 6 args, callback jalr), every store, bound and wrap checked


// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma inline_depth(3)

struct UnkStruct_0022E200_se { int f0; int f4; unsigned char f8[0x10]; };
struct UnkStruct_0022E200_re { int f0; int f4; unsigned char f8[0x10]; };
struct UnkStruct_0022E200 {
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x2C];
    void (*field_3C)(int);
    unsigned char pad_40[0x5C];
    int field_9C;
    unsigned char pad_A0[0xC];
    int field_AC;
    int field_B0;
    UnkStruct_0022E200_se field_B4[32];
    int field_3B4;
    int field_3B8;
    UnkStruct_0022E200_re field_3BC[32];
    unsigned int field_6BC;     // receive buffer base [G]; compared unsigned (sltu) [C] 0x22E3B4, 0x22E4DC
    unsigned int field_6C0;
    unsigned int field_6C4;     // receive write position, passed to sceInsockRecvfrom as the buffer
    int field_6C8;
    int field_6CC;
    unsigned int field_6D0;     // receive buffer size [G]
    unsigned char pad_6D4[0x3C];
    int field_710;
    unsigned char field_714[0x10];
};
extern "C" {
void SleepThread();
int sceInsockConnect(int, void *, int);
int sceInsockSetRecvTimeout(int, int);
int sceInsockShutdown(int, int);
void SleepThreadTillVBlank__12CGtThreadMgrFv();
int *__sceInsockErrnoLoc(void);
long sceInsockRecvfrom(int, int, int, int, void *, int *);
int sceInsockSendto(int, int, int, int, void *, int);
void WaitSema(int);
void SignalSema(int);
}

// 0x0022E200
extern "C" void func_0022E200(UnkStruct_0022E200 *self, void *a1 /* passed by every caller, not read here */)
{
    for (;;) {
        switch (self->field_710) {
        case 5:
            SleepThread();
            break;
        case 1:
            if (0 > sceInsockConnect(self->field_B0, self->field_714, 16)) self->field_710 = 4;
            if (0 > sceInsockSetRecvTimeout(self->field_B0, 50)) self->field_710 = 4;
            self->field_710 = 3;
            break;
        case 2:
            if (sceInsockShutdown(self->field_B0, 2) < 0) {
                if (*__sceInsockErrnoLoc() != 0x68) self->field_710 = 4;
            }
            self->field_B0 = -1;
            self->field_710 = 3;
            break;
        }
        SleepThreadTillVBlank__12CGtThreadMgrFv();
    }
}

// 0x0022E300 [G] second function behind func_0022E200's alabel
extern "C" void func_0022E300(UnkStruct_0022E200 *self)
{
    int i;
    while (self->field_AC == -1) SleepThreadTillVBlank__12CGtThreadMgrFv();
    for (;;) {
        for (i = 0; i < 32; ) {
            while (self->field_AC == -1) SleepThreadTillVBlank__12CGtThreadMgrFv();
            for (;;) {
                bool full;
                if (self->field_6CC == self->field_6C8 - 1) full = true;
                else if (self->field_6CC == 31 && *(const int *)&self->field_6C8 == 0) full = true;
                else {
                    unsigned int a1 = self->field_6BC + self->field_6D0;
                    unsigned int a0 = self->field_6C0;
                    unsigned int v1 = self->field_6C4;
                    int d;                       // compared signed with field_C (slt) [C] 0x22E3D0
                    if (v1 >= a0) d = a1 - v1;
                    else d = a0 - v1;
                    if (d < self->field_C) full = true;
                    else full = false;
                }
                if (!full) break;
                SleepThreadTillVBlank__12CGtThreadMgrFv();
            }
            int len = 16;
            int r = sceInsockRecvfrom(self->field_AC, (int)self->field_6C4, self->field_C, 0, self->field_3BC[self->field_6CC].f8, &len);
            if (r > 0) {
                self->field_3BC[self->field_6CC].f0 = self->field_6C4;
                self->field_3BC[self->field_6CC].f4 = r;
                int m = r % 4;
                if (m != 0) r += 4 - m;
                self->field_6C4 += r;
                if (self->field_6BC + self->field_6D0 < self->field_6C4 + self->field_C) self->field_6C4 = self->field_6BC;
                if (self->field_6CC >= 31) self->field_6CC = 0;
                else self->field_6CC++;
                i++;
            } else {
                if (*__sceInsockErrnoLoc() != 0x71) __sceInsockErrnoLoc();   // second call's result unused [C] 0x22E548
                i++;
            }
        }
        SleepThreadTillVBlank__12CGtThreadMgrFv();
    }
}

// 0x0022E560 [G] third function
extern "C" void func_0022E560(UnkStruct_0022E200 *self)
{
    int i;
    int n;
    while (self->field_AC == -1) SleepThreadTillVBlank__12CGtThreadMgrFv();
    for (;;) {
        while (self->field_AC == -1) SleepThreadTillVBlank__12CGtThreadMgrFv();
        WaitSema(self->field_9C);
        if (self->field_3B4 >= self->field_3B8) n = self->field_3B4 - self->field_3B8;
        else n = 32 - self->field_3B8 + self->field_3B4;
        for (i = 0; i < n; i++) {
            UnkStruct_0022E200_se *e = &self->field_B4[self->field_3B8];
            sceInsockSendto(self->field_AC, e->f0, e->f4, 0, e->f8, 16);
            if (self->field_3C != 0) {
                self->field_3C(e->f0);
                e->f0 = 0;
            } else {
                e->f0 = 0;
            }
            if (self->field_3B8 > 30) self->field_3B8 = 0;
            else self->field_3B8++;
        }
        SignalSema(self->field_9C);
        SleepThreadTillVBlank__12CGtThreadMgrFv();
    }
}




#pragma pop
