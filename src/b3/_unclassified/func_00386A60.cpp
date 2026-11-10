// Hand-written; the lifter refused it (a89: goto found / goto done out-of-line blocks (G goto), else loop clears all; key+count hoisted).

// FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream -- [L] DNAT: CGtSoundStreamManager::FreeStream(CGtSoundStream*) (research/proto/new_names.csv, high)
struct UnkStruct_00386A60_e { void * field_0; unsigned char field_4; };
struct UnkStruct_00386A60_s {
    unsigned char pad_0[0x134];
    void * field_134;
};
struct UnkStruct_00386A60 {
    unsigned char pad_0[0x14];
    unsigned char field_14[0x8];
    int field_1C;
    int field_20;
    UnkStruct_00386A60_e * field_24;
    int field_28;
    int field_2C;
    int field_30;
};
extern "C" void SetMediaBuffer__14CGtSoundStreamFPvi(void *, void *, int);
extern "C" void RemoveLink__11CGtFreeListFP15CGtFreeListLink(void *, void *);

// 0x00386A60
extern "C" void FreeStream__21CGtSoundStreamManagerFP14CGtSoundStream(UnkStruct_00386A60 * self, UnkStruct_00386A60_s * p0)
{
    int i;
    if (self->field_30 == 0) {
        void * key = p0->field_134;
        int n = self->field_1C;
        for (i = 0; i < n; i++) {
            if (self->field_24[i].field_0 == key) goto found;
        }
    } else {
        for (i = 0; i < self->field_1C; i++) {
            self->field_24[i].field_4 = 0;
        }
        self->field_30 = 0;
    }
done:
    SetMediaBuffer__14CGtSoundStreamFPvi(p0, 0, 0);
    RemoveLink__11CGtFreeListFP15CGtFreeListLink(self->field_14, (char *)p0 - 8);
    return;
found:
    self->field_24[i].field_4 = 0;
    goto done;
}
