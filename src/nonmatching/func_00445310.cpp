// NONMATCHING: func_00445310 -- retail 133 / ours 131 instructions, 2 in changed runs
// near8: sibling func_003C96F0 shape (Back 'goto r', f330 'if (!F) goto r', trailing return + r: return) -> 2 off: one separate 'b exit; nop' relay block for the f330-true path is missing (MWCC merges it with the Down-false return; dead-assignment/empty-block/extra-label forms all merged or dropped the test)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_00445310 -- retail 133 / ours 129 instructions, 4 in changed runs
// a251: sibling of func_003C96F0 (same menu update + extra func_0022CC60 branch); same 4 off: missing 'beqz exit' + dead 'b exit' after final Down/func_00319330 empty-then
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// func_00445310 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3MenuFlowFSMEvents {};

class CB3InputManager;
struct UnkStruct_00445310;
struct UnkStruct_00445310_e2;
struct UnkStruct_D_01E89544;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E90424;

class CB3InputManager {
public:
    int GetMenuConfirm(signed char);
    int GetMenuBack(signed char);
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90424 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00445310_e2 {
    unsigned char field_0;
    unsigned char pad_1[0x7];
};

struct UnkStruct_D_01E89544 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00445310 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    unsigned char pad_C[0x2C];
    unsigned char field_38[1];  // [G] element count unknown
    unsigned char pad_39[0x9];
    unsigned char field_42[1];  // [G] element count unknown
    unsigned char pad_43[0x9];
    unsigned char field_4C;
    unsigned char pad_4D[0x1];
    unsigned short field_4E;
    unsigned char pad_50[0x8];
    UnkStruct_00445310_e2 field_58[1];  // [G] element count unknown
};

extern UnkStruct_D_01E90424 D_01E90424;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void SetItemEnabled__19CB3VSelectComponentFib(void *, int, int);  // CB3VSelectComponent::SetItemEnabled(int,bool)
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);  // CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents,bool)
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" int func_0022D1E0(void *);
extern "C" int func_0022CC60(void *, int);
extern "C" int func_00319330(void *);
extern "C" int func_00319360(void *);

// 0x003C96F0
extern "C" void func_00445310(UnkStruct_00445310 * self)
{
    int r0 = func_0022D1E0(&D_004F50C0);
    if ((((signed char)r0) < 2) != self->field_4C) {
        self->field_4C = (((signed char)r0) < 2);
        for (int i = 0; (i < self->field_4); i++) {
            unsigned char t0 = self->field_42[i];
            if (t0 != 0) {
                int v1 = self->field_4C != 0;
                if (v1) v1 = t0 != 0;
                if (!v1) v1 = self->field_38[i] != 0;
                SetItemEnabled__19CB3VSelectComponentFib(&D_01E89544, i, (v1 ^ 1));
            }
        }
    }
    if (D_01E90424.field_0 == 5) {
        if (func_0022CC60(&D_004F50C0, 0) != 0) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)62, 0);
            return;
        }
        if (D_004F50C0.GetMenuConfirm(0) == 0) {
            if (D_004F50C0.GetMenuBack(0) != 0) {
                StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
                goto r;
            }
            if (D_004F50C0.GetMenuUp(0) != 0 && func_00319360(((char *)self + 0x4E)) != 0) {
                return;
            }
            if (D_004F50C0.GetMenuDown(0) != 0) {
                if (!(func_00319330(((char *)self + 0x4E)) != 0)) goto r;
            }
            return;
        r:
            return;
        }
        int t1 = self->field_4E;
        if (self->field_58[t1].field_0 != 0) {
            return;
        }
        if (self->field_4C == 0 || self->field_42[t1] == 0) {
            self->field_8 = t1;
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0, 0);
        }
    }
}
