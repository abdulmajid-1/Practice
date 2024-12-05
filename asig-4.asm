.model small
.data
    char db 'A'            ; Character to display
    row db 12              ; Initial row (Y-coordinate)
    col db 40              ; Initial column (X-coordinate)
    blank db ' '           ; Used to erase the previous character
.stack 100h
.code
    assume cs:code_seg, ds:data_seg, ss:stack_seg

main proc
    ; Initialize data segment
    mov ax, data_seg
    mov ds, ax

    ; Main animation loop
animate:
    ; Read a key using INT 16h
    mov ah, 00h             ; BIOS function to get key
    int 16h                 ; Wait for a keypress
    cmp al, 1Bh             ; Check for Escape key (ASCII 27)
    je exit_program         ; If Esc, exit the program

    ; Erase the current character
    mov ah, 02h             ; Set cursor position function
    xor bh, bh              ; Page number 0
    mov dh, row             ; Current row
    mov dl, col             ; Current column
    int 10h
    mov ah, 09h             ; Write character function
    mov al, blank           ; Load blank space
    mov bh, 00h             ; Page number
    mov bl, 07h             ; Attribute (white on black)
    mov cx, 1               ; Repeat count
    int 10h

    ; Move the character based on the arrow key
    cmp al, 00h             ; Check if it's an extended key
    jne animate             ; Ignore if not extended key
    cmp ah, 72h             ; Check if Up Arrow (Scan Code 72h)
    je move_up
    cmp ah, 80h             ; Check if Down Arrow (Scan Code 80h)
    je move_down
    cmp ah, 75h             ; Check if Left Arrow (Scan Code 75h)
    je move_left
    cmp ah, 77h             ; Check if Right Arrow (Scan Code 77h)
    je move_right

    jmp redraw_character    ; Skip movement logic if no valid arrow key

move_up:
    cmp row, 0              ; Prevent going off-screen
    je animate
    dec row                 ; Move one row up
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
    xor bh, bh              ; Page number 0
    mov dh, row             ; Current row
    mov dl, col             ; Current column
    int 10h
    ; Print the character
    mov ah, 09h             ; Write character function
    mov al, char            ; Load character
    mov bh, 00h             ; Page number
    mov bl, 07h             ; Attribute (white on black)
    mov cx, 1               ; Repeat count
    int 10h
    jmp animate             ; Loop back for next input

exit_program:
    mov ax, 4C00h           ; DOS terminate program
    int 21h

main endp
end main
