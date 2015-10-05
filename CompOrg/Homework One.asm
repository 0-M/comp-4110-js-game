# Author: Zachary Krausman
# Description: This program will accept two positive integers from the keyboard and display the product of those numbers
# Date: 9/20/15 


.data #data segment
first_Integer: .asciiz "Please enter an integer: "
second_Integer: .asciiz "Please enter another integer: "
result: .asciiz "The product of the entered numbers is: "

.text #assembly instructions

main: 
	li $v0,4 #system call code for printing a string is 4
	la $a0,first_Integer #load address of string to be printed in $a0'
	syscall
	
	li $v0,5 #system call code for reading an integer is 5, integer is read into $v0
	syscall
	
	move $t0,$v0 #set $a0 to be equal to the contents of $v0 -- first integer
	
	li $v0,4 #system call code for printing a string is 4
	la $a0,second_Integer #load address of string to be printed in $a0'
	syscall
	
	li $v0,5 #system call code for reading an integer is 5, integer is read into $v0
	syscall
	
	mulo $t0,$t0,$v0 #put the product of $t0 and $v0 into $t0
	
	li $v0,4 #system call code for printing a string is 4
	la $a0,result #load address of string to be printed in $a0'
	syscall
	
	move $a0,$t0 #set the contents of $a0 to $t0, so that the product
	
	li $v0,1 #system call code for printing an integer is 1
	la $t0,result #load address of integer to be printed in $a0'
	syscall
	
	li $v0, 10 # system call code for ending the program
	syscall
	
	