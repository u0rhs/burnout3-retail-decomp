// CGtSoundListenerManager::SetListener(int,CGtSoundListener*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundListenerManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundListener;

class CGtSoundListenerManager;

class CGtSoundListenerManager {
public:
    void SetListener(int p0, CGtSoundListener* p1);

    CGtSoundListener * field_0[1];  // [G] element count unknown
};

extern "C" int GetRWAListener__16CGtSoundListenerFv(void *);  // CGtSoundListener::GetRWAListener()
extern "C" void RwaListenerManagerRegisterVirtualListener(int);
extern "C" void RwaListenerManagerSetFixedModeListener(int);

// 0x00384B80
void CGtSoundListenerManager::SetListener(int p0, CGtSoundListener* p1)
{
    field_0[p0] = (CGtSoundListener *)p1;
    int r0 = GetRWAListener__16CGtSoundListenerFv(p1);
    RwaListenerManagerRegisterVirtualListener(r0);
    if (p0 == 0) {
        int r2 = GetRWAListener__16CGtSoundListenerFv(p1);
        RwaListenerManagerSetFixedModeListener(r2);
    }
}
