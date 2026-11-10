// NONMATCHING: func_0023B8C0 -- retail 280 / ours 280 instructions, 46 in changed runs
// near32: 46 off (was 51 under today's compiler), registers only: retail glob=s1 (reused as loop car), pl=s2, flag=s3, ts=s4; ours pl/car s1, flag s2, glob s3. sreg 3 rounds (best: s4 declared at the top); tried pl declared first, no glob pointer (288 instrs), non-const glob pointer
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// a140: layout/jtbl/instr count exact (280=280); only s-register assignment differs (retail s1=&D_0064D3B0 [reused as loop car], s2=pl/lim, s3=flag, s4=ts; ours pl=s1,flag=s2,ts=s3,glob=s4) and float operand regs (f0/f1 swapped in 255*x)

#include "b3/classes/UnkStruct_D_0051BA88.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));
class CGtNetworkPlayerManager {
public:
    int GetMyPlayerIndex() const;
    unsigned char pad_0[0x10];
};
struct UnkStruct_0023B8C0_pl {
    unsigned char pad_0[0xB0];
    u_long128 field_B0;
    unsigned char pad_C0[0x10];
    u_long128 field_D0;
    unsigned char pad_E0[0x124];
    int field_204;
    unsigned char pad_208[8];
    unsigned char field_210;
    unsigned char pad_211[0x1235];
    unsigned char field_1446;
    unsigned char pad_1447[0xDD];
    int field_1524;
    unsigned char field_1528;
};
struct UnkStruct_0023B8C0_car2 {
    unsigned char pad_0[0xB0];
    u_long128 field_B0;
    unsigned char pad_C0[0x10];
    u_long128 field_D0;
    unsigned char pad_E0[0x124];
    int field_204;
    unsigned char pad_208[0x221C];
    UnkStruct_0023B8C0_car2 * field_2424;
    unsigned char field_2428;
    unsigned char field_2429;
    unsigned char pad_242A;
    signed char field_242B;
};
struct UnkStruct_D_0064D3B0 {
    unsigned char pad_0[0x1161];
    unsigned char field_1161;
    unsigned char field_1162;
    unsigned char pad_1163[0x551];
    float field_16B4;
    unsigned char pad_16B8[0x2E0];
    unsigned char field_1998;
    unsigned char pad_1999[0x13];
    signed char field_19AC;
    unsigned char pad_19AD[0xAB7];
};
struct UnkStruct_0023B8C0_pkt {
    int field_0;
    int field_4;
    int field_8;
    unsigned char field_C;
    int field_10;
    unsigned char field_14;
    unsigned char field_15;
    unsigned char field_16;
    unsigned char field_17;
    unsigned char field_18;
    unsigned char field_19;
    unsigned char field_1A;
    unsigned char * field_1C;
    unsigned char * field_20;
};
struct UnkStruct_0023B8C0_car3 { unsigned char pad_0[0x19AC]; signed char field_19AC; };
struct UnkStruct_0023B8C0 {
    unsigned char pad_0[0xC];
    CGtNetworkPlayerManager * field_C;
    unsigned char pad_10[0x5B0];
    unsigned char field_5C0;
    unsigned char field_5C1;
    unsigned char pad_5C2[0x11A];
    UnkStruct_0023B8C0_car3 * field_6DC;
    unsigned char pad_6E0[4];
    unsigned char field_6E4[0x4819];
    unsigned char field_4EFD[6];
    unsigned char field_4F03[6];
    unsigned char field_4F09;
    unsigned char field_4F0A;
    unsigned char field_4F0B;
    unsigned char field_4F0C;
    int field_4F10;
};
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0055EFEC_e { UnkStruct_0023B8C0_pl * field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x122A10]; UnkStruct_0023B8C0_car2 * field_122A10[1]; };
extern UnkStruct_D_int D_01E654A0;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0064D3B0 D_0064D3B0;
extern UnkStruct_D_0055EFEC_e D_0055EFEC[];
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_int D_0064517C;
extern unsigned char D_004EE040[0x10];
extern "C" void func_001AA660();
extern "C" int func_0023BD20(void *, unsigned short *);
extern "C" int func_0023BE90(void *);
extern "C" void func_001A9DD0(void *, void *, void *, void *, void *, void *, int);
extern "C" bool func_00131E40(void *);
extern "C" void func_001A9D60(void *, int);
extern "C" void func_001A9D70(void *, int, void *, void *, void *);
extern "C" void func_0022FBC0(void *, int, int);

