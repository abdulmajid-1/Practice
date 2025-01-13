.model small
data_seg segment 'data'
    st1 db 13,10,"Enter first number : $"
    st2 db 13,10,"Enter second number : $"
    st3 db 13,10,"Enter third number : $"
    st4 db 13,10,"What operation you want to perform (+ , - , * , /) : $"
    st5 db 13,10,"The result is : $"
    minst db "-$"
    erromsg db 13,10,"Division by zero is not allowed $"
    first db ?
    second db ?
    third db ?
    operation db ?
    result db ?
    num db 0,0,0
data_seg ends

stack_seg segment 'stack'
    dw 100 DUP(?)
stack_seg ends

code_seg segment 'code'
    assume cs:code_seg, ss:stack_seg, ds:data_seg

    main proc far

    mov ax, data_seg
    mov ds, ax

    ; Take first number

    mov dx, offset st1
    mov ah, 09h
    int 21h
    call read_number
    mov first, al

    ; Take second number

    mov dx, offset st2
    mov ah, 09h
    int 21h
    call read_number
    mov second, al

    ;Take third number

    mov dx, offset st3
    mov ah, 09h
    int 21h
    call read_number
    mov third, al

    ; Ask what operation user want to perform

    mov dx, offset st4
    mov ah, 09h
    int 21h
    mov ah, 01h
    int 21h
    mov operation, al

    cmp operation, '+'
    je addsection

    cmp operation, '-'
    je subsection

    cmp operation, '*'
    je mulsection

    cmp operation, '/'
    je divsection
    
    jmp endsection ;if user entered wrong command 
    divsection:
        call Dividepro
        jmp endsection


    addsection:
        call Additionpro
        jmp endsection

    subsection:
        call Subtractionpro
        jmp endsection

    mulsection:
        call Multiplypro
    endsection:
        mov ah, 4ch
        int 21h

main endp
Additionpro proc near
    mov al, first
    add al, second
    add al, third
    mov dl, offset st5
    mov ah, 09h
    int 21h
    call greater_number ; print number
    ret
Additionpro endp
Dividepro proc near
    mov al, first   
    cmp al, 0
    je div_error

    xor ah, ah        
    mov bl, second
    cmp bl, 0
    je div_error

    div second         
    mov al, bl        
    xor ah, ah  
    mov bl, third
    cmp bl, 0
    je div_error

    div third          

    ; Convert the result to ASCII for display
    call convert_ascii

    ; Display the result message
    mov dx, offset st5
    mov ah, 09h
    int 21h

    ; Display the result character
    mov dl, result
    mov ah, 02h
    int 21h

    jmp endsection     ; Jump to the end of the program

div_error:
    mov dx, offset erromsg  ; Display an error message for invalid division
    mov ah, 09h
    int 21h
    ret
Dividepro endp

Multiplypro proc near
    mov al, first           ; Load the first number into AL
    mul second              ; Multiply AL by the second number
    mul third               ; Multiply the result by the third number;
    mov dl, offset st5
    mov ah, 09h
    int 21h
    call greater_number
    ret
Multiplypro endp
Subtractionpro proc near
     mov al, first
        sub al, second
        sub al, third
        js signednumber
        ;convert number to ascii
        call convert_ascii

        mov dx, offset st5
        mov ah, 09h
        int 21h
        mov dl, result
        mov ah, 02
        int 21h
        jmp endsection

        signednumber:
            NEG ax
            mov dx, offset st5
            mov ah, 09h
            int 21h
            mov dl, offset minst
            mov ah, 09h
            int 21h
            call greater_number
            ret
Subtractionpro endp

greater_number proc near
        mov ah, 0               ; Clear AH for division
        mov bx, 10              ; Base 10 divisor

        mov cx, 0               ; CX will hold the number of digits
        mov si, offset num      ; Store digits in the `num` array
    digit_extract:
        xor dx, dx              ; Clear DX for division
        div bx                  ; Divide AX by 10
        add dl, '0'             ; Convert remainder (DL) to ASCII
        mov [si], dl            ; Store ASCII digit in `num` array
        inc si                  ; Move to the next position in the array
        inc cx                  ; Increment digit count
        test ax, ax             ; Check if the quotient is zero
        jnz digit_extract       ; If not, continue extracting digits


    ; Now print the digits in reverse order

    print_digits:
     

        dec si                  ; Move back to the last stored digit
        mov dl, [si]            ; Load the digit into DL
        mov ah, 02h             ; Print the character
        int 21h
        loop print_digits       ; Repeat for all digits
        ret
greater_number endp
read_number proc near
    mov ah, 01h
    int 21h
    sub al, '0'
    ret
read_number endp

convert_ascii proc near
    add al, '0'
    mov result, al
    ret
convert_ascii endp

code_seg ends
end main



