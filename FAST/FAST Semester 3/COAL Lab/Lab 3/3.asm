[org 0x0100]

mov si,0
mov cx, 22
mov ax,8
mov bx,0

l1: cmp ax,[array+si]
jz addresult
add si,2
dec cx
jnz l1
jz end

addresult: add bx,1
add si,2
dec cx
jnz l1
jz end

end: mov ax,0x4c00
int 0x21

array : dw 1,9,9,9,8,8,8,8,8,8,1,1,9,9,8,8,8,8,1,9,8,8

