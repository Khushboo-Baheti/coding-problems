#include<iostream>
#include<stdio.h>
#include<ctype.h>
using namespace std;
void reverse(char *string)
{
    int l = 0;
    int r = strlen(string)-1;
    int x = r;
    char temp;
    while(l < r)
    {
        if(string[l] != string[r] )
        {
            while(string[l] != '\0' && (!isalpha(string[l])))
               l++; 
            while(string[r] != '\0' && (!isalpha(string[r])))
               r--;

            temp = string[l];
            string[l] = string[r];
            string[r] = temp;
        }
        l++;
        r--;
    }
}
int main()
{
    char str[] = "a!!!b.c.d,e'f,ghi";
    cout << "Input string: " << str << endl;
    reverse(str);
    cout << "Output string: " << str << endl;
    return 0;
}
