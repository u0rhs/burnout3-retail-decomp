// CB3StageLogic::FlapNewBodyPart(CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StageLogic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (dperm (decomp-permuter, background run): UnkStruct_00395E90_3 *new_var;; new_var = t1;; r0 = GetFlyingObjectIndex__16CB3VehicleDeformFP14CB3VehicleData17EVehicleFlyingBit((CB3VehicleData *) t1->field_CC0->field_40, (EVehicleFlyingBit) D_004C9900[i]);; r0 = GetFlyingObjectIndex__16CB3VehicleDeformFP14CB3VehicleData17EVehicleFlyingBit((CB3Ve).

class CB3RaceCar;
class CB3VehicleData;
enum EVehicleFlyingBit {};
class CB3VehiclePhysics;

class CB3StageLogic;
struct CB3RaceCar;
struct UnkStruct_00395E90_3;
struct UnkStruct_00395E90_4;
struct UnkStruct_00395E90_8;
struct UnkStruct_00395E90_e0;
struct UnkStruct_D_0055EFEC;

struct CB3RaceCar {
    unsigned char pad_0[0x1960];
    unsigned long field_1960;
    unsigned char pad_1968[0x44];
    signed char field_19AC;
};

struct UnkStruct_00395E90_e0 {
    UnkStruct_00395E90_3 * field_0;
    unsigned char pad_4[0x2C];
};

struct UnkStruct_D_0055EFEC {
    UnkStruct_00395E90_e0 field_0[1];  
};

struct UnkStruct_00395E90_3 {
    unsigned char pad_0[0x215];
    signed char field_215;
    unsigned char pad_216[0xAAA];
    UnkStruct_00395E90_4 * field_CC0;
    UnkStruct_00395E90_8 * field_CC4;
};

struct UnkStruct_00395E90_4 {
    unsigned char pad_0[0x40];
    int field_40;
};

struct UnkStruct_00395E90_8 {
    unsigned char pad_0[0x4B2];
    signed char field_4B2[1];  
};

class CB3StageLogic {
public:
    void FlapNewBodyPart(CB3RaceCar* p0);
};

extern UnkStruct_D_0055EFEC D_0055EFEC;
extern int D_004C9900[];  

extern "C" int GetFlyingObjectIndex__16CB3VehicleDeformFP14CB3VehicleData17EVehicleFlyingBit(void *, EVehicleFlyingBit);  
extern "C" void ImpactFlyingBit__16CB3VehicleDeformFP17CB3VehiclePhysicsiff(void *, void *, int, float, float);  
extern "C" void ImpactRoadRage__16CB3VehicleDeformFP17CB3VehiclePhysicsiff(void *, void *, long, float, float, int);  
extern "C" void func_001CBE50(UnkStruct_00395E90_3 *, int);









// 0x00395E90
void CB3StageLogic::FlapNewBodyPart(CB3RaceCar *p0)
{
  int i;
  int r0;
  signed char t0 = p0->field_19AC;
  UnkStruct_00395E90_3 *t1 = D_0055EFEC.field_0[t0].field_0;
  UnkStruct_00395E90_3 *v0;
  v0 = t1;
  for (i = 0; i < 7; i++)
  {
    r0 = GetFlyingObjectIndex__16CB3VehicleDeformFP14CB3VehicleData17EVehicleFlyingBit((CB3VehicleData *) v0->field_CC0->field_40, (EVehicleFlyingBit) D_004C9900[i]);
    if (r0 < 0)
    {
      continue;
    }
    UnkStruct_00395E90_8 *t2;
    if (v0->field_CC4->field_4B2[r0] != 0)
    {
      continue;
    }
    if (v0->field_215 == 1)
    {
      ImpactFlyingBit__16CB3VehicleDeformFP17CB3VehiclePhysicsiff(((char *) v0->field_CC4) - -0x300, (CB3VehiclePhysics *) v0, r0, 1.0f, 0.5f);
    }
    ImpactRoadRage__16CB3VehicleDeformFP17CB3VehiclePhysicsiff((void *) (((char *) v0->field_CC4) + 768), (CB3VehiclePhysics *) v0, p0->field_1960, 1.0f, 0.5f, 0);
    func_001CBE50(v0, r0);
    break;
  }

}
