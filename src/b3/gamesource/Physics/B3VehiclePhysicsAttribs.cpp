#include "b3/gamesource/Physics/B3VehiclePhysicsAttribs.h"

extern float D_004E0E00;   // unnamed global float constant, no evidence of its real name yet
extern float D_004E1038;   // unnamed global float constant, no evidence of its real name yet

void CB3VehiclePhysicsAttribs::Destruct()
{
}

void CB3VehiclePhysicsAttribs::Release()
{
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((char *)mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, &field_88);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((char *)mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, &field_8C);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((char *)mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, &field_98);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((char *)mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, &field_90);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((char *)mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, &field_94);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((char *)mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, &field_A8);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((char *)mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, &field_A4);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((char *)mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, &field_9C);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((char *)mpToolBase__Q27GtComms16CGtCommsToolBase + 0x10, &field_A0);
}

// Hand-inlined, same reasoning as N37/N38/N43: the compiler's FPU scheduler batches independent
// int-to-float conversion setup steps together regardless of source statement order (confirmed
// empirically across 3 source orderings -- a different, scalar-FPU-pipeline counterpart to the
// VU0 scheduling idiom, not fixable by reordering C++ statements).
void CB3VehiclePhysicsAttribs::Construct()
{
    asm volatile(
        "ori      $v1, $zero, 0xEA60"   "\n\t"
        "sb       $zero, 0x0(%0)"       "\n\t"
        "mtc1     $v1, $f0"             "\n\t"
        "lui      $a1, 0x447A"          "\n\t"
        "lwc1     $f3, D_004E0E00"      "\n\t"
        "sw       $a1, 0x88(%0)"        "\n\t"
        "cvt.s.w  $f2, $f0"             "\n\t"
        "addiu    $v1, $zero, 0x1388"   "\n\t"
        "mtc1     $v1, $f0"             "\n\t"
        "swc1     $f3, 0x98(%0)"        "\n\t"
        "cvt.s.w  $f1, $f0"             "\n\t"
        "lwc1     $f0, D_004E1038"      "\n\t"
        "swc1     $f2, 0x90(%0)"        "\n\t"
        "swc1     $f1, 0x94(%0)"        "\n\t"
        "swc1     $f0, 0x8C(%0)"        "\n\t"
        "swc1     $f3, 0xA4(%0)"        "\n\t"
        "swc1     $f2, 0x9C(%0)"        "\n\t"
        "swc1     $f1, 0xA0(%0)"        "\n\t"
        "swc1     $f0, 0xA8(%0)"
        :
        : "r"(this)
        : "v1", "a1", "f0", "f1", "f2", "f3"
    );
}
