// NONMATCHING: func_003F7750 -- retail 225 / ours 225 instructions, 12 in changed runs
// near16: final field_10 switch as default:return / case 1 / case 0 gives 225/225 (was 227). Left: retail bne a0,1 -> epilogue with case-1 call falling into the jtbl break block (ours beq + b;ld ra); case-5 field_10 in t1 vs t0. If-chains / goto / all case orders tried
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// NONMATCHING: func_003F7750 -- retail 225 / ours 227 instructions, 11 in changed runs
// a83: 227/225 instrs, 11 changed. case 2 as an inline 'ReleaseIfOpen() { if(!x) return false; Release(); return true; }' gives retail's inline Release + beqz->shared return (was the layout blocker). Left: field_10 reload in t0 vs t1, and the final field_10 dispatch (retail: beqz big; bne->shared ld-ra return; jal func_003F7550 falls into the exit block, big block after it; ours: beq call; b ret) - tried switch/if-else forms
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// func_003F7750 -- CB3OnlineEndOfRaceState::Action(EGtStateAction,void*,void*,void*) [L] DNAT (research/proto/new_names.csv, medium)
enum EGtStateAction {};
struct UnkStruct_Menu;
struct UnkStruct_Game {
    unsigned char pad_0[0x1B4];
    UnkStruct_Menu * field_1B4;
};
struct UnkStruct_Menu {
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
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual int vfunc_9C();
    virtual int vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual void vfunc_D8();
    virtual void vfunc_DC();
    virtual void vfunc_E0();
    virtual void vfunc_E4();
    unsigned char pad_E8[0x73 - 0x4];
    unsigned char field_73;
};

struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_F { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051BA88 { UnkStruct_Game * field_0; unsigned char pad_4[0xC]; };
class CB3OnlineEndOfRaceState {
public:
    unsigned char pad_0[0x10];
    int field_10;
    float field_14;
    unsigned char field_18[8];
    unsigned char field_20;
};
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_I D_01E90430;
extern UnkStruct_F D_004F509C;
extern UnkStruct_P D_01E32AE0;
extern UnkStruct_P D_01E90240;
extern UnkStruct_P D_01E95968;
extern "C" void SetPlayerRecordsNotAdded__17CB3NetworkManagerFv(void *);
extern "C" void ReleaseCurrentMenu__18CB3MenuPageManagerFv(void *);
extern "C" void func_003F7350(void *);
extern "C" void func_003F7150(void *);
extern "C" void func_003F7550(void *);
extern "C" void func_003F6EB0(void *, EGtStateAction, void *, int);
extern "C" void func_003F68E0(void *, EGtStateAction, void *, int);
extern "C" unsigned long func_003F65D0(void *, void *);
extern "C" unsigned long func_003F66F0(void *, void *);
extern "C" void func_003C5B80(void *, unsigned long);
extern "C" int func_0026C8C0(void *);
extern "C" void func_003F8040(void *, void *, int);

static inline bool ReleaseIfOpen()
{
    if (D_01E90430.field_0 == 0) {
        return false;
    }
    ReleaseCurrentMenu__18CB3MenuPageManagerFv(&D_01E90240);
    return true;
}

// [L] DNAT: CB3OnlineEndOfRaceState::Action(EGtStateAction,void*,void*,void*) (research/proto/new_names.csv, medium)
// 0x003F7750
extern "C" void func_003F7750(CB3OnlineEndOfRaceState * self, EGtStateAction p0, void * p1, int p2)
{
    switch (p0) {
    case 3:
        {
            int i = 0;
            do {
                self->field_18[i] = 0;
                i++;
            } while (i < 8);
        }
        SetPlayerRecordsNotAdded__17CB3NetworkManagerFv(&D_01E32AE0);
        if (D_01E90430.field_0 != 0) {
            ReleaseCurrentMenu__18CB3MenuPageManagerFv(&D_01E90240);
        }
        self->field_14 = 0;
        self->field_20 = 0;
        func_003F7350(self);
        break;
    case 2:
        ReleaseIfOpen();
        break;
    case 5:
        {
            int t1 = self->field_10;
            switch (t1) {
            case 0:
                func_003F6EB0(self, p0, p1, p2);
                break;
            case 1:
                func_003F68E0(self, p0, p1, p2);
                break;
            case 2:
            case 3:
                switch (p2) {
                case 1:
                case 2:
                case 0:
                {
                    if (t1 == 2) {
                        func_003F7350(self);
                    } else {
                        func_003F7150(self);
                    }
                }
                }
                break;
            }
        }
        break;
    case 4:
        {
            self->field_14 = self->field_14 + D_004F509C.field_0;
            UnkStruct_Menu * m = D_0051BA88.field_0->field_1B4;
            if (m->vfunc_9C() == 3) {
                switch (self->field_10) {
                case 0:
                case 2:
                    if (self->field_14 > 60.0f) {
                        if (D_01E90430.field_0 != 0) {
                            ReleaseCurrentMenu__18CB3MenuPageManagerFv(&D_01E90240);
                        }
                        m->vfunc_E0();
                        func_003F7150(self);
                    }
                    break;
                case 1:
                case 3:
                    if (self->field_14 > 120.0f) {
                        m->vfunc_E4();
                    }
                    break;
                }
            }
            switch (self->field_10) {
            default:
                return;
            case 1:
                func_003F7550(self);
                break;
            case 0:
                {
                UnkStruct_Menu * m2 = D_0051BA88.field_0->field_1B4;
                switch (m2->vfunc_9C()) {
                case 3:
                    func_003C5B80(&D_01E95968, func_003F65D0(self, m2));
                    break;
                case 4:
                    func_003C5B80(&D_01E95968, func_003F66F0(self, m2));
                    if (func_0026C8C0(&D_01E32AE0) == 0 || D_0051BA88.field_0->field_1B4->field_73 == 0) {
                        return;
                    }
                    func_003F8040(self, &D_01E95968, m2->vfunc_A0());
                    break;
                case 0:
                case 1:
                case 2:
                case 5:
                    break;
                default:
                    return;
                }
                }
                break;
            }
        }
        break;
    }
}

