.data
Tabchar:	.word ' ', 5 
	  	.word '#', 6  
	 	.word '(', 4  
	 	.word ')', 4  
	 	.word '*', 3  
	 	.word '+', 3  
	 	.word ',', 4  
	 	.word '-', 3  
	 	.word '.', 4  
	 	.word '/', 3  
	 	.word '0', 1 
	 	.word '1', 1  
	 	.word '2', 1  
	 	.word '3', 1  
	 	.word '4', 1  
	 	.word '5', 1  
	 	.word '6', 1  
	 	.word '7', 1  
	 	.word '8', 1  
	 	.word '9', 1  
	 	.word ':', 4  
	 	.word 'A', 2 
 		.word 'B', 2   	
 		.word 'C', 2   	
 		.word 'D', 2  
 	 	.word 'E', 2   
 	 	.word 'F', 2  
 	  	.word 'G', 2   
 	  	.word 'H', 2  
 		.word 'I', 2   
 		.word 'J', 2  
 	 	.word 'K', 2  
 	 	.word 'L', 2  
	 	.word 'M', 2  
 		.word 'N', 2  
 	 	.word 'O', 2  
 	  	.word 'P', 2 
 	    	.word 'Q', 2  
 	     	.word 'R', 2   
 	     	.word 'S', 2  
 	      	.word 'T', 2   
 	      	.word 'U', 2 
 	       	.word 'V', 2  
	 	.word 'W', 2  
	 	.word 'X', 2  
 		.word 'Y', 2 
 	 	.word 'Z', 2 
 		.word 'a', 2 
 		.word 'b', 2  
 		.word 'c', 2 
 	  	.word 'd', 2 
 	    	.word 'e', 2  
 		.word 'f', 2   
 		.word 'g', 2   
 		.word 'h', 2  
 		.word 'i', 2   
 		.word 'j', 2  
 	 	.word 'k', 2 
	 	.word 'l', 2  
	 	.word 'm', 2  
	 	.word 'n', 2  
	 	.word 'o', 2  
	 	.word 'p', 2  
 		.word 'q', 2  
 	 	.word 'r', 2   
 	 	.word 's', 2   
 	 	.word 't', 2  
 	  	.word 'u', 2 
 		.word 'v', 2  
 		.word 'w', 2  
	 	.word 'x', 2  
	 	.word 'y', 2 
	 	.word 'z', 2 
inBuf: .space 80 # Reserved space for the maximum amount of characters that can be entered in a single line 
convertedLine: .space 80 #Reserved space for the maximum amount of characters that can be entered in a single line
st_prompt: .asciiz "\nEnter a new input line. \n" 
please: .asciiz "Collected line: "
please2: .asciiz "Converted line: "
line: .asciiz ""
convert: .ascii " 1234 6"

.text

main: 
jal getlineLoop
li $v0, 10 # ends the program
syscall


getlineLoop: #loop for getting new lines
move $s1,$ra
jal  getline
move $ra,$s1
move $t1,$v0
lb $t0,($s0) #load first character into $t0
beq $t0,35,exit #move to exit if char is #
la $a0, please # 2
li $v0, 4
syscall
la $a0,($s0)  # 3 print read line
li $v0, 4
syscall
la $a0,line
li $v0,4
syscall
la $a0,convertedLine #address of space for transformed line
la $a1,($s0) #address of input string
jal echoPrint #jump to transforming the string stored in $s0
j getlineLoop #loop


exit:
jr $ra


getline:
la $a0, st_prompt # Prompt to enter a new line
li $v0, 4
syscall
la $a0, inBuf # read a new line
li $a1, 80
li $v0, 8
syscall
move $s0,$a0 # store read line
jr $ra


echoPrint: # will feed characters to linear search one by one and assemble the tranformed string will be passed 
lb $a3,($a1) #load a character into $a3 -- to be passed to linear search
la $a2,Tabchar #address of array to search through 
move $s2,$ra
jal linearSearch
move $ra,$s2
beq $a3,35,echoPrintExit #if the character is a # then the line is done
addi $a0,$a0,1 #shift $a0 to be the address of the next element
addi $a1,$a1,1 #shift $a1 to be the address of the next element
j echoPrint


echoPrintExit:
la $a0,please2
li $v0,4
syscall
la $a0,convertedLine
li $v0,4
syscall
la $a0,line
li $v0,4
syscall
jr $ra

linearSearch: #character to be compared is in $a3
lw $t0,0($a2) #load the array elemnt you want to compare into $t0
beq $t0,$a3,linearSearchExit #if the elements are the same
addi $a2,$a2,8 #move to the next character to be compared
j linearSearch

 
linearSearchExit:
#li $v0,1
#li $a0, 17
#syscall
#lw $a0,4($a2)
#li $v0,1
#syscall

lw $t0,4($a2) # the number I need to add to string
la $t1,convert
add $t1,$t1,$t0
lb $t2,0($t1)
sb $t2,($a0)
#li $v0,11
#syscall


jr $ra
