// CB3PlayerCameraStateInactive::Action(EGtStateAction,void*,void*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PlayerCameraStateInactive.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a128: switch default first, case 3 before 5, inner cases ascending; sibling of func_002E7BA0 state-change tail).

enum EGtStateAction {};
typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_002E80A0_1 { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_002E80A0_2 { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_002E80A0_F {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_002E80A0_2 *, int);
    virtual void vfunc_1C(void *, int);
    void * field_4;
    unsigned char pad_8[0x8];
    UnkStruct_002E80A0_1 * field_10;
    float field_14;
};
extern "C" UnkStruct_002E80A0_2 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
class CB3PlayerCameraStateInactive {
public:
    void Action(EGtStateAction p0, void* p1, void* p2, void* p3);
    unsigned char pad_0[0x10];
    unsigned long field_10;
};

// 0x002E80A0
void CB3PlayerCameraStateInactive::Action(EGtStateAction p0, void* p1, void* p2, void* p3)
{
    UnkStruct_002E80A0_F * fsm = (UnkStruct_002E80A0_F *)p1;
    switch (p0) {
    default:
        break;
    case 3:
        if (p2 != 0) {
            field_10 = *(unsigned long *)p2;
        } else {
            field_10 = 0xBA38E6DC828A38A1UL;
        }
        break;
    case 5:
        switch ((int)p2) {
        default:
            break;
        case 0xF:
            field_10 = 0xBA38E6DCF8C737FFUL;
            break;
        case 0x11:
            field_10 = 0xBA38E6DCA6D42A7FUL;
            break;
        case 0x14:
            field_10 = 0xBA38E82B9CC11F7FUL;
            break;
        case 0x17: {
            UnkStruct_002E80A0_2 * r1 = GetStateFromID__6CGtFSMFUl(fsm, field_10);
            if (fsm->field_4 == r1) break;
            fsm->vfunc_18(r1, 0);
            void * t0 = fsm->field_4;
            fsm->field_4 = (void *)r1;
            UnkStruct_002E80A0_1 * t1 = fsm->field_10;
            if (t1 != 0) {
                fsm->field_14 = t1->field_20;
                if (r1 != 0) {
                    r1->field_8 = fsm->field_10->field_20;
                }
            }
            fsm->vfunc_1C(t0, 0);
            break;
        }
        }
        break;
    }
}
