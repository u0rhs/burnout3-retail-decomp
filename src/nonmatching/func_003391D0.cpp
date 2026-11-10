// NONMATCHING: ForAllPlayersInLobby__20CGtLobbyPS2DirtySockFiiPFPcibiiiPcbPv_bPv -- retail 60 / ours 60 instructions, 7 in changed runs
// s321: 60/60, 7 off = s0/s1 swap only (retail n=min(count,p1+1) in s1, DispListIndex result in s0 = p1's home; ours reversed). Tried sreg run (60 variants), decl order/top decls, split min locals, loop-var forms, pminw operand order, unsigned n
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// ForAllPlayersInLobby__20CGtLobbyPS2DirtySockFiiPFPcibiiiPcbPv_bPv -- hand-matched (s321) after the proven sibling
// GetPlayerInLobby (0x3393C0). Unnamed callee func_0040A5D0 = list count [G]. Types [G] (instruction widths).

struct UnkStruct_003391D0;
struct UnkStruct_003391D0_1;
struct UnkStruct_D_004C5968;

struct UnkStruct_003391D0_1 {
    int field_0;
    unsigned char pad_4[0x4];
    char field_8[16];  // [G] length unknown
};

struct UnkStruct_D_004C5968 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003391D0 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    unsigned char pad_4[0x118];
    unsigned char field_11C;
    unsigned char pad_11D[0x387];
    char field_4A4[16];  // [G] length unknown
    unsigned char pad_4B4[0xB8];
    int field_56C;
};

extern UnkStruct_D_004C5968 D_004C5968;

extern "C" void DispListOrder(int);
extern "C" int func_0040A5D0(int);
extern "C" UnkStruct_003391D0_1 * DispListIndex(int, int);
extern "C" int strcasecmp(const char *, const char *);

static inline int func_003391D0_inl1(int a, int b) { int r; asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline int func_003391D0_inl2(int a) { int r; asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a)); return r; }

// 0x003391D0
extern "C" void ForAllPlayersInLobby__20CGtLobbyPS2DirtySockFiiPFPcibiiiPcbPv_bPv(UnkStruct_003391D0 * self, int p0, int p1, int (*p2)(char *, int, int, int, int, int, char *, int, void *), void * p3)
{
    if (self->field_11C == 0) {
        DispListOrder(self->field_56C);
        int n = func_003391D0_inl2(func_003391D0_inl1(func_0040A5D0(self->field_56C), p1 + 1));
        for (int i = p0; i < n; i++) {
            UnkStruct_003391D0_1 * r1 = DispListIndex(self->field_56C, i);
            int r2 = strcasecmp(self->field_4A4, r1->field_8);
            p2(r1->field_8, r1->field_0, ((r2 != 0) ^ 1), 0, 0, 0, (char *)&D_004C5968, i == n, p3);
        }
    }
    self->vfunc_14();
}
