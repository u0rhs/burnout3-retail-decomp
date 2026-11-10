// Hand-written; the lifter refused it (strstr skip).

// Hand-written (a108). func_00127BF8 is strstr [L] (E map, config/symbol_addrs_b3names.txt).
extern char D_004D2180[];
extern char D_004D2188[];
extern "C" char *func_00127BF8(char *, char *);
// 0x0043FF50
extern "C" char *func_0043FF50(char *s)
{
    char *p = func_00127BF8(s, D_004D2180) + 2;
    if (*p == 10) {
        p++;
    }
    char *q = func_00127BF8(p, D_004D2188);
    if (q) {
        *q = 0;
    }
    return p;
}
