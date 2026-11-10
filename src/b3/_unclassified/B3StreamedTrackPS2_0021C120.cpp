// CB3StreamedTrack::RenderAfterSpecular() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamedTrackPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a144: modelled on RenderAfterVehicles; locals order s,i,b,g; mesh/box args via g->field_38[s]; (unsigned)s+(unsigned)ptr for addu order; bool b; enum param; last loop uses block locals i2,s2).

enum UnkEnum_0026A7E0 { UnkEnum_0026A7E0_0 = 0, UnkEnum_0026A7E0_1 = 1, UnkEnum_0026A7E0_2 = 2 };
struct UnkStruct_D_01E32AA9 { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E32AB0 { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_D_01E32AB8 { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_D_01E32AC0 { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_D_01E32AC8 { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_D_01E32A10 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E32AA9 D_01E32AA9;
extern UnkStruct_D_01E32AB0 D_01E32AB0;
extern UnkStruct_D_01E32AB8 D_01E32AB8;
extern UnkStruct_D_01E32AC0 D_01E32AC0;
extern UnkStruct_D_01E32AC8 D_01E32AC8;
extern UnkStruct_D_01E32A10 D_01E32A10;
struct UnkStruct_D_0064A854 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0064A854 D_0064A854;
extern "C" void ReallySetupCameraData__16CB3TrackRendererFv(void *);
extern "C" void EndMaterial__16CB3TrackRendererFv(void *);
extern "C" void PrepareRenderStatesForRenderingTrack__16CB3TrackRendererFv(void *);
extern "C" void RestoreRenderStatesAfterRenderingTrack__16CB3TrackRendererFv(void *);
extern "C" int func_0026AF50(void *, void *, int, int);
extern "C" void func_0026AE30(void *, void *);
extern "C" void BeginInstanceRender__16CB3TrackRendererFPC15CB3InstanceMeshPC17CGtAxisAlignedBoxRC16CB3TrackMaterialff24EB3InstanceDistanceCheckbf(void *, const void *, const void *, const void *, float, float, UnkEnum_0026A7E0, bool, float);
extern "C" void PushCameraForInstanceRendering__16CB3TrackRendererF19EB3RenderableCamera(void *, int);
extern "C" void RenderInstances__16CB3TrackRendererFScPC15CB3InstanceData(void *, signed char, const void *);
extern "C" void EndInstanceRender__16CB3TrackRendererFv(void *);
extern "C" void func_002F99E0(void *, int, int, signed char *);

static inline void func_0021C120_inl1()
{
    if (D_01E32AA9.field_0 == 0 && D_01E32AB0.field_0 == D_01E32AB8.field_0 && D_01E32AC0.field_0 == D_01E32AC8.field_0) return;
        D_01E32AA9.field_0 = 0;
        D_01E32AB8.field_0 = D_01E32AB0.field_0;
        D_01E32AC8.field_0 = D_01E32AC0.field_0;
        if (D_01E32AA9.field_0 > -1) {
            ReallySetupCameraData__16CB3TrackRendererFv(&D_01E32A10);
        }
}

struct UnkStruct_0021C120_inst {
    unsigned char pad_0[0x20];
    unsigned char field_20[8];
    unsigned char field_28[0x10];
    short field_38;
    short field_3A;
    unsigned char pad_3C[2];
    short field_3E;
    float field_40;
    float field_44;
    float field_48;
    unsigned char pad_4C[4];
};
struct UnkStruct_0021C120_unit { unsigned char pad_0[0x24]; unsigned short field_24; unsigned char pad_26[2]; };
struct UnkStruct_0021C120_g {
    unsigned char pad_0[8];
    UnkStruct_0021C120_unit *field_8;
    unsigned char pad_C[0x28];
    short field_34;
    unsigned char pad_36[2];
    UnkStruct_0021C120_inst *field_38;
};
struct UnkStruct_0021C120_list {
    signed char *field_0;
    void **field_4;
};
struct UnkStruct_0021C120_mat { unsigned char pad_0[0xC]; void *field_C; unsigned char pad_10[0x30]; };
struct UnkStruct_0021C120_mats { unsigned char pad_0[0x54]; UnkStruct_0021C120_mat *field_54; };
struct UnkStruct_0021C120_d {
    unsigned char pad_0[0x61];
    signed char field_61;
    signed char field_62;
    unsigned char pad_63[0x11];
    short field_74[1];
    unsigned char pad_76[0xA7];
    signed char field_11D[17][0xA9];
};
struct UnkStruct_0021C120_o { unsigned char pad_0[4]; short field_4; unsigned char pad_6[0x114]; signed char field_11A[17][0xA9]; };
struct UnkStruct_D_0064C994 { UnkStruct_0021C120_g *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00665F1F { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_0064C994 D_0064C994;
extern UnkStruct_D_00665F1F D_00665F1F;
extern UnkStruct_D_00665F1F D_00665F21;
extern UnkStruct_D_00665F1F D_00665F23;
extern UnkStruct_D_00665F1F D_004EB8F6;

class CB3StreamedTrack {
public:
    void RenderAfterSpecular();

