// characters is not maintained in this program
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
 
/* Function to remove duplicates in a sorted array */
char *removeDupsSorted(char *str)
{
    int i=0;
    int k = 0;
    int j = i+1;
    while(*(str+i) != '\0')
    {
        *(str+k) = *(str+i);
        while(*(str+j) != '\0' && *(str+i) == *(str+j))
           j++;
        i = j;
        j++;
        k++;
    }
    *(str+k) = '\0';
    return str;
}
 
/* Function removes duplicate characters from the string
   This function work in-place and fills null characters
   in the extra space left */
char *removeDups(char *str)
{
   int n = strlen(str);
 
   // Sort the character array
   sort(str, str+n);
 
   // Remove duplicates from sorted
   return removeDupsSorted(str);
}
 
/* Driver program to test removeDups */
int main()
{
  char str[] = "geeksforgeeks";
  cout << removeDups(str);
  cout << "\n";
  return 0;
}
