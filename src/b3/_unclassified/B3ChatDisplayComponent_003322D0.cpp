// CB3ChatDisplayComponent::Update(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3ChatDisplayComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near6: clone of sibling CB3VListComponent::Update (if (D_01E90424.value == 5) return;)).

// CB3ChatDisplayComponent::Update(float) -- hand-matched (near6): clone of the proven sibling CB3VListComponent::Update
// (0x32B290, same retail body: the empty `== 5` test leaves the dead lw/li).
// [C] name: the mangled symbol in retail's tables. D_01E90424 padded past the small-data threshold (N51), as the sibling.
struct UnkStruct_D_01E90424 {
    int value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E90424 D_01E90424;

class CB3ChatDisplayComponent {
public:
    void Update(float);
};

// 0x003322D0
void CB3ChatDisplayComponent::Update(float)
{
    if (D_01E90424.value == 5)
        return;
}
