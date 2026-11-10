// func_004471A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (block form; int n=field_18+1 hoisted; keyframe elems 0x20 stride typed; func_00375260(void*,void*); final 'if (SetupTransition()==0) return;').

// lifter variant 0
// func_004471A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3PlayerCameraManager;

class CB3PlayerCameraManager;
class CB3PlayerCameraStatePlayer;
struct UnkStruct_004471A0;
struct UnkStruct_004471A0_e0;
struct UnkStruct_D_0051BAC8;
struct UnkStruct_D_0051BAD5;
struct UnkStruct_D_0051BAD6;

class CB3PlayerCameraManager {
public:
    float GetTrackTime();
    void SetActiveBehaviour(int);

    unsigned char pad_0[0xB88];
    float field_B88;
    unsigned char pad_B8C[0x1B];
    unsigned char field_BA7;
};

class CB3PlayerCameraStatePlayer {
public:
    static int SetupTransition(CB3PlayerCameraManager*);
};

struct UnkStruct_D_0051BAC8 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004471A0_e0 {
    float field_0;
    unsigned char pad_4[0x1C];
};

struct UnkStruct_D_0051BAD6 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BAD5 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004471A0 {
    UnkStruct_004471A0_e0 * field_0;
    unsigned char pad_4[0x4];
    int field_8;
    unsigned char field_C;
    unsigned char pad_D[0x3];
    CB3PlayerCameraManager * field_10;
    float field_14;
    int field_18;
    unsigned char field_1C;
};

extern UnkStruct_D_0051BAC8 D_0051BAC8;
extern UnkStruct_D_0051BAD6 D_0051BAD6;
extern UnkStruct_D_0051BAD5 D_0051BAD5;

extern "C" int GetIsSetup__17CB3CameraKeyFrameFv(void *);  // CB3CameraKeyFrame::GetIsSetup()
extern "C" int GetTypeTransition__17CB3CameraKeyFrameFv(void *);  // CB3CameraKeyFrame::GetTypeTransition()
extern "C" int GetEventPause__17CB3CameraKeyFrameFv(void *);  // CB3CameraKeyFrame::GetEventPause()
extern "C" int GetEventRecord__17CB3CameraKeyFrameFv(void *);  // CB3CameraKeyFrame::GetEventRecord()
extern "C" void func_00375260(void *, void *);

// 0x004471A0
extern "C" void func_004471A0(UnkStruct_004471A0 * self)
{
    int t0 = self->field_8;
    if (t0 != 3) {
        int n = self->field_18 + 1;
        if (self->field_C == 0) {
            self->field_14 = self->field_14 + D_0051BAC8.field_0;
        } else {
            if (t0 == 0) {
                self->field_14 = self->field_10->GetTrackTime();
            } else {
                self->field_14 = self->field_10->field_B88;
            }
        }
        if (GetIsSetup__17CB3CameraKeyFrameFv(&self->field_0[n]) != 0) {
            UnkStruct_004471A0_e0 * t2 = self->field_0;
            float t3 = self->field_14;
            if (t2[n].field_0 <= t3) {
                if (self->field_1C != 0 || GetTypeTransition__17CB3CameraKeyFrameFv(&t2[self->field_18]) == 0) {
                    func_00375260(((char *)self->field_10 + 2576), &self->field_0[n]);
                    self->field_10->SetActiveBehaviour(11);
                    self->field_1C = 0;
                }
                self->field_18 = self->field_18 + 1;
                if (self->field_C != 0) {
                    if (GetEventPause__17CB3CameraKeyFrameFv(&self->field_0[self->field_18]) == 1) {
                        D_0051BAD5.field_0 = 1;
                    } else if (GetEventPause__17CB3CameraKeyFrameFv(&self->field_0[self->field_18]) == 2) {
                        D_0051BAD6.field_0 = 1;
                    }
                }
                if (self->field_8 == 1) {
                    if (GetEventRecord__17CB3CameraKeyFrameFv(&self->field_0[self->field_18]) == 2) {
                        self->field_10->field_BA7 = 0;
                    }
                }
                if (CB3PlayerCameraStatePlayer::SetupTransition((CB3PlayerCameraManager*)self) == 0) {
                    return;
                }
            }
        }
    }
}
