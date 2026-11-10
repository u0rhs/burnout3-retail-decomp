// NONMATCHING: GetLaneChanges__15CB3TrafficValveFPb25ETrafficVehicleCategoriesiPf -- retail 177 / ours 178 instructions, 20 in changed runs
// near30: 25 -> 20: product-in-inline (inl1(a, x) returns k*r*x: retail's mul operand order) + for (v = 1;; v++) with continue (shared v++ block, sub.s in its delay slot). Left: retail loads D_0055D788 lazily inside the first random (after D_0055D78C); every lazy form (comma assign, defining inline) swaps v1/a2 for a vs cat*4 (47-52); and the two *out = f2 copies swap which one falls through (merging the conditions drops one copy)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

enum ETrafficVehicleCategories {};
struct UnkStruct_D_0055D788 { int field_0; unsigned char pad[0xC]; };
struct UnkStruct_D_0055D78C { int field_0; unsigned char pad[0xC]; };
extern UnkStruct_D_0055D788 D_0055D788;
extern UnkStruct_D_0055D78C D_0055D78C;
struct UnkStruct_266810_idx { int *field_0; int *field_4; int field_8; };
class CB3TrafficValve {
public:
    int GetLaneChanges(bool *, ETrafficVehicleCategories, int, float *);
    unsigned char pad_0[0x10];
    float *field_10[4];
    unsigned char pad_20[0x20];
    UnkStruct_266810_idx *field_40;
    unsigned char pad_44[0xD0];
    unsigned char field_114;
};
static inline float func_00266810_inl1(int &a, float x)
{
    int b = D_0055D78C.field_0;
    unsigned int r = (a << 16) + (a >> 16);
    r += b;
    D_0055D788.field_0 = r;
    D_0055D78C.field_0 = b + r;
    a = r;
    return 2.3283064e-10f * (float)r * x;
}
// 0x00266810
int CB3TrafficValve::GetLaneChanges(bool *p0, ETrafficVehicleCategories cat, int idx, float *out)
{
    float f6, f5, f4;
    float *row = field_10[idx];
    float f3 = *out;
    float f2 = row[cat];
    int v = 0;
    int a = D_0055D788.field_0;
    if (field_40->field_8 == 1 || field_114 != 0 || !(f2 < f3)) {
        *out = f2;
    } else if (func_00266810_inl1(a, f3) <= f2) {
        *out = f2;
    } else {
        float z = 0.0f;
        f3 = f3 - f2;
        for (v = 1;; v++) {
            int cnt = field_40->field_8;
            if (!(v < cnt)) break;
            int lo = idx - v;
            int hi = idx + v;
            if (lo >= 0) f6 = field_10[lo][cat]; else f6 = z;
            if (hi < cnt) f5 = field_10[hi][cat]; else f5 = z;
            f4 = f5 + f6;
            if (f4 <= z) continue;
            if (!(func_00266810_inl1(a, f3) <= f4)) { f3 = f3 - f4; continue; }
            if (f6 <= z) {
                *p0 = false;
                *out = f5;
            } else if (f5 <= z) {
                *p0 = true;
                *out = f6;
            } else if (func_00266810_inl1(a, f4) <= f6) {
                *p0 = true;
                *out = f6;
            } else {
                *p0 = false;
                *out = f5;
            }
            break;
        }
    }
    if (v == field_40->field_8) v = 0;
    return v;
}


