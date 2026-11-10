// func_00389600 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (near32: unsigned short n0 / bool p1 params, (unsigned short) re-casts inline per arm, neg assigned before whole in both arms, whole += frac in place).

// 0x00389600
extern "C" float func_00389600(unsigned short n0, signed char p0, bool p1)
{
    float whole;
    bool neg;
    if (p1) {
        neg = (n0 & 0x8000) == 0x8000;
        whole = (float)((unsigned short)((1 << (15 - p0)) - 1) & (n0 >> p0));
    } else {
        neg = false;
        whole = (float)((unsigned short)((1 << (16 - p0)) - 1) & (n0 >> p0));
    }
    unsigned int fr = (unsigned short)(n0 & ((1 << p0) - 1));
    whole += (float)fr / (float)(1 << p0);
    if (neg) whole = -whole;
    return whole;
}
