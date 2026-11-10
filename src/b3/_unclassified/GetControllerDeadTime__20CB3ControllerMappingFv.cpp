// Hand-written; the lifter refused it (a163 tiny).

struct UnkStruct_a163_g { float field_0; unsigned char pad[0x100]; };
extern UnkStruct_a163_g D_004F50A0;
class CB3ControllerMapping { public: void ResetControllerDeadTime(); float GetControllerDeadTime(); unsigned char pad_0[0x128]; float field_128; };
// 0x0012EF00
float CB3ControllerMapping::GetControllerDeadTime() { return D_004F50A0.field_0 - field_128; }
