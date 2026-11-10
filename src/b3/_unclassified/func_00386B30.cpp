// Hand-written; the lifter refused it (a88: AllocStream(bool), joined SetMediaBuffer call, goto done in find loop).

// Hand-written (a88: CGtSoundStreamManager::AllocStream(bool), DNAT high).
// [L] DNAT: CGtSoundStreamManager::AllocStream(bool) (research/proto/new_names.csv, high)
struct UnkStruct_00386B30_e { void * field_0; unsigned char field_4; };
struct UnkStruct_00386B30_s { unsigned char pad_0[0x4]; };
struct UnkStruct_00386B30 {
    unsigned char pad_0[0x14];
    unsigned char field_14[0x8];
    int field_1C;
    int field_20;
    UnkStruct_00386B30_e * field_24;
    int field_28;
    unsigned char pad_2C[0x4];
    UnkStruct_00386B30_s * field_30;
};
extern "C" void * AddLink__11CGtFreeListFv(void *);
extern "C" void SetMediaBuffer__14CGtSoundStreamFPvi(void *, void *, int);

// 0x00386B30
extern "C" UnkStruct_00386B30_s * AllocStream__21CGtSoundStreamManagerFb(UnkStruct_00386B30 * self, bool p0)
{
    UnkStruct_00386B30_s * s = (UnkStruct_00386B30_s *)((char *)AddLink__11CGtFreeListFv(self->field_14) + 8);
    void * buf;
    int size;
    int i;
    int j;
    if (p0) {
        for (i = 0; i < self->field_1C; i++) {
            for (j = 0; j < self->field_1C; j++) {
                if (self->field_24[j].field_4 == 0) {
                    self->field_24[j].field_4 = 1;
                    break;
                }
            }
        }
        size = self->field_20 * self->field_1C;
        buf = (void *)self->field_28;
        self->field_30 = s;
    } else {
        size = self->field_20;
        for (i = 0; i < self->field_1C; i++) {
            if (self->field_24[i].field_4 == 0) {
                self->field_24[i].field_4 = 1;
                buf = self->field_24[i].field_0;
                goto done;
            }
        }
        buf = 0;
    }
done:
    SetMediaBuffer__14CGtSoundStreamFPvi(s, buf, size);
    return s;
}
