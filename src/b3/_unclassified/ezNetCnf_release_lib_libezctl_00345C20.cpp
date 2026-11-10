// dmaIOP -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> ezNetCnf_release.lib libezctl.o.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (while (0 <= stat): slt at,v0,zero; inlined sceSifDmaData on stack (lead: re-queued, unit name sanitized)).

extern "C" {
extern char D_004C6CB8[];
extern char D_004C6E28[];
extern char D_004C6E30[];
struct UnkStruct_sifdma { unsigned int data; unsigned int addr; unsigned int size; unsigned int mode; };
int scePrintf(char *, ...);
int sceSifSetDma(UnkStruct_sifdma *, int);
int sceSifDmaStat(int);
// 0x00345C20
int dmaIOP(unsigned int data, unsigned int addr, unsigned int size, int flag)
{
    UnkStruct_sifdma d;
    d.data = data;
    d.addr = addr;
    d.size = (size + 15) & ~15;
    d.mode = 0;
    if ((size & 15) != 0) {
        scePrintf(D_004C6CB8, D_004C6E28);
        scePrintf(D_004C6E30, size, d.size);
    }
    int id;
    do {
        id = sceSifSetDma(&d, 1);
    } while (id == 0);
    if (flag == 0) {
        while (0 <= sceSifDmaStat(id)) {}
    }
    return id;
}
}
