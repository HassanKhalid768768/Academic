[org 0x0100]

jmp start

struct:
    push bp
    mov bp, sp
    sub sp, 10 ; 5 local variables
    push ax
    push bx
    push cx
    push si
    push di

    ; Current Condition / Access of the Stack
    
    ; |         |-> Further pushes by SP but we use BP as ref.
    ; |   LV 5  |-> BP - 10
    ; |   LV 4  |-> BP - 8
    ; |   LV 3  |-> BP - 6
    ; |   LV 2  |-> BP - 4
    ; |   LV 1  |-> BP - 2
    ; |    BP   |-> BP
    ; |  ret A  |-> BP + 2
    ; |  i/p 4  |-> BP + 4
    ; |  i/p 3  |-> BP + 6
    ; |  i/p 2  |-> BP + 8
    ; |  i/p 1  |-> BP + 10
    ; |  o/p 3  |-> BP + 12
    ; |  o/p 2  |-> BP + 14
    ; |__o/p 1__|-> BP + 16

    mov ax, [bp + 4]
    mov [bp - 2], ax
    add ax, [bp + 6]
    mov [bp - 4], ax
    add ax, [bp + 8]
    mov [bp - 6], ax
    add ax, [bp + 10]
    mov [bp - 8], ax

    mov word[bp + 12], 5
    mov word[bp + 14], 15
    mov word[bp + 16], 25

    pop di
    pop si
    pop cx
    pop bx
    pop ax
    mov sp, bp
    pop bp
    ret 8

start:
    ; Space allocation for outputs
    sub sp, 6

    ; Pushing inputs
    mov ax, 1
    push ax
    push ax
    push ax
    push ax

    call struct

    ; Poping outputs from the stack
    pop ax
    pop bx
    pop cx

mov ax, 0x4c00
int 0x21