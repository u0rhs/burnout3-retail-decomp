// CB3MenuComponents::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MenuComponents.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3BuddyDisplayComponent;
class CB3BuddyReadMailComponent;
class CB3ChatDisplayComponent;
class CB3ConnectionAnimationComponent;
class CB3EventFinishedComponent;
class CB3MenuComponents;
class CB3MessageBoxComponent;
class CB3PageTextComponent;
class CB3RewardImageComponent;
class CB3TableComponent;
class CB3TableSelectComponent;
class CB3TitleScreenComponent;

class CB3EventFinishedComponent {
public:
    void Construct();
};

class CB3ChatDisplayComponent {
public:
    void Construct();
};

class CB3ConnectionAnimationComponent {
public:
    void Construct();
};

class CB3TableComponent {
public:
    void Construct();
};

class CB3TableSelectComponent {
public:
    void Construct();
};

class CB3BuddyReadMailComponent {
public:
    void Construct();
};

class CB3BuddyDisplayComponent {
public:
    void Construct();
};

class CB3PageTextComponent {
public:
    void Construct();
};

class CB3RewardImageComponent {
public:
    void Construct();
};

class CB3TitleScreenComponent {
public:
    void Construct();
};

class CB3MessageBoxComponent {
public:
    void Construct();
};

class CB3MenuComponents {
public:
    void Construct();

    unsigned char pad_0[0xA60];
    CB3EventFinishedComponent field_A60;
    unsigned char pad_A61[0x407];
    CB3MessageBoxComponent field_E68;
    unsigned char pad_E69[0x32F7];
    CB3ChatDisplayComponent field_4160;
    unsigned char pad_4161[0x86F];
    CB3TableComponent field_49D0;
    unsigned char pad_49D1[0x3F];
    CB3TableSelectComponent field_4A10;
    unsigned char pad_4A11[0x5F];
    CB3PageTextComponent field_4A70;
    unsigned char pad_4A71[0x5F];
    CB3TitleScreenComponent field_4AD0;
    unsigned char pad_4AD1[0x2F];
    CB3ConnectionAnimationComponent field_4B00;
    unsigned char pad_4B01[0xEF];
    CB3BuddyDisplayComponent field_4BF0;
    unsigned char pad_4BF1[0xE8F];
    CB3BuddyReadMailComponent field_5A80;
    unsigned char pad_5A81[0x29F];
    CB3RewardImageComponent field_5D20;
};

extern "C" void Construct__22CB3BackgroundComponentFv(void *);  // CB3BackgroundComponent::Construct()
extern "C" void Construct__19CB3HeadingComponentFv(void *);  // CB3HeadingComponent::Construct()
extern "C" void Construct__19CB3VSelectComponentFv(void *);  // CB3VSelectComponent::Construct()
extern "C" void Construct__19CB3HSelectComponentFv(void *);  // CB3HSelectComponent::Construct()
extern "C" void Construct__19CB3HelpBarComponentFv(void *);  // CB3HelpBarComponent::Construct()
extern "C" void Construct__17CB3VListComponentFv(void *);  // CB3VListComponent::Construct()
extern "C" void Construct__19CB3PromptsComponentFv(void *);  // CB3PromptsComponent::Construct()
extern "C" void func_00461F30(void *);
extern "C" void func_003AFFD0(void *);
extern "C" void func_003B8120(void *);
extern "C" void func_0042B470(void *);
extern "C" void func_0038AF40(void *);
extern "C" void func_0042DEC0(void *);
extern "C" void func_003A67E0(void *);
extern "C" void func_004568B0(void *);
extern "C" void func_0039C170(void *);
extern "C" void func_003BE5C0(void *);
extern "C" void func_00441D60(void *);
extern "C" void func_00449F90(void *);
extern "C" void func_00352000(void *);
extern "C" void func_0041F0B0(void *);
extern "C" void func_0039D480(void *);
extern "C" void func_00435620(void *);
extern "C" void func_0043EDE0(void *);
extern "C" void func_004538E0(void *);
extern "C" void func_00351A50(void *);
extern "C" void func_003436C0(void *);
extern "C" void Construct__24CB3ReplaySymbolComponentFv(void *);
extern "C" void func_0043DE50(void *);
extern "C" void func_00445CC0(void *);
extern "C" void func_004566D0(void *);
extern "C" void func_00460180(void *);
extern "C" void Construct__29CB3ControllerRemovedComponentFv(void *);

// 0x0030B560
void CB3MenuComponents::Construct()
{
    Construct__22CB3BackgroundComponentFv(this);
    func_00461F30(((char *)this + 0x7570));
    func_003AFFD0(((char *)this + 0x70));
    func_003B8120(((char *)this + 0x5D60));
    func_0042B470(((char *)this + 0x60C0));
    field_A60.Construct();
    func_0038AF40(((char *)this + 0xA7C));
    field_4160.Construct();
    func_0042DEC0(((char *)this + 0x61B0));
    Construct__19CB3HeadingComponentFv(((char *)this + 0xA98));
    func_003A67E0(((char *)this + 0x5B58));
    func_004568B0(((char *)this + 0x6EC0));
    Construct__19CB3VSelectComponentFv(((char *)this + 0xAC4));
    func_0039C170(((char *)this + 0xC8C));
    func_003BE5C0(((char *)this + 0xB9C));
    Construct__19CB3HSelectComponentFv(((char *)this + 0xCE8));
    Construct__19CB3HelpBarComponentFv(((char *)this + 0xD08));
    func_00441D60(((char *)this + 0xF00));
    Construct__17CB3VListComponentFv(((char *)this + 0xE30));
    field_4B00.Construct();
    func_00449F90(((char *)this + 0x68E0));
    field_49D0.Construct();
    field_4A10.Construct();
    field_5A80.Construct();
    field_4BF0.Construct();
    func_00352000(((char *)this + 0x4A30));
    field_4A70.Construct();
    func_0041F0B0(((char *)this + 0x6078));
    func_0039D480(((char *)this + 0x5AD0));
    func_00435620(((char *)this + 0x6418));
    func_0043EDE0(((char *)this + 0x6538));
    func_004538E0(((char *)this + 0x6610));
    field_5D20.Construct();
    func_00351A50(((char *)this + 0xF40));
    field_4AD0.Construct();
    func_003436C0(((char *)this + 0x4AA0));
    Construct__24CB3ReplaySymbolComponentFv(((char *)this + 0x5B3C));
    Construct__19CB3PromptsComponentFv(((char *)this + 0xD80));
    func_0043DE50(((char *)this + 0x6458));
    func_00445CC0(((char *)this + 0x6818));
    func_004566D0(((char *)this + 0x6858));
    func_00460180(((char *)this + 0x6EE0));
    field_E68.Construct();
    Construct__29CB3ControllerRemovedComponentFv(((char *)this + 0x5E20));
}
