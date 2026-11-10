// CB3NetworkManager::PlayerListChangedCallback(int,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (static callback: self=(p1); vptr structs to slots 0x3C / 0x54).

struct UnkStruct_0026F150_vt {
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
};
struct UnkStruct_0026F150_vt2 {
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
    virtual void vfunc_54(char *, int, bool, int, void *, void *);
};
struct UnkStruct_0026F150_ent { unsigned char pad_0[0x34]; void *field_34; unsigned char pad_38[0x23C]; void *field_274; unsigned char pad_278[0x18]; };
struct UnkStruct_0026F150_sub { unsigned char pad_0[0x4AC]; int field_4AC; };
struct UnkStruct_0026F150_row { char field_0[16]; };
struct UnkStruct_0026F150 {
    unsigned char pad_0[4];
    unsigned char field_4;
    unsigned char pad_5[3];
    UnkStruct_0026F150_sub *field_8[1];
    unsigned char pad_C[0x1C];
    int field_28;
    unsigned char pad_2C[0x50];
    UnkStruct_0026F150_vt *field_7C;
    unsigned char pad_80[0x320];
    UnkStruct_0026F150_row field_3A0[10];
    UnkStruct_0026F150_row field_440[10];
    unsigned char pad_4E0[0xA264 - 0x4E0];
    UnkStruct_0026F150_vt2 field_A264;
    unsigned char pad_A268[0x3297C - 0xA268];
    int field_3297C;
};
extern "C" void func_0022D9F0(void *);
extern "C" void func_0022DA20(void *);
extern "C" void func_002352B0(void *);
extern "C" int ForEachNetworkOpponent__17CB3NetworkManagerFPcibiiiPcbPv(char *, int, bool, int, int, int, char *, bool, void *);
extern "C" bool PlayerListChangedCallback__17CB3NetworkManagerFiPv(int p0, void *p1)
{
    UnkStruct_0026F150 *self = (UnkStruct_0026F150 *)p1;
    self->field_3297C = 0;
    self->field_4 = 0;
    self->field_7C->vfunc_3C();
    for (int i = 0; i < self->field_28; i++) {
        UnkStruct_0026F150_sub *s = self->field_8[i];
        if (s != 0) {
            for (int j = 0; j < s->field_4AC; j++) {
                UnkStruct_0026F150_ent *e = (UnkStruct_0026F150_ent *)((char *)s + j * 24);
                func_0022D9F0(e->field_34);
                if (e->field_274 != 0) func_0022DA20(e->field_274);
            }
        }
    }
    for (int k = 0; k < 10; k++) func_0022DA20(&self->field_3A0[k]);
    for (int m = 0; m < 10; m++) func_0022DA20(&self->field_440[m]);
    func_002352B0(self);
    self->field_A264.vfunc_54(0, -1, false, 100, (void *)ForEachNetworkOpponent__17CB3NetworkManagerFPcibiiiPcbPv, self);
    return true;
}
