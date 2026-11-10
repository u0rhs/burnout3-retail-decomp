// CB3CrashCombo::UpdateCurrentCombo() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (Hand-written: E-map helpers (AddUninitialisedItemToCombo ring push, AddItemToCombo int/float, AddVehicleToCombo, UpdateVehicles/UpdateAir/UpdateExtras/AddLanding) as inline members; if+while guard; GetVehicleCollisionType inline returning 0 (hoisted zero register); 0.2f literal).

// CB3CrashCombo::UpdateCurrentCombo() -- hand-written from the retail structure (lifter refused: duplicate case label).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// The helpers inlined here are named from the E-build B3O0PCH map, where they are out of line [C names]
// (AddUninitialisedItemToCombo, AddItemToCombo x2, AddVehicleToCombo, UpdateVehicles, UpdateAir,
// UpdateExtras, AddLanding, GetVehicleCollisionType -- 0x14 bytes there); their bodies are [G], reconstructed
// from this function and AddPickupToCombo (GetVehicleCollisionType as `return 0`: retail keeps a hoisted 0 register).

typedef unsigned int u_long128 __attribute__((mode(TI)));

#include "b3/GtMath.h"

enum EComboEntryType {};
enum ECrashComboCollisionType {};

class CB3CrashCombo;
class CB3VehiclePhysics;
struct UnkStruct_00362F60_1;
struct UnkStruct_00362F60_5;
struct UnkStruct_00362F60_9;
struct UnkStruct_00362F60_14;
struct UnkStruct_00362F60_e1;
struct UnkStruct_D_00522680;

struct UnkStruct_00362F60_14 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
};

struct UnkStruct_00362F60_1 {
    unsigned char pad_0[0x204];
    UnkStruct_00362F60_14 * field_204;
    unsigned char pad_208[0xABC];
    UnkStruct_00362F60_9 * field_CC4;
};

struct UnkStruct_00362F60_e1 {
    CB3VehiclePhysics * field_0;
    int field_4;
    int field_8;
    int field_C;
};

class CB3VehiclePhysics {
public:
    unsigned char pad_0[0xCC4];
    UnkStruct_00362F60_5 * field_CC4;
};

struct UnkStruct_00362F60_5 {
    unsigned char pad_0[0x1024];
    int field_1024;
};

struct UnkStruct_00362F60_9 {
    unsigned char pad_0[0x1015];
    unsigned char field_1015;
};

struct UnkStruct_D_00522680 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3CrashCombo {
public:
    void UpdateCurrentCombo();
    void DetectAirAndGround();
    void DetectSkid();
    void UpdateSpins();
    void UpdateSkids();
    void CalculateCrashDescription();

    UnkStruct_00362F60_e1 * AddUninitialisedItemToCombo()
    {
        UnkStruct_00362F60_e1 * e = &field_0[field_108];
        field_100++;
        field_108 = (field_108 + 1) % 16;
        if (field_108 == field_104) {
            field_104 = (field_104 + 1) % 16;
        }
        if (field_110 == e) {
            field_110 = 0;
        }
        if (field_114 == e) {
            field_114 = 0;
        }
        field_118 = 1;
        field_10C = e;
        return e;
    }
    void AddVehicleToCombo(CB3VehiclePhysics * v, EComboEntryType type, ECrashComboCollisionType coll)
    {
        UnkStruct_00362F60_e1 * e = AddUninitialisedItemToCombo();
        e->field_0 = v;
        e->field_4 = type;
        e->field_8 = coll;
    }
    void AddItemToCombo(EComboEntryType type, int value, CB3VehiclePhysics * v)
    {
        UnkStruct_00362F60_e1 * e = AddUninitialisedItemToCombo();
        e->field_0 = v;
        e->field_4 = type;
        e->field_8 = 0;
        e->field_C = value;
    }
    void AddItemToCombo(EComboEntryType type, float value, CB3VehiclePhysics * v)
    {
        UnkStruct_00362F60_e1 * e = AddUninitialisedItemToCombo();
        e->field_0 = v;
        e->field_4 = type;
        e->field_8 = 0;
        *(float *)&e->field_C = value;
    }
    ECrashComboCollisionType GetVehicleCollisionType(CB3VehiclePhysics * v)
    {
        return (ECrashComboCollisionType)0;
    }
    void UpdateVehicles();
    void UpdateAir();
    void UpdateExtras();
    void AddLanding();

