// func_003E9030 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (plain switch 0/1/2 setting three ints (declared count, offset, base); two stack locals (info, name buffer); GtIDCompress__FPCc(char*) returns 64-bit).

// func_003E9030 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003E9030_2;

struct UnkStruct_003E9030_2 {
    unsigned char pad_0[0x6];
    signed char field_6;
    signed char field_7;
    signed char field_8;
    signed char field_9;
    unsigned char pad_A[0x6];
};

extern unsigned long kaB3HardCodedCrashStageList[];  // [G] element count unknown
extern unsigned long kaB3HardCodedCrashCircuitList[];  // [G] element count unknown

extern "C" void func_0021ADF0(unsigned long, void *);
extern "C" unsigned long GtIDCompress__FPCc(char *);

// 0x003E9030
extern "C" int func_003E9030(int n0, int p0)
{
    int v5;
    int v4;
    int v3;
    switch (n0) {
    case 0:
        v4 = 0;
        v3 = 6;
        v5 = 3;
        break;
    case 1:
        v4 = 3;
        v3 = 8;
        v5 = 4;
        break;
    case 2:
        v4 = 7;
        v3 = 4;
        v5 = 3;
        break;
    }
    UnkStruct_003E9030_2 info;
    char name[0x10];
    func_0021ADF0(kaB3HardCodedCrashStageList[p0], &info);
    name[0] = info.field_6;
    name[1] = info.field_7;
    name[2] = 95;
    name[3] = info.field_8;
    name[4] = info.field_9;
    name[5] = 0;
    unsigned long r1 = GtIDCompress__FPCc(name);
    for (int i = 0; i < v5; i++) {
        if (r1 == kaB3HardCodedCrashCircuitList[i + v4]) {
            return i + v3;
        }
    }
    return -1;
}
