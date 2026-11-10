// CGtLobbyPS2DirtySock::CheckForPlayerListChange() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (hand-written).

class CGtLobbyPS2DirtySock {
public:
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
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual int vfunc_AC();
    bool CheckForPlayerListChange();
    unsigned char pad_4[0x130];
    struct UnkStruct_134 * field_134;
    int field_138;
    char field_13C[8][36];
};
struct UnkStruct_Elem { int f0; unsigned char pad_4[0x3C]; char name[36]; };
struct UnkStruct_134 { unsigned char pad_0[0x1C0]; UnkStruct_Elem arr[8]; };
extern "C" int strcmp(const char *, const char *);
extern "C" char *strncpy(char *, const char *, unsigned);

// 0x0033BC80
bool CGtLobbyPS2DirtySock::CheckForPlayerListChange()
{
    int count = 0;
    int i = 0;
    bool changed = false;
    for (i = 0; i < 8; i++) {
        int off = i * 100;
        char *e = (char *)field_134 + off;
        if (*(int *)(e + 0x1C0) != 0) {
            count++;
            if (strcmp(e + 0x200, field_13C[i]) != 0) {
                strncpy(field_13C[i], (char *)field_134 + off + 0x200, 0x24);
                changed = true;
            }
        }
    }
    if ((count != 0 && count != field_138) || changed) {
        field_138 = count;
        return true;
    }
    return false;
}
