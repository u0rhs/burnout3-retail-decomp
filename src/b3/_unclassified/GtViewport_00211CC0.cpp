// CGtViewport::SetFOV(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtViewport.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (tanf takes one float (phantom this dropped); .lit4 pi/180 as 0.017453292f; both reciprocals computed into temps before the stores).

// CGtViewport::SetFOV(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtViewport.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtViewport;

class CGtViewport {
public:
    void SetFOV(float p0);

    unsigned char pad_0[0x48];
    float field_48;
    float field_4C;
    float field_50;
    float field_54;
    int field_58;
    unsigned char pad_5C[0x10];
    float field_6C;
    float field_70;
    float field_74;
};


extern "C" float tanf(float);
extern "C" void RwCameraSetViewWindow(int, void *);

// 0x00211CC0
void CGtViewport::SetFOV(float p0)
{
    field_48 = field_70 * tanf(0.017453292f * (0.5f * p0));
    field_4C = field_48 / field_74;
    float a = 1.0f / field_48;
    float b = 1.0f / field_4C;
    field_50 = a;
    field_54 = b;
    RwCameraSetViewWindow(field_58, ((char *)this + 0x48));
    field_6C = p0;
}
