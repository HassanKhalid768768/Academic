[org 0x0100]

jmp start

memory: dw 13

result: dw 0

start: mov cx,8
mov bx,[memory]
mov dx,[memory]

checkbit: shr dx,1
jnc skip

add [result],bx

skip: shl bx,1
dec cx
jnz checkbit

mov ax, [result]

mov ax,0x4c00
int 0x21

