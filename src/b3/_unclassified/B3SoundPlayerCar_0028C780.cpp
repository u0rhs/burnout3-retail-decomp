// CB3SoundPlayerCar::Register(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundPlayerCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (name buffer this+0xC0 as char field_C0[0x40] array member (not CSE'd), as sibling CB3SoundAICar::Register).

// lifter variant 0
// CB3SoundPlayerCar::Register(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundPlayerCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3SoundPlayerCar;
struct UnkStruct_0028C780_1;
struct UnkStruct_D_004BF990;
struct UnkStruct_D_004BF9B8;
struct UnkStruct_D_004BF9C8;
struct UnkStruct_D_004BF9E0;
struct UnkStruct_D_004BFA00;
struct UnkStruct_D_004BFA20;
struct UnkStruct_D_004BFA40;
struct UnkStruct_D_004BFA60;
struct UnkStruct_D_004BFA80;
struct UnkStruct_D_004BFAA0;
struct UnkStruct_D_004BFAC0;
struct UnkStruct_D_004BFAE0;
struct UnkStruct_D_004BFB00;
struct UnkStruct_D_004BFB20;
struct UnkStruct_gVdbDatabase;

struct UnkStruct_0028C780_1 {
    unsigned char pad_0[0x10];
};

struct UnkStruct_gVdbDatabase {
    int field_0;
};

struct UnkStruct_D_004BF990 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BF9B8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BF9C8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BF9E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BFA00 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BFA20 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BFA40 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BFA60 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BFA80 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BFAA0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BFAC0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BFAE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BFB00 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BFB20 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundPlayerCar {
public:
    void Register(unsigned long p0);

    unsigned char pad_0[0x68];
    int field_68;
    unsigned char pad_6C[0x53];
    unsigned char field_BF;
    char field_C0[0x40];
};

extern UnkStruct_gVdbDatabase mpToolBase__Q27GtComms16CGtCommsToolBase;
extern UnkStruct_D_004BF990 D_004BF990;
extern UnkStruct_D_004BF9B8 D_004BF9B8;
extern UnkStruct_D_004BF9C8 D_004BF9C8;
extern UnkStruct_D_004BF9E0 D_004BF9E0;
extern UnkStruct_D_004BFA00 D_004BFA00;
extern UnkStruct_D_004BFA20 D_004BFA20;
extern UnkStruct_D_004BFA40 D_004BFA40;
extern UnkStruct_D_004BFA60 D_004BFA60;
extern UnkStruct_D_004BFA80 D_004BFA80;
extern UnkStruct_D_004BFAA0 D_004BFAA0;
extern UnkStruct_D_004BFAC0 D_004BFAC0;
extern UnkStruct_D_004BFAE0 D_004BFAE0;
extern UnkStruct_D_004BFB00 D_004BFB00;
extern UnkStruct_D_004BFB20 D_004BFB20;

extern "C" void Register__15CB3SoundRaceCarFUl(void *, unsigned long);  // CB3SoundRaceCar::Register(unsigned long)
extern "C" void func_0021AB40(unsigned long, UnkStruct_0028C780_1 *);
extern "C" void sprintf(void *, void *, UnkStruct_0028C780_1 *);
extern "C" void AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi(int, int, void *, void *, void *, int, int, float, float);
extern "C" void AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii(int, int, void *, void *, void *, int, int, int, int);

// 0x0028C780
void CB3SoundPlayerCar::Register(unsigned long p0)
{
    UnkStruct_0028C780_1 local;  // [G] the frame's one local (size: up to the frame top)
    Register__15CB3SoundRaceCarFUl(this, p0);
    if (field_BF != 0) {
        func_0021AB40(p0, &local);
        sprintf(field_C0, &D_004BF990, &local);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 36), &D_004BF9B8, &D_004BF9C8, field_C0, 0, 0, 0.0f, 0.0f);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPiPCcPCcPCciiii((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), field_68, &D_004BF9E0, &D_004BFA00, field_C0, 0, 0, 0, 0);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 4), &D_004BFA20, &D_004BFA00, field_C0, 0, 0, 0.0f, 0.0f);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 8), &D_004BFA40, &D_004BFA00, field_C0, 0, 0, 0.0f, 0.0f);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 20), &D_004BFA60, &D_004BFA00, field_C0, 0, 0, 0.0f, 0.0f);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 24), &D_004BFA80, &D_004BFA00, field_C0, 0, 0, 0.0f, 0.0f);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 12), &D_004BFAA0, &D_004BFA00, field_C0, 0, 0, 0.0f, 0.0f);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 16), &D_004BFAC0, &D_004BFA00, field_C0, 0, 0, 0.0f, 0.0f);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 28), &D_004BFAE0, &D_004BFA00, field_C0, 0, 0, 0.0f, 0.0f);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 32), &D_004BFB00, &D_004BFA00, field_C0, 0, 0, 0.0f, 0.0f);
        AddEntry__Q27GtComms16CGtCommsDatabaseFPfPCcPCcPCciffi((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 40), &D_004BFB20, &D_004BF9C8, field_C0, 0, 0, 0.0f, 0.0f);
    }
}
