// func_0022D1E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (signed char counter declared before the count (register order), element pointer local, || of the two calls, signed char return).

// lifter variant 0
// func_0022D1E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0022D1E0;
struct UnkStruct_0022D1E0_e0;

struct UnkStruct_0022D1E0_e0 {
    unsigned char pad_0[0x12C];
};

struct UnkStruct_0022D1E0 {
    UnkStruct_0022D1E0_e0 field_0[1];  // [G] element count unknown
};

extern "C" int PadIsValid__20CB3ControllerMappingFv(void *);  // CB3ControllerMapping::PadIsValid()
extern "C" int func_0012EF20(void *);

// 0x0022D1E0
extern "C" signed char func_0022D1E0(UnkStruct_0022D1E0 * self)
{
    signed char i;
    signed char m0 = 0;
    for (i = 0; i < 2; i++) {
        void * p = (char *)&self->field_0[i] + 0xD48;
        if (PadIsValid__20CB3ControllerMappingFv(p) || func_0012EF20(p)) {
            m0++;
        }
    }
    return m0;
}
