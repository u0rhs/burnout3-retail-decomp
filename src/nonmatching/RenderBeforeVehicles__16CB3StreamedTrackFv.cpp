// NONMATCHING: RenderBeforeVehicles__16CB3StreamedTrackFv -- retail 537 / ours 537 instructions, 5 in changed runs
// near2: 5 off (was 7). u = g->field_8 taken before n2, then u += n2->field_38: g->field_38 now in v0 as retail. Left: field_8 (retail v1, ours a0) and the lh index (retail a0, ours v1) swapped at 0x21CD18. Tried: index locals, int/unsigned byte-offset sums, operand orders, split decl/assign; sreg run (45 variants) no gain.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// CB3StreamedTrack::RenderBeforeVehicles() -- hand-written (L280) from the asm, cloned from the proven sibling
// CB3StreamedTrack::RenderAfterVehicles (B3StreamedTrackPS2_0021C590.cpp).
// [C] name: the mangled symbol in retail's tables. Area not evidenced, so _unclassified/ (docs/conventions.md).
// Field names are placeholders and every type is [G] (instruction widths).
// Shapes: the inlined toSPR DMA (field_1C4+0x60 -> 0x70002000, 0xC0 qwords) with its sync/sync.p + bc0f wait as
// small asm (C cannot express sync.p/bc0f); camera-data inline taking the camera; scratchpad rows reached as
// (char *)s + 0x70002000 (gives retail's lui at/ori at/addu immediate form, [G]); RenderInstances' count re-read through
// a const pun ([G], retail reloads it); n1 as a byte-offset pun ([G], retail recomputes the address).

typedef volatile unsigned int UnkStruct_0021C780_vu32;
#define UNK_0021C780_R32(a) (*(UnkStruct_0021C780_vu32 *)(a))

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
extern "C" void ReallySetupCameraData__16CB3TrackRendererFv(void *);
extern "C" void EndMaterial__16CB3TrackRendererFv(void *);
extern "C" void PrepareRenderStatesForRenderingTrack__16CB3TrackRendererFv(void *);
extern "C" void RestoreRenderStatesAfterRenderingTrack__16CB3TrackRendererFv(void *);
extern "C" void EndInstanceRender__16CB3TrackRendererFv(void *);
extern "C" void PushCameraForInstanceRendering__16CB3TrackRendererF19EB3RenderableCamera(void *, int);
extern "C" void RenderInstances__16CB3TrackRendererFScPC15CB3InstanceData(void *, signed char, const void *);
extern "C" void BeginInstanceRender__16CB3TrackRendererFPC15CB3InstanceMeshPC17CGtAxisAlignedBoxRC16CB3TrackMaterialff24EB3InstanceDistanceCheckbf(void *, const void *, const void *, const void *, float, float, int, bool, float);
extern "C" void RenderBackdrop__14CB3StaticTrackFRC17CB3BackdropObject(void *, const void *);
extern "C" void RenderWater__14CB3StaticTrackFfRC17CB3BackdropObjectPC17CB3BackdropObject(void *, float, const void *, const void *);
extern "C" int func_0026AF50(void *, void *, int, int);
extern "C" void func_0026AE30(void *, void *);

// [G] inlined camera-data refresh (the sibling's func_0021C590_inl1 with the camera as a parameter)
static inline void func_0021C780_inl1(int k)
{
    if (k == D_01E32AA9.field_0 && D_01E32AB0.field_0 == D_01E32AB8.field_0 && D_01E32AC0.field_0 == D_01E32AC8.field_0) return;
    D_01E32AA9.field_0 = k;
    D_01E32AB8.field_0 = D_01E32AB0.field_0;
    D_01E32AC8.field_0 = D_01E32AC0.field_0;
    if (D_01E32AA9.field_0 > -1) {
        ReallySetupCameraData__16CB3TrackRendererFv(&D_01E32A10);
    }
}

