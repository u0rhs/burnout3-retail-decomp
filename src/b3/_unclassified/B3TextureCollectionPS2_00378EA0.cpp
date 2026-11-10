// CB3TextureCollectionPS2::Upload() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TextureCollectionPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (first entry field via &ent[0].field_4 + idx*0x80 byte pun (second via subscript) stops CSE of the two entry addresses).

class CGtTexture;
enum EGtTextureCachePS2_FilterMode { UnkEnum_0 = 0, UnkEnum_1 = 1 };
struct UnkStruct_Ent { int field_0; int field_4; unsigned char pad_8[0x78]; };
class CGtTextureCache {
public:
    void AccessTexture(CGtTexture *, float, EGtTextureCachePS2_FilterMode, bool, bool);
    void ForceBufferSwap();
    unsigned char pad_0[0xC0];
    UnkStruct_Ent ent[2];
    int field_1C0;
    unsigned char pad_1C4[0x14];
    int field_1D8;
    unsigned char pad_1DC[0x8];
    int field_1E4;
};
extern CGtTextureCache gTextureCache;
class CB3TextureCollectionPS2 {
public:
    void Upload();
    int field_0;
    int field_4;
    CGtTexture *field_8[1];
};
// 0x00378EA0
void CB3TextureCollectionPS2::Upload()
{
    int idx = gTextureCache.field_1C0;
    if (gTextureCache.field_1D8 - *(int *)((char *)&gTextureCache.ent[0].field_4 + idx * 0x80) < field_4 ||
        gTextureCache.field_1E4 - gTextureCache.ent[idx].field_0 < field_0) {
        gTextureCache.ForceBufferSwap();
    }
    for (int i = 0; i < field_0; i++) {
        gTextureCache.AccessTexture(field_8[i], 0.0f, UnkEnum_1, false, true);
    }
}
