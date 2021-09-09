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
 printf("value of m is: %d\n", m);
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