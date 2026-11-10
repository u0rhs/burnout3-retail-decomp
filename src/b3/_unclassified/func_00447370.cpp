// Hand-written; the lifter refused it (a117: SetupStartFrame-like; if (C != 0){..} else {..} order puts TrackTime block before the C==0 block).

// [L] DNAT: CB3PlayerCameraStatePlayer::SetupStartFrame(CB3CameraPlayerParams*,CB3PlayerCameraManager*) (research/proto/new_names.csv, low)
struct UnkStruct_00447370_e0 {
    float field_0;
    unsigned char pad_4[0x1C];
};
struct UnkStruct_00447370_m {
    unsigned char pad_0[0xB79];
    unsigned char field_B79;
    unsigned char pad_B7A[6];
    unsigned long field_B80;
    float field_B88;
};
struct UnkStruct_00447370 {
    UnkStruct_00447370_e0 * field_0;
    int field_4;
    int field_8;
    unsigned char field_C;
    unsigned char pad_D[3];
    UnkStruct_00447370_m * field_10;
    float field_14;
    int field_18;
    unsigned char field_1C;
};
extern "C" int GetIsSetup__17CB3CameraKeyFrameFv(void *);
extern "C" void DeactivateBehaviour__22CB3PlayerCameraManagerFi(void *, int);
extern "C" void SetActiveBehaviour__22CB3PlayerCameraManagerFi(void *, int);
extern "C" float GetTrackTime__22CB3PlayerCameraManagerFv(void *);

// 0x00447370
extern "C" void func_00447370(UnkStruct_00447370 * self)
{
    if (self->field_8 == 3) {
        if ((self->field_10->field_B80 & 0x2000) != 0) {
            DeactivateBehaviour__22CB3PlayerCameraManagerFi(self->field_10, 0xD);
        }
        self->field_10->field_B79 = 1;
        SetActiveBehaviour__22CB3PlayerCameraManagerFi(self->field_10, 0xD);
        return;
    }
    if (self->field_C != 0) {
        if (self->field_8 != 0) {
            self->field_14 = self->field_10->field_B88;
        } else {
            self->field_14 = GetTrackTime__22CB3PlayerCameraManagerFv(self->field_10);
        }
        int i = 0;
        while (i < self->field_4) {
            if (GetIsSetup__17CB3CameraKeyFrameFv(&self->field_0[i]) == 0) break;
            if (!(self->field_0[i].field_0 < self->field_14)) break;
            i++;
        }
        self->field_18 = i - 1;
    } else {
        self->field_18 = -1;
        self->field_14 = self->field_0->field_0;
    }
    self->field_1C = 1;
}
