// NONMATCHING: Prepare__17CB3RaceCarPhysicsFP10CB3RaceCar -- retail 572 / ours 557 instructions, 269 in changed runs
// ghvu21: logic believed right (attribs find/create loop, id SetX chain, 3x inlined CB3CollidingBody::SetMomentOfInertia, tail resets); 269 changed, frame 0x650 vs 0x710. Left = the 3 inertia blocks (world = R^T*I*R). Retail operand flow per product row: A row0 by GPR round trip (qmfc2 t1 .. qmtc2 t1, not vmove), A rows1-2 reloaded from the in-place transposed copy (lqc2 0x630/0x640), B rows by lq+qmtc2 (unfolded); second product reloads R1/R2 from the stack copy after the field_40 stores, R0 from the transpose's vmove copy. Ours forwards VU values (vmove) and keeps R1/R2 live (vf8/vf9). Stand-ins [L] N185 (in-place transpose as func_00356FB0's invert, row product with r operands on vf1-vf4). Header gap: CGtMatrix3x3::operator* / CB3Tensor::GetTranspose (B3O0PCH map) -- a body with .i moves may give retail's round trips (N188).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Prepare__17CB3RaceCarPhysicsFP10CB3RaceCar -- hand-written (ghvu21) from the Ghidra draft. Types/fields [G].
// [L] the three inertia blocks are CB3CollidingBody::SetMomentOfInertia(float,float,float) inlined (B3O0PCH map,
// 0x14C): the inertia tensor rows set by CGtV3d::Set(f,f,f), then the world tensor = R^T * I * R with R the body
// matrix's 3x3 part (map: CB3Tensor::GetTranspose(), CGtMatrix3x3::operator*(const CGtMatrix3x3&)); no header API, so
// [L] N185 stand-ins below.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

extern "C" int strcmp(const char *, const char *);
extern "C" int strncmp(const char *, const char *, unsigned int);
extern "C" void * memset(void *, int, unsigned int);

struct UnkStruct_001C6600_attr { unsigned char pad_0[0xB0]; unsigned long field_B0; unsigned char pad_B8[0x1A4 - 0xB8]; float field_1A4; unsigned char pad_1A8[0x1D0 - 0x1A8]; };
struct UnkStruct_001C6600_D { UnkStruct_001C6600_attr field_0[6]; UnkStruct_001C6600_attr * field_AE0[6]; };
extern UnkStruct_001C6600_D D_01D9C350;
struct UnkStruct_001C6600_car { unsigned char pad_0[0x1960]; unsigned long field_1960; };
struct UnkStruct_001C6600_cc0 { unsigned char pad_0[0x54]; int field_54; };
struct UnkStruct_001C6600_cc4 { unsigned char pad_0[0x1028]; int field_1028; int field_102C; unsigned char field_1030; unsigned char field_1031; unsigned char field_1032; unsigned char field_1033; };
struct UnkStruct_001C6600 {
    unsigned char pad_0[0x10];
    CGtMatrix3x3 field_10;
    CGtMatrix3x3 field_40;
    unsigned char pad_70[0x1D0 - 0x70];
    CGtV3d field_1D0;
    CGtV3d field_1E0;
    unsigned char pad_1F0[0x4];
    float field_1F4;
    unsigned char pad_1F8[0xC];
    CGtMatrix3x4 * field_204;
    unsigned char pad_208[0xF];
    unsigned char field_217;
    signed char field_218;
    unsigned char pad_219[0xCC0 - 0x219];
    UnkStruct_001C6600_cc0 * field_CC0;
    UnkStruct_001C6600_cc4 * field_CC4;
    unsigned char pad_CC8[0x1390 - 0xCC8];
    float field_1390;
    unsigned char pad_1394[0x13D4 - 0x1394];
    float field_13D4;
    unsigned char pad_13D8[0x13F4 - 0x13D8];
    UnkStruct_001C6600_car * field_13F4;
    UnkStruct_001C6600_attr * field_13F8;
    unsigned char field_13FC;
    unsigned char pad_13FD[3];
    int field_1400;
    int field_1404;
    int field_1408;
    int field_140C;
    int field_1410;
    int field_1414;
    int field_1418;
    int field_141C;
    int field_1420;
    int field_1424;
    int field_1428;
    int field_142C;
    float field_1430;
    int field_1434;
    int field_1438;
    int field_143C;
    float field_1440;
    unsigned char field_1444;
    unsigned char field_1445;
    unsigned char field_1446;
    unsigned char pad_1447;
    unsigned char field_1448[0x14E0 - 0x1448];
    CGtMatrix3x4 field_14E0;
    int field_1520;
    int field_1524;
    unsigned char field_1528;
    unsigned char field_1529;
    unsigned char field_152A;
    unsigned char field_152B;
    float field_152C;
    int field_1530;
    float field_1534;
    int field_1538;
    unsigned char field_153C;
    unsigned char field_153D;
    unsigned char field_153E;
    unsigned char field_153F;
    unsigned char field_1540;
};
extern char D_004B7D28[];
extern char D_004B7D38[];
extern char D_004B7D48[];
extern float D_004E16D0;
extern float D_004E16D4;
extern float D_004E16D8;
extern int D_004E16C4;

