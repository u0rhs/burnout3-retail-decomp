// Hand-written; the lifter refused it (a74: i declared before s (s0/s1 swap); for loop with s+9 bound).

struct UnkStruct_00301220 {
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x4C - 0x10];
    int field_4C;
    unsigned char pad_50[0x17C - 0x50];
    void * field_17C[1];
};

typedef void (*UnkFn_00301220)(void *, int, void *);

// [L] DNAT: CB3StreamedTrack::ForEveryUnitInSafeArea(void (*)(CB3StreamedTrackLODAndCollisionData*, int, void*),void*) (research/proto/new_names.csv, high)
// 0x00301220
extern "C" void ForEveryUnitInSafeArea__16CB3StreamedTrackFPFP35CB3StreamedTrackLODAndCollisionDataiPv_vPv(UnkStruct_00301220 * self, UnkFn_00301220 p0, void * p1)
{
    int i;
    int s = self->field_4C - 4;
    if (s < 0) {
        s += self->field_C;
    }
    for (i = s; i < s + 9; i++) {
        p0(self->field_17C[i % self->field_C], i % self->field_C, p1);
    }
}
