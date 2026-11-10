// func_004652B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (x=4,y=1 initialised at declaration; switch re-assigns them for 0/3, empty break for 1/2/4; stores after).

// func_004652B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_004652B0_a1;
struct UnkStruct_004652B0_a2;

struct UnkStruct_004652B0_a1 {
    int field_0;
};

struct UnkStruct_004652B0_a2 {
    int field_0;
};

// 0x004652B0
extern "C" void func_004652B0(int n0, UnkStruct_004652B0_a1 * p0, UnkStruct_004652B0_a2 * p1)
{
    int x = 4, y = 1;
    switch (n0) {
    case 0:
    case 3:
        x = 4; y = 1;
        break;
    case 1:
    case 2:
    case 4:
        break;
    }
    p0->field_0 = x;
    p1->field_0 = y;
}
