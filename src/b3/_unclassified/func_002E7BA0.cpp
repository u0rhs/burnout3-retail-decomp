// Hand-written; the lifter refused it (a88: CB3PlayerCameraManager::Construct(int)).

// Hand-written; lifter refused (a88: CB3PlayerCameraManager::Construct(int), shape of func_00421E50 for the state change).
// [L] DNAT: CB3PlayerCameraManager::Construct(int) (research/proto/new_names.csv, high)
struct UnkStruct_002E7BA0_1 { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_002E7BA0_2 { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E86500 { unsigned char pad_0[0x10]; };
struct UnkStruct_002E7BA0 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_002E7BA0_2 *, int);
    virtual void vfunc_1C(void *, int);
    void * field_4;
    unsigned char pad_8[0x8];
    UnkStruct_002E7BA0_1 * field_10;
    float field_14;
    unsigned char pad_18[0xB68];
    unsigned long field_B80;
    int field_B88;
    unsigned char pad_B8C[0x4];
    int field_B90;
    unsigned char pad_B94[0x10];
    unsigned char field_BA4;
    unsigned char field_BA5;
    unsigned char pad_BA6;
    unsigned char field_BA7;
};
struct UnkStruct_CSO { unsigned char pad_0[0x8]; };
extern UnkStruct_CSO maOffsetTable__22CB3PlayerCameraManager[];
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_01E86500 D_01E86500;
extern int mgpCameraBuffer__22CB3PlayerCameraManager;
extern int meLoadState__22CB3PlayerCameraManager;
extern "C" void Construct__6CGtFSMFPvPC14CGtStateOffsetP8CGtTimer(void *, void *, const void *, void *);
extern "C" void Construct__22CB3CrashCameraDirectorFP22CB3PlayerCameraManager(void *, void *);
extern "C" void Construct__15CB3CameraEditorFP22CB3PlayerCameraManager(void *, void *);
extern "C" void func_004474E0(void *, void *);
extern "C" UnkStruct_002E7BA0_2 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x002E7BA0
extern "C" void Construct__22CB3PlayerCameraManagerFi(UnkStruct_002E7BA0 * self, int p0)
{
    self->field_B90 = p0;
    self->field_B88 = 0;
    Construct__6CGtFSMFPvPC14CGtStateOffsetP8CGtTimer(self, self, maOffsetTable__22CB3PlayerCameraManager, &D_00522660);
    Construct__22CB3CrashCameraDirectorFP22CB3PlayerCameraManager((char *)self + 0x18, self);
    self->field_BA4 = 0;
    self->field_BA5 = 0;
    self->field_BA7 = 0;
    self->field_B80 = 0;
    if (self->field_B90 == 0) {
        mgpCameraBuffer__22CB3PlayerCameraManager = 0;
        Construct__15CB3CameraEditorFP22CB3PlayerCameraManager(&D_01E86500, self);
        meLoadState__22CB3PlayerCameraManager = 0;
    }
    func_004474E0((char *)self + 0x50, self);
    UnkStruct_002E7BA0_2 * r1 = GetStateFromID__6CGtFSMFUl(self, 0xBA38E6DC828A38A1);
    if (self->field_4 == r1) return;
    self->vfunc_18(r1, 0);
    void * t0 = self->field_4;
    self->field_4 = (void *)r1;
    UnkStruct_002E7BA0_1 * t1 = self->field_10;
    if (t1 != 0) {
        self->field_14 = t1->field_20;
        if (r1 != 0) {
            r1->field_8 = self->field_10->field_20;
        }
    }
    self->vfunc_1C(t0, 0);
}
