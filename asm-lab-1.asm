; ⦁	Predict the output of SHL and SAR operations on the number 1101 (signed and unsigned cases).


[org 0x100]

mov ax, 13
mov bx, -3 ; this is signed

shl ax, 1

shl bx, 1

mov cx, ax
mov dx, bx

mov ax, 13
mov bx, -3 ; this is for signed

sar ax, 1
sar bx, 1
mov ax, 0x4c00
int 0x21
