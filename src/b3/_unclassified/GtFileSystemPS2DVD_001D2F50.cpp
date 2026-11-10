// CGtFileSystemPS2DVD::CmdReadCompleteHandler(void*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFileSystemPS2DVD.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (extern C).

struct UnkStruct_1D2F_a164_E { unsigned char pad_0[0x18]; int flag; unsigned char pad_1[0x2C-0x1C]; int sema; unsigned char pad_2[0x38-0x30]; };
struct UnkStruct_1D2F_a164_B { unsigned char pad_0[0x10]; UnkStruct_1D2F_a164_E *arr; };
struct UnkStruct_1D2F_a164_A { unsigned char pad_0[0xC]; unsigned char idx; };
extern "C" int iSignalSema(int);
extern "C" int CmdReadCompleteHandler__19CGtFileSystemPS2DVDFPvPv(UnkStruct_1D2F_a164_A *a, UnkStruct_1D2F_a164_B *b)
{
    UnkStruct_1D2F_a164_E *e = &b->arr[a->idx];
    e->flag = 1;
    return iSignalSema(e->sema);
}
