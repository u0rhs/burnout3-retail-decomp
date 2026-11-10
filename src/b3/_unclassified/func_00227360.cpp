// OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (static CB3Fog::CalculateClipPlanes(float*,float*,float) on three float locals; camera-pointer locals; const pointer to ourGlobals.field_20).

// OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00227360;
struct UnkStruct_00227360_1;
struct UnkStruct_00227360_2;
struct UnkStruct_00227360_3;
struct UnkStruct_00227360_4;
struct UnkStruct_ourGlobals;

struct UnkStruct_00227360_1 {
    float field_0;
    float field_4;
    float field_8;
};

struct UnkStruct_00227360_2 {
    unsigned char pad_0[0x90];
    float field_90;
};

struct UnkStruct_00227360_3 {
    unsigned char pad_0[0x58];
    int field_58;
    unsigned char pad_5C[0x28];
    float field_84;
    float field_88;
};

struct UnkStruct_00227360_4 {
    unsigned char pad_0[0x58];
    int field_58;
};

struct UnkStruct_ourGlobals {
    unsigned char pad_0[0x20];
    int field_20;
};

struct UnkStruct_00227360 {
    unsigned char pad_0[0x3B0];
    UnkStruct_00227360_3 * field_3B0;
    UnkStruct_00227360_2 * field_3B4;
};

extern UnkStruct_ourGlobals ourGlobals;

class CB3Fog {
public:
    static void CalculateClipPlanes(float*, float*, float);
};
extern "C" void RwCameraSetNearClipPlane(int, float);
extern "C" void RwCameraSetFarClipPlane(int, float);
extern "C" void RwCameraBeginUpdate(int);
extern "C" void RpSkyRenderStateSet(int, void *);

extern "C" void OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(UnkStruct_00227360 * self, int p0)
{
    float nearClip;
    float farClip;
    float state;
    switch (p0) {
    case 0:
        self->field_3B0 = (UnkStruct_00227360_3 *)((char *)self + 0x310);
        self->field_3B4 = (UnkStruct_00227360_2 *)((char *)self + 0x1D0);
        break;
    case 1:
        self->field_3B0 = (UnkStruct_00227360_3 *)((char *)self + 0x90);
        self->field_3B4 = (UnkStruct_00227360_2 *)((char *)self + 0x1D0);
        CB3Fog::CalculateClipPlanes(&nearClip, &farClip, self->field_3B4->field_90);
        UnkStruct_00227360_3 * c;
        c = self->field_3B0;
        c->field_84 = nearClip;
        RwCameraSetNearClipPlane(c->field_58, c->field_84);
        c = self->field_3B0;
        c->field_88 = farClip;
        RwCameraSetFarClipPlane(c->field_58, c->field_88);
        break;
    case 2:
        self->field_3B0 = (UnkStruct_00227360_3 *)((char *)self + 0x130);
        self->field_3B4 = (UnkStruct_00227360_2 *)((char *)self + 0x270);
        CB3Fog::CalculateClipPlanes(&nearClip, &farClip, self->field_3B4->field_90);
        UnkStruct_00227360_3 * d;
        d = self->field_3B0;
        d->field_84 = nearClip;
        RwCameraSetNearClipPlane(d->field_58, d->field_84);
        d = self->field_3B0;
        d->field_88 = farClip;
        RwCameraSetFarClipPlane(d->field_58, d->field_88);
        break;
    }
    RwCameraBeginUpdate(self->field_3B0->field_58);
    state = 1000.0f;
    RpSkyRenderStateSet(4, &state);
    int * const fp = &ourGlobals.field_20;
    ((void (*)(int, int))*fp)(16, 1);
    ((void (*)(int, int))*fp)(15, 0);
}
