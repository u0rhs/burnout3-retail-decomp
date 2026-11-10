// B3TableComponent.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3TableComponent.cpp, 2 placed between two of them by address contiguity (N2).
// Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"

#include "b3/classes/CB3TableComponent.h"
#include "b3/classes/CGt2dFrame.h"

struct UnkStruct_0033F3E0;
struct UnkStruct_0033F3E0_a2;
struct UnkStruct_0033F400;
struct UnkStruct_0033F420_0;

struct UnkStruct_0033F3E0_a2 {
    unsigned char pad_0[0x18];
    float field_18;
    float field_1C;
};

struct UnkStruct_0033F3E0 {
    float field_0;
    float field_4;
};

struct UnkStruct_0033F400 {
    float field_0;
    float field_4;
};

struct UnkStruct_0033F420_0 {
    float field_0;
    float field_4;
};

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)
extern "C" void GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, void *, const void *, const void*);  // CGt2dObjectTable::GetImageSize(GtMathPs2::CGtV2d*,const CGt2dFrame&,const void*)
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, const void *, const void*);  // CGt2dObjectTable::GetTextSize(GtMathPs2::CGtV2d*,const CGt2dFrame&,const void*)

// GetCarIconSize__17CB3TableComponentFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0033F3E0
extern "C" float GetCarIconSize__17CB3TableComponentFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(UnkStruct_0033F3E0 * self, void *p0_, UnkStruct_0033F3E0_a2 * p1)
{
    int p0 = (int)p0_;
    float t0 = p1->field_18;
    float t1 = p1->field_1C;
    self->field_0 = t0;
    self->field_4 = t1;
    return t0;
}

// GetConnectionSize__17CB3TableComponentFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0033F400
extern "C" void GetConnectionSize__17CB3TableComponentFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(UnkStruct_0033F400 * self)
{
    self->field_0 = 18.0f;
    self->field_4 = 12.0f;
}

// CB3TableComponent::GetImageAndTextSize(GtMathPs2::CGtV2d*,const CGt2dFrame&,const void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TableComponent.cpp.
// 0x0033F420
void CB3TableComponent::GetImageAndTextSize(GtMathPs2::CGtV2d* p0, const CGt2dFrame& p1, const void* p2)
{
    UnkStruct_0033F420_0 local;  // [G] the frame's one local (size: up to the frame top)
    GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(this, p0, ((char *)&p1 + 0x50), p2);
    GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv((GtMathPs2::CGtV2d*)&local, p0, (const void*)&p1);
    field_0 = (3.0f + (field_0 + local.field_0));
    float mm0 = field_4;
    float mm1 = local.field_4;
    field_4 = GtMath::Max(mm0, mm1);
}

// CB3TableComponent::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TableComponent.cpp.
// 0x00340420
void CB3TableComponent::Construct()
{
    Construct__20CB3MenuComponentBaseFi(this, 2);
    field_C = 0;
}
