// Hand-written; the lifter refused it (a88: HandleNonFatalCollision(CB3TrafficVehicle*), field_5EC pointer, gmr float declared before t).

// Hand-written (a88: CB3Score::HandleNonFatalCollision(CB3TrafficVehicle*)).
// [L] DNAT: CB3Score::HandleNonFatalCollision(CB3TrafficVehicle*) (research/proto/new_names.csv, high)
struct UnkStruct_00157060_1 { unsigned char pad_0[0x18EA]; unsigned char field_18EA; };
struct UnkStruct_00157060_a1;
struct UnkStruct_00157060_a1 {
    unsigned char pad_0[0x10C];
    UnkStruct_00157060_a1 * field_10C;
    unsigned char pad_110[0x67];
    unsigned char field_177;
};
struct CB3Score {
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0xB8];
    UnkStruct_00157060_1 * field_C8;
    unsigned char pad_CC[0x1B0];
    int field_27C;
    unsigned char pad_280[0x168];
    unsigned char field_3E8[8];
    float field_3F0[8];
    unsigned char field_410[8];
    unsigned char pad_418[0x1CD];
    unsigned char field_5E5;
    unsigned char field_5E6;
    unsigned char pad_5E7[0x1];
    float field_5E8;
    void * field_5EC;
    float field_5F0;
};

extern float gmrTakedownCrashTime__8CB3Score;

// 0x00157060
extern "C" void HandleNonFatalCollision__8CB3ScoreFP17CB3TrafficVehicle(CB3Score * self, UnkStruct_00157060_a1 * p0)
{
    if (self->field_27C == 3) return;
    if (self->field_C8->field_18EA != 0) return;
    void * v;
    float g = gmrTakedownCrashTime__8CB3Score;
    float t = self->field_5F0;
    if (t == -1.0f) {
        v = 0;
    } else if (t + g < self->field_C) {
        v = 0;
    } else {
        v = self->field_5EC;
    }
    if (v != 0) {
        self->field_5E5 = 1;
        self->field_5E6 = 1;
        self->field_5E8 = self->field_C;
    }
    UnkStruct_00157060_a1 * o = p0->field_10C;
    if (o != 0) p0 = o;
    for (int i = 0; i < 8; i++) {
        if (self->field_3E8[i] == p0->field_177) {
            self->field_410[i] = 0;
            return;
        }
    }
    for (int i = 0; i < 8; i++) {
        if (self->field_3E8[i] == 0xFF) {
            self->field_3E8[i] = p0->field_177;
            self->field_3F0[i] = self->field_C;
            self->field_410[i] = 0;
            return;
        }
    }
}
