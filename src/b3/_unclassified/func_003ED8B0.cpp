// func_003ED8B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (switch (r) { case 12: ...; break; case 13: return; default: ... } (the case's return keeps the default jump's delay slot a nop)).

// func_003ED8B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3MenuFlowFSMEvents {};

struct UnkStruct_003ED8B0;
struct UnkStruct_D_01E8F360;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E90424;

struct UnkStruct_D_01E90424 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8F360 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003ED8B0 {
    unsigned char pad_0[0x4];
    int field_4;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E8F360 D_01E8F360;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);  // CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents,bool)
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" int func_00449150(void *, int, int);

extern "C" void func_003ED8B0(UnkStruct_003ED8B0 * self)
{
    if (D_01E90424.field_0 != 5) {
        return;
    }
    int r0 = func_00449150(&D_01E8F360, 0, 1);
    switch (r0) {
    case 12:
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        break;
    case 13:
        return;
    default:
        self->field_4 = r0;
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0, 0);
        break;
    }
}
