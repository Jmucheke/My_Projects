#include <stdio.h>

void modif_my_char(char *cc, char ccc)
{
 printf("Value of '*cc': %c\n", *cc);
 printf("Address of '*cc': %p\n", &*cc);
 printf("Value of 'ccc': %c\n", ccc);
 printf("Address of 'ccc': %p\n", &ccc);
 *cc = 'o';
 ccc = 'l';
}

int main(void)
{
 char c;
 char *p;

 p = &c;
 c = 'H';
 printf("Value of 'c': %c\n", c);
 printf("Address of 'c': %p\n", &c);
 printf("Value of 'p': %p\n", p);
 printf("Address of 'p': %p\n", &p);
 modif_my_char(p, c);
 printf("Value of 'p': %p\n", p);
 printf("Value of 'c': %c\n", c);
 return (0);
}