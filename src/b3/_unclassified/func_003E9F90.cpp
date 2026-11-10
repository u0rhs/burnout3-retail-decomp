// IsCorrectRegion__25CB3HardCodedRaceStageListF14EB3TrackRegioni -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (ternary for the stage-array lookup; early returns; phantom args dropped from GtIDUnCompress (func_0021ADF0)).

// IsCorrectRegion__25CB3HardCodedRaceStageListF14EB3TrackRegioni -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3HardCodedTrackList;
struct UnkStruct_003E9F90_4;
struct UnkStruct_003E9F90_5;

class CB3HardCodedTrackList {
public:
    static int FindTrack(unsigned long);
};

struct UnkStruct_003E9F90_4 {
    unsigned long field_0;
};

struct UnkStruct_003E9F90_5 {
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

extern unsigned long kaB3HardCodedRaceChallengeList[];  // [G] element count unknown
extern UnkStruct_003E9F90_4 * kapGPChallengeStageArrays[];  // [G] element count unknown

extern "C" void func_0021ADF0(unsigned long, UnkStruct_003E9F90_5 *);
extern "C" unsigned long GtIDCompress__FPCc(UnkStruct_003E9F90_5 *, signed char, signed char, void *, signed char, void *, void *);
extern "C" int func_003EAA60(void *);

extern "C" int IsCorrectRegion__25CB3HardCodedRaceStageListF14EB3TrackRegioni(int n0, int p0)
{
    UnkStruct_003E9F90_5 local;  // [G] the frame's one local (size: up to the frame top)
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
    int r = func_003EAA60((void *)(CB3HardCodedTrackList::FindTrack(GtIDCompress__FPCc(&local, t4, t3, ((char *)&local + 0x8), t2, ((char *)&local + 0x7), ((char *)&local + 0x6)))));
    if (n0 == r) {
        return 1;
    }
    return 0;
}
