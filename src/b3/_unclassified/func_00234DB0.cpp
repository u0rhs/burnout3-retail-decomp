// Hand-written; the lifter refused it (a84: func_00234DB0 (DNAT Prepare, inferred/medium; body = dotted-number scan); macro isdigit (no bool temp), explicit 'p = q; continue;' per failure gives retail's separate stubs).

// func_00234DB0 -- CGtNATDataManager::Prepare(CGtNetworkAdapter*,CGtNetworkPlayerManager*,float) [L] DNAT (inferred, medium); the body is a dotted-number scan (inlined digit tests)
extern "C" unsigned int strlen(const char *);
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" char * func_00234FF0(void *, const char *, const char *);

#define func_00234DB0_inl1(c) ((c) >= '0' && (c) <= '9')

// [L] DNAT: CGtNATDataManager::Prepare(CGtNetworkAdapter*,CGtNetworkPlayerManager*,float) (research/proto/new_names.csv, medium)
// 0x00234DB0
extern "C" int func_00234DB0(void * self, const char * end, const char * prefix, char * out)
{
    char * p = func_00234FF0(self, end, prefix);
    char * q;
    p = p + strlen(prefix);
    q = p;
    while (q < end) {
        while (!func_00234DB0_inl1(*p) && p < end) {
            p++;
        }
        q = p;
        while (func_00234DB0_inl1(*q) && q < end) {
            q++;
        }
        if (*q != '.') {
            p = q;
            continue;
        }
        q++;
        if (!func_00234DB0_inl1(*q)) {
            p = q;
            continue;
        }
        while (func_00234DB0_inl1(*q) && q < end) {
            q++;
        }
        if (*q != '.') {
            p = q;
            continue;
        }
        q++;
        if (!func_00234DB0_inl1(*q)) {
            p = q;
            continue;
        }
        while (func_00234DB0_inl1(*q) && q < end) {
            q++;
        }
        if (*q != '.') {
            p = q;
            continue;
        }
        q++;
        if (!func_00234DB0_inl1(*q)) {
            p = q;
            continue;
        }
        while (func_00234DB0_inl1(*q) && q < end) {
            q++;
        }
        break;
    }
    if (q - p != 0) {
        strncpy(out, p, q - p);
        return 1;
    }
    return 0;
}
