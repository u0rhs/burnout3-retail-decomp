// CB3SoundTrafficManager::IsBoostPassPlaying() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTrafficManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3SoundTrafficManager;
class CGtSoundVirtualVoice;
struct UnkStruct_00276A30_e0;

class CGtSoundVirtualVoice {
public:
    int IsPlaying();
};

struct UnkStruct_00276A30_e0 {
    unsigned char pad_0[0xF0];
    int field_F0;
    unsigned char pad_F4[0xC];
    CGtSoundVirtualVoice * field_100;
    unsigned char pad_104[0x1];
    unsigned char field_105;
    unsigned char pad_106[0x2];
    float field_108;
    unsigned char pad_10C[0x24];
};

class CB3SoundTrafficManager {
public:
    int IsBoostPassPlaying();

    UnkStruct_00276A30_e0 field_0[1];  // [G] element count unknown
};

// 0x00276A30
int CB3SoundTrafficManager::IsBoostPassPlaying()
{
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        if (field_0[i].field_F0 == 0) {
            goto loop0_next;
        }
        CGtSoundVirtualVoice * t0 = field_0[i].field_100;
        if (t0 == 0) {
            goto loop0_next;
        }
        int r0 = t0->IsPlaying();
        if (r0 == 0) {
            goto loop0_next;
        }
        if (field_0[i].field_105 >= 8) {
            goto loop0_next;
        }
        if (field_0[i].field_108 <= 0.25f) {
            goto loop0_next;
        }
        return 1;
    }
loop0_next:
    i++;
loop0_test:
    if (i < 16) goto loop0_body;
    return 0;
}
