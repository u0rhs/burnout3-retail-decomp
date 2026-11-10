// NONMATCHING: func_004D45E0 -- retail 847 / ours 250 instructions, 834 in changed runs
// gaps1e: hand-drafted from the asm (vehicle-physics / race-car arrays' static initialiser)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1e (2026-11-02): hand-drafted from the retail asm (0x4D45E0..0x4D5318) with the Ghidra aid. A C++ static
// initialiser (.init; called through the .ctor table), kept as its asm label: the inlined default constructors of the
// vehicle-physics and race-car object arrays [C bounds, strides and vtables from the asm; L the class roles from the
// vtable names]:
//   D_0057BAF0  2 x 0x4590  CB3CollidingBody -> CB3VehiclePhysics -> CB3PlayerCarPhysics
//   D_00584610  5 x 0x1580  CB3CollidingBody -> CB3VehiclePhysics -> CB3AICarPhysics
//   D_0058B190  5 x 0x1560  CB3CollidingBody -> CB3VehiclePhysics -> CB3NetworkCarPhysics
//   D_00591C70 64 x 0x2430  CB3VehiclePhysics -> CB3TrafficPhysics
//   D_00622870 32 x 0x780   CB3PropPhysics;  D_00631870 64 x 0x4E0  CB3BodyPartPhysics
//   D_0064CE40              CB3CrashScore
//   D_0064D3B0  2 x 0x27D0  vptr at +0x1910: CB3RaceCar -> CB3AICar -> CB3PlayerCar
//   D_00652350  5 x 0x2460  CB3RaceCar -> CB3AICar;  D_0065D930  5 x 0x1AA0  CB3RaceCar -> D_004DDDF0
// Each base-class vptr is stored and then overwritten, as retail does. Loops that only advance a pointer (members whose
// constructors are empty) are comments here.
// TRACK: clean
// EQUIV: [L] written from the asm: every store, constructor call and loop bound accounted for; bottom-tested loops

extern unsigned char D_0057BAF0[];
extern unsigned char D_00584610[];
extern unsigned char D_0058B190[];
extern unsigned char D_00591C70[];
extern unsigned char D_00622870[];
extern unsigned char D_00631870[];
extern unsigned char D_00645070[];
extern unsigned char D_0064D3B0[];
extern unsigned char D_00652350[];
extern unsigned char D_0065D930[];
extern unsigned char D_00665E50[];
extern void * D_0064CE40;
extern unsigned char D_004DDDF0[];
extern unsigned char __vt__16CB3CollidingBody[];
extern unsigned char __vt__17CB3VehiclePhysics[];
extern unsigned char __vt__19CB3PlayerCarPhysics[];
extern unsigned char __vt__15CB3AICarPhysics[];
extern unsigned char __vt__20CB3NetworkCarPhysics[];
extern unsigned char __vt__17CB3TrafficPhysics[];
extern unsigned char __vt__14CB3PropPhysics[];
extern unsigned char __vt__18CB3BodyPartPhysics[];
extern unsigned char __vt__13CB3CrashScore[];
extern unsigned char __vt__10CB3RaceCar[];
extern unsigned char __vt__8CB3AICar[];
extern unsigned char __vt__12CB3PlayerCar[];
extern "C" void __ct__Q29GtMathPs212CGtMatrix3x3Fv(void *);
extern "C" void __ct__Q29GtMathPs26CGtV3dFv(void *);
extern "C" void __ct__19CB3TrailEmitterDataFv(void *);

// the AI / network car physics share this part of their construction (retail inlines it twice)
static inline void func_004D45E0_inl1(unsigned char * p)
{
    *(void **)p = __vt__16CB3CollidingBody;
    __ct__Q29GtMathPs26CGtV3dFv(p + 0x10);
    __ct__Q29GtMathPs26CGtV3dFv(p + 0x20);
    __ct__Q29GtMathPs26CGtV3dFv(p + 0x30);
    __ct__Q29GtMathPs26CGtV3dFv(p + 0x40);
    __ct__Q29GtMathPs26CGtV3dFv(p + 0x50);
    __ct__Q29GtMathPs26CGtV3dFv(p + 0x60);
    *(void **)p = __vt__17CB3VehiclePhysics;
    // p+0x540..0x6A0 step 0x10: empty
    unsigned char * q = p + 0x820;
    do {
        __ct__Q29GtMathPs26CGtV3dFv(q + 0x80);
        q += 0xC0;
    } while (q != p + 0xCA0);
    q = p + 0xCE0;
    do {
        __ct__Q29GtMathPs26CGtV3dFv(q);
        __ct__Q29GtMathPs26CGtV3dFv(q + 0x10);
        __ct__Q29GtMathPs26CGtV3dFv(q + 0x20);
        __ct__Q29GtMathPs26CGtV3dFv(q + 0x30);
        __ct__Q29GtMathPs26CGtV3dFv(q + 0x40);
        __ct__Q29GtMathPs26CGtV3dFv(q + 0x50);
        q += 0xC0;
    } while (q != p + 0x1160);
    // p+0x1170..0x11B0 step 0x20 and p+0x11D0..0x1350 (0x40 x 3 x 0x10): empty
}

