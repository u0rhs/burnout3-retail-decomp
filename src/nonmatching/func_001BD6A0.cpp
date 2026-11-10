// NONMATCHING: func_001BD6A0 -- retail 490 / ours 454 instructions, 534 in changed runs
// son8: first archive. Full logic from asm: drive-mode update (wrong-way/AI/race-car physics dispatch by self+0x1580), per-wheel (0xC0 stride at +0x898) rumble accumulator with 4 type groups x contact states 3/4, early-out rumble call (func_0022C2F0 on D_004F50C0), force-feedback block (func_004429F0 with fabsf/steer blend, GetSteering), and the two tail rumble blocks. Left: retail's frame 0x140 (VU temps for v.xyz*row dot, sqc2 spill) vs ours 0x70, the dot as explicit VU, and the inlined clamp/min-max shape of D_004E16A0/A4
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_001BD6A0_w {          // 0xC0-byte element at this+0x898 [G]
    int field_0;
    unsigned char pad_4[0x34];
    signed char field_38;
    unsigned char pad_39[1];
    unsigned char field_3A;
    unsigned char field_3B;
    unsigned char pad_3C[0x84];
};
struct UnkStruct_001BD6A0_ct { unsigned char pad_0[0x133C]; int field_133C; unsigned char pad_1340[0x1480]; int field_27C0; unsigned char pad_27C4[4]; unsigned char field_27C8; };
struct UnkStruct_001BD6A0_cu { unsigned char pad_0[0x178C]; int field_178C; };
struct UnkStruct_001BD6A0_vt { unsigned char pad_0[0x24]; void (*vfunc_24)(void *); };
struct UnkStruct_001BD6A0_tm { unsigned char pad_0[0x1015]; unsigned char field_1015; };
struct UnkStruct_001BD6A0_in { unsigned char pad_0[0xD50]; int field_D50; };
struct UnkStruct_001BD6A0_s {
    UnkStruct_001BD6A0_vt *field_0;
    unsigned char pad_4[0xAC];
    u_long128 field_B0;
    unsigned char pad_C0[0x1E0];
    int *field_2A0;
    unsigned char pad_2A4[0x624];
    UnkStruct_001BD6A0_w field_8D0_base[1];
};

struct UnkStruct_001BD6A0_c {
    UnkStruct_001BD6A0_vt *field_0;
    unsigned char pad_4[0xAC];
    CGtV4d field_B0;
    unsigned char pad_C0[0x70 - 0x40 + 0x40 - 0x30];
};

extern unsigned char D_004F50C0[];
extern signed char D_004F6061[];
extern unsigned char D_004F6065[];
extern unsigned char D_004F60A0;
extern unsigned char D_00665E53;
extern int D_01E90430;
extern float D_004E1D94, D_004E1D90, D_004E1D98, D_004E1D9C, D_004E0D6C, D_004E1D8C, D_004E0E00;
extern int D_004E2DB4, D_004E1D60, D_004E2718, D_004E16A8;
extern float D_004E1D64, D_004E1D68, D_004E1D6C, D_004E1D70, D_004E1D74;
extern float D_004E16A0, D_004E16A4, D_004E16AC, D_004E16B0, D_004E16B4, D_004E16B8, D_004E16BC, D_004E271C, D_004E0C50;
extern "C" void func_0019C120(void *, int);
extern "C" void func_001D2960(void *, float);
extern "C" void Update__17CB3RaceCarPhysicsFf(void *, float);
extern "C" void func_0022C2F0(void *, int, signed char, int, float, float, float, float);
extern "C" void func_0022BEE0(void *, signed char, int, float);
extern "C" int func_0012EF20(void *);
extern "C" float func_0012F850(void *);
extern "C" signed char GetLockedPlayersPort__15CB3InputManagerFSc(void *, signed char);
extern "C" void func_004429F0(void *, float, float);
extern "C" float fabsf(float);

