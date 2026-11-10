// func_003E8EA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (declaration order: i (uninitialised) first, then m0 = 0, then r0 = call).

// from build/vt\try_func_003E8EA0_best.cpp
// func_003E8EA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3TrackRegion {};

class CB3HardCodedCrashStageList;

class CB3HardCodedCrashStageList {
public:
    static int IsChallengeOnThisCircuit(EB3TrackRegion, int, int);
};

extern "C" int func_00136380(int);
extern "C" int IsCorrectRegion__26CB3HardCodedCrashStageListF14EB3TrackRegioni(int, int);
extern "C" int func_0013AD70(void *, int, int);
extern "C" int func_0013AD30(void *, int, int);
extern "C" int func_00135F30(void *, int, int);

// 0x003E8EA0
extern "C" int func_003E8EA0(int n0, int p0, void *p1_)
{
    int p1 = (int)p1_;
    int i;
    int m0 = 0;
    int r0 = func_00136380(p1);
    for (i = 0; (i < 100); i++) {
        int r1 = IsCorrectRegion__26CB3HardCodedCrashStageListF14EB3TrackRegioni(n0, i);
        if (r1 != 0) {
            int r2 = CB3HardCodedCrashStageList::IsChallengeOnThisCircuit((EB3TrackRegion)n0, i, p0);
            if (r2 != 0) {
                int r3 = func_0013AD70((void *)(p1), i, 0);
                if (r3 == 0) {
                    int r4 = func_0013AD30((void *)(p1), i, 0);
                    if (r4 > 0) {
                        if (m0 == 0) {
                            m0 = 4;
                        }
                    } else {
                        int r5 = func_00135F30((void *)(p1), i, r0);
                        if (r5 != 0) {
                            m0 = 2;
                        } else {
                            if (m0 != 2) {
                                m0 = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return m0;
}
