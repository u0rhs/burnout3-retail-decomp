// CB3MenuInputButton -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3MENUINPUTBUTTON_H
#define B3_CLASSES_CB3MENUINPUTBUTTON_H

class CB3MenuInputButton;

class CB3MenuInputButton {
public:
    void Update(float p0, float p1, int p2);

    short field_0;
    short field_2;
    float field_4;
    float field_8;
};

#endif