enum UnkEnum_0026A7E0 { UnkEnum_0026A7E0_0, UnkEnum_0026A7E0_1, UnkEnum_0026A7E0_2 };
struct UnkStruct_0021C780_mat {
    unsigned char pad_0[0xC];
    void *field_C;
    unsigned char pad_10[0x30];
};
struct UnkStruct_0021C780_mats {
    unsigned char pad_0[0x54];
    UnkStruct_0021C780_mat *field_54;
};
struct UnkStruct_0021C780_unit {
    unsigned char pad_0[0x24];
    unsigned short field_24;
    unsigned char pad_26[2];
};
struct UnkStruct_0021C780_bd {
    unsigned char pad_0[8];
};
struct UnkStruct_0021C780_inst {
    unsigned char pad_0[0x20];
    unsigned char field_20[8];
    unsigned char field_28[8];
    unsigned char field_30[8];
    short field_38;
    short field_3A;
    short field_3C;
    short field_3E;
    float field_40;
    float field_44;
    float field_48;
    unsigned char pad_4C[4];
};
struct UnkStruct_0021C780_g {
    unsigned char pad_0[8];
    UnkStruct_0021C780_unit *field_8;
    unsigned char pad_C[0x18];
    UnkStruct_0021C780_bd *field_24;
    unsigned char pad_28[4];
    UnkStruct_0021C780_bd *field_2C;
    UnkStruct_0021C780_bd *field_30;
    short field_34;
    unsigned char pad_36[2];
    UnkStruct_0021C780_inst *field_38;
};
// the unit table DMA'd to the scratchpad (0x70002000) from field_1C4 + 0x60
struct UnkStruct_0021C780_row {
    signed char field_0[0x53];
    signed char field_53[0x56];
};
struct UnkStruct_0021C780_spr {
    unsigned char pad_0[3];
    signed char field_3;
    unsigned char pad_4[0xA];
    signed char field_E;
    signed char field_F;
    unsigned char pad_10[4];
    short field_14[0x54];
    unsigned char pad_BC[1];
    UnkStruct_0021C780_row field_BD[17];
};
struct UnkStruct_0021C780_d {
    unsigned char pad_0[0x60];
    unsigned char field_60[0x10];
    float field_70;
};
struct UnkStruct_0021C780_bk {
    unsigned char pad_0[0x64];
    signed char field_64[8];
};
struct UnkStruct_0021C780_ins {
    signed char *field_0;
    void **field_4;
};
class CB3StreamedTrack {
public:
    void RenderBeforeVehicles();
    void DoUnitFrustumTesting();

