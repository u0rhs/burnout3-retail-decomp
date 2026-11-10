// CB3AIAggressionBehaviour::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAggressionBehaviour.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a165 tiny).

struct UnkStruct_a165_rnd { int field_0; int field_4; };
extern UnkStruct_a165_rnd _gAggressiveHornRandom;
extern unsigned char _gbAggressiveHornRandomInit;
extern "C" void Construct__24CB3AIAggressionBehaviourFv(void *self) {
 if (_gbAggressiveHornRandomInit == 0) { _gAggressiveHornRandom.field_4 = 0x2B9D6F8; _gAggressiveHornRandom.field_0 = 0xFD462907; _gbAggressiveHornRandomInit = 1; } }
