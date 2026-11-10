// CB3TableSelectComponent::Prepare(int,CGt2dObjectTable*,const CB3MenuComponentSelectionData*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TableSelectComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGt2dObjectTable;
class CB3MenuComponentSelectionData;

class CB3TableSelectComponent;

class CB3TableSelectComponent {
public:
    int Prepare(int p0, CGt2dObjectTable* p1, const CB3MenuComponentSelectionData* p2);

    unsigned char pad_0[0xC];
    const CB3MenuComponentSelectionData * field_C;
    CGt2dObjectTable * field_10;
    unsigned char pad_14[0x4];
    int field_18;
    int field_1C;
};

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Prepare()

// 0x00352430
int CB3TableSelectComponent::Prepare(int p0, CGt2dObjectTable* p1, const CB3MenuComponentSelectionData* p2)
{
    Prepare__20CB3MenuComponentBaseFv(this);
    field_C = (const CB3MenuComponentSelectionData *)p2;
    field_18 = -1;
    field_1C = p0;
    field_10 = (CGt2dObjectTable *)p1;
    return 1;
}
