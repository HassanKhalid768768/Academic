[org 0x0100]

 jmp start

; strings to be printed
message1: db 'a|b|c|d' , 0
message2: db 'e|f|g|h' , 0
message3: db 'i|j|k|l' , 0
message4: db 'm|n|o|p' , 0
message5: db 'X has WON the game ' , 0
message6: db 'O has WON the game ' , 0
message7: db 'It is a DRAW no win' , 0
message8: db 'THIS GAME IS MADE BY MUHAMMAD HASSAN KHALID' , 0
message9: db 'ROLL NUMBER : 21L-5692' , 0
message10: db 'TIC TAC TOE', 0
message11: db 'By MUHAMMAD HASSAN KHALID' , 0
message12: db 'COAL PROJECT FAST NUCES LAHORE' , 0
message13: db 'Click any button to start the game' , 0
message14: db 'Instructions : Click any alphabet on keyboard corresponding to the alphabet on the screen to place firstly the X mark on that alphabet and then O on that alphabet any consecutive 4 O or X will result in that person winning the game' , 0 
message15: db 'Good Luck !!', 0
message16: db 'X|O|X|O' , 0
message17: db 'O|X|O|X' , 0
message18: db 'X|O|X|O' , 0
message19: db 'O|X|O|X' , 0
message: db '-------' , 0


; subroutine to clear the screen
clrscr: 
     push es
	 push ax
	 push cx
	 push di
	 
	 mov ax, 0xb800
	 mov es, ax ; point es to video base
	 xor di, di ; point di to top left column
	 mov ax, 0x0720 ; space char in normal attribute
	 mov cx, 2000 ; number of screen locations
	 
	 cld ; auto increment mode
	 rep stosw ; clear the whole screen
	 
	 pop di 
	 pop cx
	 pop ax
	 pop es
	 ret 
 
; subroutine to print a string
; takes the x position, y position, attribute, and address of a null
; terminated string as parameters
printstr: 
	 push bp
	 mov bp, sp
	 push es
	 push ax
	 push cx
	 push si
	 push di
	 
	 push ds
	 pop es ; load ds in es
	 mov di, [bp+4] ; point di to string
	 mov cx, 0xffff ; load maximum number in cx
	 xor al, al ; load a zero in al
	 repne scasb ; find zero in the string
	 mov ax, 0xffff ; load maximum number in ax
	 sub ax, cx ; find change in cx
	 dec ax ; exclude null from length
	 jz exitl ; no printing if string is empty
	 
	 mov cx, ax ; load string length in cx
	 mov ax, 0xb800
	 mov es, ax ; point es to video base
	 mov al, 80 ; load al with columns per row
	 mul byte [bp+8] ; multiply with y position
	 add ax, [bp+10] ; add x position
	 shl ax, 1 ; turn into byte offset
	 mov di,ax ; point di to required location
	 mov si, [bp+4] ; point si to string
	 mov ah, [bp+6] ; load attribute in ah
	 
	 cld ; auto increment mode
nextchar: 
     lodsb ; load next char in al
     stosw ; print char/attribute pair
	 loop nextchar ; repeat for the whole string
	 
exitl: 
     pop di
	 pop si
	 pop cx
	 pop ax
	 pop es
	 pop bp
	 ret 8 
 
 ; subroutine to print a character
 printchr: 
     push bp
	 mov bp, sp
	 push es
	 push ax
	 push cx
	 push si
	 push di
	 
	 mov ax, 0xb800
	 mov es, ax ; point es to video base
	 mov ah, [bp+4]
	 mov al, byte[bp+6]
	 mov di, [bp+8]
	 mov [es:di], ax ; show this char on screen
	 
	 pop di
	 pop si
	 pop cx
	 pop ax
	 pop es
	 pop bp
	 ret 6

