// B3CrashAnalyser.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3CrashAnalyser.cpp, 2 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Camera/Crash, [L] Revenge (SLUS_212.42) GameSource/Camera/Crash/B4CrashAnalyser.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3CollidingBody.h"
#include "b3/classes/CB3CrashAnalyser.h"
#include "b3/classes/CGtIntersectionResult.h"
#include "b3/classes/CGtSphereTree.h"
#include "b3/classes/CGtSphereTreeSphere.h"

struct UnkStruct_00354CF0;
struct UnkStruct_00354CF0_a1;
struct UnkStruct_00353C00_0;
struct UnkStruct_func_00353F30;

struct UnkStruct_00354CF0_a1 {
    unsigned char pad_0[0x215];
    signed char field_215;
    unsigned char pad_216[0x2];
    signed char field_218;
};

struct UnkStruct_00354CF0 {
    unsigned char pad_0[0x1038];
    int field_1038;
    int field_103C;
    unsigned char pad_1040[0x9];
    unsigned char field_1049;
};

struct UnkStruct_00353C00_0 {
    float field_0;
};

struct UnkStruct_func_00353F30 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_func_00353F30 func_00353F30;
extern "C" void AddCollidingBody__16CB3CrashAnalyserFP16CB3CollidingBody(void *, void *);  // CB3CrashAnalyser::AddCollidingBody(CB3CollidingBody*)
extern "C" void ForAllSpheresResult__13CGtSphereTreeFRC10CGtFrustumPFPC19CGtSphereTreeSphere21EGtIntersectionResultRC21CGtIntersectionResultPv_bPv(void *, const void *, const void *, void*);  // CGtSphereTree::ForAllSpheresResult(const CGtFrustum&,bool (*)(const CGtSphereTreeSphere*,EGtIntersectionResult,const CGtIntersectionResult&,void*),void*)

// CB3CrashAnalyser::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashAnalyser.cpp.
// 0x00353980
void CB3CrashAnalyser::Destruct()
{
    field_1049 = 0;
}

// CB3CrashAnalyser::RenderDebug() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashAnalyser.cpp.
// 0x00353A20
void CB3CrashAnalyser::RenderDebug()
{
}

// func_00353C00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00353C00
extern "C" float func_00353C00(int n0, int p0)
{
    UnkStruct_00353C00_0 local;  // [G] the frame's one local (size: up to the frame top)
    local.field_0 = 0.0f;
    ForAllSpheresResult__13CGtSphereTreeFRC10CGtFrustumPFPC19CGtSphereTreeSphere21EGtIntersectionResultRC21CGtIntersectionResultPv_bPv((void *)n0, (void *)p0, (const void *)&func_00353F30, (void*)&local);
    return local.field_0;
}

// CB3CrashAnalyser::GetMostInterestingCluster() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashAnalyser.cpp.
// 0x00354260
void * CB3CrashAnalyser::GetMostInterestingCluster()
{
    void * m1 = 0;
    int m0 = 0;
    for (int i = 0; (i < 10); i++) {
        int t0 = field_80[i].field_4;
        if (m0 < t0) {
            m1 = ((char *)&field_0[i] + 0x60);
            m0 = t0;
        }
    }
    return m1;
}

// func_00354CF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00354CF0
extern "C" void func_00354CF0(UnkStruct_00354CF0 * self, UnkStruct_00354CF0_a1 * p0)
{
    if (self->field_1049 != 0) {
        if (self->field_103C == p0->field_218) {
            self->field_1038 = (self->field_1038 + 1);
            signed char t0 = p0->field_215;
            if (t0 != 1) {
                if (t0 != 2) {
                    if (t0 != 3) {
                        AddCollidingBody__16CB3CrashAnalyserFP16CB3CollidingBody(self, (CB3CollidingBody*)p0);
                    }
                }
            }
        }
    }
}
