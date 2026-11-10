// IsChallengeOnThisCircuit__25CB3HardCodedRaceStageListF14EB3TrackRegionii -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (kaB3HardCodedRaceChallengeList declared const (its ld moves above the sq s0 save); 64-bit unsigned long GtIDCompress__FPCc/func_0021AC70 results compared with ==; ternary stage lookup as sibling IsCorrectRegion__25CB3HardCodedRaceStageListF14EB3TrackRegioni).

// from build/vt\try_func_003E9E50_best.cpp
// IsChallengeOnThisCircuit__25CB3HardCodedRaceStageListF14EB3TrackRegionii -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003E9E50_4;
struct UnkStruct_003E9E50_5;

struct UnkStruct_003E9E50_4 {
    unsigned long field_0;
};

struct UnkStruct_003E9E50_5 {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
    unsigned char field_4;
    unsigned char field_5;
    signed char field_6;
    signed char field_7;
    signed char field_8;
    signed char field_9;
    signed char field_A;
    signed char field_B;
    unsigned char pad_C[0x4];
};

extern const unsigned long kaB3HardCodedRaceChallengeList[];  // [G] element count unknown
extern UnkStruct_003E9E50_4 * kapGPChallengeStageArrays[];  // [G] element count unknown
extern unsigned long D_004CC370[];  // [G] element count unknown

extern "C" void func_0021ADF0(unsigned long, UnkStruct_003E9E50_5 *);
extern "C" unsigned long GtIDCompress__FPCc(UnkStruct_003E9E50_5 *, signed char, signed char, void *, signed char, void *, void *);
extern "C" unsigned long func_0021AC70(unsigned long, int);

// 0x003E9E50
extern "C" bool IsChallengeOnThisCircuit__25CB3HardCodedRaceStageListF14EB3TrackRegionii(int n0, int p0, int p1)
{
    UnkStruct_003E9E50_5 local;  // [G] the frame's one local (size: up to the frame top)
    unsigned long t0 = kaB3HardCodedRaceChallengeList[p0];
    unsigned long v0 = t0 < 7 ? kapGPChallengeStageArrays[(int)t0]->field_0 : t0;
    func_0021ADF0(v0, &local);
    signed char t1 = local.field_6;
    signed char t2 = local.field_7;
    signed char t3 = local.field_8;
    signed char t4 = local.field_9;
    local.field_2 = 95;
    local.field_5 = 95;
    local.field_0 = t1;
    signed char t5 = local.field_A;
    signed char t6 = local.field_B;
    local.field_1 = t2;
    local.field_3 = t3;
    local.field_4 = t4;
    local.field_8 = 0;
    local.field_6 = t5;
    local.field_7 = t6;
    unsigned long r1 = GtIDCompress__FPCc(&local, t4, t3, ((char *)&local + 0x8), t2, ((char *)&local + 0x7), ((char *)&local + 0x6));
    unsigned long r2 = func_0021AC70(r1, 7);
    unsigned long r3 = func_0021AC70(r2, -7);
    int v3;
    switch (n0) {
    case 0:
        v3 = 0;
        break;
    case 1:
        v3 = 6;
        break;
    case 2:
        v3 = 14;
        break;
    default:
        v3 = 0;
        break;
    }
    return r3 == D_004CC370[p1 + v3];
}
