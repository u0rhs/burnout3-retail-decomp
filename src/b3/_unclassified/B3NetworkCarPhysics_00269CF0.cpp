// CB3NetworkCarPhysics::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkCarPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3NetworkCarPhysics {
public:
    void Construct();

    unsigned char pad_0[0x215];
    unsigned char field_215;
};

extern "C" void func_001C6EF0(CB3NetworkCarPhysics *);

// 0x00269CF0
void CB3NetworkCarPhysics::Construct()
{
    func_001C6EF0(this);
    field_215 = 3;
}
