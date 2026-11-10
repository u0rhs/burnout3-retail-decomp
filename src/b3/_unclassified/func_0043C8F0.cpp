// Hand-written; the lifter refused it (switch, 1-indexed jtbl).

// Hand-written (a108).
struct UnkStruct_0043C8F0 {
    unsigned char pad_0[0xA4];
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
};
// 0x0043C8F0
extern "C" int func_0043C8F0(UnkStruct_0043C8F0 * self, unsigned int n)
{
    switch (n) {
    case 1: return self->field_A4;
    case 2: return self->field_A8;
    case 3: return self->field_AC;
    case 4: return self->field_B0;
    case 5: return self->field_B4;
    case 6: return self->field_B8;
    case 7: return self->field_BC;
    case 0: case 8: case 9: case 10: case 11: case 12: case 13: case 14:
    default: return 0;
    }
}
