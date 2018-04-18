#include<stdio.h>
using namespace std;
void printreverse(char *str)
{
    if(*str == '\0')
        return;
    char temp = *str;
    printreverse(++str);
    printf("%c",temp);
}
int main()
{
    char str[6] = {'a','n','k','i','t','\0'};
    printreverse(str);
    printf("\n");
}
