// CB3BehaviourTrackSide::IncrementSegment(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3BehaviourTrackSide.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (named int off = idx*10 added to base (a154 form)).


struct UnkStruct_is_seg { unsigned char pad_0[4]; unsigned char field_4[3]; unsigned char pad_7; unsigned short field_6[1]; unsigned char pad_a[0]; };
struct UnkStruct_is_row { unsigned char pad_0[4]; unsigned char field_4[2]; unsigned short field_6[2]; };
struct UnkStruct_is_def { unsigned char pad_0[8]; UnkStruct_is_row *field_8; unsigned short field_C; unsigned char field_E; };
struct UnkStruct_is_lane { int field_0; UnkStruct_is_def *field_4; };
struct UnkStruct_is_ent { unsigned char pad_0[0x2C]; UnkStruct_is_lane field_2C[1]; };
extern UnkStruct_is_ent D_00522660;
extern "C" void IncrementSegment__21CB3BehaviourTrackSideFb(UnkStruct_is_lane **self, unsigned short *idx, int dir, bool fwd)
{
    int n;
    UnkStruct_is_lane *lane = *self;
    int i = *idx;
    if (fwd) {
        UnkStruct_is_def *d = lane->field_4;
        if ((unsigned short)i < d->field_C - 1) {
            n = (unsigned short)(i + 1);
        } else if (d->field_E) {
            n = 0;
        } else {
            int off = (unsigned short)i * 10;
            UnkStruct_is_row *r = (UnkStruct_is_row *)(off + (int)d->field_8);
            n = r->field_6[dir];
            lane = &D_00522660.field_2C[r->field_4[dir]];
        }
    } else {
        if ((unsigned short)i > 0) {
            n = (unsigned short)(i - 1);
        } else {
            UnkStruct_is_def *d = lane->field_4;
            if (d->field_E) {
                n = (unsigned short)(d->field_C - 1);
            } else {
                int off = (unsigned short)i * 10;
            UnkStruct_is_row *r = (UnkStruct_is_row *)(off + (int)d->field_8);
                n = r->field_6[dir];
                lane = &D_00522660.field_2C[r->field_4[dir]];
            }
        }
    }
    *self = lane;
    *idx = n;
}
