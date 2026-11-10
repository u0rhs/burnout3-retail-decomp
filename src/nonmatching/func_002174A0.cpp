// NONMATCHING: func_002174A0 -- retail 32 / ours 37 instructions, 48 in changed runs
// a77: UNMATCHABLE under MWCC: this is SDK libvib/libdbc code (sceVibGetProfile-like: sceDbcReceiveData with 64-bit bitfield command word {14:2,2:2,3:8,1:8} built in program order, uninit upper bits, bgezl branch-likely which MWCC never emits) i.e. gcc-compiled; the in-order and/or chain and 'ld ra' frame show gcc scheduling. Logic: r = sceDbcReceiveData(p0, cmd, &buf, p1); if (r >= 0) r = buf; return r.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_002174A0_cmd {
    unsigned long f0 : 14;
    unsigned long f1 : 2;
    unsigned long f2 : 8;
    unsigned long f3 : 8;
};
extern "C" int sceDbcReceiveData(int, UnkStruct_002174A0_cmd, void *, int);

// 0x002174A0
extern "C" int func_002174A0(int p0, int p1)
{
    int buf;
    UnkStruct_002174A0_cmd c;
    c.f0 = 2;
    c.f1 = 2;
    c.f2 = 3;
    c.f3 = 1;
    int r = sceDbcReceiveData(p0, c, &buf, p1);
    if (r >= 0) r = buf;
    return r;
}
