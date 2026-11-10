// CB3AILane::GetDistanceBetweenSegments(unsigned short,unsigned short) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (hand-written: inline segment-distance helper takes int (stops a2 clobber), if (p0 <= p1) return f2-f1 else wrap-around).

struct UnkStruct_00147810_seg {
    float field_0;
    float field_4;
};
struct UnkStruct_00147810_1 {
    unsigned char pad_0[0x4];
    UnkStruct_00147810_seg * field_4;
    unsigned char pad_8[0x4];
    unsigned short field_C;
};
class CB3AILane {
public:
    float GetDistanceBetweenSegments(unsigned short, unsigned short) const;
    inline float func_00147810_inl1(int s) const {
        int j = s - 1;
        if (j < 0) {
            return 0.0f;
        }
        return field_4->field_4[j].field_0;
    }

    unsigned char pad_0[0x4];
    UnkStruct_00147810_1 * field_4;
};

// 0x00147810
float CB3AILane::GetDistanceBetweenSegments(unsigned short p0, unsigned short p1) const
{
    float f2 = func_00147810_inl1(p1);
    float f1 = func_00147810_inl1(p0);
    if (p0 <= p1) {
        return f2 - f1;
    }
    return f2 + (field_4->field_4[field_4->field_C - 1].field_0 - f1);
}
