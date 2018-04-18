#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
void string_reverse1(char *string)
{
    int l = 0;
    int r = strlen(string)-1;
    int x = r;
    char temp;
    while(l < r)
    {
        if(string[l] != string[r])
        {
            temp = string[l];
            string[l] = string[r];
            string[r] = temp;
        }
        l++;
        r--;
    }
}
char *string_reverse2(const char *string)
{
    int n = strlen(string);
    static char *str = (char *)malloc(sizeof(char)*(n+1));
    char *temp = str;
    int i = n-1;
    while(i >= 0)
    {
        *temp = string[i];
        i--;
        temp++;
    }
    *temp = '\0';
    return str;
} 
int main()
{
    char str[6] = {'h','e','l','l','o','\0'};
    printf("%s\n",str);
    string_reverse1(str);
    char *res = string_reverse2(str);
    printf("%s\n",str);
    printf("result : %s\n",res);
    return 0;
}
