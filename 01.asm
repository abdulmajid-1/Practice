[org 0x100]
mov ax, 5
mov bx, 5
add ax, bx
mov [num1], ax

mov ax, 0x4c00
int 0x21

num1: dw 0