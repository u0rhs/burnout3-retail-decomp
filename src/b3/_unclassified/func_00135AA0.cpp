// Hand-written; the lifter refused it (a163 tiny).

struct UnkStruct_a163_g { float field_0; unsigned char pad[0x100]; };
extern UnkStruct_a163_g D_004F50A0;
struct UnkStruct_a163_c { void *field_0; unsigned char pad_4[0x18]; float field_1C; };
extern "C" int func_0012FDA0(void *);
// 0x00135AA0
extern "C" void func_00135AA0(UnkStruct_a163_c *self) { if (func_0012FDA0(self->field_0) != 0) self->field_1C = D_004F50A0.field_0; }
