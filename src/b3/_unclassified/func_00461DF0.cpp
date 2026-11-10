// Hand-written; the lifter refused it (mwperm: +'// N182: `#pragma opt_dead_assignments off` ([G] scoped to this function; found '; +'int v0 = p1; UnkStruct_00461DF0_frame * c2; float y0; UnkStruct_00461DF0_frame *'; +'const bool t1 = 0 != v0;'; 'if (p1 != 0) {' -> 'if (!(t1)) { } else { int * t0 = &self->field_94; unsigned int t3; t3 = (int)((u'; 'for (int i = 0; i < 32; i++) {' -> 'int i; if (1) { i = 0; } while (func_00461DF0_inl1(i)) {'; +).

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x14];
    void * field_14;
    unsigned char pad_18[0x14];
    unsigned char * field_2C;
};
struct UnkStruct_00461DF0_frame {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};
struct UnkStruct_00461DF0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    int field_C[32];
    int field_8C;
    UnkStruct_00461DF0_frame * field_90;
    int field_94;
    int field_98;
    int field_9C;
    float field_A0;
    float field_A4;
    float field_A8;
    int field_AC;
};
extern UnkStruct_D_01E903E0 D_01E903E0;
struct UnkStruct_D_004D3A60 { float v; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004D3A60 D_004D3A60;
extern UnkStruct_D_004D3A60 D_004D3A64;
extern UnkStruct_D_004D3A60 D_004D3A68;
extern UnkStruct_D_004D3A60 D_004D3A6C;
extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" UnkStruct_00461DF0_frame * ConstructChild__10CGt2dFrameFv(void *);
extern "C" void SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(void *);

// N182: `#pragma opt_dead_assignments off` ([G] scoped to this function; found by mwperm).
#pragma push
#pragma opt_dead_assignments off
static inline bool func_00461DF0_inl1(int a0)
{
    return 32 > a0;
}

// 0x00461DF0
extern "C" int func_00461DF0(UnkStruct_00461DF0 * self, int p1)
{
    int v0 = p1;
    UnkStruct_00461DF0_frame * c2;
    float y0;
    UnkStruct_00461DF0_frame * t6;
    Prepare__20CB3MenuComponentBaseFv(self);
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    void * fr = scene->field_14;
    self->field_9C = 0;
    self->field_A0 = -1.0f;
    self->field_94 = 0;
    self->field_98 = 0;
    self->field_8C = 0;
    self->field_AC = 0;
    self->field_A4 = 70.0f;
    const bool t1 = 0 != v0;
    self->field_A8 = 70.0f;
    if (!(t1)) {
    } else {
        int * t0 = &self->field_94;
        unsigned int t3;
        t3 = (int)((unsigned int)3 + (unsigned int)(*t0));
        self->field_94 = self->field_94 + 3;
    }
    int i;
    if (1) {
        i = 0;
    }
    while (func_00461DF0_inl1(i)) {
        self->field_C[i] = 0;
        i++;
    }
    self->field_90 = ConstructChild__10CGt2dFrameFv(fr);
    SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(self->field_90);
    UnkStruct_00461DF0_frame * c = self->field_90;
    float t5;
    const float x0 = (t5 = D_004D3A60.v);
    y0 = D_004D3A64.v;
    self->field_90->field_0 = x0;
    c->field_4 = y0;
    union { unsigned long l; struct { float x, y; } f; } u, t;
    t.f.x = D_004D3A68.v - D_004D3A60.v;
    UnkStruct_00461DF0_frame * t8 = self->field_90;
    t.f.y = D_004D3A6C.v - D_004D3A64.v;
    u.l = t.l;
    t6 = t8;
    c2 = t6;
    float t7 = u.f.x;
    c2->field_8 = t7;
    c2->field_C = u.f.y;
    *(UnkStruct_00461DF0_frame **)(scene->field_2C + self->field_8 * 16 + 0xC) = self->field_90;
    return 1;
}
