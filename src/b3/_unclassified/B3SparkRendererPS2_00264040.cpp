// CB3SparkArray::Construct(ESparkArrayID) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SparkRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a76: GtMath::Max chain, float m bound before mul).

// [C] name CB3SparkArray::Construct(ESparkArrayID) (mangled symbol); params table CB3SparkArrayBase::mgaArrayParams (6 x 0x7C, E map); field layout [G]. No DNAT row.
#include "b3/GtMath.h"

enum ESparkArrayID { UnkEnum_0 };

struct CB3SparkArrayParams {
    unsigned char pad_0[0x40];
    float field_40;
    float field_44;
    float field_48;
    float field_4C;
    unsigned char pad_50[0x2C];
};

class CB3SparkArray {
public:
    class CSparkBank {
    public:
        void Construct(const CB3SparkArrayParams *, bool);
        unsigned char pad_0[0x4C];
    };
    void Construct(ESparkArrayID);

    CSparkBank field_0;
    CSparkBank field_4C;
    CB3SparkArrayParams * field_98;
    int field_9C;
    float field_A0;
};

class CB3SparkArrayBase {
public:
    static CB3SparkArrayParams mgaArrayParams[6];
};

extern float D_004E1160;

// 0x00264040
void CB3SparkArray::Construct(ESparkArrayID id)
{
    field_98 = &CB3SparkArrayBase::mgaArrayParams[id];
    field_0.Construct(field_98, false);
    field_4C.Construct(field_98, true);
    field_9C = 0;
    field_A0 = GtMath::Max(field_98->field_40, field_98->field_44);
    field_A0 = GtMath::Max(field_98->field_48, field_A0);
    float m = GtMath::Max(field_98->field_4C, field_A0);
    field_A0 = m * D_004E1160;
}
