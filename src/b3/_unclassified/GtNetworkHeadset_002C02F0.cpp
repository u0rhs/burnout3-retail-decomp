// CGtNetworkHeadset::GetIDOfTalkingNetworkPlayer(int*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNetworkHeadset.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (second guard written 'field > -1 && field != id' (slti at,x,0 instead of bltz)).

// CGtNetworkHeadset::GetIDOfTalkingNetworkPlayer(int*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNetworkHeadset.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtNetworkHeadset;
class CGtNetworkPlayerManager;

class CGtNetworkPlayerManager {
public:
    int GetMyPlayerID() const;
};

class CGtNetworkHeadset {
public:
    int GetIDOfTalkingNetworkPlayer(int* p0);

    unsigned char pad_0[0x81D4];
    int field_81D4;
    CGtNetworkPlayerManager * field_81D8;
};

// 0x002C02F0
int CGtNetworkHeadset::GetIDOfTalkingNetworkPlayer(int* p0)
{
    int r0 = field_81D8->GetMyPlayerID();
    if (r0 < 0) {
        return 0;
    }
    if (field_81D4 > -1 && field_81D4 != r0) {
        *p0 = field_81D4;
        return 1;
    }
    return 0;
}
