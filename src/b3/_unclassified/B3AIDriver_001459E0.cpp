// CB3AIDriver::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIDriver.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3AIDriver {
public:
    void Release();

    unsigned char pad_0[0xA10];
    signed char field_A10;
};

extern "C" void Release__15CB3AIArbitratorFv(void *);  // CB3AIArbitrator::Release()

// 0x001459E0
void CB3AIDriver::Release()
{
    Release__15CB3AIArbitratorFv(this);
    field_A10 = -1;
}
