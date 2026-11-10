// CAsyncLoadManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CASYNCLOADMANAGER_H
#define B3_CLASSES_CASYNCLOADMANAGER_H

#include "b3/GtMath.h"

class CAsyncLoadManager;
struct UnkStruct_0013D410_1;
struct UnkStruct_0013D4D0_e0;

struct UnkStruct_0013D410_1 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C(int);
    virtual void vfunc_20();
    virtual int vfunc_24();
};

struct UnkStruct_0013D4D0_e0 {
    unsigned char field_0;
    unsigned char pad_1[0x3F];
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
};

class CAsyncLoadManager {
public:
    void Abort(unsigned int);
    void Init();
    void Shutdown();

    UnkStruct_0013D4D0_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_50[0x730];
    UnkStruct_0013D410_1 * field_780;
    unsigned char field_784;
    unsigned char field_785;
    unsigned char pad_786[0x2];
    int field_788;
    int field_78C;
    int field_790;
};

#endif
