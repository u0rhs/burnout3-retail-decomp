// CB3SoundDSPDataBlock::SetParam(int,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundDSPBlock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (if-chain returns, switch(field_70) case 1, 2pi fixed-point via long mult).

class CB3SoundDSPDataBlock {
public:
    void SetParam(int, float);
    int field_0[1];
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    unsigned char pad_14[0x34];
    int field_48;
    unsigned char pad_4C[0x24];
    int field_70;
};
// 0x002FBCD0
void CB3SoundDSPDataBlock::SetParam(int idx, float val)
{
    float k = 65536.0f;
    int v = (int)(k * val);
    if (field_70 == 1) {
        if (idx == 3) return;
        if (idx == 4) return;
        if (idx == 5) return;
        if (idx == 6) return;
    }
    field_0[idx] = v;
    switch (field_70) {
    case 1:
        if (idx == 1) {
            float q = (float)field_4 / k / (float)field_48;
    int a = (int)(q * k);
            field_C = (int)(((long)a * 411774) >> 16);
        }
        if (idx == 2) {
            float q2 = k / (float)field_8;
            field_10 = (int)(q2 * k);
        }
        break;
    }
}
