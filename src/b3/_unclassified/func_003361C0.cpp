// Hand-written; the lifter refused it (switch with case order by block address (6/7 third); a1 is a real char* arg of first TagFieldSetString).

struct UnkStruct_003362B0_1 { unsigned char field_0; };
struct UnkStruct_D_004E2DAC { UnkStruct_003362B0_1 * field_0; };
class CGtLobbyPS2DirtySock {
public:
    unsigned char pad_0[0x104];
    int field_104;
};
extern UnkStruct_D_004E2DAC D_004E2DAC;
extern char D_004C5880[];
extern char D_004C5888[];
extern char D_004C5898[];
extern char D_004C58A0[];
extern char D_004C58B0[];
extern char D_004C58C0[];
extern char D_004C58D0[];
extern char D_004C58E0[];
extern char D_004C58E8[];
extern "C" void TagFieldSetString(UnkStruct_003362B0_1 *, int, void *, char*);
extern "C" void LobbyApiRequestCB(int, int, UnkStruct_003362B0_1 *, int, int);
// 0x003361C0
extern "C" void func_003361C0(CGtLobbyPS2DirtySock *self, char *p1, int sel)
{
    char *s;
    switch (sel) {
    case 0: s = D_004C5880; break;
    case 1: s = D_004C5888; break;
    case 2: s = D_004C5898; break;
    case 6: case 7: s = D_004C58A0; break;
    case 3: s = D_004C58B0; break;
    case 4: s = D_004C58C0; break;
    case 5: s = D_004C58D0; break;
    }
    D_004E2DAC.field_0->field_0 = 0;
    TagFieldSetString(D_004E2DAC.field_0, 1024, D_004C58E0, p1);
    TagFieldSetString(D_004E2DAC.field_0, 1024, D_004C58E8, s);
    LobbyApiRequestCB(self->field_104, 0x72657074, D_004E2DAC.field_0, 0, 0);
}
