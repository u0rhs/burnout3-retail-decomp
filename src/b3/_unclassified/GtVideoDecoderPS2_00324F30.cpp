// CGtVideoDecoder::SetExternalSync(float) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtVideoDecoderPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). The class is declared here with only what this function
// needs; field names are placeholders and their types are [G] from the instruction widths.

class CGtVideoDecoder {
public:
    void SetExternalSync(float p0);

    unsigned char pad_0[0x3C];
    float field_3C;
};

// 0x00324F30
void CGtVideoDecoder::SetExternalSync(float p0)
{
    field_3C = p0;
}
