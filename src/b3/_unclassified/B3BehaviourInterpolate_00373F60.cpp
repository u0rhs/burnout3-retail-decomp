// CB3BehaviourInterpolate::Prepare(void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BehaviourInterpolate.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (stabs2: implicit operator= of a polymorphic block class with a 2-element u_long128 array).

// stabs2: blocks copied by the implicit operator= of a polymorphic 0x40 class (vptr not copied; +0xC is the u_long128 alignment hole, not a member) with field_10 a 2-element array; replaces the a129_cp member-wise copy
typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_3F60_cam { virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(void *); unsigned char pad_4[0x0]; };
struct UnkStruct_3F60_blk {
    virtual void vfunc_0();   // [L] polymorphic: the implicit operator= skips +0 (vptr) and the +0xC alignment hole; slot unknown
    float field_4;
    float field_8;
    u_long128 field_10[2];   // [C] one 2-element array: copied lq,lq,sq,sq
    int field_30;
    int field_34;
    int field_38;
    unsigned char field_3C;
};
struct UnkStruct_3F60_mgr { unsigned char pad_0[0x240]; UnkStruct_3F60_cam *field_240[1]; };
class CB3BehaviourInterpolate {
public:
    int Prepare(void *p0);
    unsigned char pad_0[0x10];
    UnkStruct_3F60_blk field_10;
    UnkStruct_3F60_blk field_50;
    UnkStruct_3F60_blk field_90;
    UnkStruct_3F60_blk field_D0;
    unsigned char pad_110[0x10];
    UnkStruct_3F60_mgr *field_120;
    unsigned char pad_124[0xC];
    int field_130;
    int field_134;
    int field_138;
    int field_13C;
    int field_140;
    unsigned char pad_144[0x4];
    unsigned char field_148;
    unsigned char field_149;
};
// 0x00373F60
int CB3BehaviourInterpolate::Prepare(void *p0v)
{
    const UnkStruct_3F60_blk *p = (const UnkStruct_3F60_blk *)p0v;
    field_10 = *p;
    field_50 = *p;
    field_120->field_240[field_134]->vfunc_10(&field_50);
    field_120->field_240[field_130]->pad_4[0] = 1;
    field_120->field_240[field_134]->pad_4[0] = 1;
    if (field_140 == 2) {
        if (field_148 == 0) {
            field_90 = *p;
            field_120->field_240[field_138]->vfunc_10(&field_90);
            field_120->field_240[field_138]->pad_4[0] = 1;
        }
        if (field_149 == 0) {
            field_D0 = *p;
            field_120->field_240[field_13C]->vfunc_10(&field_D0);
            field_120->field_240[field_13C]->pad_4[0] = 1;
        }
    }
    return 1;
}
