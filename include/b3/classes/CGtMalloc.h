// CGtMalloc -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTMALLOC_H
#define B3_CLASSES_CGTMALLOC_H

class CGtMalloc;

class CGtMalloc {
public:
    static int mnPoolOffset;
    static int mnPoolSize;
    static void * mpBuffer;
    void Create(void*, unsigned int);

    unsigned char field_0;
};

#endif
