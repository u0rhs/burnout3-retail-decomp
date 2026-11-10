// CB3CameraUtils::GetOppositeSide(EAISegmentLinkType) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CameraUtils.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a165 enum return).

enum EAISegmentLinkType { E0, E1 };
extern "C" EAISegmentLinkType GetOppositeSide__14CB3CameraUtilsF18EAISegmentLinkType(EAISegmentLinkType a) { return a == E0 ? E1 : E0; }
