[org 0x0100]
jmp start

largestnumber:
  mov al,[array]
  mov si,0
  mov cl,[array+bx]

 loop1:
   add si,1
   cmp si ,4
   je end
   cmp cl,[array+si]
   jb largest
   jmp loop1

largest:
   mov cl,[array+si]
   mov [n], cl
   sub cl,2
   mov[r], cl
   jmp loop1
   

start:
   call largestnumber


  end:mov ax,0x4c00
  int 0x21

array: db 5,6,9,2
n: db 0
r: db 0
