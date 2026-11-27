global koutb
global kinb

koutb:
    mov al, [esp+8]
    mov dx, [esp+4]
    out dx, al
    ret

kinb:
    mov dx, [esp+4]
    in al, dx
    ret