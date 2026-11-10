// CAsyncLoadManager::QueueLoadRequest(const char*,bool*,void*,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AsyncDataLoader.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a90: hand-written; N24 goto entry-jump compaction loop (goto approved), memberwise element copy).

struct UnkStruct_0013CF90_nm { char c[0x40]; };
struct UnkStruct_0013CF90_e0 {
    UnkStruct_0013CF90_nm field_0;
    bool * field_40;
    void * field_44;
    unsigned int field_48;
    unsigned int field_4C;
};
class CAsyncLoadManager {
public:
    unsigned int QueueLoadRequest(const char *, bool *, void *, unsigned int);
    void Update();
    UnkStruct_0013CF90_e0 field_0[24];
    int * field_780;
    unsigned char field_784;
    unsigned char field_785;
    unsigned char pad_786[0x2];
    int field_788;
    int field_78C;
    unsigned int field_790;
};
extern "C" char * strcpy(char *, const char *);

// 0x0013CFA0
unsigned int CAsyncLoadManager::QueueLoadRequest(const char * p0, bool * p1, void * p2, unsigned int p3)
{
    int t = field_78C;
    unsigned int id = field_0[t].field_4C;
    if (id != 0) {
        do {
            field_78C = field_78C + 1;
            if (field_78C == 24) {
                field_78C = 0;
            }
            t = field_78C;
            id = field_0[t].field_4C;
            if (id == 0) {
                break;
            }
        } while (t != field_788);
    }
    if (id != 0) {
        int rd = field_788 + 1;
        if (rd == 24) {
            rd = 0;
        }
        int wr = rd;
        int n = 24;
        int h;
        goto test;
    body:
        UnkStruct_0013CF90_e0 * e;
        unsigned int * pid;
        for (;;) {
            e = &field_0[rd];
            pid = &e->field_4C;
            if (*pid != 0) {
                break;
            }
            if (rd == h) {
                break;
            }
            rd++;
            if (rd == n) {
                rd = 0;
            }
        }
        if (wr != rd) {
            UnkStruct_0013CF90_e0 * d = &field_0[wr];
            d->field_0 = e->field_0;
            d->field_40 = e->field_40;
            d->field_44 = e->field_44;
            d->field_48 = e->field_48;
            d->field_4C = *pid;
        }
        rd++;
        if (rd == n) {
            rd = 0;
        }
        wr++;
        if (wr == n) {
            wr = 0;
        }
    test:
        h = field_788;
        if (rd != h) goto body;
        if (wr == h) {
            return 0;
        }
        field_78C = wr;
    }
    strcpy(field_0[field_78C].field_0.c, p0);
    field_0[field_78C].field_40 = p1;
    field_0[field_78C].field_44 = p2;
    field_0[field_78C].field_48 = p3;
    field_0[field_78C].field_4C = field_790;
    field_790 = field_790 + 1;
    if (field_790 == 0) {
        field_790 = field_790 + 1;
    }
    *field_0[field_78C].field_40 = false;
    Update();
    return field_0[field_78C].field_4C;
}
