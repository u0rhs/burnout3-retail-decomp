// CB3ReplayFrame::ArchiveDrivingControls(CDrivingControls*,unsigned char) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ReplayFrame.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (hand-written: inverse of RetrieveDrivingControls; byte fields with compound += (a74 pattern)).

struct CDrivingControls {
    unsigned char field_0;
    unsigned char pad_1[0x7];
    float field_8;
    float field_C;
    float field_10;
    int field_14;
    float field_18;
};
class CB3ReplayFrame {
public:
    void ArchiveDrivingControls(CDrivingControls * p0, unsigned char p1);
    signed char field_0;
    unsigned char field_1;
    unsigned char field_2;
};

// 0x00154D20
void CB3ReplayFrame::ArchiveDrivingControls(CDrivingControls * p0, unsigned char p1)
{
    field_0 = (signed char)(int)(127.0f * p0->field_C);
    field_1 = (int)(7.0f * p0->field_8) << 5;
    field_1 += (unsigned char)(int)(31.0f * p0->field_18);
    field_2 = p1 << 5;
    field_2 += p0->field_0 & 0x1F;
}
