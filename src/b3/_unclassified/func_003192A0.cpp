// func_003192A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (local struct with inline ctor + Get() (computed addiu), param as const reference (lw scheduled before sh)).

// func_003192A0 -- tiny-function batch (tools/tiny_batch.py, lifted; hand-matched).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths). Twin of the identical body at 0x003180A0.

struct UnkStruct_003192A0_a2 {
    int field_0;
};

// [G] a 30-wchar fallback buffer (0x1E, the size its siblings pass to ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi) plus the
// caller's string pointer; Get() returns the pointer, or the empty buffer when it is null.
struct UnkStruct_003192A0_1 {
    short field_0[0x1E];
    int field_3C;
    UnkStruct_003192A0_1() { field_0[0] = 0; }
    UnkStruct_003192A0_1 *Get() { return field_3C != 0 ? (UnkStruct_003192A0_1 *)field_3C : this; }
};

extern "C" void _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(int, int, UnkStruct_003192A0_1 *, int, int, int);

// 0x003192A0
// [L] p1 is a reference: as a pointer, MWCC keeps the lw after the local's sh (aliasing).
extern "C" void func_003192A0(int n0, int p0, const UnkStruct_003192A0_a2 & p1)
{
    UnkStruct_003192A0_1 local;
    local.field_3C = p1.field_0;
    _FormatString__10CGtUnicodeFPUsPCUsPCUsPCUsPCUsPCUs(n0, p0, local.Get(), 0, 0, 0);
}
