// CGtNetworkHeadset::SetStatusToSend(EHeadsetTalkControlStatus,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNetworkHeadset.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a123: packed 5-slot queue; return in first-slot loop, k declared before c, i before found).

enum EHeadsetTalkControlStatus { UnkEnum_HTCS_0 };

class CGtNetworkHeadset {
public:
    void SetStatusToSend(EHeadsetTalkControlStatus, int);

    unsigned char pad_0[0x81DC];
    int field_81DC[5];
    int field_81F0[5];
};

// 0x002BF7F0
void CGtNetworkHeadset::SetStatusToSend(EHeadsetTalkControlStatus p0, int p1)
{
    int i;
    bool found = false;
    i = 0;
    while (i < 5 && !found) {
        if (field_81DC[i] != 0) {
            found = true;
        }
        i++;
    }
    if (!found) {
        field_81DC[0] = p0;
        field_81F0[0] = p1;
    } else if (i - 1 != 0) {
        int k;
        int c = 0;
        for (k = 0; k < 5 - (i - 1); k++) {
            field_81DC[k] = field_81DC[i - 1 + k];
            field_81F0[k] = field_81F0[i - 1 + k];
            if (field_81DC[k] != 0) {
                c = k + 1;
            }
        }
        field_81DC[c] = p0;
        field_81F0[c] = p1;
        for (int m = c + 1; m < 5; m++) {
            field_81DC[m] = 0;
            field_81F0[m] = -1;
        }
    } else {
        for (int j = 0; j < 5; j++) {
            if (field_81DC[j] == 0) {
                field_81DC[j] = p0;
                field_81F0[j] = p1;
                return;
            }
        }
    }
}
