[org 0x100]

jmp start

multiplier: dd 200
multiplicand: dd 100
result: dd 0

start:
    mov ax, [multiplier]
    mov bx, [multiplicand]
    mov cx, 8

checkbit:
    shr ax, 1
    jnc next
    add [result], bx


next:
    shl bx, 1
    dec cx
    jnz checkbit

    mov ax, 0x4c00
    int 0x21