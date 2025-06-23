[org 0x0100]

jmp start

	array: dw 6,7,3,9,100,5,1,50      ; array
	length: dw 8                      ; length of array
	max: dw 0                         ; memory variable to store max number
	min: dw 0                         ; memory variable to store min number
	median: dw 0                      ; memory variable to store median number
	
bubblesort:

	push bp
	mov bp, sp
	sub sp, 2                         ; make 2 byte space on stack for swap flag
	push ax                           ; pushing registers
	push bx
	push cx
	push si

	mov bx, [bp+6]                    ; array
	mov cx, [bp+4]                    ; length of array
	dec cx                            ; last element not compared
	shl cx, 1                         ; turn into byte count

mainloop:

	mov si, 0                         ; initalize array index to 0
	mov word[bp-2], 0                 ; reset swap flag to no swaps

innerloop:

	mov ax, [bx+si]                   ; load number in ax
	cmp ax, [bx+si+2]                 ; compare with next number
	jbe noswap                        ; no swap if already in order

	xchg ax, [bx+si+2]                ; exchange ax with second

	mov [bx+si], ax                   ; store second number in first
	mov word[bp-2], 1                 ; flag that a swap has been done

noswap:

	add si, 2                         ; advance si to next index
	cmp si, cx                        ; are we at last index
	jne innerloop                     ; if not compare next too

	cmp word[bp-2], 1                 ; check if a swap has been done
	je mainloop 	                  ; if yes make another pass

	pop si                            ; popping registers
	pop cx
	pop bx
	pop ax
	mov sp, bp                        ; remove space created on stack for swap flag
	pop bp
	ret 4

statsOfArray:

	push bp                             ; pushing registers
	mov bp, sp
	push ax
	push bx
	push cx
	push si

	mov ax, [bp+6]                     
	push ax                             ; place start of array on stack
	mov ax, [bp+4]
	push ax                             ; place element count on stack

	call bubblesort                     ; call sub-routine

	mov bx, [bp+6]                      ; place array in bx
	mov si, [bp+4]                      ; place length of array in si
	shl si, 1                           ; turn si into byte count
	sub si, 2                           ; point si to last element in array

	mov ax, [bx+0]                      ; move first element which is min in ax
	mov cx, [bx+si]                     ; move last element which is max in cx
	mov [min], ax                       ; store min number in memory
	mov [max], cx                       ; store max number in memory
 	
	clc                                 ; clear carry flag
	mov ax, [bp+4]                      ; place length of array in ax
	shr ax, 1                           ; divide ax by 2 to see length is even or odd
	jc odd1                             ; jump if carry if number is odd to odd1
	jmp even1                           ; jump if even to even1

	odd1: 
	mov ax, [bp+4]                      ; place length of array in ax
	sub ax, 1                           ; subtract 1 from ax
	mov si, ax                          ; store ax value in si
	mov cx, [bx+si]                     ; move median in cx
	jmp med                             ; jump to median
 
	even1: mov ax, [bp+4]               ; place length of array in ax
	mov si, ax                          ; store ax value in si
	mov cx, [bx+si]                     ; move median + 2 value in cx
	sub si, 2                           ; subtract 2 from si to point to previous value
	mov dx, [bx+si]                     ; move median - 2 value in dx
	add cx, dx                          ; median -2 + median + 2
	shr cx, 1                           ; divide answer by 2  
	jmp med                             ; jump to median

 
	med: mov [median], cx               ; store median value in memory

	
	pop si                              ; popping registers
	pop cx
	pop bx
	pop ax
	pop bp
	ret 4
	
start:

	mov ax, array
	push ax                    ; place start of array on stack
	mov ax, [length]
	push ax                    ; place element count on stack

	call statsOfArray          ; call sub-routine

end: 

	mov ax, [min]              ; storing min number in ax
	mov bx, [max]              ; storing max number in bx
	mov cx, [median]           ; storing median number in cx

	mov ax, 0x4c00             ; terminating program
	int 0x21 
