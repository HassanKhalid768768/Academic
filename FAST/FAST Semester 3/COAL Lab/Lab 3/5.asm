[org 0x0100]

  mov ax,[array]
  mov bx,0
  mov cx,[array+bx]

 loop1:
   add bx,2
   cmp bx ,22
   je last  
   cmp cx,[array+bx]
   jb largest
   jmp loop1

largest:
   mov cx,[array+bx]
   jmp loop1

last:
  mov ax,0x4c00
  int 0x21

array: dw 111,999,888,888,11,99,88,88,1,9,8,8
