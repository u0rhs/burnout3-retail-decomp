// Hand-written; the lifter refused it (scoped opt_dead_assignments off [G] (N182) around the function (pass2d pragma sweep)).

// near22: sreg found 'int i;' declared before the trk local (s3/s4 fixed, 22 -> 12). Left: BeginInstanceRender argument setup temps (retail field_3C in a1, index in v0/v1, addu a2,a1,v1; ours v1/a0/a1 and addu a2,v1,a1), and the inner k=0 'move s1,zero' scheduled 4 slots earlier. rec element-pointer forms change nothing

// func_002F99E0 -- CB3PropManager::Render(signed char,short,signed char*) [L] DNAT
#include "b3/classes/UnkStruct_D_0051BA88.h"
struct UnkStruct_002F99E0_rec {
    unsigned char pad_0[0x20];
    unsigned char field_20[0x18];
    short field_38;
    unsigned char pad_3A[0x6];
    float field_40;
    float field_44;
    unsigned char pad_48[0x8];
};
struct UnkStruct_002F99E0_mat { unsigned char pad_0[0x28]; };
struct UnkStruct_002F99E0_trk {
    unsigned char pad_0[0x8];
    UnkStruct_002F99E0_mat * field_8;
    unsigned char pad_C[0x30];
    UnkStruct_002F99E0_rec * field_3C;
    unsigned char pad_40[0x14];
    short field_54;
};
struct UnkStruct_D_0064C994 {
    UnkStruct_002F99E0_trk * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_002F99E0_e { unsigned short field_0; unsigned char field_2; unsigned char field_3; };
struct UnkStruct_002F99E0_f { unsigned short field_0; unsigned char field_2; unsigned char field_3; };
struct UnkStruct_002F99E0 {
    unsigned char pad_0[0x4];
    unsigned char * field_4;
    unsigned char pad_8[0x4];
    int field_C;
    unsigned char pad_10[0x2];
    unsigned char field_12;
    unsigned char pad_13[0x1];
    unsigned char ** field_14;
    UnkStruct_002F99E0_e *** field_18;
    UnkStruct_002F99E0_f field_1C[1];
};
struct UnkStruct_D_01E32A10 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E32A10 D_01E32A10;
extern UnkStruct_D_0064C994 D_0064C994;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern "C" void BeginInstanceRender__16CB3TrackRendererFPC15CB3InstanceMeshPC17CGtAxisAlignedBoxRC16CB3TrackMaterialff24EB3InstanceDistanceCheckbf(void *, const void *, const void *, const void *, float, float, int, bool, float);
extern "C" void PushCameraForInstanceRendering__16CB3TrackRendererF19EB3RenderableCamera(void *, int);
extern "C" void RenderInstances__16CB3TrackRendererFScPC15CB3InstanceData(void *, signed char, const void *);
extern "C" void EndInstanceRender__16CB3TrackRendererFv(void *);

// N182: [G] scoped to this function (pass2f pragma sweep: keeps retail's BeginInstanceRender argument registers
// and the late inner k = 0)
#pragma push
#pragma opt_dead_assignments off
// [L] DNAT: CB3PropManager::Render(signed char,short,signed char*) (research/proto/new_names.csv, medium)
// 0x002F99E0
extern "C" void func_002F99E0(UnkStruct_002F99E0 * self, signed char a1, short a2, signed char * a3)
{
    int i;
    UnkStruct_002F99E0_trk * trk = D_0064C994.field_0;
    if (D_0051BA88.field_0->field_1B4 != 0) {
        if (D_0051BA88.field_0->field_1B4->vfunc_B8() != 0) {
            return;
        }
    }
    for (i = 0; i < self->field_12; i++) {
        BeginInstanceRender__16CB3TrackRendererFPC15CB3InstanceMeshPC17CGtAxisAlignedBoxRC16CB3TrackMaterialff24EB3InstanceDistanceCheckbf(&D_01E32A10, trk->field_3C[i].field_20, &trk->field_3C[i], &trk->field_8[trk->field_3C[i].field_38], trk->field_3C[i].field_40 * trk->field_3C[i].field_40, trk->field_3C[i].field_44 * trk->field_3C[i].field_44, 0, false, 0.0f);
        PushCameraForInstanceRendering__16CB3TrackRendererF19EB3RenderableCamera(&D_01E32A10, 0);
        for (int j = 0; j < a1; j++) {
            short idx = a2 + a3[j];
            if (idx < 0) {
                idx = idx + trk->field_54;
            }
            short m = idx % trk->field_54;
            for (short k = 0; k < self->field_14[m][i]; k++) {
                UnkStruct_002F99E0_e * e = &self->field_18[m][i][k];
                if (e->field_3 != 2) {
                    RenderInstances__16CB3TrackRendererFScPC15CB3InstanceData(&D_01E32A10, 1, self->field_4 + e->field_0 * 64);
                }
            }
        }
        for (short q = 0; q < self->field_C; q++) {
            if (self->field_1C[q].field_2 == i && self->field_1C[q].field_3 != 2) {
                RenderInstances__16CB3TrackRendererFScPC15CB3InstanceData(&D_01E32A10, 1, self->field_4 + self->field_1C[q].field_0 * 64);
            }
        }
        EndInstanceRender__16CB3TrackRendererFv(&D_01E32A10);
    }
}
#pragma pop
