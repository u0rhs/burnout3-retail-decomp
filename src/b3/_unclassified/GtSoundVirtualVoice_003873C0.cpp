// CGtSoundVirtualVoice::UpdatePause() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVirtualVoice.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (son1: scoped opt_dead_code off [G] + int t0 in inl3 (was 6 off: stop block placement)).

#pragma push
#pragma opt_dead_code off  // [G] N182: scoped; places case 3's stop block before the exit (retail order); evidence: 6 -> 0 diff
// Logic and registers match; only case 3's stop block (field_2C = field_2D = 0, reached from count>=5 and !IsPlaying) is placed after the switch exit in ours, between fade and exit in retail. Tried ||/&& forms, nested ifs, break/return, default:, compare forms, int/bool inline return.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// lifter variant 0
// CGtSoundVirtualVoice::UpdatePause() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVirtualVoice.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundVirtualVoice;
class CGtSoundVoice;
struct UnkStruct_003873C0_1;
struct UnkStruct_003873C0_2;

struct UnkStruct_003873C0_1 {
    unsigned char pad_0[0x60];
    void * field_60;
    int field_64;
    unsigned char pad_68[0x4];
    int field_6C;
    unsigned char pad_70[0x15];
    unsigned char field_85;
    unsigned char pad_86[0x4];
    unsigned char field_8A;
};

struct UnkStruct_003873C0_2 {
    unsigned char pad_0[0x6C];
    int field_6C;
};

class CGtSoundVoice {
public:
    static unsigned char _muMaxActiveCount;
};

class CGtSoundVirtualVoice {
public:
    void UpdatePause();

    unsigned char field_0;
    unsigned char pad_1[0x3];
    UnkStruct_003873C0_1 * field_4;
    unsigned char pad_8[0x8];
    int field_10;
    unsigned char pad_14[0x18];
    unsigned char field_2C;
    unsigned char field_2D;
    unsigned char pad_2E[0x1];
    unsigned char field_2F;
    unsigned char field_30;
};

extern "C" int RwaObjHandleGetParamUInt32(void *, int, int, int);
extern "C" void _rwaVirtualVoiceSetTrigger(UnkStruct_003873C0_1 *, int);
extern "C" void RwaObjHandleSetParamReal(void *, int, int, float);
extern "C" void RwaObjHandleSetParamUInt32(void *, int, int, int);

// Inlined helpers (placeholder names [G]); _inl3 has the body of CGtSoundVirtualVoice::IsPlaying() (0x00387980) [L].
static inline bool func_003873C0_inl1(UnkStruct_003873C0_1 * vv)
{
    bool r = false;
    if (vv->field_60 != 0) {
        if ((vv->field_8A & 2) != 0) {
            r = true;
        }
    }
    return r;
}

static inline bool func_003873C0_inl2(CGtSoundVirtualVoice * v)
{
    if ((v->field_2F & 64) == 0) {
        return (((v->field_4->field_8A & 2) != 0) != false);
    }
    if ((v->field_2F & 128) != 0) {
        return true;
    }
    return false;
}

static inline bool func_003873C0_inl3(CGtSoundVirtualVoice * v)
{
    int t0 = v->field_2C;
    switch (t0) {
    case 0:
    case 1:
    case 3:
        if ((v->field_2F & 64) == 0) {
            return (((v->field_4->field_8A & 2) != 0) != false);
        }
        if ((v->field_2F & 128) != 0) {
            if (((v->field_4->field_8A & 2) != 0) == false) {
                if (t0 == 0) {
                    v->field_0 = 1;
                }
            }
        }
        return (0 < (v->field_2F & 128));
    case 2:
        return (0 < (v->field_2F & 8));
    default:
        return 0;
    }
}

static inline void func_003873C0_inl4(UnkStruct_003873C0_1 * vv, float f)
{
    if (vv->field_60 != 0) {
        RwaObjHandleSetParamReal(vv->field_60, 7, 1, f);
    }
}

// 0x003873C0
void CGtSoundVirtualVoice::UpdatePause()
{
    switch (field_2C) {
    case 0:
        return;
    case 1: {
        int n = field_2D;
        if (n < 5) {
            if (func_003873C0_inl2(this)) {
                unsigned char & vol = field_4->field_85;
                float f = (float)(unsigned int)vol / 255.0f;
                f *= 1.0f - (float)(unsigned int)n / 5.0f;
                if (field_30 < CGtSoundVoice::_muMaxActiveCount) {
                    f = 0.0f;
                }
                vol = (unsigned char)(255.0f * f);
                func_003873C0_inl4(field_4, f);
                field_2D++;
            } else {
                field_2D = 0;
                field_2C = 2;
                field_2F &= ~8;
            }
        } else {
            if (field_4->field_64 != 0) {
                field_2F |= 8;
                int pos;
                if (func_003873C0_inl1(field_4)) {
                    pos = RwaObjHandleGetParamUInt32(field_4->field_60, 9, 2, 0);
                } else {
                    pos = field_4->field_6C;
                }
                field_4->field_6C = pos;
                field_10 = pos;
                _rwaVirtualVoiceSetTrigger(field_4, 0);
            }
            field_2D = 0;
            field_2C = 2;
        }
        break;
    }
    case 2:
        return;
    case 3:
        if ((field_2F & 8) == 0) {
            field_2C = 0;
        } else {
            if (field_2D == 0) {
                _rwaVirtualVoiceSetTrigger(field_4, 1);
                field_4->field_6C = field_10;
                if (field_4->field_60 != 0) {
                    RwaObjHandleSetParamUInt32(field_4->field_60, 9, 1, field_10);
                }
            }
            if (field_2D < 5 && func_003873C0_inl3(this)) {
                unsigned char & vol = field_4->field_85;
                float f = (float)(unsigned int)vol / 255.0f;
                f *= (float)(unsigned int)field_2D / 5.0f;
                if (field_30 < CGtSoundVoice::_muMaxActiveCount) {
                    f = 0.0f;
                }
                vol = (unsigned char)(255.0f * f);
                func_003873C0_inl4(field_4, f);
                field_2D++;
            } else {
                field_2C = 0;
                field_2D = 0;
            }
        }
        break;
    }
}

#pragma pop
