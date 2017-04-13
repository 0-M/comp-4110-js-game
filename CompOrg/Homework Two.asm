.data
     array1: .word 15,16,17,18,19
     array2: .word -7,32,52,465,-106,4,692,17,98
     sum1: .word 0
     sum2: .word 0

.text 
     main:
     	addi $a1, $zero, 5 # first arugment for sumArr -- length of array1
     	la $a2, array1 # second arugment for sumArr -- address of array1 
     	addi $t0, $zero,0 # index
     	addi $t1, $zero,0 #temporary sum
     	jal sumArr # execute the sumArr function
     	sw $t1,sum1
     	
     	addi $a1, $zero, 9 # first arugment for sumArr -- length of array1
     	la $a2, array2 # second arugment for sumArr -- address of array1 
     	addi $t0, $zero,0 # index
     	addi $t1, $zero,0 #temporary sum
     	jal sumArr # execute the sumArr function
     	sw $t1,sum2
     	
     
        li $v0, 10 # ends the program
        syscall
     
     sumArr: # while loop for looping through and adding values in an array
     	beq $t0,$a1,exit # exit condition for while loop -- when a1 = 5
     	addi $t0,$t0,1 # exit condition iteration
     	lw $t2,0($a2) # putting the current array value into $t2
     	addi $a2,$a2,4 # offsetting $a2 so next time around it will be the next value in the array
     	add  $t1,$t1,$t2 # sum
     	
     	
     	
     	j sumArr
     exit: 
       jr $ra