// NONMATCHING: func_003C9340 -- retail 231 / ours 231 instructions, 11 in changed runs
// psweep: scoped #pragma opt_dead_code off [G] improves 16 -> 11
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_dead_code off
// NONMATCHING: func_003C9340 -- retail 231 / ours 231 instructions, 29 in changed runs
// a224: inl2 tail as 'switch (v) { default: B; break; case 3: A; break; }' puts A inline (231/231, 42->29 off; if/!=/early-return forms all keep A out of line). Left: compare-constant reg (retail 3 in v1, 1 in a1 shared with A's arg a1, v in v0; ours 3 in a2, 1 in v1, v in a1) and A/B block placement at tail
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

struct UnkStruct_D_01EA2974 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2970 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_003C9340_3 { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_D_01EA2980 { UnkStruct_003C9340_3 * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2984 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_003C9340_5 { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_D_01E97F38 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E96F78 { unsigned char pad_0[0x10]; };
struct UnkStruct_003C9340 { unsigned char pad_0[0x10]; unsigned char field_10; };
struct UnkStruct_D_01E900B8 { int field_0; unsigned char pad_4[12]; };
struct UnkStruct_D_01E94E54 { int field_0; unsigned char pad_4[12]; };
struct UnkStruct_D_01E900D4 { int field_0; unsigned char pad_4[12]; };
struct UnkStruct_D_01E900D8 { int field_0; unsigned char pad_4[12]; };
struct UnkStruct_D_01E900E0 { int field_0; unsigned char pad_4[12]; };
struct UnkStruct_D_01E900EC { int field_0; unsigned char pad_4[12]; };
struct UnkStruct_D_01E900C8 { int field_0; unsigned char pad_4[12]; };
struct UnkStruct_D_01E901FC { int field_0; unsigned char pad_4[12]; };
struct UnkStruct_D_01E96F90 { int field_0; unsigned char pad_4[12]; };
struct UnkStruct_D_01E90198 { unsigned long field_0; unsigned char pad_8[8]; };
struct UnkStruct_D_01E901F0 { unsigned long field_0; unsigned char pad_8[8]; };
struct UnkStruct_D_01E96F80 { unsigned long field_0; unsigned char pad_8[8]; };
struct UnkStruct_D_01E96F88 { unsigned long field_0; unsigned char pad_8[8]; };

extern UnkStruct_D_01E900B8 D_01E900B8;
extern UnkStruct_D_01E94E54 D_01E94E54;
extern UnkStruct_D_01E900D4 D_01E900D4;
extern UnkStruct_D_01E900D8 D_01E900D8;
extern UnkStruct_D_01E900E0 D_01E900E0;
extern UnkStruct_D_01E900EC D_01E900EC;
extern UnkStruct_D_01E900C8 D_01E900C8;
extern UnkStruct_D_01E901FC D_01E901FC;
extern UnkStruct_D_01E96F90 D_01E96F90;
extern UnkStruct_D_01E90198 D_01E90198;
extern UnkStruct_D_01E901F0 D_01E901F0;
extern UnkStruct_D_01E96F80 D_01E96F80;
extern UnkStruct_D_01E96F88 D_01E96F88;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01E97F38 D_01E97F38;
extern UnkStruct_D_01E96F78 D_01E96F78;

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int func_00454D80(void *, int, int, unsigned long);
extern "C" int func_00432AB0(void *, int);
extern "C" unsigned long func_00454A60(void *);
extern "C" unsigned long GetCrashStageTrackID__26CB3HardCodedCrashStageListFUl(unsigned long);
extern "C" void func_003C9210(UnkStruct_003C9340 *);

static inline void func_003C9340_inl1(unsigned long id, int mode)
{
    UnkStruct_003C9340_5 * r = (UnkStruct_003C9340_5 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, id);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, mode);
    void * t1 = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_003C9340_3 * t2 = D_01EA2980.field_0;
    if (t2 != 0) {
        D_01EA2984.field_0 = t2->field_20;
        if (r != 0) {
            r->field_8 = t2->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t1, mode);
}

static inline void func_003C9340_inl2(UnkStruct_003C9340 * self)
{
    self->field_10 = 1;
    switch (D_01E900B8.field_0) {
    case 3:
        func_00454D80(&D_01E97F38, 1, -1, 0);
        break;
    default:
        func_00432AB0(&D_01E96F78, D_01E900B8.field_0);
        break;
    }
}

// 0x003C9340
extern "C" void func_003C9340(UnkStruct_003C9340 * self, int p0, void * p1, void * p2, long p3)
{
    switch (p0) {
    case 3:
        switch (p3) {
        case 0:
        default:
            func_003C9210(self);
            break;
        case 3:
            func_003C9340_inl2(self);
            break;
        }
        break;
    case 5:
        switch ((int)p2) {
        case 0:
            if (self->field_10 != 0) {
                if (D_01E900B8.field_0 == 3) {
                    unsigned long s = func_00454A60(&D_01E97F38);
                    D_01E90198.field_0 = GetCrashStageTrackID__26CB3HardCodedCrashStageListFUl(s);
                    D_01E901F0.field_0 = s;
                    D_01E900C8.field_0 = 0;
                    D_01E901FC.field_0 = 0;
                } else {
                    D_01E90198.field_0 = D_01E96F80.field_0;
                    D_01E901F0.field_0 = D_01E96F88.field_0;
                    D_01E900C8.field_0 = D_01E96F90.field_0;
                    D_01E901FC.field_0 = 0;
                }
                D_01E900E0.field_0 = 0;
                D_01E900EC.field_0 = 9;
                func_003C9340_inl1(0x9441407ECBC88C0FUL, 0);
            } else {
                switch (D_01E94E54.field_0) {
                default:
                    D_01E900B8.field_0 = 0;
                    break;
                case 1:
                    D_01E900B8.field_0 = 1;
                    break;
                case 2:
                    D_01E900B8.field_0 = 2;
                    break;
                case 3:
                    D_01E900B8.field_0 = 3;
                    D_01E900D4.field_0 = 1;
                    D_01E900D8.field_0 = 1;
                    break;
                }
                func_003C9340_inl2(self);
            }
            break;
        case 3:
            if (self->field_10 == 0) {
                func_003C9340_inl1(0x94413FC035B0F871UL, 0);
            } else {
                goto c2;
            }
            break;
        }
        break;
    }
    return;
c1:
    func_003C9210(self);
    return;
c2:
    func_003C9210(self);
}


#pragma pop
