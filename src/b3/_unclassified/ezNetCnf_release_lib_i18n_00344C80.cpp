// ezNetCtlLocalizeMessage -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> ezNetCnf_release.lib i18n.o.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (cases 3/4 as ternaries field_0 == 0x12E ? field_4 : field_0 (if-form drops/keeps retail's b stubs)).

extern "C" {
struct UnkStruct_ezMsg { int field_0; int field_4; char *field_8; void (*field_C)(char *, int, char *, void *, void *); };
struct UnkStruct_ezStat { unsigned char pad_0[0x28]; int field_28; int field_2C; int field_30; };
struct UnkStruct_ezInfo { int field_0; int field_4; };
extern void *m_phaseMsgs;
extern void *m_errorMsgs;
extern void *m_stateMsgs;
UnkStruct_ezMsg *getMsgEntry(int, void *);
void *memset(void *, int, unsigned int);
char *strncpy(char *, const char *, unsigned int);
// 0x00344C80
void ezNetCtlLocalizeMessage(char *buf, int size, UnkStruct_ezStat *st, UnkStruct_ezInfo *info)
{
    UnkStruct_ezMsg *e = 0;
    int code = 0;
    if (buf == 0) return;
    if (size == 0) return;
    switch (st->field_28) {
    case 2:
        code = info->field_0;
        break;
    case 3:
        code = info->field_0 == 0x12E ? info->field_4 : info->field_0;
        break;
    case 4:
        code = info->field_0 == 0x12E ? info->field_4 : info->field_0;
        break;
    }
    if (code != 0 && st->field_30 > 0 && st->field_30 < 4) e = getMsgEntry(code, m_phaseMsgs);
    if (st->field_2C != 0) e = getMsgEntry(st->field_2C, m_errorMsgs);
    if (e == 0) e = getMsgEntry(st->field_30, m_stateMsgs);
    memset(buf, 0, size);
    if (e == 0) return;
    if (e->field_C != 0) {
        e->field_C(buf, size, e->field_8, st, info);
        return;
    }
    strncpy(buf, e->field_8, size);
}
}
