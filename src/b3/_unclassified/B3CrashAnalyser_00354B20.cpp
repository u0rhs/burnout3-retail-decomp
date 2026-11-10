// CB3CrashAnalyser::AddCollidingBody(CB3CollidingBody*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashAnalyser.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (AddCollidingBody).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
using GtMathPs2::CGtV4d;
class CGtSphereTreeSphere;
struct UnkStruct_acb_obj { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_acb_o2 { unsigned char pad_0[0x18C0]; int field_18C0; };
class CB3CollidingBody {
public:
    unsigned char pad_0[0x1C0];
    CGtV4d field_1C0;
    unsigned char pad_1D0[0x34];
    UnkStruct_acb_obj *field_204;
    unsigned char pad_208[0x11EC];
    UnkStruct_acb_o2 *field_13F4;
};
struct UnkStruct_acb_e0 {
    unsigned char pad_0[0x39];
    unsigned char field_39;
    unsigned char pad_3A[0x36];
};
struct UnkStruct_acb_e1 {
    unsigned char pad_0[0x40];
    CB3CollidingBody *field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    unsigned char pad_58[8];
    int field_60;
    int field_64;
    unsigned char field_68;
    unsigned char field_69;
    unsigned char field_6A;
    unsigned char pad_6B[5];
};
class CB3CrashAnalyser {
public:
    void AddCollidingBody(CB3CollidingBody *);
    UnkStruct_acb_e1 field_0[1];
    unsigned char pad_70[0x2A0];
    UnkStruct_acb_e0 field_310[1];
    unsigned char pad_380[0xC80];
    CB3CollidingBody *field_1000;
    int field_1004;
    unsigned char pad_1008[0x28];
    int field_1030;
    int field_1034;
    unsigned char pad_1038[0xC];
    int field_1044;
};
extern "C" void RemoveSphere__13CGtSphereTreeFP19CGtSphereTreeSphere(void *, void *);
extern "C" void AddSphere__13CGtSphereTreeFP19CGtSphereTreeSphereQ29GtMathPs26CGtV3dfPv(void *, void *, const CGtV3d &, float, void *);
// 0x00354B20
void CB3CrashAnalyser::AddCollidingBody(CB3CollidingBody *body)
{
    int count = field_1030;
    UnkStruct_acb_e1 *s;
    int i;
    for (i = 0; i < count; i++) {
        if (field_310[i].field_39 != 0 && i != field_1004) break;
    }
    if (i < count) {
        s = (UnkStruct_acb_e1 *)((char *)&field_0[i] + 0x2E0);
    } else {
        int idx = field_1034;
        s = (UnkStruct_acb_e1 *)((char *)&field_0[idx] + 0x2E0);
        if (count == 30) {
            if (idx == field_1004) {
                field_1034 = (idx + 1) % 30;
                s = (UnkStruct_acb_e1 *)((char *)&field_0[field_1034] + 0x2E0);
            }
            RemoveSphere__13CGtSphereTreeFP19CGtSphereTreeSphere(this, s);
        }
        s->field_64 = field_1034;
    }
    s->field_40 = body;
    const CGtV3d &p3 = s->field_40->field_204->field_30;
    AddSphere__13CGtSphereTreeFP19CGtSphereTreeSphereQ29GtMathPs26CGtV3dfPv(this, s, p3, s->field_40->field_1C0.W(), s);
    s->field_4C = 0;
    s->field_48 = 0;
    s->field_60 = 0;
    s->field_50 = 0;
    s->field_54 = 0;
    s->field_44 = 0;
    s->field_68 = 0;
    s->field_69 = 0;
    s->field_6A = 0;
    if (body == field_1000) {
        field_1004 = s->field_64;
        field_1044 = s->field_40->field_13F4->field_18C0;
    }
    if (i == field_1030) {
        if (field_1030 < 30) field_1030 = field_1030 + 1;
        field_1034 = (field_1034 + 1) % 30;
    }
}
