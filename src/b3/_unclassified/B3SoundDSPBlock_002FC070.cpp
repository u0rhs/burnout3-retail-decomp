// CB3SoundDSPDataBlock::Process(short*,short*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundDSPBlock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (if-chain -> switch with cases in source order 0,1,3,2 (MWCC emits compares in reverse case order)).

class CB3SoundDSPDataBlock {
public:
    void Process(short* p0, short* p1);
    void ProcessB2Distortion(short*, short*);

    unsigned char pad_0[0x70];
    int field_70;
};

extern "C" void func_002FB890(CB3SoundDSPDataBlock *, short*, short*);

// 0x002FC070
void CB3SoundDSPDataBlock::Process(short* p0, short* p1)
{
    switch (field_70) {
    case 0:
        break;
    case 1:
        ProcessB2Distortion(p0, p1);
        break;
    case 3:
        break;
    case 2:
        func_002FB890(this, p0, p1);
        break;
    }
}
