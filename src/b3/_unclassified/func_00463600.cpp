// func_00463600 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (archived source + goto-form join + scoped opt_optimizecontrolflow off [G]).

// func_00463600 -- placeholder (s315; sibling func_004636E0 shape, archived source + scoped pragma).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Every type is [G] (instruction widths).
extern "C" void func_004652B0(int, void *, void *);
extern "C" void func_00360AC0(int, int, int, int);
// N182: [G] scoped to this function: opt_optimizecontrolflow off + the goto-form join give retail's
// shared return block (`b L; daddu v0,zero` / `li v0,4` falling into the epilogue).
#pragma push
#pragma opt_optimizecontrolflow off
// 0x00463600
extern "C" int func_00463600(char *n0, int p0, int p1, int p2)
{
    int a = 4, b = 1;
    func_004652B0(p2, &a, &b);
    int c = 4, d = 1;
    func_004652B0(p2, &c, &d);
    unsigned int x = p1 + 12;
    unsigned int t0 = d;
    unsigned int v0;
    if (x < t0) v0 = t0; else v0 = x + (t0 - x % t0) % t0;
    int r;
    if (n0 != 0) { func_00360AC0(p0, (int)(n0 - 12), v0, a); r = 0; goto done; }
    r = 4;
done:
    return r;
}
#pragma pop
