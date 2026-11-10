// func_00396D30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (mgr = &D_01E90240 local at function top (kept in s0 across calls); dropped the const cast on the table-data argument).

// func_00396D30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CGt2dObjectTableData;
class CGt2dObjectTable;
class CB3MenuComponentSelectionData;

class CB3TableSelectComponent;
struct UnkStruct_00396D30;
struct UnkStruct_00396D30_1;
struct UnkStruct_00396D30_e0;
struct UnkStruct_D_004C9948;
struct UnkStruct_D_004C9950;
struct UnkStruct_D_004C9958;
struct UnkStruct_D_004C9960;
struct UnkStruct_D_004C9968;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E8D450;
struct UnkStruct_D_01E8D45C;
struct UnkStruct_D_01E8EAF8;
struct UnkStruct_D_01E90240;

class CB3TableSelectComponent {
public:
    void Prepare(int, CGt2dObjectTable*, const CB3MenuComponentSelectionData*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00396D30_1 {
    int field_0;
    int field_4;
};

struct UnkStruct_D_01E8D45C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C9968 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89800 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    u_long128 field_0;
};

struct UnkStruct_00396D30_e0 {
    unsigned char pad_0[0x40];
    u_long128 field_40;
};

struct UnkStruct_D_004C9948 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C9950 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D450 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8EAF8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C9958 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C9960 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00396D30 {
    unsigned char pad_0[0x24];
    short field_24;
    short field_26;
    short field_28;
    short field_2A;
    unsigned char pad_2C[0x114];
    UnkStruct_00396D30_e0 field_140[1];  // [G] element count unknown
    unsigned char pad_190[0x2CD];
    unsigned char field_45D;
    unsigned char pad_45E[0x2];
    int field_460;
};

extern UnkStruct_D_01E8D45C D_01E8D45C;
extern UnkStruct_D_004C9968 D_004C9968;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_004C9948 D_004C9948;
extern UnkStruct_D_004C9950 D_004C9950;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern CB3TableSelectComponent D_01E8D490;
extern UnkStruct_D_01E8EAF8 D_01E8EAF8;
extern UnkStruct_D_004C9958 D_004C9958;
extern UnkStruct_D_004C9960 D_004C9960;

extern "C" void Prepare__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPC20CGt2dObjectTableDatabb(void *, void *, void *, void *, void *, bool, bool);  // CB3TableComponent::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const CGt2dObjectTableData*,bool,bool)
extern "C" void Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(void *, void *, void *, void *, float);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x00396D30
extern "C" void func_00396D30(UnkStruct_00396D30 * self)
{
    UnkStruct_00396D30_1 local;  // [G] the frame's one local (size: up to the frame top)
    UnkStruct_D_01E90240 * mgr = &D_01E90240;
    self->field_45D = 2;
    self->field_460 = 0;
    local.field_0 = 0;
    local.field_4 = 0;
    Prepare__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPC20CGt2dObjectTableDatabb(&D_01E8D450, &D_004C9948, &local, &D_004C9950, ((char *)self + 0x58), 1, 0);
    self->field_28 = 0;
    self->field_2A = 9;
    D_01E8D490.Prepare(0, (CGt2dObjectTable*)D_01E8D45C.field_0, (const CB3MenuComponentSelectionData*)((char *)self + 0x28));
    self->field_24 = 0;
    self->field_26 = 9;
    Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(&D_01E8EAF8, &D_004C9958, &D_004C9960, ((char *)self + 0x24), D_004C9968.field_0);
    ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
    func_0031ECD0(&D_01E89800, 325, 3);
    for (int i = 0; (i < 9); i++) {
        self->field_140[i].field_40 = mgr->field_0;
    }
}
