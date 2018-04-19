#include<stdio.h>
using namespace std;
int lb(int arr[],int n,int x)
{
	int l = 0;
	int h = n-1;
	int mid;
	while(l < h)
	{
		mid = (l+h)/2;
		if(arr[mid] < x)
			l = mid;
		else if( arr[mid] >= x)
			h = mid-1;
	}
	return l;
}
int ub(int arr[],int n,int x)
{
 	int l = 0;
	int h = n-1;
	int mid;
	while(l < h)
	{
		mid = (l+h)/2;
		if(arr[mid] > x)
			h = mid;
		else if(arr[mid] <= x)
			l = mid+1;
	}
	return l;
}
void pairs(int x[],int n,int y[],int m)
{
	int count = 0;
	for(int i=0; i<n; i++)
	{
		int r = ub(y,m,x[i]);
		if( r != -1)
		{
			count = count + (m - r); 
		}
	}
	printf("count = %d\n",count);
}
int main()
{
	int arr[4] = {1,2,2,3};
	int a = 2;
	int n = 4;
	printf("upperbound index %d\n",ub(arr,n,a));
        printf("lowerbound index %d\n",lb(arr,n,a));
/*	int x[3] = {2,1,6}; 
	int y[2] = {1,5};
	pairs(x,3,y,2); */
}
