// Hand-written; the lifter refused it (hand-written: DNAT SetTrackID; stores trackID then marathon/p2p/right-hand-drive flags from D_005196A0).

class CB3TrackList {
public:
    bool IsTrackMarathon(unsigned long);
    bool IsTrackPointToPoint(unsigned long);
    bool IsTrackRightHandDrive(unsigned long);
    unsigned char pad_0[0x410];
};
extern CB3TrackList D_005196A0;
struct UnkStruct_00199E00 {
    unsigned char pad_0[0x12AD10];
    unsigned long field_12AD10;
    unsigned char field_12AD18;
    unsigned char field_12AD19;
    unsigned char field_12AD1A;
};

// [L] DNAT: CB3World::SetTrackID(unsigned long) (research/proto/new_names.csv, high)
// 0x00199E00
extern "C" void SetTrackID__8CB3WorldFUl(UnkStruct_00199E00 * self, unsigned long p0)
{
    self->field_12AD10 = p0;
    if (p0 != 0) {
        self->field_12AD19 = D_005196A0.IsTrackMarathon(self->field_12AD10);
        self->field_12AD18 = D_005196A0.IsTrackPointToPoint(self->field_12AD10);
        self->field_12AD1A = D_005196A0.IsTrackRightHandDrive(self->field_12AD10);
    }
}
