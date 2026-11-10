// CB3MenuChoices::RequestOnePlayerGameMode(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MenuChoices.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a124: switch(field_8) 0..3 request builder; add operands i + field_14).

class CB3TrackList {
public:
    int GetTrackIndexFromID(unsigned long);
    void CreateTrackPathFromIndex(int, char*, int);

    unsigned char pad_0[0x10];
};

struct UnkStruct_0030C2C0_req {
    unsigned long field_0;
    unsigned long field_8;
    unsigned long field_10;
    unsigned long field_18[10];
    unsigned long field_68;
    int field_70;
    int field_74;
    int field_78[10];
    int field_A0;
    int field_A4;
    unsigned char pad_A8[0x4];
    char field_AC[0x100];
    unsigned char field_1AC;
    unsigned char pad_1AD[0x7];
    void * field_1B4;
    void * field_1B8;
};

struct UnkStruct_D_0051AD00 {
    unsigned char pad_0[0x1B8];
    void * field_1B8;
};

struct UnkStruct_kacGameDataFileName {
    int field_0;
};

struct UnkStruct_D_0051B920 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051B258 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051B2A4 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051B340 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051B3B4 { unsigned char pad_0[0x10]; };

class CB3MenuChoices {
public:
    UnkStruct_0030C2C0_req * RequestOnePlayerGameMode(int p0);

    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x8];
    int field_14;
    int field_18;
    unsigned char pad_1C[0x64];
    unsigned long field_80[8];
    int field_C0[10];
    unsigned long field_E8;
    unsigned char pad_F0[0x50];
    unsigned long field_140;
    unsigned char pad_148[4];
    int field_14C;
    unsigned char pad_150[0x21];
    signed char field_171;
};

extern UnkStruct_D_0051AD00 D_0051AD00;
extern UnkStruct_kacGameDataFileName kacGameDataFileName;
extern UnkStruct_D_0051B920 D_0051B920;
extern UnkStruct_D_0051B258 D_0051B258;
extern UnkStruct_D_0051B2A4 D_0051B2A4;
extern UnkStruct_D_0051B340 D_0051B340;
extern UnkStruct_D_0051B3B4 D_0051B3B4;
extern CB3TrackList D_005196A0;
extern char D_0049BA40[];
extern char D_0049BA88[];
extern char gRomName[];
extern char D_006481A0[];

extern "C" void * memset(void *, int, unsigned int);
extern "C" char * strcat(char *, const char *);
extern "C" unsigned long GtIDCompress__FPCc(const char *);
extern "C" int func_003EB060(unsigned long);
extern "C" int GetRaceVehicleSeries__23CB3HardCodedVehicleListFi(int);
extern "C" void func_0014EC30(void *, int, int, int);

static inline int func_0030C2C0_min(int a, int b)
{
    int r;
    asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline unsigned int func_0030C2C0_zx(int a)
{
    unsigned int r;
    asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a));
    return r;
}

// 0x0030C2C0
UnkStruct_0030C2C0_req * CB3MenuChoices::RequestOnePlayerGameMode(int p0)
{
    UnkStruct_0030C2C0_req * const r = (UnkStruct_0030C2C0_req *)&D_0051AD00;
    memset(r, 0, 432);
    r->field_1B8 = &D_0051B920;
    field_14 = 1;
    r->field_A0 = field_14;
    r->field_8 = field_80[0];
    r->field_70 = field_C0[0];
    if (field_171 != 0) {
        r->field_1AC = 1;
    } else {
        r->field_1AC = 0;
    }
    switch (field_8) {
    case 0: {
        r->field_1B4 = &D_0051B258;
        r->field_A4 = field_18;
        r->field_0 = field_E8;
        for (int i = 0; i < r->field_A4; i++) {
            r->field_18[i] = field_80[i + field_14];
            r->field_78[i] = field_C0[i + field_14];
        }
        r->field_68 = GtIDCompress__FPCc(D_0049BA40);
        int s = GetRaceVehicleSeries__23CB3HardCodedVehicleListFi(func_003EB060(r->field_8));
        func_0014EC30(D_006481A0, s, field_14C, 1);
        break;
    }
    case 1:
        r->field_A4 = 0;
        r->field_1B4 = &D_0051B2A4;
        r->field_0 = field_E8;
        r->field_68 = GtIDCompress__FPCc(D_0049BA88);
        break;
    case 2: {
        r->field_1B4 = &D_0051B340;
        r->field_A4 = func_0030C2C0_zx(func_0030C2C0_min(field_18, 3));
        r->field_0 = field_E8;
        for (int i = 0; i < r->field_A4; i++) {
            r->field_18[i] = field_80[i + field_14];
            r->field_78[i] = field_C0[i + field_14];
        }
        r->field_68 = GtIDCompress__FPCc(gRomName + 8);
        break;
    }
    case 3:
        r->field_A4 = 0;
        r->field_1B4 = &D_0051B3B4;
        r->field_1AC = 1;
        r->field_0 = field_E8;
        r->field_68 = field_140;
        break;
    default:
        break;
    }
    D_005196A0.CreateTrackPathFromIndex(D_005196A0.GetTrackIndexFromID(r->field_0), r->field_AC, 256);
    strcat(r->field_AC, (const char *)kacGameDataFileName.field_0);
    return r;
}
