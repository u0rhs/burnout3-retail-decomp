// CGtNetworkPlayerManager::PostUpdate(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNetworkPlayerManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a119: extern C extra params (a2,a3,f12); switch 1/0x18 init falls into 2 upd; declare i,j,o at top of case).

struct UnkStruct_PostUpdate_vt {
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
};
struct UnkStruct_PostUpdate_it {
    unsigned char pad_0[0x34];
    void *field_34;
    unsigned char pad_38[0x23C];
    void *field_274;
    unsigned char pad_278[0x10];
};
struct UnkStruct_PostUpdate_obj {
    unsigned char pad_0[0x4AC];
    int field_4AC;
};
class CGtNetworkPlayerManager;
struct UnkStruct_PostUpdate {
    int field_0;
    unsigned char field_4;
    unsigned char field_5;
    unsigned char pad_6[2];
    UnkStruct_PostUpdate_obj *field_8[1];
    unsigned char pad_C[0x1C];
    int field_28;
    unsigned char pad_2C[0x50];
    UnkStruct_PostUpdate_vt *field_7C;
    unsigned char pad_80[0xC];
    unsigned char field_8C;
    unsigned char pad_8D[3];
    int field_90;
    int field_94;
    unsigned char pad_98[0x308];
    unsigned char field_3A0[0x10];
    unsigned char pad_3B0[0x130];
    unsigned char field_4E0[0x10];
};
extern "C" void func_0022D9F0(void *);
extern "C" void func_0022DA20(void *);
extern "C" int func_0022D2A0(void *, void *);
extern "C" void func_00237030(void *);
extern "C" int func_00234AB0(void *, void *, void *, float);

// 0x00236C50
extern "C" int PostUpdate__23CGtNetworkPlayerManagerFi(UnkStruct_PostUpdate *self, void *p1_, int p2, void *p3_, float dt)
{
    int p1 = (int)p1_;
    int p3 = (int)p3_;
    switch (self->field_0) {
    case 1:
    case 0x18:
        self->field_7C = (UnkStruct_PostUpdate_vt *)p1;
        self->field_8C = 0xFF;
        self->field_94 = p2;
        self->field_90 = p3;
        self->field_4 = 0;
        ((UnkStruct_PostUpdate_vt *)self->field_7C)->vfunc_3C();
        int i;
        int j;
        UnkStruct_PostUpdate_obj *o;
        for (i = 0; i < self->field_28; i++) {
            o = self->field_8[i];
            if (o != 0) {
                for (j = 0; j < o->field_4AC; j++) {
                    UnkStruct_PostUpdate_it *it = (UnkStruct_PostUpdate_it *)((char *)o + j * 24);
                    func_0022D9F0(it->field_34);
                    if (it->field_274 != 0) {
                        func_0022DA20(it->field_274);
                    }
                }
            }
        }
        for (int k = 0; k < 10; k++) func_0022DA20(self->field_3A0 + k * 16);
        for (int k = 0; k < 10; k++) func_0022DA20((char *)self + 0x440 + k * 16);
        func_0022D2A0(self->field_7C, (void *)func_00237030);
        self->field_0 = 2;
    case 2:
        if (func_00234AB0(self->field_4E0, (void *)(p1), self, dt) == 0) {
            return 0;
        }
        self->field_0 = 0x17;
    case 0x17:
    default:
        break;
    }
    self->field_5 = 1;
    return 1;
}
