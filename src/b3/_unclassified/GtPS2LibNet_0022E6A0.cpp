// CGtPS2LibNet::SetNetworkConfigFileLocation(const char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtPS2LibNet.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (tiny extern C).

extern "C" char *strncpy(char*, const char*, unsigned);
extern "C" void SetNetworkConfigFileLocation__12CGtPS2LibNetFPCc(char *self, const char *s) { strncpy(self + 0x6E4, s, 0x20); }