; subroutine to print the welcome screen of game
 welcomescreen:
	 push es
	 push ax
	 push cx
	 push di
	 
	 mov ax, 0xb800
	 mov es, ax ; point es to video base
	 xor di, di ; point di to top left column
	 mov ax, 0x0720 ; space char in normal attribute
	 mov cx, 2000 ; number of screen locations
	 
	 cld ; auto increment mode
	 rep stosw ; clear the whole screen
	 
	 mov ax, 30
	 push ax ; push x position
	 mov ax, 4
	 push ax ; push y position
	 mov ax, 140 ; attribute
	 push ax ; push attribute
	 mov ax, message16
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine
	 
	 mov ax, 30
	 push ax ; push x position
	 mov ax, 5
	 push ax ; push y position
	 mov ax, 140 ; attribute
	 push ax ; push attribute
	 mov ax, message17
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine
	 
	 mov ax, 30
	 push ax ; push x position
	 mov ax, 6
	 push ax ; push y position
	 mov ax, 140 ; attribute
	 push ax ; push attribute
	 mov ax, message18
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine
	 
	 mov ax, 30
	 push ax ; push x position
	 mov ax, 7
	 push ax ; push y position
	 mov ax, 140 ; attribute
	 push ax ; push attribute
	 mov ax, message19
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine
	 
	 mov ax, 28
	 push ax ; push x position
	 mov ax, 9
	 push ax ; push y position
	 mov ax, 74 ; attribute
	 push ax ; push attribute
	 mov ax, message10
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine
	 
	 mov ax, 22
	 push ax ; push x position
	 mov ax, 11
	 push ax ; push y position
	 mov ax, 73 ; attribute
	 push ax ; push attribute
	 mov ax, message11
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine
	 
	 mov ax, 20
	 push ax ; push x position
	 mov ax, 12
	 push ax ; push y position
	 mov ax, 74 ; attribute
	 push ax ; push attribute
	 mov ax, message12
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine
	 
	 mov ax, 18
	 push ax ; push x position
	 mov ax, 14
	 push ax ; push y position
	 mov ax, 75 ; attribute
	 push ax ; push attribute
	 mov ax, message13
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine
	 
	 mov ax, 0
	 push ax ; push x position
	 mov ax, 16
	 push ax ; push y position
	 mov ax, 75 ; attribute
	 push ax ; push attribute
	 mov ax, message14
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine
	 
	 mov ax, 30
	 push ax ; push x position
	 mov ax, 21
	 push ax ; push y position
	 mov ax, 77 ; attribute
	 push ax ; push attribute
	 mov ax, message15
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine
	 
	 pop di 
	 pop cx
	 pop ax
	 pop es
	 ret
 
start: 

	 call welcomescreen ; call the welcome screen subroutine

	 call read_keyboard ; get input from user
	 
	 call clrscr ; call the clrscr subroutine

	 mov ax, 0
	 push ax ; push x position
	 mov ax, 1
	 push ax ; push y position
	 mov ax, 7 ; attribute
	 push ax ; push attribute
	 mov ax, message1
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine
	 
	 
	 mov ax, 0
	 push ax ; push x position
	 mov ax, 2
	 push ax ; push y position
	 mov ax, 3 ; attribute
	 push ax ; push attribute
	 mov ax, message
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine
	 
	 
	 mov ax, 0
	 push ax ; push x position
	 mov ax, 3
	 push ax ; push y position
	 mov ax, 7 ; attribute
	 push ax ; push attribute
	 mov ax, message2
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine
	 

	 mov ax, 0
	 push ax ; push x position
	 mov ax, 4
	 push ax ; push y position
	 mov ax, 3 ; attribute
	 push ax ; push attribute
	 mov ax, message
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine
	 
	 mov ax, 0
	 push ax ; push x position
	 mov ax, 5
	 push ax ; push y position
	 mov ax, 7 ; attribute
	 push ax ; push attribute
	 mov ax, message3
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine
	 
	 mov ax, 0
	 push ax ; push x position
	 mov ax, 6
	 push ax ; push y position
	 mov ax, 3 ; attribute
	 push ax ; push attribute
	 mov ax, message
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine
	 
	 mov ax, 0
	 push ax ; push x position
	 mov ax, 7
	 push ax ; push y position
	 mov ax, 7 ; attribute
	 push ax ; push attribute
	 mov ax, message4
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine

	 ; credits
	 mov ax, 16
	 push ax ; push x position
	 mov ax, 3
	 push ax ; push y position
	 mov ax, 7 ; attribute
	 push ax ; push attribute
	 mov ax, message8
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine
	 
	 mov ax, 16
	 push ax ; push x position
	 mov ax, 5
	 push ax ; push y position
	 mov ax, 7 ; attribute
	 push ax ; push attribute
	 mov ax, message9
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine

	mov cx, 0

