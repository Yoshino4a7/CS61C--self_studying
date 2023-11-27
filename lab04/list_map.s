.globl map

.text
main:
    jal ra, create_default_list
    add s0, a0, x0  # $v0 = $s0 is head of node list

    #print the list
    add a0, s0, x0
    jal ra, print_list

    # print a newline
    jal ra, print_newline

    # load your args
    add a0, s0, x0  # load the address of the first node into $a0

    # load the address of the function in question into $a1 (check out la)
    ### YOUR CODE HERE ###
	la a1,square
    # issue the call to map
    jal ra, map

    # print the list
    add a0, s0, x0
    jal ra, print_list

    # print another newline
    jal ra, print_newline

    addi a0, x0, 10
    ecall #Terminate the program

map:
    # Prologue: Make space on the stack and back-up registers #在栈中临时存储map函数需要用到的局部资源
    ### YOUR CODE HERE ###
	addi sp, sp, -12  # 使栈指针偏移12个字节，4个字节为一个指针或一个结果的大小，需要3个指针，因此需要用到3块空间
    sw  ra, 0(sp)#返回结果
    sw  s0, 4(sp)#map函数需要用到的某一个list 的头节点指针（map的第一个参数）
    sw  s1, 8(sp)#备用寄存器，存储需要用到的square函数（map的第二个参数）
    beq a0, x0, done    # If we were given a null pointer (address 0), we're done.

    add s0, a0, x0  # Save address of this node in s0
    add s1, a1, x0  # Save address of function in s1

    # Remember that each node is 8 bytes long: 4 for the value followed by 4 for the pointer to next.
    # What does this tell you about how you access the value and how you access the pointer to next?

    # load the value of the current node into a0
    # THINK: why a0?
    ### YOUR CODE HERE ###
	lw a0,0(s0) #将s0指向的节点的value值加载到a0中，a0的值作为参数传递给square函数
    # Call the function in question on that value. DO NOT use a label (be prepared to answer why).
    # What function? Recall the parameters of "map"
    ### YOUR CODE HERE ###
	jalr s1 #jal通过label跳转，jalr通过寄存器中的地址跳转，s1是寄存器，不是label
	
	
    # store the returned value back into the node
    # Where can you assume the returned value is?
    ### YOUR CODE HERE ###
	sw a0,0(s0) #head->value=square(head->value);
	
    # Load the address of the next node into a0
    # The Address of the next node is an attribute of the current node.
    # Think about how structs are organized in memory.
    ### YOUR CODE HERE ###
	
	lw a0,4(s0) #将head->next作为下一次map的参数

    # Put the address of the function back into a1 to prepare for the recursion
    # THINK: why a1? What about a0?
    ### YOUR CODE HERE ###
	
	add a1, a1, x0 #将square函数的地址作为下一次map的第二个参数

    # recurse
    ### YOUR CODE HERE ###
	jal ra,map
	
done:
    # Epilogue: Restore register values and free space from the stack
    ### YOUR CODE HERE ###
	
    lw  ra, 0(sp)
    lw  s0, 4(sp)
    lw  s1, 8(sp)
	### 读取栈中三个结果，读取到对应的寄存器中 ###
	addi sp, sp, 12  # 使栈指针偏移12个字节（栈是向下延伸的，加法则是收回空间，减法是增加空间），收回栈的空间
	
    jr ra # Return to caller

square:
    mul a0 ,a0, a0
    jr ra

create_default_list:
    addi sp, sp, -12
    sw  ra, 0(sp)
    sw  s0, 4(sp)
    sw  s1, 8(sp)
    li  s0, 0       # pointer to the last node we handled
    li  s1, 0       # number of nodes handled
loop:   #do...
    li  a0, 8
    jal ra, malloc      # get memory for the next node
    sw  s1, 0(a0)   # node->value = i
    sw  s0, 4(a0)   # node->next = last
    add s0, a0, x0  # last = node
    addi    s1, s1, 1   # i++
    addi t0, x0, 10
    bne s1, t0, loop    # ... while i!= 10
    lw  ra, 0(sp)
    lw  s0, 4(sp)
    lw  s1, 8(sp)
    addi sp, sp, 12
    jr ra

print_list:
    bne a0, x0, printMeAndRecurse
    jr ra       # nothing to print
printMeAndRecurse:
    add t0, a0, x0  # t0 gets current node address
    lw  a1, 0(t0)   # a1 gets value in current node
    addi a0, x0, 1      # prepare for print integer ecall
    ecall
    addi    a1, x0, ' '     # a0 gets address of string containing space
    addi    a0, x0, 11      # prepare for print string syscall
    ecall
    lw  a0, 4(t0)   # a0 gets address of next node
    jal x0, print_list  # recurse. We don't have to use jal because we already have where we want to return to in ra

print_newline:
    addi    a1, x0, '\n' # Load in ascii code for newline
    addi    a0, x0, 11
    ecall
    jr  ra

malloc:
    addi    a1, a0, 0
    addi    a0, x0 9
    ecall
    jr  ra
