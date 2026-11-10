// CB3PlayerCameraManager::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PlayerCameraManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a123: behaviour mask loop with out-of-line vfunc_14, FSM state switch (vptr-first struct)).

struct UnkStruct_E7480_st {
    unsigned char pad_0[0x8];
    float field_8;
};
struct UnkStruct_E7480_tgt {
    unsigned char pad_0[0x20];
    float field_20;
};
struct UnkStruct_E7480_200 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    unsigned char pad_4[0x3C];
};
struct UnkStruct_E7480_beh {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10(void *);
    virtual void vfunc_14(int);
};
extern "C" UnkStruct_E7480_st * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

class CB3PlayerCameraManager {
public:
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_E7480_st *, int);
    virtual void vfunc_1C(void *, int);
    void Release();

    UnkStruct_E7480_st * field_4;
    unsigned char pad_8[0x8];
    UnkStruct_E7480_tgt * field_10;
    float field_14;
    unsigned char pad_18[0x1E8];
    UnkStruct_E7480_200 field_200;
    UnkStruct_E7480_beh * field_240[20];
    unsigned char pad_290[0xB80 - 0x290];
    unsigned long field_B80;
    unsigned char pad_B88[0xBA4 - 0xB88];
    unsigned char field_BA4;
};

// 0x002E7480
void CB3PlayerCameraManager::Release()
{
    for (int i = 0; i < 20; i++) {
        unsigned long m = 1UL << i;
        if (field_B80 & m) {
            if (field_BA4 != 0) {
                field_240[i]->vfunc_14(0);
            }
            field_B80 &= ~m;
        }
    }
    field_200.vfunc_14();
    for (int j = 0; j < 20; j++) {
        field_240[j]->vfunc_C();
    }
    field_200.vfunc_C();
    field_BA4 = 0;
    field_B80 = 0;
    UnkStruct_E7480_st * r = GetStateFromID__6CGtFSMFUl(this, 0xBA38E6DC828A38A1UL);
    if (field_4 != r) {
        vfunc_18(r, 0);
        UnkStruct_E7480_st * old = field_4;
        field_4 = r;
        if (field_10 != 0) {
            field_14 = field_10->field_20;
            if (r != 0) {
                r->field_8 = field_10->field_20;
            }
        }
        vfunc_1C(old, 0);
    }
}
