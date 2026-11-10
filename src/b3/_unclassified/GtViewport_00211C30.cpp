// CGtViewport::SetSubRaster(CGtViewport*,RwRect*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtViewport.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (raster fields typed RwRaster* (null-tested pointer, not int)).

class CGtViewport;
struct RwRect;
struct RwRaster;

struct RwRect {
    unsigned char pad_0[0x8];
    int field_8;
    int field_C;
};

class CGtViewport {
public:
    void SetSubRaster(CGtViewport* p0, RwRect* p1);

    unsigned char pad_0[0x60];
    RwRaster *field_60;
    RwRaster *field_64;
    unsigned char pad_68[0x10];
    int field_78;
    int field_7C;
    int field_80;
};

extern "C" RwRaster *RwRasterSubRaster(RwRaster *, RwRaster *, RwRect *);

// 0x00211C30
void CGtViewport::SetSubRaster(CGtViewport* p0, RwRect* p1)
{
    RwRasterSubRaster(field_60, p0->field_60, p1);
    if (p0->field_64) {
        RwRasterSubRaster(field_64, p0->field_64, p1);
    }
    field_78 = p1->field_8;
    field_7C = p1->field_C;
    field_80 = p0->field_80;
}
