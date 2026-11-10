// CB3CameraData::SendRegistersToGS() const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3GraphicsManagerPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (pcpyld asm header qword + u_long128 pointer post-increment copy loop of field_1C0[4]).

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_farFogPlane {
    u_long128 * field_0;
};
class CB3CameraData {
public:
    void SendRegistersToGS() const;
    unsigned char pad_0[0x1C0];
    u_long128 field_1C0[4];
};
extern UnkStruct_farFogPlane farFogPlane;
extern "C" void _rwDMAOpenVIFPkt(int, int);
// 0x002253C0
void CB3CameraData::SendRegistersToGS() const
{
    _rwDMAOpenVIFPkt(0x80000000, 5);
    u_long128 * t0 = farFogPlane.field_0;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x1000000000008004), "r"(14));
    *t0++ = q0;
    for (int i = 0; i < 4; i++) {
        *t0++ = field_1C0[i];
    }
    farFogPlane.field_0 = t0;
}
