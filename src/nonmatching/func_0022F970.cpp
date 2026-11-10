// NONMATCHING: func_0022F970 -- retail 144 / ours 142 instructions, 14 in changed runs
// 14 instrs: logic/layout right (lifter refused it; hand-written). Left: retail materialises bool a with andi a1,a0,0xFF at its definition (keeping p0->field_0 in a2 for the later ==2 test) and andi's b in the beqz delay slot; every bool/uchar/int/inline form tried either drops the andi or if-converts to sltiu.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_0022F970 -- hand-written from the retail asm (the lifter refused it).
// Unnamed in every table, so a placeholder with C linkage; file and Area unknown, so _unclassified/.
// Structs are declared with only the fields touched; every type is [G] (instruction widths).

struct UnkStruct_0022F970;
struct UnkStruct_0022F970_a1;
struct UnkStruct_0022F970_2;
struct UnkStruct_0022F970_3;

struct UnkStruct_0022F970_a1 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

struct UnkStruct_0022F970_3 {
    int field_0;
    int field_4;
};

struct UnkStruct_0022F970_2 {
    unsigned char pad_0[0x4E0];
    unsigned char field_4E0[0x10];
};

struct UnkStruct_0022F970 {
    unsigned char pad_0[0xC];
    UnkStruct_0022F970_2 * field_C;
    unsigned char pad_10[0x4];
    char field_14[0x10];
    int field_24;
    int field_28;
};

extern char D_004BA008[];  // "%d.%d.%d.%d"

extern "C" int snprintf(char *, int, const char *, ...);
extern "C" int GetMyPlayerID__23CGtNetworkPlayerManagerCFv(void *);  // CGtNetworkPlayerManager::GetMyPlayerID() const
extern "C" UnkStruct_0022F970_3 * func_002348A0(void *, int);

// [G] an inlined IP-address formatter (name unknown)
static inline void func_0022F970_inl1(char *buf, const int & ip)
{
    snprintf(buf, 16, D_004BA008, (unsigned char)((ip & 0xFF000000) >> 24), (ip & 0xFF0000) >> 16, (ip & 0xFF00) >> 8, ip & 0xFF);
}

static inline bool func_0022F970_inl2(int x) { return x == 1 || x == 2; }

// 0x0022F970
extern "C" void func_0022F970(UnkStruct_0022F970 * self, UnkStruct_0022F970_a1 * p0)
{
    char buf[16];
    func_0022F970_inl1(buf, p0->field_4);
    func_0022F970_inl1(buf, p0->field_8);
    UnkStruct_0022F970_2 *m = self->field_C;
    UnkStruct_0022F970_3 *v = func_002348A0(m->field_4E0, GetMyPlayerID__23CGtNetworkPlayerManagerCFv(m));
    bool a = func_0022F970_inl2(p0->field_0);
    bool b = func_0022F970_inl2(v->field_0);
    if (a && b != false && p0->field_4 == v->field_4) {
        self->field_24 = p0->field_8;
        func_0022F970_inl1(self->field_14, self->field_24);
        self->field_28 = p0->field_C;
    } else if (p0->field_0 != 2) {
        self->field_24 = p0->field_4;
        func_0022F970_inl1(self->field_14, self->field_24);
        self->field_28 = p0->field_C;
    } else {
        self->field_24 = p0->field_4;
        func_0022F970_inl1(self->field_14, self->field_24);
    }
}
