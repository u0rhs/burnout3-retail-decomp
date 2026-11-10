// CB3SoundAICar::Register(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundAICar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (this+0xC0 is a char array member field_C0 (passed by name twice; MWCC recomputes it instead of CSE into s0)).

// lifter variant 0
// CB3SoundAICar::Register(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundAICar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3SoundAICar;
struct UnkStruct_0028BA20_1;
struct UnkStruct_D_004BF7D0;
struct UnkStruct_D_004BF7F8;
struct UnkStruct_D_004BF808;
struct UnkStruct_gVdbDatabase;

struct UnkStruct_0028BA20_1 {
    unsigned char pad_0[0x10];
};

struct UnkStruct_gVdbDatabase {
    int field_0;
};

struct UnkStruct_D_004BF7D0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BF7F8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BF808 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundAICar {
public:
    void Register(unsigned long p0);

    unsigned char pad_0[0x68];
    int field_68;
    unsigned char pad_6C[0x53];
    unsigned char field_BF;
    char field_C0[0x40];
};

extern UnkStruct_gVdbDatabase mpToolBase__Q27GtComms16CGtCommsToolBase;
extern UnkStruct_D_004BF7D0 D_004BF7D0;
extern UnkStruct_D_004BF7F8 D_004BF7F8;
extern UnkStruct_D_004BF808 D_004BF808;

extern "C" void Register__15CB3SoundRaceCarFUl(void *, unsigned long);  // CB3SoundRaceCar::Register(unsigned long)
extern "C" void func_0021AB40(unsigned long, UnkStruct_0028BA20_1 *);
extern "C" void sprintf(void *, void *, UnkStruct_0028BA20_1 *);
extern "C" void AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(int, int, void *, void *, void *, int, int, float, float);

// 0x0028BA20
void CB3SoundAICar::Register(unsigned long p0)
{
    UnkStruct_0028BA20_1 local;
    Register__15CB3SoundRaceCarFUl(this, p0);
    if (field_BF != 0) {
        func_0021AB40(p0, &local);
        sprintf(field_C0, &D_004BF7D0, &local);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 36), &D_004BF7F8, &D_004BF808, field_C0, 0, 0, 0.0f, 0.0f);
    }
}