// 0x004D45E0
extern "C" void func_004D45E0()
{
    unsigned char * p = D_0057BAF0;
    do {
        *(void **)p = __vt__16CB3CollidingBody;
        __ct__Q29GtMathPs212CGtMatrix3x3Fv(p + 0x10);
        __ct__Q29GtMathPs212CGtMatrix3x3Fv(p + 0x40);
        __ct__Q29GtMathPs26CGtV3dFv(p + 0x70);
        __ct__Q29GtMathPs26CGtV3dFv(p + 0x80);
        __ct__Q29GtMathPs26CGtV3dFv(p + 0x90);
        __ct__Q29GtMathPs26CGtV3dFv(p + 0xA0);
        __ct__Q29GtMathPs26CGtV3dFv(p + 0x160);
        __ct__Q29GtMathPs26CGtV3dFv(p + 0x170);
        __ct__Q29GtMathPs26CGtV3dFv(p + 0x180);
        __ct__Q29GtMathPs26CGtV3dFv(p + 0x1A0);
        __ct__Q29GtMathPs26CGtV3dFv(p + 0x1B0);
        __ct__Q29GtMathPs26CGtV3dFv(p + 0x1D0);
        __ct__Q29GtMathPs26CGtV3dFv(p + 0x1E0);
        *(void **)p = __vt__17CB3VehiclePhysics;
        // p+0x540..0x6A0 step 0x10: empty
        unsigned char * q = p + 0x820;
        do {
            __ct__19CB3TrailEmitterDataFv(q + 0x80);
            q += 0xC0;
        } while (q != p + 0xCA0);
        q = p + 0xCE0;
        do {
            __ct__Q29GtMathPs212CGtMatrix3x3Fv(q);
            __ct__Q29GtMathPs212CGtMatrix3x3Fv(q + 0x30);
            q += 0xC0;
        } while (q != p + 0x1160);
        // p+0x1170..0x11B0 step 0x20 and p+0x11D0..0x1350 (0x40 x 3 x 0x10): empty
        *(void **)p = __vt__19CB3PlayerCarPhysics;
        // p+0x1590..0x2A90 (0x40 x 3 x 0x10): empty
        q = p + 0x2A90;
        do {
            // [C] lqc2 / vsubw.w vf0.w - vf0.w / vaddx.w + vf2.x (= f20 = 0.0f) / sqc2: lane w becomes 0 + 0.0f,
            // lanes x, y, z are written back unchanged
            *(float *)(q + 0xC) = 0.0f + 0.0f;
            q += 0x20;
        } while (q != p + 0x3510);
        // p+0x3540..0x4140 step 0x40, 0x3890..0x38B0 / 0x38C0..0x3980 and the rest up to the object end: empty
        p += 0x4590;
    } while (p != D_00584610);
    p = D_00584610;
    do {
        func_004D45E0_inl1(p);
        *(void **)p = __vt__15CB3AICarPhysics;
        p += 0x1580;
    } while (p != D_0058B190);
    p = D_0058B190;
    do {
        func_004D45E0_inl1(p);
        *(void **)p = __vt__20CB3NetworkCarPhysics;
        p += 0x1560;
    } while (p != D_00591C70);
    p = D_00591C70;
    do {
        *(void **)p = __vt__17CB3VehiclePhysics;
        // the VehiclePhysics members (empty constructors here), then CB3TrafficPhysics's own (empty)
        *(void **)p = __vt__17CB3TrafficPhysics;
        p += 0x2430;
    } while (p != D_00622870);
    p = D_00622870;
    do {
        *(void **)p = __vt__14CB3PropPhysics;
        p += 0x780;
    } while (p != D_00631870);
    p = D_00631870;
    do {
        *(void **)p = __vt__18CB3BodyPartPhysics;
        p += 0x4E0;
    } while (p != D_00645070);
    // D_006482E0..D_00648510 (0x70 x 6 x 0x10): empty
    D_0064CE40 = __vt__13CB3CrashScore;
    p = D_0064D3B0;
    do {
        *(void **)(p + 0x1910) = __vt__10CB3RaceCar;
        *(void **)(p + 0x1910) = __vt__8CB3AICar;
        *(void **)(p + 0x1910) = __vt__12CB3PlayerCar;
        p += 0x27D0;
    } while (p != D_00652350);
    p = D_00652350;
    do {
        *(void **)(p + 0x1910) = __vt__10CB3RaceCar;
        *(void **)(p + 0x1910) = __vt__8CB3AICar;
        p += 0x2460;
    } while (p != D_0065D930);
    p = D_0065D930;
    do {
        *(void **)(p + 0x1910) = __vt__10CB3RaceCar;
        *(void **)(p + 0x1910) = D_004DDDF0;
        p += 0x1AA0;
    } while (p != D_00665E50);
}
