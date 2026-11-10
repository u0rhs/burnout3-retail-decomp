// NONMATCHING: Update__17CAsyncLoadManagerFv -- retail 112 / ours 111 instructions, 3 in changed runs
// a90: logic and layout match (goto cleanup form puts cleanup loop out of line after the Open block, early-return arms as in retail); left: retail ends the Open block with 'sb 785; b epilogue; nop' (delay slot nop), ours fills the delay slot with the sb (1 instr fewer, 3 in changed runs). Tried return/goto end/else forms
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

class CGTFileSystem {
public:
    int Open(const char*, unsigned int);
};
struct UnkStruct_D_004F60C0 {
    CGTFileSystem * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_004EE040_x { unsigned char pad_0[0x10]; };
struct UnkStruct_0013D410_1 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10(int, int);
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C(int);
    virtual void vfunc_20();
    virtual int vfunc_24();
};
struct UnkStruct_0013D4D0_e0 {
    unsigned char field_0;
    unsigned char pad_1[0x3F];
    bool * field_40;
    int field_44;
    int field_48;
    int field_4C;
};
class CAsyncLoadManager {
public:
    void Update();
    UnkStruct_0013D4D0_e0 field_0[1];
    unsigned char pad_50[0x730];
    UnkStruct_0013D410_1 * field_780;
    unsigned char field_784;
    unsigned char field_785;
    unsigned char pad_786[0x2];
    int field_788;
    int field_78C;
    int field_790;
};
extern UnkStruct_D_004F60C0 D_004F60C0;
extern UnkStruct_D_004EE040_x D_004EE040;
extern "C" int func_001D3FA0(UnkStruct_D_004EE040_x *);

// 0x0013D250
void CAsyncLoadManager::Update()
{
    func_001D3FA0(&D_004EE040);
    int h = field_788;
    if (field_0[h].field_4C == 0) {
        return;
    }
    if (field_780 != 0) {
        if (field_780->vfunc_24() == 2) {
            return;
        }
        if (field_785 != 0) {
            field_785 = 0;
            field_780->vfunc_10(field_0[field_788].field_44, field_0[field_788].field_48);
            return;
        }
        field_780->vfunc_C();
        field_780 = 0;
        if (field_784 == 0) {
            *field_0[field_788].field_40 = true;
            field_784 = 1;
        }
        return;
    }
    if (field_784 != 0) goto cleanup;
open:
    if (field_0[h].field_4C == 0) {
        return;
    }
    field_780 = (UnkStruct_0013D410_1 *)D_004F60C0.field_0->Open((const char *)&field_0[h], 17);
    field_785 = 1;
    return;
cleanup:
    field_784 = 0;
    field_0[field_788].field_4C = 0;
    for (;;) {
        int a = field_788;
        if (a == field_78C) break;
        if (field_0[a].field_4C != 0) break;
        field_788 = a + 1;
        if (field_788 == 24) {
            field_788 = 0;
        }
    }
    h = field_788;
    goto open;
}
