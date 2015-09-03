#include <stdio.h>

int main()
{
   char str1[30], str2[30];
   printf("Enter name: ");
   fgets(str1,30,stdin);

   printf("Enter your website name: ");
   scanf("%s", &str2);

   printf("Entered Name: %s\n", str1);
   printf("Entered Website:%s", str2);

   return(0);
}
