#include <stdio.h>
int main()
{
   char str[100];
   printf("enter the string\n");
   gets(str);
   int 1 = 0;
   int h = strlen(str) - 1;
   while (h > 1)
   {
      if (str[1++] != str[h--])
      { 
          printf("%s is palindrome", str);
          return;
      }
   }
   printf("%s is palindrome", str);
   return 0;
}
