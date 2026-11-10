// CB3StartFinishLine::Construct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StartFinishLine.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes are declared here with only what this
// function needs; field names are placeholders and their types are [G] from the instruction widths.
// Tail call: Construct__22CB3SplitTimeCheckpointFv = CB3SplitTimeCheckpoint::Construct().

class CB3StartFinishLine {
public:
    void Construct();

    unsigned char pad_0[0x8];
    int field_8;
    unsigned char field_C;
};

extern "C" void Construct__22CB3SplitTimeCheckpointFv(CB3StartFinishLine *);  // CB3SplitTimeCheckpoint::Construct()

// 0x0015E890
void CB3StartFinishLine::Construct()
{
    field_8 = 0;
    field_C = 0;
    Construct__22CB3SplitTimeCheckpointFv(this);
}
