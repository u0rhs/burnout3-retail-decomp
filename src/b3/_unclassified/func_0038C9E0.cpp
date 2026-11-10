// func_0038C9E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (nested ifs -> if (p) switch { default: return 9; case 0: ternary; case 1: return 2; case 2: break; } return 9; (default first, case 2 breaks to shared tail)).

// func_0038C9E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0038C9E0_1;
struct UnkStruct_0038C9E0_2;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_0064D3A0;

struct UnkStruct_D_0051BA88 {
    UnkStruct_0038C9E0_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0038C9E0_1 {
    unsigned char pad_0[0x1B8];
    UnkStruct_0038C9E0_2 * field_1B8;
};

struct UnkStruct_0038C9E0_2 {
    unsigned char pad_0[0x4];
    int field_4;
};

struct UnkStruct_D_0064D3A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0064D3A0 D_0064D3A0;

// 0x0038C9E0
extern "C" int func_0038C9E0()
{
    UnkStruct_0038C9E0_2 * p = D_0051BA88.field_0->field_1B8;
    if (p != 0) {
        switch (p->field_4) {
        default:
            return 9;
        case 0:
            return D_0064D3A0.field_0 > 1 ? 12 : 9;
        case 1:
            return 2;
        case 2:
            break;
        }
    }
    return 9;
}
