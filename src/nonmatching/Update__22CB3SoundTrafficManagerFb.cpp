// NONMATCHING: Update__22CB3SoundTrafficManagerFb -- retail 339 / ours 340 instructions, 87 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: sreg: declare-first/assign-late of sel and found (declared at the top, assigned in place): 97 -> 87. a204: N140 pad object (int + ctor/dtor) at top fixes frame 0x130. Left: s-reg assignment, spills, loop layout (a142: retail i=s1 sel=s3 id=s0 k=s5)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_00276D80_veh { int field_0; unsigned char pad_4[0x12C]; };
struct UnkStruct_00276D80_crash { int field_0; unsigned char pad_4[0x58]; };
struct UnkStruct_D_00527440 { unsigned char pad_0[0x36218]; unsigned char field_36218[1]; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x27D0]; };
extern UnkStruct_D_00522660 D_00522660[];
extern UnkStruct_D_00527440 D_00527440;
extern unsigned char D_0055D796[];
extern int D_0064D3A0;
extern "C" void Deactivate__22CB3SoundTrafficVehicleFv(void *);
extern "C" int GetID__22CB3SoundTrafficVehicleFv(void *);
extern "C" int GetPlayerIndex__22CB3SoundTrafficVehicleCFv(const void *);
extern "C" int IsHorning__22CB3SoundTrafficVehicleFv(void *);
extern "C" void Activate__22CB3SoundTrafficVehicleFiP17CB3TrafficVehicleSc(void *, int, void *, signed char);
extern "C" void Update__22CB3SoundCrashedTrafficFv(void *);
extern "C" void Update__22CB3SoundTrafficVehicleFbf(void *, bool, float);
class CB3SoundTrafficManager {
public:
    unsigned char pad_0[0xD0];
    unsigned char field_D0;
    unsigned char pad_D1[3];
    int field_D4;
    float field_D8[2];
    int field_E0;
    unsigned char pad_E4[0xC];
    UnkStruct_00276D80_veh field_F0[16];
    UnkStruct_00276D80_crash field_13F0[16];
    void Update(bool);
};
static inline int FindA(CB3SoundTrafficManager *m, unsigned char id, long pl);
static inline int FindB(CB3SoundTrafficManager *m);
static inline int FindA(CB3SoundTrafficManager *m, unsigned char id, long pl)
{
    for (int a = 0; a < 16; a++) {
        if (id == GetID__22CB3SoundTrafficVehicleFv(&m->field_F0[a]) && pl == GetPlayerIndex__22CB3SoundTrafficVehicleCFv(&m->field_F0[a])) return a;
    }
    return -1;
}
static inline int FindB(CB3SoundTrafficManager *m)
{
    for (int a = 0; a < 16; a++) {
        if (GetID__22CB3SoundTrafficVehicleFv(&m->field_F0[a]) == -1 && GetPlayerIndex__22CB3SoundTrafficVehicleCFv(&m->field_F0[a]) == -1) return a;
    }
    return -1;
}
struct a204_pad { int x; a204_pad() {} ~a204_pad() {} };
void CB3SoundTrafficManager::Update(bool p0)
{
    signed char sel;
    bool found;
    a204_pad g;
    UnkStruct_D_00527440 * const base = &D_00527440;
    int i;
    int k;
    unsigned char id;
    if (field_D0 != 0) {
        for (i = 0; i < 16; i++) {
            if (field_F0[i].field_0 != 0) Deactivate__22CB3SoundTrafficVehicleFv(&field_F0[i]);
        }
        return;
    }
    field_E0 = 0;
    bool any = false;
    for (i = 0; i < D_0064D3A0; i++) {
        char *car = (char *)&D_00522660 + i * 0x27D0;
        sel = *(signed char *)(car + 0x12C6FC);
        int cnt = *((unsigned char *)&D_00522660 + sel + 0x3B136);
        field_E0 = field_E0 + cnt;
        bool flag = *(unsigned char *)(car + 0x12BF2E) != 0;
        any = (any | flag) != 0;
        if (flag) {
            float f = field_D8[i];
            if (f < 1.0f) {
                f = f + 0.01f;
                field_D8[i] = f;
                if (!(f <= 1.0f)) field_D8[i] = 1.0f;
            }
        } else {
            float f = field_D8[i];
            if (!(f <= 0.0f)) {
                f = f - 0.1f;
                field_D8[i] = f;
                if (f < 0.0f) field_D8[i] = 0.0f;
            }
        }
        long pl = sel;
        for (k = 0; k < cnt; k++) {
            id = base->field_36218[sel * 25 + k];
            int a = FindA(this, id, pl);
            if (a == -1) {
                a = FindB(this);
                if (a != -1)
                    Activate__22CB3SoundTrafficVehicleFiP17CB3TrafficVehicleSc(&field_F0[a], id, (char *)base + id * 0x180 + 0x127D0, sel);
            }
        }
    }
    for (i = 0; i < 16; i++) {
        char *row = (char *)this + i * 0x130;
        UnkStruct_00276D80_veh *v = (UnkStruct_00276D80_veh *)(row + 0xF0);
        int id = GetID__22CB3SoundTrafficVehicleFv(v);
        if (id != -1) {
            found = false;
            const unsigned char *tab = D_0055D796;
            const unsigned char *ids = base->field_36218;
            int *np = &D_0064D3A0;
            for (int p = 0; p < *np; p++) {
                signed char sel = *((signed char *)&D_00522660 + p * 0x27D0 + 0x12C6FC);
                int cnt = tab[sel];
                for (int k = 0; k < cnt; k++) {
                    if (ids[GetPlayerIndex__22CB3SoundTrafficVehicleCFv(row + 0xF0) * 25 + k] == id) { found = true; break; }
                }
            }
            if (!found) Deactivate__22CB3SoundTrafficVehicleFv(v);
        }
    }
    field_D4 = 0;
    for (i = 0; i < 16; i++) {
        if (IsHorning__22CB3SoundTrafficVehicleFv(&field_F0[i])) field_D4 = field_D4 + 1;
    }
    for (i = 0; i < 16; i++) {
        if (field_F0[i].field_0 != 0) Update__22CB3SoundTrafficVehicleFbf(&field_F0[i], any, field_D8[0]);
    }
    for (i = 0; i < 16; i++) {
        if (field_13F0[i].field_0 != 0) Update__22CB3SoundCrashedTrafficFv(&field_13F0[i]);
    }
}


