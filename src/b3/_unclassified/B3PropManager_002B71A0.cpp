// CB3PropManager::KillProp(CB3Prop*,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3PropManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a77: search loop + swap-remove; returns index i (v0 live at exit) so i lands in v0).

struct UnkStruct_002B7230_e0 {
    unsigned short field_0;
    unsigned char field_2;
    unsigned char field_3;
};
struct UnkStruct_002B7230 {
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0xC];
    UnkStruct_002B7230_e0 field_1C[1];  // [G] element count unknown
};

// 0x002B71A0
extern "C" int KillProp__14CB3PropManagerFP7CB3Propb(UnkStruct_002B7230 *self, UnkStruct_002B7230_e0 *p0, bool p1)
{
    int i;
    for (i = 0; i < self->field_C; i++) {
        if (p0 == &self->field_1C[i]) break;
    }
    if (p1 == false) {
        self->field_C = self->field_C - 1;
        self->field_1C[i] = self->field_1C[self->field_C];
    }
    return i;
}
