### Arrays

Are contiguous memory areas that hold a number of values of the same type. All elemts of an array have the same type unlike some other languages.
array syntax
var_name[number_of elements];
Example
int t[5];

### Pointers vs Arrays

an array is not a pointer, the variables we declare as arrays do not hold a memory address.
When we declare an array, we use a name to refer to it, but it is only a name. Array names are identifier that identify the entire array object. They are not pointers to anything. That is why we cannot change the value of a 'variable' which is an array.

**NOTE**
We can still use the name of the array in your code and its value will be the address of the first element of the array.
Example:
#include <stdio.h>

/\*\*
_ main - An array is not a pointer, but...
_ Return: Always 0.
\*/
int main(void)
{
int a[98];
printf("a: %p\n", a);
printf("&a[0]: %p\n", &a[0]);
return (0);
}

When the name of an array is used in an expression, the array type gets automatically implicitly converted to pointer-to-element type in almost all contexts(this is often referred to as "array type decay"). The resultant pointer is a completely independent temporary value, that is the address of the first element of the array.
Example of type decay
#include <stdio.h>
void f(int \*a);

/\*\*
_ main - Illustrating the array type decay
_
_ Return: Always 0.
_/
int main(void)
{
int \*p;
int t[10];

    p = t; /*This works because of the auto implicit conversion t0 (int *) */
    printf("t: %p\n", t);
    printf("&t[0]: %p\n", &t[0]);
    printf("p: %p\n", p);
    f(t);
    return (0);

}

/\*\*
_ f - prints the value of a pointer of type int
_ @a: address of an integer we need to print \*
_ Return: nothing.
_/
void f(int \*a)
{
printf("a: %p\n", a);
return;
}

**\_EXCEPTIONS**_
When the array name is an operand of sizeof or unary & (address-of), the name of the array then refers to the array object itself.
**sizeof**
The name of the aaray refers to the array object itself(composed of all its elements). Thus, \_sizeof_ an array will give you the amount of memory space used by all its elements.
Example
#include <stdio.h>

/\*\*

- main - printing the sizeof an array
-
- Return: Always 0.
  \*/
  int main(void)
  {
  int array[10];
  printf("sizeof array: %lu\n", sizeof(array));
  return (0);
  }

**&**
the name of the array refers to the array object itself(composed of all its elements). So the _address-of_ the array name will give you the address of the value of the whole array, which is the same as the address of its first element.
Example
#include <stdio.h>

    /**
     * main - prints the address of an array
     *
     * Return: Always 0.
     */
    int main(void)
    {
     char b[98];

     printf("b: %p\n", b);
     printf("&b: %p\n", &b);
     return (0);
    }

    As a consequence, the value of b is the same as the value of &b. But they do not have the same type:
     b: in this context, general rule applies, so using b will be evaluated as the address of the first element of the array. Thus, b is of type char*.
     &b: in this context (one of the two exceptions to the general rule). b will be evaluated as the array object itself so b is of type char[98] - an array of 98 characters - and then &b is of type char(*)[98], a pointer to an array of 98 characters.
     This is important because when we will manipulate those two pointers, they will behave differently, since the size of their type is different:
       sizeof b is 98.
       sizeof &b is 8,(if you're using a regular 64 bits machine)(see below).
        #include <stdio.h>

        /**
         * main - prints the size and address of an array
         *
         * Return: Always 0.
         */
        int main(void)
        {
         char b[98];

         printf("b: %p\n", b);
         printf("&b: %p\n", &b);
         printf("size of b: %lu\n", sizeof(b));
         printf("size of &b: %lu\n", sizeof(&b));
         return (0);
        }

### Pointers Arithmetic

Another way to access different elements of an array, is to use another notation: \*(var + x), where var is the name of an array and x is the (x+1)th element(starting countiong elements at 0 of course) of this array. Example:
int i[10];
then, when we will use i in the code, i[5] will be the same as (i + 5). We already know that i is evaluated as a pointer to the first element of the array, since i is an array. But now, we also know that i + 5 will be evaluated as a pointer to the 6th element of the array i.
Example:
#include <stdio.h>

/\*\*

- main - illustrates pointers in arithmetics
-
- Return: Always 0.
  \*/
  int main(void)
  {
  int a[5];

_a = 98; /_ same as _(a+0) or a[0] _/
_(a + 1) = 198;
_(a + 2) = 298;
_(a + 3) = 398;
_(a + 4) = 498;
printf("Value of a[0]: %d\n", _a);
printf("Value of a[1]: %d\n", _(a + 1));
printf("Value of a[2]: %d\n", _(a + 2));
printf("Value of a[3]: %d\n", _(a + 3));
printf("Value of a[4]: %d\n", _(a + 4));
printf("------------------\n");
printf("Value of 'a' (also address of a[0]): %p\n", a);
printf("Address of 'a[1]': %p\n", _(a + 1));
printf("Address of 'a[1]': %p\n", &(\*(a + 1)));
return (0);
}
**Note**
From the output, the value of a is 0060FEEC but the value of a + 1 is 0060FEF0 not 0060FEED.
This is the pointes arithmetic. The computer knows rhat a points to an integer. The computer also knows that the size of an integer in memory is sizeof(int) bytes - in this case 4 bytes - and concludes that the next element of this type will be stored 4 bytes later in memory.

If this works for arrays which are evaluated as pointers in this context, this means that this arithmetic also works for "regular" pointers.
Example:
#include <stdio.h>

/\*\*

- main - pointers arithmetic
-
- Return: Always 0.
  */
  int main(void)
  {
  int *p;
  int a[2];
  int n;

p = &n;
printf("p = &n;\np: %p\n", p);
printf("p + 1: %p\n", p + 1);
printf("p + 2: %p\n", p + 2);
printf("p + 10: %p\n", p + 10);
/_ possible since a is evaluated _/
/_ as an int _ in this context \*/
p = a;
printf("p = a;\np: %p\np + 1: %p\n", p, p + 1);
return (0);
}

**NOTE** one byte = collection of 8 bits

### Strings

We can also create an array of chars. It would work exactly the same way.
Example:
#include <stdio.h>

    /**
    * main - creates an array of chars and prints it
    *
    * Return: Always 0.
    */
    int main(void)
    {
    char a[6];

    *a = 'S';
    *(a + 1) = 'c';
    *(a + 2) = 'h';
    a[3] = 'o';
    *(a + 4) = 'o';
    a[5] = 'l';
    printf("%c%c%c%c%c%c\n", a[0], a[1], a[2], a[3], a[4], a[5]);
    return (0);
    }

    we use an extra character to store a string e.g
      char a[7] = "School"; // 7 characters to store a 6 string character
    because in C, strings end with the char "\0" (ascii value = 0)

Example 2:
#include <stdio.h>

    /**
    * main - prints the value of a string
    *
    * Return: Always 0.
    */
    int main(void)
    {
    char a[7] = "School";

    prints("%s\n", a);
    printf("Value of the last char of a: %d\n", a[9]);
    printf("Value of a: %p\n", a);
    printf("Value of \"School\": %p\n", "School");
    return (0);
    }

    Since every string in C ends with a '\0' we do not need to know their size to use them. By knowing the address of the first character of strings(with a pointer to a char). C functions can easily print them using a loop. One character at a time, untill they hit the character '\0'.
