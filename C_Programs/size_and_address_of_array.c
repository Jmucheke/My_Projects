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