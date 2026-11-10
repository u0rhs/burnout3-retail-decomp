// func_002222E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtTextureCache.h"
#include "b3/classes/RwRaster.h"

extern CGtTextureCache gTextureCache;

// 0x002222E0
extern "C" void func_002222E0(int n0, int p0)
{
    gTextureCache.AddRasterToCache((RwRaster*)n0, p0);
}
