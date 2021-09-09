# Memory Address in C

High Addresses ---> .----------------------.
| Environment |
|----------------------|
| | Functions and variable are declared
| STACK | on the stack.
base pointer -> | - - - - - - - - - - -|
| | |
| v |
: :
. . The stack grows down into unused space
. Empty . while the heap grows up.
. .
. . (other memory maps do occur here, such
. . as dynamic libraries, and different memory
: : allocate)
| ^ |
| | |
brk point -> | - - - - - - - - - - -| Dynamic memory is declared on the heap
| HEAP |
| |
|----------------------|
| BSS | Uninitialized data (BSS)
|----------------------|  
 | Data | Initialized data (DS)
|----------------------|
| Text | Binary code
Low Addresses ----> '----------------------'

## Segments of the Memory layout

1. Stack
2. Heap
3. BSS (Uninitialized data segment)
4. DS (Initialized data segment)
5. Text

## Stack

It is **located** at a higher address and grows and shrinks opposite to the heap segment.
The stack contains local variables froms functions and related book-keeping data.
A stack frame will create in the stack when a function is called.
The stack contains a LIFO(last in first out) structure. Function variables are pushed onto the stack when called and functions variables are popped off the stack when returned.
Each function has one stack frame.
SP(stackpointer)register tracks the top of the stack.

Example
#include <stdio.h>
int main(void)
{
int data; //local variable stored in stack
return 0;
}

## Heap

It is used to allocate the memory at run time.
Heap area managed by the memory management funtions like malloc, calloc, etc which may internally use the brk and sbrk system calls to adjust its size.
The heap area is shared by all libraries and dynamically loaded modules in aprocess.
It grows and shrinks in the opposite direction of the stack.

Example
int main(void)
{
char *pStr = malloc(sizeof(char)*4); //stored in heap
return 0;
}

## BSS(Uninitialized data segment)

It contains all unitialized global and static variables.
All variables in this segment intialized by the zero(0) and pointer with the null pointer.
The progrm loaer allocaates memory or the BSS section when it loads the program.

Example:
#include <stdio.h>
int data1; //uninitialized global variable stored in BSS
int main(void)
{
static int data2; //uninitialized static variable stored in BSS
return 0;
}

## DS(initialized data segment)

Contains the explicitly intialized global and static variables.
The size of this segment is determined by the size of the values in the program's source code and does not change at run time.
It has read-write permission so the value of the variable of this segment can be changed at run time.
This segment can be further classified into an initialized read-only area and an initialized read-write area.

Example
#include <stdio.h>
int data1 = 10; // initialized global variable stored in DS
int main(void)
{
static int data2 = 3; // Initialized static variable stored in DS
return 0;
}

## Text

Contains a binary of the compiled program.
It is a read-only segment that prevents a progrm from being accidentally modified.
It is sharable so that only a single copy needs to be in memory for frequently executed programs such as text editors.

## C Strings

Are 1D array of characters terminated by a null character "\0".

Initialization:
char greeting[] = "Hello";

Examples of functions in C
1
strcpy(s1, s2);

Copies string s2 into string s1.

2
strcat(s1, s2);

Concatenates string s2 onto the end of string s1.

3
strlen(s1);

Returns the length of string s1.

4
strcmp(s1, s2);

Returns 0 if s1 and s2 are the same; less than 0 if s1<s2; greater than 0 if s1>s2.

5
strchr(s1, ch);

Returns a pointer to the first occurrence of character ch in string s1.

6
strstr(s1, s2);

Returns a pointer to the first occurrence of string s2 in string s1.

Example
#include <stdio.h>
#include <string.h>

int main () {

char str1[12] = "Hello";
char str2[12] = "World";
char str3[12];
int len ;

/_ copy str1 into str3 _/
strcpy(str3, str1);
printf("strcpy( str3, str1) : %s\n", str3 );

/_ concatenates str1 and str2 _/
strcat( str1, str2);
printf("strcat( str1, str2): %s\n", str1 );

/_ total lenghth of str1 after concatenation _/
len = strlen(str1);
printf("strlen(str1) : %d\n", len );

return 0;
}

## Pointers in C

Every variable is a memory location and every memory location has its address defined which can be accessed using ampersand(&) operator, which denotes an address in memory.
Example:
#include <stdio.h>

     int main () {

        int  var1;
        char var2[10];

        printf("Address of var1 variable: %x\n", &var1  );
        printf("Address of var2 variable: %x\n", &var2  );

        return 0;
     }

    **Pointer** is a variable whose value is the address of another variable, ie direct address of the memory location.
    You must declare a pointer before using it to store any variable address.
    Pointer declaration:
     type *var-name;
     Valid Pointer declarations:
       int    *ip;    /* pointer to an integer */
       double *dp;    /* pointer to a double */
       float  *fp;    /* pointer to a float */
       char   *ch     /* pointer to a character */

    How to use Pointers
    example:
     #include <stdio.h>

     int main () {

        int  var = 20;   /* actual variable declaration */
        int  *ip;        /* pointer variable declaration */

        ip = &var;  /* store address of var in pointer variable*/

        printf("Address of var variable: %x\n", &var  );

        /* address stored in pointer variable */
        printf("Address stored in ip variable: %x\n", ip );

        /* access the value using the pointer */
        printf("Value of *ip variable: %d\n", *ip );

        return 0;
     }

    Null Pointers
    is a constant with a value of zero defined in several standard libraries.
    Examples:
     #include <stdio.h>

     int main () {

        int  *ptr = NULL;

        printf("The value of ptr is : %x\n", ptr  );

        return 0;
     }

     Pointer Concept
      1	Pointer arithmetic
      There are four arithmetic operators that can be used in pointers: ++, --, +, -

      2	Array of pointers
      You can define arrays to hold a number of pointers.

      3	Pointer to pointer
      C allows you to have pointer on a pointer and so on.

      4	Passing pointers to functions in C
      Passing an argument by reference or by address enable the passed argument to be changed in the calling function by the called function.

      5	Return pointer from functions in C
      C allows a function to return a pointer to the local variable, static variable, and dynamically allocated memory as well.
