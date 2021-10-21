#include <stdio.h>
#include <stdlib.h>

int main()
{
      int i;
      printf("1. All numbers from 1 to 10\n");
      printf("2. EVEN numbers from 1 to 10\n");
      printf("3. ODD numbers from 1 to 10\n");
      printf("Enter your choice : ");
      int n;
      scanf("%d", &n);

      switch (n)
      {
            case 1: 
            for(i = 1; i <= n; i++)
            {
                  printf("%d ", i);
            }
            break;
            
            case 2: 
            for(i = 2; i <= 10; i+=2)
            {
                  printf("%d ", i);
            }
            break;
            
            case 3: 
            for(i = 1; i <= 10; i+=2)
            {
                  printf("%d ", i);
            }
            break;
            
            default: 
            printf("Incorrect Choice\n");
            break; 
      }

      printf("\n");

      return 0;
}
