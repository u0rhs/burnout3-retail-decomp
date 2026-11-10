// CB3CameraAttribsCar::Release(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CameraAttribs.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (0x1B0-element array at 0x28D0 via element pointers; inline unregister helper; if/else-if chain with a no-op 'else if (t1 != 0) return;' tail).

// lifter variant 0
// CB3CameraAttribsCar::Release(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CameraAttribs.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3CameraAttribsCar;
class CB3PlayerCameraManager;
struct UnkStruct_002F8AA0_1;
struct UnkStruct_gVdbDatabase;

struct UnkStruct_002F8AA0_e0 {
    unsigned char pad_0[0xA0];
    unsigned long field_A0;
    unsigned char pad_A8[0x108];
};

struct UnkStruct_002F8AA0_1 {
    unsigned char pad_0[0x28D0];
    UnkStruct_002F8AA0_e0 field_28D0[2];  // [G] element count
};

struct UnkStruct_gVdbDatabase {
    int field_0;
};

class CB3PlayerCameraManager {
public:
    static UnkStruct_002F8AA0_1 * mgpCameraBuffer;
};

class CB3CameraAttribsCar {
public:
    static void Release(unsigned long p0);
};

extern UnkStruct_gVdbDatabase mpToolBase__Q27GtComms16CGtCommsToolBase;

extern "C" void RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(int, void *);

static inline void a51_unreg(UnkStruct_002F8AA0_e0 * e)
{
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (char *)e + 0x30);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, e);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (char *)e + 0x60);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (char *)e + 0x70);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (char *)e + 0x80);
    RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16, (char *)e + 0x90);
}

// 0x002F8AA0
void CB3CameraAttribsCar::Release(unsigned long p0)
{
    UnkStruct_002F8AA0_1 * buf = CB3PlayerCameraManager::mgpCameraBuffer;
    UnkStruct_002F8AA0_e0 * a = &buf->field_28D0[0];
    UnkStruct_002F8AA0_e0 * b = &buf->field_28D0[1];
    unsigned long t1 = a->field_A0;
    if (t1 == p0) {
        a->field_A0 = 0;
        a51_unreg(a);
    } else if (b->field_A0 == p0) {
        b->field_A0 = 0;
        a51_unreg(b);
    } else if (t1 != 0) {  // FAKEMATCH [G]: no-op branch kept for retail's layout (likely a compiled-out debug message)
        return;
    }
}
