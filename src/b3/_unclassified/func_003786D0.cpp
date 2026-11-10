// Hand-written; the lifter refused it (a89: callees take self (a0 passes through); early 'value != 5 return'. Supersedes src/nonmatching/func_003786D0.cpp).

// func_003786D0 -- [L] DNAT: CB3OnlineRecordsDisplayMenuPage::Update() (research/proto/new_names.csv, vtable slot 2)
struct UnkStruct_D_01E90424 {
    int value;
    unsigned char pad[0x100];
};
struct UnkStruct_003786D0_blk { unsigned char pad_0[0x10]; };
struct UnkStruct_003786D0 {
    unsigned char pad_0[0xF05];
    signed char field_F05;
};
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_003786D0_blk D_01E898E8;
extern UnkStruct_003786D0_blk D_01E90240;

extern "C" void func_00377D30(void *);
extern "C" void func_00378080(void *);
extern "C" void func_00378240(void *);
extern "C" void func_00377E30(void *);
extern "C" void func_003778D0(void *);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_00378990(UnkStruct_003786D0 *);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, int, bool);

// 0x003786D0
extern "C" void func_003786D0(UnkStruct_003786D0 * self)
{
    if (D_01E90424.value != 5) return;
    {
        switch (self->field_F05) {
        case 0: func_00377D30(self); break;
        case 1: func_00378080(self); break;
        case 2: func_00378240(self); break;
        case 3: func_00377E30(self); break;
        case 4: func_003778D0(self); break;
        case 5:
            if (func_0032B2C0(&D_01E898E8, 0, 1) == 0) {
                if (self->field_F05 != 0) {
                    func_00378990(self);
                } else {
                    StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, 0);
                }
            }
            break;
        }
    }
}
