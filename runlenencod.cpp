
#include<stdio.h>
#include<map>
#include<string.h>
#include<stdlib.h>
using namespace std;
/* Returns the Run Length Encoded string for the 
   source string src */
char *encode(char *src)
{     
    char arr[200];
    int n = strlen(src);
    char *str = (char *) malloc(sizeof(char)*(n*2 + 1));
    int i = 0;
    int j = 0;
    while(i < n)
    {
        int count = 1;
        *(str+j) =  *(src+i);
        j++;
        while(i+1 < n && *(src+i) == *(src+i+1))
        {
            count++;
            i++;
        }
        sprintf(arr, "%d", count);
        int k =0 ;
        while(*(arr+k) != '\0')
        {
            *(str+j) =  *(arr+k);
            j++;
            k++;
        }
        i++;
    }
     *(str+j) =  '\0';
   return str;
} 
/*driver program to test above function */
int main()
{
    char str[] = "geeksforgeeks";    
    char *res = encode(str);
    printf("%s\n", res);
   // getchar();
}
