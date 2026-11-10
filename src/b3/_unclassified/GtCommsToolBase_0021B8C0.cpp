// GtComms::CGtCommsToolBase::Construct(const char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtCommsToolBase.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (gaps1b: hand-written from the asm, exact).

// gaps1b (2026-11-02): hand-drafted from the retail asm (0x21B8C0). Publishes the tool object and sets up its game database at +0x10.
// Name: the asm symbol, which came from a config/symbol_addrs.txt row marked "names are ours" (the earlier research repo, upstream)
// -- not evidence. [L] research/retail_names.csv (high): GtComms::CGtCommsToolBase::Construct(const char*).

// [C] a 32-byte registry entry (vdbRegister*: stores, Construct__Q27GtComms16CGtCommsDatabaseFPQ27GtComms21CGtCommsDatabaseEntryi's memset of cap * 32)
struct UnkStruct_vdb_entry {
    void * field_0;               // the registered variable
    unsigned int field_4;         // float: max (f13), int: t3 [G meaning]
    unsigned int field_8;         // float: min (f12), int: t2
    const char * field_C;         // the three path parts, joined with '/' for the hash
    const char * field_10;
    const char * field_14;        // the variable's name (the vtable slot 0x14 argument)
    int field_18;                 // CalculateHash__7CGtHashFPCc of the joined path
    unsigned char field_1C;       // float / int: the last argument; SetDefaultElementValue__Q27GtComms20CGtCommsDatabaseGameFPQ27GtComms21CGtCommsDatabaseEntry: element count (>= 2 -> memcpy)
    unsigned char field_1D;       // flags; bit 0: a range was given
    unsigned char field_1E;       // type: 0 free, 1 int, 2 float, 3 bool, 5 vector
    unsigned char field_1F;
};
// [C] the registry: vtable at +0 (slots called with a0 = it)
struct UnkStruct_vdb_db {
    virtual void vfunc_8(UnkStruct_vdb_entry *);
    virtual void vfunc_C(UnkStruct_vdb_entry *);
    virtual void vfunc_10(UnkStruct_vdb_entry *);
    virtual unsigned char vfunc_14(const char *);
    int field_4;                  // the next free slot to try
    int field_8;                  // live entries
    UnkStruct_vdb_entry * field_C;
    int field_10;                 // capacity
};
// [C] the game database: the registry with 0x6C8 entries inline at +0xC20 (Construct__Q27GtComms20CGtCommsDatabaseGameFv) and a sorted (value, hash) table
// built from the blob at +0xE530 (InitialiseDefaultValues__Q27GtComms20CGtCommsDatabaseGameFv)
struct UnkStruct_vdb_rec { unsigned int field_0; int field_4; };
struct UnkStruct_vdb_blob { int pad_0; int field_4; int pad_8; int field_C; int field_10; };
struct UnkStruct_vdb_game : UnkStruct_vdb_db {
    unsigned char pad_14[0xC14 - 0x14];
    int field_C14;
    int field_C18;
    unsigned char field_C1C;
    unsigned char pad_C1D[3];
    UnkStruct_vdb_entry field_C20[0x6C8];
    int field_E520;               // records in field_E524 (keyed by field_4)
    UnkStruct_vdb_rec * field_E524;
    int field_E528;               // records in field_E52C
    UnkStruct_vdb_rec * field_E52C;
    unsigned char field_E530[0x10];   // the loaded blob starts here
};
extern UnkStruct_vdb_db * mpToolBase__Q27GtComms16CGtCommsToolBase;   // [C] gp-relative
extern int D_004E291C;
extern unsigned int manHashTable__7CGtHash[];
extern char D_004B9C88[];         // [C] "/"
extern char D_004B9C90[];         // [C] "GtCommVa%04d"
extern "C" unsigned int strlen(const char *);
extern "C" char * strcpy(char *, const char *);
extern "C" char * strcat(char *, const char *);
extern "C" int sprintf(char *, const char *, ...);
extern "C" void * memset(void *, int, unsigned int);
extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" int GtIDCompress__FPCc(char *);
extern "C" int CalculateHash__7CGtHashFPCc(const char *);
extern "C" void RemoveEntryCore__Q27GtComms16CGtCommsDatabaseFPQ27GtComms21CGtCommsDatabaseEntry(UnkStruct_vdb_db *, UnkStruct_vdb_entry *);
extern "C" void Construct__Q27GtComms20CGtCommsDatabaseGameFv(UnkStruct_vdb_game *);
extern "C" void Construct__Q27GtComms16CGtCommsDatabaseFPQ27GtComms21CGtCommsDatabaseEntryi(UnkStruct_vdb_db *, UnkStruct_vdb_entry *, int);

// [G] the shared front half of the vdbRegister* entry points (inlined in each): hash the joined path, take the next
// free slot from field_4 on (wrapping), name a scratch "GtCommVa%04d" with the slot (GtIDCompress__FPCc's result unused [C])
static inline UnkStruct_vdb_entry * func_0021B9B0_inl1(UnkStruct_vdb_db * db, const char * a, const char * b,
                                                       const char * name, int * hash)
{
    char path[0x200];
    char tmp[0x10];
    strcpy(path, a);
    strcat(path, b);
    if (path[strlen(path) - 1] != '/') {
        strcat(path, D_004B9C88);
    }
    strcat(path, name);
    *hash = CalculateHash__7CGtHashFPCc(path);
    int i = db->field_4;
    while (db->field_C[i].field_1E != 0) {
        i++;
        if (!(i < db->field_10)) {
            i = 0;
        }
    }
    db->field_4 = i;
    sprintf(tmp, D_004B9C90, i);
    GtIDCompress__FPCc(tmp);
    return &db->field_C[i];
}

// [G] the shared tail: add, then keep it only if the name check (slot 0x14) returns 1
static inline void func_0021B9B0_inl2(UnkStruct_vdb_db * db, UnkStruct_vdb_entry * e, const char * name)
{
    db->vfunc_10(e);
    if (db->vfunc_14(name) != 1) {
        e->field_1E = 0;
        db->field_8--;
        return;
    }
    db->vfunc_8(e);
}

// [G] binary search of the sorted records by key (field_4): hi = n, lo = -1, mid rounds toward zero
static inline UnkStruct_vdb_rec * func_0024FFC0_inl1(UnkStruct_vdb_rec * t, int n, int key)
{
    int hi = n, lo = -1;
    while (hi - lo >= 2) {
        int mid = (hi + lo) / 2;
        UnkStruct_vdb_rec * r = &t[mid];
        if (r->field_4 == key) {
            return r;
        }
        if (key < r->field_4) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return 0;
}

// 0x0021B8C0
extern "C" void Construct__Q27GtComms16CGtCommsToolBaseFPCc(UnkStruct_vdb_db * p, int a1)
{
    mpToolBase__Q27GtComms16CGtCommsToolBase = p;
    Construct__Q27GtComms20CGtCommsDatabaseGameFv((UnkStruct_vdb_game *)((unsigned char *)p + 0x10));
    D_004E291C = a1;
}
