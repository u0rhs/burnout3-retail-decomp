// CGtLinearMalloc::~CGtLinearMalloc() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLinearMalloc.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a72: dtor as extern C __dt (this, short flag): Destroy body inlined under null guard, flag>0 -> func_001003A0 (operator delete) [G]).

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

extern "C" void func_001003A0(void *);

// 0x002F9DD0
extern "C" CGtLinearMalloc * __dt__15CGtLinearMallocFv(CGtLinearMalloc * self0, short flag)
{
    UnkStruct_002F9D00 * self = (UnkStruct_002F9D00 *)self0;
    if (self != 0) {
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
        if (flag > 0) {
            func_001003A0(self);
        }
    }
    return self0;
}
