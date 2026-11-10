// CB3PlayerCameraManager::ActivateBehaviour(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PlayerCameraManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a79: sibling of DeactivateBehaviour (vfunc_10(&field_200) guarded by field_BA4; field_B80 |= 1UL<<idx)).

struct UnkStruct_Behaviour {
    // vptr at +0x0: placeholder virtuals by slot offset [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10(void *);
    virtual void vfunc_14(int);
};

class CB3PlayerCameraManager {
public:
// 0x002E7250
    void ActivateBehaviour(int idx);

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

// 0x002E72D0
void CB3PlayerCameraManager::ActivateBehaviour(int idx)
{
    if (field_BA4 != 0) {
        field_240[idx]->vfunc_10(field_200);
    }
    field_B80 |= 1UL << idx;
}
