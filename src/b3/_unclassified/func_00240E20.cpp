// func_00240E20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (n0 typed as a pointer (int arg made MWCC compute n0+32 before n0)).

// func_00240E20 -- tiny-function batch (tools/tiny_batch.py, lifted; hand-matched).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Every type is [G] (instruction widths).

extern "C" int func_0022FC10(void *, int);
extern "C" void func_0022FE10(void *, int, int, unsigned char *, unsigned char *, void *, void *, void *);

// 0x00240E20
// [L] n0 is a pointer: as an int, MWCC evaluates `n0 + 32` ahead of `n0` (retail passes them in order).
extern "C" void func_00240E20(unsigned char *n0, void *p0_)
{
    int p0 = (int)p0_;
    if (func_0022FC10((void *)(p0), 1) == 0) {
        func_0022FE10((void *)(p0), 1, 32, n0, n0 + 32, (void *)(0), (void *)(0), (void *)(0));
    }
}
