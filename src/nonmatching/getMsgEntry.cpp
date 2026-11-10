// NONMATCHING: getMsgEntry -- retail 32 / ours 34 instructions, 4 in changed runs
// 4 instrs off: flow right (goto form, r+done); retail returns v0 directly with ld ra in the b delay slot of the found block and lui hoisted into the loop-test bnez delay; ours returns via a1 move
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_00344C00_e {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};
extern char D_004C69B0[];
extern char D_004C69A0[];
extern char D_004C69C0[];
extern "C" int scePrintf(char *, ...);

extern "C" UnkStruct_00344C00_e *getMsgEntry(int id, UnkStruct_00344C00_e *e)
{
    UnkStruct_00344C00_e *r;
    goto test;
body:
    if (id >= e->field_0 && id <= e->field_4) {
        r = e;
        goto done;
    }
    e++;
test:
    if (e->field_8 != 0) goto body;
    scePrintf(D_004C69B0, D_004C69A0);
    scePrintf(D_004C69C0, id);
    r = 0;
done:
    return r;
}

