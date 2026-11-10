// NONMATCHING: StopRaceCarBodyPartsCrashing__17CB3PhysicsManagerFi -- retail 88 / ours 88 instructions, 3 in changed runs
// inlc: state test inline takes (manager,index) and forms the element itself; st formed in the caller before the call; off-int c lookup. 3 left: retail ptr a0 / shift-1 a1, ours swapped (decl orders, refs, e-before/after tried)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

class UnkStruct_001B2A40_body {
public:
    virtual void vfunc_0();
    virtual void vfunc_4();
    virtual void vfunc_8();
    virtual void vfunc_14();
    unsigned char pad_4[0x2AC];
    void * field_2B0;
};
struct UnkStruct_001B2A40_e {
    unsigned char pad_0[0x70];
    signed char field_10;
    unsigned char field_11;
    unsigned char pad_72[0xA];
    UnkStruct_001B2A40_body * field_1C;
    unsigned char pad_20[0x2];
};
struct UnkStruct_001B2A40_d {
    unsigned char pad_0[0xC];
    signed char field_C;
};
struct UnkStruct_001B2A40_c {
    unsigned char pad_0[0x40];
    UnkStruct_001B2A40_d * field_40;
};
struct UnkStruct_001B2A40_p {
    unsigned char pad_0[0x4B2];
    signed char field_4B2;
};
struct UnkStruct_001B2A40_car {
    unsigned char pad_0[0xCC0];
    UnkStruct_001B2A40_c * field_CC0;
    char * field_CC4;
};

struct UnkStruct_001B2A40_t {
    unsigned char pad_0[0x30];
};

class CB3PhysicsManager;
class CB3PhysicsManager {
public:
    void StopRaceCarBodyPartsCrashing(int p0);
    UnkStruct_001B2A40_t field_0[1];
    unsigned char pad_30[0x1CB40];
    int field_1CB70;
};

static inline bool func_001B2A40_inl1(CB3PhysicsManager *m, int i)
{
    UnkStruct_001B2A40_e * e = (UnkStruct_001B2A40_e *)((char *)m + i * 0x30);
    return (unsigned int)e->field_10 <= 2 || e->field_10 == 4 || e->field_10 == 6 || e->field_10 == 7;
}
// 0x001B2A40
void CB3PhysicsManager::StopRaceCarBodyPartsCrashing(int p0)
{
    int i = 0;
    int off = p0 * 0x30;
    UnkStruct_001B2A40_car * c = (UnkStruct_001B2A40_car *)((UnkStruct_001B2A40_e *)(off + (int)this))->field_1C;
    for (; i < field_1CB70; i++) {
        signed char * st = &((UnkStruct_001B2A40_e *)((char *)this + i * 0x30))->field_10;
        if (func_001B2A40_inl1(this, i)) {
            UnkStruct_001B2A40_e * e = (UnkStruct_001B2A40_e *)((char *)this + i * 0x30);
            if (*st == 7) {
                if (e->field_1C->field_2B0 == c) {
                    e->field_1C->vfunc_14();
                    e->field_11 = 1;
                }
            }
        }
    }
    for (int j = 0; j < c->field_CC0->field_40->field_C; j++) {
        UnkStruct_001B2A40_p * p = (UnkStruct_001B2A40_p *)(c->field_CC4 + j);
        signed char * q = &p->field_4B2;
        if (*q == 3) *q = 4;
    }
}
