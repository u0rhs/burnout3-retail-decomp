// GtID.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 5 function(s) named in research/retail_names.csv -> GtID.cpp.
// Area: src/b3/GameShared/GameClasses/Core, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Core/GtID.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

extern unsigned long gaGtIDCharacterMasks[13];

// Hand-written; the lifter refused it (a88: GtIDConvertToString base-40, else-if chain; local copies o=out, v=id declared before i).
// 0x0021AB40
extern "C" void func_0021AB40(unsigned long id, char * out)
{
    char * o = out;
    unsigned long v = id;
    int i;
    for (i = 11; i >= 0; i--) {
        char d = (char)(v % 40);
        char c;
        if (d == 39) {
            c = '_';
        } else if (d >= 13) {
            c = d + 'A' - 13;
        } else if (d >= 3) {
            c = d + '0' - 3;
        } else {
            if (d == 2) c = '/';
            else if (d == 1) c = '-';
            else if (d == 0) c = ' ';
            else c = 0;
        }
        o[i] = c;
        v = v / 40;
    }
    out[12] = 0;
    char * p = out + 11;
    while (*p == ' ' && p >= out) {
        *p = 0;
        p--;
    }
}

// GtIDScroll(unsigned long,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtID.cpp.
// 0x0021AC70
extern "C" unsigned long func_0021AC70(unsigned long id, int n)
{
    unsigned long v;
    if (n == 0) {
        return id;
    }
    else if (n < -11 || n > 11) {
        return 0;
    }
    else if (n > 0) {
        v = id / gaGtIDCharacterMasks[n];
    }
    else {
        return (id % gaGtIDCharacterMasks[11 - (-n - 1)]) * gaGtIDCharacterMasks[-n];
    }
    return v;
}

// Hand-written; the lifter refused it (a76: local copy v of id (swaps s0/s1)).
// 0x0021AD60
extern "C" unsigned long func_0021AD60(unsigned long id, int a, int b)
{
    unsigned long v = id;
    if (a > 0) {
        v = v % gaGtIDCharacterMasks[11 - (a - 1)];
    }
    if (b < 11) {
        v = v - v % gaGtIDCharacterMasks[11 - b];
    }
    return v;
}

// Hand-written; the lifter refused it (a67: GtIDUnCompress, if-chain with >= comparisons (slt v0 vs at)).
// 0x0021ADF0
extern "C" void func_0021ADF0(unsigned long id, char *out)
{
    for (int i = 11; i >= 0; i--) {
        char r = id % 40;
        char c;
        if (r == 39) {
            c = '_';
        } else if (r >= 13) {
            c = r + 0x34;
        } else if (r >= 3) {
            c = r + 0x2D;
        } else if (r == 2) {
            c = '/';
        } else if (r == 1) {
            c = '-';
        } else if (r == 0) {
            c = ' ';
        } else {
            c = 0;
        }
        out[i] = c;
        id /= 40;
    }
    out[12] = 0;
}

// GtIDCompress(const char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtID.cpp.
// 0x0021AEF0
extern "C" unsigned long GtIDCompress__FPCc(const char *s)
{
    unsigned long v = 0;
    int i = 0;
    for (; i < 12; i++) {
        char c = s[i];
        if (c == 0) {
            break;
        }
        v *= 40;
        if (c == '_') {
            v += 39;
        } else if (c >= 'a') {
            v += c - 0x54;
        } else if (c >= 'A') {
            v += c - 0x34;
        } else if (c >= '0') {
            v += c - 0x2D;
        } else if (c == '/') {
            v += 2;
        } else if (c == '-') {
            v += 1;
        }
    }
    while (i < 12) {
        v *= 40;
        i++;
    }
    return v;
}
