; this is a comment. Comment starts with semicolon
; this program adds three numbers in registers
[org 0x0100] ;we will see org directive later

mov ax, 10 ;
mov bx, 20 ; 
mov cx, 30 ;
mov dx, bx ;  
mov bx, ax ; 
mov ax, cx ;
mov cx, dx ;
mov dx, ax ;
mov ax, cx ;
mov cx, bx ;
mov bx, dx ;
mov ax, 0x4c00 ;terminate the program
int 0x21