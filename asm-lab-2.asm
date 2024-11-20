;⦁	Write a program to count the number of 1s in a binary number using SHR.
;  Hint: 14 is a binary number 

[org 0x100]
mov ax, 14

mov cx, 0
jmp start

condition:
        add cx, 1 ; cx will store the result
        test ax, ax ; this will test if all the ones have been shifted or not
        jz End ; this will jump to end if above condition is true

        
start:
    shr ax,1 ; shift right
    jc condition ; this will check if the carry flag is one because of the shifting operation
                 ; it will jump if it was one 
    jmp start

End:
    mov ax, 0x4c00
    int 0x21

    