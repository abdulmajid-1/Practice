;Write an assembly program to perform multiplication of two 3-bit numbers
[org 0x100]

jmp start

multipliler: db 7
multiplicand: db 5
result: dd 0

start:
    mov al, [multipliler]
    mov bl, [multiplicand]
    mov cl, 3
    checkbit:

        shr al, 1
        jnc next

        add [result], bl

    next:
        shl bl, 1
        dec cl
        jnz checkbit

    endif:
        mov ax, 0x4c00
        int 0x21

