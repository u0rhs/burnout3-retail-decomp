// func_003BAE10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (as sibling func_003BAB10: char field_AC[256] member, element pointer, D_01EA2974 store before D_01EA2980 load).

// lifter variant 0
// func_003BAE10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3TrackList;
struct UnkStruct_003BAE10;
struct UnkStruct_003BAE10_13;
struct UnkStruct_003BAE10_15;
struct UnkStruct_003BAE10_16;
struct UnkStruct_003BAE10_6;
struct UnkStruct_003BAE10_8;
struct UnkStruct_003BAE10_e4;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_0051BACC;
struct UnkStruct_D_00665E52;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;
struct UnkStruct_kacGameDataFileName;

class CB3TrackList {
public:
    int GetTrackIndexFromID(unsigned long);
    void CreateTrackPathFromIndex(int, char*, int);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_003BAE10_8 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003BAE10_6 {
    unsigned char pad_0[0x34];
    UnkStruct_003BAE10_e4 * field_34;
};

struct UnkStruct_003BAE10_e4 {
    unsigned long field_0;
    unsigned long field_8;
    unsigned char pad_10[0x10];
};

struct UnkStruct_003BAE10_8 {
    unsigned long field_0;
    unsigned char pad_8[0x60];
    unsigned long field_68;
    unsigned char pad_70[0x3C];
    char field_AC[256];
};

struct UnkStruct_kacGameDataFileName {
    int field_0;
};

struct UnkStruct_D_01EA2974 {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2970 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_003BAE10_15 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_003BAE10_13 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003BAE10_13 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003BAE10_15 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003BAE10_16 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_0051BACC {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00665E52 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003BAE10 {
    unsigned char pad_0[0x8];
    UnkStruct_003BAE10_6 * field_8;
    unsigned char pad_C[0x4];
    int field_10;
    int field_14[1];  // [G] element count unknown
    unsigned char pad_18[0x14];
    int field_2C[1];  // [G] element count unknown
    unsigned char pad_30[0x14];
    unsigned char field_44[1];  // [G] element count unknown
    unsigned char pad_45[0x5];
    signed char field_4A[1];  // [G] element count unknown
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_kacGameDataFileName kacGameDataFileName;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_0051BACC D_0051BACC;
extern UnkStruct_D_00665E52 D_00665E52;
extern CB3TrackList D_005196A0;

extern "C" char * strcat(char *, const char *);
extern "C" UnkStruct_003BAE10_15 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x003BAE10
extern "C" void func_003BAE10(UnkStruct_003BAE10 * self, int p0)
{
    if (p0 != 0) {
        for (int i = 0; (i < 6); i++) {
            self->field_14[i] = self->field_2C[i];
            self->field_44[i] = self->field_4A[i];
        }
    }
    UnkStruct_003BAE10_8 * t2 = D_0051BA88.field_0;
    UnkStruct_003BAE10_e4 * e = &self->field_8->field_34[self->field_10];
    t2->field_0 = e->field_0;
    t2->field_68 = e->field_8;
    int r0 = D_005196A0.GetTrackIndexFromID(e->field_0);
    D_005196A0.CreateTrackPathFromIndex(r0, t2->field_AC, 256);
    strcat(t2->field_AC, (const char *)kacGameDataFileName.field_0);
    UnkStruct_003BAE10_15 * r3 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FA737AAA797);
    if (D_01EA2974.field_0 != r3) {
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r3, 0);
        void * t4 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r3;
        UnkStruct_003BAE10_13 * t5 = D_01EA2980.field_0;
        if (t5 != 0) {
            D_01EA2984.field_0 = t5->field_20;
            if (r3 != 0) {
                r3->field_8 = t5->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t4, 0);
    }
    D_0051BACC.field_0 = 8;
    D_00665E52.field_0 = 0;
}
