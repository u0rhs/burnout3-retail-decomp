// CB3PhysicsManager::CrashTrafficBody(CB3ActiveBody*,int,int,bool,bool,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PhysicsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (plain structure (no body-state inline); o declared before b fixes a0/v1).

struct UnkStruct_001B41D0_veh {
    unsigned char pad_0[0x10C];
    int field_10C;
    int field_110;
};

struct UnkStruct_001B41D0_obj {
    unsigned char pad_0[0x1D0];
    unsigned char pad_1D0[0x34];
    void * field_204;
    unsigned char pad_208[0x221C];
    UnkStruct_001B41D0_obj * field_2424;
    unsigned char field_2428;
};

struct UnkStruct_001B41D0_ent {
    signed char field_0;
    unsigned char pad_1[0x3];
    void * field_4;
    void * field_8;
    UnkStruct_001B41D0_obj * field_C;
    unsigned char pad_10[0x20];
};

class CB3ActiveBody {
public:
    signed char field_0;
    unsigned char pad_1[0x3];
    void * field_4;
    void * field_8;
    UnkStruct_001B41D0_obj * field_C;
};

struct UnkStruct_D_16 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_16 D_004EE040;
extern UnkStruct_D_16 D_0055E948;
extern UnkStruct_D_16 D_0064CE40;

extern "C" void Prepare__17CB3TrafficPhysicsFP17CB3TrafficVehiclei(void *, void *, int);
extern "C" void StartTrafficCrashing__22CB3CrashActionDirectorFP17CB3TrafficPhysicsi(void *, void *, int);
extern "C" void HandleCrashTrafficCar__13CB3CrashScoreFP17CB3TrafficPhysicsP17CB3TrafficVehiclebi(void *, void *, void *, bool);
extern "C" int func_00131E40(void *);
extern "C" void func_00167D10(void *);

class CB3PhysicsManager {
public:
    void CrashTrafficBody(CB3ActiveBody * p0, int p1, int p2, bool p3, bool p4, bool p5);

    unsigned char pad_0[0x70];
    UnkStruct_001B41D0_ent field_70[1];
    unsigned char pad_A0[0xE6100 - 0xA0];
    UnkStruct_001B41D0_obj * field_E6100[67];
    int field_E620C;
};

// 0x001B41D0
void CB3PhysicsManager::CrashTrafficBody(CB3ActiveBody * p0, int p1, int p2, bool p3, bool p4, bool p5)
{
    UnkStruct_001B41D0_veh * veh = (UnkStruct_001B41D0_veh *)p0->field_C;
    int i;
    p0->field_0 = 4;
    for (i = 0; i < 0x40; i++) {
        if (*((unsigned char *)this + i * 0x2430 + 0x32F10) == 0) {
            break;
        }
    }
    field_E6100[field_E620C] = (UnkStruct_001B41D0_obj *)((char *)this + i * 0x2430 + 0x32D00);
    p0->field_C = field_E6100[field_E620C];
    Prepare__17CB3TrafficPhysicsFP17CB3TrafficVehiclei(field_E6100[field_E620C], veh, p1);
    StartTrafficCrashing__22CB3CrashActionDirectorFP17CB3TrafficPhysicsi(&D_0055E948, field_E6100[field_E620C], p2);
    p0->field_4 = field_E6100[field_E620C]->field_204;
    p0->field_8 = (char *)field_E6100[field_E620C] + 0x1D0;
    field_E620C = field_E620C + 1;
    if (func_00131E40(&D_004EE040) != 0) {
        HandleCrashTrafficCar__13CB3CrashScoreFP17CB3TrafficPhysicsP17CB3TrafficVehiclebi(&D_0064CE40, p0->field_C, veh, p3);
    }
    if (p5 && veh->field_110 != 0) {
        int n = *(int *)((char *)this + 0x1CB70);
        for (i = 0; i < n; i++) {
            if (field_70[i].field_0 == 3 && (int)field_70[i].field_C == veh->field_110) {
                break;
            }
        }
        CrashTrafficBody((CB3ActiveBody *)&field_70[i], p1, p2, p3, false, true);
        UnkStruct_001B41D0_obj * o = field_70[i].field_C;
        UnkStruct_001B41D0_obj * b = p0->field_C;
        o->field_2428 = 1;
        o->field_2424 = b;
        b->field_2428 = 0;
        b->field_2424 = o;
    }
    if (p4 && veh->field_10C != 0) {
        int n = *(int *)((char *)this + 0x1CB70);
        for (i = 0; i < n; i++) {
            if (field_70[i].field_0 == 3 && (int)field_70[i].field_C == veh->field_10C) {
                break;
            }
        }
        CrashTrafficBody((CB3ActiveBody *)&field_70[i], p1, p2, p3, true, false);
        UnkStruct_001B41D0_obj * o = field_70[i].field_C;
        UnkStruct_001B41D0_obj * b = p0->field_C;
        b->field_2428 = 1;
        b->field_2424 = o;
        o->field_2428 = 0;
        o->field_2424 = b;
    }
    func_00167D10(veh);
}
