// Hand-written; the lifter refused it (gaps1c: written from the asm, exact).

// gaps1c (2026-11-02): hand-written from the retail asm (0x14EC30..0x14ECA0). Unnamed (no retail_names.csv row; between B3Burn.cpp functions). Stores a2
// at +0x580 and a3 as a byte at +0x58B, and maps a1 through jtbl_004B60D0 to +0x57C: 0 -> 1, 1 -> 4, 2 -> 3, 3 -> 2,
// 4 -> 5, anything else -> 0.

struct UnkStruct_0014EC30 {
    unsigned char pad_0[0x57C];
    int field_57C;
    int field_580;
    unsigned char pad_584[0x7];
    unsigned char field_58B;
};

// 0x0014EC30
extern "C" void func_0014EC30(UnkStruct_0014EC30 * self, unsigned int kind, int p1, int p2)
{
    self->field_580 = p1;
    self->field_58B = (unsigned char)p2;
    switch (kind) {
    case 0:
        self->field_57C = 1;
        break;
    case 1:
        self->field_57C = 4;
        break;
    case 2:
        self->field_57C = 3;
        break;
    case 3:
        self->field_57C = 2;
        break;
    case 4:
        self->field_57C = 5;
        break;
    case 5:
    case 6:
    default:
        self->field_57C = 0;
        break;
    }
}
