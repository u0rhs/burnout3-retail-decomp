// NONMATCHING: DecryptData__17CGtNetworkMessageFii -- retail 87 / ours 86 instructions, 19 in changed runs
// near38: real member CGtNetworkMessage::DecryptData (this = base), w as unsigned int* block pointer, XTEA round as a static inline (key term k computed first), scoped opt_lifetimes off [G] only: 71 -> 19. Left: retail keeps a separate q = w+4 store address in a0 (delta then lands in t6, key in a1); every q form (pointer, char+4, inline args) shifts all temps one register up (47-63); xor operand order in round 1
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

extern unsigned int D_01D6EDD0[4];
struct CGtNetworkMessage { void DecryptData(int, int); };
static inline void func_0022D480_inl1(unsigned int * a, unsigned int * b)
{
    unsigned int v0 = *a;
    unsigned int v1 = *b;
    unsigned int sum = 0xC6EF3720;
    while (sum != 0) {
        unsigned int k = sum + D_01D6EDD0[(sum >> 11) & 3];
        sum += 0x61C88647;
        v1 -= (((v0 << 4) ^ (v0 >> 5)) + v0) ^ k;
        v0 -= (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + D_01D6EDD0[sum & 3]);
    }
    *a = v0;
    *b = v1;
}
#pragma push
#pragma opt_lifetimes off
// 0x0022D480
void CGtNetworkMessage::DecryptData(int off, int len)
{
    unsigned char * data = (unsigned char *)this + off;
    unsigned char * p;
    unsigned char * end = data + len;
    int head = 0;
    p = data;
    if (((unsigned int)data & 3) != 0) {
        head = 4 - ((unsigned int)data & 3);
        for (int i = 0; i < head; i++) {
            *p++ ^= ((unsigned char *)D_01D6EDD0)[i];
        }
    }
    unsigned int * w = (unsigned int *)(data + head);
    while (((int)end - (int)w) / 4 >= 2) {
        func_0022D480_inl1(w, w + 1);
        w += 2;
    }
    p = (unsigned char *)w;
    for (int j = 0; p != end; j++) {
        *p++ ^= ((unsigned char *)D_01D6EDD0)[j];
    }
}
#pragma pop
