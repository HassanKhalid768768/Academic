[org 0x0100]

jmp start

memory: dw 4

result: dw 0

start: 
mov di,1
mov bx,[memory]

l1:
mov cx,8

mov dx,[memory]

sub dx,di

checkbit: shr dx,1
jnc skip

add [result],bx

skip: shl bx,1
dec cx
jnz checkbit

mov bx, [result]
inc di

cmp di,3
jnz l1

mov ax, [result]

mov ax,0x4c00
int 0x21

