// CB3HUDPrimaryMessage::UpdateTransition(float,bool,EHUDMode,EHUDMode) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDPrimaryMessage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (void return; early returns: if (p0 != 1.0f) return; if ((field_4C != 0) == false) return;).

// CB3HUDPrimaryMessage::UpdateTransition(float,bool,EHUDMode,EHUDMode) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDPrimaryMessage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EHUDMode {};

class CB3HUDPrimaryMessage;
class CB3HUDPrimaryMessageHandler;

class CB3HUDPrimaryMessageHandler {
public:
    void ClearMessage(bool);  // [C] void: defined so (B3HUDPrimaryMessageHandler_003D5510.cpp); no caller reads v0/f0 (0x3D8110 jal, then jr)
};

class CB3HUDPrimaryMessage {
public:
    void UpdateTransition(float p0, bool p1, EHUDMode p2, EHUDMode p3);

    unsigned char pad_0[0x40];
    CB3HUDPrimaryMessageHandler field_40;
    unsigned char pad_41[0xB];
    int field_4C;
};


// 0x003D80E0
void CB3HUDPrimaryMessage::UpdateTransition(float p0, bool p1, EHUDMode p2, EHUDMode p3)
{
    if (p0 != 1.0f) return;
    if ((field_4C != 0) == false) return;
    field_40.ClearMessage(1);
}