extern "C" void Prepare__17CB3VehiclePhysicsFP25CB3VehicleEssentialParamsP16CB3VehicleParams(UnkStruct_001C6600 *, UnkStruct_001C6600_car *, void *);
extern "C" void Prepare__24CB3RaceCarPhysicsAttribsFP17CB3VehiclePhysics(UnkStruct_001C6600_attr *, UnkStruct_001C6600 *);
extern "C" void CopyToPhysics__24CB3RaceCarPhysicsAttribsFP17CB3VehiclePhysics(UnkStruct_001C6600_attr *, UnkStruct_001C6600 *);
extern "C" void func_001C7880(void *, UnkStruct_001C6600 *);
extern "C" void func_0021AB40(unsigned long, char *);

// [L] N185 stand-ins (no header API): transpose of a 3x3 (per-lane copies, as func_00356FB0's invert) and the 3x3
// product r_i = a_i.x * b0 + a_i.y * b1 + a_i.z * b2.
static inline void func_001C6600_r0(CGtV3d &d, const CGtV3d &b, const CGtV3d &c) { asm("vaddx.y %0, $vf0, %1x" "\n\t" "vaddx.z %0, $vf0, %2x" : "+j"(d.mData) : "j"(b.mData), "j"(c.mData)); }
static inline void func_001C6600_r1(CGtV3d &d, const CGtV3d &a, const CGtV3d &c) { asm("vaddy.x %0, $vf0, %1y" "\n\t" "vaddy.z %0, $vf0, %2y" : "+j"(d.mData) : "j"(a.mData), "j"(c.mData)); }
static inline void func_001C6600_r2(CGtV3d &d, const CGtV3d &a, const CGtV3d &b) { asm("vaddz.x %0, $vf0, %1z" "\n\t" "vaddz.y %0, $vf0, %2z" : "+j"(d.mData) : "j"(a.mData), "j"(b.mData)); }
static inline void func_001C6600_trip(CGtMatrix3x3 &t)
{
    CGtV3d a = t.mRight, b = t.mUp, c = t.mAt;
    func_001C6600_r0(t.mRight, b, c);
    func_001C6600_r1(t.mUp, a, c);
    func_001C6600_r2(t.mAt, a, b);
}
static inline CGtV3d func_001C6600_row(u_long128 a, u_long128 b0, u_long128 b1, u_long128 b2)
{
    u_long128 r;
    asm("qmtc2 %2, $vf4" "\n\t" "qmtc2 %1, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "qmtc2 %3, $vf3" "\n\t"
        "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "qmtc2 %4, $vf2" "\n\t" "vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2 %0, $vf1"
        : "=r"(r) : "r"(a), "r"(b0), "r"(b1), "r"(b2));
    return CGtV3d(r);
}
static inline CGtMatrix3x3 func_001C6600_mul(const CGtMatrix3x3 &a, const CGtMatrix3x3 &b)
{
    CGtMatrix3x3 r;
    u_long128 b0 = b.mRight.mData, b1 = b.mUp.mData, b2 = b.mAt.mData;
    r.mRight = func_001C6600_row(a.mRight.mData, b0, b1, b2);
    r.mUp = func_001C6600_row(a.mUp.mData, b0, b1, b2);
    r.mAt = func_001C6600_row(a.mAt.mData, b0, b1, b2);
    return r;
}
// [L] CB3CollidingBody::SetMomentOfInertia(float,float,float) (map name; placeholder inline here, [G] body)
static inline void func_001C6600_inl1(UnkStruct_001C6600 * self, float x, float y, float z)
{
    self->field_10.mRight.Set(x, 0.0f, 0.0f);
    self->field_10.mUp.Set(0.0f, y, 0.0f);
    self->field_10.mAt.Set(0.0f, 0.0f, z);
    CGtMatrix3x3 i = self->field_10;
    CGtMatrix3x3 r = *(CGtMatrix3x3 *)self->field_204;
    CGtMatrix3x3 t = r;
    func_001C6600_trip(t);
    self->field_40 = func_001C6600_mul(t, i);
    self->field_40 = func_001C6600_mul(self->field_40, r);
}

