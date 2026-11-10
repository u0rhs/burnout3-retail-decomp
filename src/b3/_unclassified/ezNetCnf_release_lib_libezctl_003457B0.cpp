// ezNetCtlSetProperties -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> ezNetCnf_release.lib libezctl.o.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ezNetCtlSetProperties; break on r<=0, return r on ==1).

extern "C" {
extern int m_rpcRunning;
extern char D_004C6CB8[];
extern char D_004C6D00[];
extern char D_004C6D18[];
extern char D_004C6D30[];
extern char D_004C6D50[];
extern char D_004C6D80[];
struct UnkStruct_01EA3DC0 { int field_0; int pad[3]; };
extern UnkStruct_01EA3DC0 D_01EA3DC0;
extern char D_01EA3D80[];
int scePrintf(char *, ...);
int sceSifCallRpc(void *, int, int, void *, int, void *, int, int, int);
void SyncDCache(void *, void *);
int dmaIOP(unsigned int data, unsigned int addr, unsigned int size, int flag);
int ezNetCtlWaitEventTO(int);
// 0x003457B0
int ezNetCtlSetProperties(char *a)
{
    UnkStruct_01EA3DC0 *p = &D_01EA3DC0;
    if (m_rpcRunning == 0) {
        scePrintf(D_004C6CB8, D_004C6D00);
        scePrintf(D_004C6D30);
        return -1;
    }
    if (((unsigned int)a & 0x3F) != 0) {
        scePrintf(D_004C6CB8, D_004C6D00);
        scePrintf(D_004C6D50, a, 0x40);
        return -0x16;
    }
    SyncDCache(a, a + 0x133F);
    sceSifCallRpc(D_01EA3D80, 0, 0, 0, 0, p, 4, 0, 0);
    if (p->field_0 == 0) {
        scePrintf(D_004C6CB8, D_004C6D00);
        scePrintf(D_004C6D80);
        return -2;
    }
    dmaIOP((unsigned int)a, p->field_0, 0x1340, 0);
    sceSifCallRpc(D_01EA3D80, 1, 0, p, 4, p, 4, 0, 0);
    int code = p->field_0;
    scePrintf(D_004C6CB8, D_004C6D00);
    scePrintf(D_004C6D18, code);
    int r;
    for (;;) {
        r = ezNetCtlWaitEventTO(2000);
        if (r <= 0) break;
        if (r == 1) return r;
    }
    return r;
}
}
