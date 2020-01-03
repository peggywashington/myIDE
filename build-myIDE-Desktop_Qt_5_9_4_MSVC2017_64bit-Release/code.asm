.DATA  0x0000
.TEXT  0x0004
start:
             j main
     delay : sw $ra,0($sp)
             addi $sp,$sp,4
             sw $s8,0($sp)
             addi $sp,$sp,4
             sw $s0,0($sp)
             addi $sp,$sp,4
             sw $s1,0($sp)
             addi $sp,$sp,4
             sw $s2,0($sp)
             addi $sp,$sp,4
             sw $s3,0($sp)
             addi $sp,$sp,4
             sw $s4,0($sp)
             addi $sp,$sp,4
             sw $s5,0($sp)
             addi $sp,$sp,4
             sw $s6,0($sp)
             addi $sp,$sp,4
             sw $s7,0($sp)
             addi $sp,$sp,4
             or $s8,$0,$sp
             addi $sp,$sp,8
             ori $s0,$0,30000
             sw $s0,4($s8)
  SECTION1 : lw $s1,4($s8)
             ori $s2,$0,0
             slt $s0,$s2,$s1
             bne $s0,$0,SECTION3
             j END
  SECTION3 : lw $s0,4($s8)
             ori $s2,$0,1
             sub $s1,$s0,$s2
             sw $s1,4($s8)
             j SECTION1
      main : or $s8,$0,$sp
             addi $sp,$sp,14
             ori $s0,$0,0
             addi $s1,$s0,1
             lui $s2,0xffff
             addiu $s2,$s2,0xfc60
             sw $s1,0($s2)
             lui $s3,0xffff
             addiu $s3,$s3,0xfc62
             sw $s1,0($s3)
             sw $s1,4($s8)
             lw $s1,4($s8)
             ori $s2,$0,10
             slt $s0,$s2,$s1
             bne $s0,$0,SECTION13
             j SECTION14
 SECTION13 : ori $s0,$0,0
             sw $s0,4($s8)
 SECTION14 : jal delay
             sw $v0,14($s8)
  DEADLOOP : j DEADLOOP
