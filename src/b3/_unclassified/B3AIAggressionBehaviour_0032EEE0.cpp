// CB3AIAggressionBehaviour::DoAggressiveHornBlast(EAggressiveHornBlashReason) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAggressionBehaviour.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// CB3AIAggressionBehaviour has a header in include/ (pads and a few proven fields only): declared locally instead, as the
// hand-matched units of such classes do (B3AITarget_00149140.cpp) [lift3].
// Hand-finished from the lifted source (lit4fix: .lit4 externs as literals).


#include "b3/_unclassified/GtRandom.h"
enum EAggressiveHornBlashReason {};
struct UnkStruct_D_float { float field_0; };
struct UnkStruct_HornOwner { unsigned char pad_0[0x18ED]; unsigned char field_18ED; };
extern CGtRandom _gAggressiveHornRandom;
extern int _gnHornPattern;
extern unsigned int _kaxHornPatterns[];
class CB3AIAggressionBehaviour {
public:
    void DoAggressiveHornBlast(EAggressiveHornBlashReason);
    unsigned char pad_0[0x44];
    UnkStruct_HornOwner * field_44;
    unsigned char pad_48[0x4];
    float field_4C;
    float field_50;
    unsigned int field_54;
    unsigned char field_58;
};
// 0x0032EEE0
void CB3AIAggressionBehaviour::DoAggressiveHornBlast(EAggressiveHornBlashReason p0)
{
    if (field_58 == 0 && field_4C <= 0.0f) {
        const float k = 2.3283064e-10f;
        if (p0 == 1) {
            if (k * (float)_gAggressiveHornRandom.Random() < 0.5f) {
                return;
            }
        }
        if (p0 == 0) {
            if (k * (float)_gAggressiveHornRandom.Random() < 0.1f) {
                return;
            }
        }
        int pat = _gnHornPattern;
        unsigned int bits = _kaxHornPatterns[pat];
        _gnHornPattern = (pat + 1) & 0xF;
        float r = k * (float)_gAggressiveHornRandom.Random();
        field_4C = 0.5f + 2.5f * r;
        field_50 = 0.05f;
        field_54 = bits;
        field_58 = 1;
    }
}
