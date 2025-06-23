[org 0x0100]

jmp start

	array: dw 1,1,1,0,1,1,1,1,0,0,0,0,1,0,1,0  ; array to search from
	search: dw 1,1,1,1,0,0                     ; searching array
	n: dw 6                                    ; counter for search value   
	startingindex: db 0                        ; variable to store starting index of array that is searched
	c1: dw 0                                   ; temporary memory space to store result

result1:

	push ax             ; pushing ax to save value  
	mov ax, [c1]        ; moving value from memory to ax 
	add ax ,1           ; incrementing c1
	mov [c1], ax        ; moving value from ax to memory
	pop ax              ; popping ax to restore value
	jmp l2

FindingSearchValue:

	push bp             
	mov bp, sp
	push ax             ; pushing registers
	push bx
	push cx
	push dx
	push si
	push di

	mov bx, [bp+6]  ; searching array
	mov ax, [bp+8]  ; array to search from
	mov cx, [bp+4]  ; counter for search value   
	shl cx, 1       ; multiplying cx by 2 to convert to word
	mov di, 0       ; counter for array to search from
	mov si, 0       ; counter for searching array

l1:
	mov bx, [bp+8]      ; pointing bx to array to search from
	mov dx, [bx+di]     ; array to search from
	mov bx, [bp+6]      ; pointing bx to searching array
	mov cx, [bx+si]     ; searching array

	cmp cx, dx          ; comparing values of both arrays
	jz result1          ; jumping if result is 0 to result1

l2:

	add di, 2         ; increnting to point to next value of array to search from
	add si, 2         ; increnting to point to next value of searching array
	push ax           ; storing ax value
	mov ax, [bp+4]    ; moving counter for search value in ax
	shl ax, 1         ; multiplying ax by 2 to turn to word
	cmp si, ax        ; comparing with length of searching array
	pop ax            ; retrieving ax value
	jnz l1            ; jumping if not 0 to start of searching again with di incremented so to point to next bit of array to search from

	push ax           ; storing ax value
	mov ax, [c1]      ; seeing if value is same 6 times
	push bx           ; storing bx value
	mov bx, [bp+4]    ; moving counter for search value in bx
	cmp ax, bx        ; comparing if value of c1 and bx
	pop bx            ; retrieving bx value
	jz end            ; if same value than pattern is present in array and end program
	mov ax, 0         ; storing 0 in ax
	mov [c1], ax      ; storing 0 in c1
	pop ax            ; retrieving ax value

	push ax           ; storing ax value
	mov ax, [bp+4]    ; moving counter for search value in ax
	shl ax, 1         ; multiplying ax value by 2 to turn into word
	sub ax, 2         ; subtracting ax by 2
	sub di, ax        ; decrementing di by 10 to point to new value of di
	pop ax            ; retrieving ax value
	mov si, 0         ; storing 0 in si
	cmp di, 32        ; comparing di with length of pattern 
	jz end1           ; jump if 0 to end of program as pattern not found
	jmp l1            ; jump back to searching again


start:

	mov ax, array                     ; pushing array to search from into ax
	push ax                           ; pushing array to search from into stack
	mov ax, search                    ; pushing searching array into ax
	push ax                           ; pushing searching array into stack
	mov ax, [n]                       ; pushing counter for search value into ax
	push ax                           ; pushing counter for search value into stack

	call FindingSearchValue           ; calling sub-routine

end:
	push ax                           ; pushing ax to save value  
	mov ax, [n]                       ; moving value from memory to ax 
	shl ax, 1                         ; multiplying ax by 2
	sub di, ax                        ; calculating index of searched pattern
	pop ax                            ; popping ax to restore value
	shr di, 1                         ; dividing di value by 2 to convert to byte 
	mov [startingindex], di           ; putting index in memory
	jmp end3                          ; jumping to end of program

end1:

	mov di, -1                        ; moving -1 if pattern not found
	mov [startingindex], di           ; putting index in memory
	jmp end3                          ; jumping to end of program

end3:

	pop di                            ; popping registers
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	pop bp

	
	mov ax, [startingindex]           ; moving index into ax for display

	mov ax, 0x4c00                    ; terminating program
	int 0x21 