#include <stdio.h>
#include <string.h>
int main(void)
{
 int len;
 char jesse[] = "Jesse & ";
 char polly[] = "Ngina";
 strcat(jesse, polly);
 printf("%s\n", jesse);
 strcpy(jesse, polly);
 printf("%s\n", jesse);
 len = strlen(jesse);
 printf("%d", len);
 return 0;
}