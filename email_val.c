#include <stdio.h>
#include <regex.h>
int main ()
 {
   regex_t regex;
   int result;
   char email[100];

   printf("Please enter your email\n");
   scanf("%99s", email);

   const char * pattern = "^[A-Za-z0-9._%+-]+@[A-Za-z0-9]+\\.[A-Za-z]{2,}$";
   result = regcomp(&regex, pattern , REG_EXTENDED | REG_NOSUB);
   if(result)
    {
      printf("Could not compile the regex \n");
      return 1;
    }

    result = regexec(&regex, email, 0, NULL, 0);
    if(!result)
     printf("Email is valid\n");
    else if(result == REG_NOMATCH)
     printf("Not a vaild Email.\n");
    else 
     printf("Regex error met\n");


     regfree(&regex);

    return 0;
 }