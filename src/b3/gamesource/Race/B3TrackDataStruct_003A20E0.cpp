// B3TrackDataStruct.cpp (E map). Local fork unit; names from the E map, members without evidence are field_XX.
// Struct offsets are retail offsets.

struct CB3TrackDataStruct
{
    char _p[0x3e0];
    unsigned int field_3e0;
    unsigned int field_3e4;
    void Fixup(unsigned int o);
};

// 0x3A20E0 (E 0x34E940)
void CB3TrackDataStruct::Fixup(unsigned int o)
{
    field_3e0 += o;
    field_3e4 += o;
}
