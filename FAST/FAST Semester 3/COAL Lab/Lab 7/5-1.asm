[org 0x0100]
jmp start

rollnumber:
mov di,0
mov si,0
mov bx,ax
l1:
mov ax,bx
mov dx,0
mov cx , 0x10
div cx
mov bx ,ax
mov [p+si],dx
add si,2
add di,1
cmp di,4
jnz l1
ret

start:
mov ax, 0x5692
call rollnumber

mov si,0
mov cx,0
l2:
mov ax,[p+si]
add si,2
add cx,ax
cmp si,8
jnz l2

shr cx,1
shr cx,1
add cx,2
mov [m],cx

mov ax, 0x4c00
int 0x21

p: dw 0
m: dw 0