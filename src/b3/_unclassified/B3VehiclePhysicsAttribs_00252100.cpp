// CB3VehiclePhysicsAttribs::Register(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehiclePhysicsAttribs.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a140: vdb table; bufB0 declared before buf30; sd id right before 2nd sprintf (delay slot)).

class CB3VehiclePhysicsAttribs {
public:
    void Register(unsigned long);
    char field_0[0x80];
    unsigned long field_80;
    float field_88;
    float field_8C;
    float field_90;
    float field_94;
    float field_98;
    float field_9C;
    float field_A0;
    float field_A4;
    float field_A8;
};
struct UnkStruct_gVdbDatabase { int field_0; };
extern UnkStruct_gVdbDatabase mpToolBase__Q27GtComms16CGtCommsToolBase;
extern char D_004BB7E0[];
extern char D_004BB808[];
extern char D_004BB810[];
extern char D_004BB820[];
extern char D_004BB830[];
extern char D_004BB850[];
extern char D_004BB860[];
extern char D_004BB870[];
extern char D_004BB880[];
extern char D_004BB890[];
extern "C" void func_0021AB40(unsigned long, char *);
extern "C" int sprintf(char *, const char *, ...);
extern "C" void AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(int, void *, void *, void *, void *, int, int, float, float);

// 0x00252100
void CB3VehiclePhysicsAttribs::Register(unsigned long id)
{
    char bufB0[0x10];
    char buf30[0x80];
    func_0021AB40(id, bufB0);
    sprintf(field_0, D_004BB7E0, bufB0);
    field_80 = id;
    sprintf(buf30, D_004BB808, bufB0, D_004BB810);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (char *)this + 0x88, D_004BB820, D_004BB810, this, 0, 0, 0.0f, 0.0f);
    sprintf(buf30, D_004BB808, bufB0, D_004BB830);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (char *)this + 0x8C, D_004BB850, D_004BB830, this, 0, 0, 0.0f, 0.0f);
    sprintf(buf30, D_004BB808, bufB0, D_004BB830);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (char *)this + 0x98, D_004BB860, D_004BB830, this, 0, 0, 0.0f, 0.0f);
    sprintf(buf30, D_004BB808, bufB0, D_004BB830);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (char *)this + 0x90, D_004BB870, D_004BB830, this, 0, 0, 0.0f, 0.0f);
    sprintf(buf30, D_004BB808, bufB0, D_004BB830);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (char *)this + 0x94, D_004BB880, D_004BB830, this, 0, 0, 0.0f, 0.0f);
    sprintf(buf30, D_004BB808, bufB0, D_004BB890);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (char *)this + 0xA8, D_004BB850, D_004BB890, this, 0, 0, 0.0f, 0.0f);
    sprintf(buf30, D_004BB808, bufB0, D_004BB890);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (char *)this + 0xA4, D_004BB860, D_004BB890, this, 0, 0, 0.0f, 0.0f);
    sprintf(buf30, D_004BB808, bufB0, D_004BB890);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (char *)this + 0x9C, D_004BB870, D_004BB890, this, 0, 0, 0.0f, 0.0f);
    sprintf(buf30, D_004BB808, bufB0, D_004BB890);
    AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (char *)this + 0xA0, D_004BB880, D_004BB890, this, 0, 0, 0.0f, 0.0f);
}
