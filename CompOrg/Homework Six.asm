		.data
inArr:		.word		0:60
symTab:		.word		0:80
prompt:		.asciiz		"Enter new set of tokens and types: \n\n"
LOC:		.word		0
saveReg: 	.word 0:3
test:           .asciiz "Made it here"
space: 		.ascii " "
line:		.asciiz "\n"
storeSpace: 	.byte ' '
DEFN0:		.byte '0'
DEFN1:		.byte '1'
DEFN:		.byte ' '
DDE:		.asciiz "Double Definition Error"


		.text
main:
		li		$t0,0x0400	# Initialize the Location Counter to x400
		sw		$t0, LOC
		li   		$s7,0 # Initialize symTab index
		li 		$s6,0 # Number of entries in symTab
		li		$s5,0 # print symTab
		#b 		inLoop
		
inLoop:		
		la 		$a0, prompt # print prompt
		li 		$v0, 4
		syscall	
		la		$a0, inArr
		jal		getTokens # get tokens
		
		
		li		$t0, 0		# index to inArr
		
		lb $t3,inArr($t0)
		beq $t3,35,exit # if the first character is a '#' exit the program
		
		# if the NEXT Token is a ':' then the current Token is a label
		# Since the current Token takes 12 bytes, look ahead 12 bytes and see if it's a ':'
		lb		$s0, inArr+12($t0)
		bne		$s0, ':', operator
		
		lb $a1,DEFN1 # DEFN = 1
		li $t1,'1'
		sb $t1,DEFN
		move $a0,$t0 # token is in offset $a0 to be passed to VARIABLE
		jal VARIABLE # DEFN is in $a1 -- token is in offset $a0
		
operator:
	addi $t0,$t0,12 # go to next token
	lb $a1,DEFN0 # DEFN = 0
	li $t1,'0'
	sb $t1,DEFN
	li $t1,1 # isComma = true
	
chkVar:
	lb $t8,inArr+8($t0)
	beq $t8,'6',dump #is next token is '#'
	bne $t8,'2',nextVar # if next token isn't letters
	beq $t1,0,nextVar # if isComma is not true
	move $a0,$t0
	move $a3,$ra
	jal VARIABLE # DEFN is in $a1 -- token is in offset $a0
	move $ra,$a3
nextVar:	
	lb $t8,inArr($t0)
	beq $t8,',',isComma
	li $t1,0 # isComma = false
	addi $t0,$t0,12 # go to next token
	b chkVar

isComma:
	li $t1,1 #isComma = true
	addi $t0,$t0,12 # go to next token
	b chkVar

dump:
	li $t0,0
	li $t1,0
	jal clearInArr
	li $t6,0
	li $a2,16
	mult $a2,$s6
	mflo $a2
	jal printSymTab
	lw $t8,LOC
	addi $t8,$t8,4
	sw $t8,LOC
	b inLoop	
exit:		
	li $v0, 10 # ends the program
	syscall

VARIABLE: # DEFN is in $a1 -- token is in offset $a0
move $s2,$ra # return address but will be changed when jumping to functions
#move $a2,$s6 # give number of entries in symbol table to look through
jal LOOKUP
move $ra,$s2
move $s2,$ra
jal symSTATUS
move $ra,$s2
bge $s3,6,return
la $s0, symACTS
sll $s3, $s3, 2 # Multiply the new status value by 4 to
add $s0, $s0, $s3 # properly index into the jump table
jr $s0

symACTS: 
b symACT0
b symACT1
b symACT2
b symACT3
b symACT4
b symACT5

symACT0: # This is a forward reference.
lw $v0,symTab+8($t9) # return the old value
lw $a0,LOC
move $a3,$ra
jal hex2char
move $ra,$a3
sw $v0,symTab+8($t9) # update the value
b return
symACT1: # A previously used TOKEN is defined for the first time.
lw $v0,symTab+8($t9) # return the old value
lw $a0,LOC
move $a3,$ra
jal hex2char
move $ra,$a3
sw $v0,symTab+8($t9) # update the value
b return

symACT2: # A previously defined TOKEN is used. 
la $v0,symTab # return the token (location of the token)
b return

symACT3: # A previously defined TOKEN is defined again. 
la $a0,DDE  # print out double definition error
li $v0,4 # return -1
syscall
b return

symACT4: # TOKEN seen for the first time as a forward reference. 
lw $a0,LOC
move $a3,$ra
jal hex2char
move $ra,$a3
sw $v0,symTab+8($t9) # update the value
b return

symACT5: # TOKEN seen for the first time as a definition.
lw $a0,LOC
move $a3,$ra
jal hex2char
move $ra,$a3
sw $v0,symTab+8($t9) # store LOC in the value
b return

return: # if necessary, do any remaining actions
jr $s2

symSTATUS:
#move $s4,$ra # save the return address
bgtz $v1,inSymTab # Token is already in symTab

