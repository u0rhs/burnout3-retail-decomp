// Hand-written; the lifter refused it (a71: case-insensitive bounded substring search (tolower inlined, signed char); match arm first).

extern "C" char * func_00234FF0(char * p0, char * p1, char * p2);

// 0x00234FF0
extern "C" char * func_00234FF0(char * p0, char * p1, char * p2)
{
    if (*p2 == 0) {
        return p0;
    }
    if (p0 == p1) {
        return 0;
    }
    char * s = p0;
    char * n = p2;
    for (;;) {
        char c = *s;
        if (c >= 'A' && c <= 'Z') {
            c = c + 32;
        }
        char d = *n;
        if (d >= 'A' && d <= 'Z') {
            d = d + 32;
        }
        if (c == d) {
            n++;
            s++;
            if (*n == 0) {
                return p0;
            }
        } else {
            p0++;
            n = p2;
            s = p0;
        }
        if (s == p1) {
            return 0;
        }
    }
}
