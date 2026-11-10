// CB3WrongWayWall::Render() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3WrongWayWall.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (static B3Im3d extern C callees (no this), enum 0 blend mode, bool false args, nested ifs).

class CGtTexture;
struct CB3Im3dVertex;
enum UnkEnum_B3Im3d_EBlendMode { UnkEnum_B3Im3d_EBlendMode_0 };
extern "C" void BeginRendering__6B3Im3dFv();
extern "C" void SetTexture__6B3Im3dFP10CGtTexture(CGtTexture *);
extern "C" void SetBlendMode__6B3Im3dFQ26B3Im3d10EBlendMode(UnkEnum_B3Im3d_EBlendMode);
extern "C" void SetBackfaceCull__6B3Im3dFb(bool);
extern "C" void SetZWrite__6B3Im3dFb(bool);
extern "C" void RenderTristrip__6B3Im3dFPC13CB3Im3dVertexi(const CB3Im3dVertex *, int);
extern "C" void EndRendering__6B3Im3dFv();
struct CB3WrongWayWall {
    void Render();
    unsigned char pad_0[0x1500];
    unsigned char field_1500[0xA84];
    int field_1F84;
    unsigned char pad_1F88[0x10];
    unsigned char field_1F98;
};
// 0x0019B6E0
void CB3WrongWayWall::Render()
{
    if (field_1F98 != 0) {
        if (field_1F84 > 0) {
            BeginRendering__6B3Im3dFv();
            SetTexture__6B3Im3dFP10CGtTexture(0);
            SetBlendMode__6B3Im3dFQ26B3Im3d10EBlendMode(UnkEnum_B3Im3d_EBlendMode_0);
            SetBackfaceCull__6B3Im3dFb(false);
            SetZWrite__6B3Im3dFb(false);
            RenderTristrip__6B3Im3dFPC13CB3Im3dVertexi((const CB3Im3dVertex *)field_1500, field_1F84);
            EndRendering__6B3Im3dFv();
        }
    }
}
