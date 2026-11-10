// CGtViewport::Destruct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtViewport.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtViewport;

class CGtViewport {
public:
    void Destruct();

    unsigned char pad_0[0x58];
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
};

extern "C" void RwRasterDestroy(int);
extern "C" void RwFrameDestroy(int);
extern "C" void _rwObjectHasFrameSetFrame(int, int);
extern "C" void RwCameraDestroy(int);

// 0x00211D70
void CGtViewport::Destruct()
{
    RwRasterDestroy(field_60);
    RwRasterDestroy(field_64);
    RwFrameDestroy(field_5C);
    _rwObjectHasFrameSetFrame(field_58, 0);
    RwCameraDestroy(field_58);
    field_60 = 0;
    field_64 = 0;
    field_58 = 0;
    field_5C = 0;
    field_68 = 0;
}
