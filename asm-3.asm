
.model small

; we store our name in st1
; each letter of the name will create a byte in memory

data_seg segment 'data'
  st1 db "Abdul Majid", 13, 10, '$'
data_seg ends

stack_seg segment 'stack'
  dw 100 DUP(?)
stack_seg ends

; code segment
code_seg segment 'code'
  assume cs:code_seg, ds:data_seg, ss:stack_seg
main proc far
 
  mov ax, data_seg
  mov ds, ax

  mov ah, 06h
  mov al, 25     ;mov 25 lines
  mov bh, 07h
  mov cx, 0000h  ;top most left is row and column is 0
  mov dx, 184Fh  ;lower right most col = 79 and row = 24
  int 10h 

  ; change the cursor position

  mov bh, 0   ;page number zero
  mov dh, 12  ;total rows = 25, half = 25/2
  mov dl, 33  ;total cols = 80, half = 80/2 = 40 - (string length / 2) 7 = 33
  mov ah, 02
  int 10h  ;for changing cursor

  ; printing the string
  mov dx, offset st1
  mov ah, 9
  int 21h
  
  mov ah, 04ch
  int 21h

main endp
code_seg ends


end main
