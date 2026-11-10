// NONMATCHING: func_0022D5E0 -- retail 95 / ours 94 instructions, 55 in changed runs
// a226: 'if (c) do {..} while (c)' reproduces retail's duplicated entry test (95 vs 94 instrs); left: n/end/q registers (retail t0/t1/t2, ours t2/a2/t1; declaration order has no effect), key base re-materialisation
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_0022D5E0 -- retail 95 / ours 87 instructions, 56 in changed runs
// TEA/XTEA cipher logic right (head bytes, 8-byte 32-round blocks, tail bytes); retail 95 vs ours 87: retail re-materialises the D_01D6EDD0 lui/addiu base in each of three regions (head, middle, tail), ours CSEs the lui; register assignment also differs
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

struct UnkStruct_D_01D6EDD0 {
    unsigned int field_0[4];
    unsigned int field_10[4];
};
extern UnkStruct_D_01D6EDD0 D_01D6EDD0;

static inline void func_0022D5E0_inl1(unsigned char *q, int n)
{
    const unsigned char *k = (const unsigned char *)&D_01D6EDD0;
    int i;
    for (i = 0; i < n; i++) {
        *q++ ^= k[i];
    }
}

static inline void func_0022D5E0_inl2(unsigned char *q, unsigned char *end)
{
    const unsigned char *k = (const unsigned char *)&D_01D6EDD0;
    int i = 0;
    while (q != end) {
        *q++ ^= k[i];
        i++;
    }
}

// 0x0022D5E0
// [G] TEA/XTEA-style cipher over buf+off, len bytes: unaligned head and tail bytes XORed with key bytes, 8-byte blocks run 32 rounds (delta 0x9E3779B9)
extern "C" void func_0022D5E0(unsigned char *buf, int off, int len)
{
    unsigned char *p = buf + off;
    int n = 0;
    unsigned char *end = p + len;
    unsigned char *q = p;
    if ((((unsigned int)p) & 3) != 0) {
        n = 4 - (((unsigned int)p) & 3);
        func_0022D5E0_inl1(q, n);
    }
    q = p + n;
    const unsigned int *key = D_01D6EDD0.field_0;
    if (((int)(end - q)) / 4 >= 2) do {
        unsigned int v0 = ((unsigned int *)q)[0];
        unsigned int v1 = ((unsigned int *)q)[1];
        unsigned int sum = 0;
        while (sum != 0xC6EF3720) {
            v0 += (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key[sum & 3]);
            sum += 0x9E3779B9;
            v1 += (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key[(sum >> 11) & 3]);
        }
        ((unsigned int *)q)[0] = v0;
        ((unsigned int *)q)[1] = v1;
        q += 8;
    } while (((int)(end - q)) / 4 >= 2);
    func_0022D5E0_inl2(q, end);
}

