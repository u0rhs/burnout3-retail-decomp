// NONMATCHING: UpdateSmallMessage__11CB3HUDScoreFf -- retail 1062 / ours 1058 instructions, 355 in changed runs
// fix2 (2026-11-01): the +0x1B0 virtual call: gm's vtable pointer sits at +0x1B0 and the call passes gm itself (the draft loaded field_1B0 as an object and called through its +0 vtable) [C] retail 0x1A31D8..0x1A31E4; miles factor 0.000621371f (0x3A22E380) -> 0x3A22E384 = 1/1609.344 as retail's .lit4 | Before: draftZ: 1059/1062, 358 changed; call order matches except 3 spots; left: two identical 0x8B4 branches merged by MWCC (retail keeps both), lap if/else and 0x890 block polarity, b3 kept in a register (retail spills it, frame 0x240 vs 0x250); top-tested loops come from continue-style bodies, (x == -5.0f) != 0 keeps the -5 block inline
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: every call, argument, constant (.lit4 0.01/FLT_MAX/0.0006213712/0.001/0.1/0.9), field offset and branch condition accounted for; sections: -5 sentinel min-speed init, checkpoint split messages (+OnEvent 0x8F/0x8D), lap message, low-boost toggle, D_01E90220 final-lap timer, field_124 idle hint, mode-2 car loop (distance flags, countdown 0x8B4, count), network ready/timer, priority chain -> func_001A22A0 + HUD sound


// CB3HUDScore::UpdateSmallMessage(float) -- hand-written (draftZ) from the retail asm; siblings: UpdateScoreObject
// (0x1A1CD0), UpdateMessageAnimation (0x1A2100), func_001A22A0 (message setup, called at the end).
// [C] name: the mangled symbol in retail's tables. Layout [G] from instruction widths; field names are placeholders.
#include "b3/GtMath.h"

struct UnkStruct_001A2700_bonus { unsigned char pad_0[0x4]; };
class CB3Score {
public:
    int GetRaceCheckpoint(int, int);
    float GetRaceCheckpointTime(int);
    float GetTotalRaceAmount();
    bool func_001A2700_inl2() { return !(field_104 < field_110); }

    short field_0;
    unsigned char pad_2[0xA];
    float field_C;
    unsigned char pad_10[0x4];
    int field_14;
    unsigned char pad_18[0x50];
    int field_68;
    unsigned char pad_6C[0x8];
    int field_74;
    unsigned char pad_78[0x8];
    int * field_80;
    unsigned char pad_84[0x80];
    float field_104;
    unsigned char pad_108[0x8];
    float field_110;
    unsigned char pad_114[0xA];
    unsigned char field_11E;
    unsigned char pad_11F[0x5];
    UnkStruct_001A2700_bonus field_124;
    unsigned char pad_128[0x1A4];
    float field_2CC;
    unsigned char pad_2D0[0xC];
    int field_2DC;
    unsigned char pad_2E0[0x220];
    float field_500;
    unsigned char pad_504[0xF0];
    float field_5F4;
};
struct UnkStruct_001A2700_car {
    unsigned char pad_0[0x1160];
    unsigned char field_1160;
    unsigned char pad_1161[0x16C8 - 0x1161];
    int field_16C8;
};
struct UnkStruct_001A2700_p {
    unsigned char pad_0[0x1160];
    unsigned char field_1160;
    unsigned char pad_1161[0x1894 - 0x1161];
    float field_1894[10];
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x1C];
    float field_1C;
    unsigned char pad_20[0x12AD1C - 0x20];
    int field_12AD1C;
    unsigned char pad_12AD20[0x8];
    UnkStruct_001A2700_car * field_12AD28[10];
    UnkStruct_001A2700_p field_12AD50;
};
struct UnkStruct_001A2700_vm1 {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual int vfunc_20();
};
struct UnkStruct_001A2700_vm2 {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34();
    virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44();
    virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64();
    virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74();
    virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84();
    virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94();
    virtual void vfunc_98(); virtual int vfunc_9C();
};
struct UnkStruct_001A2700_gm {
    unsigned char pad_0[0x1B0];
    // [C] the vtable pointer sits at +0x1B0 (MWCC places it where the first virtual is declared): retail 0x1A31D8..0x1A31E4
    // calls *(*(gm + 0x1B0) + 0x20) with a0 = gm itself (fix2; the draft called through field_1B0 as an object pointer)
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual int vfunc_20();
    UnkStruct_001A2700_vm2 * field_1B4;
};
struct UnkStruct_001A2700_np {
    unsigned char pad_0[0x4EFC];
    unsigned char field_4EFC;
    bool func_001A2700_inl3() { return field_4EFC != 0; }
};
struct UnkStruct_001A2700_obj { unsigned char pad_0[0x10]; };

