// NONMATCHING: Construct__21CGtSoundStreamManagerFP13RwaSPU2Outputii -- retail 69 / ours 69 instructions, 2 in changed runs
// pass3b: ourGlobals+0x134 as a sub-struct {field_0 alloc, field_4 free} [L, field_138 is the free call in GtSoundStream_00386360]: og->field_134.field_0 keeps 308(s5); a const/non-const/reference/function-pointer-pointer to the sub-struct, defined before sz/after/at top, and a this copy (s) all fold the offset but colour og=s4/this=s5 (25 off). The folded constant address always colours below this.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// a219: 25 -> 2. Calling through a const struct pointer og=&ourGlobals (og->field_134)(..) fixes the s-register order; only left: retail folds +0x134 into the base (addiu s5,ourGlobals+0x134; lw 0(s5)) whereas ours keeps base ourGlobals + lw 308(s5). Sub-struct pointer/&field/byte-offset forms regress the s-regs to 25

// 25 instrs, register-only: retail s5=&ourGlobals.field_134, s4=this, s3=p0, s2=p1, s1=p2*p1 (mult hoisted into the entry-jump delay slot), s0=i; ours this=s5. Logic exact (69/69); 10 declaration-order variants tried

struct GtLListTag; struct GtLLLinkTag; struct GtLListPoolTag;
class CGtFreeListPool;
struct RwaSPU2Output;
extern "C" void Construct__15CGtFreeListPoolFUiUiUiPCvPvUi(CGtFreeListPool*, unsigned int, unsigned int, unsigned int, const void*, void*, unsigned int);
extern "C" void Construct__11CGtFreeListFP15CGtFreeListPool(void *, void *);
extern "C" void *AddLink__11CGtFreeListFv(void *);
extern "C" void RemoveAllLinks__11CGtFreeListFv(void *);
extern "C" void Construct__14CGtSoundStreamFP13RwaSPU2Outputi(void *, RwaSPU2Output *, int);
extern "C" void *memset(void *, int, unsigned);
struct UnkStruct_ourGlobals {
    unsigned char pad_0[0x134];
    void *(*field_134)(int, int);
};
extern UnkStruct_ourGlobals ourGlobals;
class CGtSoundStreamManager {
public:
    void Construct(RwaSPU2Output *p0, int p1, int p2);
    unsigned char pad_0[0x14];
    unsigned char field_14[8];
    int field_1C;
    unsigned char pad_20[4];
    void *field_24;
    unsigned char pad_28[4];
    void *field_2C;
    int field_30;
};
void CGtSoundStreamManager::Construct(RwaSPU2Output *p0, int p1, int p2)
{
    int sz = p1 * 0x200 + 0x10;
    UnkStruct_ourGlobals * const og = &ourGlobals;
    field_2C = (og->field_134)(sz, 0);
    Construct__15CGtFreeListPoolFUiUiUiPCvPvUi((CGtFreeListPool *)this, p1, 0x1F8, 0x10, 0, field_2C, sz);
    Construct__11CGtFreeListFP15CGtFreeListPool(field_14, this);
    for (int i = 0; i < p1; i++) {
        Construct__14CGtSoundStreamFP13RwaSPU2Outputi((char *)AddLink__11CGtFreeListFv(field_14) + 8, p0, p2 * p1);
    }
    field_1C = p1;
    field_24 = (og->field_134)(field_1C * 8, 0);
    memset(field_24, 0, field_1C * 8);
    RemoveAllLinks__11CGtFreeListFv(field_14);
    field_30 = 0;
}

