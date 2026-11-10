// CB3SoundDSPDataBlock::SetType(EDSPType) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundDSPBlock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). The class is declared here with only what this function
// needs; field names are placeholders and their types are [G] from the instruction widths.

enum EDSPType {};

class CB3SoundDSPDataBlock {
public:
    void SetType(EDSPType p0);

    unsigned char pad_0[0x70];
    EDSPType field_70;
};

// 0x002FC150
void CB3SoundDSPDataBlock::SetType(EDSPType p0)
{
    field_70 = p0;
}
