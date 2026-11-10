// CB3PlayerCameraStatePlayer::SetupTransition(CB3PlayerCameraManager*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PlayerCameraStatePlayer.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a117: camera SetupTransition; float passed as a vararg: (double)d calls the runtime's fptodp, named by the E map [C]).

// [L] state at a0: keyframes (+0), mode (+0xC), manager (+0x10), index (+0x18); retail's mangled signature names the manager type
struct UnkStruct_00447000_e0 {
    float field_0;
    unsigned char pad_4[0x1C];
};
struct UnkStruct_00447000_m { unsigned char pad_0[0xBB0]; };
struct UnkStruct_00447000 {
    UnkStruct_00447000_e0 * field_0;
    unsigned char pad_4[0x8];
    unsigned char field_C;
    UnkStruct_00447000_m * field_10;
    unsigned char pad_14[0x4];
    int field_18;
};
extern "C" int GetIsSetup__17CB3CameraKeyFrameFv(void *);
extern "C" int GetTypeTransition__17CB3CameraKeyFrameFv(void *);
extern "C" void func_00375260(void *, void *);
extern "C" void func_00447170(int, ...);
extern "C" void SetActiveBehaviour__22CB3PlayerCameraManagerFi(void *, int);
extern "C" void SetParameters__23CB3BehaviourInterpolateF24EB3PlayerCameraBehaviour24EB3PlayerCameraBehaviourf20EB3InterpolationType24EB3InterpolationTimeMode(void *, int, int, float, int, int);
extern char D_004D2FA0[];
extern char D_004D2FF0[];

extern "C" int SetupTransition__26CB3PlayerCameraStatePlayerFP22CB3PlayerCameraManager(UnkStruct_00447000 * self)
{
    if (GetTypeTransition__17CB3CameraKeyFrameFv(&self->field_0[self->field_18]) != 0) {
        if (GetIsSetup__17CB3CameraKeyFrameFv(&self->field_0[self->field_18 + 1]) == 0) {
            func_00447170((int)D_004D2FA0, self->field_18 + 1);
            return 0;
        }
        int idx = self->field_18;
        UnkStruct_00447000_e0 * k = &self->field_0[idx];
        float d = k[1].field_0 - k->field_0;
        if (d < 0.0f) {
            func_00447170((int)D_004D2FF0, idx + 1, (double)d);
            return 0;
        }
        func_00375260((char *)self->field_10 + 0xA10, k);
        func_00375260((char *)self->field_10 + 0xA1C, &self->field_0[self->field_18 + 1]);
        SetActiveBehaviour__22CB3PlayerCameraManagerFi(self->field_10, 0xB);
        ((unsigned char *)self->field_10)[0xBA6] = 0;
        int mode = self->field_C ? 0 : 2;
        int ty = GetTypeTransition__17CB3CameraKeyFrameFv(&self->field_0[self->field_18]);
        int a3 = 1;
        if (ty == 1) a3 = 0;
        SetParameters__23CB3BehaviourInterpolateF24EB3PlayerCameraBehaviour24EB3PlayerCameraBehaviourf20EB3InterpolationType24EB3InterpolationTimeMode((char *)self->field_10 + 0x8C0, 0xB, 0xC, d, a3, mode);
    }
    return 1;
}