    UnkStruct_00362F60_e1 field_0[16];
    int field_100;
    int field_104;
    int field_108;
    UnkStruct_00362F60_e1 * field_10C;
    UnkStruct_00362F60_e1 * field_110;
    UnkStruct_00362F60_e1 * field_114;
    unsigned char field_118;
    unsigned char field_119;
    unsigned char field_11A;
    unsigned char pad_11B[0x9];
    float field_124;
    unsigned char pad_128[0x18];
    u_long128 field_140;
    unsigned char pad_150[0x48];
    int field_198;
    unsigned char pad_19C[0x21];
    unsigned char field_1BD;
    unsigned char field_1BE;
    unsigned char pad_1BF[0x1];
    float field_1C0;
    unsigned char pad_1C4[0x14];
    float field_1D8;
    unsigned char pad_1DC[0x17];
    unsigned char field_1F3;
    unsigned char pad_1F4[0x34];
    UnkStruct_00362F60_1 * field_228;
    unsigned char pad_22C[0x4];
    CB3VehiclePhysics * field_230[64];  // [G] element count unknown
    int field_330;
    int field_334;
};

extern int D_004C76A0[];  // [G] element count unknown
extern UnkStruct_D_00522680 D_00522680;

extern "C" int GetSideFacingUp__13CB3CrashComboFRCQ29GtMathPs212CGtMatrix3x4(const void *);  // CB3CrashCombo::GetSideFacingUp(const GtMathPs2::CGtMatrix3x4&)

inline void CB3CrashCombo::UpdateVehicles()
{
    if (field_334 != 0) {
        while (field_334 != 0) {
            CB3VehiclePhysics * v = field_230[field_330 - field_334];
            AddVehicleToCombo(v, (EComboEntryType)1, GetVehicleCollisionType(v));
            if (v->field_CC4->field_1024 != 0) {
                AddItemToCombo((EComboEntryType)24, 0, 0);
            }
            field_334--;
        }
    }
}

inline void CB3CrashCombo::UpdateAir()
{
    if (field_1BE != 0 && field_1C0 > 0.2f) {
        if (field_114 == 0) {
            if (field_10C != 0 && field_10C->field_4 == 25) {
                field_114 = field_10C;
            }
        }
        if (field_114 != 0 && field_114->field_4 == 25) {
            *(float *)&field_114->field_C = GtMath::Max(field_1C0, *(float *)&field_114->field_C);
        } else {
            AddItemToCombo((EComboEntryType)25, field_1C0, 0);
            field_114 = field_10C;
        }
    }
}

inline void CB3CrashCombo::UpdateExtras()
{
    if ((field_228->field_CC4->field_1015 & 0x10) != 0 && field_1F3 == 0) {
        AddItemToCombo((EComboEntryType)27, 0, 0);
        field_1F3 = 1;
    }
}

inline void CB3CrashCombo::AddLanding()
{
    if (field_1BD != 0) {
        if (field_198 != 0 && !(field_1D8 < 2.0f)) {
            AddItemToCombo((EComboEntryType)D_004C76A0[field_198], 0, 0);
            field_114 = 0;
        }
        field_1D8 = 0.0f;
    }
}

// 0x00362F60
void CB3CrashCombo::UpdateCurrentCombo()
{
    field_198 = GetSideFacingUp__13CB3CrashComboFRCQ29GtMathPs212CGtMatrix3x4(field_228->field_204);
    DetectAirAndGround();
    DetectSkid();
    UpdateSpins();
    UpdateSkids();
    UpdateVehicles();
    UpdateAir();
    UpdateExtras();
    AddLanding();
    if (field_119 != 0) {
        field_11A = 0;
        field_124 = D_00522680.field_0;
        CalculateCrashDescription();
    }
    field_140 = field_228->field_204->field_30;
}
