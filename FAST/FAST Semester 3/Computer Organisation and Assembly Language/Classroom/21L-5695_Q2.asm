[org 0x0100]

jmp start

array1: dw 6, 7, 3, 9, 100, 5, 1, 50
lenArray1: dw 8

bubbleSort:
        push bp
        mov bp, sp
        sub sp, 2 ; 1 Local Variable
        push ax
        push dx
        push bx
        push si
        push di

        ; Input Parameters
        ; [bp + 4] = size of arr
        ; [bp + 6] = address of arr

        ; Local Variable(s)
        ; [bp - 2] = swap flag

        mov bx, [bp + 6]
        mov di, [bp + 4]
        shl di, 1 ; byte offset
        sub di, 2

    outerLoop:
        mov word[bp - 2], 0 ; Swap Flag
        mov si, 0

    innerLoop:
        mov ax, [bx + si] ; elem 1
        mov dx, [bx + si + 2] ; elem 2
        cmp ax, dx
        jle skip

        ;swap
        mov [bx + si], dx
        mov [bx + si + 2], ax
        mov word[bp - 2], 1

    skip:
        add si, 2
        cmp si, di
        jne innerLoop

        cmp word[bp - 2], 1
        je outerLoop

        pop di
        pop si
        pop bx
        pop dx
        pop ax
        mov sp, bp
        pop bp
        ret 4

statsOfArray:
        push bp
        mov bp, sp
        push ax
        push dx
        push bx
        push si
        push cx

        ; Input Paramters of the stack
        ; [bp + 4] = len of arr
        ; [bp + 6] = address of arr

        ; Output Parameters of the stack
        ; [bp + 8] = min
        ; [bp + 10] = max
        ; [bp + 12] = median

        mov bx, [bp + 6]
        mov cx, [bp + 4]

        mov si, 0
        mov ax, [bx + si]
        mov word[bp + 8], ax    ; taking first elem as min/max
        mov word[bp + 10], ax

    mimax:
        mov ax, [bx + si]
        cmp ax, [bp + 8] ; min
        jge chk1
        mov [bp + 8], ax
    chk1:
        cmp ax, [bp + 10] ; max
        jle chk2
        mov [bp + 10], ax

    chk2:
        add si,  2
        loop mimax

        ; sorting the array
        push bx ; addr
        push word[bp + 4] ; len
        call bubbleSort

        mov ax, [bp + 4]
        mov cx, 2
        div cx
        cmp dx, 0
        jne odd

        ; Even
        mov si, [bp + 4]
        mov ax, [bx + si]
        mov dx, [bx + si - 2]
        add ax, dx ; sum of two middle values
        shr ax, 1 ; dividing by 2
        jmp exit

    odd:    
        ; Odd
        mov si, [bp + 4]
        dec si
        mov ax, [bx + si]

    exit:
        mov word[bp + 12], ax ; copying median

        pop cx
        pop si
        pop bx
        pop dx
        pop ax
        pop bp
        ret 4

start:
    sub sp, 6 ; Stack allocation for outputs

    mov ax, array1
    push ax
    push word[lenArray1]
    call statsOfArray

    pop ax ; min value
    pop bx ; max value
    pop cx ; median

mov ax, 0x4c00
int 0x21