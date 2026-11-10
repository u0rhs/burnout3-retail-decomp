// func_00157380 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (dperm (decomp-permuter, background run): OnTradePaint__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb(g->field_0[b].field_0, (CB3RaceCarPhysics *) g->field_0[a].field_0, (CB3RaceCarPhysics *) p1, f0, b);; if (b); {; OnTradePaint__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb((&D_0055EFEC)->field_0[b].field_0, (CB3RaceCarPhysic).

class CB3RaceCarPhysics;

class CB3Score;
struct UnkStruct_00157380;
struct UnkStruct_00157380_2;
struct UnkStruct_00157380_a1;
struct UnkStruct_00157380_e0;
struct UnkStruct_D_0055EFEC;

class CB3Score {
public:
    void OnTradePaint(CB3RaceCarPhysics*, CB3RaceCarPhysics*, float, bool);
};

struct UnkStruct_00157380_a1 {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};

struct UnkStruct_00157380_2 {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};

struct UnkStruct_00157380_e0 {
    CB3Score * field_0;
    unsigned char pad_4[0x2C];
};

struct UnkStruct_D_0055EFEC {
    UnkStruct_00157380_e0 field_0[1];  
};

struct UnkStruct_00157380 {
    unsigned char pad_0[0xC8];
    UnkStruct_00157380_2 * field_C8;
};

extern UnkStruct_D_0055EFEC D_0055EFEC;


extern "C" void OnTradePaint__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb(CB3Score *, CB3RaceCarPhysics *, CB3RaceCarPhysics *, float, signed char);
extern "C" void func_00157380 ( UnkStruct_00157380 * self , UnkStruct_00157380_a1 * p0 , int p1 , float f0 );







// 0x00157380
void func_00157380(UnkStruct_00157380 *self, UnkStruct_00157380_a1 *p0, int p1, float f0)
{
  UnkStruct_D_0055EFEC * const g = &D_0055EFEC;
  signed char b = self->field_C8->field_19AC;
  signed char a = p0->field_19AC;
  if (b)
  {
    OnTradePaint__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb((&D_0055EFEC)->field_0[b].field_0, (CB3RaceCarPhysics *) (&D_0055EFEC)->field_0[a].field_0, (CB3RaceCarPhysics *) p1, f0, b);
  }
  else
  {
    OnTradePaint__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb((&D_0055EFEC)->field_0[b].field_0, (CB3RaceCarPhysics *) (&D_0055EFEC)->field_0[a].field_0, (CB3RaceCarPhysics *) p1, f0, b);
  }
 do { } while (0);
}
