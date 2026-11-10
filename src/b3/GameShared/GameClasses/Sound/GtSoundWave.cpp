// GtSoundWave.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> GtSoundWave.cpp.
// Area: src/b3/GameShared/GameClasses/Sound, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundWave.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtSoundWave.h"
#include "b3/classes/RwaSPU2Wave.h"

extern "C" unsigned long GtIDCompress__FPCc(int, RwaSPU2Wave *);

// CGtSoundWave::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundWave.cpp.
// 0x003895C0
void CGtSoundWave::Destruct()
{
    field_8 = 0;
    field_0 = 0;
}

// CGtSoundWave::Construct(RwaSPU2Wave*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundWave.cpp.
// 0x003895D0
void CGtSoundWave::Construct(RwaSPU2Wave* p0)
{
    field_8 = p0;
    unsigned long r0 = GtIDCompress__FPCc(p0->field_4, p0);
    field_0 = r0;
}
