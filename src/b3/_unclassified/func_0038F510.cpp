// OnNetworkCarDeath__26CB3OnlineRoadRageRaceLogicFP13CB3NetworkCar -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0038F510_a1;

struct UnkStruct_0038F510_a1 {
    unsigned char pad_0[0x1161];
    unsigned char field_1161;
};

// 0x0038F510
extern "C" void OnNetworkCarDeath__26CB3OnlineRoadRageRaceLogicFP13CB3NetworkCar(int n0, UnkStruct_0038F510_a1 * p0)
{
    if (p0->field_1161 != 0) return;
    p0->field_1161 = 1;
}
