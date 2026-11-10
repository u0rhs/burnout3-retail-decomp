// NONMATCHING: func_002C0500 -- retail 295 / ours 295 instructions, 13 in changed runs
// 295/295 instrs, 13 in changed runs: ONLY the spill choice in the 4-chunk loop: retail keeps 'base' (ushort pkt->14) in fp and spills the pointer &pkt->field_10[i] (sq 0xA0(sp), lq later); ours keeps the pointer in fp and spills base. Tried decl order, int/ushort base, ptr outside loop, pkt->field_10[i] re-read, b0 local. Logic otherwise exact. Notes: 5 params (self, ushort, pid, pkt, chunks=t0); callee func_002365A0 declared bool + 'bool isf = f(); if (isf)' gives andi; GetPlayerByID returns int (direct ==0 test inline) but func_00236310/00236460 return void* (cold clear-flag blocks); 'int s2 = self->field_81C' before the if loads in the beq delay slot
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_C0500_pkt {
    unsigned char field_0;
    unsigned char pad_1[0xF];
    unsigned char field_10[4];
    unsigned short field_14;
};
struct UnkStruct_C0500_out {
    unsigned char field_0;
    unsigned char pad_1[2];
    unsigned char field_3;
    unsigned char pad_4[8];
    unsigned short field_C;
    unsigned char pad_E[2];
    unsigned char field_10[4];
    unsigned short field_14;
};
struct UnkStruct_C0500_mgr { unsigned char pad_0[0x28]; int field_28; };
struct UnkStruct_C0500 {
    unsigned char pad_0[0xC];
    unsigned char field_C[4][0x200];
    int field_80C[4];
    int field_81C;
    unsigned char pad_820[0xA];
    unsigned char field_82A[0x3C][0x200];
    unsigned char pad_802A[2];
    int field_802C[0x3C];
    int field_811C;
    int field_8120;
    unsigned char pad_8124[4];
    unsigned char field_8128[0x3C];
    int field_8164;
    unsigned char pad_8168[0x6C];
    int field_81D4;
    void * field_81D8;
};
extern "C" int GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);
extern "C" int GetMyPlayerID__23CGtNetworkPlayerManagerCFv(void *);
extern "C" int func_0022FBB0(void *);
extern "C" bool func_002365A0(void *, int, int);
extern "C" void * func_00236310(void *, int);
extern "C" void * func_00236460(void *, int);
extern "C" UnkStruct_C0500_out * func_0022F910(void *, int);
extern "C" void func_0022D850(void *);
extern "C" void * memcpy(void *, const void *, unsigned int);

// 0x002C0500
extern "C" void func_002C0500(UnkStruct_C0500 * self, unsigned short p1, int pid, UnkStruct_C0500_pkt * pkt, void ** chunks)
{
    unsigned short seq = p1;
    if ((pkt->field_0 & 1) == 1) {
    void * pl = (void *)GetPlayerByID__23CGtNetworkPlayerManagerCFi(self->field_81D8, pid);
    if (self->field_8164 == -1) self->field_8164 = pkt->field_14;
    int base = pkt->field_14;
    int i;
    for (i = 0; i < 4; i++) {
        unsigned char * src = pkt->field_10 + i;
        self->field_80C[i] = pkt->field_10[i];
        memcpy(self->field_C[i], chunks[i], self->field_80C[i]);
        int a = base + i;
        if (a >= self->field_8164 && a < self->field_8164 + 0x3C) {
            int idx = (self->field_811C + (a - self->field_8164)) % 0x3C;
            unsigned char * fl = &self->field_8128[idx];
            if (*fl == 0) {
                self->field_802C[idx] = *src;
                memcpy(self->field_82A[idx], chunks[i], self->field_802C[idx]);
                *fl = 1;
                self->field_8120 = self->field_8120 + 1;
            }
        }
    }
    if (((UnkStruct_C0500_mgr *)self->field_81D8)->field_28 < 4) { pkt->field_0 = pkt->field_0 & ~1; return; }
    if (GetPlayerByID__23CGtNetworkPlayerManagerCFi(self->field_81D8, pid) == 0) { pkt->field_0 = pkt->field_0 & ~1; return; }
    int my = GetMyPlayerID__23CGtNetworkPlayerManagerCFv(self->field_81D8);
    void * h;
    bool isf = func_002365A0(self->field_81D8, my, func_0022FBB0(pl));
    if (isf) {
        h = func_00236310(self->field_81D8, my);
        if (h == 0) { pkt->field_0 = pkt->field_0 & ~1; return; }
        if (self->field_81D4 == func_0022FBB0(h)) { pkt->field_0 = pkt->field_0 & ~1; return; }
    } else {
        h = func_00236460(self->field_81D8, my);
        if (h == 0) { pkt->field_0 = pkt->field_0 & ~1; return; }
        if (self->field_81D4 == func_0022FBB0(h)) { pkt->field_0 = pkt->field_0 & ~1; return; }
    }
    int hid = func_0022FBB0(h);
    unsigned short n = pkt->field_14;
    UnkStruct_C0500_out * o = func_0022F910((void *)GetPlayerByID__23CGtNetworkPlayerManagerCFi(self->field_81D8, hid), 2);
    int ptrs[4];
    int sizes[4];
    for (i = 0; i < 4; i++) ptrs[i] = (int)((char *)o + 0x20 + i * 0x42);
    int s2 = self->field_81C;
    if ((o->field_0 & 1) != 1) {
        for (i = 0; i < 4; i++) {
            sizes[i] = self->field_80C[s2];
            if (sizes[i] > 0x42) sizes[i] = 0x42;
            memcpy((void *)ptrs[i], self->field_C[s2], sizes[i]);
            s2 = (s2 + 1) % 4;
        }
        for (i = 0; i < 4; i++) o->field_10[i] = sizes[i];
        o->field_14 = n;
        if ((o->field_0 & 2) == 2) func_0022D850(o);
        o->field_3 = 2;
        o->field_C = seq;
        o->field_0 = o->field_0 | 1;
    }
    pkt->field_0 = pkt->field_0 & ~1;
    }
}


