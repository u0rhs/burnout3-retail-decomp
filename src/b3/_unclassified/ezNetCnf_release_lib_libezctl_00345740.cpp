// ezNetCtlExit -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> ezNetCnf_release.lib libezctl.o.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (0 > StopModule idiom gives slt at,v0,zero; nested ifs (lead: re-queued, unit name sanitized)).

extern "C" {
extern int m_modId;
extern int m_rpcRunning;
int sceSifStopModule(int, int, char *, int *);
int sceSifUnloadModule(int);
// 0x00345740
int ezNetCtlExit(int flag)
{
    int ret = 0;
    if ((flag & 2) == 0 && m_rpcRunning != 0) {
        if (0 <= sceSifStopModule(m_modId, 0, 0, &ret)) {
            ret = sceSifUnloadModule(m_modId);
            if (0 <= ret) {
                m_rpcRunning = 0;
                ret = 0;
            }
        }
    }
    return ret;
}
}
