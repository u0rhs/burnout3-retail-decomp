// CB3Score::AddScore(int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a74: extern C def with extra a3 index param; k=1.0f local kept; early return on mask==0 then p2>=4 return).

struct UnkStruct_00156260_3 {
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
    virtual int vfunc_48();
};
struct UnkStruct_00156260_2 {
    unsigned char pad_0[0x1B4];
    UnkStruct_00156260_3 * field_1B4;
};
struct UnkStruct_D_0051BA88 {
    UnkStruct_00156260_2 * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_00156260 {
    unsigned char pad_0[0x4C];
    int field_4C;
    unsigned char pad_50[0x5C];
    int field_AC[4];
};
extern UnkStruct_D_0051BA88 D_0051BA88;

// 0x00156260
extern "C" void AddScore__8CB3ScoreFii(UnkStruct_00156260 * self, int p0, int p1, int p2)
{
    if ((p1 & D_0051BA88.field_0->field_1B4->vfunc_48()) == 0) {
        return;
    }
    float k = 1.0f;
    int t0 = (int)((float)p0 * k);
    self->field_4C = self->field_4C + t0;
    if (p2 >= 4) {
        return;
    }
    self->field_AC[p2] = self->field_AC[p2] + t0;
}
