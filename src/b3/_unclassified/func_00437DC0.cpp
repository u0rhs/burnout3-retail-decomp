// func_00437DC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (s0/s1 param rotation: p1 taken as void* and cast-copied into a typed local (different-type copy is a new local numbered after params -> lower s; mwmodel q5 t4)).

// lifter variant 0
// func_00437DC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3BehaviourType {};
class CB3AttribsTrackSide;

class CB3BehaviourTrackSide;
struct UnkStruct_00437DC0_1;
struct UnkStruct_00437DC0_2;
struct UnkStruct_00437DC0_3;
struct UnkStruct_00437DC0_4;
struct UnkStruct_00437DC0_5;
struct UnkStruct_00437DC0_6;
struct UnkStruct_00437DC0_7;
struct UnkStruct_00437DC0_a2;

class CB3BehaviourTrackSide {
public:
    void SetParameters(EB3BehaviourType, CB3AttribsTrackSide*, int);
};

struct UnkStruct_00437DC0_a2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    void * field_4;
    unsigned char pad_8[0x8];
    UnkStruct_00437DC0_1 * field_10;
    float field_14;
    unsigned char pad_18[0xAA8];
    CB3BehaviourTrackSide field_AC0;
    unsigned char pad_AC1[0xD3];
    int field_B94;
};

struct UnkStruct_00437DC0_1 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_00437DC0_2 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00437DC0_3 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_00437DC0_4 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00437DC0_5 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00437DC0_6 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00437DC0_7 {
    unsigned char pad_0[0x8];
    float field_8;
};

extern "C" void SetActiveBehaviour__22CB3PlayerCameraManagerFi(void *, int);  // CB3PlayerCameraManager::SetActiveBehaviour(int)
extern "C" void * GetStateFromID__6CGtFSMFUl(UnkStruct_00437DC0_a2 *, unsigned long);

// [G] inlined helper (name unknown): switches p1's current state object, carrying the time over
static inline void func_00437DC0_swap(UnkStruct_00437DC0_a2 * p1, unsigned long id, int arg)
{
    UnkStruct_00437DC0_2 * r = (UnkStruct_00437DC0_2 *)GetStateFromID__6CGtFSMFUl(p1, id);
    if (p1->field_4 == r) return;
    p1->vfunc_18(r, arg);
    void * t0 = p1->field_4;
    p1->field_4 = (void *)r;
    if (p1->field_10 != 0) {
        p1->field_14 = p1->field_10->field_20;
        if (r != 0) {
            r->field_8 = p1->field_10->field_20;
        }
    }
    p1->vfunc_1C(t0, arg);
}

// 0x00437DC0
extern "C" void func_00437DC0(int n0, int p0, void * pv, int p2, int p3)
{
    UnkStruct_00437DC0_a2 * p1 = (UnkStruct_00437DC0_a2 *)pv;
    switch (p0) {
    case 3:
        p1->field_AC0.SetParameters((EB3BehaviourType)1, (CB3AttribsTrackSide*)p1->field_B94, p2);
        SetActiveBehaviour__22CB3PlayerCameraManagerFi(p1, 8);
        break;
    case 2:
    case 4:
        break;
    case 5:
        switch (p2) {
        case 13:
        case 7:
            break;
        case 15:
            func_00437DC0_swap(p1, 0xBA38E6DCF8C737FF, 0);
            break;
        case 14:
            func_00437DC0_swap(p1, 0xBA38E6DC828A38A1, 0);
            break;
        case 20:
            func_00437DC0_swap(p1, 0xBA38E82B9CC11F7F, 0);
            break;
        case 17:
            func_00437DC0_swap(p1, 0xBA38E6DCA6D42A7F, 0);
            break;
        case 22:
            func_00437DC0_swap(p1, 0xBA38E63A96099FBF, p3);
            break;
        }
        break;
    }
}
