// NONMATCHING: PackHeader__15CB3ReplaySystemFv -- retail 101 / ours 99 instructions, 8 in changed runs
// a248: logic exact, regs t2=1/t0=3 right; remaining: retail rematerialises li 3 / li 1 inside the switch (2 extra instrs), ours reuses t0/t2. tried unsigned switch, if-chain, const locals
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// lifter variant 0
// CB3ReplaySystem::PackHeader() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ReplaySystem.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3ReplaySystem;
class CGtByteStream;
struct UnkStruct_00154E60_13;
struct UnkStruct_00154E60_5;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0064D370;
struct UnkStruct_D_0064D37C;
struct UnkStruct_D_0064D3A0;
struct UnkStruct_D_0064D3A4;
struct UnkStruct_D_01E900B4;
struct UnkStruct_D_01E900B8;

class CGtByteStream {
public:
    int GetUsage() const;
};

struct UnkStruct_D_0064D3A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064D3A4 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064D370 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_00154E60_5 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00154E60_5 {
    unsigned char pad_0[0x68];
    unsigned long field_68;
};

struct UnkStruct_D_01E900B4 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E900B8 {
    unsigned int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064D37C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12AD28];
    UnkStruct_00154E60_13 * field_12AD28[1];  // [G] element count unknown
};

struct UnkStruct_00154E60_13 {
    unsigned char pad_0[0x59];
    signed char field_59;
    unsigned char pad_5A[0x1906];
    unsigned long field_1960;
};

class CB3ReplaySystem {
public:
    int PackHeader();

    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    unsigned long field_18;
    unsigned long field_20;
    unsigned long field_28[1];  // [G] element count unknown
    unsigned char pad_30[0x28];
    unsigned char field_58[1];  // [G] element count unknown
    unsigned char pad_59[0x7];
    CGtByteStream field_60;
    unsigned char pad_61[0x1F];
    int field_80;
};

extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_0064D3A4 D_0064D3A4;
extern UnkStruct_D_0064D370 D_0064D370;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_01E900B4 D_01E900B4;
extern UnkStruct_D_01E900B8 D_01E900B8;
extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_00522660 D_00522660;

// 0x00154E60
int CB3ReplaySystem::PackHeader()
{
    field_4 = 1;
    field_8 = field_80;
    field_C = D_0064D3A0.field_0;
    field_10 = D_0064D3A4.field_0;
    field_18 = D_0064D370.field_0;
    field_20 = D_0051BA88.field_0->field_68;
    if (D_01E900B4.field_0 == 3) {
        field_0 = 7;
    } else {
        switch (D_01E900B8.field_0) {
        case 0:
            field_0 = 0;
            break;
        case 1:
            field_0 = 4;
            break;
        case 2:
            field_0 = 3;
            break;
        case 3:
            field_0 = 6;
            break;
        default:
            break;
        }
    }
    int r0 = field_60.GetUsage();
    field_14 = r0;
     int n = field_C + field_10;
    if (n != D_0064D37C.field_0) {
        return 0;
    }
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        if (i < D_0064D37C.field_0) {
            UnkStruct_00154E60_13 * t0 = D_00522660.field_12AD28[i];
            field_28[i] = t0->field_1960;
            field_58[i] = t0->field_59;
        } else {
            field_28[i] = 0;
            field_58[i] = 0;
        }
    }
    i++;
loop0_test:
    if (i < 6) goto loop0_body;
    return 1;
}

