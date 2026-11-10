// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// CB3DebrisArray::Construct(EDebrisGeometry) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DebrisRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (int *pp = &_ga[p0]; n = *pp << 6; ... int t1 = *pp; stores -- pointer-to-element local makes the reload schedule before the field stores).

// CB3DebrisArray::Construct(EDebrisGeometry) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DebrisRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EDebrisGeometry {};

class CB3DebrisArray;
class CB3EffectsManager;

class CB3EffectsManager {
public:
    static int Alloc(unsigned int, unsigned int);
};

class CB3DebrisArray {
public:
    void Construct(EDebrisGeometry p0);
    void ConstructGeometryData(EDebrisGeometry);

    unsigned char pad_0[0x14];
    int field_14;
    int field_18;
};

extern int _gaDebrisArrayParams[];  // [G] element count unknown

extern "C" void * memset(void *, int, unsigned int);

// 0x002F49A0
void CB3DebrisArray::Construct(EDebrisGeometry p0)
{
    ConstructGeometryData(p0);
    int * pp = &_gaDebrisArrayParams[p0];
    int n = *pp << 6;
    int r1 = CB3EffectsManager::Alloc(n, 16);
    memset((void *)r1, 0, n);
    int t1 = *pp;
    field_14 = r1;
    field_18 = t1;
}
