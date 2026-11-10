// func_0035F240 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (N182 [G] scoped opt_repositioncode off + goto-form out-of-line return blocks; was 7 off).


// lifter variant 0
// func_0035F240 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_0035F240_0;

struct UnkStruct_0035F240_0 {
    u_long128 field_0;
    u_long128 field_10;
};

extern "C" int HLBListGetBuddyByName(int, int);
extern "C" int HLBBudIsBlocked(int);
extern "C" int func_004190D8(int);
extern "C" int func_00419048(int);
extern "C" int func_00419060(int);
extern "C" int func_00418FA8(int);
extern "C" int strcasecmp(int, int);

// 0x0035F240
static inline int func_0035F240_rank(bool blocked, bool x, bool y, bool z, bool w)
{
    if (blocked) return 1;
    if (x || y) return 5;
    if (z) return 2;
    if (w) return 3;
    return 4;
}
// N182: [G] scoped to this function
#pragma push
#pragma opt_repositioncode off
extern "C" int func_0035F240(int n0, int p0, int p1, int p2)
{
    int a = HLBListGetBuddyByName(n0, p1);
    int b = HLBListGetBuddyByName(n0, p2);
    if (a == 0) goto retm1;
    if (b == 0) goto ret1;
    {
    bool blkA = HLBBudIsBlocked(a) == 1;
    bool a0 = func_004190D8(a) == 0;
    bool a1 = func_00419048(a) == 1;
    bool a2 = func_00419060(a) == 1;
    bool a3 = func_00418FA8(a) == 1;
    bool blkB = HLBBudIsBlocked(b) == 1;
    bool b0 = func_004190D8(b) == 0;
    bool b1 = func_00419048(b) == 1;
    bool b2 = func_00419060(b) == 1;
    bool b3 = func_00418FA8(b) == 1;
    int ra = func_0035F240_rank(blkA, a1, a3, a2, a0);
    int rb = func_0035F240_rank(blkB, b1, b3, b2, b0);
    if (ra != rb) goto diff;
    if (!blkA) goto l424;
l3f4:
    if (blkA) goto sc;
    if (!a0) goto sc;
    if (b0) goto sc;
    return 1;
retm1:
    return -1;
ret1:
    return 1;
l424:
    if (a0) goto l3f4;
    if (!b0) goto l3f4;
    return -1;
sc:
    return strcasecmp(p1, p2);
diff:
    return rb - ra;
    }
}

#pragma pop
