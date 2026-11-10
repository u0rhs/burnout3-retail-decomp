// CB3Score::GetRaceCheckpoint(int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3Score;

class CB3Score {
public:
    int GetRaceCheckpoint(int p0, int p1);

    unsigned char pad_0[0x2E0];
    int field_2E0;
};

// 0x0015A7D0
int CB3Score::GetRaceCheckpoint(int p0, int p1)
{
    return (p1 + (p0 * (field_2E0 + 1)));
}
