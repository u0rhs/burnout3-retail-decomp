// CB3Bloom::Blend(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,bool,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BloomPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (dperm (decomp-permuter, background run): q = p + 8;; q = p + 8;).

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_farFogPlane {
    u_long128 * field_0;
};

struct UnkStruct_D_006662D0 {
    unsigned int field_0;
    unsigned char pad_4[0xC];  
};

class CB3Bloom {
public:
    void Blend(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, bool p6, bool p7);

    unsigned char pad_0[0x8];
    float field_8;
};

extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_D_006662D0 D_006662D0;





// 0x00264C30
void CB3Bloom::Blend(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, bool p6, bool p7)
{
  unsigned int n = ((p0 >> 2) + 31) >> 5;
  u_long128 *p = farFogPlane.field_0;
asm ( "pcpyld %0, %2, %1" : "=r" ( p [ 0 ] ) : "r" ( 0x10AB400000000006UL ) , "r" ( 14 ) ) ;
asm ( "pcpyld %0, %2, %1" : "=r" ( p [ 1 ] ) : "r" ( ( D_006662D0 . field_0 >> 5 ) | 0xFF00000000030000UL ) , "r" ( 76 ) ) ;
asm ( "pcpyld %0, %2, %1" : "=r" ( p [ 2 ] ) : "r" ( ( unsigned int ) ( p4 << 5 ) | ( ( unsigned long ) p5 << 14 ) | 0x6A8000000UL ) , "r" ( 6 ) ) ;
asm ( "pcpyld %0, %2, %1" : "=r" ( p [ 3 ] ) : "r" ( 97 ) , "r" ( 20 ) ) ;
asm ( "pcpyld %0, %2, %1" : "=r" ( p [ 4 ] ) : "r" ( 0x31001 ) , "r" ( 71 ) ) ;
  unsigned long a;
  if (p7)
  {
    a = 42;
  }
  else
    if (p6)
  {
    a = 106;
  }
  else
  {
    a = (((unsigned long) ((int) (118.0f * field_8))) << 32) | 41;
  }
asm ( "pcpyld %0, %2, %1" : "=r" ( p [ 5 ] ) : "r" ( a ) , "r" ( 66 ) ) ;
asm ( "pcpyld %0, %2, %1" : "=r" ( p [ 6 ] ) : "r" ( 0x808080 ) , "r" ( 1 ) ) ;
asm ( "pcpyld %0, %2, %1" : "=r" ( p [ 7 ] ) : "r" ( ( unsigned long ) n | 0x4400000000000000UL ) , "r" ( 21331 ) ) ;
  unsigned long x;
  unsigned long u;
  unsigned int i;
  u_long128 *q;
  q = p + 8;
  x = (unsigned int) (p2 << 2);
  u = 0;
  unsigned long y3 = (unsigned int) (p3 << 2);
  unsigned long y1 = (unsigned int) (p1 << 2);
  i = 0;
  goto test;
  body:
  {
asm ( "pcpyld %0, %2, %1" : "=r" ( * q ++ ) : "r" ( u ) , "r" ( x | ( y3 << 16 ) ) ) ;
  }

  if (i < (n - 1))
  {
    x += 512;
    u += 512;
  }
  else
  {
    x = (unsigned int) ((p2 + p0) << 2);
    u = (unsigned int) (p0 << 2);
  }
asm ( "pcpyld %0, %2, %1" : "=r" ( * q ++ ) : "r" ( u | ( y1 << 16 ) ) , "r" ( x | ( ( y3 + y1 ) << 16 ) ) ) ;
  i++;
  test:
  if (i < n)
  {
    goto body;
  }

  farFogPlane.field_0 = q;
}
