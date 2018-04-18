#include<stdio.h>
#include<string.h>
using namespace std;
void string_reverse(char *string , int l, int r)
{
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
void reverseWords(char *s)
{
    int n = strlen(s);
   string_reverse(s,0,n-1);
   int start = 0;
    int i = 0;
    while(*(s+i) != '\0')
    {
        if(*(s+i) == ' ')
        {
        string_reverse(s,start,i-1);
        start = i+1;
        }
        if(*(s+i) == '\0')
        {
        string_reverse(s,start,i-1);
        }
        i++;
    }
}
 
 
/* Driver function to test above functions */
int main()
{
  char s[] = "i like this program very much";
  char *temp = s;
  reverseWords(s);
  printf("%s", s);
  return 0;
}
