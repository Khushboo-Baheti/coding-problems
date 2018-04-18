#include <stdio.h>
#include <string.h>
#include<stdlib.h>
using namespace std;
bool arekAnagram(char *str1, char *str2,int k)
{
    int count[26] = {0};
    int n = strlen(str1);
    int m = strlen(str2);
    if(n != m)
        return 0;
    int i = 0;
    while(*(str1+i) != '\0' && *(str2+i) != '\0')
    {
            count[*(str1+i) - 'a']++;
            count[*(str2+i) - 'a']--;
            i++;
    }  
    //for(int p =0 ;p < 26; p++)
      //  printf("%d",count[p]);
    //printf("\n");
    int c = 0;
    i = 0;
    while(*(str1+i) != '\0')
     {
         if(count[*(str1+i)- 'a'] > 0)
         {
             c = c + (abs(count[*(str1+i) - 'a']));
             count[*(str1+i)- 'a'] = 0;
        }
         i++;
     }
     return(c <= k);
}


/* Driver program to test to print printDups*/
int main()
{
    char str1[] = "anagram";
    char str2[] = "gremmer";
    int k = 3;
    if (arekAnagram(str1, str2, k))
      printf("The two strings are anagram of each other");
    else
      printf("The two strings are not anagram of each other");

    return 0;
}





