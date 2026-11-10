// GtFileSystem.cpp -- translation unit regrouped by tools/tu_merge.py from 6 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 6 function(s) named in research/retail_names.csv -> GtFileSystem.cpp.
// Area: src/b3/GameShared/GameClasses/System/FileSystem, [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/FileSystem/GtFileSystem.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGTFileSystem.h"
#include "b3/classes/UnkStruct_D_00676440.h"
#include "b3/classes/UnkStruct_D_00676444.h"
#include "b3/classes/UnkStruct_D_00676448.h"
#include "b3/classes/UnkStruct_D_0067644C.h"
#include "b3/classes/UnkStruct_D_00676450.h"
#include "b3/classes/UnkStruct_D_00676454.h"
#include "b3/classes/UnkStruct_D_00676458.h"
#include "b3/classes/UnkStruct_D_0067645C.h"
#include "b3/classes/UnkStruct_D_00676460.h"
#include "b3/classes/UnkStruct_D_00676464.h"
#include "b3/classes/UnkStruct_D_00676468.h"

struct UnkStruct_00212890_1;
struct UnkStruct_00212890_2;
struct UnkStruct_00212890_3;
struct UnkStruct_00212CB0_1;

struct UnkStruct_00212890_1 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual int vfunc_24();
};

struct UnkStruct_00212890_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual int vfunc_8(CGTFileSystem *, const char*, unsigned int);
};

struct UnkStruct_00212890_3 {
    unsigned char pad_0[0x24];
    int field_24;
};

struct UnkStruct_00212CB0_1 {
    void * field_0;
    void * field_4;
    void * field_8;
    void * field_C;
    void * field_10;
    void * field_14;
    void * field_18;
    void * field_1C;
    void * field_20;
    void * field_24;
    void * field_28;
};

extern UnkStruct_D_00676440 D_00676440;
extern UnkStruct_D_00676444 D_00676444;
extern UnkStruct_D_00676448 D_00676448;
extern UnkStruct_D_0067644C D_0067644C;
extern UnkStruct_D_00676450 D_00676450;
extern UnkStruct_D_00676454 D_00676454;
extern UnkStruct_D_00676458 D_00676458;
extern UnkStruct_D_0067645C D_0067645C;
extern UnkStruct_D_00676460 D_00676460;
extern UnkStruct_D_00676464 D_00676464;
extern UnkStruct_D_00676468 D_00676468;
extern "C" void FOpen__13CGTFileSystemFPCcPCc(const char*, const char*);  // CGTFileSystem::FOpen(const char*,const char*), its address taken
extern "C" void FClose__13CGTFileSystemFPv(void*);  // CGTFileSystem::FClose(void*), its address taken
extern "C" void FRead__13CGTFileSystemFPvUiUiPv(void*, unsigned int, unsigned int, void*);  // CGTFileSystem::FRead(void*,unsigned int,unsigned int,void*), its address taken
extern "C" void FWrite__13CGTFileSystemFPCvUiUiPv(const void*, unsigned int, unsigned int, void*);  // CGTFileSystem::FWrite(const void*,unsigned int,unsigned int,void*), its address taken
extern "C" void FGets__13CGTFileSystemFPciPv(char*, int, void*);  // CGTFileSystem::FGets(char*,int,void*), its address taken
extern "C" void FPuts__13CGTFileSystemFPCcPv(const char*, void*);  // CGTFileSystem::FPuts(const char*,void*), its address taken
extern "C" void FEof__13CGTFileSystemFPv(void*);  // CGTFileSystem::FEof(void*), its address taken
extern "C" void FSeek__13CGTFileSystemFPvii(void*, int, int);  // CGTFileSystem::FSeek(void*,int,int), its address taken
extern "C" void FFlush__13CGTFileSystemFPv(void*);  // CGTFileSystem::FFlush(void*), its address taken
extern "C" void FExist__13CGTFileSystemFPCc(const char*);  // CGTFileSystem::FExist(const char*), its address taken
extern "C" void FTell__13CGTFileSystemFPv(void*);  // CGTFileSystem::FTell(void*), its address taken
extern "C" UnkStruct_00212CB0_1 * func_001D8B88();

