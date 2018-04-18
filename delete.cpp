#include<stdio.h>
using namespace std;
int main()
{
	int arr[5] = {3,1,2,5,90};
	int x = 2;
	int n = 5;
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i] == x)
		{
			while(i+1 < n)
			{
				arr[i] = arr[i+1];
				i++;
			}
			arr[i] = '\0';
		}
	}
	for(i = 0; i<n; i++)
	{
		printf("%d\t",arr[i]);
	}
}
