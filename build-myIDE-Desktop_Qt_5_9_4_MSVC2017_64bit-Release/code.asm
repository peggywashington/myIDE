.DATA  0x0000
.TEXT  0x0005
start:
             j main
      main : or $s8,$0,$sp
             addi $sp,$sp,52
             ori $s0,$0,0
             ori $s1,$0,0
             ori $s2,$0,0
             sw $s0,4($s8)
             sw $s1,12($s8)
             sw $s2,16($s8)
  SECTION3 : ori $s0,$0,1
             bne $s0,$0,SECTION5
             j END
  SECTION5 : lui $s0,0xFFFF
             addiu $s0,$s0,0xFC72
             lw $s1,0($s0)
             lui $s2,0xFFFF
             addiu $s2,$s2,0xFC70
             lw $s3,0($s2)
             andi $s4,$s3,65280
             ori $s6,$0,256
             div $s4,$s6
             mflo $s5
             lui $s6,0xFFFF
             addiu $s6,$s6,0xFC70
             lw $s7,0($s6)
             andi $s0,$s7,255
             sw $s0,16($s8)
             sw $s1,4($s8)
             sw $s5,12($s8)
             lw $s1,4($s8)
             ori $s2,$0,0
             beq $s1,$s2,SECTION16
             j SECTION19
 SECTION16 : lw $s0,16($s8)
             lw $s1,12($s8)
             add $s2,$s1,$s0
             lui $s3,0xFFFF
             addiu $s3,$s3,0xFC00
             sw $s2,0($s3)
             sw $s2,36($s8)
             j END
 SECTION19 : lw $s1,4($s8)
             ori $s2,$0,1
             beq $s1,$s2,SECTION21
             j SECTION31
 SECTION21 : lw $s0,16($s8)
             lw $s1,12($s8)
             sub $s2,$s1,$s0
             sw $s2,20($s8)
             lw $s1,20($s8)
             ori $s2,$0,0
             slt $s0,$s2,$s1
             beq $s0,$0,SECTION25
             j SECTION29
 SECTION25 : lw $s0,20($s8)
             ori $s2,$0,0
             sub $s1,$s2,$s0
             lui $s2,0xFFFF
             addiu $s2,$s2,0xFC00
             sw $s1,0($s2)
             lui $s3,0xFFFF
             addiu $s3,$s3,0xFC02
             ori $s4,$0,15
             sw $s4,0($s3)
             sw $s1,44($s8)
             j END
 SECTION29 : lui $s0,0xFFFF
             addiu $s0,$s0,0xFC00
             lw $s1,20($s8)
             sw $s1,0($s0)
             j END
 SECTION31 : lw $s1,4($s8)
             ori $s2,$0,2
             beq $s1,$s2,SECTION33
             j SECTION37
 SECTION33 : lw $s0,16($s8)
             lw $s1,12($s8)
             mult $s1,$s0
             mflo $s2
             lui $s3,0xFFFF
             addiu $s3,$s3,0xFC00
             sw $s2,0($s3)
             sw $s2,20($s8)
             j END
 SECTION37 : lw $s0,16($s8)
             lw $s1,12($s8)
             div $s1,$s0
             mflo $s2
             lui $s3,0xFFFF
             addiu $s3,$s3,0xFC00
             sw $s2,0($s3)
             sw $s2,20($s8)
             j SECTION3
       END : j END
