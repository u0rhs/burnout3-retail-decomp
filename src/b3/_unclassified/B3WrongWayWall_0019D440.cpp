// CB3WrongWayWall::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3WrongWayWall.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a79: bool return (li v0,1 left), two memset array members).

extern "C" void * memset(void *, int, unsigned int);
struct CB3WrongWayWall {
    bool Prepare();
    unsigned char field_0[0xA80];
    unsigned char field_A80[0xA80];
    unsigned char pad_1500[0xA80];
    int field_1F80;
    int field_1F84;
    int field_1F88;
    int field_1F8C;
    short field_1F90;
    unsigned char pad_1F92[2];
    int field_1F94;
    unsigned char field_1F98;
    unsigned char field_1F99;
};
// 0x0019D440
bool CB3WrongWayWall::Prepare()
{
    field_1F80 = 0;
    field_1F84 = 0;
    field_1F88 = 0;
    field_1F99 = 0;
    field_1F94 = -1;
    field_1F98 = 0;
    memset(field_0, 0, 0xA80);
    memset(field_A80, 0, 0xA80);
    field_1F8C = 0;
    field_1F90 = 0;
    return true;
}
