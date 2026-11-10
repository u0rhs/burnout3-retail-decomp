// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// CB3StaticTrackData::FixUp() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StaticTrackData.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (rewritten: offset-to-pointer fix-ups with char* fields, inline group-table helper (inner counter j declared up front) x4, inline node-table helper x2 with a self-relative pair fix-up, explicit loops for the rest).

// CB3StaticTrackData::FixUp()

struct UnkStruct_0015E8E0_leaf {
    unsigned char pad_0[0xC];
    char * field_C;
    unsigned char pad_10[0xC];
    char * field_1C;
    unsigned char pad_20[0x20];
};

struct UnkStruct_0015E8E0_list {
    short field_0;
    unsigned char pad_2[0x2];
    UnkStruct_0015E8E0_leaf * field_4;
};

struct UnkStruct_0015E8E0_sub {
    unsigned char pad_0[0x40];
    UnkStruct_0015E8E0_list field_40;
    char * field_48;
    unsigned char pad_4C[0x4];
};

struct UnkStruct_0015E8E0_group {
    short field_0;
    unsigned char pad_2[0x2];
    UnkStruct_0015E8E0_sub * field_4;
};

struct UnkStruct_0015E8E0_pair {
    char * field_0;
    char * field_4;
    // [G] inlined self-relative fix-up of the two offsets (no name in any table)
    inline void func_0015E8E0_inl1()
    {
        if (field_0 != 0) field_0 = field_0 + (int)this;
        if (field_4 != 0) field_4 = field_4 + (int)this;
    }
};

struct UnkStruct_0015E8E0_node {
    unsigned char pad_0[0x20];
    UnkStruct_0015E8E0_pair field_20;
    UnkStruct_0015E8E0_pair field_28;
    UnkStruct_0015E8E0_pair field_30;
    unsigned char pad_38[0x6];
    short field_3E;
    unsigned char pad_40[0x10];
};

class CB3TrackMaterial {
public:
    void FixUp();

    unsigned char pad_0[0x28];
};

extern "C" void FixUp__10CGtTextureFv(void *);

class CB3StaticTrackData {
public:
    void FixUp();

    unsigned char pad_0[0x8];
    CB3TrackMaterial * field_8;
    short field_C;
    unsigned char pad_E[0x2];
    char * field_10;
    unsigned char pad_14[0x2];
    short field_16;
    char ** field_18;
    short field_1C;
    short field_1E;
    short field_20;
    short field_22;
    UnkStruct_0015E8E0_group * field_24;
    UnkStruct_0015E8E0_group * field_28;
    UnkStruct_0015E8E0_group * field_2C;
    UnkStruct_0015E8E0_group * field_30;
    short field_34;
    short field_36;
    UnkStruct_0015E8E0_node * field_38;
    UnkStruct_0015E8E0_node * field_3C;
    unsigned char pad_40[0x4];
    char * field_44;
    char * field_48;
    char ** field_4C;
    char *** field_50;
    short field_54;
    unsigned char pad_56[0x2];
    char * field_58;
    char * field_5C;
};

// [G] inlined fix-up of one group table (no name in any table)
static inline void func_0015E8E0_inl2(UnkStruct_0015E8E0_group *& arr, short & count, void * base)
{
    int j;
    if (arr != 0) {
        arr = (UnkStruct_0015E8E0_group *)((int)arr + (int)base);
        for (int i = 0; i < count; i++) {
            UnkStruct_0015E8E0_group * g = &arr[i];
            g->field_4 = (UnkStruct_0015E8E0_sub *)((int)g->field_4 + (int)g);
            for (j = 0; j < g->field_0; j++) {
                UnkStruct_0015E8E0_list * l = &g->field_4[j].field_40;
                if (l->field_0 > 0) {
                    l->field_4 = (UnkStruct_0015E8E0_leaf *)((int)l->field_4 + (int)l);
                    for (int k = 0; k < l->field_0; k++) {
                        UnkStruct_0015E8E0_leaf * e = &l->field_4[k];
                        if (e->field_C != 0) e->field_C = e->field_C + (int)e;
                        if (e->field_1C != 0) e->field_1C = e->field_1C + (int)e;
                    }
                }
                if (g->field_4[j].field_48 != 0) g->field_4[j].field_48 = (char *)g + (int)g->field_4[j].field_48;
            }
        }
    }
}

// [G] inlined fix-up of one node table (no name in any table)
static inline void func_0015E8E0_inl3(UnkStruct_0015E8E0_node *& arr, short & count, void * base)
{
    if (arr != 0) {
        arr = (UnkStruct_0015E8E0_node *)((int)arr + (int)base);
        for (int i = 0; i < count; i++) {
            arr[i].field_20.func_0015E8E0_inl1();
            if (arr[i].field_3E & 1) arr[i].field_28.func_0015E8E0_inl1();
            if (arr[i].field_3E & 2) arr[i].field_30.func_0015E8E0_inl1();
        }
    }
}

// 0x0015E8E0
void CB3StaticTrackData::FixUp()
{
    if (field_10 != 0) field_10 = field_10 + (int)this;
    if (field_8 != 0) {
        field_8 = (CB3TrackMaterial *)((int)field_8 + (int)this);
        for (int i = 0; i < field_C; i++) field_8[i].FixUp();
    }
    if (field_18 != 0) {
        field_18 = (char **)((int)field_18 + (int)this);
        for (int i = 0; i < field_16; i++) {
            field_18[i] = (char *)this + (int)field_18[i];
            FixUp__10CGtTextureFv(field_18[i]);
        }
    }
    func_0015E8E0_inl2(field_24, field_1C, this);
    func_0015E8E0_inl2(field_2C, field_20, this);
    func_0015E8E0_inl2(field_30, field_22, this);
    func_0015E8E0_inl2(field_28, field_1E, this);
    func_0015E8E0_inl3(field_38, field_34, this);
    func_0015E8E0_inl3(field_3C, field_36, this);
    if (field_4C != 0) {
        field_4C = (char **)((int)field_4C + (int)this);
        for (int i = 0; i < field_54; i++) {
            if (field_4C[i] != 0) field_4C[i] = (char *)this + (int)field_4C[i];
        }
    }
    if (field_50 != 0) {
        field_50 = (char ***)((int)field_50 + (int)this);
        for (int i = 0; i < field_54; i++) {
            if (field_50[i] != 0) {
                field_50[i] = (char **)((int)this + (int)field_50[i]);
                for (int k = 0; k < field_36; k++) {
                    if (field_50[i][k] != 0) field_50[i][k] = (char *)this + (int)field_50[i][k];
                }
            }
        }
    }
    if (field_44 != 0) field_44 = field_44 + (int)this;
    if (field_48 != 0) field_48 = field_48 + (int)this;
    if (field_58 != 0) field_58 = field_58 + (int)this;
    if (field_5C != 0) field_5C = field_5C + (int)this;
}
