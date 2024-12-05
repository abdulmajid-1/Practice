. model small
dataseg segment 'data'
    st1 db 13,10,"Input char"
    st2 db 13,10,"Char input was : "

    Mychar db(2)

Dataseg ends

codeseg segment 'code'
    assume cs:codeseg,ds:dataseg,ss:stackseg
    main proc for
    mov ax, dataseg
    mov ds, ax
    mov ah, 9
    mov ds, offset st1
    int 21h
    mov ah, 1
    int 21h
    mov mychar, al
    mov ah, 9
    mov dx, offset st2
    int 21h
    mov ah,2
    mov dl , mychar
    int 21h
    mov ah, 9
    mov dx, offset st1
    int 21h
    mov ah, 7
    int 21h
    mov mychar, al
    mov ah, 9
    mov dx, offset st2
    int 21h
    mov ah,2
    mov dl, mychar
    int 21h
    mov ah, 4ch
    int 21h

    main endp
    code_seg ends
    stack_seg ends
    end main