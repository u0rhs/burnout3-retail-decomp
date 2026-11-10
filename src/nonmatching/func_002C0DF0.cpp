// NONMATCHING: func_002C0DF0 -- retail 302 / ours 302 instructions, 32 in changed runs
// near31: 32 off, 302/302: sibling func_002C16A0's goto doit/skip form for (field_8==2||field_8==1) and int stores '*(int *)&field_8178 = 0' (retail sw zero); the post-loop flag as bool (no andi). Left: slot loop -- retail computes &field_81DC[s] (ori 0x81DC) into s0 and tests lw 0(s0) (a *slot test caches/reloads wrongly: 86 off), s1/s2/s3 rotation of the loop index/d/j
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_002C0DF0 -- retail 302 / ours 303 instructions, 44 in changed runs
// 302/303 instrs, 44 in changed runs. Logic complete (slot loop over field_81DC[5] with field_81F0[5] targets, found flag s6, d = modular dist16 / (ushort)(int)f, post-loop player list 81B0[] + func_002C12B0 x2, common timer tail). Left: (1) register pressure/allocation: retail keeps np in fp and spills &self->81D8 (sq 0xB0), p1 raw in s4 + (ushort)p1 in s7, slot ptr s0, *slot NOT cached across calls (reloaded 'lw a2,0(s0)'); ours caches *slot in a saved reg when tests use the pointer (tests via self->field_81DC[s] fixes the caching but loses 'lw a1,0(s0)'). (2) retail stores zero to floats 8178/8184 with 'sw zero' (int stores), ours swc1; (3) '(v==2||v==1)' merges to addiu/sltiu in ours, retail beq 2 / bne 1; (4) post-loop flag is bool: 'andi s2,a3,255' first, 'daddiu s2,zero,1' second
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

enum EHeadsetTalkControlStatus_C0DF0 { eHeadsetTalkControlStatus_C0DF0_dummy };
struct UnkStruct_C0DF0_mgr { unsigned char pad_0[0x28]; int field_28; };
struct UnkStruct_C0DF0_pl { unsigned char pad_0[0x4B0]; unsigned char field_4B0; };
struct UnkStruct_C0DF0 {
    unsigned char field_0;
    unsigned char pad_1[7];
    int field_8;
    unsigned char pad_C[0x829 - 0xC];
    unsigned char field_829;
    unsigned char pad_82A[0x8168 - 0x82A];
    unsigned short field_8168;
    unsigned char pad_816A[0x8178 - 0x816A];
    float field_8178;
    unsigned char pad_817C[4];
    float field_8180;
    float field_8184;
    unsigned char pad_8188[0x81B0 - 0x8188];
    int field_81B0[8];
    int field_81D0;
    int field_81D4;
    UnkStruct_C0DF0_mgr * field_81D8;
    int field_81DC[5];
    int field_81F0[5];
};
extern "C" UnkStruct_C0DF0_pl * func_002366D0(void *, int);
extern "C" int GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);
extern "C" int func_0022FBB0(void *);
extern "C" int func_0022F910(void *, int);
extern "C" void func_002C1FC0(void *, int, int, int);
extern "C" void func_002C1560(void *, int *, int *);
extern "C" void func_002C13F0(void *);
extern "C" void func_002C12B0(void *, int *, int, int, int, int);
extern "C" void func_002BFB00(void *);
extern "C" void SetStatusToSend__17CGtNetworkHeadsetF25EHeadsetTalkControlStatusi(void *, int, int);

static inline unsigned short func_C0DF0_dist(unsigned short a, unsigned short b)
{
    if (a < 0x5555 && b > 0xAAAA) return a + (0xFFFF - b);
    return a - b;
}

// 0x002C0DF0
extern "C" void func_002C0DF0(UnkStruct_C0DF0 * self, int p1, float dt)
{
    int cnt;
    int list[11];
    bool found = false;
    bool ran = false;
    int s = 0;
    int np = self->field_81D8->field_28;
    while (s < 5 && !found) {
        int * slot = &self->field_81DC[s];
        if (self->field_81DC[s] != 0) {
            found = true;
            int d;
            if (self->field_81DC[s] == 4) d = func_C0DF0_dist((unsigned short)p1, self->field_8168);
            else if (self->field_81DC[s] == 6) d = (unsigned short)(int)self->field_8178;
            else d = 0;
            if (self->field_81F0[s] == -1) {
                int j;
                for (j = 0; j < np; j++) {
                    UnkStruct_C0DF0_pl * p = func_002366D0(self->field_81D8, j);
                    if (p != 0 && p->field_4B0 != 0) func_002C1FC0((void *)(func_0022F910(p, 3)), p1, *slot, d);
                }
                *slot = 0;
            } else {
                func_002C1FC0((void *)(func_0022F910((void *)GetPlayerByID__23CGtNetworkPlayerManagerCFi(self->field_81D8, self->field_81F0[s]), 3)), p1, *slot, d);
                *slot = 0;
            }
        }
        s++;
    }
    if (!found) {
        func_002C1560(self, list, &cnt);
        ran = false;
        if (self->field_8 == 1) func_002C13F0(self);
        self->field_81D0 = 0;
        int n2 = self->field_81D8->field_28;
        int k;
        for (k = 0; k < n2; k++) {
            UnkStruct_C0DF0_pl * p = func_002366D0(self->field_81D8, k);
            if (p != 0) {
                self->field_81B0[self->field_81D0] = func_0022FBB0(p);
                self->field_81D0 = self->field_81D0 + 1;
            }
        }
        if (self->field_8 == 1 && cnt > 0) {
            ran = true;
            func_002C12B0(self, list, cnt, 1, p1, 0);
        }
        if (self->field_8 == 2 && cnt > 0) {
            ran = true;
            func_002C12B0(self, list, cnt, 6, p1, (unsigned short)(int)self->field_8178);
        }
        if (!ran) func_002BFB00(self);
    }
    if (self->field_8178 <= 0.0f) {
        if (self->field_8 == 2) {
            self->field_0 = 1;
            if (self->field_8 == 2) goto doit;
            if (self->field_8 != 1) goto skip;
        doit:
            self->field_81D4 = -1;
            *(int *)&self->field_8178 = 0;
            self->field_8 = 0;
            *(int *)&self->field_8184 = 0;
            self->field_8180 = 1.0f;
            SetStatusToSend__17CGtNetworkHeadsetF25EHeadsetTalkControlStatusi(self, 4, -1);
        skip:;
        }
        self->field_8178 = 0.0f;
    } else {
        if (self->field_8 == 2 || self->field_829 != 0) self->field_8178 = self->field_8178 - dt;
    }
    if (self->field_8180 > 0.0f) {
        self->field_8180 = self->field_8180 - dt;
        if (self->field_8180 <= 0.0f) {
            self->field_8180 = 0.0f;
            self->field_0 = 0;
        }
    }
    self->field_8184 = self->field_8184 + dt;
}


