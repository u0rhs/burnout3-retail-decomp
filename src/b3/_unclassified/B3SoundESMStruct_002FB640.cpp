// CB3SoundESMGraphStruct::Update(const CB3SoundESMGraphInputs&,CB3SoundEsmGraphOutputs&) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESMStruct.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (s323: CalcVolumeOutput sibling shape (nested ternary clamp, && break loop, 0.0f+y0+v*dy)).

// Hand-written (s323): clone of CB3SoundSkidModelGraph::CalcVolumeOutput (B3SoundSkidModel_0028E120.cpp) -- nested-ternary clamp, && break search, 0.0f != d, 0.0f + y0 + v*(y1-y0).
class CB3SoundESMGraphInputs { public: float field_0[7]; };
class CB3SoundEsmGraphOutputs { public: float field_0[20]; };
struct UnkStruct_es_pt { float field_0; float field_4; };
class CB3SoundESMGraphStruct {
public:
    void Update(const CB3SoundESMGraphInputs &in, CB3SoundEsmGraphOutputs &out) const;
    UnkStruct_es_pt *field_0;
    unsigned char field_4;
    signed char field_5;
    signed char field_6;
};

// 0x002FB640
void CB3SoundESMGraphStruct::Update(const CB3SoundESMGraphInputs &in, CB3SoundEsmGraphOutputs &out) const
{
    float p0 = in.field_0[field_5];
    float lo = field_0[0].field_0;
    float hi = field_0[field_4 - 1].field_0;
    float t = p0 < lo ? lo : (p0 > hi ? hi : p0);
    int i;
    for (i = 0; i < field_4 - 1; i++) {
        if (t >= field_0[i].field_0 && t < field_0[i + 1].field_0) {
            break;
        }
    }
    float d = field_0[i + 1].field_0 - field_0[i].field_0;
    float r;
    if (0.0f != d) {
        float v = (t - field_0[i].field_0) / d;
        float y0 = field_0[i].field_4;
        float y1 = field_0[i + 1].field_4;
        r = 0.0f + y0 + v * (y1 - y0);
    } else {
        r = field_0[i].field_4;
    }
    if (field_6 == 0) {
        out.field_0[field_6] *= r;
    } else {
        out.field_0[field_6] = r;
    }
}
