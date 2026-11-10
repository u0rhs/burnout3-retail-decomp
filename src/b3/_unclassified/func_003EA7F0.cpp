// Hand-written; the lifter refused it (FindTrack inlined; returns &D_004E2F08 (v0)).

extern const unsigned long kaB3HardCodedTrackList[];
extern signed char D_004E2F00;
extern float D_004E2F08;
extern float D_004E2F0C;
extern float D_004CCE60[];
extern float D_004CCE64[];

// 0x003EA7F0
extern "C" float *func_003EA7F0(unsigned long n0)
{
    int i = 0;
    goto test;
body:
    if (n0 == kaB3HardCodedTrackList[i]) goto found;
    i++;
test:
    if (i < 36) goto body;
    i = -1;
found:
    if (D_004E2F00 == 0) {
        D_004E2F00 = 1;
    }
    D_004E2F08 = D_004CCE60[i * 2];
    D_004E2F0C = D_004CCE64[i * 2];
    return &D_004E2F08;
}
