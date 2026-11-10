// B3HUDPrimaryMessageHandler.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 0 function(s) named in research/retail_names.csv -> B3HUDPrimaryMessageHandler.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Hud, [G] domain word `HUD` in the name: 37 of Revenge's 38 files with it are in GameSource/Hud/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

struct UnkStruct_003D5CD0 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    unsigned char pad_18[0x134];
    int field_14C;
    unsigned char pad_150[0x8];
    int field_158;
    int field_15C;
    int field_160;
};

// Prepare__27CB3HUDPrimaryMessageHandlerFP10CGt2dSceneii -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003D5CD0
extern "C" void Prepare__27CB3HUDPrimaryMessageHandlerFP10CGt2dSceneii(UnkStruct_003D5CD0 *self, void *p0_, int p1, int p2)
{
    int p0 = (int)p0_;
    self->field_C = 0;
    self->field_10 = 0;
    self->field_14 = 0;
    self->field_14C = 3;
    self->field_158 = 0;
    self->field_15C = 0;
    self->field_160 = 0;
    self->field_0 = p0;
    self->field_4 = p1;
    self->field_8 = p2;
}
