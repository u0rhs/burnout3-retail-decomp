// B3HardCodedTrackRegionList.cpp -- translation unit regrouped by tools/tu_merge.py from 8 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3HardCodedTrackRegionList.cpp, 5 placed between two of them by address contiguity (N2).
// Area not evidenced (no Revenge file of that name), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/GtMathPs2.h"

#include "b3/classes/CB3HardCodedTrackRegionList.h"
#include "b3/classes/EB3TrackRegion.h"
#include "b3/classes/UnkStruct_kaaeFakeMipsImages.h"
#include "b3/classes/UnkStruct_kaaeSatMaps.h"
#include "b3/classes/UnkStruct_kaaeZoomImages.h"

struct UnkStruct_003F5C70_e0 {
    short field_0;
    short field_2;
};

extern UnkStruct_kaaeFakeMipsImages kaaeFakeMipsImages;
extern UnkStruct_kaaeZoomImages kaaeZoomImages;
extern UnkStruct_kaaeSatMaps kaaeSatMaps;
extern int D_004CE3D0[];  // [G] element count unknown
extern unsigned char D_004CE3B0[];  // [G] element count unknown
extern int D_004CE398[];  // [G] element count unknown
extern int D_004CE388[];  // [G] element count unknown
extern UnkStruct_003F5C70_e0 D_004CE270[];  // [G] element count unknown; D_004CE272 is field_2 of element 0

// CB3HardCodedTrackRegionList::GetFakeMipImage(EB3TrackRegion,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HardCodedTrackRegionList.cpp.
// 0x003F5AC0
int CB3HardCodedTrackRegionList::GetFakeMipImage(EB3TrackRegion p0, int p1)
{
    return kaaeFakeMipsImages.field_0[p0].field_0[p1];
}

// CB3HardCodedTrackRegionList::GetZoomImage(EB3TrackRegion,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HardCodedTrackRegionList.cpp.
// 0x003F5AE0
int CB3HardCodedTrackRegionList::GetZoomImage(EB3TrackRegion p0, int p1)
{
    return kaaeZoomImages.field_0[p0].field_0[p1];
}

// CB3HardCodedTrackRegionList::GetSatMapImage(EB3TrackRegion,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HardCodedTrackRegionList.cpp.
// 0x003F5B00
int CB3HardCodedTrackRegionList::GetSatMapImage(EB3TrackRegion p0, int p1)
{
    return kaaeSatMaps.field_0[p0].field_0[p1];
}

// func_003F5B30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003F5B30
extern "C" int func_003F5B30(int n0, int p0)
{
    int v0;
    switch (n0) {
    case 0:
        v0 = 0;
        break;
    case 1:
        v0 = 9;
        break;
    case 2:
        v0 = 21;
        break;
    default:
        v0 = 0;
        break;
    }
    return D_004CE3D0[(p0 + v0)];
}

// GetTrackIconPulseImage__27CB3HardCodedTrackRegionListF14EB3TrackRegioni -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003F5B90
extern "C" int GetTrackIconPulseImage__27CB3HardCodedTrackRegionListF14EB3TrackRegioni(int n0, int p0)
{
    int v0;
    switch (n0) {
    case 0:
        v0 = 0;
        break;
    case 1:
        v0 = 9;
        break;
    case 2:
        v0 = 21;
        break;
    default:
        v0 = 0;
        break;
    }
    return D_004CE398[D_004CE3B0[(p0 + v0)]];
}

// func_003F5C00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003F5C00
extern "C" int func_003F5C00(int n0, int p0)
{
    int v0;
    switch (n0) {
    case 0:
        v0 = 0;
        break;
    case 1:
        v0 = 9;
        break;
    case 2:
        v0 = 21;
        break;
    default:
        v0 = 0;
        break;
    }
    return D_004CE388[D_004CE3B0[(p0 + v0)]];
}

// func_003F5C70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003F5C70
extern "C" GtMathPs2::CGtV2d func_003F5C70(int p0, int p1, int a2 /* passed by every caller, not read here */)
{
    int v0;
    switch (p0) {
    case 0:
        v0 = 0;
        break;
    case 1:
        v0 = 9;
        break;
    case 2:
        v0 = 21;
        break;
    default:
        v0 = 0;
        break;
    }
    int i = p1 + v0;
    GtMathPs2::CGtV2d v((float)D_004CE270[i].field_0, (float)D_004CE270[i].field_2);
    return v;
}

// func_003F5D10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003F5D10
extern "C" int func_003F5D10(int n0)
{
    switch (n0) {
    case 0:
        return 9;
    case 1:
        return 12;
    case 2:
        return 7;
    }
    return 0;
}
