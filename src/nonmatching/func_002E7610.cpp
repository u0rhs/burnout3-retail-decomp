// NONMATCHING: func_002E7610 -- retail 126 / ours 126 instructions, 8 in changed runs
// son2: 9 -> 8: Cur2 as 'int o = field_B98 << 5; (int)mgp + o + 0x990' gives retail's addu v1,a0,v1. Left: special-arm lui D_004F509C hoisted above the addu; retail bc1f delay slot nop with addiu a0 in the jal slot (ours fills the bc1f slot). Tried Cur/Cur2 per-site (8 combos), float dd local, 15-pragma sweep
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// [L] DNAT: CB3PlayerCameraManager::Update(float) (research/proto/new_names.csv, medium)
struct UnkStruct_D_004F509C { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BAC4 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004EB1E0 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E86535 { unsigned char field_0; unsigned char pad_1[0xF]; };

class CB3CameraKeyFrame {
public:
    int GetEventRecord();
    bool GetIsSetup();
    float field_0;
    unsigned char pad_4[0x1C];
};
struct UnkStruct_Behaviour {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(float, void *);
};
struct UnkStruct_Self200 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(float);
    float field_204;
};
struct UnkStruct_7610 {
    unsigned char pad_0[0x200];
    UnkStruct_Self200 field_200;
    unsigned char pad_208[0x38];
    UnkStruct_Behaviour * field_240[20];
    unsigned char pad_290[0x8F0];
    unsigned long field_B80;
    float field_B88;
    float field_B8C;
    int field_B90;
    unsigned char pad_B94[0x4];
    int field_B98;
    unsigned char pad_B9C[0x8];
    unsigned char field_BA4;
    unsigned char field_BA5;
};
struct UnkStruct_Cam { unsigned char pad_0[0x10]; };

extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_D_0051BAC4 D_0051BAC4;
extern UnkStruct_D_004EB1E0 D_004EB1E0;
extern UnkStruct_D_01E86535 D_01E86535;
extern "C" CB3CameraKeyFrame * mgpCameraBuffer__22CB3PlayerCameraManager;
extern "C" void Update__6CGtFSMFv(void *);

static inline CB3CameraKeyFrame * Cur2(UnkStruct_7610 * s)
{
    unsigned int o = s->field_B98 * 32;
    return (CB3CameraKeyFrame *)(o + (unsigned int)mgpCameraBuffer__22CB3PlayerCameraManager + 0x990);
}
static inline CB3CameraKeyFrame * Cur(UnkStruct_7610 * s)
{
    return (CB3CameraKeyFrame *)((char *)mgpCameraBuffer__22CB3PlayerCameraManager + s->field_B98 * 32 + 0x990);
}

// 0x002E7610
extern "C" void func_002E7610(UnkStruct_7610 * self, float dt)
{
    if (self->field_BA4 == 0) {
        return;
    }
    for (int i = 0; i < 20; i++) {
        if ((self->field_B80 & (1UL << i)) != 0) {
            if (i == 14 || i == 0) {
                self->field_240[i]->vfunc_18(D_004F509C.field_0, &self->field_200);
            } else {
                self->field_240[i]->vfunc_18(dt, &self->field_200);
            }
        }
    }
    Update__6CGtFSMFv(self);
    if (self->field_BA5 != 0) {
        self->field_200.field_204 = 90.0f;
    }
    self->field_200.vfunc_18(dt);
    if (self->field_B90 == 0) {
        if (Cur(self)->GetIsSetup()) {
            float t = self->field_B88;
            CB3CameraKeyFrame * kf = Cur2(self);
            if (kf->field_0 <= t) {
                if (kf->GetEventRecord() == 1) {
                    D_01E86535.field_0 = 1;
                } else if (Cur(self)->GetEventRecord() == 2) {
                    D_01E86535.field_0 = 0;
                }
                self->field_B98++;
            }
        }
    }
    if (D_004EB1E0.field_0 != 0) {
        self->field_B8C = 0.0f + self->field_B8C + D_004F509C.field_0 * (float)D_0051BAC4.field_0;
        self->field_B88 = self->field_B88 + dt;
    }
}
