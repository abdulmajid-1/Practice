.model small
data_seg segment 'data'
    row db 12              ; Initial row (Y-coordinate)
    col db 33              ; Initial column (X-coordinate)
    blank db ' '           ; Used to erase the previous character
    char db 'A'
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
setcursor:
    mov bh, 00
    mov dh, row
    mov dl, col
    mov ah, 02
    int 10h
    

    mov dl, char
    mov ah, 02
    int 21h


    mov ah, 00h
    int 16h
    mov ah, 00h

animate:
    
    cmp al, 1BH
    je exitpro

    cmp ah, 72h             ; Check if Up Arrow (Scan Code 72h)
    je move_up

    cmp ah, 80h             ; Check if Down Arrow (Scan Code 80h)
    je move_down

    cmp ah, 75h             ; Check if Left Arrow (Scan Code 75h)
    je move_left

    cmp ah, 77h             ; Check if Right Arrow (Scan Code 77h)
    je move_right

move_up:
    cmp row, 0              ; Prevent going off-screen
    je skip_move
    mov ah, 02h             ; Set cursor position function
    mov bh, 0               ; Page number 0
    mov dh, row             ; Current row
    mov dl, col             ; Current column
    int 10h

    ; Print a blank space
    mov dl, blank
    mov ah, 02
    int 21h

    dec row, 1

    ; Set cursor position to current (row, col)
    mov bh, 00
    mov dh, row
    mov dl, col
    mov ah, 02
    int 10h


    ; Print the character
    mov dl, char
    mov ah, 02
    int 21h

skip_move:
    jmp animate

move_down:
    cmp row, 24             ; Prevent going off-screen (25 rows max)
    je skip_move

    mov ah, 02h             ; Set cursor position function
    mov bh, 0               ; Page number 0
    mov dh, row             ; Current row
    mov dl, col             ; Current column
    int 10h

    ; Print a blank space
    mov dl, blank
    mov ah, 02
    int 21h

    inc row, 1

    ; Set cursor position to current (row, col)
    mov bh, 00
    mov dh, row
    mov dl, col
    mov ah, 02
    int 10h


    ; Print the character
    mov dl, char
    mov ah, 02
    int 21h


skip_move:
    jmp animate

move_left:
    cmp col, 0              ; Prevent going off-screen
    je skip_move

    mov ah, 02h             ; Set cursor position function
    mov bh, 0               ; Page number 0
    mov dh, row             ; Current row
    mov dl, col             ; Current column
    int 10h

    ; Print a blank space
    mov dl, blank
    mov ah, 02
    int 21h

    dec col, 1

    ; Set cursor position to current (row, col)
    mov bh, 00
    mov dh, row
    mov dl, col
    mov ah, 02
    int 10h


    ; Print the character
    mov dl, char
    mov ah, 02
    int 21h

skip_move:
    jmp animate

move_right:
    cmp col, 79             ; Prevent going off-screen (80 columns max)
    je skip_move
        mov ah, 02h             ; Set cursor position function
    mov bh, 0               ; Page number 0
    mov dh, row             ; Current row
    mov dl, col             ; Current column
    int 10h

    ; Print a blank space
    mov dl, blank
    mov ah, 02
    int 21h

    inc row, 1

    ; Set cursor position to current (row, col)
    mov bh, 00
    mov dh, row
    mov dl, col
    mov ah, 02
    int 10h


    ; Print the character
    mov dl, char
    mov ah, 02
    int 21h

skip_move:
    jmp animate        
        
    



    exitpro:
    mov ah, 4Ch
    int 21h
main endp
code_seg ends
end main