; reading what the user has input from keyboard for user X
getpoint:

	 call read_keyboard
	 
	 cmp al,0x1b		; Esc key pressed
	 jne l100           ; not equal point to next location
	 jmp do_exit		; equal exit
	 l100:
	 cmp al,0x61        ; a key pressed
	 jne l1             ; not equal point to next location
	 jmp sq1            ; equal jump to corresponding location
	 l1:
	 cmp al,0x62
	 jne l2
	 jmp sq2
	 l2:
	 cmp al,0x63
	 jne l3
	 jmp sq3
	 l3:
	 cmp al,0x64
	 jne l4
	 jmp sq4
	 l4:
	 cmp al,0x65
	 jne l5
	 jmp sq5
	 l5:
	 cmp al,0x66
	 jne l6
	 jmp sq6
	 l6:
	 cmp al,0x67
	 jne l7
	 jmp sq7
	 l7:
	 cmp al,0x68
	 jne l8
	 jmp sq8
	 l8:
	 cmp al,0x69
	 jne l9
	 jmp sq9
	 l9:
	 cmp al,0x6A
	 jne l10
	 jmp sq10
	 l10:
	 cmp al,0x6B
	 jne l11
	 jmp sq11
	 l11:
	 cmp al,0x6C
	 jne l12
	 jmp sq12
	 l12:
	 cmp al,0x6D
	 jne l13
	 jmp sq13
	 l13:
	 cmp al,0x6E
	 jne l14
	 jmp sq14
	 l14:
	 cmp al,0x6F
	 jne l15
	 jmp sq15
	 l15:
	 cmp al,0x70
	 jne l16
	 jmp sq16
	 l16:
	 
	 ; incrementing counter by 1 to keep track of number of moves
	 add cx, 1
	 
	 ; seeing if any formation is made and if made ending the game with appopriate message
	 jmp find_whowon
	 l200:
	 
	 ; reading what the user has input from keyboard for user O
	 call read_keyboard
	 cmp al,0x1b		; Esc key pressed
	 jne l101           ; not equal point to next location
	 jmp do_exit		; exit
	 l101:
	 cmp al,0x61
	 jne l17
	 jmp sq17
	 l17:
	 cmp al,0x62
	 jne l18
	 jmp sq18
	 l18:
	 cmp al,0x63
	 jne l19
	 jmp sq19
	 l19:
	 cmp al,0x64
	 jne l20
	 jmp sq20
	 l20:
	 cmp al,0x65
	 jne l21
	 jmp sq21
	 l21:
	 cmp al,0x66
	 jne l22
	 jmp sq22
	 l22:
	 cmp al,0x67
	 jne l23
	 jmp sq23
	 l23:
	 cmp al,0x68
	 jne l24
	 jmp sq24
	 l24:
	 cmp al,0x69
	 jne l25
	 jmp sq25
	 l25:
	 cmp al,0x6A
	 jne l26
	 jmp sq26
	 l26:
	 cmp al,0x6B
	 jne l27
	 jmp sq27
	 l27:
	 cmp al,0x6C
	 jne l28
	 jmp sq28
	 l28:
	 cmp al,0x6D
	 jne l29
	 jmp sq29
	 l29:
	 cmp al,0x6E
	 jne l30
	 jmp sq30
	 l30:
	 cmp al,0x6F
	 jne l31
	 jmp sq31
	 l31:
	 cmp al,0x70
	 jne l32
	 jmp sq32
	 l32:
	 
	 ; incrementing counter by 1 to keep track of number of moves
	 add cx, 1
	 
	 ; seeing if any formation is made and if made ending the game with appopriate message
	 jmp find_whowon
	 l700:

	 ; if total number of moves reached
	 cmp cx, 16
	 ; end game by saying that its a draw
	 je exit
	 ; otherwise again jump to start of loop
	 jne getpoint
 
exit:
 
	 mov ax, 0
	 push ax ; push x position
	 mov ax, 9
	 push ax ; push y position
	 mov ax, 7 ; attribute
	 push ax ; push attribute
	 mov ax, message7
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine
	 
	 mov ax, 0x4c00 ; terminate program
	 int 0x21
 
do_exitX:

	 mov ax, 0
	 push ax ; push x position
	 mov ax, 9
	 push ax ; push y position
	 mov ax, 4 ; attribute
	 push ax ; push attribute
	 mov ax, message5
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine
	 
	 mov ax, 0x4c00 ; terminate program
	 int 0x21
 
