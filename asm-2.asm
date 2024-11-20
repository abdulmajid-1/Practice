.model small

Dataseg segment 'Data'

    name db "Abdul Majid$"   ; Replace with your name followed by '$'

Dataseg ends
Codeseg segment 'code'

    assume cs:Codeseg, ds:Dataseg, ss:Stackseg

    main proc for
    ; Initialize data segment
    mov ax, Dataseg
    mov ds, ax

    ; Clear screen (int 10h, ah = 0)
    mov ah, 0
    int 10h  ; Clears the screen

    ; Move cursor to middle of screen (row 12, column 40)
    mov ah, 2          ; Function to set cursor position
    mov bh, 0          ; Page number (usually 0)
    mov dl, 40         ; Column (40th column)
    mov dh, 12         ; Row (12th row)
    int 10h            ; Call BIOS interrupt

    ; Print name
    mov ah, 9          ; Function to display string
    lea dx, name       ; Load address of the string into DX
    int 21h            ; Call DOS interrupt to display string

    ; Exit program
    mov ah, 4Ch        ; DOS function to terminate program
    int 21h            ; Call DOS interrupt to exit
    main endp

Code_seg ends

code_seg segment 'stack' dw 

    80H DUP(?)

stack_seg ends

end main

