// CB3StreamedTrack::UpdateStreamHighFSM() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamedTrack.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (switch with default: break and shared return 0; vptr via D_0064CD40.field_0).

class CB3StreamedTrackHighData;
struct UnkStruct_us_el { unsigned int field_0; int field_4; int field_8; int field_C; };
struct UnkStruct_us_mgr {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10(CB3StreamedTrackHighData *, int);
    virtual void vfunc_14();
    virtual void vfunc_18(unsigned long, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_us_tbl { unsigned char pad_0[0x34]; short field_34; unsigned char pad_36[0x22]; UnkStruct_us_el *field_58; unsigned char pad_5C[4]; };
struct UnkStruct_us_self {
    unsigned char pad_0[8]; int field_8; unsigned char pad_C[8]; UnkStruct_us_el *field_14; unsigned char pad_18[8]; int field_20; unsigned char pad_24[0xC]; int field_30; unsigned char pad_34[8]; int field_3C; unsigned char pad_40[0x10]; int field_50; unsigned char pad_54[0x100]; CB3StreamedTrackHighData *field_154[1];
};
struct UnkStruct_D_0064C994 { UnkStruct_us_tbl *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064CD40 { UnkStruct_us_mgr *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064CD40 D_0064CD40;
extern UnkStruct_D_0064C994 D_0064C994;
extern "C" void FixUp__24CB3StreamedTrackHighDataFs(CB3StreamedTrackHighData *, short);
extern "C" int UpdateStreamHighFSM__16CB3StreamedTrackFv(UnkStruct_us_self *self)
{
    switch (self->field_3C) {
    case 1:
        self->field_14 = D_0064C994.field_0->field_58 + self->field_50;
        D_0064CD40.field_0->vfunc_18(self->field_14->field_0, 0);
        self->field_3C = 2;
        break;
    case 2:
        self->field_30 = self->field_20 % self->field_8;
        D_0064CD40.field_0->vfunc_10(self->field_154[self->field_30], self->field_14->field_8);
        self->field_3C = 3;
        break;
    case 3:
        FixUp__24CB3StreamedTrackHighDataFs(self->field_154[self->field_30], D_0064C994.field_0->field_34);
        *(int *)((unsigned int)self->field_154[self->field_30] | 0x20000000) = 2;
        self->field_3C = 0;
        return 1;
    default:
        break;
    }
    return 0;
}
