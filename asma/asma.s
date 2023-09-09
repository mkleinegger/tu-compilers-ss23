	.file	"asma.c"
	.text
	.globl	asma
	.type	asma, @function
asma:
.LFB0:
	.cfi_startproc
	# create mask for working with n bytes
	movq $64, %rcx      # set rcx to 64
	subq %rsi, %rcx     # subtract n from 64
	movq $-1, %r8       # set r8 to 0xffffffffffffffff
	shrq %rcx, %r8      # shift right r8 by rcx bits
	kmovq %r8, %k1      # move r8 to k
	
	vmovdqu8 (%rdi), %zmm0{%k1} # move the specified bytes from rdi to simd register

	mov $0x61616161, %r9d        # set r9d (lower 32bits) to the comparison value 'a'
	vpbroadcastd %r9d, %zmm1     # broadcast r9d to all bytes of zmm1
	vpcmpnltb %zmm1, %zmm0, %k2  # compare each byte of zmm0 with the corresponding byte of zmm1, and set k2 mask to 1 if byte in zmm0 is greater or equal than byte in zmm1
	
	mov $0x7A7A7A7A, %r9d        # set r9d (lower 32bits) to the comparison value 'z'
	vpbroadcastd %r9d, %zmm2     # broadcast r9d to all bytes of zmm2
	vpcmpleb %zmm2, %zmm0, %k3   # compare each byte of zmm0 with the corresponding byte of zmm2, and set k3 mask to 1 if byte in zmm0 is less or equal than byte in zmm2

	kandq %k2, %k3, %k4  # (k2 and k3) = get all bytes that are a lowercase-letter
	kandq %k1, %k4, %k4  # mark all bits till n
	
	mov $0x20202020, %r9d        # set r9d (lower 32bits) to the comparison value 'z'
	vpbroadcastd %r9d, %zmm3     # broadcast r9d to all bytes of zmm3
	vpsubb %zmm3, %zmm0, %zmm0{%k4} # substract 'A'-'a' from all lowercase letters (masked through k4)
	
	vmovdqu8 %zmm0, (%rdi){%k1}  # move the manipulated bytes back to original memory
	movq %rdi, %rax              # set the return pointer to the memory address from s
	ret
	.cfi_endproc
.LFE0:
	.size	asma, .-asma
	.ident	"GCC: (Debian 10.2.1-6) 10.2.1 20210110"
	.section	.note.GNU-stack,"",@progbits
