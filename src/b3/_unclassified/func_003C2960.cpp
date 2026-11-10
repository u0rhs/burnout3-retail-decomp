// func_003C2960 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (t0+0xAC as a char[0x100] member (array members aren't CSE'd); unsigned char index k = B1*2, k2 = k+1; D_01EA2974 store before the D_01EA2980 load).

// func_003C2960 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3TrackList;
struct UnkStruct_003C2960;
struct UnkStruct_003C2960_20;
struct UnkStruct_003C2960_22;
struct UnkStruct_003C2960_23;
struct UnkStruct_003C2960_3;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_0051BACC;
struct UnkStruct_D_00665E52;
struct UnkStruct_D_01E90198;
struct UnkStruct_D_01E901F0;
struct UnkStruct_D_01E90224;
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
    UnkStruct_003C2960_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C2960_3 {
    unsigned long field_0;
    unsigned long field_8;
    unsigned long field_10;
    unsigned char pad_18[0x50];
    unsigned long field_68;
    int field_70;
    int field_74;
    unsigned char pad_78[0x34];
    char field_AC[0x100];
};

struct UnkStruct_D_01E901F0 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90198 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_kacGameDataFileName {
    int field_0;
};

struct UnkStruct_D_01E90224 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
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
    virtual void vfunc_18(UnkStruct_003C2960_22 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_003C2960_20 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C2960_20 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C2960_22 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003C2960_23 {
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

struct UnkStruct_003C2960 {
    unsigned char pad_0[0x8];
    unsigned long field_8[1];  // [G] element count unknown
    unsigned char pad_10[0x20];
    unsigned long field_30[1];  // [G] element count unknown
    unsigned char pad_38[0x78];
    unsigned char field_B0;
    unsigned char field_B1;
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_01E901F0 D_01E901F0;
extern UnkStruct_D_01E90198 D_01E90198;
extern UnkStruct_kacGameDataFileName kacGameDataFileName;
extern UnkStruct_D_01E90224 D_01E90224;
extern unsigned long D_01E90130[];  // [G] element count unknown
extern int D_01E90170[];  // [G] element count unknown
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_0051BACC D_0051BACC;
extern UnkStruct_D_00665E52 D_00665E52;
extern CB3TrackList D_005196A0;

extern "C" char * strcat(char *, const char *);
extern "C" UnkStruct_003C2960_22 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x003C2960
extern "C" void func_003C2960(UnkStruct_003C2960 * self)
{
    UnkStruct_003C2960_3 * t0 = D_0051BA88.field_0;
    t0->field_68 = self->field_8[self->field_B0];
    t0->field_0 = self->field_30[self->field_B0];
    D_01E901F0.field_0 = t0->field_68;
    D_01E90198.field_0 = t0->field_0;
    int r0 = D_005196A0.GetTrackIndexFromID(self->field_30[self->field_B0]);
    D_005196A0.CreateTrackPathFromIndex(r0, t0->field_AC, 256);
    strcat(t0->field_AC, (const char *)kacGameDataFileName.field_0);
    if (D_01E90224.field_0 != 0) {
        unsigned char k = self->field_B1 * 2;
        t0->field_8 = D_01E90130[k];
        t0->field_70 = D_01E90170[k];
        unsigned char k2 = k + 1;
        t0->field_10 = D_01E90130[k2];
        t0->field_74 = D_01E90170[k2];
    } else {
        t0->field_8 = D_01E90130[self->field_B1];
        t0->field_70 = D_01E90170[self->field_B1];
    }
    UnkStruct_003C2960_22 * r3 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FA737AAA797);
    if (D_01EA2974.field_0 != r3) {
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r3, 0);
        void * t2 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r3;
        UnkStruct_003C2960_20 * t3 = D_01EA2980.field_0;
        if (t3 != 0) {
            D_01EA2984.field_0 = t3->field_20;
            if (r3 != 0) {
                r3->field_8 = t3->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t2, 0);
    }
    D_0051BACC.field_0 = 8;
    D_00665E52.field_0 = 0;
}
