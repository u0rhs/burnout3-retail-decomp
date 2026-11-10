// CB3DebugManager::RenderPerfMonDataCallback(const char*,float,float,float,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DebugManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a137: inline text-row helper, int-pun colour, kOne, padded globals).

// Hand-written (a137): lifter refused. [G] static helper inlines per text row (copy of col by value + wbuf[256]); colour built via int-pun block temps (keeps 1.0f out of an FPR); static const kOne stops the 1.0f hoist; padded globals avoid gp-relative; float z=0 keeps +0.0f.
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
using namespace GtMathPs2;
struct UnkStruct_D_00665ED0 { CGt2dFont *pFont; unsigned char pad[0x100]; };
extern UnkStruct_D_00665ED0 D_00665ED0;
struct UnkStruct_D_004ED7E0 { float v; unsigned char pad[12]; };
extern UnkStruct_D_004ED7E0 D_004ED7E0;
struct UnkStruct_D_004ED7E4 { float v; unsigned char pad[12]; };
extern UnkStruct_D_004ED7E4 D_004ED7E4;
struct UnkStruct_D_004ED7E8 { unsigned char v; unsigned char pad[15]; };
extern UnkStruct_D_004ED7E8 D_004ED7E8;
extern char kDebugColourScale[16];
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(const char *, unsigned short *, int);
extern "C" int sprintf(char *, const char *, ...);
static inline int a137_max(int a, int b) { int r; asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline int a137_min(int a, int b) { int r; asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline unsigned int a137_zx(int a) { unsigned int r; asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a)); return r; }
static const float kOne = 1.0f;
static inline void a137_txt(const char *s, float x, float y, CGtV4d col)
{
    unsigned short wbuf[256];
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(s, wbuf, 0x100);
    D_00665ED0.pFont->RenderString(wbuf, x, y, 20.0f, col);
}
extern "C" void RenderPerfMonDataCallback__15CB3DebugManagerFPCcfffb(const char *name, float f0, float f1, float f2, bool flag)
{
    CGtV4d col;
    char buf[0x20];
    if (flag) { CGtV4d t1; *(int *)&t1.f[1] = 0; *(int *)&t1.f[0] = 0x3F800000; *(int *)&t1.f[3] = 0x3F800000; *(int *)&t1.f[2] = 0; col = t1; }
    else { CGtV4d t2; *(int *)&t2.f[0] = 0x3F800000; *(int *)&t2.f[1] = 0x3F800000; *(int *)&t2.f[2] = 0x3F800000; *(int *)&t2.f[3] = 0x3F800000; col = t2; }
    a137_txt(name, D_004ED7E0.v, D_004ED7E4.v, col);
    sprintf(buf, kDebugColourScale, (double)f0);
    a137_txt(buf, 270.0f + D_004ED7E0.v, D_004ED7E4.v, col);
    sprintf(buf, kDebugColourScale, (double)f1);
    a137_txt(buf, 340.0f + D_004ED7E0.v, D_004ED7E4.v, col);
    sprintf(buf, kDebugColourScale, (double)f2);
    a137_txt(buf, 410.0f + D_004ED7E0.v, D_004ED7E4.v, col);
    if (D_004ED7E8.v != 0 && f2 > 0.0f) {
        unsigned int n = a137_zx(a137_min(a137_max((int)(10.0f * (kOne - f1 / f2)) + 1, 0), 10));
        if ((int)n > 0) {
            buf[n] = 0;
            while (n-- != 0) buf[n] = '*';
            a137_txt(buf, 500.0f + D_004ED7E0.v, D_004ED7E4.v, col);
        }
    }
    float z = 0.0f;
    D_004ED7E0.v = D_004ED7E0.v + z;
    D_004ED7E4.v = D_004ED7E4.v + 16.0f;
}
