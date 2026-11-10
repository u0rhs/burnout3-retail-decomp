// B3Globe2dObject.cpp (E map). Local fork unit; names from the E map, members without evidence are field_XX.

struct CB3Globe2dObject
{
    char _p[0x34];
    unsigned char field_34;
    unsigned char field_35;
    void SetGlobeAlpha(float f);
    void SetGlobeReveal(float f);
};

// 0x3B54D0
void CB3Globe2dObject::SetGlobeReveal(float f)
{
    field_35 = (unsigned char)(int)(f * 255.0f);
}

// 0x3B54F0
void CB3Globe2dObject::SetGlobeAlpha(float f)
{
    field_34 = (unsigned char)(int)(f * 255.0f);
}
