// CB3GraphicsManagerBase::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3GraphicsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (near6: reuse the t1 local for the field_30 reload (range-split FP numbering)).


// lifter variant 0
// CB3GraphicsManagerBase::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3GraphicsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3GraphicsManagerBase;
class CGtScreenCentre;
struct UnkStruct_0019EB60_1;

class CGtScreenCentre {
public:
    void MoveScreen(float, float);
};

struct P2 { float x; float y; };
struct UnkStruct_0019EB60_1 { float field_0; float field_4; };

class CB3GraphicsManagerBase {
public:
    void Update();

    unsigned char pad_0[0x1C];
    CGtScreenCentre field_1C;
    unsigned char pad_1D[0x13];
    float field_30;
    float field_34;
    float field_38;
    float field_3C;
};

// 0x0019EB60
void CB3GraphicsManagerBase::Update()
{
    P2 cp; UnkStruct_0019EB60_1 local;
    float t0 = field_38;
    float t1 = field_30;
    if (!(t1 == t0) || !(field_34 == field_3C)) {
    local.field_0 = (t1 - t0);
    local.field_4 = (field_34 - field_3C);
    *(unsigned long *)&cp = *(unsigned long *)&local;
    field_1C.MoveScreen(cp.x, cp.y);
    t1 = field_30;
    float t2 = field_34;
    field_38 = t1;
    field_3C = t2;
    }
}
