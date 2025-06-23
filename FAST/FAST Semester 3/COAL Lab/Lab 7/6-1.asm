[org 0x100]

jmp start

str1: db 'COMPUTER ORGANISATION'
str2: db 'AND'
str3: db 'ASSEMBLY LANGUAGE'
length1: dw 21
length2: dw 3
length3: dw 17

clrscr:
push es
push ax
push di

mov ax, 0xb800
mov es, ax
mov di, 0

nextloc:
mov word[es:di],0x0720
add di,2
cmp di,4000
jne nextloc

pop di
pop ax
pop es
ret

printstr:
push bp
mov bp,sp
push es
push ax
push cx
push si
push di

mov ax, 0xb800
mov es,ax
mov al,80
mul byte[bp+10]
add ax,[bp+12]
shl ax,1
mov di,ax
mov si,[bp+6]
mov cx,[bp+4]
mov ah,[bp+8]

nextchar:
mov al,[si]
mov [es:di],ax
add di,2
add si,1
loop nextchar

pop di
pop si
pop cx
pop ax
pop es
pop bp
ret 10

start:
call clrscr

mov ax,30
push ax
mov ax,20
push ax
mov ax,0xFC
push ax
mov ax,str1
push ax
push word[length1]
call printstr

mov ax,10
push ax
mov ax,10
push ax
mov ax,0xFE
push ax

mov ax,str2
push ax
push word[length2]
call printstr

mov ax,50
push ax
mov ax,0
push ax
mov ax,0xFF
push ax

mov ax,str3
push ax
push word[length3]
call printstr

mov ax, 0x4C00
int 21h