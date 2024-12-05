.model small
data_seg segment 'data'
    st1 db 13,10,"Input char: "
    mychar db(?)
data_seg ends

stack_seg segment 'stack'
    dw 100 DUP(?)
stack_seg ends

code_seg segment 'code'
    assume cs:code_seg, ds:data_seg, ss:stack_seg
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
    mov dh, 12
    mov dl, 33
    mov ah, 02
    int 10h

 ;   mov dx, offset st1
 ;   mov ah, 9
 ;   int 21h


  ;  mov ah, 1
  ;  int 21h
  ;  mov mychar, al

   ; mov bh, 0
   ; mov dh, 12
   ; mov dl, 40
   ; mov ah, 02
   ; int 10h

    ;mov ah, 2
   ; mov dl, mychar
   ; int 21h

    mov ax, 4ch
    int 21h
main endp
code_seg ends
end main



