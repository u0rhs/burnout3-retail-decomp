// func_00389700 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (rewritten: signed char shift, bool flags, unsigned short result built in two statements (r = ip<<n; r += frac part)).

extern "C" unsigned short func_00389700(signed char n0, bool p0, float f0)
{
    bool neg;
    int ip;
    float frac;
    if (f0 < 0.0f) {
        neg = 1;
        ip = -(int)f0;
        frac = -f0 - (float)ip;
    } else {
        neg = 0;
        ip = (int)f0;
        frac = f0 - (float)ip;
    }
    unsigned short r = (unsigned short)(ip << n0);
    r += (unsigned short)(int)(frac * (float)(1 << n0));
    if (p0) {
        if (neg) {
            r |= 0x8000;
        } else {
            r &= 0x7FFF;
        }
    }
    return r;
}
