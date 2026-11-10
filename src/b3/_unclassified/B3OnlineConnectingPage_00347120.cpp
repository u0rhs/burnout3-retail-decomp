// CB3OnlineConnectingPage::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineConnectingPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (inner switch on GetLobbyStatus() in source order 0,2,1 (a1=1 reused from the compare); phantom a1 args dropped).

// CB3OnlineConnectingPage::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineConnectingPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EB3MenuFlowFSMEvents {};

class CB3OnlineConnectingPage;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E90424;

struct UnkStruct_D_01E90424 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnlineConnectingPage {
public:
    void Update();

    unsigned char pad_0[0x4];
    signed char field_4;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void UpdateISP__23CB3OnlineConnectingPageFv(void *);  // CB3OnlineConnectingPage::UpdateISP()
extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::GetLobbyStatus()
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]

// 0x00347120
void CB3OnlineConnectingPage::Update()
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    switch (field_4) {
    case 0:
        UpdateISP__23CB3OnlineConnectingPageFv(this);
        break;
    case 1:
        switch (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0)) {
        case 0:
            break;
        case 2:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
            break;
        case 1:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)21, 0);
            break;
        }
        break;
    }
}
