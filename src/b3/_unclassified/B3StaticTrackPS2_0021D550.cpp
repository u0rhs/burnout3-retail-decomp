// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// CB3StaticTrack::RenderWater(float,const CB3BackdropObject&,const CB3BackdropObject*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StaticTrackPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (camera-refresh block as static inline with early return when clean; element pointer for the water piece).

// from build/vt\try_RenderWater__14CB3StaticTrackFfRC17CB3Ba_best.cpp
// CB3StaticTrack::RenderWater(float,const CB3BackdropObject&,const CB3BackdropObject*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StaticTrackPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3BackdropObject;

class CB3StaticTrack;
struct CB3BackdropObject;
struct UnkStruct_0021D550_5;
struct UnkStruct_0021D550_e0;
struct UnkStruct_0021D550_e2;
struct UnkStruct_0021D550_e3;
struct UnkStruct_0021D550_e4;
struct UnkStruct_0021D550_e5;
struct UnkStruct_0021D550_e6;
struct UnkStruct_D_00666330;
struct UnkStruct_D_01E32A10;
struct UnkStruct_D_01E32AA9;
struct UnkStruct_D_01E32AB0;
struct UnkStruct_D_01E32AB8;
struct UnkStruct_D_01E32AC0;
struct UnkStruct_D_01E32AC8;
struct UnkStruct_D_01E32ADC;

struct UnkStruct_D_01E32ADC {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct CB3BackdropObject {
    short field_0;
    unsigned char pad_2[0x2];
    UnkStruct_0021D550_e0 * field_4;
};

struct UnkStruct_0021D550_e0 {
    unsigned char pad_0[0x40];
    short field_40;
    unsigned char pad_42[0x2];
    UnkStruct_0021D550_e5 * field_44;
    short * field_48;
    unsigned char pad_4C[0x4];
};

struct UnkStruct_0021D550_5 {
    unsigned char pad_0[0x8];
    UnkStruct_0021D550_e2 * field_8;
};

struct UnkStruct_0021D550_e2 {
    int field_0;
    unsigned char pad_4[0x24];
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

struct UnkStruct_0021D550_e3 {
    int field_0;
    unsigned char pad_4[0x24];
};

struct UnkStruct_D_00666330 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32A10 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0021D550_e4 {
    unsigned char pad_0[0x28];
};

struct UnkStruct_0021D550_e5 {
    unsigned char pad_0[0x40];
};

struct UnkStruct_0021D550_e6 {
    unsigned char pad_0[0x50];
};

class CB3StaticTrack {
public:
    void RenderWater(float p0, const CB3BackdropObject& p1, const CB3BackdropObject* p2);

    unsigned char pad_0[0x4];
    UnkStruct_0021D550_5 * field_4;
};

extern UnkStruct_D_01E32ADC D_01E32ADC;
extern UnkStruct_D_01E32AA9 D_01E32AA9;
extern UnkStruct_D_01E32AB0 D_01E32AB0;
extern UnkStruct_D_01E32AB8 D_01E32AB8;
extern UnkStruct_D_01E32AC0 D_01E32AC0;
extern UnkStruct_D_01E32AC8 D_01E32AC8;
extern UnkStruct_D_00666330 D_00666330;
extern UnkStruct_D_01E32A10 D_01E32A10;

extern "C" void ReallySetupCameraData__16CB3TrackRendererFv(void *);  // CB3TrackRenderer::ReallySetupCameraData()
extern "C" void EndMaterial__16CB3TrackRendererFv(void *);  // CB3TrackRenderer::EndMaterial()
extern "C" void RenderStaticObject__14CB3StaticTrackFRC20CB3StaticTrackObject(void *, const void *);  // CB3StaticTrack::RenderStaticObject(const CB3StaticTrackObject&)
extern "C" int IntersectFrustum__14GtIntersectionFRC10CGtFrustumRC16CGtOrthogonalBox(void *, void *);
extern "C" void func_0026AE30(void *, void *, short);
extern "C" int func_0026AF50(void *, void *, int, int);

// [G] inlined camera-data refresh (likely a CB3TrackRenderer inline, cf. CB3VehicleRenderer::SetupCameraData;
// name not in any table): dirty flag / cached-value compares, early return when clean
static inline void func_0021D550_inl1()
{
    if (D_01E32AA9.field_0 == 0 && D_01E32AB0.field_0 == D_01E32AB8.field_0 && D_01E32AC0.field_0 == D_01E32AC8.field_0) return;
        D_01E32AA9.field_0 = 0;
        D_01E32AB8.field_0 = D_01E32AB0.field_0;
        D_01E32AC8.field_0 = D_01E32AC0.field_0;
        if (D_01E32AA9.field_0 > -1) {
            ReallySetupCameraData__16CB3TrackRendererFv(&D_01E32A10);
        }
}

// 0x0021D550
void CB3StaticTrack::RenderWater(float p0, const CB3BackdropObject& p1, const CB3BackdropObject* p2)
{
    if (p2 != 0) {
        D_01E32ADC.field_0 = p0;
        for (int i = 0; (i < p2->field_0); i++) {
            UnkStruct_0021D550_e0 * t0 = &p2->field_4[i];
            if (IntersectFrustum__14GtIntersectionFRC10CGtFrustumRC16CGtOrthogonalBox(&D_00666330, t0) != 0) {
                for (int i1 = 0; (i1 < t0->field_40); i1++) {
                    short t3 = t0->field_48[i1];
                    UnkStruct_0021D550_e2 * t4 = field_4->field_8;
                    int t5 = t4[t3].field_0;
                    t4[t3].field_0 = 7;
                    func_0026AE30(&D_01E32A10, &((UnkStruct_0021D550_e4 *)field_4->field_8)[t3], t3);
                    func_0021D550_inl1();
                    func_0026AF50(&D_01E32A10, &t0->field_44[i1], 3, 0);
                    EndMaterial__16CB3TrackRendererFv(&D_01E32A10);
                    ((UnkStruct_0021D550_e3 *)field_4->field_8)[t3].field_0 = t5;
                }
            }
        }
    }
    for (int i2 = 0; (i2 < p1.field_0); i2++) {
        RenderStaticObject__14CB3StaticTrackFRC20CB3StaticTrackObject(this, &((UnkStruct_0021D550_e6 *)p1.field_4)[i2]);
    }
}
