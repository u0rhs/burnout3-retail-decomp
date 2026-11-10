// NONMATCHING: GenerateProfile__11CB3AIDriverFv -- retail 227 / ours 228 instructions, 96 in changed runs
// a137: 228 vs 227 instrs, 96 changed; all three modes + lerp (adda.s/madd.s via 'float r = 0.0f + C; r += t*(A-C)'), unsigned-vs-int float conversions ((float)(int)u8 for 4 of 5), A12=(x&1)==1 solved. Left: register choice of temps (v1 vs a0 / t-regs) and retail's held &D_0064D344 in t1 (lui/addiu) — a 'T* const pd = &D_0064D344' local moved it into s0 and broke the frame
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_GP_e { unsigned char pad_0[4]; float field_4; float field_8; float field_C; };
struct UnkStruct_GP_t { unsigned char pad_0[0x10]; unsigned int field_10; unsigned char pad_14[0xC]; UnkStruct_GP_e arr[1]; };
struct UnkStruct_D_0064D344 { UnkStruct_GP_t *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_GP_o {
    unsigned char pad_0[0x1B0];
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C();
    virtual int vfunc_20();
};
struct UnkStruct_D_0051BA88 { UnkStruct_GP_o *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_GP_p {
    unsigned char pad_0[0x10]; float tbl10[16]; float tbl50[16];
    unsigned char field_90; unsigned char field_91; unsigned char field_92; unsigned char field_93;
    unsigned char pad_94; signed char field_95; signed char field_96; unsigned char field_97;
};
struct UnkStruct_D_0064D350 { UnkStruct_GP_p *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064D360 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_GP_car { unsigned char pad_0[0x19AC]; signed char field_19AC; unsigned char pad_19AD[0xA93]; int field_2440; };
struct UnkStruct_D_float16 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004E0E24 { float field_0; };
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0064D344 D_0064D344;
extern UnkStruct_D_0064D350 D_0064D350;
extern UnkStruct_D_0064D360 D_0064D360;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_float16 D_01E754EC;
extern UnkStruct_D_float16 D_01E754F0;
extern UnkStruct_D_004E0E24 D_004E0E24;
extern UnkStruct_D_004EE040 D_004EE040;
extern "C" int func_00131E40(void *);
class CB3AIDriver {
public:
    void GenerateProfile();
    unsigned char pad_0[0x7A0];
    UnkStruct_GP_car *field_7A0;
    unsigned char pad_7A4[0x1C];
    float field_7C0[2][8][8];
    float field_9C0[8];
    float field_9E0;
    float field_9E4;
    float field_9E8;
    float field_9EC;
    float field_9F0;
    float field_9F4;
    int field_9F8;
    unsigned char pad_9FC[0x16];
    bool field_A12;
};
void CB3AIDriver::GenerateProfile()
{
    int i;
    unsigned int j;
    if (field_7A0->field_2440 == 1) {
        field_9E8 = 1.0f;
        field_9EC = 1.0f;
        field_9F0 = 1.0f;
        field_9F4 = 1.0f;
        field_9E0 = 1.0f;
        field_A12 = false;
        field_9F8 = 2;
        float big = 100000;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < D_0064D344.field_0->field_10; j++) {
                field_7C0[0][j][i] = 0;
                field_7C0[1][j][i] = big;
            }
        }
        return;
    }
    if (D_0064D344.field_0 == 0) return;
    if (D_0064D350.field_0 != 0 && field_7A0->field_19AC < D_0064D360.field_0) {
        UnkStruct_GP_p *p = (UnkStruct_GP_p *)((char *)D_0064D350.field_0 + field_7A0->field_19AC * 0x98);
        field_9E4 = (float)p->field_97 / 100.0f;
        field_9E8 = (float)(int)p->field_93 / 100.0f;
        field_9EC = (float)(int)p->field_90 / 100.0f;
        field_9F0 = (float)(int)p->field_92 / 100.0f;
        field_9F4 = (float)(int)p->field_91 / 100.0f;
        field_9E0 = field_9EC;
        field_9F8 = p->field_95;
        field_A12 = (p->field_96 & 1) == 1;
        int n = D_0051BA88.field_0->vfunc_20();
        if (n == 0) n = 1;
        unsigned int tot = n * D_0064D344.field_0->field_10;
        float z = 0.0f;
        for (i = 0; i < n; i++) {
            for (j = 0; j < D_0064D344.field_0->field_10; j++) {
                UnkStruct_GP_e *e = &D_0064D344.field_0->arr[j];
                unsigned int idx = ((j + i * D_0064D344.field_0->field_10) * 16) / tot;
                float r1 = 0.0f + e->field_C;
                r1 += p->tbl50[idx] * (e->field_8 - e->field_C);
                field_7C0[0][j][i] = r1;
                e = &D_0064D344.field_0->arr[j];
                float r2 = 0.0f + e->field_C;
                r2 += p->tbl10[idx] * (e->field_8 - e->field_C);
                field_7C0[1][j][i] = r2;
            }
        }
    } else {
        func_00131E40(&D_004EE040);
        field_9E8 = 0;
        field_9EC = 0;
        field_9F0 = D_004E0E24.field_0;
        field_9F4 = 1.0f;
        field_9E0 = 0;
        field_9F8 = 1;
        field_A12 = false;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < D_0064D344.field_0->field_10; j++) {
                UnkStruct_GP_e *e = &D_0064D344.field_0->arr[j];
                field_7C0[0][j][i] = e->field_4 / D_01E754EC.field_0;
                field_7C0[1][j][i] = e->field_4 / D_01E754F0.field_0;
            }
        }
    }
}
