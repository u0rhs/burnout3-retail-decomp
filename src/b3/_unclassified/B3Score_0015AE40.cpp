// CB3Score::IsAheadOf(CB3Score*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a93: scoped locals, > / < compare forms, ternary tail).

struct UnkStruct_Score_C8 {
    unsigned char pad_0[0x16C0];
    short field_16C0;
    unsigned char pad_16C2[0x1998 - 0x16C2];
    unsigned char field_1998;
    unsigned char pad_1999[0x19AC - 0x1999];
    signed char field_19AC;
};

class CB3Score {
public:
    int IsAheadOf(CB3Score *p0);

    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0xBC];
    UnkStruct_Score_C8 *field_C8;
    unsigned char pad_CC[0x27C - 0xCC];
    int field_27C;
    unsigned char pad_280[0x348 - 0x280];
    float field_348;
    int field_34C;
    int field_350;
};

// 0x0015AE40
int CB3Score::IsAheadOf(CB3Score *p0)
{
    if (field_27C == 3 && field_8 == 1) {
        if (p0->field_27C != 3 || p0->field_8 != 1) {
            return 1;
        }
        return field_C8->field_16C0 < p0->field_C8->field_16C0;
    }
    if (p0->field_27C == 3 && p0->field_8 == 1) {
        return 0;
    }
    UnkStruct_Score_C8 *b = p0->field_C8;
    UnkStruct_Score_C8 *a = field_C8;

    int r = a->field_1998;
    if (r != b->field_1998) {
        return r;
    }
    {
        int b0 = p0->field_350;
        int a0 = field_350;
        if (a0 > b0) {
            return 1;
        }
        if (a0 < b0) {
            return 0;
        }
    }
    {
        int b1 = p0->field_34C;
        int a1 = field_34C;
        if (a1 > b1) {
            return 1;
        }
        if (a1 < b1) {
            return 0;
        }
    }
    float y = p0->field_348;
    float x = field_348;
    if (x > y) {
        return 1;
    }
    if (x < y) {
        return 0;
    }
    return b->field_19AC < a->field_19AC ? 1 : 0;
}
