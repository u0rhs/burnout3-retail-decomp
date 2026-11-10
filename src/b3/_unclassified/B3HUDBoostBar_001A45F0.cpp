// CB3HUDBoostBar::UpdateBoostMessage(CB3HUDBoostBar::EMessageType,const CB3ScoreCategory*,float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3HUDBoostBar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (from scratch; signed char t0, int pr=t0; size global as CGtV2d wrapper; obj loaded before GetStringWidth).

#include "b3/GtMathPs2.h"

class CGt2dFrame;
struct UnkStruct_001A45F0_msg;
struct UnkStruct_001A45F0_row;
struct UnkStruct_001A45F0_obj;

class CB3ScoreCategory {
public:
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0x4];
    unsigned char field_10;
    signed char field_11;
    signed char field_12;
    signed char field_13;
};

class CB3Score {
public:
    static float gmrNearMissChainTime;
};

struct UnkStruct_001A45F0_row {
    unsigned char pad_0[0x70];
};

struct UnkStruct_001A45F0_obj {
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0x10];
    UnkStruct_001A45F0_msg * field_20;
};

struct UnkStruct_001A45F0_msg {
    UnkStruct_001A45F0_obj * field_0;
    const unsigned short * field_4;
    float field_8;
    float field_C;
    float field_10;
    UnkStruct_001A45F0_msg * field_14;
    signed char field_18;
    unsigned char pad_19[0x3];
    float field_1C;
    float field_20;
    float field_24;
};

struct UnkStruct_F16 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_V2_16 { GtMathPs2::CGtV2d field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_D_00665ED0 { void * field_0; unsigned char pad_4[0xC]; };

extern UnkStruct_F16 krHUDBoostBarMessageIndentX;
extern UnkStruct_V2_16 D_004B7940;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern float D_004E0760;
extern float D_004E08FC;
extern float D_004E0900;

extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" float GetStringWidth__9CGt2dFontCFPCUs(void *, const unsigned short *);
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, GtMathPs2::CGtV4d, const void *, unsigned int, unsigned int);
extern "C" void _Render__24C2dObjectBoostBarMessageFRCQ211CGt2dObject16CGt2dObjectSpacePCv(void *, void *);

class CB3HUDBoostBar {
public:
    enum EMessageType { EMT_0, EMT_1, EMT_2 };
    bool UpdateBoostMessage(EMessageType p0, const CB3ScoreCategory * p1, float p2, float p3);

    unsigned char pad_0[0x4];
    UnkStruct_001A45F0_row * field_4;
    void * field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x54F];
    float field_56C;
    UnkStruct_001A45F0_msg field_570[3];
    unsigned char pad_5E8[0xA0];
    UnkStruct_001A45F0_msg * field_688;
    UnkStruct_001A45F0_obj * field_68C;
};

static inline GtMathPs2::CGtV2d func_001A45F0_inl1(float y)
{
    GtMathPs2::CGtV2d off = D_004B7940.field_0 * GtMathPs2::CGtV2d(0.0f, 0.0f);
    return GtMathPs2::CGtV2d(krHUDBoostBarMessageIndentX.field_0, y) - off;
}

// 0x001A45F0
bool CB3HUDBoostBar::UpdateBoostMessage(EMessageType p0, const CB3ScoreCategory * p1, float p2, float p3)
{
    bool upd = false;
    UnkStruct_001A45F0_msg * m = &field_570[p0];
    bool created = false;
    signed char t0 = -1;
    int had = m->field_0 != 0;
    if (p1->field_10 != 0) {
        if (!(p1->field_0 < p3)) {
            t0 = p1->field_11;
            upd = true;
            if (t0 < m->field_18) {
                m->field_18 = -1;
            }
        }
    } else {
        if (!(p1->field_8 < p3)) {
            t0 = p1->field_12;
        }
    }
    if (!upd && !had) {
        return false;
    }
    signed char pr = (signed char)t0;
    if (pr > -1) {
        if (m->field_18 < pr) {
            m->field_18 = t0;
            m->field_1C = 2.0f;
            m->field_20 = 0.0f;
        }
    }
    float d = 5.0f * p2;
    float v = m->field_1C - d;
    m->field_1C = v;
    if (v < 1.0f) {
        m->field_1C = 1.0f;
    }
    if (pr == p1->field_13 - 1) {
        m->field_24 = 0.0f;
    } else if (!upd) {
        m->field_24 = m->field_24 - d;
    } else {
        if (p0 == 2) {
            m->field_20 = 0.0f + m->field_20 + p2 * (D_004E08FC * (1.0f - (field_68C->field_C - p1->field_4) / CB3Score::gmrNearMissChainTime));
        } else {
            m->field_20 = 0.0f + m->field_20 + D_004E0900 * p2;
        }
        m->field_24 = 1.0f;
    }
    if (m->field_0 == 0) {
        m->field_0 = (UnkStruct_001A45F0_obj *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame((char *)field_4 + field_1C * 0x70 + 0x14, field_10, field_8);
        m->field_10 = field_56C - 26.0f;
        m->field_14 = field_688;
        field_688 = m;
        float y = m->field_10;
        UnkStruct_001A45F0_obj * o = m->field_0;
        GetStringWidth__9CGt2dFontCFPCUs(D_00665ED0.field_0, m->field_4);
        o->field_20 = m;
        GtMathPs2::CGtV4d col(1.0f, 1.0f, 1.0f, 1.0f);
        GtMathPs2::CGtV2d pos = func_001A45F0_inl1(y);
        Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(o, pos, D_004B7940.field_0, col, (const void *)&_Render__24C2dObjectBoostBarMessageFRCQ211CGt2dObject16CGt2dObjectSpacePCv, 64, 4);
        created = true;
    }
    if (upd) {
        m->field_8 = D_004E0760;
    }
    m->field_C = m->field_8;
    return created;
}
