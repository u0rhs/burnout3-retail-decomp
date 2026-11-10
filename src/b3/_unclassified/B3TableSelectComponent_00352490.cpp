// CB3TableSelectComponent::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TableSelectComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3TableSelectComponent {
public:
    void Construct();

    unsigned char pad_0[0x14];
    int field_14;
};

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// 0x00352490
void CB3TableSelectComponent::Construct()
{
    Construct__20CB3MenuComponentBaseFi(this, 1);
    field_14 = 0;
}
