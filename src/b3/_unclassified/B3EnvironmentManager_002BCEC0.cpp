// CB3EnvironmentManager::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EnvironmentManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (lifted source exact with the current header (SetX/Y/Z(1.0f) + Normalise)).

// CB3EnvironmentManager::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EnvironmentManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CB3EnvironmentManager;
class CB3SunRenderer;

class CB3SunRenderer {
public:
    static void Construct();
};

class CB3EnvironmentManager {
public:
    void Construct();

    unsigned char pad_0[0x80];
    GtMathPs2::CGtV3d field_80;
    unsigned char pad_90[0xA0];
    int field_130;
    unsigned char pad_134[0xC];
    int field_140;
    unsigned char pad_144[0x4];
    int field_148;
};

extern "C" void Construct__18CB3SkyDomeRendererFv(void *);  // CB3SkyDomeRenderer::Construct()

// 0x002BCEC0
void CB3EnvironmentManager::Construct()
{
    Construct__18CB3SkyDomeRendererFv(this);
    CB3SunRenderer::Construct();
    field_140 = 1;
    field_148 = 0;
    field_130 = -1;
    field_80.SetX(1.0f);
    field_80.SetY(1.0f);
    field_80.SetZ(1.0f);
    field_80.Normalise();
}
