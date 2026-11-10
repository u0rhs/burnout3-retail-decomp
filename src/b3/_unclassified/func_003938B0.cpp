// func_003938B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (switch: default: case written FIRST (before case 0) removes the b-to-b join block; ptr cached in local).

// func_003938B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003938B0_1;
struct UnkStruct_003938B0_2;
struct UnkStruct_D_0051BA88;

struct UnkStruct_D_0051BA88 {
    UnkStruct_003938B0_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003938B0_1 {
    unsigned char pad_0[0x1B8];
    UnkStruct_003938B0_2 * field_1B8;
};

struct UnkStruct_003938B0_2 {
    unsigned char pad_0[0x4];
    int field_4;
};

extern UnkStruct_D_0051BA88 D_0051BA88;

// 0x003938B0
extern "C" int func_003938B0()
{
    UnkStruct_003938B0_2 * p = D_0051BA88.field_0->field_1B8;
    if (p == 0) {
        return 10;
    }
    switch (p->field_4) {
    default:
        return 10;
    case 0:
        return 10;
    case 1:
        return 6;
    case 2:
        return 15;
    }
}
