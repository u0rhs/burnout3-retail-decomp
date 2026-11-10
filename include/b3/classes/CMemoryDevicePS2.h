// CMemoryDevicePS2 -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CMEMORYDEVICEPS2_H
#define B3_CLASSES_CMEMORYDEVICEPS2_H

#include "b3/classes/EMemDevPollOrWait.h"

class CMemoryDevicePS2;

class CMemoryDevicePS2 {
public:
    int CloseFile();
    int FileExists(const char* p0);
    int GetError();
    int GetFileSize(const char* p0);
    int GetFreeSpace();
    int MkDir(const char* p0);
    int Read(char*, unsigned int, unsigned int);
    void Sync(EMemDevPollOrWait, int*);

    int field_0;
    unsigned char pad_4[0x48];
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    unsigned char pad_5C[0x74];
    int field_D0;
    int field_D4;
    int field_D8;
};

#endif
