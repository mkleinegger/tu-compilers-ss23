	.file	"amsb.c"
	.text
	.globl	asmb
	.type	asmb, @function
asmb:
.LFB0:
	.cfi_startproc
	# create mask for working with n bytes
	movq %rdi, %rdx
	movq $-1, %r9 # register to save 0xffffffffffffffff
	movq $0, %r10 # counter for 64 bytes jump

	mov $0x61616161, %r11d        # set r9d (lower 32bits) to the comparison value 'a'
	vpbroadcastd %r11d, %zmm1     # broadcast r9d to all bytes of zmm1

	mov $0x7A7A7A7A, %r11d        # set r9d (lower 32bits) to the comparison value 'z'
	vpbroadcastd %r11d, %zmm2     # broadcast r9d to all bytes of zmm2

	mov $0x20202020, %r11d        # set r9d (lower 32bits) to the substraction value 'A'-'a'
	vpbroadcastd %r11d, %zmm3     # broadcast r9d to all bytes of zmm3
.LOOP:
	movq $0, %r8 	    # set r8 to 0
	test %rsi, %rsi     # test for rsi & rsi, that we can check if rsi = 0 for cmovCC
	cmovnz %r9, %r8     # set r8 to 0xffffffffffffffff if rsi <> 0
	
	cmp $64, %rsi	    # rsi - 64 to check if rsi >= 64
	jge .UPPERCASE	    # if rsi >= 64 then skip building mask for n < 64
	
	movq $64, %rcx      # set rcx to 64
	subq %rsi, %rcx     # subtract n from 64
	shrq %rcx, %r8      # shift right r8 by rcx bits
.UPPERCASE:
	kmovq %r8, %k1      # move r8 to k

	vmovdqu8 (%rdx), %zmm0{%k1} # move the specified bytes from rdi to simd register

	vpcmpnltb %zmm1, %zmm0, %k2{%k1}  # compare each byte of zmm0 with the corresponding byte of zmm1, and set k2 mask to 1 if byte in zmm0 is greater or equal than byte in zmm1
	vpcmpleb %zmm2, %zmm0, %k3{%k2}   # compare each byte of zmm0 with the corresponding byte of zmm2, and set k3 mask to 1 if byte in zmm0 is less or equal than byte in zmm2
	
	vpsubb %zmm3, %zmm0, %zmm0{%k3}   # substract 'A'-'a' from all lowercase letters (masked through k3)
	
	vmovdqu8 %zmm0, (%rdx){%k1}  # move the manipulated bytes back to original memory
   	
	add $64, %rdx  # increase rdx by 64 bytes
	add $64, %r10  # increase r10 by 64 bytes
    	sub $64, %rsi  # decrease rsi (n) by 64 bytes

	cmp $0, %rsi  # rsi - 0 to check if rsi > 0
    	jg .LOOP      # if rs > 0 then jump to LOOP and redo toUppercase for rest of string
	
	movq %rdi, %rax  # set the return pointer to the memory address from s

	ret
	.cfi_endproc
.LFE0:
	.size	asmb, .-asmb
	.ident	"GCC: (Debian 10.2.1-6) 10.2.1 20210110"
	.section	.note.GNU-stack,"",@progbits

