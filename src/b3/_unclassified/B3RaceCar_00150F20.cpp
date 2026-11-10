// CB3RaceCar::Register() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (for loop with element pointer + break; char field_1790[] array member (recomputed this+0x1790)).

// CB3RaceCar::Register() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3RaceCar;
struct UnkStruct_00150F20_1;
struct UnkStruct_00150F20_e0;
struct UnkStruct_D_004B61A8;
struct UnkStruct_D_004B61B0;
struct UnkStruct_D_004B61C0;
struct UnkStruct_D_004B61D8;
struct UnkStruct_D_004B61E8;
struct UnkStruct_D_004B6200;
struct UnkStruct_D_004B6210;
struct UnkStruct_gVdbDatabase;
struct UnkStruct_gaVehicleReflectivityData;
struct UnkStruct_kpcVehicleMaterialPropertiesPath;

struct UnkStruct_00150F20_1 {
    unsigned char pad_0[0x10];
};

struct UnkStruct_kpcVehicleMaterialPropertiesPath {
    int field_0;
};

struct UnkStruct_00150F20_e0 {
    unsigned long field_0;
    unsigned char pad_8[0xE8];
};

struct UnkStruct_gaVehicleReflectivityData {
    UnkStruct_00150F20_e0 field_0[1];  // [G] element count unknown
};

struct UnkStruct_gVdbDatabase {
    int field_0;
};

struct UnkStruct_D_004B61A8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004B61B0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004B61C0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004B61D8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004B61E8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004B6200 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004B6210 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3RaceCar {
public:
    void Register();

    unsigned char pad_0[0x520];
    void * field_520;
    unsigned char pad_524[0x126C];
    char field_1790[0x1D0];  // [G] element count: up to field_1960
    unsigned long field_1960;
};

extern UnkStruct_kpcVehicleMaterialPropertiesPath kpcVehicleMaterialPropertiesPath;
extern UnkStruct_gaVehicleReflectivityData gaVehicleReflectivityData;
extern UnkStruct_gVdbDatabase mpToolBase__Q27GtComms16CGtCommsToolBase;
extern UnkStruct_D_004B61A8 D_004B61A8;
extern UnkStruct_D_004B61B0 D_004B61B0;
extern UnkStruct_D_004B61C0 D_004B61C0;
extern UnkStruct_D_004B61D8 D_004B61D8;
extern UnkStruct_D_004B61E8 D_004B61E8;
extern UnkStruct_D_004B6200 D_004B6200;
extern UnkStruct_D_004B6210 D_004B6210;

extern "C" char * strcpy(char *, const char *);
extern "C" char * strcat(char *, const char *);
extern "C" void func_0021AB40(unsigned long, UnkStruct_00150F20_1 *);
extern "C" void AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(int, void *, void *, void *, void *, int, int, float, float);

// 0x00150F20
void CB3RaceCar::Register()
{
    UnkStruct_00150F20_1 local;  // [G] the frame's one local (size: up to the frame top)
    func_0021AB40(field_1960, &local);
    strcpy(field_1790, (const char *)kpcVehicleMaterialPropertiesPath.field_0);
    strcat(field_1790, (const char *)&local);
    strcat(field_1790, (const char *)&D_004B61A8);
    unsigned long id = field_1960;
    for (int i = 0; i < 18; i++) {
        UnkStruct_00150F20_e0 *e = &gaVehicleReflectivityData.field_0[i];
        if (e->field_0 == 0) {
            AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (char *)e + 0x8, &D_004B61B0, &D_004B61C0, field_1790, 0, 8, 0.0f, 1.0f);
            AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (char *)e + 0x28, &D_004B61D8, &D_004B61C0, field_1790, 0, 8, 0.0f, 1.0f);
            AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (char *)e + 0x48, &D_004B61E8, &D_004B61C0, field_1790, 0, 8, 0.0f, 1.0f);
            AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (char *)e + 0x68, &D_004B6200, &D_004B61C0, field_1790, 2, 0, 0.0f, 1.0f);
            AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (char *)e + 0x6C, &D_004B6210, &D_004B61C0, field_1790, 2, 0, 0.0f, 1.0f);
            e->field_0 = id;
            field_520 = e;
            break;
        }
        if (id == e->field_0) {
            field_520 = e;
            break;
        }
    }
}
