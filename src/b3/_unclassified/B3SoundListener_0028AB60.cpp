// CB3SoundListener::Prepare(unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundListener.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (false splat symbolisation resolved (diff_vs_retail any-symbol ABS)).

// CB3SoundListener::Prepare(unsigned int)
// [C] retail asm shows the D_00522660+i*0x27D0+0x12C6FC byte load as `lui %hi(__moddi3+0x4C)` / `lb %lo(..)` (splat symbolised the constant): same bytes, 2 reloc-notation diffs in the harness.
class CB3SoundListener;
class CGtSoundListener;
struct UnkStruct_D_0064D370 {
    unsigned long field_0;
    unsigned char pad_8[0x8];
};
struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_01E75688 {
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x27D0];
};

class CGtSoundListener {
public:
    bool Prepare(unsigned int);
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
};

class CB3SoundListener : public CGtSoundListener {
public:
    bool Prepare(unsigned int p0);

    unsigned char field_C;
    void * field_10;
    int field_14;
    int field_18;
};

extern UnkStruct_D_0064D370 D_0064D370;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_01E75688 D_01E75688;
extern UnkStruct_D_00522660 D_00522660;
extern "C" int func_00131E40(void *);
extern "C" void func_00384A30(void *, float);

// 0x0028AB60
bool CB3SoundListener::Prepare(unsigned int p0)
{
    if (!CGtSoundListener::Prepare(p0)) {
        return 0;
    }
    if (D_0064D370.field_0 != 0) {
        field_10 = (char *)&D_004EE040 + p0 * 0xBB0 + 0x28E00;
        field_14 = *((signed char *)&D_00522660 + p0 * 0x27D0 + 0x12C6FC);
    }
    field_C = 0;
    if (func_00131E40(&D_004EE040) == 0) {
        func_00384A30(&D_01E75688, 1.0f);
    } else {
        func_00384A30(&D_01E75688, 0.0f);
    }
    field_18 = 0;
    return 1;
}
