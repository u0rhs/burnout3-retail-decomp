// func_003EAF00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (range-checked table read as a static inline helper (n==-1||n>=67 -> 0), outer guard with ||, t==1||t==2 call arm first).

// lifter variant 0
// func_003EAF00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern int D_004CD4D0[];  // [G] element count unknown
extern int D_004CD5E0[];  // [G] element count unknown
extern unsigned long D_004CDB30[];  // [G] element count unknown

extern "C" int FindChallengeIndex__25CB3HardCodedRaceStageListFUl(unsigned long);

static inline int func_003EAF00_inl1(int n)
{
    if (n == -1 || n >= 67) {
        return 0;
    }
    return D_004CD4D0[n];
}

// 0x003EAF00
extern "C" int func_003EAF00(int n0)
{
    if (n0 == -1 || n0 >= 67) {
        return 0;
    }
    int t = func_003EAF00_inl1(n0);
    if (t == 1 || t == 2) {
        return FindChallengeIndex__25CB3HardCodedRaceStageListFUl(D_004CDB30[D_004CD5E0[n0]]);
    }
    return D_004CD5E0[n0];
}
