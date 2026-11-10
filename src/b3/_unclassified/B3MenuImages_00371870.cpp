// CB3MenuImages::CacheFrontendTextures() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MenuImages.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (dperm (decomp-permuter, background run): UnkStruct_00371870_3 *t1 = D_0051A868.field_0;; UnkStruct_00371870_3 *t1 = D_0051A868.field_0;).

class CB3MenuImages;
struct UnkStruct_00371870_3;
struct UnkStruct_00371870_e1;
struct UnkStruct_D_0051A868;

struct UnkStruct_D_0051A868 {
    UnkStruct_00371870_3 * field_0;
    unsigned char pad_4[0xC];  
};

struct UnkStruct_00371870_3 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_00371870_e1 * field_C;
};

struct UnkStruct_00371870_e1 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

class CB3MenuImages {
public:
    void CacheFrontendTextures();

    unsigned char pad_0[0x400];
    int field_400[1];  
};

extern void *kapcFrontendImageNames[];  
extern UnkStruct_D_0051A868 D_0051A868;

extern "C" int strcasecmp(const char *, const void *);
struct UnkStruct_00371870_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};





// 0x00371870
void CB3MenuImages::CacheFrontendTextures()
{
  for (int i = 0; i < 144; i++)
  {
    void *t0 = kapcFrontendImageNames[i];
    int t2;
    UnkStruct_00371870_3 *t1 = D_0051A868.field_0;
    int i1;
    for (i1 = 0; i1 < t1->field_8; i1++)
    {
      t2 = t1->field_C[i1].field_8;
      if (strcasecmp(((UnkStruct_00371870_blk *) (t2 + 0x90))->field_18, t0) == 0)
      {
        goto found;
      }
    }

    t2 = 0;
    found:
    field_400[i] = t2;

  }

}
