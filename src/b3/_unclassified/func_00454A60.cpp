// Hand-written; the lifter refused it (early returns; extern C callees).

struct UnkStruct_a167_cs { unsigned char pad_0[4]; int field_4; unsigned char field_8; };
extern "C" unsigned long GetCrashStageGtID__26CB3HardCodedCrashStageListFi(int);
extern "C" unsigned long func_00454AC0(UnkStruct_a167_cs *);
// 0x00454A60
extern "C" unsigned long func_00454A60(UnkStruct_a167_cs * self)
{
    if (self->field_8 != 0) {
        if (self->field_4 == 0) {
            return func_00454AC0(self);
        }
        return GetCrashStageGtID__26CB3HardCodedCrashStageListFi(self->field_4 - 1);
    }
    return GetCrashStageGtID__26CB3HardCodedCrashStageListFi(self->field_4);
}