class CB3HUDScore {
public:
    class CScoreMessage {
    public:
        unsigned char pad_0[0x88];
        float field_88;
    };
    void UpdateSmallMessage(float p0);
    bool func_001A2700_inl1(CScoreMessage * m, const float & t)
    {
        bool b = m->field_88 < t;
        if (b) b = field_CC->field_C < t + 5.0f;
        return b;
    }

    unsigned char pad_0[0x2C];
    CScoreMessage field_2C;
    unsigned char pad_B8[0x14];
    CB3Score * field_CC;
    unsigned char pad_D0[0x4];
    int field_D4;
    int field_D8;
    unsigned char pad_DC[0x38];
    float field_114;
    float field_118;
    unsigned char pad_11C[0x3];
    unsigned char field_11F;
    unsigned char field_120;
    unsigned char field_121;
    unsigned char pad_122[0x2];
    float field_124;
    unsigned char pad_128[0x8];
    float field_130;
    int field_134;
    unsigned char pad_138[0x8];
    unsigned char field_140;
    unsigned char field_141;
};

extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_D_0051BA88 {
    UnkStruct_001A2700_gm * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
struct UnkStruct_D_01E32B08 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E65499 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E90220 { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_0051BA88 D_0051BA88;
struct UnkStruct_D_0051B258 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0051B258 D_0051B258;
extern UnkStruct_D_0051B258 D_0051B5B8;
extern UnkStruct_001A2700_obj D_0051BA44;
extern UnkStruct_001A2700_obj D_004EE040;
extern UnkStruct_001A2700_obj D_01E32AE0;
extern UnkStruct_001A2700_obj D_01E7A800;
extern unsigned int D_004E2918;
extern UnkStruct_D_01E90220 D_01E90220;
extern UnkStruct_D_01E65499 D_01E65499;
extern UnkStruct_D_01E32B08 D_01E32B08;
extern int D_004B77D0[4];
extern int D_004B77E0[4];

extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, const unsigned short *);
extern "C" void *func_001A3AA0(unsigned short *, const unsigned short *, int *);
extern "C" void func_001A39E0(unsigned short *, const unsigned short *, int *, const unsigned short **);
extern "C" int func_00131CA0(void *);
extern "C" int func_00150D00(UnkStruct_001A2700_car *);
extern "C" float func_0015A7F0(CB3Score *);
extern "C" UnkStruct_001A2700_np * func_002366D0(void *, int);
extern "C" unsigned char func_003904D0(UnkStruct_001A2700_vm2 *);
extern "C" void func_00284AE0(void *);
extern "C" void func_00285C00(void *, int, int, int);
extern "C" int OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(void *, int, int, int, bool);
extern "C" void func_001A22A0(CB3HUDScore *, CB3HUDScore::CScoreMessage *, int, const unsigned short *, bool, float);

static inline bool func_001A2700_inl0()
{
    return D_0051BA88.field_0 != 0 && D_0051BA88.field_0->field_1B4 == (void *)&D_0051B258;
}
static inline int func_001A2700_max(int a, int b)
{
    int r;
    asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline unsigned int func_001A2700_zx(int a)
{
    unsigned int r;
    asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a));
    return r;
}

