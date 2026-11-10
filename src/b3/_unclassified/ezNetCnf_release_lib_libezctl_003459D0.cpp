// ezNetCtlDownInterface -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> ezNetCnf_release.lib libezctl.o.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (sibling of UpInterface (lead: re-queued, unit name sanitized)).

extern "C" {
extern int m_rpcRunning;
extern char D_004C6CB8[];
extern char D_004C6DD0[];
extern char D_004C6D30[];
struct UnkStruct_01EA3DC0 { int field_0; int pad[3]; };
extern UnkStruct_01EA3DC0 D_01EA3DC0;
extern char D_01EA3D80[];
int scePrintf(char *, ...);
int sceSifCallRpc(void *, int, int, void *, int, void *, int, int, int);
// 0x003459D0
int ezNetCtlDownInterface()
{
    UnkStruct_01EA3DC0 *p = &D_01EA3DC0;
    if (m_rpcRunning == 0) {
        scePrintf(D_004C6CB8, D_004C6DD0);
        scePrintf(D_004C6D30);
        return -1;
    }
    sceSifCallRpc(D_01EA3D80, 6, 0, 0, 0, p, 4, 0, 0);
    return p->field_0;
}
}
