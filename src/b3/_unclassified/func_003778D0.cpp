// func_003778D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (early returns then if/else-if input chain; cursor-update and pair-setter static inline helpers [G]; partial sum in its own int local).

// lifter variant 0
// func_003778D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3MenuFlowFSMEvents {};

class CB3InputManager;
class CGtLobbyPS2DirtySock;
struct UnkStruct_003778D0;
struct UnkStruct_D_01E7A800;
struct UnkStruct_D_01E90240;

class CB3InputManager {
public:
    int GetMenuConfirm(signed char);
    int GetMenuBack(signed char);
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);
    int GetMenuPageUp(signed char);
    int GetMenuPageDown(signed char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtLobbyPS2DirtySock {
public:
    void GetRankingData(int, int, char*, int);
    int GetNumberRankRecords();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E7A800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

// [G] the scroll position pair at +0xEDC (func_00319330/func_00319360 take its address)
struct UnkStruct_003778D0_s {
    unsigned short field_0;
    unsigned short field_2;
};

struct UnkStruct_003778D0 {
    unsigned char pad_0[0x4];
    char field_4[0xED8];
    UnkStruct_003778D0_s field_EDC;
    short field_EE0;
    short field_EE2;
    unsigned char pad_EE4[0xC];
    int field_EF0;
    unsigned char pad_EF4[0x4];
    int field_EF8;
    unsigned char pad_EFC[0x4];
    int field_F00;
};

extern CB3InputManager D_004F50C0;
extern CGtLobbyPS2DirtySock D_01E3CD44;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E7A800 D_01E7A800;

extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);  // CB3MenuPageManager::StartLeadOutFore(EB3MenuFlowFSMEvents,bool)
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);  // CB3HUDSoundManager::FEVerticalMove(), passed 2 more argument(s) [G]
extern "C" void func_00378990(UnkStruct_003778D0 *);
extern "C" int func_0022CBE0(void *, int);
extern "C" bool func_00376A60(UnkStruct_003778D0 *, int);
extern "C" int func_00319330(UnkStruct_003778D0_s *);
extern "C" int func_00319360(UnkStruct_003778D0_s *);


// [G] inlined helper (name unknown): stores the cursor row and plays the move sound
static inline void func_003778D0_inl(UnkStruct_003778D0 * self)
{
    int a = self->field_EF8;
    int b = self->field_F00;
    int s = a + self->field_EF0;
    self->field_EE0 = s + self->field_EDC.field_0;
    self->field_EE2 = b;
    FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
}

// [G] inlined setter (name unknown): rewrites both halves of the pair
static inline void func_003778D0_set(UnkStruct_003778D0_s * s, unsigned short v)
{
    unsigned short m = s->field_2;
    s->field_0 = v;
    s->field_2 = m;
}

// 0x003778D0
extern "C" void func_003778D0(UnkStruct_003778D0 * self)
{
    if (D_004F50C0.GetMenuConfirm(0) != 0) {
        D_01E3CD44.GetRankingData(self->field_EF0 + self->field_EDC.field_0, 1, self->field_4, 16);
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)44, 0);
        return;
    }
    if (D_004F50C0.GetMenuBack(0) != 0) {
        func_00378990(self);
        return;
    }
    if (func_0022CBE0(&D_004F50C0, 0) != 0) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)36, 0);
    } else if (D_004F50C0.GetMenuUp(0) != 0) {
        if (func_00319360(&self->field_EDC) != 0) {
            func_003778D0_inl(self);
        } else if (self->field_EF0 > 0) {
            self->field_EF0--;
            func_00376A60(self, self->field_EF0);
            func_003778D0_inl(self);
        }
    } else if (D_004F50C0.GetMenuDown(0) != 0) {
        if (func_00319330(&self->field_EDC) != 0) {
            func_003778D0_inl(self);
        } else if (self->field_EF0 + self->field_EDC.field_0 < D_01E3CD44.GetNumberRankRecords() - 1) {
            self->field_EF0++;
            unsigned short v = self->field_EDC.field_0;
            func_00376A60(self, self->field_EF0);
            func_003778D0_set(&self->field_EDC, v);
            func_003778D0_inl(self);
        }
    } else if (D_004F50C0.GetMenuPageUp(0) != 0) {
        if (self->field_EF0 >= 5) {
            self->field_EF0 -= 5;
            func_00376A60(self, self->field_EF0);
            func_003778D0_inl(self);
        } else if (self->field_EF0 != 0) {
            self->field_EF0 = 0;
            func_003778D0_set(&self->field_EDC, 0);
            func_00376A60(self, self->field_EF0);
            func_003778D0_inl(self);
        }
    } else if (D_004F50C0.GetMenuPageDown(0) != 0) {
        if (self->field_EF0 + self->field_EDC.field_0 + 5 <= D_01E3CD44.GetNumberRankRecords() - 5) {
            self->field_EF0 += 5;
            func_00376A60(self, self->field_EF0);
            func_003778D0_inl(self);
        } else if (self->field_EF0 + self->field_EDC.field_0 < D_01E3CD44.GetNumberRankRecords() - 1) {
            func_003778D0_set(&self->field_EDC, self->field_EDC.field_2 - 1);
            func_00376A60(self, self->field_EF0);
            func_003778D0_inl(self);
        }
    }
}
