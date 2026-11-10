// CB3HUDScore::ShowScore(CB3HUDScore::EScoreEvent,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDScore.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (slot=(int*)((p0<<2)+(int)this+0xDC); compare uses 3.87f literal (lit4->D_004E0940 retarget), store uses global).

extern float D_004E0924;
extern float D_004E0940;
extern float D_004E0944;
class CB3HUDScore {
public:
    enum EScoreEvent {};
    void ShowScore(EScoreEvent p0, int p1);

    unsigned char pad_0[0xDC];
    int field_DC[2];  // [G] element count
    int field_E4;
    unsigned char pad_E8[0x28];
    float field_110;
    unsigned char pad_114[0x2A];
    unsigned char field_13E;
};

// 0x001A2030
void CB3HUDScore::ShowScore(EScoreEvent p0, int p1)
{
    if (field_13E != 0) {
        int * slot = (int *)((p0 << 2) + (int)this + 0xDC);
        if (*slot != p1) {
            float t = field_110;
            if (t < 0.0f) {
                field_110 = D_004E0944;
            } else if (t < D_004E0924) {
                field_110 = D_004E0940 + D_004E0924 * ((D_004E0924 - t) / D_004E0924);
            } else {
                if (t < 3.87f) {
                    field_110 = D_004E0940;
                }
            }
            *slot = p1;
            field_E4 = 0;
            for (int i = 0; i < 2; i++) {
                field_E4 = field_E4 + field_DC[i];
            }
        }
    }
}
