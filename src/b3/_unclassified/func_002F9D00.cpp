// Destroy__15CGtLinearMallocFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (field_4 void* (pointer-vs-int), dropped phantom callback args a1/a2).

// lifter variant 0
// Destroy__15CGtLinearMallocFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtLinearMalloc;
struct UnkStruct_002F9D00;
struct UnkStruct_002F9D00_2;
struct UnkStruct_D_01E86D50;
struct UnkStruct_D_01E86D54;
struct UnkStruct_D_01E86D58;
struct UnkStruct_D_01E86D5C;
struct UnkStruct_ourGlobals;

struct UnkStruct_D_01E86D50 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_002F9D00_2 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

struct UnkStruct_D_01E86D54 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E86D58 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E86D5C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_ourGlobals {
    unsigned char pad_0[0x138];
    int field_138;
};

class CGtLinearMalloc {
public:
    static int mpActiveRWAllocator;
};

struct UnkStruct_002F9D00 {
    unsigned char field_0;
    unsigned char pad_1[0x3];
    void * field_4;
    int field_8;
    int field_C;
    int field_10;
};

extern UnkStruct_D_01E86D50 D_01E86D50;
extern UnkStruct_D_01E86D54 D_01E86D54;
extern UnkStruct_D_01E86D58 D_01E86D58;
extern UnkStruct_D_01E86D5C D_01E86D5C;
extern UnkStruct_ourGlobals ourGlobals;

extern "C" UnkStruct_002F9D00_2 * RwOsGetMemoryInterface();

// 0x002F9D00
extern "C" void Destroy__15CGtLinearMallocFv(UnkStruct_002F9D00 * self)
{
    if ((int)self == CGtLinearMalloc::mpActiveRWAllocator) {
        UnkStruct_002F9D00_2 * r0 = RwOsGetMemoryInterface();
        r0->field_0 = D_01E86D50.field_0;
        r0->field_4 = D_01E86D54.field_0;
        r0->field_8 = D_01E86D58.field_0;
        r0->field_C = D_01E86D5C.field_0;
        CGtLinearMalloc::mpActiveRWAllocator = 0;
    }
    if (self->field_4 != 0) {
        ((void (*)(void *))ourGlobals.field_138)(self->field_4);
        self->field_4 = 0;
    }
    self->field_8 = 0;
    self->field_C = 0;
    self->field_10 = 0;
    self->field_0 = 0;
}
