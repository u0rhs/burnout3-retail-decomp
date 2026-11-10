// QueryBlock__16CB3MemoryManagerCF14EB3MemoryBlocki -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (switch(p0) case 13; placeholder inline taking the value by const int& (load stays in the taken arm)).

// lifter variant 0
// QueryBlock__16CB3MemoryManagerCF14EB3MemoryBlocki -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003E7A50;

struct UnkStruct_003E7A50 {
    unsigned char pad_0[0x358];
    int field_358;
    unsigned char pad_35C[0x4];
    int field_360;
    unsigned char pad_364[0x4B4];
    int field_818;
    unsigned char pad_81C[0x4];
    int field_820;
    unsigned char pad_824[0x160];
    int field_984;
};

// [G] placeholder inline: the value by const reference keeps its load inside the taken arm (retail's out-of-line
// `b; lw` blocks); same helper for both slot pairs
static inline int func_003E7A50_inl1(int idx, int cur, const int & val)
{
    if (idx >= 0 && idx != cur) {
        return 0;
    }
    return val;
}

// 0x003E7A50
extern "C" int QueryBlock__16CB3MemoryManagerCF14EB3MemoryBlocki(UnkStruct_003E7A50 * self, int p0)
{
    switch (p0) {
    case 13:
    {
        int t0 = self->field_984;
        if (t0 == 2) {
            return func_003E7A50_inl1(self->field_818, t0, self->field_820);
        } else {
            return func_003E7A50_inl1(self->field_358, t0, self->field_360);
        }
    }
    }
    return 0;
}
