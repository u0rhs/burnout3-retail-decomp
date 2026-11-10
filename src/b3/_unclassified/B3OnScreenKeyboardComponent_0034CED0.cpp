// CB3OnScreenKeyboardComponent::SetAllowableCharacters(EGlobalStrings) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (field_1A/1B are bool (passed straight to bool params); keep (19^18)!=0).

// CB3OnScreenKeyboardComponent::SetAllowableCharacters(EGlobalStrings) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EGlobalStrings {};

class CB3OnScreenKeyboardComponent;

class CB3OnScreenKeyboardComponent {
public:
    void SetAllowableCharacters(EGlobalStrings p0);
    void SetupKeys(bool, bool, bool);

    unsigned char pad_0[0x18];
    unsigned char field_18;
    unsigned char field_19;
    bool field_1A;
    bool field_1B;
    unsigned char pad_1C[0x31EC];
    int field_3208;
};

// 0x0034CED0
void CB3OnScreenKeyboardComponent::SetAllowableCharacters(EGlobalStrings p0)
{
    field_3208 = p0;
    SetupKeys(((field_19 ^ field_18) != 0), field_1A, field_1B);
}