do_exitO:

	 mov ax, 0
	 push ax ; push x position
	 mov ax, 9
	 push ax ; push y position
	 mov ax, 1 ; attribute
	 push ax ; push attribute
	 mov ax, message6
	 push ax ; push address of message
	 call printstr ; call the printstr subroutine
	 
	 mov ax, 0x4c00 ; terminate program
	 int 0x21
 
do_exit:

	 mov ax, 0x4c00 ; terminate program
	 int 0x21
 
 read_keyboard:
	 push bx
	 push cx
	 push dx
	 push si
	 push di
	 mov ah,0x00
	 int 0x16		; Call the BIOS for reading keyboard
	 pop di
	 pop si
	 pop dx
	 pop cx
	 pop bx
	 ret
	
 sq1:
	 mov di, 160     ; pointing to desired location
	 push di         ; pushing location
	 mov ax, 0x58    ; character to print
	 push ax         ; pushing character 
	 mov ax, 4       ; attribute
	 push ax         ; push attribute
	 call printchr   ; call subroutine
	 jmp l1          ; jump back to location
 
 sq2:
	 mov di, 164
	 push di
	 mov ax, 0x58
	 push ax
	 mov ax, 4
	 push ax
	 call printchr
	 jmp l2
 
 sq3:
	 mov di, 168
	 push di
	 mov ax, 0x58
	 push ax
	 mov ax, 4
	 push ax
	 call printchr
	 jmp l3
 
 sq4:
	 mov di, 172
	 push di
	 mov ax, 0x58
	 push ax
	 mov ax, 4
	 push ax
	 call printchr
	 jmp l4
 
 sq5:
	 mov di, 480
	 push di
	 mov ax, 0x58
	 push ax
	 mov ax, 4
	 push ax
	 call printchr
	 jmp l5
 
 sq6:
	 mov di, 484
	 push di
	 mov ax, 0x58
	 push ax
	 mov ax, 4
	 push ax
	 call printchr
	 jmp l6
 
 sq7:
	 mov di, 488
	 push di
	 mov ax, 0x58
	 push ax
	 mov ax, 4
	 push ax
	 call printchr
	 jmp l7
 
 sq8:
	 mov di, 492
	 push di
	 mov ax, 0x58
	 push ax
	 mov ax, 4
	 push ax
	 call printchr
	 jmp l8
 
 sq9:
	 mov di, 800
	 push di
	 mov ax, 0x58
	 push ax
	 mov ax, 4
	 push ax
	 call printchr
	 jmp l9
	 
 sq10:
	 mov di, 804
	 push di
	 mov ax, 0x58
	 push ax
	 mov ax, 4
	 push ax
	 call printchr
	 jmp l10
 
 sq11:
	 mov di, 808
	 push di
	 mov ax, 0x58
	 push ax
	 mov ax, 4
	 push ax
	 call printchr
	 jmp l11
 
 sq12:
	 mov di, 812
	 push di
	 mov ax, 0x58
	 push ax
	 mov ax, 4
	 push ax
	 call printchr
	 jmp l12
 
 sq13:
	 mov di, 1120
	 push di
	 mov ax, 0x58
	 push ax
	 mov ax, 4
	 push ax
	 call printchr
	 jmp l13
 
 sq14:
	 mov di, 1124
	 push di
	 mov ax, 0x58
	 push ax
	 mov ax, 4
	 push ax
	 call printchr
	 jmp l14
 
 sq15:
	 mov di, 1128
	 push di
	 mov ax, 0x58
	 push ax
	 mov ax, 4
	 push ax
	 call printchr
	 jmp l15
 
 sq16:
	 mov di, 1132
	 push di
	 mov ax, 0x58
	 push ax
	 mov ax, 4
	 push ax
	 call printchr
	 jmp l16
	 
 sq17:
	 mov di, 160
	 push di
	 mov ax, 0x4F
	 push ax
	 mov ax, 1
	 push ax
	 call printchr
	 jmp l17
 
 sq18:
	 mov di, 164
	 push di
	 mov ax, 0x4F
	 push ax
	 mov ax, 1
	 push ax
	 call printchr
	 jmp l18
 
 sq19:
	 mov di, 168
	 push di
	 mov ax, 0x4F
	 push ax
	 mov ax, 1
	 push ax
	 call printchr
	 jmp l19
 
 sq20:
	 mov di, 172
	 push di
	 mov ax, 0x4F
	 push ax
	 mov ax, 1
	 push ax
	 call printchr
	 jmp l20
 
 sq21:
	 mov di, 480
	 push di
	 mov ax, 0x4F
	 push ax
	 mov ax, 1
	 push ax
	 call printchr
	 jmp l21
 
 sq22:
	 mov di, 484
	 push di
	 mov ax, 0x4F
	 push ax
	 mov ax, 1
	 push ax
	 call printchr
	 jmp l22
 
 sq23:
	 mov di, 488
	 push di
	 mov ax, 0x4F
	 push ax
	 mov ax, 1
	 push ax
	 call printchr
	 jmp l23
	 
 sq24:
	 mov di, 492
	 push di
	 mov ax, 0x4F
	 push ax
	 mov ax, 1
	 push ax
	 call printchr
	 jmp l24
 
 sq25:
	 mov di, 800
	 push di
	 mov ax, 0x4F
	 push ax
	 mov ax, 1
	 push ax
	 call printchr
	 jmp l25
 
 sq26:
	 mov di, 804
	 push di
	 mov ax, 0x4F
	 push ax
	 mov ax, 1
	 push ax
	 call printchr
	 jmp l26
 
 sq27:
	 mov di, 808
	 push di
	 mov ax, 0x4F
	 push ax
	 mov ax, 1
	 push ax
	 call printchr
	 jmp l27
 
 sq28:
	 mov di, 812
	 push di
	 mov ax, 0x4F
	 push ax
	 mov ax, 1
	 push ax
	 call printchr
	 jmp l28
 
 sq29:
	 mov di, 1120
	 push di
	 mov ax, 0x4F
	 push ax
	 mov ax, 1
	 push ax
	 call printchr
	 jmp l29
 
 sq30:
	 mov di, 1124
	 push di
	 mov ax, 0x4F
	 push ax
	 mov ax, 1
	 push ax
	 call printchr
	 jmp l30
 
 sq31:
	 mov di, 1128
	 push di
	 mov ax, 0x4F
	 push ax
	 mov ax, 1
	 push ax
	 call printchr
	 jmp l31
	 
 sq32:
	 mov di, 1132
	 push di
	 mov ax, 0x4F
	 push ax
	 mov ax, 1
	 push ax
	 call printchr
	 jmp l32
	 
