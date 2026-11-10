// CB3RacePosition::DrawTrafficValues() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RacePosition.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a92: bool began, decl order r,n,i,b,c).

class CB3VehiclePhysics;
struct UnkStruct_D_0051BA88 {
    void * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_0051A9E0 {
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_0064517C {
    int field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_0064CE40 {
    unsigned char pad_0[0x10];
};
extern unsigned char D_00522660[];
class CB3RacePosition {
public:
    void DrawTrafficValues();
    void DrawSingleVehicleValue(CB3VehiclePhysics *, int, int, float, bool);
};
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0051A9E0 D_0051A9E0;
extern UnkStruct_D_0064517C D_0064517C;
extern UnkStruct_D_0064CE40 D_0064CE40;
extern "C" int func_003CCA70(void *, void *);
extern "C" void Begin__12Gt2dRendererFv();
extern "C" void func_00217E70(int);
extern "C" void End__12Gt2dRendererFv();
extern "C" void SetTextureFilterMode__12Gt2dRendererFQ212Gt2dRenderer19EGt2dRendererFilter(int);
extern "C" void EnableZTest__12Gt2dRendererFb(bool);

// 0x00154230
void CB3RacePosition::DrawTrafficValues()
{
    int r;
    int n;
    int i;
    bool began = false;
    CB3VehiclePhysics * car;
    if (D_0051BA88.field_0 == (void *)&D_0051A9E0) {
        return;
    }
    n = D_0064517C.field_0;
    for (i = 0; i < n; i++) {
        car = *(CB3VehiclePhysics **)(D_00522660 + i * 4 + 0x122A10);
        r = func_003CCA70(&D_0064CE40, car);
        if (!began) {
            began = true;
            Begin__12Gt2dRendererFv();
            func_00217E70(0);
            SetTextureFilterMode__12Gt2dRendererFQ212Gt2dRenderer19EGt2dRendererFilter(0);
            EnableZTest__12Gt2dRendererFb(false);
        }
        DrawSingleVehicleValue(car, i, r, 0.5f, false);
    }
    if (began) {
        End__12Gt2dRendererFv();
    }
}
