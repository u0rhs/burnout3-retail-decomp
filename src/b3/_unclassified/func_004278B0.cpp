// Hand-written; the lifter refused it (hand-written CB3OptionsDisplayComponent::Release [L]; s=&D_01E903E0 declared before the vcall; car struct padded to 0x2460).

// func_004278B0 -- hand-written from the retail structure (lifter refused).
// [L] DNAT: CB3OptionsDisplayComponent::Release() (research/proto/new_names.csv, medium)

class CGt2dObject;

struct UnkStruct_004278B0_vt {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
};
struct UnkStruct_004278B0_ent {
    int field_0;
    int field_4;
};
struct UnkStruct_004278B0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x6];
    UnkStruct_004278B0_ent field_10[1];
    unsigned char pad_18[0x8];
    UnkStruct_004278B0_vt field_20;
    unsigned char pad_24[0x70];
    int field_94;
    unsigned char pad_98[0x5];
    signed char field_9D;
    signed char field_9E;
    unsigned char pad_9F[0x1];
    void * field_A0;
    unsigned char pad_A4[0x3C];
    void * field_E0;
};
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E7A800 { unsigned char pad_0[0x10]; };
struct UnkStruct_gVdbDatabase { int field_0; };
struct UnkStruct_004278B0_car {
    unsigned char pad_0[0x1910];
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    int field_1914;
    unsigned char pad_1918[0x2460 - 0x1918];
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12FCF0];
    UnkStruct_004278B0_car field_12FCF0[1];
};

extern UnkStruct_gVdbDatabase mpToolBase__Q27GtComms16CGtCommsToolBase;
extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_01E7A800 D_01E7A800;
extern UnkStruct_D_00522660 D_00522660;

extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(int, int);
extern "C" void func_00284260(void *);

// 0x004278B0
extern "C" void func_004278B0(UnkStruct_004278B0 * self)
{
    if (self->field_9D != -1) {
        int i = self->field_9D;
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (int)&self->field_10[i].field_0);
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (int)&self->field_10[i].field_4);
        D_00522660.field_12FCF0[self->field_9D].vfunc_10();
        self->field_9D = -1;
    }
    if (self->field_9E != -1) {
        int i = self->field_9E;
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (int)&self->field_10[i].field_0);
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (int)&self->field_10[i].field_4);
        D_00522660.field_12FCF0[self->field_9E].vfunc_10();
        self->field_9E = -1;
    }
    self->field_94 = 0;
    Release__20CB3MenuComponentBaseFv(self);
    UnkStruct_D_01E903E0 * const s = &D_01E903E0;
    self->field_20.vfunc_14();
    if (self->field_A0 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(s, self->field_8, self->field_A0);
        self->field_A0 = 0;
    }
    if (self->field_E0 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(s, self->field_8, self->field_E0);
        self->field_E0 = 0;
    }
    func_00284260(&D_01E7A800);
}
