// Hand-written; the lifter refused it (i and c declared up top (i first), c zeroed after the flag reads).

// 0x0022D970
// [G] byte 0 holds flag bits 0/1 plus an xor checksum of the first n bytes; no DNAT row in new_names.csv
extern "C" void func_0022D970(unsigned char *p, int n)
{
    int i;
    unsigned char c;
    unsigned char b = p[0];
    unsigned char k0 = b & 1;
    unsigned char k1 = b & 2;
    p[0] = 0;
    c = 0;
    for (i = 0; i < n; i++) {
        c ^= p[i];
    }
    p[0] = c;
    p[0] &= 0xFE;
    p[0] |= k0;
    p[0] &= 0xFD;
    p[0] |= k1;
}
