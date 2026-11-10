// NONMATCHING: func_00437060 -- retail 147 / ours 147 instructions, 6 in changed runs
// a135: layout exact (goto first block out of line, cases 6,7,8 / 1,24,2); 6 instrs: li 10 / li 5 constants use v0 and are hoisted above the sb, retail uses v1 after the sb
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_P16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E8980A { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E89800 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E90226 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_004B5B48 { char *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00437060 {
    unsigned char pad_0[0x84];
    void *field_84;
    void *field_88;
    unsigned char field_8C;
    bool field_8D;
    bool field_8E;
    unsigned char pad_8F;
    int field_90;
};
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E90226 D_01E90226;
extern UnkStruct_D_004B5B48 D_004B5B48;
extern UnkStruct_D_004B5B48 D_004B5B68;
extern UnkStruct_D_004B5B48 D_004B5B88;
extern UnkStruct_D_004B5B48 D_004B5BC0;
extern UnkStruct_D_004B5B48 D_004B5BE0;
extern UnkStruct_D_004B5B48 D_004B5C00;
extern UnkStruct_P16 D_004F6100;
extern UnkStruct_P16 D_004EE040;
extern UnkStruct_P16 D_01E898E8;
extern UnkStruct_P16 D_01E90240;
extern UnkStruct_P16 D_0051BA44;
extern UnkStruct_P16 D_0051BA48;
extern UnkStruct_P16 D_004D1BB0;
extern UnkStruct_P16 D_004D1BE0;
extern UnkStruct_P16 theMemMgr;
extern int D_004E2918;
enum EB3MenuFlowFSMEvents {};
extern "C" int GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(void *, int);
extern "C" int QueueLoadRequest__17CAsyncLoadManagerFPCcPbPvUi(void *, const char *, bool *, void *, unsigned int);
extern "C" int Prepare__10CB3StringsFPvPCci(void *, void *, const char *, int);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_00131B30(void *);

extern "C" void func_00437060(UnkStruct_00437060 * self)
{
    char *s1;
    char *s0;
    if (D_01E90424.field_0 != 5) return;
    if (self->field_8C == 0) goto first;
sw:
    switch (self->field_90) {
    case 1:
    case 24:
        if (self->field_84 == 0) return;
        QueueLoadRequest__17CAsyncLoadManagerFPCcPbPvUi(&D_004F6100, s1, &self->field_8D, self->field_84, GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(&theMemMgr, 10));
        QueueLoadRequest__17CAsyncLoadManagerFPCcPbPvUi(&D_004F6100, s0, &self->field_8E, self->field_88, GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(&theMemMgr, 11));
        self->field_90 = 2;
        break;
    case 2:
        if (self->field_8D == false || self->field_8E == false) return;
        Prepare__10CB3StringsFPvPCci(&D_0051BA44, self->field_84, (const char *)&D_004D1BB0, 0xFA5);
        Prepare__10CB3StringsFPvPCci(&D_0051BA48, self->field_88, (const char *)&D_004D1BE0, 10);
        self->field_90 = 23;
        D_01E90226.field_0 = 1;
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        break;
    }
    return;
first:
        switch (func_0032B2C0(&D_01E898E8, 0, 1)) {
        case 6:
            s1 = D_004B5B48.field_0;
            s0 = D_004B5BC0.field_0;
            self->field_8C = 1;
            D_004E2918 = 0;
            break;
        case 7:
            s1 = D_004B5B68.field_0;
            s0 = D_004B5BE0.field_0;
            self->field_8C = 1;
            D_004E2918 = 10;
            break;
        case 8:
            s1 = D_004B5B88.field_0;
            s0 = D_004B5C00.field_0;
            self->field_8C = 1;
            D_004E2918 = 5;
            break;
        default:
            return;
        }
        func_00131B30(&D_004EE040);
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
    goto sw;
}
