// func_00135BE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (plain for loops with && chains; gCalculatedData+0x11C reached by byte-offset cast (same layout as D_0051BFA0)).

struct UnkStruct_D_0051BFA0;
struct UnkStruct_gCalculatedData;

struct UnkStruct_D_0051BFA0 {
    unsigned char pad_0[0x57];
    unsigned char field_57[73];  // [G] element count from the loop bound
    unsigned char field_A0[100];  // [G] element count from the loop bound
};

struct UnkStruct_gCalculatedData {
    unsigned char pad_0[0x11C];
    UnkStruct_D_0051BFA0 field_11C;  // [G] same layout as D_0051BFA0 (field_57/field_A0 indexed alike)
};

extern UnkStruct_D_0051BFA0 D_0051BFA0;
extern UnkStruct_gCalculatedData gCalculatedData;

extern "C" int func_003E8E60(int);
extern "C" int func_00135F30(void *, int, int);
extern "C" int IsCorrectRegion__26CB3HardCodedCrashStageListF14EB3TrackRegioni(int, int);
extern "C" int func_003E96E0(int);
extern "C" int func_00136110(void *, int, int);
extern "C" int IsCorrectRegion__25CB3HardCodedRaceStageListF14EB3TrackRegioni(int, int);

// 0x00135BE0
extern "C" int func_00135BE0(void *n0, int p0, int p1)
{
    if (p1 != 0) {
        int m = -1;
        int i;
        for (i = 0; i < 100; i++) {
            if (D_0051BFA0.field_A0[i] != 0) {
                if (m < func_003E8E60(i)) {
                    m = func_003E8E60(i);
                }
            }
        }
        for (i = 0; i < 100; i++) {
            if (func_00135F30((void *)(n0), i, m) != 0 && IsCorrectRegion__26CB3HardCodedCrashStageListF14EB3TrackRegioni(p0, i) != 0 &&
                ((UnkStruct_D_0051BFA0 *)((char *)&gCalculatedData + 0x11C))->field_A0[i] == 0) {
                return 1;
            }
        }
    } else {
        int m = -1;
        int i;
        for (i = 0; i < 73; i++) {
            if (D_0051BFA0.field_57[i] != 0) {
                if (m < func_003E96E0(i)) {
                    m = func_003E96E0(i);
                }
            }
        }
        for (i = 0; i < 73; i++) {
            if (func_00136110((void *)(n0), i, m) != 0 && IsCorrectRegion__25CB3HardCodedRaceStageListF14EB3TrackRegioni(p0, i) != 0 &&
                ((UnkStruct_D_0051BFA0 *)((char *)&gCalculatedData + 0x11C))->field_57[i] == 0) {
                return 1;
            }
        }
    }
    return 0;
}
