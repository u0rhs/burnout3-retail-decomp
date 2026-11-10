// CB3Score::DecrementHealth(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3Score;

class CB3Score {
public:
    void DecrementHealth(float p0);

    unsigned char pad_0[0x5F4];
    float field_5F4;
};

// 0x00156220
void CB3Score::DecrementHealth(float p0)
{
    float t0 = field_5F4;
    field_5F4 = (t0 - p0);
    if ((t0 - p0) < 0.0f) {
        field_5F4 = 0.0f;
    }
}
