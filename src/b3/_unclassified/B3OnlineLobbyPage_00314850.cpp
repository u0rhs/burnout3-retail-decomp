// CB3OnlineLobbyPage::UpdateLatency() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (latency in its own float temp; slot count as a static inline placeholder (i declared before n), if/else-if tail).

// lifter variant 0
// CB3OnlineLobbyPage::UpdateLatency() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3OnlineLobbyPage;
class CGtNetworkPlayerManager;
struct UnkStruct_00314850_1;
struct UnkStruct_D_01E32B08;

class CGtNetworkPlayerManager {
public:
    int GetMyPlayerIndex() const;

    unsigned char pad_0[0x8];
    int field_8[1];  // [G] element count unknown
    unsigned char pad_C[0x4];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32B08 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00314850_1 {
    unsigned char pad_0[0x5C4];
    float field_5C4;
};

class CB3OnlineLobbyPage {
public:
    void UpdateLatency();
    void SetPlayerLatency(int, int);

    unsigned char pad_0[0x138C];
    int field_138C;
};

extern UnkStruct_D_01E32B08 D_01E32B08;
extern CGtNetworkPlayerManager D_01E32AE0;

extern "C" UnkStruct_00314850_1 * func_002366D0(void *, int);

// [G] placeholder: an inlined count of the network player slots in use
static inline int func_00314850_inl1()
{
    int i;
    int n = 0;
    for (i = 0; i < D_01E32B08.field_0; i++) {
        if (D_01E32AE0.field_8[i] != 0) {
            n++;
        }
    }
    return n;
}

// 0x00314850
void CB3OnlineLobbyPage::UpdateLatency()
{
    int t0 = D_01E32B08.field_0;
    float m0 = 0.0f;
    for (int i = 0; i < t0; i++) {
        UnkStruct_00314850_1 * r0 = func_002366D0(&D_01E32AE0, i);
        if (r0 != 0) {
            float v0 = r0->field_5C4;
            if (!(v0 <= 500.0f)) {
                v0 = 500.0f;
            }
            if (v0 < 60.0f) {
                v0 = 60.0f;
            }
            float lat = 4.0f * ((500.0f - v0) / 440.0f);
            m0 += lat;
            SetPlayerLatency(i, (int)lat);
        }
    }
    if (func_00314850_inl1() > 0) {
        SetPlayerLatency(field_138C, (int)(m0 / (float)func_00314850_inl1()));
    } else if (D_01E32AE0.GetMyPlayerIndex() > -1) {
        SetPlayerLatency(field_138C, -1);
    }
}
