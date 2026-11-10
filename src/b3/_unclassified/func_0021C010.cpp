// func_0021C010 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (element sub-struct at +0x3D0 (0x12A980+0x3D0 folded) taken before the tests; func_00131E40 takes only a0 (phantom a1/a2 dropped); && / || chains).

// from build/vt\try_func_0021C010_best.cpp
// func_0021C010 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0021C010;
struct UnkStruct_0021C010_10;
struct UnkStruct_0021C010_2;
struct UnkStruct_0021C010_7;
struct UnkStruct_0021C010_9;
struct UnkStruct_0021C010_e0;
struct UnkStruct_0021C010_e1;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0064C990;
struct UnkStruct_D_0064C994;
struct UnkStruct_D_00665E53;
struct UnkStruct_D_00665F1E;
struct UnkStruct_D_01E32A10;

struct UnkStruct_D_0064C994 {
    UnkStruct_0021C010_7 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0021C010_2 {
    unsigned char pad_0[0x6D];
    signed char field_6D;
};

struct UnkStruct_D_00665F1E {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0021C010_s {
    unsigned char pad_0[0x18EA];
    unsigned char field_18EA;
};

struct UnkStruct_0021C010_e0 {
    unsigned char pad_0[0x3D0];
    UnkStruct_0021C010_s field_3D0;
    unsigned char pad_1CBB[0xB15];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12A980];
    UnkStruct_0021C010_e0 field_12A980[1];  // [G] element count unknown
};

struct UnkStruct_D_00665E53 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0021C010_7 {
    unsigned char pad_0[0x28];
    UnkStruct_0021C010_e1 * field_28;
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_0021C010_9 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0021C010_9 {
    unsigned char pad_0[0x1B4];
    UnkStruct_0021C010_10 * field_1B4;
};

struct UnkStruct_0021C010_10 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual int vfunc_AC();
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32A10 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0021C010_e1 {
    unsigned char pad_0[0x8];
};

struct UnkStruct_D_0064C990 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0021C010 {
    unsigned char pad_0[0x1C];
    int field_1C;
    unsigned char pad_20[0x24];
    unsigned char field_44;
    unsigned char pad_45[0x183];
    UnkStruct_0021C010_2 * field_1C8;
};

extern UnkStruct_D_0064C994 D_0064C994;
extern UnkStruct_D_00665F1E D_00665F1E;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_00665E53 D_00665E53;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_01E32A10 D_01E32A10;
extern UnkStruct_D_0064C990 D_0064C990;

extern "C" void PrepareRenderStatesForRenderingTrack__16CB3TrackRendererFv(void *);  // CB3TrackRenderer::PrepareRenderStatesForRenderingTrack()
extern "C" void RenderBackdrop__14CB3StaticTrackFRC17CB3BackdropObject(void *, void *);  // CB3StaticTrack::RenderBackdrop(const CB3BackdropObject&)
extern "C" void RestoreRenderStatesAfterRenderingTrack__16CB3TrackRendererFv(void *);  // CB3TrackRenderer::RestoreRenderStatesAfterRenderingTrack()
extern "C" int func_00131E40(void *);

// 0x0021C010
extern "C" void func_0021C010(UnkStruct_0021C010 * self)
{
    if (self->field_44 != 0) {
        UnkStruct_0021C010_7 * t0 = D_0064C994.field_0;
        UnkStruct_0021C010_s * e = &D_00522660.field_12A980[self->field_1C].field_3D0;
        if (self->field_1C8->field_6D >= 0 && D_00665F1E.field_0 != 0 && e->field_18EA == 0 && D_00665E53.field_0 == 0) {
            if (func_00131E40(&D_004EE040) == 0 || D_0051BA88.field_0->field_1B4->vfunc_AC() == 0) {
                PrepareRenderStatesForRenderingTrack__16CB3TrackRendererFv(&D_01E32A10);
                RenderBackdrop__14CB3StaticTrackFRC17CB3BackdropObject(&D_0064C990, &t0->field_28[self->field_1C8->field_6D]);
                RestoreRenderStatesAfterRenderingTrack__16CB3TrackRendererFv(&D_01E32A10);
            }
        }
    }
}
