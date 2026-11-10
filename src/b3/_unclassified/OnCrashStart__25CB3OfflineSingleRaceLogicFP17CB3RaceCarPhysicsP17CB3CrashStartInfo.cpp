// Hand-written; the lifter refused it (arms reload c=p0->field_13F4 before shared stores).

struct UnkStruct_00389AB0_car {
    unsigned char pad_0[0x11C0];
    float field_11C0;
    unsigned char pad_11C4[0x1D];
    unsigned char field_11E1;
    unsigned char field_11E2;
};
struct UnkStruct_00389AB0_a1 {
    unsigned char pad_0[0x13F4];
    UnkStruct_00389AB0_car *field_13F4;
};
extern "C" void HandleCrashStart__8CB3ScoreFP17CB3CrashStartInfo(void *, void *);
extern "C" void SetInfiniteBoost__7CB3BurnFb(void *, bool);
extern "C" void RemoveBurn__7CB3BurnFf(void *, float);
extern "C" void SetNumExtraBoostBarSegments__7CB3BurnFi(void *, int);
extern "C" void RemoveSegment__7CB3BurnFv(void *);
extern "C" void OnCrashStart__25CB3OfflineSingleRaceLogicFP17CB3RaceCarPhysicsP17CB3CrashStartInfo(void *self, UnkStruct_00389AB0_a1 *p0, void *p1)
{
    HandleCrashStart__8CB3ScoreFP17CB3CrashStartInfo((char *)p0->field_13F4 + 0x10C0, p1);
    SetInfiniteBoost__7CB3BurnFb((char *)p0->field_13F4 + 0x118C, false);
    UnkStruct_00389AB0_car *c = p0->field_13F4;
    if (c->field_11E1 != 0 && c->field_11E2 != 0) {
        RemoveBurn__7CB3BurnFf((char *)c + 0x118C, c->field_11C0);
        SetNumExtraBoostBarSegments__7CB3BurnFi((char *)p0->field_13F4 + 0x118C, 0);
        c = p0->field_13F4;
    } else {
        RemoveSegment__7CB3BurnFv((char *)c + 0x118C);
        c = p0->field_13F4;
    }
    c->field_11E1 = 0;
    c->field_11E2 = 0;
}
