// Hand-written; the lifter refused it (near7: loop as idx = 5; i = idx; while (i--) {...} (rotated with the kept beqz idx guard)).

#include "b3/GtMath.h"
class CB3Score {
public:
    bool IsAheadOfIgnoringLaps(CB3Score* p0);
    unsigned char pad_0[0x10];
};
struct UnkStruct_001D0F50_car {
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
};
struct UnkStruct_001D0F50_rng {
    float field_0;
    float field_4;
    unsigned char field_8;
    unsigned char field_9;
    unsigned char field_A;
};
struct UnkStruct_001D0F50_self {
    unsigned char pad_0[0x216];
    signed char field_216;
    unsigned char pad_217[0x1339];
    unsigned char field_1550;
    unsigned char pad_1551[0x17];
    UnkStruct_001D0F50_car * field_1568;
};
extern float D_004B7DD0[];

// 0x001D0F50
extern "C" void func_001D0F50(UnkStruct_001D0F50_self * self, UnkStruct_001D0F50_car * car, UnkStruct_001D0F50_rng * out, float x)
{
    float arr[6];
    if (car == 0 || self->field_216 == -1) return;
    float base;
    bool ah = self->field_1568->field_10C0.IsAheadOfIgnoringLaps(&car->field_10C0);
    if (ah) {
        if (self->field_1550 != 0) base = 19600;
        else base = 15625;
    } else {
        if (self->field_1550 != 0) base = 19600;
        else base = 15625;
    }
    if (!(x <= base)) return;
    out->field_8 = 1;
    int i;
    int idx;
    idx = 5;
    i = idx;
    while (i--) {
        arr[i] = base * D_004B7DD0[i];
        if (x <= arr[i + 1]) idx = i;
    }
    if (!(idx > 3)) {
        float t = GtMath::Min(GtMath::Max((x - arr[3]) / (arr[4] - arr[3]), 0.0f), 1.0f);
        out->field_0 = 1.0f - t;
    }
    if (!(idx > 2)) out->field_9 = 1;
    if (!(idx > 1)) {
        float t = GtMath::Min(GtMath::Max((x - arr[1]) / (arr[2] - arr[1]), 0.0f), 1.0f);
        float r = 1.0f - t;
        out->field_4 = r;
        out->field_A = r > 0.0f;
    }
}
