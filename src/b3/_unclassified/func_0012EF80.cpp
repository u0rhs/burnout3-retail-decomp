// func_0012EF80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (bool return of one && chain over implicit float->bool (!f() / f())).

// lifter variant 0
// func_0012EF80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern "C" float func_0012FC30(void *, int, int);

// 0x0012EF80
extern "C" bool func_0012EF80(int n0)
{
    return !func_0012FC30((void *)(n0), 0, 0) && func_0012FC30((void *)(n0), 1, 0) && !func_0012FC30((void *)(n0), 3, 0) && !func_0012FC30((void *)(n0), 8, 0) && !func_0012FC30((void *)(n0), 9, 0) && !func_0012FC30((void *)(n0), 10, 0) && func_0012FC30((void *)(n0), 11, 0) && !func_0012FC30((void *)(n0), 12, 0) && func_0012FC30((void *)(n0), 13, 0);
}
