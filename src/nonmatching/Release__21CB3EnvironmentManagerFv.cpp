// NONMATCHING: Release__21CB3EnvironmentManagerFv -- retail 43 / ours 43 instructions, 2 in changed runs
// near17: really 2 off under today's header: retail's li v1,24 sits after Normalise's sq 0x80; ours schedules it into the qmfc2->sq gap because the header Normalise stores mData = t after its .set reorder (header gap; field_140 placements, k locals, copies tried)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// CB3EnvironmentManager::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EnvironmentManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CB3EnvironmentManager;
class CB3SkyDomeRenderer;

class CB3SkyDomeRenderer {
public:
    static void Release();
};

class CB3EnvironmentManager {
public:
    void Release();

    unsigned char pad_0[0x80];
    GtMathPs2::CGtV3d field_80;
    unsigned char pad_90[0x20];
    GtMathPs2::CGtV3d field_B0;
    unsigned char pad_C0[0x30];
    u_long128 field_F0;
    unsigned char pad_100[0x3C];
    unsigned char field_13C;
    unsigned char pad_13D[0x3];
    int field_140;
    unsigned char pad_144[0x8];
    unsigned char field_14C;
};

extern "C" void Release__14CB3SunRendererFv(void *);  // CB3SunRenderer::Release()

// 0x002BC970
void CB3EnvironmentManager::Release()
{
    if (field_13C != 0) {
        Release__14CB3SunRendererFv(this);
    }
    CB3SkyDomeRenderer::Release();
    field_14C = 0;
    field_13C = 0;
    field_80.SetX(1.0f);
    field_80.SetY(1.0f);
    field_80.SetZ(1.0f);
    field_80.Normalise();
    field_B0 = field_80;
    field_F0 = field_80.mData;
    field_140 = 24;
}


