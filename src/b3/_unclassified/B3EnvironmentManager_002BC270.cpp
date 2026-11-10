// CB3EnvironmentManager::RenderClouds() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EnvironmentManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a165 early return).

extern "C" void BeginRender__18CB3SkyDomeRendererFv(void);
extern "C" void RenderComponent__18CB3SkyDomeRendererFQ222CB3SkyDomeRendererBase13ESkyComponent(int);
extern "C" void EndRender__18CB3SkyDomeRendererFv(void);
struct UnkStruct_a165_em { unsigned char pad_0[0x14C]; unsigned char field_14C; };
extern "C" void RenderClouds__21CB3EnvironmentManagerFv(UnkStruct_a165_em *self) {
 if (self->field_14C == 0) return;
  BeginRender__18CB3SkyDomeRendererFv();
  RenderComponent__18CB3SkyDomeRendererFQ222CB3SkyDomeRendererBase13ESkyComponent(2);
  EndRender__18CB3SkyDomeRendererFv(); }
