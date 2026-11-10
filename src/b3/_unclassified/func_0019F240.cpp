// Hand-written; the lifter refused it (a93: three CB3Viewport inits; int-pun 0.5f near, (float)10000 far).

struct UnkStruct_0019F240_cam { unsigned char pad_0[0x4]; };
extern "C" void Construct__11CB3ViewportFiii(void *, int, int, int);
extern "C" void SetFOV__11CGtViewportFf(void *, float);
extern "C" void RwCameraSetNearClipPlane(void *, float);
extern "C" void RwCameraSetFarClipPlane(void *, float);

struct UnkStruct_0019F240 {
    int field_0;
    int field_4;
    int field_8;
    unsigned char pad_C[0x7C];
    unsigned char field_88[8];
    unsigned char pad_90[0x58];
    void *field_E8;
    unsigned char pad_EC[0x28];
    float field_114;
    float field_118;
    unsigned char pad_11C[0x14];
    unsigned char field_130[8];
    unsigned char pad_138[0x50];
    void *field_188;
    unsigned char pad_18C[0x28];
    float field_1B4;
    float field_1B8;
    unsigned char pad_1BC[0x154];
    unsigned char field_310[8];
    unsigned char pad_318[0x50];
    void *field_368;
    unsigned char pad_36C[0x28];
    float field_394;
    float field_398;
};

// 0x0019F240
extern "C" void func_0019F240(UnkStruct_0019F240 *self)
{
    Construct__11CB3ViewportFiii(&self->field_310, self->field_0, self->field_4, self->field_8);
    Construct__11CB3ViewportFiii((char *)self + 0x90, 0, 0, 0);
    Construct__11CB3ViewportFiii(&self->field_130, 0, 0, 0);
    SetFOV__11CGtViewportFf(&self->field_310, 30.0f);
    *(int *)&self->field_394 = 0x3F000000;
    RwCameraSetNearClipPlane(self->field_368, self->field_394);
    self->field_398 = (float)10000;
    RwCameraSetFarClipPlane(self->field_368, self->field_398);
    *(int *)&self->field_114 = 0x3F000000;
    RwCameraSetNearClipPlane(self->field_E8, self->field_114);
    self->field_118 = (float)10000;
    RwCameraSetFarClipPlane(self->field_E8, self->field_118);
    *(int *)&self->field_1B4 = 0x3F000000;
    RwCameraSetNearClipPlane(self->field_188, self->field_1B4);
    self->field_1B8 = (float)10000;
    RwCameraSetFarClipPlane(self->field_188, self->field_1B8);
}
