// Hand-written; the lifter refused it (byte-offset cast of D_00522660+0x12C6FC+idx*0x27D0 (hi split like retail)).

struct UnkStruct_D_00522660 { unsigned char pad[0x12C6C4]; };
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_a167_hud { unsigned char pad_0[0x28]; int field_28; int field_2C; };
extern "C" void PrepareCrashTimerObject__16CB3HUDCrashTimerFv(UnkStruct_a167_hud *);
// 0x003B83F0
extern "C" void func_003B83F0(UnkStruct_a167_hud * self)
{
    if (self->field_2C == -1) {
        self->field_2C = *((signed char *)&D_00522660 + 0x12C6FC + self->field_28 * 0x27D0);
    }
    PrepareCrashTimerObject__16CB3HUDCrashTimerFv(self);
}
