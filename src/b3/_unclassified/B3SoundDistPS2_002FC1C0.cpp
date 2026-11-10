// CB3SoundDistortion::GetDSPSends(CGtSoundRealVoiceDSPSend**,int*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundDistPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (a165 tiny).

struct UnkStruct_D_01E86D60 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E86D60 D_01E86D60;
extern "C" void GetDSPSends__18CB3SoundDistortionFPP24CGtSoundRealVoiceDSPSendPi(void *self, UnkStruct_D_01E86D60 **p0, int *p1) { *p0 = &D_01E86D60; *p1 = 2; }