    unsigned char pad_0[0x44];
    unsigned char field_44;
    unsigned char pad_45[0x13];
    unsigned short field_58[17];
    unsigned char pad_7A[2];
    UnkStruct_0021C780_mats *field_7C[17];
    unsigned char pad_C0[4];
    UnkStruct_0021C780_mats *field_C4[17];
    unsigned char pad_108[4];
    UnkStruct_0021C780_ins *field_10C[17];
    unsigned char pad_150[0x74];
    UnkStruct_0021C780_d *field_1C4;
    UnkStruct_0021C780_bk *field_1C8;
};
struct UnkStruct_D_0064C994 {
    UnkStruct_0021C780_g *field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_0064C990 {
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_00665F1D {
    unsigned char field_0;
    unsigned char pad_1[0xF];
};
extern UnkStruct_D_0064C990 D_0064C990;
extern UnkStruct_D_0064C994 D_0064C994;
extern UnkStruct_D_00665F1D D_00665F1D;
extern UnkStruct_D_00665F1D D_00665F1F;
extern UnkStruct_D_00665F1D D_00665F20;
extern UnkStruct_D_00665F1D D_00665F21;
extern UnkStruct_D_00665F1D D_00665F22;
extern UnkStruct_D_00665F1D D_004EB8F6;

// [G] inlined per-camera flag read (2 bits per camera in field_58)
static inline int func_0021C780_inl2(CB3StreamedTrack *t, int i, int c)
{
    return (t->field_58[i] >> (c * 2)) & 3;
}

// N182: [G] scoped to this function
#pragma push
#pragma opt_arithtransformation off
// 0x0021C780
void CB3StreamedTrack::RenderBeforeVehicles()
{
    int i;
    int c;
    int s;
    if (field_44 == 0) return;
    UnkStruct_0021C780_g *g = D_0064C994.field_0;
    DoUnitFrustumTesting();
    // [G] inlined scratchpad upload (toSPR, DMA channel 9)
    unsigned int src = (unsigned int)field_1C4->field_60;
    UNK_0021C780_R32(0x1000E010) = 0x200;
    UNK_0021C780_R32(0x1000D480) = 0x70002000;
    UNK_0021C780_R32(0x1000D410) = src;
    UNK_0021C780_R32(0x1000D420) = 0xC0;
    UNK_0021C780_R32(0x1000D400) = 0x100;
    asm("sync\nsync.p");
    if ((UNK_0021C780_R32(0x1000D400) & 0x100) != 0) {
        UNK_0021C780_R32(0x1000E020) = 0x200;
        asm("sync\nsync.p\nL280w1:\nnop\nnop\nnop\nnop\nnop\nbc0f L280w1");
        while ((UNK_0021C780_R32(0x1000D400) & 0x100) != 0) {
        }
    }
    UnkStruct_0021C780_spr *const spr = (UnkStruct_0021C780_spr *)0x70002000;
    PrepareRenderStatesForRenderingTrack__16CB3TrackRendererFv(&D_01E32A10);
    for (i = 0; i < 8; i++) {
        int b = field_1C8->field_64[i];
        if (b >= 0 && D_00665F1D.field_0 != 0) {
            RenderBackdrop__14CB3StaticTrackFRC17CB3BackdropObject(&D_0064C990, &g->field_24[b]);
        }
    }
    for (s = 0; s < spr->field_3; s++) {
        func_0021C780_inl1(-1);
        func_0026AE30(&D_01E32A10, &g->field_8[spr->field_14[s]]);
        if (D_00665F1F.field_0 != 0 && D_004EB8F6.field_0 == 0) {
            func_0021C780_inl1(0);
            for (i = 0; i < 17; i++) {
                int fl = field_58[i] & 3;
                if (fl != 0) {
                    int m = ((UnkStruct_0021C780_spr *)((char *)s + 0x70002000))->field_BD[i].field_0[0];
                    if (m >= 0) {
                        UnkStruct_0021C780_mat *e = &field_7C[i]->field_54[m];
                        if (e->field_C != 0) {
                            func_0026AF50(&D_01E32A10, e, fl, 0);
                        }
                    }
                }
            }
        }
        if (D_00665F20.field_0 != 0) {
            for (c = 1; c < 4; c++) {
                func_0021C780_inl1(c);
                for (i = 0; i < 17; i++) {
                    UnkStruct_0021C780_mats *p = field_C4[i];
                    if (p != 0) {
                        int fl = (field_58[i] >> (c * 2)) & 3;
                        if (fl != 0) {
                            int m = ((UnkStruct_0021C780_spr *)((char *)s + 0x70002000))->field_BD[i].field_53[0];
                            if (m >= 0) {
                                UnkStruct_0021C780_mat *e = &p->field_54[m];
                                if (e->field_C != 0) {
                                    func_0026AF50(&D_01E32A10, e, fl, 1);
                                }
                            }
                        }
                    }
                }
            }
        }
        EndMaterial__16CB3TrackRendererFv(&D_01E32A10);
    }
    bool far;
    int t;
    for (t = 0; t < g->field_34; t++) {
        float h = 0.0f;
        far = false;
        int fl = g->field_38[t].field_3E;
        if (fl & 4) {
            h = g->field_38[t].field_48;
            far = true;
        }
        if ((fl & 2) && D_00665F22.field_0 != 0) {
            UnkStruct_0021C780_inst *n1 = (UnkStruct_0021C780_inst *)((char *)g->field_38 + t * 0x50);
            BeginInstanceRender__16CB3TrackRendererFPC15CB3InstanceMeshPC17CGtAxisAlignedBoxRC16CB3TrackMaterialff24EB3InstanceDistanceCheckbf(
                &D_01E32A10, n1->field_30, n1, &g->field_8[n1->field_3C], n1->field_40, n1->field_44, 0, far, h);
            PushCameraForInstanceRendering__16CB3TrackRendererF19EB3RenderableCamera(&D_01E32A10, 1);
            PushCameraForInstanceRendering__16CB3TrackRendererF19EB3RenderableCamera(&D_01E32A10, 2);
            PushCameraForInstanceRendering__16CB3TrackRendererF19EB3RenderableCamera(&D_01E32A10, 3);
            for (i = 0; i < 17; i++) {
                UnkStruct_0021C780_ins *p = field_10C[i];
                if (p != 0) {
                    if (p->field_0[t] != 0) {
                        int m = func_0021C780_inl2(this, i, 1) | func_0021C780_inl2(this, i, 2);
                        m |= func_0021C780_inl2(this, i, 3);
                        if (m != 0) {
                            RenderInstances__16CB3TrackRendererFScPC15CB3InstanceData(&D_01E32A10, *(const signed char *)&p->field_0[t], p->field_4[t]);
                        }
                    }
                }
            }
            EndInstanceRender__16CB3TrackRendererFv(&D_01E32A10);
        }
        UnkStruct_0021C780_unit *u = g->field_8;
        UnkStruct_0021C780_inst *n2 = &g->field_38[t];
        u += n2->field_38;
        if ((u->field_24 & 4) && D_00665F21.field_0 != 0) {
            BeginInstanceRender__16CB3TrackRendererFPC15CB3InstanceMeshPC17CGtAxisAlignedBoxRC16CB3TrackMaterialff24EB3InstanceDistanceCheckbf(
                &D_01E32A10, n2->field_20, n2, u, n2->field_40, n2->field_44, (n2->field_3E & 1) ? UnkEnum_0026A7E0_1 : UnkEnum_0026A7E0_0, far, h);
            PushCameraForInstanceRendering__16CB3TrackRendererF19EB3RenderableCamera(&D_01E32A10, 0);
            for (i = 0; i < 17; i++) {
                if ((field_58[i] & 3) != 0) {
                    UnkStruct_0021C780_ins *p = field_10C[i];
                    if (p->field_0[t] != 0) {
                        RenderInstances__16CB3TrackRendererFScPC15CB3InstanceData(&D_01E32A10, *(const signed char *)&p->field_0[t], p->field_4[t]);
                    }
                }
            }
            EndInstanceRender__16CB3TrackRendererFv(&D_01E32A10);
            UnkStruct_0021C780_inst *n3 = &g->field_38[t];
            if (n3->field_3E & 1) {
                BeginInstanceRender__16CB3TrackRendererFPC15CB3InstanceMeshPC17CGtAxisAlignedBoxRC16CB3TrackMaterialff24EB3InstanceDistanceCheckbf(
                    &D_01E32A10, n3->field_28, n3, &g->field_8[n3->field_3A], n3->field_40, n3->field_44, 2, far, h);
                PushCameraForInstanceRendering__16CB3TrackRendererF19EB3RenderableCamera(&D_01E32A10, 0);
                for (i = 0; i < 17; i++) {
                    if ((field_58[i] & 3) != 0) {
                        UnkStruct_0021C780_ins *p = field_10C[i];
                        if (p->field_0[t] != 0) {
                            RenderInstances__16CB3TrackRendererFScPC15CB3InstanceData(&D_01E32A10, *(const signed char *)&p->field_0[t], p->field_4[t]);
                        }
                    }
                }
                EndInstanceRender__16CB3TrackRendererFv(&D_01E32A10);
            }
        }
    }
    if (D_00665F1D.field_0 != 0) {
        int w = spr->field_E;
        if (w >= 0) {
            UnkStruct_0021C780_bd *o = 0;
            int w2 = spr->field_F;
            if (w2 >= 0) o = &g->field_30[w2];
            float lv;
            if (field_1C4 == 0) lv = 0.0f;
            else lv = field_1C4->field_70;
            RenderWater__14CB3StaticTrackFfRC17CB3BackdropObjectPC17CB3BackdropObject(&D_0064C990, lv, &g->field_2C[w], o);
        }
    }
    RestoreRenderStatesAfterRenderingTrack__16CB3TrackRendererFv(&D_01E32A10);
}
#pragma pop
