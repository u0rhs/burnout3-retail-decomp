// FindLocalStageIndex__25CB3HardCodedRaceStageListFUli -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (bool found + break search; i declared first; p0=-1; return p0).

// lifter variant 0
// FindLocalStageIndex__25CB3HardCodedRaceStageListFUli -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern unsigned long kaB3HardCodedRaceChallengeList[];  // [G] element count unknown
extern int kanGPChallengeStageNumber[];  // [G] element count unknown
extern unsigned long * kapGPChallengeStageArrays[];  // [G] element count unknown

// 0x003EA2D0
extern "C" int FindLocalStageIndex__25CB3HardCodedRaceStageListFUli(unsigned long n0, int p0)
{
    int i;
    unsigned long t0 = kaB3HardCodedRaceChallengeList[p0];
    bool found = false;
    if (t0 < 7) {
        int id = (int)t0;
        for (i = 0; i < kanGPChallengeStageNumber[id]; i++) {
            if (n0 == kapGPChallengeStageArrays[id][i]) {
                found = true;
                break;
            }
        }
    } else if (t0 == n0) {
        found = true;
    }
    if (found) {
        return p0;
    }
    p0 = -1;
    return p0;
}