find_whowon:

	 mov ax, 0xb800
	 mov es, ax ; point es to video base
	 
	 ; row 1
	 mov dx, 0  ; X
	 mov bx, 0  ; O
	 mov ax, word[es:160] ; point to required location
	 cmp ax, 0x0458       ; compare with X
	 jne l202             ; not equal then jumo to next position 
	 call l201            ; equal hence increment X->dx by 1
	 l202:
	 cmp ax, 0x014F       ; compare with O
	 jne l206             ; not equal then jumo to next position 
	 call l301            ; equal hence increment O->bx by 1
	 l206:
	 mov ax, word[es:164]
	 cmp ax, 0x0458
	 jne l203
	 call l201
	 l203:
	 cmp ax, 0x014F
	 jne l207
	 call l301
	 l207:
	 mov ax, word[es:168]
	 cmp ax, 0x0458
	 jne l204
	 call l201
	 l204:
	 cmp ax, 0x014F
	 jne l208
	 call l301
	 l208:
	 mov ax, word[es:172]
	 cmp ax, 0x0458
	 jne l205
	 call l201
	 l205:
	 cmp ax, 0x014F
	 jne l209
	 call l301
	 l209:
	 cmp dx, 4
	 je do_exitX
	 cmp bx, 4
	 je do_exitO

	 ; row 2
	 mov dx, 0  ; X
	 mov bx, 0  ; O
	 mov ax, word[es:480]
	 cmp ax, 0x0458
	 jne l210
	 call l201
	 l210:
	 cmp ax, 0x014F
	 jne l211
	 call l301
	 l211:
	 mov ax, word[es:484]
	 cmp ax, 0x0458
	 jne l212
	 call l201
	 l212:
	 cmp ax, 0x014F
	 jne l213
	 call l301
	 l213:
	 mov ax, word[es:488]
	 cmp ax, 0x0458
	 jne l214
	 call l201
	 l214:
	 cmp ax, 0x014F
	 jne l215
	 call l301
	 l215:
	 mov ax, word[es:492]
	 cmp ax, 0x0458
	 jne l216
	 call l201
	 l216:
	 cmp ax, 0x014F
	 jne l217
	 call l301
	 l217:
	 cmp dx, 4
	 je do_exitX
	 cmp bx, 4
	 je do_exitO

	 ; row 3
	 mov dx, 0  ; X
	 mov bx, 0  ; O
	 mov ax, word[es:800]
	 cmp ax, 0x0458
	 jne l218
	 call l201
	 l218:
	 cmp ax, 0x014F
	 jne l219
	 call l301
	 l219:
	 mov ax, word[es:804]
	 cmp ax, 0x0458
	 jne l220
	 call l201
	 l220:
	 cmp ax, 0x014F
	 jne l221
	 call l301
	 l221:
	 mov ax, word[es:808]
	 cmp ax, 0x0458
	 jne l222
	 call l201
	 l222:
	 cmp ax, 0x014F
	 jne l223
	 call l301
	 l223:
	 mov ax, word[es:812]
	 cmp ax, 0x0458
	 jne l224
	 call l201
	 l224:
	 cmp ax, 0x014F
	 jne l225
	 call l301
	 l225:
	 cmp dx, 4
	 je do_exitX
	 cmp bx, 4
	 je do_exitO

	 ; row 4
	 mov dx, 0  ; X
	 mov bx, 0  ; O
	 mov ax, word[es:1120]
	 cmp ax, 0x0458
	 jne l226
	 call l201
	 l226:
	 cmp ax, 0x014F
	 jne l227
	 call l301
	 l227:
	 mov ax, word[es:1124]
	 cmp ax, 0x0458
	 jne l228
	 call l201
	 l228:
	 cmp ax, 0x014F
	 jne l229
	 call l301
	 l229:
	 mov ax, word[es:1128]
	 cmp ax, 0x0458
	 jne l230
	 call l201
	 l230:
	 cmp ax, 0x014F
	 jne l231
	 call l301
	 l231:
	 mov ax, word[es:1132]
	 cmp ax, 0x0458
	 jne l232
	 call l201
	 l232:
	 cmp ax, 0x014F
	 jne l233
	 call l301
	 l233:
	 cmp dx, 4
	 je do_exitX
	 cmp bx, 4
	 je do_exitO

	 ; column 1
	 mov dx, 0  ; X
	 mov bx, 0  ; O
	 mov ax, word[es:160]
	 cmp ax, 0x0458
	 jne l234
	 call l201
	 l234:
	 cmp ax, 0x014F
	 jne l235
	 call l301
	 l235:
	 mov ax, word[es:480]
	 cmp ax, 0x0458
	 jne l236
	 call l201
	 l236:
	 cmp ax, 0x014F
	 jne l237
	 call l301
	 l237:
	 mov ax, word[es:800]
	 cmp ax, 0x0458
	 jne l238
	 call l201
	 l238:
	 cmp ax, 0x014F
	 jne l239
	 call l301
	 l239:
	 mov ax, word[es:1120]
	 cmp ax, 0x0458
	 jne l240
	 call l201
	 l240:
	 cmp ax, 0x014F
	 jne l241
	 call l301
	 l241:
	 cmp dx, 4
	 je do_exitX
	 cmp bx, 4
	 je do_exitO
	 
	 ; column 2
	 mov dx, 0  ; X
	 mov bx, 0  ; O
	 mov ax, word[es:164]
	 cmp ax, 0x0458
	 jne l242
	 call l201
	 l242:
	 cmp ax, 0x014F
	 jne l243
	 call l301
	 l243:
	 mov ax, word[es:484]
	 cmp ax, 0x0458
	 jne l244
	 call l201
	 l244:
	 cmp ax, 0x014F
	 jne l245
	 call l301
	 l245:
	 mov ax, word[es:804]
	 cmp ax, 0x0458
	 jne l246
	 call l201
	 l246:
	 cmp ax, 0x014F
	 jne l247
	 call l301
	 l247:
	 mov ax, word[es:1124]
	 cmp ax, 0x0458
	 jne l248
	 call l201
	 l248:
	 cmp ax, 0x014F
	 jne l249
	 call l301
	 l249:
	 cmp dx, 4
	 je do_exitX
	 cmp bx, 4
	 je do_exitO
	 
	 ; column 3
	 mov dx, 0  ; X
	 mov bx, 0  ; O
	 mov ax, word[es:168]
	 cmp ax, 0x0458
	 jne l250
	 call l201
	 l250:
	 cmp ax, 0x014F
	 jne l251
	 call l301
	 l251:
	 mov ax, word[es:488]
	 cmp ax, 0x0458
	 jne l252
	 call l201
	 l252:
	 cmp ax, 0x014F
	 jne l253
	 call l301
	 l253:
	 mov ax, word[es:808]
	 cmp ax, 0x0458
	 jne l254
	 call l201
	 l254:
	 cmp ax, 0x014F
	 jne l255
	 call l301
	 l255:
	 mov ax, word[es:1128]
	 cmp ax, 0x0458
	 jne l256
	 call l201
	 l256:
	 cmp ax, 0x014F
	 jne l257
	 call l301
	 l257:
	 cmp dx, 4
	 je do_exitX
	 cmp bx, 4
	 je do_exitO
	 
	 ; column 4
	 mov dx, 0  ; X
	 mov bx, 0  ; O
	 mov ax, word[es:172]
	 cmp ax, 0x0458
	 jne l258
	 call l201
	 l258:
	 cmp ax, 0x014F
	 jne l259
	 call l301
	 l259:
	 mov ax, word[es:492]
	 cmp ax, 0x0458
	 jne l260
	 call l201
	 l260:
	 cmp ax, 0x014F
	 jne l261
	 call l301
	 l261:
	 mov ax, word[es:812]
	 cmp ax, 0x0458
	 jne l262
	 call l201
	 l262:
	 cmp ax, 0x014F
	 jne l263
	 call l301
	 l263:
	 mov ax, word[es:1132]
	 cmp ax, 0x0458
	 jne l264
	 call l201
	 l264:
	 cmp ax, 0x014F
	 jne l265
	 call l301
	 l265:
	 cmp dx, 4
	 je do_exitX
	 cmp bx, 4
	 je do_exitO
	 
	 ; diagonal 1
	 mov dx, 0  ; X
	 mov bx, 0  ; O
	 mov ax, word[es:160]
	 cmp ax, 0x0458
	 jne l266
	 call l201
	 l266:
	 cmp ax, 0x014F
	 jne l267
	 call l301
	 l267:
	 mov ax, word[es:484]
	 cmp ax, 0x0458
	 jne l268
	 call l201
	 l268:
	 cmp ax, 0x014F
	 jne l269
	 call l301
	 l269:
	 mov ax, word[es:808]
	 cmp ax, 0x0458
	 jne l270
	 call l201
	 l270:
	 cmp ax, 0x014F
	 jne l271
	 call l301
	 l271:
	 mov ax, word[es:1132]
	 cmp ax, 0x0458
	 jne l272
	 call l201
	 l272:
	 cmp ax, 0x014F
	 jne l273
	 call l301
	 l273:
	 cmp dx, 4
	 je do_exitX
	 cmp bx, 4
	 je do_exitO
	 
	 ; diagonal 2
	 mov dx, 0  ; X
	 mov bx, 0  ; O
	 mov ax, word[es:172]
	 cmp ax, 0x0458
	 jne l274
	 call l201
	 l274:
	 cmp ax, 0x014F
	 jne l275
	 call l301
	 l275:
	 mov ax, word[es:488]
	 cmp ax, 0x0458
	 jne l276
	 call l201
	 l276:
	 cmp ax, 0x014F
	 jne l277
	 call l301
	 l277:
	 mov ax, word[es:804]
	 cmp ax, 0x0458
	 jne l278
	 call l201
	 l278:
	 cmp ax, 0x014F
	 jne l279
	 call l301
	 l279:
	 mov ax, word[es:1120]
	 cmp ax, 0x0458
	 jne l280
	 call l201
	 l280:
	 cmp ax, 0x014F
	 jne l281
	 call l301
	 l281:
	 cmp dx, 4
	 je do_exitX
	 cmp bx, 4
	 je do_exitO
	 
	 clc          ; clear carry flag to 0
	 mov bx, cx   ; copy cx value to bx
	 shr bx, 1    ; divide bx value by 2
	 jc l200      ; if it is a odd number then jump to l200
	 jmp l700     ; if it is a even number then jump to l700
 
l201:
	add dx, 1 ; increment dx by 1
	ret
l301: 
	add bx, 1 ; increment bx by 1
	ret
