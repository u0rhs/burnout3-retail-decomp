// func_003F5800 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern "C" int IsCorrectRegion__25CB3HardCodedRaceStageListF14EB3TrackRegioni(int, int);
extern "C" int func_0013AD70(void *, int, int);
extern "C" int IsCorrectRegion__26CB3HardCodedCrashStageListF14EB3TrackRegioni(int, int);

// 0x003F5800
extern "C" int func_003F5800(int n0, int p0)
{
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        int r0 = IsCorrectRegion__25CB3HardCodedRaceStageListF14EB3TrackRegioni(n0, i);
        if (r0 != 0) {
            int r1 = func_0013AD70((void *)(p0), i, 1);
            if (r1 != 0) {
                goto loop0_next;
            }
            return 1;
        }
    }
loop0_next:
    i++;
loop0_test:
    if (i < 73) goto loop0_body;
    int i1 = 0;
    goto loop1_test;
loop1_body:
    {
        int r2 = IsCorrectRegion__26CB3HardCodedCrashStageListF14EB3TrackRegioni(n0, i1);
        if (r2 != 0) {
            int r3 = func_0013AD70((void *)(p0), i1, 0);
            if (r3 != 0) {
                goto loop1_next;
            }
            return 1;
        }
    }
loop1_next:
    i1++;
loop1_test:
    if (i1 < 100) goto loop1_body;
    return 0;
}
