// CB3PlayerCameraStateDebug::Action(EGtStateAction,void*,void*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PlayerCameraStateDebug.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (vfunc_14 passes compare const 0xD (leftover a1)).

// a123: 102/102 instrs, 2 changed: the 0xD case-compare constant is in a0 (retail a1; retail: 0x18/0x11/0xF a0, 0xD a1, 7 v1). Tried id local, braces, hoisting; vfunc_14(p0,0) passes action in a1 [G]

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
extern "C" void SetActiveBehaviour__22CB3PlayerCameraManagerFi(void *, int);
extern "C" void func_002E90C0(void *);
enum EGtStateAction { UnkEnum_SA_0 };
extern "C" UnkStruct_E7480_st * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

struct UnkStruct_E7F00_mgr {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int);
    virtual void vfunc_18(UnkStruct_E7480_st *, int);
    virtual void vfunc_1C(void *, int);
    UnkStruct_E7480_st * field_4;
    unsigned char pad_8[0x8];
    UnkStruct_E7480_tgt * field_10;
    float field_14;
};

class CB3PlayerCameraStateDebug {
public:
    void Action(EGtStateAction, void *, void *, void *);

    unsigned char pad_0[0x10];
    unsigned long field_10;
};

// 0x002E7F00
void CB3PlayerCameraStateDebug::Action(EGtStateAction p0, void * p1, void * p2, void * p3)
{
    UnkStruct_E7F00_mgr * m = (UnkStruct_E7F00_mgr *)p1;
    switch (p0) {
    case 3:
        field_10 = *(unsigned long *)p2;
        SetActiveBehaviour__22CB3PlayerCameraManagerFi(m, 0);
        break;
    case 5:
        switch ((int)p2) {
        case 7:
            m->vfunc_14(0xD, 0); // [G] a1 leftover = compare constant 0xD (reused register), not a real argument
            break;
        case 0xD: {
            UnkStruct_E7480_st * r = GetStateFromID__6CGtFSMFUl(m, field_10);
            if (m->field_4 != r) {
                m->vfunc_18(r, 0);
                UnkStruct_E7480_st * old = m->field_4;
                m->field_4 = r;
                if (m->field_10 != 0) {
                    m->field_14 = m->field_10->field_20;
                    if (r != 0) {
                        r->field_8 = m->field_10->field_20;
                    }
                }
                m->vfunc_1C(old, 0);
            }
            break;
        }
        case 0xF:
            field_10 = 0xBA38E6DCF8C737FFUL;
            break;
        case 0x11:
            field_10 = 0xBA38E6DCA6D42A7FUL;
            break;
        case 0x18:
            func_002E90C0((char *)m + 0x70);
            break;
        }
        break;
    }
}
