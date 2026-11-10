// CB3VehicleRenderer::FixUpVehicleData(CB3VehicleData*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehicleRendererRuntime.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): p->field_64 = (UnkStruct_FUVD_hdr *) (((int) p->field_64) + ((int) p));; h = (UnkStruct_FUVD_hdr *) (((int) p->field_64) + ((int) p));; p->field_64 = h;).

struct UnkStruct_FUVD_ent { int field_0; void *field_4; int field_8; int field_C; };
struct UnkStruct_FUVD_hdr { signed char field_0; unsigned char pad_1[3]; UnkStruct_FUVD_ent *field_4; };
struct UnkStruct_FUVD_ent12 { int field_0; int field_4; int field_8; };
struct UnkStruct_FUVD_p {
    unsigned char pad_0[0x4C];
    void *field_4C[5];
    void *field_60;
    UnkStruct_FUVD_hdr *field_64;
    UnkStruct_FUVD_hdr *field_68;
    unsigned char pad_6C[0xFF4];
    unsigned char field_1060[0x604];
    void *field_1664[18];
    unsigned char pad_16AC[0x14];
    UnkStruct_FUVD_ent12 *field_16C0;
    void *field_16C4;
    signed char field_16C8;
    unsigned char pad_16C9[0x13];
    void *field_16DC[2];
};
class CB3VehicleData;
class CB3VehicleRenderer {
public:
    int FixUpVehicleData(CB3VehicleData *);
};
extern "C" void FixUp__10CGtTextureFv(void *);
extern "C" void func_002FB240(void *);
extern "C" void FixUp__21CB3VehicleLODDataBaseFv(void *);
extern "C" void Fixup__13CB3ConvexHullFv(void *);








// 0x00220B70
int CB3VehicleRenderer::FixUpVehicleData(CB3VehicleData *vd)
{
  UnkStruct_FUVD_p *p = (UnkStruct_FUVD_p *) vd;
  UnkStruct_FUVD_hdr *h;
  int i;
  if (p->field_60 != 0)
  {
    p->field_60 = (void *) (((int) p->field_60) + ((int) p));
    FixUp__10CGtTextureFv(p->field_60);
  }
  for (i = 0; i < 5; i++)
  {
    void **pp = &p->field_4C[i];
    if ((*pp) != 0)
    {
      *pp = (void *) (((int) (*pp)) + ((int) p));
      FixUp__21CB3VehicleLODDataBaseFv(*pp);
    }
  }

  if (p->field_64 != 0)
  {
    h = (UnkStruct_FUVD_hdr *) (((int) p->field_64) + ((int) p));
    p->field_64 = h;
    h = p->field_64;
    h->field_4 = (UnkStruct_FUVD_ent *) (((int) h->field_4) + ((int) h));
    for (i = 0; i < h->field_0; i++)
    {
      UnkStruct_FUVD_ent *e = &h->field_4[i];
      e->field_0 += (int) e;
      if (e->field_4 != 0)
      {
        e->field_4 = (void *) (((int) e->field_4) + ((int) e));
      }
    }

  }
  if (p->field_68 != 0)
  {
    p->field_68 = (UnkStruct_FUVD_hdr *) (((int) p->field_68) + ((int) p));
    h = p->field_68;
    h->field_4 = (UnkStruct_FUVD_ent *) (((int) h->field_4) + ((int) h));
    for (i = 0; i < h->field_0; i++)
    {
      UnkStruct_FUVD_ent *e = &h->field_4[i];
      e->field_0 += (int) e;
      if (e->field_4 != 0)
      {
        e->field_4 = (void *) (((int) e->field_4) + ((int) e));
      }
    }

  }
  for (i = 0; i < 18; i++)
  {
    void **pp = &p->field_1664[i];
    if ((*pp) != 0)
    {
      *pp = (void *) (((int) (*pp)) + ((int) p));
    }
  }

  if (p->field_16C4 != 0)
  {
    p->field_16C4 = (void *) (((int) p->field_16C4) + ((int) p));
  }
  if (p->field_16C0 != 0)
  {
    p->field_16C0 = (UnkStruct_FUVD_ent12 *) (((int) p->field_16C0) + ((int) p));
    for (i = 0; i < p->field_16C8; i++)
    {
      UnkStruct_FUVD_ent12 *e = &p->field_16C0[i];
      e->field_8 = (int) (((char *) p) + e->field_8);
    }

  }
  Fixup__13CB3ConvexHullFv(p->field_1060);
  for (i = 0; i < 2; i++)
  {
    void **pp = &p->field_16DC[i];
    if ((*pp) != 0)
    {
      *pp = (void *) (((int) (*pp)) + ((int) p));
      func_002FB240(*pp);
    }
  }

  return 1;
}
