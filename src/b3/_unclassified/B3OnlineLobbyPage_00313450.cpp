// CB3OnlineLobbyPage::SetPlayerLatency(int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (GetConnectionSize (not func_0033F400) at +0x3C; unions v0..v2 (v2 0x40) for frame; row ptr (off+(unsigned)this); zero/one/else-if chain order).

// CB3OnlineLobbyPage::SetPlayerLatency(int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3OnlineLobbyPage;
struct UnkStruct_00313450_3;
struct UnkStruct_00313450_e0;
struct UnkStruct_00313450_e1;
struct UnkStruct_00313450_e2;
struct UnkStruct_D_004E0A40;
struct UnkStruct_D_01E90240;
struct UnkStruct_func_0033F400;

struct UnkStruct_00313450_e0 {
    unsigned char pad_0[0x38];
    void * field_38;
    void * field_3C;
    unsigned char pad_40[0x8];
};

struct UnkStruct_00313450_e1 {
    unsigned char pad_0[0x18];
    int field_18;
    unsigned char pad_1C[0x34];
};

struct UnkStruct_00313450_3 {
    float field_0;
    float field_4;
    int field_8;
    float field_C;
    float field_10;
    int field_14;
    int field_18;
    float field_1C;
    int field_20;
    int field_24;
    int field_28;
    float field_2C;
    unsigned char pad_30[0x30];
};

struct UnkStruct_00313450_e2 {
    unsigned char pad_0[0x20];
    u_long128 field_20;
    unsigned char pad_30[0x20];
};

struct UnkStruct_D_004E0A40 {
    float field_0;
};

struct UnkStruct_D_01E90240 {
    u_long128 field_0;
};

struct UnkStruct_func_0033F400 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00313450_row {
    unsigned char pad_0[0xF20];
    u_long128 field_F20;
    unsigned char pad_F30[0x38];
    int field_F68;
};
union UnkUnion_00313450_vbig {
    float f[4];
    int i[4];
    u_long128 q;
    unsigned char pad[0x40];
};
union UnkUnion_00313450_v {
    float f[4];
    int i[4];
    u_long128 q;
};
class CB3OnlineLobbyPage {
public:
    void SetPlayerLatency(int p0, int p1);

    unsigned char pad_0[0x168];
    UnkStruct_00313450_e0 field_168[1];
    unsigned char pad_1B0[0x1390 - 0x1B0];
    int field_1390;
};

extern UnkStruct_D_004E0A40 D_004E0A40;
extern UnkStruct_D_01E90240 D_01E90240;
extern "C" void GetConnectionSize__17CB3TableComponentFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *);

extern "C" void RenderConnection__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const void *, const void *, unsigned short*, const void *, const void*);  // CB3TableComponent::RenderConnection(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,unsigned short*,const CGt2dFrame&,const void*), its address taken

// 0x00313450
void CB3OnlineLobbyPage::SetPlayerLatency(int p0, int p1)
{
    UnkUnion_00313450_vbig v2;
    UnkUnion_00313450_v v1;
    UnkUnion_00313450_v v0;
    int t0 = field_1390;
    if (p0 >= t0) {
        int k = p0 - t0;
        if (k <= 5) {
            if (p1 > -1) {
                field_168[k].field_38 = (void *)&RenderConnection__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                field_168[k].field_3C = (void *)&GetConnectionSize__17CB3TableComponentFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
            } else {
                field_168[k].field_38 = 0;
                field_168[k].field_3C = 0;
            }
            unsigned int off = k * 0x50;
            UnkStruct_00313450_row *e = (UnkStruct_00313450_row *)(off + (unsigned int)this);
            e->field_F68 = p1;
            if (p1 <= 0) {
                v2.i[0] = 0;
                v2.f[3] = 1.0f;
                v2.i[1] = 0;
                v2.i[2] = 0;
                e->field_F20 = v2.q;
            } else if (p1 >= 2) {
                    if (p1 <= 3) {
                        float t1 = D_004E0A40.field_0;
                        v0.i[2] = 0;
                        v0.f[3] = 1.0f;
                        v0.f[0] = t1;
                        v0.f[1] = t1;
                        e->field_F20 = v0.q;
                    } else {
                        e->field_F20 = D_01E90240.field_0;
                    }
            } else {
                    float t2 = D_004E0A40.field_0;
                    v1.f[0] = t2;
                    v1.i[1] = 0;
                    v1.i[2] = 0;
                    v1.f[3] = 1.0f;
                    e->field_F20 = v1.q;
            }
            return;
        }
        return;
    }
}
