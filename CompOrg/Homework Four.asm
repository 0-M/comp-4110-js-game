		.data
inArr:		.word		0:60
symTab:		.word		0:80
prompt:		.asciiz		"Enter new set of tokens and types: \n\n"
LOC:		.word		0
saveReg: 	.word 0:3
test:           .asciiz "Made it here"
space: 		.asciiz " "
line:		.asciiz "\n"
storeSpace: 	.byte ' '
DEFN0:		.byte '0'
DEFN1:		.byte '1'


		.text
main:
		li		$t0,0x0400	# Initialize the Location Counter to x400
		sw		$t0, LOC
		li   		$s7,0 # Initialize symTab index
		li 		$s6,0 # Number of entries in symTab
		li		$s5,0 # print symTab
		b 		inLoop
		
inLoop:		
		la 		$a0, prompt # print prompt
		li 		$v0, 4
		syscall	
		la		$a0, inArr
		jal		getTokens # get tokens
		
		
		li		$t9, 0		# DEFN
		li		$t0, 0		# index to inArr
		
		lb $t3,inArr($t0)
		beq $t3,35,exit # if the first character is a '#' exit the program
		
		# if the NEXT Token is a ':' then the current Token is a label
		# Since the current Token takes 12 bytes, look ahead 12 bytes and see if it's a ':'
		lb		$s0, inArr+12($t0)
		bne		$s0, ':', noVar
		
		jal		getLabel
		
		
chkVar:		bne		$s1,2610, noVar	#compare to type 2
		# found a variable
		# save the var and LOC into symTab
		addi		$t0, $t0, 12	# The current token is a ',' and the next token is the variable
		jal		getVar
			
		
noVar:		addi		$t0, $t0, 12		# go to next token
		lb		$s0, inArr($t0)
		lb		$t3,inArr($t0)
		beq 		$s0,'#',nextLine
		bne		$s0,',', noVar		# keep going until we get a ',' - variable might come next
		
		lw		$s1, inArr+20($t0)
		b		chkVar
		
nextLine:		
		#
		# Increase LOC by 4 for next line
		#
		lw $t4,LOC
		add $t4,$t4,4
		sw $t4,LOC
		move $t6,$s5
		li $a2,17
		mult $a2,$s6
		mflo $a2
		jal		printSymTab
		lb $a0,line
		li $v0,11
		syscall
		li $t0,0
		li $t1,0
		jal		clearInArr 
		
		b		inLoop
	
exit:		li $v0, 10 # ends the program
		syscall
			
#
# Save from keyboard to inArr table
# Get all the tokens and their types for a given line of assembly language
#	
getTokens:
li		$a1, 60
li		$v0, 8
syscall
lb $t1,($a0)
beq $t1,35,tokenExit
addi $a0,$a0,12
j getTokens

tokenExit:
jr $ra

#
# getLabel: Label is found, save it in symTab
#
getLabel:
#li $t9,1 # DEFN = 1
#la $t9,DEFN1
lb $t9, DEFN1
lb $a2, storeSpace
lw $t8,inArr($t0) # First word of token
lw $t7,inArr+4($t0) # Second word of token
lw $a0,LOC
jal hex2char
sw $t8,symTab($s7)
sw $t7,symTab+4($s7)
sw $v0,symTab+8($s7)
#sw $t9,symTab+12($s7)
sb $t9,symTab+12($s7)
sb $a2,symTab+13($s7)
sb $a2,symTab+14($s7)
sb $a2,symTab+15($s7)
addi $s7,$s7,16
addi $s6,$s6,1

b noVar


#
# getVar: Var is found, save it in symTab
#
getVar:
#li $t9,0 # DEFN = 0
#la $t9,DEFN0
lb $t9, DEFN0
lb $a2, storeSpace
lw $t8,inArr($t0)
lw $t7,inArr+4($t0)
lw $a0,LOC
jal hex2char
sw $t8,symTab($s7)
sw $t7,symTab+4($s7)
sw $v0,symTab+8($s7)
#sw $t9,symTab+12($s7)
sb $t9,symTab+12($s7)
sb $a2,symTab+13($s7)
sb $a2,symTab+14($s7)
sb $a2,symTab+15($s7)
addi $s7,$s7,16
addi $s6,$s6,1

b noVar
#
# printSymTab
#


printSymTab:
beq $t6,$a2,printExit
lb $a0,symTab($t6)
li $v0,11
syscall
addi $t6,$t6,1
b printSymTab
#printDefn:
#subi $t6,$t6,1
#lw $a0,symTab($t6)
#li $v0,1
#syscall
#addi $t6,$t6,4
#b printExit
printExit:
jr $ra

#
# clearInArr
#
clearInArr:
beq $t0,240,clearExit
sw $t1,inArr($t0)
addi $t0,$t0,4
j clearInArr

clearExit:
jr $ra

#
# hex2char:
# Convert a number in $a0 into char hex in $v0
#
# When you have '6b6a' in $a0,
# $v0 should have 'a''6''b''6'
#
# 4-bit mask slides from right to left in $a0.
# As corresponding char is collected into $v0,
# $a0 is shifted right by four bits for the next hex digit in the last four bits
#
#


hex2char:
# save registers
sw $t0, saveReg($0) # hex digit to process
sw $t1, saveReg+4($0) # 4-bit mask
sw $t9, saveReg+8($0)
# initialize registers
li $t1, 0x0000000f # $t1: mask of 4 bits
li $t9, 3 # $t9: counter limit

nibble2char:
and $t0, $a0, $t1 # $t0 = least significant 4 bits of $a0
# convert 4-bit number to hex char
bgt $t0, 9, hex_alpha # if ($t0 > 9) goto alpha
# hex char '0' to '9'
addi $t0, $t0, 0x30 # convert to hex digit
b collect

hex_alpha:
addi $t0, $t0, -10 # subtract hex # "A"
addi $t0, $t0, 0x61 # convert to hex char, a..f
# save converted hex char to $v0

collect:
sll $v0, $v0, 8 # make a room for a new hex char
or $v0, $v0, $t0 # collect the new hex char
# loop counter bookkeeping
srl $a0, $a0, 4 # right shift $a0 for the next digit
addi $t9, $t9, -1 # $t9--
bgez $t9, nibble2char
# restore registers
lw $t0, saveReg($0)
lw $t1, saveReg+4($0)
lw $t9, saveReg+8($0)
jr $ra
