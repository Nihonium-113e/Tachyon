global load
section .multiboot
align 4
dd 0x1BADB002
dd 0x00
dd -(0x1BADB002 + 0x00)

section .text 
extern kmain
load:
    mov eax, 0xCAFEBABE
    call kmain
    cli
    hlt
    jmp $
.loop:
    jmp .loop