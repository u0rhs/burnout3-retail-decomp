// Render__18CB3MenuPageManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (a70: Render call guarded by ||, u_long128* stores, c const after call, q0 asm before ptr load).

// Render__18CB3MenuPageManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_0030D6E0;
struct UnkStruct_0030D6E0_1;
struct UnkStruct_D_01E8E8AA;
struct UnkStruct_farFogPlane;

struct UnkStruct_farFogPlane {
    UnkStruct_0030D6E0_1 * field_0;
};

struct UnkStruct_0030D6E0_1 {
    u_long128 field_0;
    u_long128 field_10;
};

struct UnkStruct_D_01E8E8AA {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0030D6E0 {
    unsigned char pad_0[0x1F0];
    int field_1F0;
};

extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_D_01E8E8AA D_01E8E8AA;

extern "C" void Render__10CGt2dSceneFv(void *);  // CGt2dScene::Render()
extern "C" void _rwDMAOpenVIFPkt(int, int);

// [L] DNAT: CB3MenuPageManager::Render() (research/proto/new_names.csv, high)
// 0x0030D6E0
extern "C" void Render__18CB3MenuPageManagerFv(UnkStruct_0030D6E0 * self)
{
    _rwDMAOpenVIFPkt(0x80000000, 2);
    unsigned long c = 0x1000000000008001;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(c), "r"(14));
    u_long128 * t0 = (u_long128 *)farFogPlane.field_0;
    u_long128 q1;
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"(0x41001), "r"(71));
    t0[0] = q0;
    t0[1] = q1;
    farFogPlane.field_0++;
    if (self->field_1F0 != 0 || D_01E8E8AA.field_0 != 0) {
        Render__10CGt2dSceneFv(((char *)self + 0x1A0));
    }
    _rwDMAOpenVIFPkt(0x80000000, 2);
    u_long128 * t1 = (u_long128 *)farFogPlane.field_0;
    u_long128 q2;
    asm("pcpyld %0, %2, %1" : "=r"(q2) : "r"(c), "r"(14));
    u_long128 q3;
    asm("pcpyld %0, %2, %1" : "=r"(q3) : "r"(0x50003), "r"(71));
    t1[0] = q2;
    t1[1] = q3;
    farFogPlane.field_0++;
}
