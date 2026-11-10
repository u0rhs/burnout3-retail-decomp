// CB3DebugManager::RenderWorld() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DebugManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (a73: statics via B3Im3d::; n%2>0 idiom; empty-ctor/dtor local reserves retail's 16-byte frame slot).

// from build/vt\try_RenderWorld__15CB3DebugManagerFv_best.cpp
// CB3DebugManager::RenderWorld() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DebugManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtTexture;
class CB3Im3dVertex;

class B3Im3d;
class CB3AIDebug;
class CB3CrashAnalyser;
class CB3DebugManager;
class CB3PhysicsManagerDebug;
class CB3TrafficDebug;
struct UnkStruct__gaDebugPointsArray;
struct UnkStruct__gnDebugNumPoints;

class CB3AIDebug {
public:
    void RenderWorld();
};

class CB3PhysicsManagerDebug {
public:
    void RenderWorld();
};

class CB3TrafficDebug {
public:
    void RenderWorld();
};

class CB3CrashAnalyser {
public:
    void RenderDebug();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class B3Im3d {
public:
    static void BeginRendering();
    static void SetTexture(CGtTexture*);
    static void RenderLinelist(const CB3Im3dVertex*, int);
    static void EndRendering();
};

struct UnkStruct__gnDebugNumPoints {
    int field_0;
};

struct UnkStruct__gaDebugPointsArray {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3DebugManager {
public:
    void RenderWorld();

    unsigned char pad_0[0x10];
    CB3AIDebug field_10;
    unsigned char pad_11[0x6FF];
    CB3PhysicsManagerDebug field_710;
    unsigned char pad_711[0x1EDF];
    CB3TrafficDebug field_25F0;
};

extern UnkStruct__gnDebugNumPoints _gnDebugNumPoints;
extern CB3CrashAnalyser D_0064A8F0;
extern CB3CrashAnalyser D_0064B940;
extern UnkStruct__gaDebugPointsArray _gaDebugPointsArray;

// [G] placeholder pad type: a local with an (empty) user ctor/dtor reserves retail's unused 16-byte frame slot (N140).
struct UnkStruct_001308B0_pad {
    unsigned char field_0[0x4];
    UnkStruct_001308B0_pad() {}
    ~UnkStruct_001308B0_pad() {}
};

// 0x001308B0
void CB3DebugManager::RenderWorld()
{
    UnkStruct_001308B0_pad pad;  // [G] unused local object: retail keeps 0x10 unused frame bytes (known.md N140)
    field_10.RenderWorld();
    field_710.RenderWorld();
    field_25F0.RenderWorld();
    D_0064A8F0.RenderDebug();
    D_0064B940.RenderDebug();
    if (_gnDebugNumPoints.field_0 % 2 > 0) {
        _gnDebugNumPoints.field_0 = _gnDebugNumPoints.field_0 - 1;
    }
    if (_gnDebugNumPoints.field_0 > 0) {
        B3Im3d::BeginRendering();
        B3Im3d::SetTexture(0);
        B3Im3d::RenderLinelist((const CB3Im3dVertex*)&_gaDebugPointsArray, _gnDebugNumPoints.field_0);
        B3Im3d::EndRendering();
        _gnDebugNumPoints.field_0 = 0;
    }
}
