// CB3NetworkGameModeStatusMessage -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3NETWORKGAMEMODESTATUSMESSAGE_H
#define B3_CLASSES_CB3NETWORKGAMEMODESTATUSMESSAGE_H

class CB3NetworkGameModeStatusMessage;

class CB3NetworkGameModeStatusMessage {
public:
    int Retrieve(signed char* p0);

    unsigned char field_0;
    unsigned char pad_1[0xF];
    signed char field_10;
};

#endif
