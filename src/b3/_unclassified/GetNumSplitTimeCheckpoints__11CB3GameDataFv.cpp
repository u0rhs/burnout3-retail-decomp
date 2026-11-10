// Hand-written; the lifter refused it (a163 tiny).

struct UnkStruct_a163_gd { unsigned char pad_0[0x3F4]; int field_3F4; };
class CB3GameData { public: int GetNumSplitTimeCheckpoints(); unsigned char pad_0[0x560]; void *field_560; unsigned char pad_564[0x8]; UnkStruct_a163_gd *field_56C; };
// 0x0014E880
int CB3GameData::GetNumSplitTimeCheckpoints() { int r = 0; if (field_560 != 0) r = field_56C->field_3F4; return r; }
