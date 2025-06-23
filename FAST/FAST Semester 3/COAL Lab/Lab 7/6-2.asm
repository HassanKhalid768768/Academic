[org 0x100]

jmp start

length1: dw 10
length2: dw 20
length3: dw 30
length3: dw 40

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
mov di,0

nextloc:
mov word[es:di],0x072B
add di,2
cmp di,80
jne nextloc


pop di
pop si
pop cx
pop ax
pop es
pop bp
ret 10

start:
call clrscr

call printstr

mov ax, 0x4C00
int 21h