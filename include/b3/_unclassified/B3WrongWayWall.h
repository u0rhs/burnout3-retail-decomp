#ifndef B3_B3WRONGWAYWALL_H
#define B3_B3WRONGWAYWALL_H

// [C] class and method names: retail's own tables (research/retail_names.csv -> B3WrongWayWall.cpp, high,
// "direct+chain agree"). Area not evidenced, so _unclassified/. Embedded in CB3PlayerCarPhysics at +0x1590
// (B3PlayerCarPhysics.h). Full size unknown: at least 0x1F9A, since Construct() writes +0x1F99.
struct CB3WrongWayWall
{
    void Destruct();    // 0x0019B750 [C] empty
    void Release();     // 0x0019B760 [C] empty
    void Construct();   // 0x0019D4B0 [C]

    unsigned char pad_0[0x1F80];
    // [C] Construct() zeroes these four; types are [G] from the store widths.
    int field_1F80;
    int field_1F84;
    int field_1F88;
    unsigned char pad_1F8C[0xD];
    unsigned char field_1F99;
};

#endif
