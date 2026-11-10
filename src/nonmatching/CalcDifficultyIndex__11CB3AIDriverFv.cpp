// NONMATCHING: CalcDifficultyIndex__11CB3AIDriverFv -- retail 71 / ours 71 instructions, 4 in changed runs
// near8: t0/t1/t2 declared first, assigned t1-then-t0 -> &D_00522660 addiu lands in the b delay slot as retail (5 -> 4). Left: global load order (retail D_0064D360 into v1 before D_0064D37C into a1; ours the reverse) and loop-2 beq v1,a0 vs ours a0,v1 (operand swaps/locals/!=/continue forms inert)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: CalcDifficultyIndex__11CB3AIDriverFv -- retail 71 / ours 71 instructions, 5 in changed runs
// a245: logic complete; callback is the static member (qsort fn-ptr param), int v1, element ptr; 5 left: late &D_00522660 addiu in delay slot, lui a1 placement, beq operand order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// from build/vt/try_CalcDifficultyIndex__11CB3AIDriverFv_best.cpp
// CB3AIDriver::CalcDifficultyIndex() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIDriver.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3AIDriver;
struct UnkStruct_00144D00_11;
struct UnkStruct_00144D00_4;
struct UnkStruct_00144D00_8;
struct UnkStruct_00144D00_e0;
struct UnkStruct_00144D00_e2;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0064D350;
struct UnkStruct_D_0064D360;
struct UnkStruct_D_0064D37C;
struct UnkStruct_func_00144E20;

struct UnkStruct_D_0064D360 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064D37C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064D350 {
    UnkStruct_00144D00_e0 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00144D00_e0 {
    unsigned char pad_0[0x97];
    unsigned char field_97;
};

struct UnkStruct_00144D00_e2 {
    int field_0;
    int field_4;
    unsigned char field_8;
    unsigned char pad_9[0x3];
};

struct UnkStruct_00144D00_4 {
    UnkStruct_00144D00_e2 field_0[1];  // [G] element count unknown
    unsigned char pad_C[0x44];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12AD28];
    UnkStruct_00144D00_8 * field_12AD28[1];  // [G] element count unknown
};

struct UnkStruct_00144D00_8 {
    unsigned char pad_0[0x1914];
    int field_1914;
};

struct UnkStruct_00144D00_11 {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};

struct UnkStruct_func_00144E20 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3AIDriver {
public:
    int CalcDifficultyIndex();
    static int _CalcDifficultyIndexQSortCallback(const void *, const void *);

    unsigned char pad_0[0x7A0];
    UnkStruct_00144D00_11 * field_7A0;
};

extern UnkStruct_D_0064D360 D_0064D360;
extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_0064D350 D_0064D350;
extern UnkStruct_D_00522660 D_00522660;

extern "C" void qsort(void *, int, int, int (*)(const void *, const void *));

// 0x00144D00
int CB3AIDriver::CalcDifficultyIndex()
{
    UnkStruct_00144D00_4 local;  // [G] the frame's one local (size: up to the frame top)
    int t0;
    int t1;
    UnkStruct_00144D00_e0 * t2;
    t1 = D_0064D37C.field_0;
    t0 = D_0064D360.field_0;
    t2 = D_0064D350.field_0;
    for (int i = 0; (i < t1); i++) {
        int v1 = 0;
        if (i < t0) {
            v1 = t2[i].field_97;
        }
        UnkStruct_00144D00_8 * t3 = D_00522660.field_12AD28[i];
        local.field_0[i].field_0 = i;
        local.field_0[i].field_4 = v1;
        local.field_0[i].field_8 = (t3->field_1914 == 1);
    }
    qsort(&local, t1, 12, CB3AIDriver::_CalcDifficultyIndexQSortCallback);
    int t4 = D_0064D37C.field_0;
    for (int i1 = 0; (i1 < t4); i1++) {
        if (field_7A0->field_19AC == local.field_0[i1].field_0) {
            return i1;
        }
    }
    return 0;
}

