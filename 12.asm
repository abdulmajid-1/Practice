.model small

data_seg segment 'data'
    st1 db 53 DUP(?)
    st2 db 'A', 13,10,'$'
data_seg ends

stack_seg segment 'stack'
    dw 100 DUP(?)
stack_seg ends

code_seg segment 'code'
    assume cs: code_seg, ss: stack_seg, ds: data_seg
main proc far
    mov ax, data_seg
    mov ds, ax

    mov ah, 06h
    mov al, 25
    mov bh, 07h
    mov cx, 0000h
    mov dx, 184Fh
    int 10h

    mov bh, 0
    mov dh, 10
    mov dl, 30
    mov ah, 02h
    int 10h

    mov dx, offset st2
    mov ah, 09h
    int 21h

    mov ah, 4Ch
    int 21h

main endp

code_seg ends

end main
