// NONMATCHING: MessagesUpdate__14CB3HUDBoostBarFf -- retail 270 / ours 270 instructions, 82 in changed runs
// 82 instrs: logic/calls right; retail moves the y<lim clamp block out of line to the end (goto form gets 77), CGtV2d temporaries' stack slots differ, f-register colouring in the loop head
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3HUDBoostBar::MessagesUpdate(float) -- hand-written (fresh6) from the retail asm and the layout of the proven sibling
// CB3HUDBoostBar::UpdateBoostMessage (B3HUDBoostBar_001A45F0.cpp). [C] name: the mangled symbol. Every type is [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_001A41B0_msg;
class CB3ScoreCategory { public: unsigned char pad_0[0x14]; };
struct UnkStruct_001A41B0_row { unsigned char pad_0[0x14]; unsigned char field_14[0x5C]; };
struct UnkStruct_001A41B0_obj {
    CGtV2d field_0;
    CGtV2d field_8;
    CGtV4d field_10;
};
struct UnkStruct_001A41B0_msg {
    UnkStruct_001A41B0_obj *field_0;
    const unsigned short *field_4;
    float field_8;
    float field_C;
    float field_10;
    UnkStruct_001A41B0_msg *field_14;
    signed char field_18;
    unsigned char pad_19[0x3];
    float field_1C;
    float field_20;
    float field_24;
};
struct UnkStruct_001A41B0_score {
    unsigned char pad_0[0x374];
    CB3ScoreCategory field_374;
    unsigned char pad_388[0x8];
    CB3ScoreCategory field_390;
    unsigned char pad_3A4[0x74];
    CB3ScoreCategory field_418;
    unsigned char pad_42C[0x138];
    CB3ScoreCategory field_564;
    unsigned char pad_578[0x20];
    CB3ScoreCategory field_598;
    unsigned char pad_5AC[0x18];
    CB3ScoreCategory field_5C4;
};
struct UnkStruct_F16 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_V2_16 { CGtV2d field_0; unsigned char pad_8[0x8]; };
class CB3HUDSoundManager { public: void GeneralPopup(); unsigned char pad_0[0x10]; };

extern UnkStruct_F16 krHUDBoostBarMessageIndentX;
extern UnkStruct_V2_16 D_004B7940;
extern CB3HUDSoundManager D_01E7A800;

extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);

class CB3HUDBoostBar {
public:
    enum EMessageType { EMT_0, EMT_1, EMT_2 };
    bool UpdateBoostMessage(EMessageType p0, const CB3ScoreCategory *p1, float p2, float p3);
    void MessagesUpdate(float dt);

    unsigned char pad_0[0x4];
    UnkStruct_001A41B0_row *field_4;
    void *field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x54F];
    float field_56C;
    unsigned char pad_570[0x118];
    UnkStruct_001A41B0_msg *field_688;
    UnkStruct_001A41B0_score *field_68C;
};

// [G] inlined CGtV2d setter taking its value by copy (no name known; retail's 8-byte ld/sd copy then lwc1/swc1)
static inline void func_001A41B0_inl1(CGtV2d &d, CGtV2d v)
{
    d.marValues[0] = v.marValues[0];
    d.marValues[1] = v.marValues[1];
}

// 0x001A41B0
void CB3HUDBoostBar::MessagesUpdate(float dt)
{
    bool any = false;
    if (UpdateBoostMessage((EMessageType)0, &field_68C->field_374, dt, 100.0f)) any = true;
    if (UpdateBoostMessage((EMessageType)1, &field_68C->field_390, dt, 0.0f)) any = true;
    if (UpdateBoostMessage((EMessageType)2, &field_68C->field_418, dt, 0.0f)) any = true;
    if (UpdateBoostMessage((EMessageType)4, &field_68C->field_598, dt, 1.0f)) any = true;
    if (UpdateBoostMessage((EMessageType)5, &field_68C->field_5C4, dt, 1.0f)) any = true;
    if (UpdateBoostMessage((EMessageType)6, &field_68C->field_564, dt, 1.0f)) any = true;
    float step = 300.0f * dt;
    float top = field_56C - 26.0f;
    float lim = top - 26.0f;
    CGtV4d col;
    col = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
    if (any) D_01E7A800.GeneralPopup();
    float indent = krHUDBoostBarMessageIndentX.field_0;
    UnkStruct_001A41B0_msg *m = field_688;
    UnkStruct_001A41B0_msg *prev = 0;
    while (m != 0) {
        CGtV2d off(0.0f, 0.0f);
        float a = 1.0f;
        float t = m->field_8 - dt;
        m->field_8 = t;
        if (t < 0.0f) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(field_4[field_1C].field_14, field_10, m->field_0);
            m->field_0 = 0;
            if (prev != 0) {
                prev->field_14 = m->field_14;
            } else {
                field_688 = m->field_14;
            }
            m->field_14 = 0;
            m->field_18 = -1;
            m->field_1C = 1.0f;
            m->field_20 = 0.0f;
            m->field_24 = 0.0f;
        } else {
            if (t < 0.25f) {
                float q = t / 0.25f;
                off = D_004B7940.field_0 * (-0.05000000075f * (1.0f - q));
                a = q;
            } else if (t >= m->field_C) {
                off = D_004B7940.field_0 * ((t - m->field_C) / 0.150000006f) * 0.05000000075f;
            }
            col.SetA(a);
            m->field_0->field_10 = col;
            func_001A41B0_inl1(m->field_0->field_8, D_004B7940.field_0 + off * 2.0f);
            float y = GtMath::Min(m->field_10, top);
            if (y < lim) {
                y = GtMath::Min(y + step, lim);
            } else if (y > lim) {
                y = GtMath::Max(y - step, lim);
            }
            func_001A41B0_inl1(m->field_0->field_0, CGtV2d(indent - off.marValues[0], y - off.marValues[1]));
            prev = m;
            lim -= 26.0f;
            top -= 26.0f;
            m->field_10 = y;
        }
        m = m->field_14;
    }
}
