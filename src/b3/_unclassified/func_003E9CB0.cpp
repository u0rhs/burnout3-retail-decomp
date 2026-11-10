// func_003E9CB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (phantom args dropped (func_0021ADF0/GtIDCompress__FPCc real prototypes, u64 returns); char buf; ternary id select; two inline switch helpers for base/count).

// lifter variant 0
// func_003E9CB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003E9CB0_4;

struct UnkStruct_003E9CB0_4 {
    unsigned long field_0;
};

extern unsigned long kaB3HardCodedRaceChallengeList[];  // [G] element count unknown
extern UnkStruct_003E9CB0_4 * kapGPChallengeStageArrays[];  // [G] element count unknown
extern unsigned long D_004CC370[];  // [G] element count unknown

extern "C" void func_0021ADF0(unsigned long, char *);
extern "C" unsigned long GtIDCompress__FPCc(const char *);  // [L] reads only a0 (unit_0021AD60.s); returns 64-bit
extern "C" unsigned long func_0021AC70(unsigned long, int);

static inline int func_003E9CB0_inl1(int n)  // [G] inlined helper (name unknown)
{
    int r;
    switch (n) {
    case 0:
        r = 0;
        break;
    case 1:
        r = 6;
        break;
    case 2:
        r = 14;
        break;
    default:
        r = 0;
        break;
    }
    return r;
}

static inline int func_003E9CB0_inl2(int n)  // [G] inlined helper (name unknown)
{
    int r;
    switch (n) {
    case 0:
        r = 6;
        break;
    case 1:
        r = 8;
        break;
    case 2:
        r = 4;
        break;
    default:
        r = 0;
        break;
    }
    return r;
}

// 0x003E9CB0
extern "C" int func_003E9CB0(int n0, int p0)
{
    char buf[16];  // [G] name buffer; size from the frame
    unsigned long t0 = kaB3HardCodedRaceChallengeList[p0];
    unsigned long id = (t0 < 7) ? kapGPChallengeStageArrays[(int)t0]->field_0 : t0;
    func_0021ADF0(id, buf);
    buf[0] = buf[6];
    buf[1] = buf[7];
    buf[2] = '_';
    buf[3] = buf[8];
    buf[4] = buf[9];
    buf[5] = '_';
    buf[6] = buf[10];
    buf[7] = buf[11];
    buf[8] = 0;
    unsigned long h = func_0021AC70(func_0021AC70(GtIDCompress__FPCc(buf), 7), -7);
    int base = func_003E9CB0_inl1(n0);
    for (int i = 0; i < func_003E9CB0_inl2(n0); i++) {
        if (h == D_004CC370[base + i]) {
            return i;
        }
    }
    return -1;
}
