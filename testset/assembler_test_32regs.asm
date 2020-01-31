.data  0x0000
   buf:   .word  0x00000055, 0x000000AA
.text 0x0000
start:  
		ori $at,$zero,1
		ori $v0,$zero,2
		ori $v1,$zero,3
		ori $a0,$zero,4
		ori $a1,$zero,5
		ori $a2,$zero,6
		ori $a3,$zero,7
		ori $t0,$zero,8
		ori $t1,$zero,9
		ori $t2,$zero,10
		ori $t3,$zero,11
		ori $t4,$zero,12
		ori $t5,$zero,13
		ori $t6,$zero,14
		ori $t7,$zero,15
		ori $s0,$zero,16
		ori $s1,$zero,17
		ori $s2,$zero,18
		ori $s3,$zero,19
		ori $s4,$zero,20
		ori $s5,$zero,21
		ori $s6,$zero,22
		ori $s7,$zero,23
		ori $t8,$zero,24
		ori $t9,$zero,25
		ori $26,$zero,26
		ori $27,$zero,27
		ori $28,$zero,28
		ori $sp,$zero,29
		ori $s8,$zero,30
		ori $ra,$zero,31
		ori $v0,$zero,0x55       		# lw $v0,buf($zero) 
		ori $a0,$zero,4
		ori $a1,$zero,5
		lw $v1,buf($a0)			# buf+4
		add $1,$v0,$v1
		sw $1,8($zero)
		subu $a0,$v1,$v0
		slt $a0,$v0,$1
		and $1,$v1,$a3
		or $a2,$v0,$1
		xor $a3,$v0,$v1
		nor $a2,$a1,$1
lop:		beq $v1,$v0,lop
lop1:	sub $v0,$v0,$a1
		bne $a1,$v0,lop1
		beq $1,$1,lop2
		nop 
lop2:	jal subp
		j next
subp:	jr $ra 
next:	addi $v0,$zero,0x99
		ori $v1,$zero,0x77
		sll $v1,$v0,4 
		srl $v1,$v0,4 
		srlv $v1,$v0,$1
		lui $a2,0x9988
		sra $a3,$a2,4
		addi $v0,$zero,0
		addi $v1,$zero,2
		sub  $1,$v0,$v1
		j	 start

