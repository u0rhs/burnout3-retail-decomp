// NONMATCHING: func_004556D0 -- retail 265 / ours 265 instructions, 14 in changed runs
// L263: logic exact; 14 off: retail materialises &D_00519AA8/&D_005196A0/&D_005196A4 in s-regs at the top of each outer (region) iteration, ours hoists them before the outer loop (const locals) or not at all (plain globals); opt_loop_invariants off puts them inside but breaks the i3 loop (20)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// from build/vt/try_func_004556D0_best.cpp
// func_004556D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3TrackRegion {};
enum EB3BackgroundType {};

class CB3HardCodedCrashStageList;
class CB3HardCodedTrackList;
class CB3HardCodedTrackRegionList;
class CB3PromptBarComponent;
class CB3TrackList;
struct UnkStruct_004556D0;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_005196A4;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_01E88A80;
struct UnkStruct_D_01E89518;
struct UnkStruct_D_01E8961C;
struct UnkStruct_D_01E89800;

class CB3HardCodedCrashStageList {
public:
    static unsigned long GetCrashStageGtID(int);
};

class CB3TrackList {
public:
    int GetTrackRegion(unsigned long);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3HardCodedTrackRegionList {
public:
    static int GetTrackRegionString(EB3TrackRegion, bool);
};

class CB3HardCodedTrackList {
public:
    static int FindTrack(unsigned long);
    static int GetTrackString(int, bool);
};

class CB3PromptBarComponent {
public:
    void Prepare();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_005196A4 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x2BA68];
    unsigned long field_2BA68[1];  // [G] element count unknown
};

