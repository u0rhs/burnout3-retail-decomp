// func_003366E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (ConvertDirtySockError is static (a0 = int error code field_C), no phantom this).

// lifter variant 0
// func_003366E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtLobbyPS2DirtySock;
struct UnkStruct_003366E0_a1;
struct UnkStruct_003366E0_a2;

class CGtLobbyPS2DirtySock {
public:
    static int ConvertDirtySockError(int);  // [L] static: its asm compares a0 (an int error code) to FourCC constants
};

struct UnkStruct_003366E0_a1 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_003366E0_a2 {
    unsigned char pad_0[0x110];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
};

// 0x003366E0
extern "C" void func_003366E0(int n0, UnkStruct_003366E0_a1 * p0, UnkStruct_003366E0_a2 * p1)
{
    int t0 = p0->field_C;
    if (t0 != 0) {
        int r0 = CGtLobbyPS2DirtySock::ConvertDirtySockError(t0);
        p1->field_112 = 1;
        p1->field_110 = 0;
        p1->field_114 = r0;
    } else {
        p1->field_111 = 1;
    }
}
