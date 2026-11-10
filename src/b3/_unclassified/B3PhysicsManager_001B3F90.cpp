// CB3PhysicsManager::ClearCrashingBodies(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PhysicsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (inlc: body-state inline takes (manager, index); state/element pointers formed in the caller before the call; flags[i]=0 first).

extern "C" void HideUnderRoad__20CB3NetworkCarPhysicsFv(void *);
class UnkStruct_001B3F90_obj {
public:
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
    virtual void vfunc_54(void *);
    virtual void vfunc_58(void *);
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
    virtual int vfunc_8C(int);
};
struct UnkStruct_001B3F90_mgr {
    unsigned char pad_0[0x1B4];
    UnkStruct_001B3F90_obj * field_1B4;
};
struct UnkStruct_D_0051BA88 {
    UnkStruct_001B3F90_mgr * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_0064D37C {
    int field_0;
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0064D37C D_0064D37C;

class UnkStruct_001B3F90_car {
public:
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    unsigned char pad_4[0x214];
    signed char field_218;
};
struct UnkStruct_001B3F90_e {
    unsigned char pad_0[0x70];
    signed char field_70;
    unsigned char field_71;
    unsigned char pad_72[0xA];
    UnkStruct_001B3F90_car * field_7C;
};
class CB3PhysicsManager;
class CB3PhysicsManager {
public:
    void ClearCrashingBodies(int p0);
    unsigned char pad_0[0x1CB70];
    int field_1CB70;
};

// [L] inlc: the body-state test takes the manager and the index and forms the element address itself (as in
// InduceTrafficVehicleCrash); the state pointer and the element pointer are formed in the caller.
static inline bool func_001B3F90_inl1(CB3PhysicsManager *m, int i)
{
    UnkStruct_001B3F90_e * e = ((UnkStruct_001B3F90_e *)((char *)m + i * 0x30));
    return (unsigned int)e->field_70 <= 2 || e->field_70 == 4 || e->field_70 == 6 || e->field_70 == 7;
}
// 0x001B3F90
void CB3PhysicsManager::ClearCrashingBodies(int p0)
{
    unsigned char flags[8];
    UnkStruct_001B3F90_obj * o = D_0051BA88.field_0->field_1B4;
    int i = 0;
    for (; i < D_0064D37C.field_0; i++) {
        flags[i] = 0;
        UnkStruct_001B3F90_car * c = ((UnkStruct_001B3F90_e *)((char *)this + i * 0x30))->field_7C;
        if (p0 == c->field_218) {
            o->vfunc_54(c);
            flags[i] = 1;
        }
    }
    if (o->vfunc_8C(p0)) {
        for (i = 0; i < field_1CB70; i++) {
            UnkStruct_001B3F90_e * e = (UnkStruct_001B3F90_e *)((char *)this + i * 0x30);
            signed char * st = &((UnkStruct_001B3F90_e *)((char *)this + i * 0x30))->field_70;
            if (func_001B3F90_inl1(this, i)) {
                UnkStruct_001B3F90_car * c = e->field_7C;
                if (p0 == c->field_218) {
                    if (*st == 4 || (unsigned int)(*st - 6) <= 1) {
                        c->vfunc_14();
                        e->field_71 = 1;
                    } else if (*st != 1) {
                        c->vfunc_14();
                    } else {
                        HideUnderRoad__20CB3NetworkCarPhysicsFv(c);
                    }
                }
            }
        }
    }
    for (int j = 0; j < D_0064D37C.field_0; j++) {
        if (flags[j] != 0) {
            o->vfunc_58(((UnkStruct_001B3F90_e *)((char *)this + j * 0x30))->field_7C);
        }
    }
}
