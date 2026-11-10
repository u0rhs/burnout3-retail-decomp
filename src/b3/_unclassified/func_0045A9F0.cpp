// func_0045A9F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (buddy options page: sibling func_00315CE0's add-entry inline helper and bool locals; buddy name as a char array member field_4 (not CSE'd)).

// lifter variant 0
// func_0045A9F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3MenuComponentSelectionData;
class CB3VSelectComponentEntryData;

class CGtBuddiesPS2DirtySock;
struct UnkStruct_0045A9F0;
struct UnkStruct_0045A9F0_9;
struct UnkStruct_0045A9F0_e0;
struct UnkStruct_D_004D35F0;
struct UnkStruct_D_004D35F8;
struct UnkStruct_D_004D3600;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_01E3D4B0;
struct UnkStruct_D_01E89544;
struct UnkStruct_D_01E8954E;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E898F2;
struct UnkStruct_D_01E8D450;
struct UnkStruct_D_01E8D45A;
struct UnkStruct_D_01E8D490;
struct UnkStruct_D_01E8D49A;

class CGtBuddiesPS2DirtySock {
public:
    void IsPermanentBuddy(char*, bool*);
    void IsBuddyIgnored(char*, bool*);
    void IsWannaBeMyBuddy(char*, bool*);
    void IsWannaBeHisBuddy(char*, bool*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8954E {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89544 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D45A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D450 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D49A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D490 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898F2 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898E8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0045A9F0_9 {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
};

struct UnkStruct_D_01E3D4B0 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0045A9F0_e0 {
    int field_0;
    unsigned char field_4;
    unsigned char field_5;
    unsigned char pad_6[0x2];
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D35F0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D35F8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D3600 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0045A9F0 {
    unsigned char pad_0[0x4];
    char field_4[0xC9C];  // [G] the buddy name (size unknown)
    short field_CA0;
    short field_CA2;
    unsigned char pad_CA4[0x4];
    UnkStruct_0045A9F0_e0 field_CA8[1];  // [G] element count unknown
    unsigned char pad_CB0[0x28];
    int field_CD8[1];  // [G] element count unknown
    unsigned char pad_CDC[0x14];
    unsigned char field_CF0;
    unsigned char pad_CF1[0x5C];
    unsigned char field_D4D;
};

extern UnkStruct_D_01E8954E D_01E8954E;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E8D45A D_01E8D45A;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern UnkStruct_D_01E8D49A D_01E8D49A;
extern UnkStruct_D_01E8D490 D_01E8D490;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E3D4B0 D_01E3D4B0;
extern CGtBuddiesPS2DirtySock D_01E3D390;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_004D35F0 D_004D35F0;
extern UnkStruct_D_004D35F8 D_004D35F8;
extern UnkStruct_D_004D3600 D_004D3600;

extern "C" void Prepare__19CB3VSelectComponentFbffffPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, bool, float, float, float, float, const void *, void *, int, float);  // CB3VSelectComponent::Prepare(bool,float,float,float,float,const CB3MenuComponentSelectionData*,CB3VSelectComponentEntryData*), passed 2 more argument(s) [G]
extern "C" int func_00271A00(void *, int);
extern "C" void func_00320E20(void *, void *, void *, void *);

// inlined add-entry helper (placeholder name) [G]; same shape as func_00315CE0's
static inline void func_0045A9F0_inl1(UnkStruct_0045A9F0 * self, int id, unsigned char f4, int k)
{
    UnkStruct_0045A9F0_e0 * e = &self->field_CA8[self->field_CF0];
    e->field_0 = func_00271A00(&D_0051BA44, id);
    e->field_4 = f4;
    e->field_5 = 0;
    self->field_CD8[self->field_CF0] = k;
    self->field_CF0++;
}

// 0x0045A9F0
extern "C" void func_0045A9F0(UnkStruct_0045A9F0 * self)
{
    bool perm;
    bool ign;
    bool my;
    bool his;
    self->field_D4D = 1;
    if (D_01E8954E.field_0 != 0) {
        ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
    }
    if (D_01E8D45A.field_0 != 0) {
        ((UnkStruct_D_01E8D450 *)&D_01E8D450)->vfunc_C();
    }
    if (D_01E8D49A.field_0 != 0) {
        ((UnkStruct_D_01E8D490 *)&D_01E8D490)->vfunc_C();
    }
    if (D_01E898F2.field_0 != 0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    }
    D_01E3D390.IsPermanentBuddy(self->field_4, &perm);
    D_01E3D390.IsBuddyIgnored(self->field_4, &ign);
    D_01E3D390.IsWannaBeMyBuddy(self->field_4, &my);
    D_01E3D390.IsWannaBeHisBuddy(self->field_4, &his);
    self->field_CF0 = 0;
    if (!my && !his && !perm && D_01E3D4B0.field_0 != 0) {
        func_0045A9F0_inl1(self, 61, 0, 0);
    }
    if (his && D_01E3D4B0.field_0 != 0) {
        func_0045A9F0_inl1(self, 20, 0, 1);
    }
    unsigned char online = D_01E3D4B0.field_0;
    if (online != 0 && perm) {
        func_0045A9F0_inl1(self, 11, !online, 2);
    }
    func_0045A9F0_inl1(self, 62, 0, 3);
    if (!ign && D_01E3D4B0.field_0 != 0) {
        func_0045A9F0_inl1(self, 14, ign || !D_01E3D4B0.field_0, 4);
    }
    func_0045A9F0_inl1(self, 1088, 0, 5);
    unsigned char t10 = self->field_CF0;
    self->field_CA0 = 0;
    self->field_CA2 = t10;
    Prepare__19CB3VSelectComponentFbffffPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, 0, 320.0f, 256.0f, 26.0f, 34.0f, (const CB3MenuComponentSelectionData*)((char *)self + 0xCA0), (CB3VSelectComponentEntryData*)((char *)self + 0xCA8), 1, 640.0f);
    func_00320E20(&D_01E89544, &D_004D35F0, &D_004D35F8, &D_004D3600);
}
