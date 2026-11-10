.include "macro.inc"

.section .text, "ax"

nonmatching vu_rw_0046A000, 0x270

glabel vu_rw_0046A000
.incbin "assembly/assets/vu/rw_0046A000.textbin.bin"
endlabel vu_rw_0046A000
