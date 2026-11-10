// Hand-written; the lifter refused it (a162: body-part allocator (free-bit mask / oldest-part reuse); hand-written from asm, break-out of find loop, self-> extern C).

// func_001B86A0 -- hand-written (body-part allocation; Prepare/GetIntervals callees named in retail)
class UnkStruct_001B86A0_q {
public:
    unsigned char pad_0[0x4AC];
    unsigned char field_4AC[6];
    unsigned char field_4B2[1];
};
struct UnkStruct_001B86A0_o {
    unsigned char pad_0[0xCC4];
    UnkStruct_001B86A0_q *field_CC4;
};
class UnkStruct_001B86A0_part {
public:
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10(int, int);
    unsigned char pad_4[0x1CC];
    int field_1D0;
    unsigned char pad_1D4[0x30];
    int field_204;
    unsigned char pad_208[0xA8];
    UnkStruct_001B86A0_o *field_2B0;
    float field_2B4;
    short field_2B8;
    unsigned char field_2BA;
    unsigned char pad_2BB[0x225];
};
struct UnkStruct_001B86A0_vp {
    unsigned char pad_0[0x210];
    unsigned char field_210;
    unsigned char pad_211[7];
    signed char field_218;
};
struct UnkStruct_001B86A0_e {
    signed char field_0;
    unsigned char field_1;
    unsigned char field_2;
    int field_4;
    int field_8;
    void *field_C;
    unsigned char pad_10[0x20];
};
extern "C" void Prepare__18CB3BodyPartPhysicsFP17CB3VehiclePhysicsi13EBodyPartType(void *, void *, int, int);
class CB3ActiveBody;
class CB3PhysicsManager;
extern "C" void func_001B7E10(CB3PhysicsManager *, int);
class CB3PhysicsManager {
public:
    void GetIntervals(CB3ActiveBody *);
    unsigned char pad_0[0x70];
    UnkStruct_001B86A0_e field_70[2448];
    int field_1CB70;
    unsigned char pad_1CB74[0xB5D8C];
    UnkStruct_001B86A0_part field_D2900[64];
    unsigned char pad_end[0x3118];
    unsigned long field_E9218;
};
// 0x001B86A0
extern "C" UnkStruct_001B86A0_part *func_001B86A0(CB3PhysicsManager *self, UnkStruct_001B86A0_vp *vp, int p2, int p3)
{
    UnkStruct_001B86A0_part *part;
    int idx;
    unsigned long bit;
    if (self->field_E9218 == (unsigned long)-1) {
        float best = -1.0f;
        int i;
        bit = 1;
        for (i = 0; i < 64; i++, bit <<= 1) {
            float f = self->field_D2900[i].field_2B4;
            if (f > best) {
                best = f;
                idx = i;
            }
        }
        part = &self->field_D2900[idx];
        switch (part->field_2BA) {
        case 2:
            break;
        case 1:
            part->field_2B0->field_CC4->field_4B2[self->field_D2900[idx].field_2B8] = 4;
            break;
        case 0:
            part->field_2B0->field_CC4->field_4AC[self->field_D2900[idx].field_2B8] = 4;
            break;
        }
        Prepare__18CB3BodyPartPhysicsFP17CB3VehiclePhysicsi13EBodyPartType(part, vp, p2, p3);
        if (vp->field_210 != 0) {
            part->vfunc_10(vp->field_218, 0);
        }
        for (int j = 0; j < self->field_1CB70; j++) {
            UnkStruct_001B86A0_e *e = &self->field_70[j];
            if (e->field_0 == 7 && e->field_2 == idx) {
                e->field_4 = part->field_204;
                e->field_8 = (int)&part->field_1D0;
                e->field_1 = 0;
                self->GetIntervals((CB3ActiveBody *)e);
                break;
            }
        }
        return part;
    }
    bit = 1;
    idx = 0;
    while (idx < 64) {
        if ((self->field_E9218 & bit) == 0) {
            break;
        }
        bit <<= 1;
        idx++;
    }
    if (idx == 64) {
        return 0;
    }
    self->field_E9218 |= bit;
    part = &self->field_D2900[idx];
    Prepare__18CB3BodyPartPhysicsFP17CB3VehiclePhysicsi13EBodyPartType(part, vp, p2, p3);
    if (vp->field_210 != 0) {
        part->vfunc_10(vp->field_218, 0);
    }
    UnkStruct_001B86A0_e *e = &self->field_70[self->field_1CB70];
    e->field_0 = 7;
    e->field_C = part;
    e->field_4 = part->field_204;
    e->field_8 = (int)&part->field_1D0;
    e->field_1 = 0;
    e->field_2 = idx;
    self->GetIntervals((CB3ActiveBody *)e);
    func_001B7E10(self, self->field_1CB70);
    self->field_1CB70++;
    return part;
}
