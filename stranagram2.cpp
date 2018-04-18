// C/C++ program to check whether two strings are anagrams
// of each other
#include <stdio.h>
#include <string.h>
#include<map>
using namespace std;
bool areAnagram(char *str1, char *str2)
{
    map <char,int> m1;
    int i =0 ;
    while(*(str1+i) != '\0')
    {
        if(m1.find(*(str1+i)) != m1.end())
            m1[*(str1+i)]++;
        else
            m1[*(str1+i)] = 1;
        i++;
    }
     i =0 ;
    while(*(str2+i) != '\0')
    {
        if(m1.find(*(str2+i)) != m1.end())
        {
            if(m1[*(str2+i)] >= 1)
            m1[*(str2+i)]--;
            else
                return 0;
        }
        else
        {
                return 0;
        }
        i++;
    }
     i = 0 ;
        while(*(str2+i) != '\0')
    {
        if(m1.find(*(str2+i)) != m1.end())
            if(m1[*(str2+i)] != 0)
                return  0;
        i++;
    }

    return 1;
}
 
 
/* Driver program to test to print printDups*/
int main()
{
    char str1[] = "listen";
    char str2[] = "silent";
    if (areAnagram(str1, str2))
      printf("The two strings are anagram of each other");
    else
      printf("The two strings are not anagram of each other");
 
    return 0;
}
