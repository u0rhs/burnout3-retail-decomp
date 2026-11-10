// CB3MenuChoices::RequestCrashPartyGameMode() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MenuChoices.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (D_0051BA3A/BA3B/B988 are fields of D_004EE040 (+0x2D9FA/B/+0x2D948): count reloads; char field_AC[256] member; v0 set before its 0x1B4 store).

// from build/vt\try_RequestCrashPartyGameMode__14CB3MenuChoi_best.cpp
// CB3MenuChoices::RequestCrashPartyGameMode() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MenuChoices.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3HardCodedCrashStageList;
class CB3MenuChoices;
class CB3TrackList;
struct UnkStruct_0030BE20_9;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_0051AD00;
struct UnkStruct_D_0051AEC0;
struct UnkStruct_D_0051B464;
struct UnkStruct_D_0051B4BC;
struct UnkStruct_D_0051B988;
struct UnkStruct_D_0051BA3A;
struct UnkStruct_D_0051BA3B;
struct UnkStruct_kacGameDataFileName;

class CB3HardCodedCrashStageList {
public:
    static unsigned long GetCrashStageTrackID(unsigned long);
};

class CB3TrackList {
public:
    int GetTrackIndexFromID(unsigned long);
    void CreateTrackPathFromIndex(int, char*, int);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051AD00 {
    unsigned char pad_0[0x1B4];
    void * field_1B4;
};

struct UnkStruct_D_0051AEC0 {
    unsigned char pad_0[0x1B4];
    void * field_1B4;
};

struct UnkStruct_D_0051BA3A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x2D948];
    unsigned char field_2D948[0x8];  // [L] = D_0051B988 (address taken)
    unsigned long field_2D950[5];  // [G] count from the next field's offset
    unsigned long field_2D978[1];  // [G] element count unknown
    unsigned char pad_2D980[0x7A];
    unsigned char field_2D9FA;  // [L] = D_0051BA3A (same object: reloaded after each array store)
    unsigned char field_2D9FB;  // [L] = D_0051BA3B
};

struct UnkStruct_D_0051BA3B {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0030BE20_9 {
    unsigned long field_0;
    unsigned long field_8;
    unsigned long field_10;
    unsigned char pad_18[0x50];
    unsigned long field_68;
    int field_70;
    int field_74;
    unsigned char pad_78[0x28];
    int field_A0;
    int field_A4;
    unsigned char pad_A8[0x4];
    char field_AC[0x100];
    unsigned char field_1AC;
    unsigned char pad_1AD[0x7];
    void * field_1B4;
    void * field_1B8;
};

struct UnkStruct_kacGameDataFileName {
    int field_0;
};

struct UnkStruct_D_0051B4BC {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051B464 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051B988 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3MenuChoices {
public:
    UnkStruct_0030BE20_9 * RequestCrashPartyGameMode();

    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[0xC];
    int field_24;
    int field_28;
    unsigned char pad_2C[0x54];
    unsigned long field_80;
    unsigned long field_88;
    unsigned char pad_90[0x30];
    int field_C0;
    int field_C4;
    unsigned char pad_C8[0x20];
    unsigned long field_E8;
    unsigned long field_F0[1];  // [G] element count unknown
    unsigned char pad_F8[0x48];
    unsigned long field_140;
    unsigned char pad_148[0x2C];
    unsigned char field_174;
};

extern UnkStruct_D_0051AD00 D_0051AD00;
extern UnkStruct_D_0051AEC0 D_0051AEC0;
extern UnkStruct_D_0051BA3A D_0051BA3A;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_0051BA3B D_0051BA3B;
extern UnkStruct_kacGameDataFileName kacGameDataFileName;
extern UnkStruct_D_0051B4BC D_0051B4BC;
extern UnkStruct_D_0051B464 D_0051B464;
extern UnkStruct_D_0051B988 D_0051B988;
extern CB3TrackList D_005196A0;

extern "C" void * memset(void *, int, unsigned int);
extern "C" char * strcat(char *, const char *);

// 0x0030BE20
UnkStruct_0030BE20_9 * CB3MenuChoices::RequestCrashPartyGameMode()
{
    UnkStruct_0030BE20_9 * v0;
    if (field_174 != 0) {
        v0 = (UnkStruct_0030BE20_9 *)&D_0051AEC0;
        v0->field_1B4 = &D_0051B4BC;
        field_14 = 2;
    } else {
        v0 = (UnkStruct_0030BE20_9 *)&D_0051AD00;
        v0->field_1B4 = &D_0051B464;
        field_14 = 1;
    }
    memset(v0, 0, 432);
    for (int i = 0; (i < field_28); i++) {
        unsigned long t0 = field_F0[i];
        unsigned long r1 = CB3HardCodedCrashStageList::GetCrashStageTrackID(t0);
        D_004EE040.field_2D950[D_004EE040.field_2D9FA] = t0;
        D_004EE040.field_2D978[D_004EE040.field_2D9FA] = r1;
        D_004EE040.field_2D9FA++;
        if (i == 0) {
            field_140 = t0;
            field_E8 = r1;
        }
    }
    D_004EE040.field_2D9FB = field_24;
    v0->field_8 = field_80;
    v0->field_70 = field_C0;
    if (field_174 != 0) {
        v0->field_10 = field_88;
        v0->field_74 = field_C4;
    }
    v0->field_1B8 = D_004EE040.field_2D948;
    v0->field_A0 = field_14;
    v0->field_A4 = 0;
    v0->field_1AC = 1;
    v0->field_0 = field_E8;
    v0->field_68 = field_140;
    D_005196A0.CreateTrackPathFromIndex(D_005196A0.GetTrackIndexFromID(v0->field_0), v0->field_AC, 256);
    strcat(v0->field_AC, (const char *)kacGameDataFileName.field_0);
    return v0;
}
