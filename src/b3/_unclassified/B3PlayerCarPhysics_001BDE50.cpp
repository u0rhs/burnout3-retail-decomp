// CB3PlayerCarPhysics::Prepare(CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PlayerCarPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a74: standalone decl (header-owned class), operand order &D==p, field_217 signed char).

class CB3RaceCar;
struct UnkStruct_D_0064D3B0 {
    unsigned char pad_0[0x10C4];
};
extern UnkStruct_D_0064D3B0 D_0064D3B0;
extern "C" void * memset(void *, int, unsigned int);

struct CB3WrongWayWall {
    void Prepare();
};
struct CB3AICarPhysics {
    void Prepare(CB3RaceCar *);
};
struct CB3PlayerCarPhysics : CB3AICarPhysics {
    int Prepare(CB3RaceCar * p0);

    unsigned char pad_0[0x217];
    signed char field_217;
    unsigned char pad_218[0x13FC - 0x218];
    unsigned char field_13FC;
    unsigned char pad_13FD[0x1580 - 0x13FD];
    CB3RaceCar * field_1580;
    unsigned char pad_1584[0x1590 - 0x1584];
    CB3WrongWayWall mWrongWayWall;
    unsigned char pad_1591[0x3530 - 0x1591];
    float field_3530;
    float field_3534;
    float field_3538;
    int field_353C;
    unsigned char field_3540[0x1040];
    unsigned char field_4580;
    unsigned char field_4581;
    unsigned char pad_4582[2];
    unsigned char field_4584;
    unsigned char pad_4585;
    unsigned char field_4586;
    unsigned char field_4587;
    unsigned char field_4588;
    unsigned char pad_4589[3];
    int field_458C;
};

// 0x001BDE50
int CB3PlayerCarPhysics::Prepare(CB3RaceCar * p0)
{
    field_1580 = p0;
    CB3AICarPhysics::Prepare(p0);
    mWrongWayWall.Prepare();
    field_3530 = 1.0f;
    if (field_1580 != 0) {
        if ((void *)&D_0064D3B0 == (void *)field_1580) {
            field_217 = 0;
        } else {
            field_217 = 1;
        }
    }
    field_3530 = 1.0f;
    field_13FC = 0;
    field_3534 = -1.0f;
    field_3538 = 0.0f;
    field_4580 = 0;
    field_4581 = 0;
    field_4584 = 0;
    field_4586 = 0;
    field_4587 = 0;
    field_4588 = 0;
    field_458C = field_217;
    field_353C = 0;
    memset(field_3540, 0, 0x1040);
    return 1;
}
