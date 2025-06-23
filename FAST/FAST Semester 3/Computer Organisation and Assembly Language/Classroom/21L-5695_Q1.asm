[org 0x0100]

jmp start

cmpBits:
        push bp
        mov bp, sp
        sub sp, 10 ; 5 Local Variables
        push si
        push di
        push cx
        push dx

        mov si, 1000000000000000b ; Mask to get the MSB
        mov di, 1
        mov cx, 1

    top:    ; Creating a mask for bx
        shl di, 1
        inc cx
        cmp cx, [bp + 4]
        jne top

        mov cx, 0
        mov [bp - 10], cx ; count for index
        mov [bp - 8], bx ; storing bx to retain later incase we need it

        jmp initcheck ; intially we need to compare directly

    itercheck:
        shl bx, 1
        inc cx
        cmp cx, [bp + 4]
        je count
    contcheck:
        shl ax, 1
        add word[bp - 10], 1 ; incrementing count
        cmp word[bp - 10], 16
        jge count
        mov word[bp - 2], 0
    initcheck:
        mov [bp - 4], si
        and [bp - 4], ax ; this will get the MSB of ax
                         ; in case of 0x8000, we get MSB as 1
    currcheck:
        mov [bp - 6], di
        and [bp - 6], bx ; this will get the MSB of bx
                         ; in case of 0xn, we get MSB as 1
        cmp word[bp - 4], 0x8000
        jne ws
        mov word[bp - 4], 1
        jmp forw1

        ws:
        mov word[bp - 4], 0

        ;; Bringing both results on equal terms
    forw1:
        cmp [bp - 6], di
        jne ws2
        mov word[bp - 6], 1
        jmp forw2

        ws2:
        mov word[bp - 6], 0

    forw2:
        mov dx, [bp - 4]
        cmp dx, [bp - 6]

        je itercheck

    notEqual:
        mov cx, 0 ; resetting counter
        mov bx, [bp - 8] ; Resetting bx to original n bits
        cmp word[bp - 2], 1
        je contcheck
        mov word[bp - 2], 1
        mov [bp - 6], di
        and [bp - 6], bx
        jmp forw1

    count:
        mov cx, -1 ; init with -1
        cmp word[bp - 10], 16
        jge end

    cal: ; calculating the index we found to be matched
        mov cx, word[bp - 10]
        sub cx, [bp + 4]
        inc cx

    end:
        mov ax, cx ; moving seached index to ax

        pop dx
        pop cx
        pop di
        pop si
        mov sp, bp
        pop bp
        ret

start:
    mov ax, 1110111100001010b ; 16 bit number
    mov bx, 111100b ; n-bit pattern 
    mov cx, 6 ; size of n bits
    push cx
    call cmpBits

mov ax, 0x4c00
int 0x21