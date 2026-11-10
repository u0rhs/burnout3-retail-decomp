// CB3AIDriver::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIDriver.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CB3AIDriver;

class CB3AIDriver {
public:
    int Prepare();
    void GenerateProfile();
    int CalcDifficultyIndex();

    unsigned char pad_0[0x7B0];
    GtMathPs2::CGtV3d field_7B0;
    unsigned char pad_7C0[0x200];
    int field_9C0;
    int field_9C4;
    float field_9C8;
    int field_9CC;
    int field_9D0;
    int field_9D4;
    int field_9D8;
    int field_9DC;
    int field_9E0;
    int field_9E4;
    int field_9E8;
    int field_9EC;
    int field_9F0;
    int field_9F4;
    int field_9F8;
    float field_9FC;
    float field_A00;
    int field_A04;
    int field_A08;
    float field_A0C;
    signed char field_A10;
    unsigned char field_A11;
    unsigned char field_A12;
    unsigned char field_A13;
    unsigned char field_A14;
    unsigned char field_A15;
    unsigned char field_A16;
    unsigned char field_A17;
    unsigned char field_A18;
    unsigned char field_A19;
    unsigned char pad_A1A[0x2];
    int field_A1C;
    int field_A20;
    int field_A24;
    int field_A28;
    float field_A2C;
    unsigned char field_A30;
    unsigned char field_A31;
};

extern "C" void * memset(void *, int, unsigned int);
extern "C" int Prepare__15CB3AIArbitratorFv(void *);  // CB3AIArbitrator::Prepare()

// 0x00145D10
int CB3AIDriver::Prepare()
{
    field_A17 = 0;
    field_A12 = 0;
    field_A18 = 0;
    field_A19 = 0;
    field_9C4 = 0;
    field_9C8 = 1.0f;
    field_9C0 = 0;
    field_9CC = 0;
    field_9D0 = 0;
    field_9D4 = 0;
    field_7B0.Zero();
    field_A13 = 0;
    field_A14 = 0;
    field_A15 = 0;
    field_A16 = 0;
    field_9E0 = 0;
    field_9E4 = 0;
    field_9E8 = 0;
    field_9EC = 0;
    field_9F0 = 0;
    field_9F4 = 0;
    field_A11 = 0;
    field_9F8 = 0;
    field_A08 = 0;
    field_A10 = -1;
    field_A04 = 0;
    field_9FC = -1.0f;
    field_A00 = -1.0f;
    field_A31 = 0;
    memset(((char *)this + 0x7C0), 0, 256);
    memset(((char *)this + 0x8C0), 0, 256);
    field_A1C = 0;
    field_A20 = 0;
    field_A24 = 0;
    field_A28 = 0;
    field_A2C = -1.0f;
    field_A30 = 0;
    field_9D8 = 0;
    field_9DC = 0;
    field_A0C = -1.0f;
    int r2 = Prepare__15CB3AIArbitratorFv(this);
    if (r2 == 0) {
        return 0;
    }
    GenerateProfile();
    int r4 = CalcDifficultyIndex();
    field_A11 = r4;
    return 1;
}