struct UnkStruct_D_01E89518 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8961C {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E88A80 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004556D0 {
    unsigned char pad_0[0x18];
    short field_18;
    short field_1A;
    int field_1C;
    int field_20;
    void * field_24;
    unsigned char field_28;
    unsigned char field_29;
    unsigned char field_2A;
    unsigned char pad_2B[0x1];
    int field_2C;
    int field_30;
    int field_34;
    void * field_38;
    unsigned char field_3C;
    unsigned char field_3D;
    unsigned char field_3E;
    unsigned char pad_3F[0x1];
    int field_40;
    int field_44;
    int field_48;
    void * field_4C;
    unsigned char field_50;
    unsigned char field_51;
    unsigned char field_52;
    unsigned char pad_53[0x1];
    int field_54;
    int field_58[1];  // [G] element count unknown
    unsigned char pad_5C[0xC];
    int field_68[1];  // [G] element count unknown
    unsigned char pad_6C[0xC];
    int field_78;
    unsigned char pad_7C[0x4];
    unsigned long field_80[1];  // [G] element count unknown
    unsigned char pad_88[0x98];
    int field_120[1];  // [G] element count unknown
    unsigned char pad_124[0x4C];
    int field_170;
    unsigned char pad_174[0x4];
    unsigned long field_178[1];  // [G] element count unknown
    unsigned char pad_180[0x328];
    int field_4A8[1];  // [G] element count unknown
    unsigned char pad_4AC[0x194];
    int field_640;
    int field_644;
    int field_648;
    int field_64C;
    int field_650;
};

extern UnkStruct_D_005196A4 D_005196A4;
extern unsigned long D_00519AA8[];  // [G] element count unknown
extern UnkStruct_D_004EE040 D_004EE040;
extern CB3TrackList D_005196A0;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E8961C D_01E8961C;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" int func_003E9490(int, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" int func_003BE5A0(void *, void *, void *);
extern "C" void func_003BC5B0(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x004556D0
extern "C" int func_004556D0(UnkStruct_004556D0 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    self->field_640 = 0;
    for (int i = 0; (i < 100); i++) {
        unsigned long r1 = CB3HardCodedCrashStageList::GetCrashStageGtID(i);
        self->field_178[self->field_640] = r1;
        int r2 = func_003E9490(i, 0);
        self->field_4A8[self->field_640] = r2;
        self->field_640 = (self->field_640 + 1);
    }
    if (self->field_64C >= self->field_640) {
        self->field_64C = 0;
    }
    self->field_78 = 0;
    for (int i1 = 0; (i1 < 3); i1++) {
        unsigned long * const ids = D_00519AA8;
        CB3TrackList * const tl = &D_005196A0;
        UnkStruct_D_005196A4 * const n = &D_005196A4;
        for (int i2 = 0; (i2 < n->field_0); i2++) {
            if (i1 == tl->GetTrackRegion(ids[i2])) {
                self->field_58[self->field_78] = i1;
                self->field_68[self->field_78] = CB3HardCodedTrackRegionList::GetTrackRegionString((EB3TrackRegion)i1, 0);
                self->field_78 = (self->field_78 + 1);
                break;
            }
        }
    }
    if (self->field_644 >= self->field_78) {
        self->field_644 = 0;
    }
    int t0 = self->field_644;
    int t1 = self->field_58[t0];
    self->field_170 = 0;
    for (int i3 = 0; (i3 < D_005196A4.field_0); i3++) {
        unsigned long t2 = D_004EE040.field_2BA68[i3];
        int r5 = D_005196A0.GetTrackRegion(t2);
        if (t1 == r5) {
            self->field_80[self->field_170] = t2;
            int r6 = CB3HardCodedTrackList::FindTrack(t2);
            int r7 = CB3HardCodedTrackList::GetTrackString(r6, 0);
            self->field_120[self->field_170] = r7;
            self->field_170 = (self->field_170 + 1);
        }
    }
    if (self->field_648 >= self->field_170) {
        self->field_648 = 0;
    }
    func_00319C80(&D_01E89518, 664, 14);
    self->field_18 = 0;
    self->field_1A = 3;
    unsigned char t3 = *(unsigned char *)&self->field_78;
    int r9 = func_00271A00(&D_0051BA44, 706);
    self->field_1C = r9;
    self->field_24 = ((char *)self + 0x68);
    self->field_28 = t3;
    self->field_29 = 4;
    self->field_2A = 0;
    self->field_2C = 0;
    self->field_20 = 0;
    int t4 = self->field_170;
    if (t4 <= 0) {
        int r10 = func_00271A00(&D_0051BA44, 719);
        self->field_30 = r10;
        self->field_38 = ((char *)self + 0x120);
        self->field_3C = t4;
        self->field_3D = 4;
        self->field_3E = 1;
        self->field_40 = 0;
        self->field_34 = 0;
    } else {
        int r11 = func_00271A00(&D_0051BA44, 719);
        self->field_30 = r11;
        self->field_38 = ((char *)self + 0x120);
        self->field_3C = t4;
        self->field_3D = 4;
        self->field_3E = 0;
        self->field_40 = 0;
        self->field_34 = 0;
    }
    int t5 = self->field_640;
    if (t5 <= 0) {
        int r12 = func_00271A00(&D_0051BA44, 720);
        self->field_44 = r12;
        self->field_4C = ((char *)self + 0x4A8);
        self->field_50 = t5;
        self->field_51 = 4;
        self->field_52 = 1;
        self->field_54 = 0;
        self->field_48 = 0;
    } else {
        int r13 = func_00271A00(&D_0051BA44, 720);
        self->field_44 = r13;
        self->field_4C = ((char *)self + 0x4A8);
        self->field_50 = t5;
        self->field_51 = 4;
        self->field_52 = 0;
        self->field_54 = 0;
        self->field_48 = 0;
    }
    func_003BE5A0(&D_01E8961C, ((char *)self + 0x18), ((char *)self + 0x1C));
    func_003BC5B0(&D_01E8961C, 0, self->field_644);
    func_003BC5B0(&D_01E8961C, 1, self->field_648);
    func_003BC5B0(&D_01E8961C, 2, self->field_64C);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 321, 3);
    D_01E894FC.Prepare();
    self->field_650 = 0;
    return 1;
}


