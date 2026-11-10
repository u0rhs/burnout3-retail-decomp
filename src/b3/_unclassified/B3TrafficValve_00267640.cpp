// CB3TrafficValve::GetRandomVehicleID(ETrafficVehicleCategories) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficValve.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near34: real member fn (frees a0), base/count/total load order, i declared before sum).

// CB3TrafficValve::GetRandomVehicleID -- [C] name: mangled symbol in retail's tables; types/fields [G] (instruction widths).
struct UnkStruct_D_0055D788 { int field_0; unsigned char pad[0xC]; };
struct UnkStruct_D_0055D78C { int field_0; unsigned char pad[0xC]; };
extern UnkStruct_D_0055D78C D_0055D78C;
struct UnkStruct_00267640_ent { unsigned char pad_0[0x10]; int field_10; unsigned char pad_14[4]; };
struct UnkStruct_00267640_tbl { UnkStruct_00267640_ent *field_0; int field_4; int field_8; };
struct UnkStruct_00267640_sys { unsigned char pad_0[0x54]; UnkStruct_00267640_tbl field_54; UnkStruct_00267640_tbl field_60; UnkStruct_00267640_tbl field_6C; UnkStruct_00267640_tbl field_78; UnkStruct_00267640_tbl field_84; UnkStruct_00267640_tbl field_90; };
struct UnkStruct_D_00527440 { UnkStruct_00267640_sys *field_0; unsigned char pad[0xC]; };
extern UnkStruct_D_00527440 D_00527440;
extern UnkStruct_D_0055D788 D_0055D788;
enum ETrafficVehicleCategories { };  // [C] type name from the mangled symbol; enumerators unknown
class CB3TrafficValve {
public:
    UnkStruct_00267640_ent *GetRandomVehicleID(ETrafficVehicleCategories cat);
};
// 0x00267640
UnkStruct_00267640_ent *CB3TrafficValve::GetRandomVehicleID(ETrafficVehicleCategories cat)
{
    UnkStruct_00267640_sys *sys = D_00527440.field_0;
    unsigned int total;
    int count;
    UnkStruct_00267640_ent *base;
    // pass1 [C] retail: no default assignment -- a category outside {1,2,3,4,5,11} reaches the divu at 0x267734 with total
    // (t1), count (v1) and base (a2) never written here: whatever UpdateGeneration's caller left there (t1 is
    // Update__15CB3TrafficValveFiUsfbb's untouched entry t1). Not an argument; unreachable for valid categories [L].
    // Port: treat any other category as invalid (return 0) -- retail's value is undefined.
    switch (cat) {
    case 1: base = sys->field_54.field_0; count = sys->field_54.field_4; total = sys->field_54.field_8; break;
    case 2: base = sys->field_60.field_0; count = sys->field_60.field_4; total = sys->field_60.field_8; break;
    case 5: base = sys->field_6C.field_0; count = sys->field_6C.field_4; total = sys->field_6C.field_8; break;
    case 3: base = sys->field_78.field_0; count = sys->field_78.field_4; total = sys->field_78.field_8; break;
    case 4: base = sys->field_84.field_0; count = sys->field_84.field_4; total = sys->field_84.field_8; break;
    case 11: base = sys->field_90.field_0; count = sys->field_90.field_4; total = sys->field_90.field_8; break;
    default: break;
    }
    if (count == 1) return base;
    int a = D_0055D788.field_0;
    int b = D_0055D78C.field_0;
    unsigned int rr = (a << 16) + (a >> 16);
    rr += b;
    D_0055D788.field_0 = rr;
    D_0055D78C.field_0 = b + rr;
    int r = rr % total;
    int i;
    int sum = 0;
    for (i = 0; i < count; i++) {
        sum += base[i].field_10;
        if (sum >= r) return &base[i];
    }
    return 0;
}
