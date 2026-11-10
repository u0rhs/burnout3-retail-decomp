// NONMATCHING: DynamisePropBody__17CB3PhysicsManagerFP13CB3ActiveBody -- retail 181 / ours 181 instructions, 25 in changed runs
// draftAO (2026-11-01): parameter typed CB3ActiveBody (the placeholder mangled to a different symbol: archive scored 0); slot array as member field_C3900[16] (0x780 stride), bitmask field_E9220; 181/181, calls identical, only the slot-header schedule (9 instrs) differs | Before: logic recovered, 177 vs 181 instrs: s1/s2 (pe vs best) swap, body-search loop pointer regs (a3/a2/a0 element/state/field ptrs), slot-base fold; callee func_001BE3C0 a1 in path1 = &D_00522660+0x128210+ret*4 element ptr [G]
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm (0x1B4530..0x1B4800): every call, branch and store checked; returns 1 on both paths


struct UnkStruct_001B4530_pe {
    unsigned short field_0;
    unsigned char field_2;
    unsigned char field_3;
};
class UnkStruct_001B4530_slot {
public:
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0x20C];
    unsigned char field_210;
    unsigned char pad_211[0xF];
    void * field_220;
    float field_224;
    unsigned char pad_228[0x558];
};
class CB3ActiveBody {
public:
    unsigned char field_0;
    unsigned char pad_1;
    unsigned char field_2;
    unsigned char pad_3;
    int field_4;
    int field_8;
    UnkStruct_001B4530_pe * field_C;
};
struct UnkStruct_001B4530_e {
    unsigned char pad_0[0x70];
    signed char field_70;
    unsigned char field_71;
    unsigned char pad_72[0xA];
    void * field_7C;
};
struct UnkStruct_D_0064A854 {
    unsigned char pad_0[0x10];
};
extern UnkStruct_D_0064A854 D_0064A854;
extern UnkStruct_001B4530_pe D_0064A870[];
extern unsigned char D_0064A872[];
extern unsigned char D_0064A873[];
extern unsigned char D_00522660[];
extern "C" int KillProp__14CB3PropManagerFP7CB3Propb(void *, void *, bool);
extern "C" void * DynamiseProp__14CB3PropManagerFP7CB3Prop(void *, void *);
extern "C" bool func_001BE3C0(void *, void *, void *, void *);

struct UnkStruct_001B4530_e2 {
    signed char field_0;
    unsigned char field_1;
    unsigned char pad_2[0xA];
    void * field_C;
    unsigned char pad_10[0x20];
};
class CB3PhysicsManager {
public:
    int DynamisePropBody(CB3ActiveBody * p0);   // returns 1 on both paths [C] 0x1B4770
    unsigned char pad_0[0x70];
    UnkStruct_001B4530_e2 field_70[1];
    unsigned char pad_A0[0x1CB70 - 0xA0];
    int field_1CB70;
    unsigned char pad_1CB74[0xC3900 - 0x1CB74];
    UnkStruct_001B4530_slot field_C3900[16];
    unsigned char pad_CB100[0xE9220 - 0xCB100];
    unsigned long long field_E9220;
};

// 0x001B4530
int CB3PhysicsManager::DynamisePropBody(CB3ActiveBody * p0)
{
    int best;
    UnkStruct_001B4530_pe * pe = p0->field_C;
    unsigned long long bit = 1;
    int i;
    for (i = 0; i < 16; i++) {
        if ((field_E9220 & bit) == 0) break;
        bit <<= 1;
    }
    if (i == 16) {
        p0->field_0 = 6;
        best = 0;
        float bd = 999999;              // retail: li 0xF423F; cvt.s.w (int literal converted) [C] 0x1B45AC
        for (int k = 0; k < 16; k++) {
            if (field_C3900[k].field_220 != 0 && field_C3900[k].field_210 == 0 && field_C3900[k].field_224 < bd) {
                bd = field_C3900[k].field_224;
                best = k;
            }
        }
        UnkStruct_001B4530_slot * sl;
        int off = best * 0x780;
        char * sb = (char *)this + off;
        int n = field_1CB70;
        sl = (UnkStruct_001B4530_slot *)(sb + 0xC3900);
        for (int j = 0; j < n; j++) {
            UnkStruct_001B4530_e * e = (UnkStruct_001B4530_e *)((char *)this + j * 0x30);
            signed char * st = &e->field_70;
            if (*st == 6) {
                void ** pp = &e->field_7C;
                if (e->field_7C == sl) {
                    e->field_71 = 1;
                    *st = 8;
                    *pp = 0;
                    break;
                }
            }
        }
        int r = KillProp__14CB3PropManagerFP7CB3Propb(&D_0064A854, field_C3900[best].field_220, true);
        sl = (UnkStruct_001B4530_slot *)(sb + 0xC3900);
        sl->vfunc_C();
        D_0064A870[r].field_0 = pe->field_0;
        D_0064A872[r * 4] = pe->field_2;
        D_0064A873[r * 4] = pe->field_3;
        pe->field_3 = 2;
        UnkStruct_001B4530_pe * q = (UnkStruct_001B4530_pe *)(D_00522660 + r * 4 + 0x128210);
        q->field_3 = 1;
        func_001BE3C0(sl, q, (void *)(p0->field_4), (void *)(p0->field_8));
        p0->field_C = (UnkStruct_001B4530_pe *)sl;
        p0->field_2 = best;
    } else {
        p0->field_0 = 6;
        p0->field_2 = i;
        field_E9220 |= bit;
        void * r = DynamiseProp__14CB3PropManagerFP7CB3Prop(&D_0064A854, pe);
        UnkStruct_001B4530_slot * sl = &field_C3900[i];
        func_001BE3C0(sl, r, (void *)(p0->field_4), (void *)(p0->field_8));
        p0->field_C = (UnkStruct_001B4530_pe *)sl;
    }
    return 1;
}


