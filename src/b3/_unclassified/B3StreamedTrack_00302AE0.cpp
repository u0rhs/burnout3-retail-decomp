// CB3StreamedTrack::UpdateStreamLowFSM() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamedTrack.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (twin of High FSM).

class CB3StreamedTrackLODAndCollisionData;
struct UnkStruct_us_el { unsigned int field_0; unsigned int field_4; int field_8; int field_C; };
struct UnkStruct_us_mgr {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10(CB3StreamedTrackLODAndCollisionData *, int);
    virtual void vfunc_14();
    virtual void vfunc_18(unsigned long, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_us_tbl { unsigned char pad_0[0x34]; short field_34; unsigned char pad_36[0x22]; UnkStruct_us_el *field_58; unsigned char pad_5C[4]; };
struct UnkStruct_us_self {
    unsigned char pad_0[0xC]; int field_C; unsigned char pad_10[4]; UnkStruct_us_el *field_14; unsigned char pad_18[0xC]; int field_24; unsigned char pad_28[0xC]; int field_34; unsigned char pad_38[8]; int field_40; unsigned char pad_44[0x10]; int field_54; unsigned char pad_58[0x124]; CB3StreamedTrackLODAndCollisionData *field_17C[1];
};
struct UnkStruct_D_0064C994 { UnkStruct_us_tbl *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064CD40 { UnkStruct_us_mgr *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064CD40 D_0064CD40;
extern UnkStruct_D_0064C994 D_0064C994;
extern "C" void FixUp__35CB3StreamedTrackLODAndCollisionDataFi(CB3StreamedTrackLODAndCollisionData *, int);
extern "C" int UpdateStreamLowFSM__16CB3StreamedTrackFv(UnkStruct_us_self *self)
{
    switch (self->field_40) {
    case 1:
        self->field_14 = D_0064C994.field_0->field_58 + self->field_54;
        D_0064CD40.field_0->vfunc_18(self->field_14->field_4, 0);
        self->field_40 = 2;
        break;
    case 2:
        self->field_34 = self->field_24 % self->field_C;
        D_0064CD40.field_0->vfunc_10(self->field_17C[self->field_34], self->field_14->field_C);
        self->field_40 = 3;
        break;
    case 3:
        FixUp__35CB3StreamedTrackLODAndCollisionDataFi(self->field_17C[self->field_34], D_0064C994.field_0->field_34);
        *(int *)((unsigned int)self->field_17C[self->field_34] | 0x20000000) = 2;
        self->field_40 = 0;
        return 1;
    default:
        break;
    }
    return 0;
}
