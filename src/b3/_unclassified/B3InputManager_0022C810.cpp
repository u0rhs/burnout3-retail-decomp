// CB3InputManager::GetMenuButton(CB3MenuInput::EMenuControls,signed char) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3InputManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (hand-written method; a2 passes through to GetAvailableControllers; 12-byte button records at +0x14).

class CB3ControllerMapping;
struct CB3MenuInput {
    enum EMenuControls { EMenuControls_Unk0 };
};
class CB3InputManager {
public:
    void GetAvailableControllers(CB3ControllerMapping**, signed char);
    int GetMenuButton(CB3MenuInput::EMenuControls, signed char);
};
struct UnkStruct_0022C810_2 {
    unsigned char pad_0[0x14];
    struct { short a; short b; int c; int d; } field_14[1];
};
struct UnkStruct_0022C810_0 {
    UnkStruct_0022C810_2 * field_0[1];
    unsigned char pad_4[0x4];
};

// 0x0022C810
int CB3InputManager::GetMenuButton(CB3MenuInput::EMenuControls p0, signed char p1)
{
    UnkStruct_0022C810_0 local;
    GetAvailableControllers((CB3ControllerMapping**)&local, p1);
    for (signed char i = 0; (i < 2); i++) {
        UnkStruct_0022C810_2 * t0 = local.field_0[i];
        if (t0 == 0) {
            continue;
        }
        bool v;
        if ((int)p0 == 8) {
            v = t0->field_14[p0].b != 0;
        } else {
            v = t0->field_14[p0].a != 0;
        }
        if (v) {
            return 1;
        }
    }
    return 0;
}
