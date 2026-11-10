// func_003C4150 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (if-else chain (not switch) on p1; bool locked/|| bool; i+400 local; element pointer after call).

// lifter variant 0
// func_003C4150 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3BackgroundType {};
enum ESatMapLevel {};
enum EB3TrackRegion {};
enum ESatMapEnterDirection {};

class CB3PromptBarComponent;
class CB3SatNavComponent;
struct UnkStruct_003C4150;
struct UnkStruct_003C4150_e0;
struct UnkStruct_D_004E2ED4;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_0051BF9C;
struct UnkStruct_D_01E7A800;
struct UnkStruct_D_01E7A888;
struct UnkStruct_D_01E88A80;
struct UnkStruct_D_01E893D4;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E8E7E0;

class CB3SatNavComponent {
public:
    void Prepare(ESatMapLevel, EB3TrackRegion, ESatMapEnterDirection);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3PromptBarComponent {
public:
    void Prepare();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BF9C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E2ED4 {
    unsigned char field_0;
};

struct UnkStruct_003C4150_e0 {
    int field_0;
    unsigned char field_4;
    unsigned char field_5;
    unsigned char pad_6[0x2];
};

struct UnkStruct_D_01E893D4 {
    signed char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E7A800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E7A888 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E88A80 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8E7E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C4150 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    int field_C;
    unsigned char field_10;
    unsigned char field_11;
    unsigned char field_12;
    unsigned char pad_13[0x1];
    short field_14;
    short field_16;
    UnkStruct_003C4150_e0 field_18[1];  // [G] element count unknown
};

extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_004E2ED4 D_004E2ED4;
extern UnkStruct_D_01E893D4 D_01E893D4;
extern UnkStruct_D_01E7A800 D_01E7A800;
extern UnkStruct_D_01E7A888 D_01E7A888;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern CB3SatNavComponent D_01E88AF0;
extern UnkStruct_D_01E8E7E0 D_01E8E7E0;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void func_00284FB0(void *);
extern "C" void func_003FA600(void *, int);
extern "C" int func_003F5800(int, int);
extern "C" int func_00135DA0(void *, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003C43E0(UnkStruct_003C4150 *, int, int);
extern "C" int func_003B78D0(void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x003C4150
extern "C" int func_003C4150(UnkStruct_003C4150 * self, int p0, int p1, int p2)
{
    int t0 = D_0051BF9C.field_0;
    Prepare__15CB3MenuPageBaseFb(self, 0);
    func_00284FB0(&D_01E7A800);
    func_003FA600(&D_01E7A888, 1);
    self->field_8 = p0;
    self->field_10 = 0;
    self->field_11 = 0;
    self->field_12 = 0;
    D_004E2ED4.field_0 = 0;
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    for (int i = 0; i < 3; i++) {
        int id = i + 400;
        bool locked = !func_003F5800(i, t0);
        bool v1 = func_00135DA0((void *)(t0), i, 1) != 0 || func_00135DA0((void *)(t0), i, 0) != 0;
        int name = func_00271A00(&D_0051BA44, id);
        UnkStruct_003C4150_e0 * e = &self->field_18[i];
        e->field_0 = name;
        e->field_4 = locked;
        e->field_5 = v1;
        if (self->field_8 == i && locked) {
            self->field_8 = 0;
        }
    }
    self->field_14 = self->field_8;
    self->field_16 = 3;
    int v3;
    if (p1 == 0) {
        self->field_4 = 0;
        func_003C43E0(self, 1, 1);
        func_003B78D0(&D_01E8E7E0, self->field_8);
        v3 = 0;
    } else if (p1 == 1) {
        self->field_4 = 1;
        func_003C43E0(self, 1, 1);
        D_01E88AF0.Prepare((ESatMapLevel)0, (EB3TrackRegion)self->field_8, (ESatMapEnterDirection)p2);
        self->field_10 = 1;
        v3 = 12;
    } else if (p1 == 4) {
        self->field_4 = 4;
        func_003C43E0(self, 1, 1);
        D_01E88AF0.Prepare((ESatMapLevel)1, (EB3TrackRegion)self->field_8, (ESatMapEnterDirection)p2);
        self->field_10 = 1;
        v3 = 3;
    } else {
        self->field_4 = 2;
        func_003C43E0(self, 1, 1);
        D_01E88AF0.Prepare((ESatMapLevel)1, (EB3TrackRegion)self->field_8, (ESatMapEnterDirection)p2);
        self->field_10 = 1;
        v3 = 3;
    }
    func_0031ECD0(&D_01E89800, 0x800000105, v3);
    D_01E894FC.Prepare();
    self->field_C = D_01E893D4.field_0;
    return 1;
}
