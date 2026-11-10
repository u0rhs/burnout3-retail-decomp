// CB3StaticTrack::RenderStaticObject(const CB3StaticTrackObject&) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StaticTrackPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (a66: lifter's triplicated update block folded to one 'if (A==0 && B==C && D==E) {} else {update}' (empty-then), r0==2 ? 1 : 3 arm order, '> -1' for slti at, callee takes const CB3StaticTrackObject*).

// lifter variant 0
// CB3StaticTrack::RenderStaticObject(const CB3StaticTrackObject&) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StaticTrackPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3StaticTrackObject;

class CB3StaticTrack;
struct CB3StaticTrackObject;
struct UnkStruct_0021D770_3;
struct UnkStruct_0021D770_e1;
struct UnkStruct_0021D770_e2;
struct UnkStruct_D_00666330;
struct UnkStruct_D_01E32A10;
struct UnkStruct_D_01E32AA9;
struct UnkStruct_D_01E32AB0;
struct UnkStruct_D_01E32AB8;
struct UnkStruct_D_01E32AC0;
struct UnkStruct_D_01E32AC8;

struct CB3StaticTrackObject {
    unsigned char pad_0[0x40];
    short field_40;
    unsigned char pad_42[0x2];
    UnkStruct_0021D770_e2 * field_44;
    short * field_48;
};

struct UnkStruct_0021D770_3 {
    unsigned char pad_0[0x8];
    UnkStruct_0021D770_e1 * field_8;
};

struct UnkStruct_D_01E32AA9 {
    signed char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32AB0 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32AB8 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32AC0 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32AC8 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00666330 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32A10 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0021D770_e1 {
    unsigned char pad_0[0x28];
};

struct UnkStruct_0021D770_e2 {
    unsigned char pad_0[0x40];
};

class CB3StaticTrack {
public:
    void RenderStaticObject(const CB3StaticTrackObject& p0);

    unsigned char pad_0[0x4];
    UnkStruct_0021D770_3 * field_4;
};

extern UnkStruct_D_01E32AA9 D_01E32AA9;
extern UnkStruct_D_01E32AB0 D_01E32AB0;
extern UnkStruct_D_01E32AB8 D_01E32AB8;
extern UnkStruct_D_01E32AC0 D_01E32AC0;
extern UnkStruct_D_01E32AC8 D_01E32AC8;
extern UnkStruct_D_00666330 D_00666330;
extern UnkStruct_D_01E32A10 D_01E32A10;

extern "C" void ReallySetupCameraData__16CB3TrackRendererFv(void *);  // CB3TrackRenderer::ReallySetupCameraData()
extern "C" void EndMaterial__16CB3TrackRendererFv(void *);  // CB3TrackRenderer::EndMaterial()
extern "C" int IntersectFrustum__14GtIntersectionFRC10CGtFrustumRC16CGtOrthogonalBox(void *, const CB3StaticTrackObject *);
extern "C" void func_0026AE30(void *, void *);
extern "C" int func_0026AF50(void *, void *, int, int);

// 0x0021D770
void CB3StaticTrack::RenderStaticObject(const CB3StaticTrackObject& p0)
{
    int r0 = IntersectFrustum__14GtIntersectionFRC10CGtFrustumRC16CGtOrthogonalBox(&D_00666330, &p0);
    if (r0 == 0) {
        return;
    }
    int v0;
    if (r0 == 2) {
        v0 = 1;
    } else {
        v0 = 3;
    }
    for (int i = 0; (i < p0.field_40); i++) {
        func_0026AE30(&D_01E32A10, &field_4->field_8[p0.field_48[i]]);
        if (D_01E32AA9.field_0 == 0 && D_01E32AB0.field_0 == D_01E32AB8.field_0 && D_01E32AC0.field_0 == D_01E32AC8.field_0) {
        } else {
            D_01E32AA9.field_0 = 0;
            D_01E32AB8.field_0 = D_01E32AB0.field_0;
            D_01E32AC8.field_0 = D_01E32AC0.field_0;
            if (D_01E32AA9.field_0 > -1) {
                ReallySetupCameraData__16CB3TrackRendererFv(&D_01E32A10);
            }
        }
        func_0026AF50(&D_01E32A10, &p0.field_44[i], v0, 0);
        EndMaterial__16CB3TrackRendererFv(&D_01E32A10);
    }
}
