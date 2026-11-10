// CB3SoundCrashManager::GenericGlassSmash(CB3VehiclePhysics*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (hand-written: this passes through to func_0027FFF0/002802B0 (a0 untouched); if/else then return gives retail's nop-delay b).

class CB3VehiclePhysics {
public:
    unsigned char pad_0[0x204];
    char * field_204;
};
class CB3SoundCrashManager {
public:
    void GenericGlassSmash(CB3VehiclePhysics *);
    unsigned char pad_0[0x520];
    int field_520;
    int field_524;
    unsigned char pad_528[0x80];
    float field_5A8;
    unsigned char pad_5AC[0x8C6 - 0x5AC];
    signed char field_8C6;
};
extern "C" void func_0027FFF0(CB3SoundCrashManager *, float, void *, int);
extern "C" void func_002802B0(CB3SoundCrashManager *, float, void *, int);

// 0x00280860
void CB3SoundCrashManager::GenericGlassSmash(CB3VehiclePhysics * p0)
{
    if (field_8C6 == 0) {
    field_520 = (field_520 << 16) + (field_520 >> 16);
    field_520 = field_520 + field_524;
    field_524 = field_524 + field_520;
        if ((unsigned int)field_520 % 10 < 5) {
            func_0027FFF0(this, field_5A8, p0->field_204 + 0x30, 0);
        } else {
            func_002802B0(this, field_5A8, p0->field_204 + 0x30, 0);
        }
        return;
    }
}
