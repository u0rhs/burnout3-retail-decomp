// func_004695A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (merged state 5/8 paths with ||; plain byte-pointer globals; self[i] ^= *cursor).

// func_004695A0 -- tiny-function batch (tools/tiny_batch.py, lifted; hand-finished).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Every type is [G] (instruction widths): D_004E2FD8 is a byte cursor that wraps from
// D_004E2FD4 (end) back to D_004E2FD0 (start); D_004E2668 a state value.

extern int D_004E2668;
extern unsigned char * D_004E2FD8;
extern unsigned char * D_004E2FD4;
extern unsigned char * D_004E2FD0;

// 0x004695A0
extern "C" int func_004695A0(unsigned char * self, unsigned int p0)
{
    if (self == 0 || p0 == 0) {
        return 2;
    }
    int t0 = D_004E2668;
    if (t0 == 5 || t0 == 8) {
        for (unsigned int i = 0; i < p0; i++) {
            self[i] ^= *D_004E2FD8;
            if (D_004E2FD8 == D_004E2FD4) {
                D_004E2FD8 = D_004E2FD0;
            } else {
                D_004E2FD8++;
            }
        }
        D_004E2668 = 8;
        return 0;
    }
    return t0;
}