extern "C" void func_001BD6A0(UnkStruct_001BD6A0_c *self, float p0)
{
    char *b = (char *)self;
    UnkStruct_001BD6A0_ct *ct = *(UnkStruct_001BD6A0_ct **)(b + 0x1580);
    signed char port = ct->field_27C0;
    if (ct->field_133C == 3) {
        *(int *)(b + 0x3510) = 0;
    } else {
        func_0019C120(b + 0x1590, port);
    }
    if ((*(UnkStruct_001BD6A0_ct **)(b + 0x1580))->field_27C8 == 0) {
        Update__17CB3RaceCarPhysicsFf(self, p0);
    } else {
        func_001D2960(self, p0);
    }
    self->field_0->vfunc_24(self);
    float acc = 0.0f;
    signed char n = *(signed char *)(b + 0x1169);
    float s = ((float)*(int *)(b + 0xBC) / 70.0f) / (float)n;
    long i = 0;
    while (i < n) {
        UnkStruct_001BD6A0_w *e = (UnkStruct_001BD6A0_w *)(b + 0x898 + i * 0xC0);
        if (e->field_3B != 0) {
            bool chk = true;
            switch (e->field_38) {
            case 1: case 2: case 12: case 13:
                if (e->field_0 == 3) { acc = D_004E1D94 * s * 0.5f + acc + 0.0f; chk = false; break; }
                if (e->field_0 == 4) { acc = D_004E1D90 * s * 0.5f + acc + 0.0f; chk = false; break; }
                break;
            case 4: case 5: case 6: case 8: case 9:
                if (e->field_0 == 3) acc = D_004E1D94 * s + acc + 0.0f;
                else if (e->field_0 == 4) acc = D_004E1D90 * s + acc + 0.0f;
                acc = D_004E1D98 * s + acc + 0.0f;
                break;
            case 7: case 11: case 14: case 15: case 16: case 18: case 20:
                if (e->field_0 == 3) acc = D_004E1D94 * s + acc + 0.0f;
                else if (e->field_0 == 4) acc = D_004E1D90 * s + acc + 0.0f;
                acc = D_004E1D9C * s + acc + 0.0f;
                break;
            }
            if (chk && e->field_3A != 0 && 20.0f < D_004E0D6C * ((float *)&self->field_B0)[3]) {
                if ((i & 1) == 0)
                    func_0022C2F0(D_004F50C0, D_004E2DB4, port, 0xFFFF, D_004E1D8C, -1.0f, D_004E1D8C, D_004E0E00);
                else
                    func_0022C2F0(D_004F50C0, D_004E2DB4, port, 0xFFFF, D_004E1D8C, 1.0f, D_004E1D8C, D_004E0E00);
                break;
            }
        }
        i = i + 1;
    }
    func_0022BEE0(D_004F50C0, port, 1, 0.0f);
    func_0022BEE0(D_004F50C0, port, 2, acc);
    signed char *pp = &D_004F6061[port];
    int ci;
    if (func_0012EF20((char *)D_004F50C0 + 0xD48 + *pp * 300) == 0) {
        ci = *(int *)(b + 0x13F4);
    } else {
        signed char lp = GetLockedPlayersPort__15CB3InputManagerFSc(D_004F50C0, port);
        if (D_004F6065[lp] == 0 || D_004F60A0 != 0 || D_00665E53 != 0 || D_01E90430 != 0) {
            func_004429F0((void *)(*(int *)((char *)D_004F50C0 + 0xD50 + *pp * 300)), D_004E0C50, 0.0f);
            ci = *(int *)(b + 0x13F4);
        } else if (*(unsigned char *)(b + 0x8D3) == 0 && *(unsigned char *)(b + 0x993) == 0) {
            func_004429F0((void *)(*(int *)((char *)D_004F50C0 + 0xD50 + *pp * 300)), 0.0f, 0.0f);
            ci = *(int *)(b + 0x13F4);
        } else {
            CGtV4d v = self->field_B0;
            float t = (D_004E0D6C * ((float *)&v)[3]) / 50.0f;
            if (!(t < 1.0f)) t = 1.0f;
            float a = D_004E16A0 * t;
            float c = D_004E16A4 > a ? D_004E16A4 : a;
            float *row = *(float **)(b + 0x204);
            float dot = ((float *)&v)[0] * row[0] + ((float *)&v)[1] * row[1] + ((float *)&v)[2] * row[2];
            float steer = 0.0f - dot;
            float amount = fabsf(steer) * 0.25f + c + 0.0f;
            if (D_004E0D6C * ((float *)&v)[3] < 20.0f) {
                float k = (D_004E0D6C * ((float *)&v)[3]) / 20.0f;
                float w = func_0012F850((char *)D_004F50C0 + 0xD48 + *pp * 300);
                steer = steer * k + w * (1.0f - k);
            }
            if (*(unsigned char *)(b + 0x212) != 0) {
                steer = 0.0f;
                amount = D_004E16A4;
            }
            func_004429F0((void *)(*(int *)((char *)D_004F50C0 + 0xD50 + *pp * 300)), amount, steer);
            ci = *(int *)(b + 0x13F4);
        }
    }
    UnkStruct_001BD6A0_cu *cu = (UnkStruct_001BD6A0_cu *)ci;
    if (cu->field_178C != 1) {
        if (*(unsigned char *)(b + 0x1446) == 0) {
            *(unsigned char *)(b + 0x4581) = 0;
            if (*(unsigned char *)(b + 0x1529) == 0) {
                func_0022BEE0(D_004F50C0, port, 0xFFFF, 0.0f);
            } else if (*(unsigned char *)(b + 0x152A) == 0) {
                func_0022BEE0(D_004F50C0, port, 0xFFFF, D_004E1D70);
            } else if (*(unsigned char *)(b + 0x152B) == 0) {
                func_0022BEE0(D_004F50C0, port, 0xFFFF, D_004E1D74);
            } else {
                func_0022BEE0(D_004F50C0, port, 0xFFFF, 0.0f);
            }
        } else if (*(unsigned char *)(b + 0x4581) == 0) {
            func_0022C2F0(D_004F50C0, D_004E1D60, port, 0xFFFF, D_004E1D64, 0.0f, D_004E1D68, D_004E1D6C);
            *(unsigned char *)(b + 0x4581) = 1;
        }
    }
    UnkStruct_001BD6A0_tm *tm = *(UnkStruct_001BD6A0_tm **)(b + 0xCC4);
    if ((tm->field_1015 & 8) != 0) {
        func_0022C2F0(D_004F50C0, D_004E16A8, port, 0xFFFF, D_004E16AC, 0.0f, D_004E16B0, D_004E16B4);
        func_0022C2F0(D_004F50C0, D_004E2718, port, 0xFFFF, D_004E16B8, 0.0f, D_004E16BC, D_004E271C);
    }
}
