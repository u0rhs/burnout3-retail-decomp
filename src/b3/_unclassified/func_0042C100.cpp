// Hand-written; the lifter refused it (pminw/pextlw asm helpers (as B3AIDriver_001446B0), padded D_01E8EBDE (N51)).

struct UnkStruct_a167_c { unsigned char pad_0[0xA0]; unsigned char field_A0; };
struct UnkStruct_a167_b { unsigned char pad_0[0x60]; UnkStruct_a167_c * field_60; };
struct UnkStruct_a167_a { UnkStruct_a167_b * field_0; unsigned char pad_4[0x2460 - 4]; };
struct UnkStruct_a167_g { signed char value; unsigned char pad[0x100]; };
extern UnkStruct_a167_g D_01E8EBDE;
extern UnkStruct_a167_a D_00652390[];
static inline int a167_pminw(int a, int b) { int r; asm("pminw %0,%1,%2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline int a167_pextlw0(int a) { int r; asm("pextlw %0,$0,%1" : "=r"(r) : "r"(a)); return r; }
// 0x0042C100
extern "C" bool func_0042C100(void *a0 /* passed by every caller, not read here */)
{
    int i = D_01E8EBDE.value;
    if (i == -1) return false;
    int n = D_00652390[i].field_0->field_60->field_A0;
    return a167_pextlw0(a167_pminw(n, 6)) >= 2;
}