// 0x001A2700
void CB3HUDScore::UpdateSmallMessage(float p0)
{
    int type = 1;
    const unsigned short * text = 0;
    bool flag = false;
    CScoreMessage * msg = &field_2C;
    unsigned short buf[64];
    if (field_CC->field_C < 0.01f)
        return;
    bool b3 = false;
    bool b8 = false;
    bool b7 = false;
    bool b9 = false;
    bool b1 = false;
    bool b10 = false;
    bool b11 = false;
    bool b12 = false;
    bool b5 = false;
    bool b6 = false;
    bool two = false;
    const unsigned short * text9;
    if (func_001A2700_inl0() && D_00522660.field_12AD1C == 2)
        two = true;
    bool show = true;
    if ((field_130 == -5.0f) != 0) {
        float m = 3.4028235e+38f;
        for (int i = 0;; i++) {
            if (!(i < D_00522660.field_12AD1C)) break;
            UnkStruct_001A2700_car * car = D_00522660.field_12AD28[i];
            if (!car->field_1160) {
                float v = func_0015A7F0((CB3Score *)((char *)car + 0x10C0));
                if (D_004E2918 >= 2)
                    v *= 0.001f;
                else
                    v *= 0.0006213712f;   // [C] retail .lit4 0x3A22E384 (1 / 1609.344)
                if (v < m) m = v;
            }
        }
        field_130 = GtMath::Min((float)(int)m, 5.0f);
    }
    if (field_CC->field_14 >= 0) {
        int cp = field_CC->GetRaceCheckpoint(field_CC->field_14, field_CC->field_2DC);
        if (field_D8 < cp) {
            int prev = cp - 1;
            float my = field_CC->GetRaceCheckpointTime(prev);
            if (field_CC->field_0 > 1) {
                float best = -1.0f;
                for (int i = 0; i < D_00522660.field_12AD1C; i++) {
                    CB3Score * o = (CB3Score *)((char *)D_00522660.field_12AD28[i] + 0x10C0);
                    if (field_CC != o) {
                        float t = o->GetRaceCheckpointTime(prev);
                        if (best < t) best = t;
                    }
                }
                if (best > 0.0f && my >= best) {
                    float d = my - best;
                    if (d < 2.0f) {
                        if (d >= 1.0f) {
                            CopyN__10CGtUnicodeFPUsiPCUs(buf, 0x40, func_00271A00(&D_0051BA44, 0x891));
                            b3 = true;
                        }
                    } else {
                        int secs = (int)d;
                        func_001A3AA0(buf, func_00271A00(&D_0051BA44, 0x88F), &secs);
                        b3 = true;
                        if (two && secs > 3)
                            OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(&field_CC->field_124, 0x8F, 0, -1, 0);
                    }
                }
                field_D8 = cp;
            } else {
                float best = 3.4028235e+38f;
                for (int i = 0; i < D_00522660.field_12AD1C; i++) {
                    CB3Score * o = (CB3Score *)((char *)D_00522660.field_12AD28[i] + 0x10C0);
                    if (field_CC != o) {
                        float t = o->GetRaceCheckpointTime(prev);
                        if (t > 0.0f && best > t) best = t;
                    }
                }
                if (best < 3.4028235e+38f) {
                    if (my < best) {
                        float d = best - my;
                        if (d < 2.0f) {
                            if (d >= 1.0f) {
                                CopyN__10CGtUnicodeFPUsiPCUs(buf, 0x40, func_00271A00(&D_0051BA44, 0x890));
                                b3 = true;
                            }
                            if (two)
                                OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(&field_CC->field_124, 0x8D, 0, -1, 0);
                        } else {
                            int secs = (int)d;
                            func_001A3AA0(buf, func_00271A00(&D_0051BA44, 0x88E), &secs);
                            b3 = true;
                            if (two && secs < 6 && field_CC->GetTotalRaceAmount() > 0.0f)
                                OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(&field_CC->field_124, 0x8D, 0, -1, 0);
                        }
                    }
                    field_D8 = cp;
                }
            }
        }
    }
    if (field_CC->field_80 != 0 && field_CC->field_68 != field_D4 && field_CC->field_C > field_CC->field_500 + 4.0f) {
        field_D4 = field_CC->field_68;
        int n = 4;
        int lap = field_CC->field_74;
        if (lap == 4)
            n = 0;
        else if (lap != 2)
            n = lap + 1;
        if (n != 4 && lap != 2) {
            if (field_D4 == field_CC->field_80[n] - 1) {
                CopyN__10CGtUnicodeFPUsiPCUs(buf, 0x40, func_00271A00(&D_0051BA44, D_004B77D0[n]));
            } else {
                func_001A3AA0(buf, func_00271A00(&D_0051BA44, D_004B77E0[n]), &field_CC->field_80[n]);
            }
            type = 12;
            b8 = true;
        }
    }
    if (!func_00131CA0(&D_004EE040) || D_0051BA88.field_0->field_1B4 == (void *)&D_0051B5B8) {
        bool b = field_CC->field_5F4 < 0.1f;
        if (b != field_11F) {
            if (b)
                b7 = true;
            else
                field_11F = 0;
        }
    }
    if (D_0051BA88.field_0->field_1B4 == (void *)&D_0051B5B8 && field_CC->field_68 == D_01E90220.field_0 - 1) {
        if (field_114 == 0.0f) {
            field_114 = 4.0f;
        } else {
            field_114 -= D_00522660.field_1C;
            if (field_114 <= 0.0f) {
                b8 = true;
                CopyN__10CGtUnicodeFPUsiPCUs(buf, 0x40, func_00271A00(&D_0051BA44, 0x31E));
                field_114 = -1.0f;
            }
        }
    }
    if (field_121 && !field_120) {
        if (field_CC->func_001A2700_inl2() && !field_CC->field_11E) {
            field_124 -= D_00522660.field_1C;
            if (field_124 <= 0.0f) {
                text9 = func_00271A00(&D_0051BA44, 0xA4);
                b9 = true;
                field_124 = 30.0f;
                field_120 = 1;
            }
        } else {
            field_124 = 5.0f;
        }
    }
    if (D_0051BA88.field_0->field_1B4->vfunc_9C() == 2) {
        UnkStruct_001A2700_p * p = &D_00522660.field_12AD50;
        bool x = p->field_1160 != 0;
        bool y = x;
        int count = 0;
        for (int i = 0;; i++) {
            if (!(i < D_00522660.field_12AD1C)) break;
            UnkStruct_001A2700_car * car = D_00522660.field_12AD28[i];
            if (!car->field_1160 && p->field_1894[i] > -300.0f)
                x = false;
            if (!car->field_1160 && p->field_1894[i] < 500.0f)
                y = false;
            if (!car->field_1160 && !func_00150D00(car)) {
                float v = func_0015A7F0((CB3Score *)((char *)car + 0x10C0));
                int off;
                const unsigned short * unit;
                if (D_004E2918 >= 2) {
                    off = 0x2DA04;
                    v *= 0.001f;
                    unit = func_00271A00(&D_0051BA44, 0x7EE);
                } else {
                    off = 0x2DA04;
                    v *= 0.0006213712f;   // [C] retail .lit4 0x3A22E384 (1 / 1609.344)
                    unit = func_00271A00(&D_0051BA44, 0x7EF);
                }
                if (field_130 > 0.0f && v < field_130) {
                    int secs = (int)field_130;
                    b11 = true;
                    if (secs == 1) {
                        func_001A39E0(buf, func_00271A00((char *)&D_004EE040 + off, 0x8B4), &secs, &unit);
                    } else {
                        func_001A39E0(buf, func_00271A00((char *)&D_004EE040 + off, 0x8B4), &secs, &unit);
                    }
                    field_130 -= 1.0f;
                }
            }
            if (!car->field_1160 && !func_00150D00(car) && car->field_16C8 == 0)
                count++;
        }
        if (x) b1 = true;
        if (y) b10 = true;
        if (field_134 != 1 && count == 1)
            b12 = true;
        field_134 = count;
    }
    if (D_01E65499.field_0) {
        b5 = true;
        int n = D_01E32B08.field_0;
        for (int i = 0; i < n; i++) {
            UnkStruct_001A2700_np * np = func_002366D0(&D_01E32AE0, i);
            if (np && !np->func_001A2700_inl3()) {
                b5 = false;
                break;
            }
        }
        if (func_003904D0(D_0051BA88.field_0->field_1B4)) {
            b6 = true;
            field_118 -= p0;
        } else {
            b6 = false;
            field_118 = 20.0f;
        }
    }
    int cur = D_0051BA88.field_0->vfunc_20();
    if (b5) {
        text = func_00271A00(&D_0051BA44, 0xC59);
        type = 0x18;
        show = false;
        flag = true;
    } else if (b6) {
        const unsigned short * fmt = func_00271A00(&D_0051BA44, 0xC57);
        int secs = func_001A2700_zx(func_001A2700_max((int)(field_118 + 0.9f), 0));
        func_001A3AA0(buf, fmt, &secs);
        text = buf;
        type = 0x18;
        flag = true;
        show = false;
    } else if (b7 && func_001A2700_inl1(msg, field_CC->field_C)) {
        field_11F = 1;
        text = func_00271A00(&D_0051BA44, 0x8A1);
        func_00284AE0(&D_01E7A800);
        type = 9;
    } else if (field_140 && field_CC->field_14 + 1 == cur && func_001A2700_inl1(msg, field_CC->field_2CC)) {
        text = func_00271A00(&D_0051BA44, 0x806);
        show = true;
    } else if (field_141 && b3 && func_001A2700_inl1(msg, field_CC->field_C)) {
        text = buf;
        show = true;
    } else if (b8 && func_001A2700_inl1(msg, field_CC->field_C)) {
        text = buf;
    } else if (b9 && func_001A2700_inl1(msg, field_CC->field_C)) {
        text = text9;
        show = false;
    } else if (b1 && func_001A2700_inl1(msg, field_CC->field_C)) {
        text = func_00271A00(&D_0051BA44, 0x8B2);
    } else if (b10 && func_001A2700_inl1(msg, field_CC->field_C)) {
        text = func_00271A00(&D_0051BA44, 0x8B3);
    } else if (b11 && func_001A2700_inl1(msg, field_CC->field_C)) {
        text = buf;
    } else if (b12 && func_001A2700_inl1(msg, field_CC->field_C)) {
        text = func_00271A00(&D_0051BA44, 0x8B5);
    }
    func_001A22A0(this, msg, type, text, flag, p0);
    if (text && show)
        func_00285C00(&D_01E7A800, type, 0, 0);
}
