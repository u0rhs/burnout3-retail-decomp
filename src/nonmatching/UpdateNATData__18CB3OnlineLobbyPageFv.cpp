// NONMATCHING: UpdateNATData__18CB3OnlineLobbyPageFv -- retail 232 / ours 232 instructions, 15 in changed runs
// a147: 232/232 instrs, 15 in changed runs, ALL one register swap: retail keeps the host loop index in s2 and the player pointer (func_002366D0 result) in s1; ours gives s1 to the index (n's reg, free after the first two loops) and s2 to the pointer. 120 declaration-order permutations, const pointers, separate counters j/i, for-scope i all fail to flip it. Layout found: if (s3 == 0) {loop2} else {loop1} puts loop1's cond2 block after loop2 like retail; rows via (UnkStruct_row*)((char*)p + k*4) with int o = k*4 shared.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (a147).
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E32AE0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E3CD44 {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34();
    virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44();
    virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64();
    virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74();
    virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84();
    virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94();
    virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4();
    virtual void vfunc_A8(); virtual void vfunc_AC(); virtual void vfunc_B0(); virtual void vfunc_B4(); virtual void vfunc_B8();
    virtual void vfunc_BC(); virtual void vfunc_C0(); virtual void vfunc_C4(); virtual void vfunc_C8(); virtual void vfunc_CC();
    virtual void vfunc_D0(int, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_player {
    virtual int vfunc_8();
    virtual int vfunc_C();
    virtual int vfunc_10();
    unsigned char pad_4[0x4FC];
    int field_500[8];
    int field_520[8];
    unsigned char pad_540[0x40];
    int field_580[8];
    int field_5A0[8];
};
struct UnkStruct_row {
    unsigned char pad_0[0x500];
    int field_500;
    unsigned char pad_504[0x1C];
    int field_520;
    unsigned char pad_524[0x5C];
    int field_580;
    unsigned char pad_584[0x1C];
    int field_5A0;
};
class CB3OnlineLobbyPage {
public:
    void UpdateNATData();
    unsigned char pad_0[0x13A4];
    bool field_13A4;
};
extern UnkStruct_D_int D_01E32B08;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern "C" int func_0022D3B0();
extern "C" UnkStruct_player * func_002366D0(void *, int);
extern "C" void func_0023B500(UnkStruct_player *);
extern "C" int func_0023B380(UnkStruct_player *);
extern "C" int func_0022FBB0(UnkStruct_player *);
extern "C" int AllNATDataIsFinalised__17CB3NetworkManagerFv(void *);
extern "C" int AmIHost__17CB3NetworkManagerFv(void *);
extern "C" int GetMyPlayerID__23CGtNetworkPlayerManagerCFv(void *);

// 0x00315940
void CB3OnlineLobbyPage::UpdateNATData()
{
    field_13A4 = true;
    int s5;
    int s4;
    UnkStruct_player * s3;
    UnkStruct_player * s1;
    int i;
    int n = D_01E32B08.field_0;
    if (func_0022D3B0()) {
        for (i = 0; i < n; i++) {
            UnkStruct_player * p = func_002366D0(&D_01E32AE0, i);
            if (p != 0) func_0023B500(p);
        }
    }
    if (AllNATDataIsFinalised__17CB3NetworkManagerFv(&D_01E32AE0) == 0) {
        field_13A4 = false;
    } else if (func_0022D3B0() == 0) {
        field_13A4 = false;
    }
    if (field_13A4) {
        for (i = 0; i < n; i++) {
            UnkStruct_player * p = func_002366D0(&D_01E32AE0, i);
            if (p != 0) {
                if (func_0023B380(p) == 0) field_13A4 = false;
            }
        }
    }
    if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0 && !field_13A4) {
        for (i = 0; i < D_01E32B08.field_0; i++) {
            s1 = func_002366D0(&D_01E32AE0, i);
            if (s1 == 0) continue;
            for (s5 = 0; s5 < D_01E32B08.field_0; s5++) {
                if (i == s5) continue;
                s3 = func_002366D0(&D_01E32AE0, s5);
                if (s3 == 0) {
                    for (s4 = 0; s4 < 8; s4++) {
                        UnkStruct_row * r1 = (UnkStruct_row *)((char *)s1 + s4 * 4);
                        if (r1->field_500 == func_0022FBB0(s1) && r1->field_520 == 3) { s4 = -1; break; }
                        if (r1->field_580 == GetMyPlayerID__23CGtNetworkPlayerManagerCFv(&D_01E32AE0) && r1->field_5A0 == 3) { s4 = -1; break; }
                    }
                } else {
                    for (s4 = 0; s4 < 8; s4++) {
                        int o = s4 * 4;
                        UnkStruct_row * r1 = (UnkStruct_row *)((char *)s1 + o);
                        if (r1->field_580 == func_0022FBB0(s3) && r1->field_5A0 == 3) { s4 = -1; break; }
                        UnkStruct_row * r3 = (UnkStruct_row *)((char *)s3 + o);
                        if (r3->field_580 == func_0022FBB0(s1) && r3->field_5A0 == 3) { s4 = -1; break; }
                    }
                }
                if (s4 != -1) continue;
                if (s3 == 0) {
                    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_D0(s1->vfunc_10(), 3);
                } else if (s5 < i) {
                    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_D0(s1->vfunc_10(), 3);
                } else {
                    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_D0(s3->vfunc_10(), 3);
                }
                break;
            }
        }
    }
}
