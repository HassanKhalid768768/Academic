[org 0x0100]

jmp start

	num1: dw 2            ; num 1 value is 2
	num2: dw 4            ; num 2 value is 4
	num3: dw 6            ; num 3 value is 6
	num4: dw 8            ; num 4 value is 8
	result1: dw 0         ; creating a space in memory to store num1 + num2
	result2: dw 0         ; creating a space in memory to store (num1 + num2) + (num1 + num3)
	result3: dw 0         ; creating a space in memory to store (num1 + num2) + (num1 + num4)
	
Function:

	push bp               
	mov bp, sp              
	sub sp, 10            ; creating space for 5 local variables
	push ax               ; pushing registers 
	push bx
	push cx
	push si
	push di

	mov ax, [bp+10]       ; num1
	mov bx, [bp+8]        ; num2
	add ax, bx            ; num1 + num2
	mov [bp-2], ax        ; storing (num1 + num2) in local variable 1

	mov ax, [bp+10]       ; num1
	mov bx, [bp+6]        ; num3
	add ax, bx            ; num1 + num3
	mov [bp-4], ax        ; storing (num1 + num3) in local variable 2

	mov ax, [bp+10]       ; num1
	mov bx, [bp+4]        ; num4
	add ax, bx            ; num1 + num4
	mov [bp-6], ax        ; storing (num1 + num4) in local variable 3

	mov ax, [bp-2]        ; num1 + num2
	mov bx, [bp-4]        ; num1 + num3
	add ax, bx            ; (num1 + num2) + (num1 + num3)
	mov [bp-8], ax        ; storing (num1 + num2) + (num1 + num3) in local variable 4

	mov ax, [bp-2]        ; num1 + num2
	mov bx, [bp-6]        ; num1 + num4
	add ax, bx            ; (num1 + num2) + (num1 + num4)
	mov [bp-10], ax       ; storing (num1 + num2) + (num1 + num4) in local variable 5

	mov ax, [bp-2]        ; moving num1 + num2 to ax
	mov [result1], ax     ; moving ax to memory

	mov bx, [bp-8]        ; moving (num1 + num2) + (num1 + num3) to bx
	mov [result2], bx     ; moving bx to memory

	mov cx, [bp-10]       ; moving (num1 + num2) + (num1 + num4) to cx
	mov [result3], cx     ; moving cx to memory

	pop di                ; popping registers
	pop si
	pop cx
	pop bx
	pop ax
	mov sp, bp            
	pop bp
	ret 8

start:

	mov ax, [num1]        ; moving num1 to ax
	push ax               ; pushing ax
	mov ax, [num2]        ; moving num2 to ax
	push ax               ; pushing ax
	mov ax, [num3]        ; moving num3 to ax
	push ax               ; pushing ax
	mov ax, [num4]        ; moving num4 to ax
	push ax               ; pushing ax

	call Function         ; calling sub-routine

	mov ax, [result1]     ; moving num1 + num2 from memory to ax
	mov bx, [result2]     ; moving (num1 + num2) + (num1 + num3) to bx
	mov cx, [result3]     ; moving (num1 + num2) + (num1 + num4) to cx

end: 

	mov ax, 0x4c00        ; terminating program
	int 0x21 
