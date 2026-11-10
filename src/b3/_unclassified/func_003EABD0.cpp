// func_003EABD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (inverted inner test (t0 <= p0 first), early-return tail, counter declared before the min/max).

// lifter variant 0
// func_003EABD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern int D_004CD4D0[];  // [G] element count unknown
extern int D_004CD5E0[];  // [G] element count unknown

// 0x003EABD0
extern "C" int func_003EABD0(int n0, int p0, int p1)
{
    int i;
    int m1 = -1;
    int m0 = 0x7FFFFFFF;
    for (i = 0; (i < 67); i++) {
        if (p1 == D_004CD4D0[i]) {
            int t0 = D_004CD5E0[i];
            if (n0 < t0) {
                if (t0 <= p0) {
                    if (m1 < t0) {
                        m1 = t0;
                    }
                } else {
                    if (t0 < m0) {
                        m0 = t0;
                    }
                }
            }
        }
    }
    if (m1 > 0) {
        return m1;
    }
    if (m0 != 0x7FFFFFFF) {
        return m0;
    }
    m0 = -1;
    return m0;
}
