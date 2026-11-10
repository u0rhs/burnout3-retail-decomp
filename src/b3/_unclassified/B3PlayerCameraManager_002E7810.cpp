// CB3PlayerCameraManager::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PlayerCameraManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a146: array-member subobjects (no CSE), separate D_01E86534/5 externs; the lb constant 0x12C6FC shows as retail-only __moddi3+0x4C reloc (splat artifact, same as FlyAround 002ED310)).

struct UnkStruct_E7810_v {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
};
struct UnkStruct_E7810_cam {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    float field_4;
    unsigned char pad_8[0x38];
};
struct UnkStruct_E7810_st { unsigned long field_0; };
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12C6FC];
    signed char field_12C6FC;
    unsigned char pad_12C6FD[0x27D0 - 1];
};
struct UnkStruct_D_01E86530 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E86534 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E86535 { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_01E86530 D_01E86530;
extern UnkStruct_D_01E86534 D_01E86534;
extern UnkStruct_D_01E86535 D_01E86535;
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_00665EC0 D_00665EC0;
extern "C" {
void Construct__23CB3BehaviourInterpolateFP22CB3PlayerCameraManager(void *, void *);
void Construct__18CB3BehaviourEffectFP22CB3PlayerCameraManager(void *, void *);
void Construct__21CB3BehaviourTrackSideFi(void *, int);
void func_00446970(void *, int);
void Construct__25CB3BehaviourRaceCarFollowFib(void *, int, bool);
void Construct__18CB3BehaviourOffsetF16EB3BehaviourTypei(void *, int, int);
void Construct__21CB3BehaviourFlyAroundFi16EB3FlyAroundType(void *, int, int);
void AttachCameraToViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelectionP9CGtCamera(void *, int, void *);
void func_00447370(void *);
}
class CB3PlayerCameraManager {
public:
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int);
    int Prepare();
    UnkStruct_E7810_st *field_4;
    unsigned char pad_8[72];
    unsigned char field_50[32];
    unsigned char field_70[400];
    UnkStruct_E7810_cam field_200;
    void *field_240[20];
    unsigned char field_290[128];
    unsigned char field_310[40];
    unsigned char field_338[40];
    unsigned char field_360[64];
    unsigned char field_3A0[64];
    unsigned char field_3E0[64];
    unsigned char field_420[64];
    unsigned char field_460[64];
    unsigned char field_4A0[32];
    unsigned char field_4C0[32];
    unsigned char field_4E0[496];
    unsigned char field_6D0[496];
    unsigned char field_8C0[336];
    unsigned char field_A10[12];
    unsigned char field_A1C[20];
    unsigned char field_A30[144];
    unsigned char field_AC0[48];
    unsigned char field_AF0[64];
    unsigned char field_B30[88];
    int field_B88;
    int field_B8C;
    int field_B90;
    int field_B94;
    int field_B98;
    unsigned char pad_B9C[0x8];
    unsigned char field_BA4;
    unsigned char pad_BA5;
    unsigned char field_BA6;
};
static inline unsigned long func_E7810_inl1(UnkStruct_E7810_st *s)
{
    if (s != 0) return s->field_0;
    return 0x6D6123044330FCCFUL;
}
// 0x002E7810
int CB3PlayerCameraManager::Prepare()
{
    field_B8C = 0;
    field_B88 = 0;
    field_B98 = 0;
    D_01E86534.field_0 = 0;
    D_01E86535.field_0 = 0;
    field_B94 = *((signed char *)&D_00522660 + field_B90 * 0x27D0 + 0x12C6FC);
    ((UnkStruct_E7810_v *)field_A10)->vfunc_8();
    ((UnkStruct_E7810_v *)field_A1C)->vfunc_8();
    ((UnkStruct_E7810_v *)field_290)->vfunc_8();
    ((UnkStruct_E7810_v *)field_4E0)->vfunc_8();
    ((UnkStruct_E7810_v *)field_6D0)->vfunc_8();
    ((UnkStruct_E7810_v *)field_AF0)->vfunc_8();
    ((UnkStruct_E7810_v *)field_4C0)->vfunc_8();
    Construct__23CB3BehaviourInterpolateFP22CB3PlayerCameraManager(((UnkStruct_E7810_v *)field_8C0), this);
    Construct__18CB3BehaviourEffectFP22CB3PlayerCameraManager(((UnkStruct_E7810_v *)field_4A0), this);
    Construct__21CB3BehaviourTrackSideFi(((UnkStruct_E7810_v *)field_AC0), field_B90);
    func_00446970(((UnkStruct_E7810_v *)field_B30), field_B90);
    Construct__25CB3BehaviourRaceCarFollowFib(((UnkStruct_E7810_v *)field_310), field_B94, false);
    Construct__25CB3BehaviourRaceCarFollowFib(((UnkStruct_E7810_v *)field_338), field_B94, true);
    Construct__18CB3BehaviourOffsetF16EB3BehaviourTypei(((UnkStruct_E7810_v *)field_360), 0, field_B94);
    Construct__18CB3BehaviourOffsetF16EB3BehaviourTypei(((UnkStruct_E7810_v *)field_460), 1, field_B94);
    Construct__21CB3BehaviourFlyAroundFi16EB3FlyAroundType(((UnkStruct_E7810_v *)field_70), field_B90, 0);
    Construct__21CB3BehaviourFlyAroundFi16EB3FlyAroundType(((UnkStruct_E7810_v *)field_A30), field_B90, 1);
    Construct__18CB3BehaviourOffsetF16EB3BehaviourTypei(((UnkStruct_E7810_v *)field_3A0), 5, field_B94);
    Construct__18CB3BehaviourOffsetF16EB3BehaviourTypei(((UnkStruct_E7810_v *)field_3E0), 6, field_B94);
    Construct__18CB3BehaviourOffsetF16EB3BehaviourTypei(((UnkStruct_E7810_v *)field_420), 7, field_B94);
    field_240[1] = ((UnkStruct_E7810_v *)field_290);
    field_240[15] = ((UnkStruct_E7810_v *)field_4A0);
    field_240[16] = ((UnkStruct_E7810_v *)field_4C0);
    field_240[5] = ((UnkStruct_E7810_v *)field_360);
    field_240[4] = ((UnkStruct_E7810_v *)field_460);
    field_240[3] = ((UnkStruct_E7810_v *)field_338);
    field_240[2] = ((UnkStruct_E7810_v *)field_310);
    field_240[0] = ((UnkStruct_E7810_v *)field_70);
    field_240[14] = ((UnkStruct_E7810_v *)field_A30);
    field_240[6] = ((UnkStruct_E7810_v *)field_4E0);
    field_240[7] = ((UnkStruct_E7810_v *)field_6D0);
    field_240[10] = ((UnkStruct_E7810_v *)field_8C0);
    field_240[11] = ((UnkStruct_E7810_v *)field_A10);
    field_240[12] = ((UnkStruct_E7810_v *)field_A1C);
    field_240[8] = ((UnkStruct_E7810_v *)field_AC0);
    field_240[9] = ((UnkStruct_E7810_v *)field_AF0);
    field_240[13] = ((UnkStruct_E7810_v *)field_B30);
    field_240[17] = ((UnkStruct_E7810_v *)field_3A0);
    field_240[18] = ((UnkStruct_E7810_v *)field_3E0);
    field_240[19] = ((UnkStruct_E7810_v *)field_420);
    field_200.vfunc_8();
    if (field_B90 == 0) {
        AttachCameraToViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelectionP9CGtCamera(&D_00665EC0, 1, &field_200);
    } else {
        AttachCameraToViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelectionP9CGtCamera(&D_00665EC0, 2, &field_200);
    }
    field_200.field_4 = 90.0f;
    field_200.vfunc_10();
    field_BA6 = 1;
    field_BA4 = 1;
    if (func_E7810_inl1(field_4) == 0xBA38E6DC828A38A1UL) {
        vfunc_14(0x17, 0);
    }
    if (func_E7810_inl1(field_4) == 0xBA38E63A96099FBFUL && D_01E86530.field_0 == 2) {
        func_00447370(((UnkStruct_E7810_v *)field_50));
    }
    return 1;
}
