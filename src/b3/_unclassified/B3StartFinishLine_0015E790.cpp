// CB3StartFinishLine::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StartFinishLine.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3StartFinishLine {
public:
    void Release();

    unsigned char pad_0[0x8];
    int field_8;
    unsigned char field_C;
};

extern "C" void Release__22CB3SplitTimeCheckpointFv(void *);  // CB3SplitTimeCheckpoint::Release()

// 0x0015E790
void CB3StartFinishLine::Release()
{
    Release__22CB3SplitTimeCheckpointFv(this);
    field_8 = 0;
    field_C = 0;
}
