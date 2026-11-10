// CB3PhysicsManager::InduceTrafficVehicleCrash(CB3TrafficVehicle*,CB3VehiclePhysics*,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PhysicsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (inlc: body-state inline takes (manager, index) and forms the element address itself; caller forms e after the call (fixes the a2/a3 swap)).

struct UnkStruct_D_0064ED5C {
    signed char field_0;
    unsigned char pad_1[0xF];
};
struct UnkStruct_D_0055E948 {
    unsigned char pad_0[0x10];
};
extern UnkStruct_D_0064ED5C D_0064ED5C;
extern UnkStruct_D_0055E948 D_0055E948;
extern unsigned char kaabCanFatal[][7];

class CB3ActiveBody;
extern "C" int GetNetworkCollBodyType__13CB3ActiveBodyCFv(void *);
extern "C" void CrashTrafficBody__17CB3PhysicsManagerFP13CB3ActiveBodyiibbb(void *, void *, int, int, bool, bool, bool);
extern "C" void SetSympatheticTraffic__22CB3CrashActionDirectorFiP17CB3VehiclePhysics(void *, int, void *);

struct UnkStruct_InduceTVC_o {
    unsigned char pad_0[0x2424];
    int field_2424;
};
struct UnkStruct_InduceTVC_b {
    unsigned char pad_0[0xC];
    UnkStruct_InduceTVC_o * field_C;
};
struct CB3TrafficVehicle {
    unsigned char pad_0[0x16C];
    UnkStruct_InduceTVC_b * field_16C;
};
struct CB3VehiclePhysics {
    unsigned char pad_0[0x218];
    signed char field_218;
};
struct UnkStruct_InduceTVC_e {
    signed char field_0;
    unsigned char pad_1[0xB];
    void * field_C;
};
class CB3PhysicsManager {
public:
    void * InduceTrafficVehicleCrash(CB3TrafficVehicle * p0, CB3VehiclePhysics * p1, bool p2);
    unsigned char pad_0[0x1CB70];
    int field_1CB70;
    unsigned char pad_1CB74[0xC9698];
    int field_E620C;
};

// [L] inlc: the inlined body-state test takes the manager and the index and forms the element address itself; the
// caller forms its own pointer after the call. Passing the element/state pointer in gives retail's code with the
// result and pointer registers swapped (N-row: inline-constant investigation).
static inline bool func_001B82F0_inl1(CB3PhysicsManager *m, int i)
{
    UnkStruct_InduceTVC_e * e = (UnkStruct_InduceTVC_e *)((char *)m + i * 0x30 + 0x70);
    return (unsigned int)e->field_0 <= 2 || e->field_0 == 4;
}
// 0x001B82F0
void * CB3PhysicsManager::InduceTrafficVehicleCrash(CB3TrafficVehicle * p0, CB3VehiclePhysics * p1, bool p2)
{
    void * found = 0;
    if (p1->field_218 == -1) {
        p1->field_218 = 0;
    }
    UnkStruct_InduceTVC_b * body = p0->field_16C;
    int n = field_1CB70;
    for (int i = 0; i < n; i++) {
        if (func_001B82F0_inl1(this, i)) {
            UnkStruct_InduceTVC_e * e = (UnkStruct_InduceTVC_e *)((char *)this + i * 0x30 + 0x70);
            if (e->field_C == p1) {
                found = e;
                break;
            }
        }
    }
    int t0 = GetNetworkCollBodyType__13CB3ActiveBodyCFv(body);
    int t1 = GetNetworkCollBodyType__13CB3ActiveBodyCFv(found);
    if (kaabCanFatal[t0][t1] == 0) return 0;
    CrashTrafficBody__17CB3PhysicsManagerFP13CB3ActiveBodyiibbb(this, body, D_0064ED5C.field_0, p1->field_218, false, true, true);
    UnkStruct_InduceTVC_o * r = body->field_C;
    if (p2) {
        if (r->field_2424 != 0) {
            SetSympatheticTraffic__22CB3CrashActionDirectorFiP17CB3VehiclePhysics(&D_0055E948, field_E620C - 2, p1);
            return r;
        }
        SetSympatheticTraffic__22CB3CrashActionDirectorFiP17CB3VehiclePhysics(&D_0055E948, field_E620C - 1, p1);
    }
    return r;
}
