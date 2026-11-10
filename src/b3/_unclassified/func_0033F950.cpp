// Hand-written; the lifter refused it (a85: TableComponent::Release; goto-entry loops, 'int i' declared at function top fixes s0-s3 order).

// [L] DNAT: CB3TableComponent::Release() (research/proto/new_names.csv, high); modeled on func_0033FF10 (Prepare).
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

class CGt2dObjectTableData {
public:
    unsigned char pad_0[0x8];
    int field_8;
};

struct UnkStruct_0033F950 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dObject * field_C;
    CGt2dObject * field_10;
    CGt2dObject * field_14;
    CGt2dObject ** field_18;
    CGt2dObject * field_1C;
    const CGt2dObjectTableData * field_20;
    unsigned char pad_24[0xC];
    int field_30;
    CGt2dObject * field_34;
    CGt2dObject * field_38;
};

extern CGt2dScene D_01E903E0;
extern int D_004E2DB0;
extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()

// 0x0033F950
extern "C" void Release__17CB3TableComponentFv(UnkStruct_0033F950 * self)
{
    int i;
    Release__20CB3MenuComponentBaseFv(self);
    CGt2dScene * const scene = &D_01E903E0;
    scene->DestructObject(self->field_8 + 1, self->field_C);
    self->field_C = 0;
    if (self->field_10 != 0) {
        scene->DestructObject(self->field_8, self->field_10);
    }
    self->field_10 = 0;
    if ((self->field_30 & 4) != 0) {
        if (self->field_14 != 0) {
            scene->DestructObject(self->field_8, self->field_14);
        }
        self->field_14 = 0;
    }
    if ((self->field_30 & 8) != 0) {
        if (self->field_1C != 0) {
            scene->DestructObject(self->field_8, self->field_1C);
            i = 0;
            goto test1;
body1:
            if (self->field_18[i] != 0) {
                scene->DestructObject(self->field_8, self->field_18[i]);
            }
            self->field_18[i] = 0;
            i++;
test1:
            if (i < self->field_20->field_8 - 1) goto body1;
        } else {
            if ((self->field_30 & 0x10) != 0) {
                i = 0;
            } else {
                i = 1;
            }
            goto test2;
body2:
            if (self->field_18[i] != 0) {
                scene->DestructObject(self->field_8, self->field_18[i]);
            }
            self->field_18[i] = 0;
            i++;
test2:
            if (i < self->field_20->field_8) goto body2;
        }
    }
    if (D_004E2DB0 != 0) {
        if (self->field_34 != 0) {
            scene->DestructObject(self->field_8 + 1, self->field_34);
            self->field_34 = 0;
        }
        if (self->field_38 != 0) {
            scene->DestructObject(self->field_8 + 1, self->field_38);
            self->field_38 = 0;
        }
        D_004E2DB0 = 0;
    }
}
