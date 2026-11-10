// CB3OnlineLobbyPage::SetPlayerCar(int,unsigned long,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a72: early-return arms (p1==0 text, ==-1 clear, else car icon); element arrays as members).

// CB3OnlineLobbyPage::SetPlayerCar(int,unsigned long,int) [G] hand-matched a72
class CB3OnlineLobbyPage;
struct UnkStruct_00313580_e0 {
    void * field_0;
    void * field_4;
    void * field_8;
    unsigned char pad_C[0x3C];
};
struct UnkStruct_00313580_e1 {
    unsigned long field_0;
    int field_8;
    unsigned char pad_C[0x14];
};
class CB3OnlineLobbyPage {
public:
    void SetPlayerCar(int p0, unsigned long p1, int p2);

    unsigned char pad_0[0x194];
    UnkStruct_00313580_e0 field_194[1];
    unsigned char pad_1DC[0x7D0 - 0x1DC];
    UnkStruct_00313580_e1 field_7D0[1];
    unsigned char pad_7F0[0x1390 - 0x7F0];
    int field_1390;
};
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const void *, const void *, unsigned short*, const void *, const void*);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, const void *, const void*);
extern "C" void func_0033F620(const void *, const void *, unsigned short*, const void *, const void*);
extern "C" float GetCarIconSize__17CB3TableComponentFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, const void *, const void*);

// 0x00313580
void CB3OnlineLobbyPage::SetPlayerCar(int p0, unsigned long p1, int p2)
{
    int t0 = field_1390;
    if (p0 < t0) {
        return;
    }
    if ((p0 - t0) >= 6) {
        return;
    }
    if (p1 == 0) {
        field_194[(p0 - t0)].field_0 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        field_194[(p0 - t0)].field_4 = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
        field_194[(p0 - t0)].field_8 = (char *)this + 0x320;
        return;
    }
    if (p1 == (unsigned long)-1) {
        field_194[(p0 - t0)].field_0 = 0;
        field_194[(p0 - t0)].field_4 = 0;
        return;
    }
        field_194[(p0 - t0)].field_0 = (void *)&func_0033F620;
        field_194[(p0 - t0)].field_4 = (void *)&GetCarIconSize__17CB3TableComponentFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
        field_194[(p0 - t0)].field_8 = &field_7D0[(p0 - t0)];
        field_7D0[(p0 - t0)].field_0 = p1;
        field_7D0[(p0 - t0)].field_8 = p2;
}
