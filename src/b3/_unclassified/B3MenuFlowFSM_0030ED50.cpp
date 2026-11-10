// CB3MenuFlowFSM::GetMenuFlowType() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3MenuFlowFSM.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). The class is declared here with only what this function
// needs; field names are placeholders and their types are [G] from the instruction widths.

class CB3MenuFlowFSM {
public:
    int GetMenuFlowType();

    unsigned char pad_0[0x818];
    int field_818;
};

// 0x0030ED50
int CB3MenuFlowFSM::GetMenuFlowType()
{
    return field_818;
}
