// func_003392C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003392C0;
struct UnkStruct_003392C0_1;
struct UnkStruct_003392C0_a2;

struct UnkStruct_003392C0_1 {
    unsigned char pad_0[0x24];
    int field_24;
};

struct UnkStruct_003392C0_a2 {
    int field_0;
};

struct UnkStruct_003392C0 {
    unsigned char pad_0[0x56C];
    int field_56C;
};

extern "C" void DispListOrder(int);
extern "C" int func_0040A5D0(int);
extern "C" UnkStruct_003392C0_1 * DispListIndex(int, int);
extern "C" int strcasecmp(int, void *);

// 0x003392C0
extern "C" int func_003392C0(UnkStruct_003392C0 * self, int p0, UnkStruct_003392C0_a2 * p1)
{
    DispListOrder(self->field_56C);
    for (int i = 0; (i < func_0040A5D0(self->field_56C)); i++) {
        UnkStruct_003392C0_1 * r1 = DispListIndex(self->field_56C, i);
        if (r1 == 0) {
            continue;
        }
        int r2 = strcasecmp(p0, ((char *)r1 + 0x8));
        if (r2 != 0) {
            continue;
        }
        p1->field_0 = r1->field_24;
        return 1;
    }
    return 0;
}
