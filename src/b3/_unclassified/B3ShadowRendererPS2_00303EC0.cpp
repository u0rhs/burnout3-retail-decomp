// CB3ShadowRenderer::BeginShadowRendering() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ShadowRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a165 tiny).

struct UnkStruct_a165_gc { unsigned char pad_0[0x100]; int field_100; int field_104; int field_108; int field_10C; int field_110; int field_114; };
extern UnkStruct_a165_gc *_gpCache;
extern "C" void BeginShadowRendering__17CB3ShadowRendererFv(void *self) {
 _gpCache = (UnkStruct_a165_gc *)0x70002000;
 _gpCache->field_108 = 0;
 _gpCache->field_10C = 0;
 _gpCache->field_100 = ((int)_gpCache + 0x1200) & -16;
 _gpCache->field_104 = _gpCache->field_100 + 0x1000;
 _gpCache->field_110 = 0;
 _gpCache->field_114 = 0; }
