// CB3StreamManager::Prepare(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (case 1/24 fall into case 2; one && guard; field_F0=2 then break to final return 1; D_0051BA88 void*).

// lifter variant 0
// CB3StreamManager::Prepare(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3StreamManager;
class CB3TrackList;
class CGTFileSystem;
struct UnkStruct_003C3430_2;
struct UnkStruct_D_004CA348;
struct UnkStruct_D_004F60C0;
struct UnkStruct_D_0051AEC0;
struct UnkStruct_D_0051BA88;

class CB3TrackList {
public:
    int GetTrackIndexFromID(unsigned long);
    void CreateTrackPathFromIndex(int, char*, int);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGTFileSystem {
public:
    int Open(const char*, unsigned int);
};

struct UnkStruct_D_0051BA88 {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C3430_2 {
    unsigned char pad_0[0x100];
};

struct UnkStruct_D_004F60C0 {
    CGTFileSystem * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051AEC0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004CA348 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3StreamManager {
public:
    int Prepare(unsigned long p0);

    int field_0;
    unsigned char field_4;
    unsigned char pad_5[0x3];
    unsigned long field_8;
    unsigned char pad_10[0xD8];
    int field_E8;
    int field_EC;
    int field_F0;
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_004F60C0 D_004F60C0;
extern UnkStruct_D_0051AEC0 D_0051AEC0;
extern CB3TrackList D_005196A0;
extern UnkStruct_D_004CA348 D_004CA348;

extern "C" char * strcat(char *, const char *);

// 0x003C3430
int CB3StreamManager::Prepare(unsigned long p0)
{
    UnkStruct_003C3430_2 local;
    if (D_0051BA88.field_0 == &D_0051AEC0) {
        field_E8 = 19;
        field_EC = 35;
    } else {
        field_E8 = 10;
        field_EC = 18;
    }
    switch (field_F0) {
    case 1:
    case 24:
        field_8 = p0;
        field_F0 = 2;
    case 2:
        if (field_4 != 0 && field_0 == 0) {
            D_005196A0.CreateTrackPathFromIndex(D_005196A0.GetTrackIndexFromID(field_8), (char*)&local, 256);
            strcat((char *)&local, (const char *)&D_004CA348);
            field_0 = D_004F60C0.field_0->Open((const char*)&local, 17);
            if (field_0 == 0) {
                return 0;
            }
        }
        field_F0 = 2;
        break;
    }
    return 1;
}
