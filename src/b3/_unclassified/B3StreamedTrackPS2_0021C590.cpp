// CB3StreamedTrack::RenderAfterVehicles() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamedTrackPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (decl order s,i,g gives s0/s1/s2; s is int; camera inline).

struct UnkStruct_D_01E32AA9 {
    signed char field_0;
    unsigned char pad_1[0xF];
};
struct UnkStruct_D_01E32AB0 {
    unsigned long field_0;
    unsigned char pad_8[0x8];
};
struct UnkStruct_D_01E32AB8 {
    unsigned long field_0;
    unsigned char pad_8[0x8];
};
struct UnkStruct_D_01E32AC0 {
    unsigned long field_0;
    unsigned char pad_8[0x8];
};
struct UnkStruct_D_01E32AC8 {
    unsigned long field_0;
    unsigned char pad_8[0x8];
};
struct UnkStruct_D_01E32A10 {
    unsigned char pad_0[0x10];
};
extern UnkStruct_D_01E32AA9 D_01E32AA9;
extern UnkStruct_D_01E32AB0 D_01E32AB0;
extern UnkStruct_D_01E32AB8 D_01E32AB8;
extern UnkStruct_D_01E32AC0 D_01E32AC0;
extern UnkStruct_D_01E32AC8 D_01E32AC8;
extern UnkStruct_D_01E32A10 D_01E32A10;
extern "C" void ReallySetupCameraData__16CB3TrackRendererFv(void *);  // CB3TrackRenderer::ReallySetupCameraData()
extern "C" void EndMaterial__16CB3TrackRendererFv(void *);  // CB3TrackRenderer::EndMaterial()
extern "C" void PrepareRenderStatesForRenderingTrack__16CB3TrackRendererFv(void *);
extern "C" void RestoreRenderStatesAfterRenderingTrack__16CB3TrackRendererFv(void *);
extern "C" int func_0026AF50(void *, void *, int, int);

// [G] inlined camera-data refresh (same as B3StaticTrackPS2_0021D550 func_0021D550_inl1)
static inline void func_0021C590_inl1()
{
    if (D_01E32AA9.field_0 == 0 && D_01E32AB0.field_0 == D_01E32AB8.field_0 && D_01E32AC0.field_0 == D_01E32AC8.field_0) return;
        D_01E32AA9.field_0 = 0;
        D_01E32AB8.field_0 = D_01E32AB0.field_0;
        D_01E32AC8.field_0 = D_01E32AC0.field_0;
        if (D_01E32AA9.field_0 > -1) {
            ReallySetupCameraData__16CB3TrackRendererFv(&D_01E32A10);
        }
}

struct UnkStruct_0021C590_mat {
    unsigned char pad_0[0xC];
    void *field_C;
    unsigned char pad_10[0x30];
};
struct UnkStruct_0021C590_mats {
    unsigned char pad_0[0x54];
    UnkStruct_0021C590_mat *field_54;
};
struct UnkStruct_0021C590_unit {
    unsigned char pad_0[0x28];
};
struct UnkStruct_0021C590_g {
    unsigned char pad_0[8];
    UnkStruct_0021C590_unit *field_8;
};
struct UnkStruct_0021C590_d {
    unsigned char pad_0[0x62];
    signed char field_62;
    signed char field_63;
    unsigned char pad_64[0x10];
    short field_74[1];
    unsigned char pad_76[0xA7];
    signed char field_11D[17][0xA9];
};
struct UnkStruct_0021C590_o {
    unsigned char pad_0[0x58];
};
class CB3StreamedTrack {
public:
    void RenderAfterVehicles();

    unsigned char pad_0[0x44];
    unsigned char field_44;
    unsigned char pad_45[0x13];
    unsigned short field_58[17];
    unsigned char pad_7A[2];
    UnkStruct_0021C590_mats *field_7C[17];
    unsigned char pad_C0[0x104];
    UnkStruct_0021C590_d *field_1C4;
};
struct UnkStruct_D_0064C994 {
    UnkStruct_0021C590_g *field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_00665F1F {
    unsigned char field_0;
    unsigned char pad_1[0xF];
};
struct UnkStruct_D_004EB8F6 {
    unsigned char field_0;
    unsigned char pad_1[0xF];
};
extern UnkStruct_D_0064C994 D_0064C994;
extern UnkStruct_D_00665F1F D_00665F1F;
extern UnkStruct_D_004EB8F6 D_004EB8F6;
extern "C" void func_0026AE30(void *, void *);

// 0x0021C590
void CB3StreamedTrack::RenderAfterVehicles()
{
    int s;
    int i;
    UnkStruct_0021C590_g *g = D_0064C994.field_0;
    if (field_44 != 0 && D_00665F1F.field_0 != 0 && D_004EB8F6.field_0 != 1) {
        PrepareRenderStatesForRenderingTrack__16CB3TrackRendererFv(&D_01E32A10);
        for (s = field_1C4->field_63; s < field_1C4->field_62; s++) {
            func_0026AE30(&D_01E32A10, &g->field_8[field_1C4->field_74[s]]);
            func_0021C590_inl1();
            for (i = 0; i < 17; i++) {
                int fl = field_58[i] & 3;
                if (fl != 0) {
                    int m = field_1C4->field_11D[i][s];
                    if (m >= 0) {
                        UnkStruct_0021C590_mat *e = &field_7C[i]->field_54[m];
                        if (e->field_C != 0) {
                            func_0026AF50(&D_01E32A10, e, fl, 0);
                        }
                    }
                }
            }
            EndMaterial__16CB3TrackRendererFv(&D_01E32A10);
        }
        RestoreRenderStatesAfterRenderingTrack__16CB3TrackRendererFv(&D_01E32A10);
    }
}
