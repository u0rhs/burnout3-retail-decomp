// CGtSoundBankManager::UnloadBank(CGtSoundBank*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundBankManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (N182 [G] scoped opt_repositioncode off + goto-form found block (chk after done); was 7 off).


struct GtLListTag; struct GtLLLinkTag;
extern "C" void RemoveLink__11CGtFreeListFP15CGtFreeListLink(void *, void *);
class CGtSoundBank { public: int GetReferenceCount(); void SetReferenceCount(int); void Unload(); unsigned char pad_0[0x39C]; int field_39C; };
struct UnkStruct_Ent { int field_0; int field_4; unsigned char field_8; unsigned char pad_9[3]; };
class CGtSoundBankManager {
public:
    void UnloadBank(CGtSoundBank *p0);
    unsigned char pad_0[0xC];
    UnkStruct_Ent *field_C;
    unsigned char pad_10[0x8];
    int field_18;
    unsigned char pad_1C[0x18];
    int field_34;
};
// N182: [G] scoped to this function
#pragma push
#pragma opt_repositioncode off
// 0x00383FF0
void CGtSoundBankManager::UnloadBank(CGtSoundBank *p0)
{
    int rc = p0->GetReferenceCount();
    if (rc > 0) {
        p0->SetReferenceCount(rc - 1);
        return;
    }
    int id = p0->field_39C;
    p0->Unload();
    int n = field_18;
    UnkStruct_Ent *e;
    unsigned char *q;
    int i;
    for (i = 0; i < n; i++) {
        e = &field_C[i];
        if (e->field_0 == id) goto chk;
    cont: ;
    }
done:
    RemoveLink__11CGtFreeListFP15CGtFreeListLink((char *)this + 0x34, (char *)p0 - 8);
    goto fin;
chk:
    q = &e->field_8;
    if (e->field_8 == 0) goto cont;
    *q = 0;
    goto done;
fin: ;
}

#pragma pop
