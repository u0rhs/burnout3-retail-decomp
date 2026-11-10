// CGtScreenCentre::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtScreenCentre.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (bitfield DISPLAY).

struct UnkStruct_2213_a164_disp { unsigned int field_0 : 12; unsigned int field_0b : 11; unsigned int pad : 9; };
struct UnkStruct_2213_a164_F { unsigned char pad_0[0x18]; UnkStruct_2213_a164_disp field_18; };
extern UnkStruct_2213_a164_F _rwDMAFlipData;
struct UnkStruct_2213_a164 { float f0; float f4; int f8; int fC; };
extern "C" void Construct__15CGtScreenCentreFv(UnkStruct_2213_a164 *s)
{
    s->f0 = 0;
    s->f4 = 0;
    s->f8 = _rwDMAFlipData.field_18.field_0;
    s->fC = _rwDMAFlipData.field_18.field_0b;
}
