// An efficient C++ program to remove all spaces
// from a string
#include <iostream>
using namespace std;
 
// Function to remove all spaces from a given string
void removeSpaces(char *str)
{
    int i = 0;
    int j = 0;
    while(*(str+i) != '\0')
    {
        while(*(str+i) == ' ' || *(str+i) == '\t')
           i++;
       *(str+j) = *(str+i);
       j++;
       i++;
    }
    *(str+j) = '\0';
}
 
// Driver program to test above function
int main()
{
    char str[] = "g  eeks   for ge  eeks  ";
    removeSpaces(str);
    cout << str;
    return 0;
}
