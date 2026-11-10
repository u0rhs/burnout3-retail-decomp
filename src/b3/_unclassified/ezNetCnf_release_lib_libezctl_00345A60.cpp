// ezNetCtlGetStatus -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> ezNetCnf_release.lib libezctl.o.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (RPC status; memcpy real call (lead: re-queued, unit name sanitized)).

extern "C" {
extern int m_rpcRunning;
extern char D_004C6CB8[];
extern char D_004C6DF0[];
extern char D_004C6D30[];
struct UnkStruct_01EA3DC0 { int field_0; char pad_4[0xC]; char field_10[0x100]; char field_110[0x70]; };
extern UnkStruct_01EA3DC0 D_01EA3DC0;
extern char D_01EA3D80[];
extern char D_01EA3B80[];
int scePrintf(char *, ...);
int sceSifCallRpc(void *, int, int, void *, int, void *, int, int, int);
void *memcpy(void *, const void *, unsigned int);
void ezNetCtlRecreateIfstat(char *, char *, char *);
void ezNetCtlLocalizeMessage(char *, char *, char *, char *);
// 0x00345A60
int ezNetCtlGetStatus(char *a, char *b, int c_)
{
    char * c = (char *)c_;
    UnkStruct_01EA3DC0 *p = &D_01EA3DC0;
    if (m_rpcRunning == 0) {
        scePrintf(D_004C6CB8, D_004C6DF0);
        scePrintf(D_004C6D30);
        return -1;
    }
    sceSifCallRpc(D_01EA3D80, 3, 0, 0, 0, p, 0x180, 0, 0);
    memcpy(a, p->field_110, 0x38);
    ezNetCtlRecreateIfstat(p->field_10, a, D_01EA3B80);
    ezNetCtlLocalizeMessage(b, c, a, D_01EA3B80);
    return p->field_0;
}
}
