// Hand-written; the lifter refused it (near16: scoped opt_removeemptyloops off [G] + entry-jump goto empty loop i<=2 (MWCC tiny-loop nop padding)).

struct UnkStruct_00465EB0_g {
    unsigned char pad_0[0xD4];
    int field_D4;
    void * field_D8;
    int field_DC;
    int field_E0;
    int field_E4;
    int field_E8;
    void * field_EC;
    int field_F0;
    int field_F4;
    int field_F8;
    int field_FC;
    int field_100;
    int field_104;
    int field_108;
};
struct UnkStruct_D_004E2FC4_a { UnkStruct_00465EB0_g * field_0; };
extern UnkStruct_D_004E2FC4_a D_004E2FC4;
extern "C" void func_00466670(void *, void *);
extern "C" int func_00466DA0(int *);

// N182 [G] scoped to this function: retail keeps an empty counted loop (move a3,0; b test; addiu; slti at; 3 nops = MWCC
// tiny-loop padding; bnez) that opt_removeemptyloops would delete. Entry-jump goto form (N24) + `<= 2` gives slti at.
#pragma push
#pragma opt_removeemptyloops off
// 0x00465EB0
extern "C" int func_00465EB0(int p0)
{
    D_004E2FC4.field_0->field_D4 = p0;
    D_004E2FC4.field_0->field_108 = D_004E2FC4.field_0->field_D4;
    UnkStruct_00465EB0_g * p = D_004E2FC4.field_0;
    int s = p->field_D4;
    int v = 0;
    if (s == 3 || s == 2 || s == 1 || s == 0) goto known;
    v = 0xF;
common:
    D_004E2FC4.field_0->field_DC = 9;
    D_004E2FC4.field_0->field_EC = (void *)&func_00466670;
    D_004E2FC4.field_0->field_E0 = 0;
    D_004E2FC4.field_0->field_E4 = 0;
    D_004E2FC4.field_0->field_E8 = 0;
    D_004E2FC4.field_0->field_F0 = 4;
    { int i = 0; goto t; l: i++; t: if (i <= 2) goto l; }
    D_004E2FC4.field_0->field_F4 = 0;
    D_004E2FC4.field_0->field_F8 = 0;
    D_004E2FC4.field_0->field_FC = 0;
    D_004E2FC4.field_0->field_100 = 0;
    D_004E2FC4.field_0->field_104 = 0;
    return v;
known:
    p->field_D8 = (void *)&func_00466DA0;
    goto common;
}
#pragma pop