# else this is the tokens first occurance
lb $t8,storeSpace
sb $t8,symTab+12($t9) # first byte is empty
lb $t8,DEFN1
sb $t8,symTab+13($t9) # first occurance = 1
lb $t8,DEFN0
sb $t8,symTab+14($t9) # Already defined = 0
sb $a1,symTab+15($t9) # DEFN

j retStatus

retStatus: #stores the status of the token which is in $t9 and returns it to $s3
lb $t5,symTab+13($t9) # First occurance
lb $t7,symTab+14($t9) # Already Defined
lb $t8,symTab+15($t9) # DEFN
sub $t5,$t5,48
sub $t7,$t7,48
sub $t8,$t8,48
li $t1,4
mult $t5,$t1
mflo $t5
li $t1,2
mult $t7,$t1
mflo $t7
li $t1,1
mult $t8,$t1
mflo $t8
add $t5,$t5,$t7
add $t5,$t5,$t8
move $s3,$t5
jr $ra

inSymTab: #v1 has oldStatus
#li $t9,16
#mult $s6,$t9
#mflo $t9
lb $t8,storeSpace
sb $t8,symTab+12($t9) # first byte is empty
move $t8,$v1 #t8 has a copy of oldStatus
and $t8,2
and $v1,1
sll $v1,$v1,1
or $v1,$v1,$t8
lb $t8,DEFN
sub $t8,$t8,48
or $v1,$t8,$v1
lb $t8,DEFN0
sb $t8,symTab+13($t9) # first occurance = 0
sb $t8,symTab+14($t9) # already defined = 0
sb $t8,symTab+15($t9) # DEFN = 0
#move $a3,$ra
bgt  $v1,3,setOccurance
#move $ra,$a3
bgt $v1,1,setDefined
bgt $v1,0,setDEFN



b retStatus

setOccurance:

lb $t8,DEFN1
sb $t8,symTab+13($t9) # first occurance = 1
subi $v1,$v1,4
bgt $v1,1,setDefined
bgt $v1,0,setDEFN
b retStatus

setDefined:
lb $t8,DEFN1
sb $t8,symTab+14($t9) # already defined = 1
subi $v1,$v1,2
bgt $v1,0,setDEFN
b retStatus

setDEFN:
lb $t8,DEFN1
sb $t8,symTab+15($t9) # DEFN = 1
subi $v1,$v1,1
b retStatus

LOOKUP: # looks for the token in the symbol table $a2 holds the number of entries in the symbol table
li $t4,0 # search counter
li $t9,-1 # return from lookup
move $s3,$ra #save return address
jal searchSymTab
move $ra,$s3

beq $t9,-1,NOTHINGFOUND # no matching token
bne $t9,-1,ENTRYFOUND	# matching token

NOTHINGFOUND:
li $t9,16
mult $s6,$t9
mflo $t9
lb $a2, storeSpace
lw $t8,inArr($a0) # First word of token
lw $t7,inArr+4($a0) # Second word of token
lw $a0,LOC
move $a3,$ra
jal hex2char
move $ra,$a3
sw $t8,symTab($t9)
sw $t7,symTab+4($t9)
sw $v0,symTab+8($t9)

#sb $a1,symTab+16($s7) #store DEFN
#sb $a2,symTab+15($s7) # Already defined 
#sb $a2,symTab+14($s7)
#sb $a2,symTab+13($s7)
#li $a2,0
#sw $a2,symTab+12($s7)
addi $s7,$s7,16
addi $s6,$s6,1
li  $v0,-1 # return -1 for oldVal
li $v1,-1 # return -1 for oldStatus
jr $ra

ENTRYFOUND:
lw $v0,symTab+8($t9) # oldVal
move $a3,$ra
jal retStatus
move $ra,$a3
move $v1,$s3
jr $ra

searchSymTab:
beq $t4,$s6,searchExit
lw $t5,inArr($a0) # first word of the token
li $t9,16
mult $t4,$t9
mflo $t9
lw $t7,symTab($t9) # first word in current symbol table token
li $t9,-1 #nothing was found
addi $t4,$t4,1 # move to next symbol table entry
bne $t5,$t7,searchSymTab #branch if the first words aren't equal
addi $t4,$t4,-1 # move back one entry

lw $t5,inArr+4($a0) # second word of the token
li $t9,16
mult $t4,$t9
mflo $t9
lw $t7,symTab+4($t9) # second word in current symbol table token
addi $t4,$t4,1 # move to next symbol table entry
li $t9,-1 #nothing was found
bne $t5,$t7,searchSymTab #branch if the second words aren't equal
addi $t4,$t4,-1 # move back one entry
li $t9,16
mult $t4,$t9
mflo $t9 # something was found return the offset of the token in the table
j searchExit

#addi $t4,$t4,1 # move to next symbol table entry
#j searchSymTab

searchExit:
jr $ra

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
# printSymTab
#
printSymTab:
bgt $t6,$a2,printExit
lb $a0,symTab($t6)
li $v0,11
syscall
addi $t6,$t6,1
b printSymTab

printExit:
li $a0,'\n'
li $v0,11
syscall
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
