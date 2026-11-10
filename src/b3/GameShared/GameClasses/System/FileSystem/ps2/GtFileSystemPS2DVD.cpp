// GtFileSystemPS2DVD.cpp -- translation unit regrouped by tools/tu_merge.py from 6 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> GtFileSystemPS2DVD.cpp, 3 placed between two of them by address contiguity (N2).
// Area: src/b3/GameShared/GameClasses/System/FileSystem/ps2, [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/FileSystem/ps2/GtFileSystemPS2DVD.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtFilePS2DVD.h"
#include "b3/classes/CGtFileSystemPS2DVD.h"

extern "C" void WaitSema(int);

// CGtFileSystemPS2DVD::GetStatus() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtFileSystemPS2DVD.cpp.
// 0x001D2F80
int CGtFileSystemPS2DVD::GetStatus()
{
    return field_4;
}

// CGtFileSystemPS2DVD::FileExists(const char*) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtFileSystemPS2DVD.cpp.
// 0x001D2F90
int CGtFileSystemPS2DVD::FileExists(const char* p0)
{
    return 1;
}

// CGtFilePS2DVD::Sync(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFileSystemPS2DVD.cpp.
// 0x001D3050
int CGtFilePS2DVD::Sync(int p0)
{
    for (;;) {
        if ((((p0 != 0) ^ 1) & 255) == 0) {
            if (field_18 == 2) {
                WaitSema(field_2C);
                continue;
            }
        }
        break;
    }
    return field_18;
}

// CGtFilePS2DVD::Write(const void*,unsigned int) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFileSystemPS2DVD.cpp.
// 0x001D3270
int CGtFilePS2DVD::Write(const void* p0, unsigned int p1)
{
    field_1C = 1;
    return 0;
}

// CGtFilePS2DVD::GetStatus() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtFileSystemPS2DVD.cpp.
// 0x001D3820
int CGtFilePS2DVD::GetStatus()
{
    return field_18;
}

// CGtFileSystemPS2DVD::GetFileObject(unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFileSystemPS2DVD.cpp.
// 0x001D3830
void * CGtFileSystemPS2DVD::GetFileObject(unsigned int p0)
{
    return &field_10[p0];
}
