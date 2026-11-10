// CGTFileSystem -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTFILESYSTEM_H
#define B3_CLASSES_CGTFILESYSTEM_H

class CGTFileSystem;
struct UnkStruct_00212890_1;
struct UnkStruct_00212890_3;

class CGTFileSystem {
public:
    static CGTFileSystem * mpDefaultFilesystem;
    static int mbInstalledToRW;
    int FClose(void* p0);
    int FFlush(void* p0);
    int FGets(char* p0, int p1, void* p2);
    int InstallToRenderWare();
    UnkStruct_00212890_3 * Open(const char* p0, unsigned int p1);
    void SetAsDefaultFilesystem();

    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C(void*);
    virtual UnkStruct_00212890_1 * vfunc_10(int);
    unsigned char pad_4[0x4];
    int field_8;
    int field_C;
};

#endif
