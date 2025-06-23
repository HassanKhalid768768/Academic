; this is a comment. Comment starts with semicolon
; this program adds three numbers in registers
[org 0x0100] ;we will see org directive later

mov bx, 3 ;
mov ax, 3 ; 
add ax, bx ; 
add ax, bx ;
add ax, bx ;
add ax, bx ;
mov ax, 0x4c00 ;terminate the program
int 0x21