// CB3BuddyDisplayComponent::MailSent(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3BuddyDisplayComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (index local computed first, one && range guard).

// CB3BuddyDisplayComponent::MailSent(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3BuddyDisplayComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3BuddyDisplayComponent;
struct UnkStruct_00366570_e0;

struct UnkStruct_00366570_e0 {
    unsigned char pad_0[0x2C];
    int field_2C;
};

class CB3BuddyDisplayComponent {
public:
    void MailSent(int p0);

    unsigned char pad_0[0xF0];
    UnkStruct_00366570_e0 field_F0[1];  // [G] element count unknown
    unsigned char pad_120[0xD60];
    int field_E80;
};

// 0x00366570
void CB3BuddyDisplayComponent::MailSent(int p0)
{
    int i = p0 - field_E80;
    if (p0 >= field_E80 && p0 < field_E80 + 9) {
        field_F0[i].field_2C = 0;
    }
}
