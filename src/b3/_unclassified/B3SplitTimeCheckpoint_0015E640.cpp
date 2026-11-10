// CB3SplitTimeCheckpoint::Release() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SplitTimeCheckpoint.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes are declared here with only what this
// function needs; field names are placeholders and their types are [G] from the instruction widths.
// Tail call: func_00272B90.

class CB3SplitTimeCheckpoint {
public:
    void Release();

    unsigned char pad_0[0x4];
    int field_4;
};

extern "C" void func_00272B90(CB3SplitTimeCheckpoint *);

// 0x0015E640
void CB3SplitTimeCheckpoint::Release()
{
    field_4 = 0;
    func_00272B90(this);
}
