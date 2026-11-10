// CGtSoundStream::Pause(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundStream.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (if (field_1D0 > 2) { if (p0 && !field_1F5) {...} else if (p0 == false && field_1F6 == 1) {...} }).

// lifter variant 0
// CGtSoundStream::Pause(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundStream.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundStream;

class CGtSoundStream {
public:
    void Pause(bool p0);

    unsigned char pad_0[0x1CC];
    int field_1CC;
    int field_1D0;
    unsigned char pad_1D4[0x21];
    unsigned char field_1F5;
    unsigned char field_1F6;
};

extern "C" void _rwaStreamSetPlayState(int, int);
extern "C" int _rwaStreamGetStatus(int);

void CGtSoundStream::Pause(bool p0)
{
    if (field_1D0 > 2) {
        if (p0 && !field_1F5) {
            if (_rwaStreamGetStatus(field_1CC) == 6) {
                field_1F6 = 1;
            }
            _rwaStreamSetPlayState(field_1CC, 3);
            field_1D0 = 8;
            field_1F5 = 1;
        } else if (p0 == false && field_1F6 == 1) {
            _rwaStreamSetPlayState(field_1CC, 2);
            field_1D0 = 6;
            field_1F5 = 0;
        }
    }
}