// CGTFileSystem::FFlush(void*) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFileSystem.cpp.
// 0x002125E0
int CGTFileSystem::FFlush(void* p0)
{
    return 0;
}

// CGTFileSystem::FGets(char*,int,void*) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFileSystem.cpp.
// 0x002126E0
int CGTFileSystem::FGets(char* p0, int p1, void* p2)
{
    return 0;
}

// CGTFileSystem::FClose(void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFileSystem.cpp.
// 0x00212770
int CGTFileSystem::FClose(void* p0)
{
    vfunc_C(p0);
    return 0;
}

// CGTFileSystem::Open(const char*,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFileSystem.cpp.
// 0x00212890
UnkStruct_00212890_3 * CGTFileSystem::Open(const char* p0, unsigned int p1)
{
    UnkStruct_00212890_2 * m0 = 0;
    for (int i = 0; ((unsigned int)i < (unsigned int)field_C); i++) {
        UnkStruct_00212890_1 * r0 = vfunc_10(i);
        int r1 = r0->vfunc_24();
        if (r1 == 0) {
            m0 = (UnkStruct_00212890_2 *)r0;
            break;
        }
    }
    UnkStruct_00212890_3 * v1;
    if (m0 == 0) {
        field_8 = 3;
        v1 = (UnkStruct_00212890_3 *)m0;
    } else {
        int r2 = m0->vfunc_8(this, p0, p1);
        field_8 = r2;
        UnkStruct_00212890_2 * v0 = m0;
        if (field_8 != 0) {
            v0 = 0;
        }
        v1 = (UnkStruct_00212890_3 *)v0;
    }
    if (v1 != 0) {
        v1->field_24 = 2;
    }
    return v1;
}

// CGTFileSystem::SetAsDefaultFilesystem() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFileSystem.cpp.
// 0x00212A70
void CGTFileSystem::SetAsDefaultFilesystem()
{
    CGTFileSystem::mpDefaultFilesystem = this;
}

// CGTFileSystem::InstallToRenderWare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFileSystem.cpp.
// 0x00212CB0
int CGTFileSystem::InstallToRenderWare()
{
    if (CGTFileSystem::mbInstalledToRW != 0) {
        return 0;
    }
    UnkStruct_00212CB0_1 * r0 = func_001D8B88();
    D_00676440.field_0 = (int)r0->field_0;
    D_00676444.field_0 = (int)r0->field_4;
    D_00676448.field_0 = (int)r0->field_8;
    D_0067644C.field_0 = (int)r0->field_C;
    D_00676450.field_0 = (int)r0->field_10;
    D_00676454.field_0 = (int)r0->field_14;
    D_00676458.field_0 = (int)r0->field_18;
    D_0067645C.field_0 = (int)r0->field_1C;
    D_00676460.field_0 = (int)r0->field_20;
    D_00676464.field_0 = (int)r0->field_24;
    D_00676468.field_0 = (int)r0->field_28;
    r0->field_4 = (void *)&FOpen__13CGTFileSystemFPCcPCc;
    r0->field_8 = (void *)&FClose__13CGTFileSystemFPv;
    r0->field_C = (void *)&FRead__13CGTFileSystemFPvUiUiPv;
    r0->field_10 = (void *)&FWrite__13CGTFileSystemFPCvUiUiPv;
    r0->field_14 = (void *)&FGets__13CGTFileSystemFPciPv;
    r0->field_18 = (void *)&FPuts__13CGTFileSystemFPCcPv;
    r0->field_1C = (void *)&FEof__13CGTFileSystemFPv;
    r0->field_20 = (void *)&FSeek__13CGTFileSystemFPvii;
    r0->field_24 = (void *)&FFlush__13CGTFileSystemFPv;
    r0->field_0 = (void *)&FExist__13CGTFileSystemFPCc;
    r0->field_28 = (void *)&FTell__13CGTFileSystemFPv;
    CGTFileSystem::mbInstalledToRW = 1;
    return 1;
}
