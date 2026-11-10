// CB3NetworkManager::GameModeStatusMessageDeliveredCallback(bool,CGtNetworkMessage*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a80: sibling 0026E1A0 shape, vfunc_CC(int,int)).

// CB3NetworkManager::GameModeStatusMessageArrivedCallback(CGtNetworkMessage*,int,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a77: GetPlayerByID, Retrieve(&c), vfunc_D0 on D_0051BA88->field_1B4).

struct UnkStruct_0026E1A0_obj {
    // vptr at +0x0: placeholder virtuals by slot offset [G]
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
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC(int, int);
    virtual void vfunc_D0();
};
struct UnkStruct_0026E1A0_sys {
    unsigned char pad_0[0x1B4];
    UnkStruct_0026E1A0_obj * field_1B4;
};
struct UnkStruct_0026E1A0_g {
    UnkStruct_0026E1A0_sys * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_0026E130_m { unsigned char pad_0[0x8]; int field_8; unsigned short field_C; };
struct UnkStruct_0026E1A0_p { unsigned char pad_0[0x8]; };
extern UnkStruct_0026E1A0_g D_0051BA88;
extern "C" UnkStruct_0026E1A0_p * GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);

// 0x0026E130
extern "C" void GameModeStatusMessageDeliveredCallback__17CB3NetworkManagerFbP17CGtNetworkMessagePv(bool p0, UnkStruct_0026E130_m *msg, void *p1)
{
    UnkStruct_0026E1A0_p *r0 = GetPlayerByID__23CGtNetworkPlayerManagerCFi(p1, msg->field_8);
    if (r0 != 0) {
        if (D_0051BA88.field_0 != 0) {
            UnkStruct_0026E1A0_obj *o = (UnkStruct_0026E1A0_obj *)D_0051BA88.field_0->field_1B4;
            if (o != 0) {
                o->vfunc_CC(msg->field_C, msg->field_8);
            }
        }
    }
}
