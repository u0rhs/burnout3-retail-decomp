// CB3GraphicsManager::SetVideoModeParams(RwSkyVideoMode*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3GraphicsManagerPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (switch 0/1/2 (reverse test order), uninit a2/v1 locals for default).

class RwSkyVideoMode {
public:
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    unsigned char field_30;
    unsigned char field_31;
    unsigned char field_32;
    unsigned char field_33;
};

class CB3GraphicsManager {
public:
    void SetVideoModeParams(RwSkyVideoMode *);

    int field_0;
    int field_4;
    int field_8;
    unsigned char pad_C[2];
    unsigned char field_E;
    unsigned char pad_F[0x3B8 - 0xF];
    int field_3B8;
    int field_3BC;
    int field_3C0;
    int field_3C4;
    unsigned char pad_3C8[0x424 - 0x3C8];
    int field_424;
    int field_428;
};

// 0x00227A20
void CB3GraphicsManager::SetVideoModeParams(RwSkyVideoMode *p0)
{
    int a2;
    unsigned char v1;
    switch (field_3B8) {
    case 0:
        field_424 = 8;
        field_428 = 0;
        field_0 = 0x280;
        field_4 = 0x1C0;
        field_8 = 0x20;
        field_3BC = 0x280;
        field_3C0 = 0x1C0;
        field_3C4 = 0x10;
        field_E = 0;
        a2 = 0x103;
        v1 = 2;
        break;
    case 1:
        field_424 = 8;
        field_428 = 0;
        field_0 = 0x280;
        field_4 = 0x1C0;
        field_8 = 0x20;
        field_3BC = 0x280;
        field_3C0 = 0x1E0;
        field_3C4 = 0x10;
        field_E = 0;
        a2 = 1;
        v1 = 0x50;
        break;
    case 2:
        field_424 = 8;
        field_428 = 0;
        field_0 = 0x280;
        field_4 = 0x200;
        field_8 = 0x20;
        field_3BC = 0x280;
        field_3C0 = 0x200;
        field_3C4 = 0x10;
        field_E = 1;
        a2 = 0x103;
        v1 = 3;
        break;
    }
    p0->field_0 = field_0;
    p0->field_4 = field_4;
    p0->field_8 = field_8;
    p0->field_C = 0;
    p0->field_14 = 0x500;
    p0->field_18 = field_3BC;
    p0->field_1C = field_3C0;
    p0->field_20 = field_3C4;
    p0->field_24 = a2;
    p0->field_2C = 0x100;
    p0->field_30 = 1;
    p0->field_31 = 1;
    p0->field_32 = v1;
    p0->field_33 = 0;
}
