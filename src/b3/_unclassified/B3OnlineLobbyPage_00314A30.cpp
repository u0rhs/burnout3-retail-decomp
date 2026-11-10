// CB3OnlineLobbyPage::UpdateLaunchGame() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (record ptr before AmIHost (no phantom arg); 0x48-byte local; int& refs for C/14/20; by-ref 8-byte id inline; statement order; ||-of-&& else-arm).

// lifter variant 0
// CB3OnlineLobbyPage::UpdateLaunchGame() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3OnlineLobbyPage;
class CB3TrackList;
class CGtLobbyPS2DirtySock;
struct UnkStruct_00314A30_7;
struct UnkStruct_00314A30_9;
struct UnkStruct_00314A30_e0;
struct UnkStruct_D_004F50C0;
struct UnkStruct_D_004F6061;
struct UnkStruct_D_0051B24C;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E32B08;
struct UnkStruct_D_01E65480;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E898F2;
struct UnkStruct_D_01E900C0;
struct UnkStruct_D_01E900CC;
struct UnkStruct_D_01E90198;
struct UnkStruct_D_01E901F0;
struct UnkStruct_D_01E90225;

class CGtLobbyPS2DirtySock {
public:
    void LeaveGameImmediately();

    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual int vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual int vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC(UnkStruct_00314A30_9 *);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3TrackList {
public:
    int IsTrackPointToPoint(unsigned long);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004F6061 {
    signed char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00314A30_e0 {
    unsigned char pad_0[0xE4];
    short field_E4;
    unsigned char pad_E6[0x46];
};

struct UnkStruct_D_004F50C0 {
    unsigned char pad_0[0xCE4];
    UnkStruct_00314A30_e0 field_CE4[1];  // [G] element count unknown
};

struct UnkStruct_D_01E32B08 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E900CC {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00314A30_7 {
    unsigned char pad_0[0x80];
    int field_80;
    unsigned char pad_84[0x38];
    int field_BC;
};

struct UnkStruct_D_01E65480 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00314A30_9 {
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x4];
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    unsigned char pad_2C[0x1C];
};

struct UnkStruct_D_01E900C0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90225 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E901F0 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90198 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051B24C {
    int field_0;
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

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnlineLobbyPage {
public:
    void UpdateLaunchGame();

    unsigned char pad_0[0x1388];
    int field_1388;
    unsigned char pad_138C[0x18];
    unsigned char field_13A4;
    unsigned char field_13A5;
    unsigned char pad_13A6[0x6];
    signed char field_13AC;
};

extern UnkStruct_D_004F6061 D_004F6061;
extern UnkStruct_D_004F50C0 D_004F50C0;
extern UnkStruct_D_01E32B08 D_01E32B08;
extern CGtLobbyPS2DirtySock D_01E3CD44;
extern UnkStruct_D_01E900CC D_01E900CC;
extern UnkStruct_D_01E65480 D_01E65480;
extern UnkStruct_D_01E900C0 D_01E900C0;
extern UnkStruct_D_01E90225 D_01E90225;
extern UnkStruct_D_01E901F0 D_01E901F0;
extern UnkStruct_D_01E90198 D_01E90198;
extern UnkStruct_D_0051B24C D_0051B24C;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern CB3TrackList D_005196A0;

extern "C" int AmIHost__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::AmIHost()
extern "C" void func_0026F2B0(void *);
extern "C" void func_0032D080(void *, int, int, int, int);

// [G] 8-byte id built on the stack from two ints and passed/stored as one unsigned long (ld/sd)
struct UnkStruct_00314A30_id {
    int field_0;
    int field_4;
};

struct UnkStruct_00314A30_sub {
    unsigned char pad_0[0x80];
    short field_80;
    unsigned char pad_82[0xAA];
};

// [G] D_004F50C0 viewed as an array of 0x12C-byte records from +0xD48 (retail keeps &rec in s0 across AmIHost)
struct UnkStruct_00314A30_D {
    unsigned char pad_0[0xD48];
    UnkStruct_00314A30_sub field_D48[1];  // [G] element count unknown
};

static inline unsigned long func_00314A30_inl1(  // [G] inlined helper, name unknown; by-reference args give the addiu sp,K address regs
    const int & a, const int & b)
{
    UnkStruct_00314A30_id t;
    t.field_0 = a;
    t.field_4 = b;
    return *(unsigned long *)&t;
}

// 0x00314A30
void CB3OnlineLobbyPage::UpdateLaunchGame()
{
    UnkStruct_00314A30_9 local;  // [G] the frame's one local (size: up to the frame top)
    UnkStruct_00314A30_sub * e = &((UnkStruct_00314A30_D *)&D_004F50C0)->field_D48[D_004F6061.field_0];
    if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0 && e->field_80 != 0 && field_13A5 != 0 && field_13A4 != 0 && D_01E32B08.field_0 > 1) {
        signed char t1 = field_13AC;
        if (t1 != 12 && t1 != 14 && t1 != 13) {
            D_01E3CD44.LeaveGameImmediately();
            field_13AC = 17;
        }
    }
    if (((CGtLobbyPS2DirtySock *)&D_01E3CD44)->vfunc_70() == 0) {
        return;
    }
    signed char t2 = field_13AC;
    if (t2 != 12 && t2 != 14 && t2 != 13) {
        D_01E900CC.field_0 = field_1388;
        func_0026F2B0(&D_01E32AE0);
        D_01E65480.field_0 = ((CGtLobbyPS2DirtySock *)&D_01E3CD44)->vfunc_80();
        ((CGtLobbyPS2DirtySock *)&D_01E3CD44)->vfunc_BC(&local);
        int & c = local.field_C;
        int & k = local.field_14;
        int & d = local.field_20;
        D_01E900C0.field_0 = k;
        D_01E90198.field_0 = func_00314A30_inl1(c, d);
        D_01E901F0.field_0 = func_00314A30_inl1(local.field_24, local.field_28);
        D_01E90225.field_0 = ((((unsigned int)local.field_18 >> 16) & 255) == 1);
        if (D_005196A0.IsTrackPointToPoint(func_00314A30_inl1(c, d)) == 0 || (k != 0 && k != 1)) {
            D_0051B24C.field_0 = (((unsigned int)local.field_1C >> 24) & 255);
        } else {
            D_0051B24C.field_0 = 1;
        }
        field_13AC = 11;
        if (D_01E898F2.field_0 != 0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        }
        func_0032D080(&D_01E898E8, 0, 952, 15, 0);
    }
}
