// CB3StreamedTrack::IsUnitVisibleToMainCamera(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamedTrackPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (N182 opt_repositioncode off + goto blocks after loop).

// N182: retail compiled this function with `#pragma opt_repositioncode off` ([G] scoped to this function).
#pragma push
#pragma opt_repositioncode off

struct UnkStruct_0021CFF0 {
    unsigned char pad_0[0x44];
    unsigned char field_44;
    unsigned char pad_45[0x13];
    unsigned short field_58[17];
    unsigned char pad_7A[0x4A];
    int field_C4[17];
    unsigned char pad_108[0x74];
    int field_17C[1];
};

// 0x0021CFF0
extern "C" bool IsUnitVisibleToMainCamera__16CB3StreamedTrackFi(UnkStruct_0021CFF0 *self, int p0)
{
    int i;
    if (self->field_44 != 0) {
        if (p0 != -1) {
            i = 0;
top:
            if (i <= 16) {
                if (self->field_C4[i] != self->field_17C[p0]) goto next;
                return (self->field_58[i] & 3) != 0;
next:
                i++;
                goto top;
            }
            goto z;
        }
        goto n;
    }
    return true;
n:
    return false;
z:
    return true;
}

#pragma pop