    unsigned char pad_0[0x44];
    unsigned char field_44;
    unsigned char pad_45[0x13];
    unsigned short field_58[17];
    unsigned char pad_7A[2];
    UnkStruct_0021C120_mats *field_7C[17];
    unsigned char pad_C0[0x4C];
    UnkStruct_0021C120_list *field_10C[17];
    unsigned char pad_150[0x74];
    UnkStruct_0021C120_d *field_1C4;
    UnkStruct_0021C120_o *field_1C8;
};

// 0x0021C120
void CB3StreamedTrack::RenderAfterSpecular()
{
    int s;
    int i;
    bool b;
    UnkStruct_0021C120_g *g = D_0064C994.field_0;
    if (field_44 == 0) return;
    PrepareRenderStatesForRenderingTrack__16CB3TrackRendererFv(&D_01E32A10);
    if (D_00665F21.field_0 != 0) {
        for (s = 0; s < g->field_34; s++) {
            UnkStruct_0021C120_inst *in = &g->field_38[s];
            float f = 0.0f;
            b = false;
            if (in->field_3E & 4) {
                f = in->field_48;
                b = true;
            }
            if (g->field_8[in->field_38].field_24 & 4) continue;
            BeginInstanceRender__16CB3TrackRendererFPC15CB3InstanceMeshPC17CGtAxisAlignedBoxRC16CB3TrackMaterialff24EB3InstanceDistanceCheckbf(&D_01E32A10, g->field_38[s].field_20, &g->field_38[s], &g->field_8[in->field_38], g->field_38[s].field_40, g->field_38[s].field_44, (in->field_3E & 1) ? UnkEnum_0026A7E0_1 : UnkEnum_0026A7E0_0, b, f);
            PushCameraForInstanceRendering__16CB3TrackRendererF19EB3RenderableCamera(&D_01E32A10, 0);
            for (i = 0; i < 17; i++) {
                if ((field_58[i] & 3) != 0) {
                    UnkStruct_0021C120_list *l = field_10C[i];
                    signed char *p = (signed char *)((unsigned)s + (unsigned)l->field_0);
                    if (*p != 0)
                        RenderInstances__16CB3TrackRendererFScPC15CB3InstanceData(&D_01E32A10, *(const signed char *)p, l->field_4[s]);
                }
            }
            EndInstanceRender__16CB3TrackRendererFv(&D_01E32A10);
            in = &g->field_38[s];
            if ((in->field_3E & 1) == 0) continue;
            BeginInstanceRender__16CB3TrackRendererFPC15CB3InstanceMeshPC17CGtAxisAlignedBoxRC16CB3TrackMaterialff24EB3InstanceDistanceCheckbf(&D_01E32A10, g->field_38[s].field_28, &g->field_38[s], &g->field_8[in->field_3A], in->field_40, in->field_44, UnkEnum_0026A7E0_2, b, f);
            PushCameraForInstanceRendering__16CB3TrackRendererF19EB3RenderableCamera(&D_01E32A10, 0);
            for (i = 0; i < 17; i++) {
                if ((field_58[i] & 3) != 0) {
                    UnkStruct_0021C120_list *l = field_10C[i];
                    signed char *p = (signed char *)((unsigned)s + (unsigned)l->field_0);
                    if (*p != 0)
                        RenderInstances__16CB3TrackRendererFScPC15CB3InstanceData(&D_01E32A10, *(const signed char *)p, l->field_4[s]);
                }
            }
            EndInstanceRender__16CB3TrackRendererFv(&D_01E32A10);
        }
    }
    if (D_00665F23.field_0 != 0) {
        signed char buf[17];
        for (i = 0; i < 17; i++) buf[i] = field_1C8->field_11A[i][0];
        func_002F99E0(&D_0064A854, 17, field_1C8->field_4, buf);
    }
    if (D_00665F1F.field_0 != 0 && D_004EB8F6.field_0 == 0) {
        int i2;
        int s2 = field_1C4->field_62;
        for (; s2 < field_1C4->field_61; s2++) {
            func_0026AE30(&D_01E32A10, &g->field_8[field_1C4->field_74[s2]]);
            func_0021C120_inl1();
            for (i2 = 0; i2 < 17; i2++) {
                int fl = field_58[i2] & 3;
                if (fl != 0) {
                    int m = field_1C4->field_11D[i2][s2];
                    if (m >= 0) {
                        UnkStruct_0021C120_mat *e = &field_7C[i2]->field_54[m];
                        if (e->field_C != 0) {
                            func_0026AF50(&D_01E32A10, e, fl, 0);
                        }
                    }
                }
            }
            EndMaterial__16CB3TrackRendererFv(&D_01E32A10);
        }
    }
    RestoreRenderStatesAfterRenderingTrack__16CB3TrackRendererFv(&D_01E32A10);
}
