// CGtSoundListenerManager::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundListenerManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundListener;
class CGtSoundListenerManager;

class CGtSoundListener {
public:
    void Release();
};

class CGtSoundListenerManager {
public:
    void Release();

    CGtSoundListener * field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x4];
    int field_8;
};

// 0x00384C70
void CGtSoundListenerManager::Release()
{
    for (int i = 0; ((unsigned int)i < (unsigned int)field_8); i++) {
        CGtSoundListener * t0 = field_0[i];
        if (t0 != 0) {
            t0->Release();
        }
    }
    field_8 = 0;
}