// 0x0023B8C0
extern "C" void func_0023B8C0(UnkStruct_0023B8C0 * self)
{
    int s4;
    if (self->field_5C0 == 0 || self->field_5C1 != 0) return;
    if (D_01E654A0.field_0 == -1) return;
    func_001AA660();
    UnkStruct_D_0064D3B0 * const s1 = &D_0064D3B0;
    UnkStruct_0023B8C0_pl * pl = D_0055EFEC[s1->field_19AC].field_0;
    if (pl == 0) return;
    int ts;
    if (!func_0023BD20(self, (unsigned short *)&ts)) return;
    if (D_0051BA88.field_0->field_1B4->vfunc_9C() == 3) return;
    u_long128 vA = pl->field_B0;
    u_long128 vB = pl->field_D0;
    s4 = *(unsigned short *)&ts;
    if (s4 == 0xFFFF) s4 = 0;
    bool s3 = false;
    if (pl->field_210 != 0) {
        if (func_0023BE90(self) != 0) s3 = true;
    }
    UnkStruct_0023B8C0_pkt pkt;
    switch (D_0051BA88.field_0->field_1B4->vfunc_9C()) {
    case 0:
    case 3:
    case 4:
    case 5:
        pkt.field_8 = 0;
        pkt.field_4 = (int)(s1->field_16B4 * 255.0f);
        break;
    case 2:
        pkt.field_8 = 0;
        pkt.field_4 = (int)(s1->field_16B4 * 255.0f);
        if (s1->field_1162 != 0) pkt.field_8 |= 1;
        if (s1->field_1161 != 0) pkt.field_8 |= 2;
        break;
    case 1:
    default:
        break;
    }
    pkt.field_C = self->field_4F0C;
    pkt.field_10 = pl->field_1524;
    pkt.field_14 = pl->field_210;
    pkt.field_15 = pl->field_1528;
    pkt.field_16 = pl->field_1446;
    pkt.field_1C = self->field_4EFD;
    pkt.field_20 = self->field_4F03;
    pkt.field_17 = self->field_4F09;
    pkt.field_18 = self->field_4F0A;
    pkt.field_19 = self->field_4F0B;
    pkt.field_1A = !(s1->field_1998 != 0);
    pkt.field_0 = self->field_6DC->field_19AC;
    int sz;
    if (s3) {
        func_001A9DD0(self->field_6E4, s1, &vA, &vB, (char *)s1 + 0x2464, &pkt, s4);
        int n = 0;
        bool bb = func_00131E40(&D_004EE040);
        int lim = bb ? 0x18 : 8;
        int cnt = D_0064517C.field_0;
        for (int i = 0; i < cnt; i++) {
            UnkStruct_0023B8C0_car2 * car = D_00522660.field_122A10[i];
            if (car->field_242B == self->field_C->GetMyPlayerIndex()) {
                vA = car->field_B0;
                vB = car->field_D0;
                int s3b = car->field_204;
                int s6 = car->field_2429;
                if (!(n < lim)) break;
                if (car->field_2428 != 0) continue;
                if (car->field_2424 != 0) {
                    u_long128 vC = car->field_2424->field_B0;
                    u_long128 vD = car->field_2424->field_D0;
                    if (!(n + 1 < lim)) break;
                    func_001A9D70(self->field_6E4, car->field_2424->field_2429, (void *)(car->field_2424->field_204), &vC, &vD);
                    n++;
                }
                func_001A9D70(self->field_6E4, s6, (void *)(s3b), &vA, &vB);
                n++;
            }
        }
        func_001A9D60(self->field_6E4, n);
        sz = 0x240 - (0x18 - n) * 22;
    } else {
        func_001A9DD0(self->field_6E4, s1, &vA, &vB, (char *)s1 + 0x2464, &pkt, s4);
        func_001A9D60(self->field_6E4, 0);
        sz = 0x30;
    }
    for (int j = 0; j < 6; j++) {
        self->field_4EFD[j] = 0;
        self->field_4F03[j] = 0;
    }
    if (self->field_4F10 > 0) {
        self->field_4F10 = self->field_4F10 - 1;
    } else {
        self->field_4F0A = 0;
        self->field_4F0B = 0;
        self->field_4F09 = 0;
        self->field_4F0C = 0xFF;
    }
    func_0022FBC0(self, 8, sz);
}

