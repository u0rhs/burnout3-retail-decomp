// Hand-written; the lifter refused it (extern C, [n][3] u8 array, int i=p0-4 local).

struct UnkStruct_a167_cs { unsigned char pad_0[0x4A9]; unsigned char field_4A9[1][3]; };
extern "C" void AddCrashMultiplier__13CB3CrashScoreF20ECrashModePickupTypei(UnkStruct_a167_cs * self, int p0, int p1)
{
    int i = p0 - 4;
    self->field_4A9[p1][i] = 1;
}
