// SetFrontendFrameRate__7CB3GameFb -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (rewritten as nested if/else (nonzero first) with rate declared before freq; rate /= 2 in the p0 arm).

// lifter variant 0
// SetFrontendFrameRate__7CB3GameFb -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtPerfMon;
struct UnkStruct_D_004E2910;

struct UnkStruct_D_004E2910 {
    signed char field_0;
};

class CGtPerfMon {
public:
    static int meGameFrequency;
};

extern UnkStruct_D_004E2910 D_004E2910;

extern "C" void func_001F4290(int);
extern "C" int PrepareTimerServices__8CGtTimerFi(int);
extern "C" bool Prepare__8CGtTimerFv(void *);
extern "C" void Start__8CGtTimerFv(void *);

// 0x001D3EE0
extern "C" void SetFrontendFrameRate__7CB3GameFb(void *n0_, int p0)
{
    int n0 = (int)n0_;
    int rate;
    int freq;
    if (D_004E2910.field_0 != 0) {
        rate = 50;
        if (p0 != 0) {
            freq = 3;
        } else {
            freq = 1;
        }
    } else {
        rate = 60;
        if (p0 != 0) {
            freq = 2;
        } else {
            freq = 0;
        }
    }
    if (p0 != 0) {
        rate /= 2;
        func_001F4290(2);
    } else {
        func_001F4290(1);
    }
    CGtPerfMon::meGameFrequency = freq;
    PrepareTimerServices__8CGtTimerFi(rate);
    Prepare__8CGtTimerFv((void *)(n0 + 0x7040));
    Start__8CGtTimerFv((void *)(n0 + 0x7040));
}
