#include<stdio.h>
using namespace std;
int main()
{
	int arr[5] = {2,3,3,2,5};
	int n = 5;
	for(int i = 0; i < n; i++)
	{
		arr[i] = arr[i]-1;
	}
	for(int i = 0; i < n;i++)
	{
		arr[arr[i]%n] = arr[arr[i]%n]+n;
	}
	for(int i = 0; i<n; i++)
	{
		printf("%d ---> %d\n",i+1,arr[i]/n);   
	}
}
