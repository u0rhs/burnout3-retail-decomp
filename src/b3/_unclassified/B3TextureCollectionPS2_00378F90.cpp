// CB3TextureCollectionPS2::AddTexture(CGtTexture*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TextureCollectionPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a173: named load local then (int)((unsigned)field_4+(unsigned)f) fixes load order and addu operands).


class CGtTexture { public: unsigned char pad_0[0x64]; int field_64; };
class CB3TextureCollectionPS2 {
public:
    void AddTexture(CGtTexture *p0);
    int field_0;
    int field_4;
    CGtTexture *field_8[1];
};
// 0x00378F90
void CB3TextureCollectionPS2::AddTexture(CGtTexture *p0)
{
    int n = field_0;
    for (int i = 0; i < n; i++) {
        if (field_8[i] == p0) return;
    }
    field_8[field_0++] = p0;
    int f = p0->field_64;
    f = (int)((unsigned)field_4 + (unsigned)f);
    field_4 = f;
}