// 0x001C6600
extern "C" int Prepare__17CB3RaceCarPhysicsFP10CB3RaceCar(UnkStruct_001C6600 * self, UnkStruct_001C6600_car * car)
{
    UnkStruct_001C6600_attr * at;
    char name[16];
    Prepare__17CB3VehiclePhysicsFP25CB3VehicleEssentialParamsP16CB3VehicleParams(self, car, (char *)car + 0x80);
    self->field_13F4 = car;
    int i;
    for (i = 0; i < 6; i++) {
        UnkStruct_001C6600_attr ** slot = &D_01D9C350.field_AE0[i];
        if (*slot == 0) {
            *slot = &D_01D9C350.field_0[i];
            Prepare__24CB3RaceCarPhysicsAttribsFP17CB3VehiclePhysics(*slot, self);
            at = *slot;
            goto done;
        }
        if ((*slot)->field_B0 == self->field_13F4->field_1960) {
            UnkStruct_001C6600_attr ** p = &D_01D9C350.field_AE0[i];
            CopyToPhysics__24CB3RaceCarPhysicsAttribsFP17CB3VehiclePhysics(*slot, self);
            at = *p;
            goto done;
        }
    }
    at = 0;
done:
    self->field_13F8 = at;
    func_001C7880(self->field_1448, self);
    self->field_218 = -1;
    if (car->field_1960 == 0x790798FBA1182C00UL) {
        self->field_1E0.SetX(-1.2f);
        self->field_1D0.SetX(1.2f);
    } else if (car->field_1960 == 0x790798FBA1192600UL || car->field_1960 == 0x790798FBA11A2000UL) {
        self->field_1E0.SetX(-1.015f);
        self->field_1D0.SetX(1.015f);
    }
    func_001C6600_inl1(self, 0.0008f, 0.0011f, 0.0013f);
    if (self->field_13F4 != 0) {
        func_0021AB40(self->field_13F4->field_1960, name);
        if (strcmp(name, D_004B7D28) == 0 || strcmp(name, D_004B7D38) == 0) {
            func_001C6600_inl1(self, 0.00075f, 0.0008f, 0.0011f);
        } else if (strncmp(name, D_004B7D48, 4) == 0) {
            func_001C6600_inl1(self, D_004E16D0, D_004E16D4, D_004E16D8);
        }
    }
    self->field_13FC = 0;
    self->field_1400 = 0;
    self->field_1404 = 0;
    self->field_1408 = 0;
    self->field_1414 = 0;
    self->field_1410 = 0;
    self->field_1418 = 0;
    self->field_141C = 0;
    self->field_1420 = 0;
    self->field_1424 = 0;
    self->field_1428 = 0;
    self->field_142C = 0;
    self->field_1430 = self->field_1390;
    self->field_1440 = self->field_1390;
    self->field_1434 = 0;
    self->field_1438 = 0;
    self->field_1444 = 0;
    self->field_143C = 0;
    self->field_1445 = 0;
    self->field_1446 = 0;
    self->field_1528 = 0;
    self->field_1529 = 0;
    self->field_152A = 0;
    self->field_152B = 0;
    memset(&self->field_14E0, 0, 0x40);
    self->field_14E0.SetIdentity();
    self->field_1520 = 0;
    self->field_152C = -1.0f;
    self->field_1524 = 0;
    self->field_217 = 0;
    self->field_1534 = 1.0f;
    self->field_1538 = 0;
    self->field_153D = 0;
    self->field_153E = 0;
    self->field_153F = 0;
    self->field_1540 = 0;
    self->field_1F4 = (self->field_1D0.Y() - self->field_1E0.Y()) * 0.1f;
    self->field_13D4 = self->field_13F8->field_1A4;
    self->field_153C = 0;
    self->field_1530 = 0;
    self->field_CC0->field_54 = 0;
    self->field_CC4->field_1028 = 0;
    self->field_CC4->field_102C = 0;
    self->field_CC4->field_1030 = 0;
    self->field_CC4->field_1031 = 0;
    self->field_CC4->field_1032 = 0;
    self->field_CC4->field_1033 = 0;
    if (D_004E16C4 == -1)
        D_004E16C4 = 0;
    return 1;
}
