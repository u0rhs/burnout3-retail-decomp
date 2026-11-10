// Hand-written; the lifter refused it (a163 tiny).

struct UnkStruct_a163_g { float field_0; unsigned char pad[0x100]; };
extern UnkStruct_a163_g D_01E900D4;
class CB3OfflineCrashPartyLogic { public: bool IsTurnBased(); bool IsCrashType(); };
// 0x00134270
bool CB3OfflineCrashPartyLogic::IsTurnBased() { return (int&)D_01E900D4.field_0 >= 2; }
