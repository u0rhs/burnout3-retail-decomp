// CB3SoundGameModeManager::GetModeBankPath() const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundGameModeManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (extern C; vfunc_98/9C ints on D_0051BA88.field_0->field_1B4; result var r, two switches).

struct UnkStruct_GMBP_1 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual int vfunc_98();
    virtual int vfunc_9C();
};
struct UnkStruct_GMBP_0 {
    unsigned char pad_0[0x1B4];
    UnkStruct_GMBP_1 *field_1B4;
};
struct UnkStruct_GMBP_G { UnkStruct_GMBP_0 *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_GMBP_G D_0051BA88;
extern char *D_004E1B58;
extern char *D_004E1B5C;
extern char *D_004E1B60;
extern char *D_004E1B64;
extern "C" char *GetModeBankPath__23CB3SoundGameModeManagerCFv(void *self)
{
    char *r = 0;
    if (D_0051BA88.field_0 != 0) {
    UnkStruct_GMBP_1 *o = D_0051BA88.field_0->field_1B4;
    int m = o->vfunc_98();
    int v = o->vfunc_9C();
    switch (m) {
    case 4:
    case 0:
        return D_004E1B58;
    case 3:
        return D_004E1B5C;
    case 6:
        return D_004E1B60;
    case 1:
        return D_004E1B64;
    }
    switch (v) {
    case 0:
        return D_004E1B58;
    case 1:
        return D_004E1B5C;
    case 2:
        return D_004E1B5C;
    case 3:
    case 4:
    case 5:
        return D_004E1B60;
    }
    }
    return r;
}
