[org 0x0100]

mov al,[n]
mov si,[n]
mul [al-si]
mov cl,0
add cl,al
   

mov ax,0x4c00
int 0x21

n: db 3
r: db 1
