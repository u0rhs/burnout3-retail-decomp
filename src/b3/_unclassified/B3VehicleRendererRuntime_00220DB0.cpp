// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// CB3VehicleLODDataBase::FixUp() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehicleRendererRuntime.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (rewritten: one table struct type for all four arrays, inline relocate helper + inline element fix-up loop, null-tested element field_4 as pointer).

// CB3VehicleLODDataBase::FixUp()

struct UnkStruct_00220DB0_e0 {
    int field_0;
    void * field_4;
    unsigned char pad_8[0x8];
};

struct UnkStruct_00220DB0_1 {
    signed char field_0;
    unsigned char pad_1[0x3];
    UnkStruct_00220DB0_e0 * field_4;
    // [G] inlined per-table fix-up (no name in any table)
    inline void func_00220DB0_inl1()
    {
        field_4 = (UnkStruct_00220DB0_e0 *)((int)field_4 + (int)this);
        for (int i = 0; i < field_0; i++) {
            UnkStruct_00220DB0_e0 * e = &field_4[i];
            e->field_0 = e->field_0 + (int)e;
            if (e->field_4 != 0) {
                e->field_4 = (void *)((int)e->field_4 + (int)e);
            }
        }
    }
};

// [G] inlined relocation of one table pointer (no name in any table)
static inline void func_00220DB0_inl2(UnkStruct_00220DB0_1 *& p, void * base)
{
    if (p != 0) {
        p = (UnkStruct_00220DB0_1 *)((int)p + (int)base);
        p->func_00220DB0_inl1();
    }
}

class CB3VehicleLODDataBase {
public:
    void FixUp();

    UnkStruct_00220DB0_1 * field_0;
    UnkStruct_00220DB0_1 * field_4[6];
    UnkStruct_00220DB0_1 * field_1C[3];
    UnkStruct_00220DB0_1 * field_28[8];
};

// 0x00220DB0
void CB3VehicleLODDataBase::FixUp()
{
    int i;
    func_00220DB0_inl2(field_0, this);
    for (i = 0; i < 6; i++) func_00220DB0_inl2(field_4[i], this);
    for (i = 0; i < 3; i++) func_00220DB0_inl2(field_1C[i], this);
    for (i = 0; i < 8; i++) func_00220DB0_inl2(field_28[i], this);
}
