// func_0022D400 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004B9E18.h"
#include "b3/classes/UnkStruct_D_01D6EDD0.h"
#include "b3/classes/UnkStruct__gbEncryptionKeyValid.h"

struct UnkStruct_0022D400;
struct UnkStruct_0022D400_0;

struct UnkStruct_0022D400_0 {
    unsigned char field_0;
    unsigned char pad_1[0xAF];
};

struct UnkStruct_0022D400 {
    signed char field_0[1];  // [G] element count unknown
};

extern UnkStruct__gbEncryptionKeyValid _gbEncryptionKeyValid;
extern UnkStruct_D_004B9E18 D_004B9E18;
extern UnkStruct_D_01D6EDD0 D_01D6EDD0;
extern "C" char * strcat(char *, const char *);
extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" void sprintf(void *, void *, signed char);

// 0x0022D400
extern "C" void func_0022D400(UnkStruct_0022D400 * self)
{
    char tmp[16];
    char buf[160];
    buf[0] = 0;
    for (int i = 0; i < 32; i++) {
        sprintf(tmp, &D_004B9E18, self->field_0[i]);
        strcat(buf, tmp);
    }
    memcpy(&D_01D6EDD0, self, 32);
    _gbEncryptionKeyValid.field_0 = 1;
}
