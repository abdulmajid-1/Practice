.model small
data_seg segment 'data'
    char db 'A'            ; Character to display
    row db 12              ; Initial row (Y-coordinate)
    col db 33              ; Initial column (X-coordinate)
    blank db ' '           ; Used to erase the previous character
data_seg ends

stack_seg segment 'stack'
    dw 200 DUP(?)
stack_seg ends

code_seg segment 'code'
    assume cs:code_seg, ds:data_seg, ss:stack_seg

main proc far 
    ; Initialize data segment
    mov ax, data_seg
    mov ds, ax
    
    ;clear screen

    mov ah, 06h
    mov al, 25
    mov bh, 07h
    mov cx, 0000h
    mov dx, 184Fh
    int 10h
    ;put a char in the middle of the screen 
    mov bh, 00
    mov dh, row
    mov dl, col
    mov ah, 02
    int 10h
    

    mov dl, char
    mov ah, 02
    int 21h
    ; Main animation loop
animate:
    ; Read a key using INT 16h
    mov ah, 0              ; BIOS function to get key
    int 16h                 ; Wait for a keypress
    cmp al, 1Bh             ; Check for Escape key (ASCII 27)
    je tempexit        ; If Esc, exit the program

    mov cx, ax
    ; Erase the current character
    mov ah, 02h             ; Set cursor position function
    mov bh, 00              ; Page number 0
    mov dh, row             ; Current row
    mov dl, col             ; Current column
    int 10h
    
    mov dl, blank
    mov ah, 02
    int 21h
 
    mov ax, cx
    ; Move the character based on the arrow key
    cmp al, 00h             ; Check if it's an extended key
    jne animate             ; Ignore if not extended key
    cmp ah, 48h             ; Check if Up Arrow (Scan Code 46h)
    je move_up
    cmp ah, 50h             ; Check if Down Arrow (Scan Code 50h)
    je move_down
    cmp ah, 4Bh             ; Check if Left Arrow (Scan Code 4Bh)
    je move_left
    cmp ah, 4Dh             ; Check if Right Arrow (Scan Code 4Dh)
    je move_right

    jmp redraw_character    ; Skip movement logic if no valid arrow key
    tempexit:
        jmp exit_program
move_up:
    cmp row, 0              ; Prevent going off-screen
    je animate
    dec row                ; Move one row up
    jmp redraw_character

move_down:
    cmp row, 24             ; Prevent going off-screen (25 rows max)
    je animate
    inc row                 ; Move one row down
    jmp redraw_character

move_left:
    cmp col, 0              ; Prevent going off-screen
    je animate
    dec col                 ; Move one column left
    jmp redraw_character

move_right:
    cmp col, 79             ; Prevent going off-screen (80 columns max)
    je animate
    inc col                 ; Move one column right

 redraw_character:
  
    ; Set cursor position to current (row, col)
    mov ah, 02h             ; Set cursor position function
    mov bh, 0               ; Page number 0
    mov dh, row             ; Current row
    mov dl, col             ; Current column
    int 10h
    ; Print the character
    mov dl, char
    mov ah, 02
    int 21h

    jmp animate             ; Loop back for next input


exit_program:
    mov ax, 4C00h           ; DOS terminate program
    int 21h

main endp
code_seg ends
end main
