// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// GetCarTexture__22CB3ImageReward2dObjectF17EB3MenuCarClassesi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (find-by-name: strcasecmp(((blk*)(int+0x90))->field_18) per N113; find result and fallback global typed void* (int flips block layout)).

// GetCarTexture__22CB3ImageReward2dObjectF17EB3MenuCarClassesi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3MenuCarClasses {};

class CB3VehicleList;
struct UnkStruct_004277C0_0;
struct UnkStruct_004277C0_2;
struct UnkStruct_004277C0_e0;
struct UnkStruct_D_0051A868;
struct UnkStruct_D_01EA46FC;
struct UnkStruct_D_01EA4710;

class CB3VehicleList {
public:
    unsigned long GetCarID(EB3MenuCarClasses, int);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004277C0_0 {
    unsigned char pad_0[0x10];
};

struct UnkStruct_D_0051A868 {
    UnkStruct_004277C0_2 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004277C0_2 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_004277C0_e0 * field_C;
};

struct UnkStruct_004277C0_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

struct UnkStruct_D_01EA46FC {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA4710 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_0051A868 D_0051A868;
extern UnkStruct_D_01EA46FC D_01EA46FC;
extern UnkStruct_D_01EA4710 D_01EA4710;
extern CB3VehicleList D_005186A0;

extern "C" void func_0021AB40(unsigned long, UnkStruct_004277C0_0 *);
extern "C" int strcasecmp(const char *, UnkStruct_004277C0_0 *);

// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113, B3SunRendererPS2_0024D390).
struct UnkStruct_004277C0_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

static inline void * func_004277C0_inl1(UnkStruct_004277C0_0 * name)
{
    UnkStruct_004277C0_2 * t0 = D_0051A868.field_0;
    for (int i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_004277C0_blk *)(t2 + 0x90))->field_18, name) == 0) {
            return (void *)t2;
        }
    }
    return 0;
}

// 0x004277C0
extern "C" int GetCarTexture__22CB3ImageReward2dObjectF17EB3MenuCarClassesi(int n0, int p0)
{
    UnkStruct_004277C0_0 local;  // [G] the frame's one local (size: up to the frame top)
    if (p0 == -1) return D_01EA4710.field_0;
    unsigned long r0 = D_005186A0.GetCarID((EB3MenuCarClasses)n0, p0);
    if (r0 == 0) return 0;
    func_0021AB40(r0, &local);
    void * v = func_004277C0_inl1(&local);
    if (v == 0) v = D_01EA46FC.field_0;
    return (int)v;
}
