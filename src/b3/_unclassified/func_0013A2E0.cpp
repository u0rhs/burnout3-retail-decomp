// func_0013A2E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (p0 advanced in place in a for(;;) with top test; counters declared before accumulators (fresh pair for the second loop); gCalculatedData+0x11C byte-offset cast).

struct UnkStruct_D_0051BFA0;
struct UnkStruct_gCalculatedData;

struct UnkStruct_D_0051BFA0 {
    unsigned char pad_0[0x43];
    unsigned char field_43[20];  // [G] element count from the loop bound
};

struct UnkStruct_gCalculatedData {
    unsigned char pad_0[0x11C];
    UnkStruct_D_0051BFA0 field_11C;  // [G] same layout as D_0051BFA0 (field_43 indexed alike)
};

extern UnkStruct_D_0051BFA0 D_0051BFA0;
extern UnkStruct_gCalculatedData gCalculatedData;

extern "C" int func_003F5FF0(int);

// 0x0013A2E0
extern "C" int func_0013A2E0(void *n0_, int p0)
{
    int n0 = (int)n0_;
    p0++;
    for (;;) {
        if (!(p0 < 4)) {
            return -1;
        }
        int i;
        int n = 0;
        for (i = 0; i < 20; i++) {
            if (p0 == func_003F5FF0(i) && D_0051BFA0.field_43[i] != 0) {
                n++;
            }
        }
        if (n >= 5) {
            int j;
            int n2 = 0;
            for (j = 0; j < 20; j++) {
                if (p0 == func_003F5FF0(j) && ((UnkStruct_D_0051BFA0 *)((char *)&gCalculatedData + 0x11C))->field_43[j] != 0) {
                    n2++;
                }
            }
            if (n2 < 5) {
                return p0;
            }
        }
        p0++;
    }
}
