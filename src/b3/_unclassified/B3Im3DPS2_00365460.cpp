// B3Im3d::SetZWrite(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Im3DPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (dperm (decomp-permuter, background run): nx = t0 + 1;).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class B3Im3d;
struct UnkStruct_00365460_1;
struct UnkStruct_00365460_3;
struct UnkStruct_farFogPlane;

struct UnkStruct_farFogPlane {
    UnkStruct_00365460_1 * field_0;
};

struct UnkStruct_00365460_1 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
};

struct UnkStruct_00365460_3 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
};

class B3Im3d {
public:
    static void SetZWrite(bool p0);
    static UnkStruct_00365460_3 * _gpau128Registers;
};

extern UnkStruct_farFogPlane farFogPlane;

extern "C" void _rwDMAOpenVIFPkt(int, int);






// 0x00365460
void B3Im3d::SetZWrite(bool p0)
{
  _rwDMAOpenVIFPkt(0, 3);
  UnkStruct_00365460_1 *t0 = farFogPlane.field_0;
  u_long128 q0;
asm ( "pcpyld %0, %2, %1" : "=r" ( q0 ) : "r" ( 0x10000002 ) , "r" ( 0x5000000211000000 ) ) ;
  u_long128 q1;
asm ( "pcpyld %0, %2, %1" : "=r" ( q1 ) : "r" ( 0x1000000000008001 ) , "r" ( 14 ) ) ;
  t0->field_0 = q0;
  t0->field_10 = q1;
  UnkStruct_00365460_1 *nx;
  if (p0)
  {
    nx = t0 + 1;
    t0->field_20 = B3Im3d::_gpau128Registers->field_10;
  }
  else
  {
    nx = t0 + 1;
    u_long128 q2;
asm ( "pcpyld %0, %2, %1" : "=r" ( q2 ) : "r" ( ( ( unsigned long ) B3Im3d::_gpau128Registers -> field_10 | ( ( unsigned long ) 1 << 32 ) ) ) , "r" ( 78 ) ) ;
    t0->field_20 = q2;
    nx = t0 + 1;
  }
  farFogPlane.field_0 = nx;
}
