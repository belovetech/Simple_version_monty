 gcc -Wall -Werror -Wextra -pedantic *.c -o monty
 

<!--
STEPS
----------------------
main function
----------------------
1. Check if argc != 2 ?  print to stderr 
2. Take the second argv and open it and read
3. if unable to read file print error
4. run monty on the file
5. close file
6. exit

----------------------
monty function
----------------------
stack = NULL, unsigned int line_number = 0, *line = NULL, 
size_t len = 0
1. accept bytecodes file
2. get each line instruction -> tokenize the instruction
3. create stack
4. if not successful return Exit code
5. get the line
 - use getline function
 - while (getline(lineptr, &len, bytecode) != EOF)
   - increment line_number
   - tokenize the line
   - if not not successful do something
   - else if the first [0][0]tokenization is #
      free the token then continue
   - pass the first index -> the opcode to the function
   - if it's NULL free stack, return error, free token and break
   - call the opcode function with stack and line number
   - if token array length
   - free token
6. free stack
7. free line return error
 
----------------------
create stack function
----------------------
1. accept address of the stack
2. allocate memeory
3. assign value -> STACK
4. set prev and next to NULL
5. derefernce the stack address to point to new stack created
6. free ->

----------------------
free stack function
----------------------
1. accept address of the stack
2. initialiaze temp stack
3. loop
  - store the next of stack to temp
  - free the stack
  - derefernce to point to temp
  
----------------------
check stack function
----------------------
1. accept  stack_s
2. if stack -> n == STACK return STACK
3. else if stack ->n == QUEUE return QUEUE
4. else return -1

----------------------
strtoken function 
----------------------

----------------------
get opcode function 
----------------------

----------------------
opcode function 
----------------------
-->