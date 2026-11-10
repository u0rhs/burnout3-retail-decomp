// CGtSoundListenerManager::Destruct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundListenerManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundListener;
class CGtSoundListenerManager;

class CGtSoundListener {
public:
    void Destruct();
};

class CGtSoundListenerManager {
public:
    void Destruct();

    CGtSoundListener * field_0[1];  // [G] element count unknown
    unsigned char pad_4[0xC];
    int field_10;
};

extern "C" void RwaObjDestroy(int, int, int);

// 0x00384BF0
void CGtSoundListenerManager::Destruct()
{
    int i = 0;
    do {
        CGtSoundListener * t0 = field_0[i];
        if (t0 != 0) {
            t0->Destruct();
            field_0[i] = 0;
        }
        i++;
    } while ((unsigned int)i < (unsigned int)2);
    RwaObjDestroy(field_10, 0, 0);
    field_10 = 0;
}
