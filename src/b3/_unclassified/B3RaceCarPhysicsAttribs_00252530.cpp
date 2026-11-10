// CB3RaceCarPhysicsAttribs::CopyToPhysics(CB3VehiclePhysics*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCarPhysicsAttribs.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (D_004E0D60 (.lit4 pi/180) written as the literal 0.017453292f at both cosf sites; no k local).

// CB3RaceCarPhysicsAttribs::CopyToPhysics(CB3VehiclePhysics *) -- [C] mangled name from the retail tables. Float field
// copies via a byte-offset macro, the wheel rows via a struct array; fields are placeholders, types [G].
// near12: D_004E0D60 is retail's .lit4 constant 0x3C8EFA35 = 0.017453292f (pi/180, as in other proven files): written as
// the literal at both cosf sites, its loads schedule above the aliasing stores as retail's do.

#include "b3/gamesource/Physics/B3RaceCarPhysicsAttribs.h"
#define F(o, off) (*(float *)((char *)(o) + (off)))
struct UnkStruct_00252530_row { float field_0; unsigned char pad_4[0xBC]; };
struct UnkStruct_00252530_p { unsigned char pad_0[0x894]; UnkStruct_00252530_row field_894[4]; unsigned char pad_B94[0x10C]; float field_CA0; unsigned char pad_CA4[0xC]; float field_CB0; unsigned char pad_CB4[0x4B5]; signed char field_1169; };
extern "C" float func_002527F0(float);
extern "C" float cosf(float);

// 0x00252530
void CB3RaceCarPhysicsAttribs::CopyToPhysics(CB3VehiclePhysics *physics)
{
    F(physics, 0x1F0) = F(this, 0xB8);
    F(physics, 0xCAC) = F(this, 0xC8);
    F(physics, 0xCA8) = F(this, 0xC0);
    F(physics, 0xCA4) = F(this, 0xC4);
    F(physics, 0xCA0) = F(this, 0xBC);
    F(physics, 0xCBC) = F(this, 0xD4);
    F(physics, 0xCB8) = F(this, 0xCC);
    F(physics, 0xCB4) = F(this, 0xD0);
    F(physics, 0xCB0) = F(this, 0xD8);
    for (int i = 0; i < ((UnkStruct_00252530_p *)physics)->field_1169; i++) {
        if (i < 2) {
            ((UnkStruct_00252530_p *)physics)->field_894[i].field_0 = ((UnkStruct_00252530_p *)physics)->field_CA0;
        } else {
            ((UnkStruct_00252530_p *)physics)->field_894[i].field_0 = ((UnkStruct_00252530_p *)physics)->field_CB0;
        }
    }
    F(physics, 0x1448) = F(this, 0xE0);
    F(physics, 0x144C) = F(this, 0xE4);
    F(physics, 0x1450) = F(this, 0xE8);
    F(physics, 0x1454) = F(this, 0xEC);
    F(physics, 0x1458) = F(this, 0xF0);
    F(physics, 0x145C) = F(this, 0xF4);
    F(physics, 0x1460) = F(this, 0xF8);
    F(physics, 0x1464) = F(this, 0xFC);
    F(physics, 0x1468) = F(this, 0x100);
    F(physics, 0x146C) = F(this, 0x104);
    F(physics, 0x1470) = F(this, 0x108);
    F(physics, 0x1474) = F(this, 0x10C);
    F(physics, 0x1480) = F(this, 0x118);
    F(physics, 0x1484) = F(this, 0x11C);
    F(physics, 0x148C) = func_002527F0(F(this, 0x120));
    F(physics, 0x1490) = func_002527F0(F(this, 0x124));
    F(physics, 0x1494) = F(this, 0x128);
    F(physics, 0x1498) = F(this, 0x12C);
    F(physics, 0x1360) = F(this, 0x130);
    F(physics, 0x1364) = F(this, 0x134);
    F(physics, 0x1368) = F(this, 0x138);
    F(physics, 0x136C) = F(this, 0x13C);
    F(physics, 0x1370) = F(this, 0x140);
    F(physics, 0x1374) = F(this, 0x144);
    F(physics, 0x1378) = F(this, 0x148);
    F(physics, 0x137C) = F(this, 0x14C);
    F(physics, 0x1380) = F(this, 0x150);
    F(physics, 0x1384) = F(this, 0x154);
    F(physics, 0x1388) = F(this, 0x158);
    F(physics, 0x138C) = F(this, 0x15C);
    F(physics, 0x1390) = F(this, 0x160);
    F(physics, 0x1394) = F(this, 0x164);
    F(physics, 0x1398) = F(this, 0x168);
    F(physics, 0x139C) = F(this, 0x16C);
    F(physics, 0x13A0) = F(this, 0x170);
    F(physics, 0x13A4) = F(this, 0x174);
    F(physics, 0x13A8) = F(this, 0x178);
    F(physics, 0x13AC) = F(this, 0x17C);
    F(physics, 0x13B0) = F(this, 0x180);
    F(physics, 0x13B4) = F(this, 0x184);
    F(physics, 0x13B8) = F(this, 0x188);
    F(physics, 0x13BC) = F(this, 0x18C);
    F(physics, 0x13C0) = F(this, 0x190);
    F(physics, 0x13C4) = F(this, 0x194);
    F(physics, 0x13C8) = F(this, 0x198);
    F(physics, 0x13CC) = F(this, 0x19C);
    F(physics, 0x13D0) = cosf(0.017453292f * F(this, 0x1A0));
    F(physics, 0x13D4) = F(this, 0x1A4);
    F(physics, 0x13DC) = cosf(0.017453292f * (90.0f - F(this, 0x1B4)));
    F(physics, 0x13D8) = F(this, 0x1B0);
    F(physics, 0x13E0) = F(this, 0x1BC);
    F(physics, 0x13E4) = F(this, 0x1C0);
    F(physics, 0x13E8) = F(this, 0x1C4);
    F(physics, 0x13EC) = F(this, 0x1C8);
    F(physics, 0x13F0) = F(this, 0x1CC);
}
