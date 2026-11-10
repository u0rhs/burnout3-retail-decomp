// CB3OnlineLobbyPage::SetPlayerHeadsetStatus(int,unsigned char) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (else-if chain with the (p1&1) arm before the plain else).

// lifter variant 0
// CB3OnlineLobbyPage::SetPlayerHeadsetStatus(int,unsigned char) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3OnlineLobbyPage;
struct UnkStruct_00313650_e0;
struct UnkStruct_00313650_e1;

struct UnkStruct_00313650_e0 {
    unsigned char pad_0[0x20];
    void * field_20;
    void * field_24;
    void * field_28;
    unsigned char pad_2C[0x1C];
};

struct UnkStruct_00313650_e1 {
    unsigned char pad_0[0xC0];
};

class CB3OnlineLobbyPage {
public:
    void SetPlayerHeadsetStatus(int p0, unsigned char p1);

    UnkStruct_00313650_e1 field_0[1];  // [G] element count unknown
    unsigned char pad_C0[0xA8];
    UnkStruct_00313650_e0 field_168[1];  // [G] element count unknown
    unsigned char pad_1B0[0x11E0];
    int field_1390;
};

extern "C" void RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const void *, const void *, unsigned short*, const void *, const void*);  // CGt2dObjectTable::RenderImage(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,unsigned short*,const CGt2dFrame&,const void*), its address taken
extern "C" void GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, const void *, const void*);  // CGt2dObjectTable::GetImageSize(GtMathPs2::CGtV2d*,const CGt2dFrame&,const void*), its address taken

// 0x00313650
void CB3OnlineLobbyPage::SetPlayerHeadsetStatus(int p0, unsigned char p1)
{
    int t0 = field_1390;
    if (p0 < t0) {
        return;
    }
    if ((p0 - t0) >= 6) {
        return;
    }
    if (((p1 & 255) & 4) != 0) {
        field_168[(p0 - t0)].field_20 = (void *)&RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        field_168[(p0 - t0)].field_24 = (void *)&GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
        field_168[(p0 - t0)].field_28 = ((char *)&field_0[(p0 - t0)] + 0xA10);
    } else if (((p1 & 255) & 2) != 0) {
        field_168[(p0 - t0)].field_20 = (void *)&RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        field_168[(p0 - t0)].field_24 = (void *)&GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
        field_168[(p0 - t0)].field_28 = ((char *)&field_0[(p0 - t0)] + 0xA50);
    } else if (((p1 & 255) & 1) != 0) {
        field_168[(p0 - t0)].field_20 = (void *)&RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        field_168[(p0 - t0)].field_24 = (void *)&GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
        field_168[(p0 - t0)].field_28 = ((char *)&field_0[(p0 - t0)] + 0xA90);
    } else {
        field_168[(p0 - t0)].field_20 = 0;
        field_168[(p0 - t0)].field_24 = 0;
        field_168[(p0 - t0)].field_28 = ((char *)&field_0[(p0 - t0)] + 0xA10);
    }
}
