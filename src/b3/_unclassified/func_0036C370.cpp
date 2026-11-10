// func_0036C370 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (if (n0 != 0) {..} else {..} order; 64-bit prompt value built as 'v = 0x105 | 4<<32; if/else v |= n<<32' and passed untruncated).

// lifter variant 0
// func_0036C370 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3BuddyDisplayComponent;
struct UnkStruct_0036C370_a1;
struct UnkStruct_D_004C8158;
struct UnkStruct_D_004C8160;
struct UnkStruct_D_01E3D460;
struct UnkStruct_D_01E8970C;
struct UnkStruct_D_01E89716;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E898F2;
struct UnkStruct_D_01E8D67A;
struct UnkStruct_D_01E8EAF8;
struct UnkStruct_D_01E8EB02;

class CB3BuddyDisplayComponent {
public:
    void SetFocus(bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
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

struct UnkStruct_0036C370_a1 {
    unsigned char pad_0[0xCC];
    int field_CC;
    unsigned char pad_D0[0x54];
    int field_124;
    int field_128;
};

struct UnkStruct_D_01E8D67A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89716 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8970C {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8EB02 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3D460 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8EAF8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C8158 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C8160 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E8D67A D_01E8D67A;
extern UnkStruct_D_01E89716 D_01E89716;
extern UnkStruct_D_01E8970C D_01E8970C;
extern UnkStruct_D_01E8EB02 D_01E8EB02;
extern UnkStruct_D_01E3D460 D_01E3D460;
extern CB3BuddyDisplayComponent D_01E8D670;
extern UnkStruct_D_01E8EAF8 D_01E8EAF8;
extern UnkStruct_D_004C8158 D_004C8158;
extern UnkStruct_D_004C8160 D_004C8160;
extern UnkStruct_D_01E89800 D_01E89800;

extern "C" void Prepare__24CB3BuddyDisplayComponentFv(void *, int, int);  // CB3BuddyDisplayComponent::Prepare(), passed 2 more argument(s) [G]
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);  // CB3PromptsComponent::SetCurrentPrompts(unsigned int,unsigned int); [G] declared with a 64-bit first value: retail builds a 64-bit a1 (0x105 | n<<32) and passes it untruncated
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(void *, void *, void *, void *, float);

// 0x0036C370
extern "C" void func_0036C370(int n0, UnkStruct_0036C370_a1 * p0)
{
    if (D_01E898F2.field_0 != 0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    }
    if (n0 != 0) {
        p0->field_CC = 2;
        if (D_01E8D67A.field_0 == 0) {
            Prepare__24CB3BuddyDisplayComponentFv(&D_01E8D670, p0->field_124, p0->field_128);
        }
        D_01E8D670.SetFocus(1);
        if (D_01E89716.field_0 != 0) {
            ((UnkStruct_D_01E8970C *)&D_01E8970C)->vfunc_C();
        }
        if (D_01E8EB02.field_0 == 0) {
            Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(&D_01E8EAF8, &D_004C8158, &D_004C8160, ((char *)p0 + 0x5C), 272.0f);
        }
        unsigned long v = 0x105 | ((unsigned long)4 << 32);
        if (D_01E3D460.field_0 == 6) {
            v |= (unsigned long)2 << 32;
        } else {
            v |= (unsigned long)1 << 32;
        }
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, v, 3);
    } else {
        func_0032D080(&D_01E898E8, 2, 66, 0, 0);
    }
}
