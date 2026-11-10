// CB3OnlineStageLogic::UpdateSyncReplay() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineStageLogic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a130: single shared return 0 (if(p){..} else {..; if(ok) return 1;} return 0), bool sent/found/ok, declaration order i,ok,pl,found,j).

struct UnkStruct_00390990_pl { unsigned char pad_0[0x10]; };
struct UnkStruct_00390990 {
    unsigned char pad_0[0x20];
    int field_20;
    int field_24[8];
    unsigned char pad_44[4];
    unsigned char field_48;
};
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_00 D_01E32AE0;
extern UnkStruct_D_int D_01E32B08;
extern UnkStruct_D_00 D_0055EEE8;
extern UnkStruct_D_00 D_0055EF48;
extern UnkStruct_D_int D_0055EEFC;
extern UnkStruct_D_int D_0055EF60;
extern UnkStruct_D_int D_0051B85C;
extern UnkStruct_D_int D_0051B860;
extern "C" void func_0026FAA0(void *, int);
extern "C" UnkStruct_00390990_pl * GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);
extern "C" void * memcpy(void *, const void *, unsigned long);
extern "C" void UnpackHeader__15CB3ReplaySystemFv(void *);
extern "C" void PackHeader__15CB3ReplaySystemFv(void *);
extern "C" void SetPosition__13CGtByteStreamFi(void *, int);
extern "C" unsigned char func_0023B6A0(void *);
extern "C" void * func_002366D0(void *, int);
extern "C" float GetTimeSinceLastPacketArrived__16CB3NetworkPlayerCFv(void *);
extern "C" int func_0022FBB0(void *);
extern "C" bool func_0023B6E0(void *, void *, void *);
// 0x00390990
extern "C" int UpdateSyncReplay__19CB3OnlineStageLogicFv(UnkStruct_00390990 *self)
{
    func_0026FAA0(&D_01E32AE0, 0);
    int i;
    bool ok;
    int j;
    void *pl;
    bool found;
    UnkStruct_00390990_pl *p = GetPlayerByID__23CGtNetworkPlayerManagerCFi(&D_01E32AE0, self->field_20);
    if (p != 0) {
        if (self->field_48 != 0) {
            memcpy(&D_0055EEE8, (void *)D_0051B85C.field_0, 0x60);
            memcpy((void *)D_0055EF60.field_0, (void *)D_0051B860.field_0, D_0055EEFC.field_0);
            UnpackHeader__15CB3ReplaySystemFv(&D_0055EEE8);
            SetPosition__13CGtByteStreamFi(&D_0055EF48, D_0055EEFC.field_0);
            return 1;
        }
        self->field_48 = func_0023B6A0(p);
    } else {
    ok = true;
    PackHeader__15CB3ReplaySystemFv(&D_0055EEE8);
    for (i = 0; i < D_01E32B08.field_0; i++) {
        pl = func_002366D0(&D_01E32AE0, i);
        if (pl == 0) {
            continue;
        }
        if (GetTimeSinceLastPacketArrived__16CB3NetworkPlayerCFv(pl) <= 60.0f) {
            found = false;
            for (j = 0; j < 8; j++) {
                int slot = self->field_24[j];
                if (slot == func_0022FBB0(pl)) {
                    found = true;
                    break;
                }
                if (slot == -1) {
                    break;
                }
            }
            if (found) {
                continue;
            }
            ok = false;
            bool sent = func_0023B6E0(pl, &D_0055EEE8, (void *)(D_0055EF60.field_0));
            if (sent) {
                for (int k = 0; k < 8; k++) {
                    int *s = &self->field_24[k];
                    if (self->field_24[k] == -1) {
                        *s = func_0022FBB0(pl);
                        break;
                    }
                }
            }
        }
    }
    if (ok) {
        return 1;
    }
    }
    return 0;
}
