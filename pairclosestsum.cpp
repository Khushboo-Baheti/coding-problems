#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
using namespace std;
int main()
{
	int arr[6]={10,22,28,29,30,40};
	int n = 6;
	int x = 54;
	int l = 0;
	int r = n-1;
	int diff =INT_MAX;
	int i = 0;
	int j = n-1;
	while(l < r)
	{
		if((abs(arr[l]+arr[r])-x)< diff)
		{
			i = l;
			j = r;
			diff = abs((arr[l]+arr[r])-x);
		}
		if(arr[l] + arr[r] < x)
		l++;
		else
		r--;	
	}
	printf("%d %d \n",arr[i],arr[j]);
}


