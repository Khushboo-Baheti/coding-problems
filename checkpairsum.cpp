#include<stdio.h>
using namespace std;
int main()
{
    int arr[6]= {1,4,6,8,10,45};
    int n = 6;
    int sum = 16;
    int l = 0;
    int r = n-1;
    while(l < r)
    {
        if(sum == (arr[l]+arr[r]))
            printf("%d  %d\n",arr[l],arr[r]);
        if((arr[l]+arr[r]) > sum )
            r--;
        else
            l++;
    } 
}
