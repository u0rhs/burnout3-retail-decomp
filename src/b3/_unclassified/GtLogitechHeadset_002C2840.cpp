// CGtLogitechHeadset::Construct(char*,int,char*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtLogitechHeadset.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (status tail as if (17C != -1 && 180 != 0) =2; else if (17C == -1) =0; else if (180 == 0) =1).

// lifter variant 0
// CGtLogitechHeadset::Construct(char*,int,char*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtLogitechHeadset.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtLogitechHeadset;

class CGtLogitechHeadset {
public:
    void Construct(char* p0, int p1, char* p2, int p3);

    char * field_0;
    int field_4;
    char * field_8;
    int field_C;
    int field_10;
    unsigned char pad_14[0x10];
    int field_24;
    unsigned char pad_28[0x154];
    int field_17C;
    int field_180;
    unsigned char pad_184[0x800];
    unsigned char field_984;
};

void CGtLogitechHeadset::Construct(char* p0, int p1, char* p2, int p3)
{
    field_0 = p0;
    field_4 = p1;
    field_8 = p2;
    field_C = p3;
    field_17C = -1;
    field_24 = 0;
    field_180 = 0;
    field_984 = 0;
    if (field_17C != -1 && field_180 != 0) {
        field_10 = 2;
    } else if (field_17C == -1) {
        field_10 = 0;
    } else if (field_180 == 0) {
        field_10 = 1;
    }
}
