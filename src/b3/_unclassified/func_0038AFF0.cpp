// Hand-written; the lifter refused it (ternary != 0 ? 4 : 5 -> movz).

struct UnkStruct_a167_x { int field_0; unsigned char pad_4[0x1C]; };
extern UnkStruct_a167_x D_004EE040;
extern "C" int func_00131CE0(UnkStruct_a167_x *);
// 0x0038AFF0
extern "C" int func_0038AFF0()
{
    return func_00131CE0(&D_004EE040) != 0 ? 4 : 5;
}
