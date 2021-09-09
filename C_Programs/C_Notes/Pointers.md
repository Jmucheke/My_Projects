## Pointers

### Types and memory

Sizes of the most common types on most 64-bit:
char -> 1 byte
int -> 4 bytes
float -> bytes

To check the size of a variable we use the _sizeof_ function.
Snippet example:
printf("size of type 'char' on my computer is: %lu bytes\n", sizeof(char));

We use the "address-of unary operator" (&) to know what is the address of a variable.
Snippet example:
char c;
printf("Address of variable 'c': %p\n", $c);
// We use %p to print addresses(the values of pointers) with pointers.

### Storing memory addresses

We can store an address in a pointer.
**A Pointer** is simply the address of data in memory. It is a variable that stores the address of that piece of data.

Declaration of a pointer:
var*type \_var;
Example:
/* ptr2 is a pointer to a char */
char *ptr2;

### Dereferencing

Is the manipulation of values stored at the memory address that pointers point to. We use the dereference operator \*.

program to deference pointers:
#include <stdio.h>

    /**
    * main - dereferencing pointers
    *
    * Return: Always 0.
    */
    int main(void)
    {
    int n;
    int *p;

    n = 98;
    p = &n; // P takes the address of n i.e *p == n
    printf("Value of 'n': %d\n", n);
    printf("Address of 'n': %p\n", &n);
    printf("Value of 'p': %p\n", p);
    *p = 402;
    printf("Value of 'n': %d\n", n);
    return (0);
    }

### Functions parameters are passed by value

When a function is called, the parameters are copied.
Example:
#include <stdio.h>

    /**
    * modify_my_param - this funtion does not modify n
    * @n: a useless integer
    *
    * Return: nothing.
    */
    void modify_my_param(int m)
    {
    m = 402;
    }

    /**
    * main - parameters are passed by value
    *
    * Return: Always 0.
    */
    int main(void)
    {
    int n;
    n = 98;
    modify_my_param(n);
    return (0);
    }

We can modify a variable from outside the function it is declared using a pointer.
Example:
#include <stdio.h>

        /**
        * modify_my_param2 - set the integer to 402
        * @m: a pointer the integer we want to set to 402
        *
        * Return: nothing
        */
        void modify_my_param2(int *m)
        {
        printf("Value of 'm': %p\n", m);
        printf("Address of 'm': %p\n", &m);
        *m = 402;
        }

        /**
        * main - how to change the value of a varianle from outside the funtion
        * it is declared in, using a pointer.
        *
        * Return: Always 0.
        */
        int main(void)
        {
        int n;
        int *p;

        p = &n;
        n = 98;
        printf("Value of 'n' before the call: %d\n", n);
        printf("Address of 'n': %p\n", &n);
        printf("Value of 'p': %p\n", p);
        printf("Address of 'p': %p\n", p);
        modify_my_param2(p);
        printf("Value of 'n' after the call: %d\n", n);
        return (0);
        }

        **NOTE**
        1 When we call the funtion modify_my_param, the value of p is stored in a new variable called m.
        2 Since m stores the same memory address, it points to the same address, and so botj p and m now point to n. Therefore , when we execute the line *m = 402; we modify the value of n and n now holds 402.
        3 When we leave the function modif_my_param2, the variable , is destroyed , but n's value is still 402.
