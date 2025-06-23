[org 0x0100]
jmp start

multiply:
mov cx,0
mov si,1
mov ax, [p]
l1:
mul word[p]
add cx,ax
mov ax,cx
add si,1
cmp si,5
jnz l1
mov [f],cx
ret


start:
mov ax, [p]
mov bx, [m]
call multiply


mov ax, 0x4c00
int 0x21

p: dw 5
m: dw 7
f: dd 0