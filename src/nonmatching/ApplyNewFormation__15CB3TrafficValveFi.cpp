// NONMATCHING: ApplyNewFormation__15CB3TrafficValveFi -- retail 162 / ours 162 instructions, 8 in changed runs
// layout+logic exact; only s-register rotation (this/p0/base/lane) differs, 17 instrs; decl order sweep didn't help | mwperm: 17 -> 8 ('UnkStruct_2664B0_lane *lane; if (id0 == 255) lane = 0; else ' -> 'UnkStruct_2664B0_lane *const lane = 255 == id0 ? 0 : (UnkStruct_2664B0_lane *)((')
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_D_00522660_e { unsigned char pad_0[0x4C]; };
struct UnkStruct_D_00522660 { UnkStruct_D_00522660_e field_0[1]; };
struct UnkStruct_2664B0_fm { unsigned char pad_0[0x10]; int field_10; };
struct UnkStruct_2664B0_lane { unsigned char pad_0[4]; unsigned short field_4; };
struct UnkStruct_2664B0_v { unsigned char pad_0[0x30]; float field_30; unsigned char pad_34[4]; UnkStruct_2664B0_fm *field_38; unsigned char pad_3C[0xB]; unsigned char field_47; unsigned char field_48; };
struct UnkStruct_2664B0_li { UnkStruct_2664B0_fm **field_0; };
struct UnkStruct_2664B0_idx { int *field_0; int *field_4; };
struct UnkStruct_D_0055D7DC { unsigned char *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0055D7DC D_0055D7DC;
extern "C" int FindNextValve__14CB3TrafficLaneFiPiPi(void *, int, int*, int*);
class CB3TrafficValve {
public:
    void ApplyNewFormation(int);
    unsigned char pad_0[0x20];
    UnkStruct_2664B0_fm * field_20[1];
    unsigned char pad_24[0x1C];
    UnkStruct_2664B0_idx * field_40;
    unsigned char pad_44[0xC8];
    unsigned char field_10C[1];
};
static inline UnkStruct_2664B0_v *func_002664B0_inl1(unsigned char id)
{
    if (id == 255) return 0;
    return (UnkStruct_2664B0_v *)((char *)&D_00522660 + id * 80 + 0x2F2B0);
}
// 0x002664B0
void CB3TrafficValve::ApplyNewFormation(int p0)
{
    UnkStruct_2664B0_v *v;
    unsigned char id;
    struct { int field_0; int field_4; } local;
    int id0 = field_40->field_0[p0];
    unsigned char *base = D_0055D7DC.field_0;
    UnkStruct_2664B0_lane *const lane = 255 == id0 ? 0 : (UnkStruct_2664B0_lane *)((char *)&D_00522660.field_0[id0] + 0x22C);
    field_10C[p0] = 0;
    if (FindNextValve__14CB3TrafficLaneFiPiPi(lane, field_40->field_4[p0], &local.field_4, &local.field_0) == 0) {
        local.field_0 = *(int *)((char *)*(void **)lane + 0x10) - 1;
    }
    id = base[lane->field_4 + field_40->field_4[p0]];
    if (id == 255) return;
    v = func_002664B0_inl1(id);
    for (;;) {
        if (v == 0) return;
        if (!(v->field_30 <= (float)local.field_0)) return;
        if (v->field_48 == 0) {
            UnkStruct_2664B0_fm *r;
            if (field_20[p0]->field_10 <= 0) {
                v->field_47 = 255;
                r = 0;
            } else {
                v->field_47 = field_10C[p0];
                field_10C[p0] = field_10C[p0] + 1;
                field_10C[p0] = (unsigned int)field_10C[p0] % (unsigned int)field_20[p0]->field_10;
                if (field_20[p0] == 0) v->field_47 = 255;
                r = field_20[p0];
            }
            v->field_38 = r;
        } else {
            v->field_47 = 255;
            v->field_38 = 0;
        }
        unsigned char *tbl = base + lane->field_4;
        unsigned short s = (unsigned short)v->field_30;
        unsigned char nxt = (tbl + s)[1];
        if (nxt == 255) return;
        if (nxt == id) return;
        id = nxt;
        v = func_002664B0_inl1(nxt);
    }
}


