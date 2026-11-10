// NONMATCHING: func_00364300 -- retail 192 / ours 192 instructions, 12 in changed runs
// prag1: scoped opt_propagation off [G] + s0 = 0x2DA04 assigned in each arm just before the call (else arm: arg in a local first), o==0 as goto into the switch default, D_004E2918 > 1, D_004E1110 -> 3.28083992f literal: 103 -> 12. Left: prologue schedule only (retail hoists lw v0,4(a0) to the top, move s3,a0 before the branch, sq s0 in the delay slot); 15-pragma second sweep, switch form, local copy of field_4 no change
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#pragma push
#pragma opt_propagation off
// a150: logic complete (type 1 object/vehicle string id, flag-row dispatch 4/8/1/2). OPEN: retail keeps the constant 0x2DA04 (D_0051BA44-D_004EE040) in saved reg s0 (lui/ori hoisted before first GetString call), used as 'addu a0,&D_004EE040,s0' at 4 sites; every source form (int local, (char*)&G+K, (int)&G+K, big struct member) either folds the reloc or rematerialises per site. Also frame: buf60 is ushort[16]. ~45 instrs differ, all around s0/frame.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

struct UnkStruct_00364300_obj {
    unsigned char pad_0[0x215];
    signed char field_215;
    unsigned char pad_216[0x2214];
    unsigned char field_242A;
};
struct UnkStruct_00364300 {
    UnkStruct_00364300_obj * field_0;
    int field_4;
    int field_8;
    float field_C;
};
struct UnkStruct_D_004E2918 { unsigned int field_0; };
struct UnkStruct_D_004C74C0 { int field_0; int field_4; int field_8; int field_C; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004E2918 D_004E2918;
extern UnkStruct_D_004C74C0 D_004C74C0[];
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_004EE040 D_004EE040;
extern unsigned long D_0055B7D0[];
extern float D_004E1110;
extern char D_004C7700[];
extern "C" int func_00271A00(void *, int);
extern "C" int func_003EAC90(int);
extern "C" int FindTrafficVehicle__23CB3HardCodedVehicleListFUl(unsigned long);
extern "C" void *func_001A3AA0(void *, void *, int *);
extern "C" void func_001A39E0(void *, void *, int *, int *);
extern "C" void func_00364600(void *, int, unsigned short *, int *);
extern "C" unsigned short * Copy__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" int sprintf(char *, const char *, ...);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, unsigned short *, int);

extern "C" void func_00364300(UnkStruct_00364300 * self, void * out, int a2 /* passed by every caller, not read here */)
{
    int s1;
    int s0;
    int sp8C;
    int sp88;
    int sp84;
    int sp80;
    unsigned short buf60[16];
    char buf50[16];
    if (self->field_4 == 1) {
        UnkStruct_00364300_obj * o = self->field_0;
        int id;
        if (o == 0) goto def;
            switch (o->field_215) {
            case 1:
            case 2:
            case 3:
                id = 0x8DA;
                break;
            case 4:
            case 5:
                id = func_003EAC90(FindTrafficVehicle__23CB3HardCodedVehicleListFUl(D_0055B7D0[o->field_242A]));
                break;
            default:
            def:
                id = 0x7AC;
                break;
            }
        s0 = 0x2DA04;
        s1 = func_00271A00(&D_0051BA44, id);
    } else {
        int a = D_004C74C0[self->field_4].field_0;
        s0 = 0x2DA04;
        s1 = func_00271A00(&D_0051BA44, a);
    }
    int flags = D_004C74C0[self->field_4].field_4;
    if (flags & 4) {
        float f1;
        if (D_004E2918.field_0 > 1) {
            sp8C = func_00271A00((void *)((int)&D_004EE040 + s0), 0x7D9);
            f1 = 1.0f;
        } else {
            sp8C = func_00271A00((void *)((int)&D_004EE040 + s0), 0x7DA);
            f1 = 3.28083992f;
        }
        sp88 = (int)(self->field_C * f1);
        func_001A39E0(out, (void *)(s1), &sp88, &sp8C);
    } else if (flags & 8) {
        sprintf(buf50, D_004C7700, (double)self->field_C);
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf50, buf60, 16);
        sp84 = func_00271A00((void *)((int)&D_004EE040 + s0), 0x7DB);
        func_00364600(out, s1, buf60, &sp84);
    } else if (flags & 1) {
        if (flags & 2) {
            sp80 = self->field_8 * 180;
            func_001A3AA0(out, (void *)(s1), &sp80);
        } else {
            int v = self->field_8;
            switch (v) {
            case 2:
            case 3:
                Copy__10CGtUnicodeFPUsPCUs((unsigned short *)out, (const unsigned short *)func_00271A00((void *)((int)&D_004EE040 + s0), (&D_004C74C0[self->field_4].field_0)[v]));
                break;
            default:
                func_001A3AA0(out, (void *)(s1), &self->field_8);
                break;
            }
        }
    } else {
        Copy__10CGtUnicodeFPUsPCUs((unsigned short *)out, (const unsigned short *)s1);
    }
}

#pragma pop
