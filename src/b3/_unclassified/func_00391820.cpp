// Hand-written; the lifter refused it (a83: UpdateWaitInitCountdownHost [L] DNAT; inline CountActive (i declared before c, dead first call kept via int c1), n via const-int pun, bool flag tested as (int)have, a2 loaded before f58).

// func_00391820 -- CB3OnlineStageLogic::UpdateWaitInitCountdownHost() [L] DNAT (research/proto/new_names.csv, medium)
class CGtNetworkPlayerManager {
public:
    int GetMyPlayerID() const;
    unsigned char pad_0[0x8];
    int field_8[1];
};
enum UnkEnum_00391820 { UnkEnum_00391820_0, UnkEnum_00391820_1 };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_F { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_00391820 {
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
    virtual int vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual int vfunc_B8(int);
    unsigned char pad_4[0x50];
    float field_54;
    float field_58;
    unsigned char pad_5C[2];
    unsigned char field_5E;
};

extern CGtNetworkPlayerManager D_01E32AE0;
extern UnkStruct_I D_01E32B08, D_01E654A8, D_01E6549C;
extern UnkStruct_B D_01E654AC;
extern UnkStruct_F D_01E654A4, D_01E65458, D_004F50A0;
extern "C" void func_00270880(void *, int);
extern "C" void func_0026FAA0(void *, int);
extern "C" int func_0026CA50(void *, int, int);
extern "C" void *func_002366D0(void *, int);
extern "C" int func_001A85C0(void *, int, void *, float);

static inline int CountActive()
{
    int n = D_01E32B08.field_0;
    int i;
    int c = 0;
    for (i = 0; i < n; i++) {
        if (D_01E32AE0.field_8[i] != 0) {
            c++;
        }
    }
    return c;
}

// [L] DNAT: CB3OnlineStageLogic::UpdateWaitInitCountdownHost() (research/proto/new_names.csv, medium)
// 0x00391820
extern "C" int func_00391820(UnkStruct_00391820 * self)
{
    int arr[8];
    func_00270880(&D_01E32AE0, 1);
    func_0026FAA0(&D_01E32AE0, 1);
    int c1 = CountActive();
    int n = *(const int *)&D_01E32B08.field_0;
    int id = D_01E32AE0.GetMyPlayerID();
    int a2;
    bool have;
    if (D_01E654AC.field_0 != 0) {
        a2 = D_01E654A8.field_0;
        self->field_58 = D_01E654A4.field_0;
        have = true;
    } else {
        self->field_58 = -1.0f;
        a2 = -1;
        have = false;
    }
    if ((int)have) {
        if (func_0026CA50(&D_01E32AE0, id, a2)) {
            return 1;
        }
    }
    float limit;
    if (self->field_5E != 0) {
        limit = 45.0f;
    } else if (self->vfunc_A0()) {
        limit = 60.0f;
    } else {
        limit = 10.0f;
    }
    if (D_01E6549C.field_0 != CountActive()) {
        if (D_004F50A0.field_0 - self->field_54 <= limit) {
            return 0;
        }
    }
    int c3 = CountActive();
    if (self->vfunc_B8(c3)) {
        self->field_58 = 10.0f + D_01E65458.field_0;
    } else {
        self->field_58 = 5.0f + D_01E65458.field_0;
    }
    for (int i = 0; i < 8; i++) {
        arr[i] = -1;
    }
    for (int j = 0; j < n; j++) {
        char *p = (char *)func_002366D0(&D_01E32AE0, j);
        if (p) {
            func_001A85C0(p + 0xBBC, id, arr, self->field_58);
        }
    }
    float cur = self->field_58;
    D_01E654A8.field_0 = id;
    D_01E654A4.field_0 = cur;
    D_01E654AC.field_0 = 1;
    return 1;
}
