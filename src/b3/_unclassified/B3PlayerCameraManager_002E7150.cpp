// CB3PlayerCameraManager::SetActiveBehaviour(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PlayerCameraManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (bits are 1UL << i (dsllv); flags field is unsigned long; vfunc_14(0)/vfunc_10(&field_200) behaviour calls guarded by field_BA4).

// CB3PlayerCameraManager::SetActiveBehaviour(int) -- hand-written (a69). Clears every active behaviour bit (calling the
// behaviour's vfunc_14(0) when the manager is active), then activates behaviour `idx` (vfunc_10(&this->field_200)).
// Layout [G] from instruction widths; standalone class (the shared header does not carry these fields).
struct UnkStruct_Behaviour {
    // vptr at +0x0: placeholder virtuals by slot offset [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10(void *);
    virtual void vfunc_14(int);
};

class CB3PlayerCameraManager {
public:
    void SetActiveBehaviour(int idx);

    unsigned char pad_0[0x200];
    unsigned char field_200[0x40];
    UnkStruct_Behaviour *field_240[20];
    unsigned char pad_290[0xB80 - 0x290];
    unsigned long field_B80;
    unsigned char pad_B88[0xBA0 - 0xB88];
    int field_BA0;
    unsigned char field_BA4;
    unsigned char pad_BA5;
    unsigned char field_BA6;
};

// 0x002E7150
void CB3PlayerCameraManager::SetActiveBehaviour(int idx)
{
    for (int i = 0; i < 20; i++) {
        unsigned long bit = 1UL << i;
        if ((field_B80 & bit) != 0) {
            if (field_BA4 != 0) {
                field_240[i]->vfunc_14(0);
            }
            field_B80 &= ~bit;
        }
    }
    if (field_BA4 != 0) {
        field_240[idx]->vfunc_10(&field_200);
    }
    field_B80 |= 1UL << idx;
    field_BA0 = idx;
    field_BA6 = 1;
}
