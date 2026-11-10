// CB3PhysicsManagerDebug::RenderWorld() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PhysicsManagerDebug.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a162: hand-written from asm; body-state inline takes const element pointer (const param stops the CSE with the direct ==3 test)).

// CB3PhysicsManagerDebug::RenderWorld() -- hand-written
struct UnkStruct_RW_hull {
    unsigned char pad_0[4];
    void *field_4;
    void *field_8;
};
struct UnkStruct_RW_prop {
    unsigned char pad_0[0xB0];
    unsigned char *field_B0;
    unsigned char pad_B4[0x154];
    UnkStruct_RW_hull *field_208;
};
struct UnkStruct_RW_e {
    signed char field_0;
    unsigned char pad_1[3];
    void *field_4;
    int field_8;
    UnkStruct_RW_prop *field_C;
    unsigned char pad_10[0x20];
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x3C980];
    UnkStruct_RW_e field_3C980[1];
};
struct UnkStruct_D_0057BAE0 {
    int field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_0055E948 {
    unsigned char pad_0[0x10];
};
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0057BAE0 D_0057BAE0;
extern UnkStruct_D_0055E948 D_0055E948;
extern "C" void DebugRenderEdges__13CB3ConvexHullCFRCQ29GtMathPs212CGtMatrix3x4b(void *, void *, bool);
extern "C" void DebugRenderPlanes__13CB3ConvexHullFRCQ29GtMathPs212CGtMatrix3x4PCQ29GtMathPs28CGtPlanePCQ29GtMathPs26CGtV3db(void *, void *, void *, void *, bool);
extern "C" void RenderDebugData__22CB3CrashActionDirectorFv(void *);
class CB3PhysicsManagerDebug {
public:
    void RenderWorld();
    void DrawIntervals();
    void DrawCollisionWorld();
    void DrawCollisionTriangleCache();
    void DrawHullToHullCollisionPlanes();
    unsigned char pad_0[4];
    bool field_4;
    unsigned char pad_5;
    unsigned char field_6;
    unsigned char field_7;
    unsigned char field_8;
    unsigned char pad_9[3];
    unsigned char field_C;
    unsigned char pad_D[3];
    unsigned char field_10;
};
static inline bool func_002BEA00_inl1(const UnkStruct_RW_e *e)
{
    return (unsigned int)e->field_0 <= 2 || e->field_0 == 4 || e->field_0 == 6 || e->field_0 == 7;
}
// 0x002BEA00
void CB3PhysicsManagerDebug::RenderWorld()
{
    if (field_7 != 0) {
        for (int i = 0; i < D_0057BAE0.field_0; i++) {
            UnkStruct_RW_e *e = &D_00522660.field_3C980[i];
            UnkStruct_RW_hull *h = 0;
            if (e->field_0 == 3) {
                unsigned char *x = e->field_C->field_B0;
                if (x != 0) {
                    h = (UnkStruct_RW_hull *)(x + 0x1060);
                }
            } else if (func_002BEA00_inl1(e)) {
                h = e->field_C->field_208;
            }
            if (h != 0) {
                DebugRenderEdges__13CB3ConvexHullCFRCQ29GtMathPs212CGtMatrix3x4b(h, e->field_4, field_4);
                DebugRenderPlanes__13CB3ConvexHullFRCQ29GtMathPs212CGtMatrix3x4PCQ29GtMathPs28CGtPlanePCQ29GtMathPs26CGtV3db(h, e->field_4, h->field_4, h->field_8, field_4);
            }
        }
    }
    if (field_8 != 0) {
        DrawIntervals();
    }
    if (field_6 != 0) {
        DrawCollisionWorld();
    }
    if (field_C != 0) {
        DrawCollisionTriangleCache();
    }
    if (field_10 != 0) {
        DrawHullToHullCollisionPlanes();
    }
    RenderDebugData__22CB3CrashActionDirectorFv(&D_0055E948);
}
