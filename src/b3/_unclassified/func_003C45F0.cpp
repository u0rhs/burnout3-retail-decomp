// func_003C45F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (switch (case 5: case 2:) for the state test + StartLeadOut as a goto block after the final return + func_0038FF70 declared (void*, float, int) for retail's f12-first arg setup).

// func_003C45F0 -- [L] DNAT CB3EventFinishedPage::Update (a132 note); placeholder name, C linkage.
// near12: the D_01E90424 test is a switch (`case 5: case 2:`, retail's beq chain + `b` to the join), the
// StartLeadOut arm is a goto block after the final return (retail lays it out last, falling into the epilogue).

struct UnkStruct_003C45F0 { unsigned char pad_0[4]; float field_4; float field_8; };
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004F50A0 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BA88 { struct UnkStruct_45F0_a *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_45F0_a { unsigned char pad_0[0x1B4]; void *field_1B4; };
struct UnkStruct_D_01E8F294 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E8980A { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E8F1CC { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064EA7C { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064E470 { short field_0; unsigned char pad_2[0xE]; };
struct UnkStruct_D_0064EA70 { short field_0; unsigned char pad_2[0xE]; };
struct UnkStruct_Gen { unsigned char pad_0[0x10]; };
enum EB3MenuFlowFSMEvents {};
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_004F50A0 D_004F50A0;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_01E8F294 D_01E8F294;
extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01E8F1CC D_01E8F1CC;
extern UnkStruct_D_0064EA7C D_0064EA7C;
extern UnkStruct_D_0064E470 D_0064E470;
extern UnkStruct_D_0064EA70 D_0064EA70;
extern UnkStruct_Gen D_01E32AE0, D_01ECD9F0, D_01E90240, D_004F50C0, D_01E89800;
extern "C" int GetMyPlayerID__23CGtNetworkPlayerManagerCFv(void *);
extern "C" int func_0038FF70(void *, float, int);  // [G] float declared 2nd: same EABI registers (a0, f12, a1) as the callee's (int, int, float) placeholder; this order gives retail's argument setup (f12 loaded before the a1 move)
extern "C" void func_0042F0F0(void *);
extern "C" void func_003C47C0(void *);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" int GetMenuConfirm__15CB3InputManagerFSc(void *, signed char);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x003C45F0
extern "C" void func_003C45F0(UnkStruct_003C45F0 *self)
{
    if (self->field_8 > 0.0f) {
        if (self->field_8 <= D_004F50A0.field_0) {
            void *p = D_0051BA88.field_0->field_1B4;
            int r = func_0038FF70(p, D_0064EA7C.field_0, GetMyPlayerID__23CGtNetworkPlayerManagerCFv(&D_01E32AE0));
            D_0064E470.field_0 = r + 1;
            D_0064EA70.field_0 = r + 1;
            func_0042F0F0(&D_01ECD9F0);
            func_003C47C0(self);
            self->field_8 = -1.0f;
        }
        return;
    }
    if (self->field_4 > 0.0f) {
        if (D_01E90424.field_0 == 5) {
            if (!(D_004F50A0.field_0 <= self->field_4)) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)2, 0);
            }
        }
        return;
    }
    switch (D_01E90424.field_0) {
    case 5: case 2: {
        if (D_01E8F294.field_0 != 0) {
            if (GetMenuConfirm__15CB3InputManagerFSc(&D_004F50C0, 0) != 0) goto lead;
            if (D_01E8980A.field_0 == 0) {
                func_0031ECD0(&D_01E89800, 0x10, 3);
            }
        } else {
            if (GetMenuConfirm__15CB3InputManagerFSc(&D_004F50C0, 0) != 0) {
                D_01E8F1CC.field_0 = 600.0f;
            }
        }
    }
    }
    return;
lead:
    StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)2, 0);
}
