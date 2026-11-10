// CB3TextComponent::Update(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3TextComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (if (D_01E90424==5) return idiom (N53)).

#include "b3/classes/UnkStruct_D_01E90424.h"
extern UnkStruct_D_01E90424 D_01E90424;
extern "C" void Update__16CB3TextComponentFf(void *self, float dt) { if (D_01E90424.field_0 == 5) return; }
