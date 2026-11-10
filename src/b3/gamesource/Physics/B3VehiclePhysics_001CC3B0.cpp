// B3VehiclePhysics.cpp (E map). Local fork unit.
#include "b3/gamesource/Physics/B3VehiclePhysics.h"

// 0x1CC3B0
void CB3VehiclePhysics::DetachAll(bool bFlap)
{
    for (int b = 0; b < 7; b++) {
        int idx = CB3VehicleDeform::GetFlyingObjectIndex(field_cc0->field_40, (EVehicleFlyingBit)b);
        if (idx >= 0) {
            if (bFlap) {
                if (field_cc4->field_4b2[idx] == 0 || field_cc4->field_4b2[idx] == 1)
                    field_cc4->field_4b2[idx] = 2;
            } else {
                field_cc4->field_f90[idx] = 1000.0f;  // E: 2.0f
            }
        }
    }
    for (int w = 0; w < mnNumWheels; w++) {
        if (field_cc4->field_4ac[w] == 0 || field_cc4->field_4ac[w] == 1)
            field_cc4->field_4ac[w] = 2;
        if (!bFlap)
            field_cc4->field_f78[w] = 2.0f;
    }
}
