// CB3VehicleDeform::ImpactFlyingBit(CB3VehiclePhysics*,int,float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehicleDeform.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a154: int off=p1*4; pp=(int*)(off+(int)f18+0xAC4) fixes addu order).


struct UnkStruct_D_01E78510 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E78510 D_01E78510;
struct UnkStruct_ImpFB_cc0 { unsigned char pad_0[0x40]; void *field_40; };
struct UnkStruct_ImpFB_cc4 { unsigned char pad_0[0x101C]; unsigned char field_101C[1]; };
struct UnkStruct_ImpFB_phys { unsigned char pad_0[0xCC0]; UnkStruct_ImpFB_cc0 *field_CC0; UnkStruct_ImpFB_cc4 *field_CC4; };
struct UnkStruct_ImpFB_f18 { unsigned char pad_0[0xAC4]; int field_AC4[1]; };
struct UnkStruct_ImpFB_self {
    unsigned char pad_0[0x10];
    UnkStruct_ImpFB_cc0 *field_10;
    UnkStruct_ImpFB_cc4 *field_14;
    UnkStruct_ImpFB_f18 *field_18;
    UnkStruct_ImpFB_phys *field_1C;
};
extern "C" void DeformDoor__16CB3VehicleDeformF17EVehicleFlyingBitff(void *, int, float, float);
extern "C" void DeformBumperLikeThing__16CB3VehicleDeformF17EVehicleFlyingBit17EVirtualBoneIndex17EVirtualBoneIndex17EVirtualBoneIndexf(void *, int, int, int, int, float);
extern "C" void DeformBonnet__16CB3VehicleDeformFffb(void *, float, float, bool);
extern "C" void DeformFrontBumper__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(void *, void *, float);
extern "C" void DeformRearBumper__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(void *, void *, float);
extern "C" void DeformBoot__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(void *, void *, float);
extern "C" void DeformSpoiler__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(void *, void *, float);
extern "C" void ImpactFlyingBit__16CB3VehicleDeformFP17CB3VehiclePhysicsiff(UnkStruct_ImpFB_self *self, UnkStruct_ImpFB_phys *phys, int p1, float p2, float p3)
{
    self->field_1C = phys;
    if (self->field_1C == 0) return;
    self->field_14 = self->field_1C->field_CC4;
    if (self->field_14 == 0) return;
    self->field_10 = self->field_1C->field_CC0;
    if (self->field_10 == 0) return;
    self->field_18 = (UnkStruct_ImpFB_f18 *)self->field_10->field_40;
    if (self->field_18 == 0) return;
    if (p2 <= 0.0f) return;
    self->field_14->field_101C[p1] = 1;
    for (int i = 0; i < 8; i++) {
        int off = p1 * 4;
        int *pp = (int *)(off + (int)self->field_18 + 0xAC4);
        switch ((unsigned)self->field_18->field_AC4[p1]) {
        case 0:
        case 1:
            DeformDoor__16CB3VehicleDeformF17EVehicleFlyingBitff(self, *pp, p2, p3);
            break;
        case 2:
            DeformBumperLikeThing__16CB3VehicleDeformF17EVehicleFlyingBit17EVirtualBoneIndex17EVirtualBoneIndex17EVirtualBoneIndexf(self, 2, 0, 0, 1, p2);
            if (p3 > 0.0f) DeformFrontBumper__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(&D_01E78510, (char *)self->field_10 + 0x30, p3);
            break;
        case 3:
            DeformBumperLikeThing__16CB3VehicleDeformF17EVehicleFlyingBit17EVirtualBoneIndex17EVirtualBoneIndex17EVirtualBoneIndexf(self, 3, 4, 4, 5, p2);
            if (p3 > 0.0f) DeformRearBumper__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(&D_01E78510, (char *)self->field_10 + 0x30, p2);
            break;
        case 4:
            DeformBonnet__16CB3VehicleDeformFffb(self, p2, p3, 1);
            break;
        case 5:
            DeformBumperLikeThing__16CB3VehicleDeformF17EVehicleFlyingBit17EVirtualBoneIndex17EVirtualBoneIndex17EVirtualBoneIndexf(self, 5, 4, 4, 5, p2);
            if (p3 > 0.0f) DeformBoot__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(&D_01E78510, (char *)self->field_10 + 0x30, p3);
            break;
        case 6:
            DeformBumperLikeThing__16CB3VehicleDeformF17EVehicleFlyingBit17EVirtualBoneIndex17EVirtualBoneIndex17EVirtualBoneIndexf(self, 6, 4, 4, 5, p2);
            if (p3 > 0.0f) DeformSpoiler__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(&D_01E78510, (char *)self->field_10 + 0x30, p3);
            break;
        }
    }
}
