// CGtFileSystemPS2DVD::CmdErrorHandler(void*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtFileSystemPS2DVD.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a79: static callback (cmd,res), switch cases 1,0,2,3 source order).

struct UnkStruct_001D2EE0_cmd {
    unsigned char pad_0[0xC];
    int field_C;
};
struct UnkStruct_001D2EE0_res {
    unsigned char pad_0[4];
    int field_4;
};
class CGtFileSystemPS2DVD {
public:
    static void CmdErrorHandler(void *, void *);
};
// 0x001D2EE0
void CGtFileSystemPS2DVD::CmdErrorHandler(void *p0, void *p1)
{
    UnkStruct_001D2EE0_cmd *cmd = (UnkStruct_001D2EE0_cmd *)p0;
    UnkStruct_001D2EE0_res *res = (UnkStruct_001D2EE0_res *)p1;
    switch (cmd->field_C) {
    case 1:
        res->field_4 = 3;
        break;
    case 0:
        res->field_4 = 1;
        break;
    case 2:
        res->field_4 = 4;
        break;
    case 3:
        res->field_4 = 5;
        break;
    }
}
