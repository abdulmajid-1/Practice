.model small

data_seg segment 'data'
   st1 db 53 DUP(?)      ; Buffer for input (53 bytes max)
   st2 db "Input Name: ",13,10,'$'
   st3 db "Name is: ",13,10,'$'
   Mychar db ?           ; Reserved, but not used in this program
data_seg ends

stack_seg segment 'stack'
  dw 100 DUP(?)          ; Define stack space
stack_seg ends

code_seg segment 'code'
  assume cs:code_seg, ds:data_seg, ss:stack_seg
main proc far

  ; Initialize data segment
  mov ax, data_seg
  mov ds, ax

  ; Clear the screen using interrupt 10h, function 06h
  mov ah, 06h
  mov al, 00h          ; Clear entire screen
  mov bh, 07h          ; Background color (white)
  mov cx, 0000h        ; Top-left corner (row 0, col 0)
  mov dx, 184Fh        ; Bottom-right corner (row 24, col 79)
  int 10h 

  ; Set cursor position to display "Input Name:"
  mov bh, 0            ; Page number 0
  mov dh, 10           ; Row 10 (slightly above center)
  mov dl, 30           ; Column 30 (arbitrary start position for input prompt)
  mov ah, 02h          ; Set cursor position
  int 10h 

  ; Display "Input Name:" message
  mov dx, offset st2
  mov ah, 09h
  int 21h

  ; Set up input buffer
  mov st1[0], 50       ; Max input length is 50 characters
  mov dx, offset st1
  mov ah, 0Ah          ; Buffered input function
  int 21h

  ; Terminate the user input string
  mov bl, st1[1]       ; Get the length of the input
  mov bh, 0
  mov st1[bx + 2], '$' ; Add string terminator ('$') at the end of input


  mov bh, 0
  mov dh, 11
  mov dl, 30
  mov ah, 02h
  int 10h


  ; Display "Name is:" message
  mov dx, offset st3
  mov ah, 09h
  int 21h


  mov bh, 0            ; Page number 0
  mov dh, 11           ; Row 10 (slightly above center)
  mov dl, 39           ; Column 30 (arbitrary start position for input prompt)
  mov ah, 02h          ; Set cursor position
  int 10h 


  ; Display the user's input
  mov dx, offset st1 + 2 ; Skip buffer control bytes
  mov ah, 09h
  int 21h

  ; Exit program
  mov ah, 4Ch
  int 21h

main endp
code_seg ends
end main
