#include<stdio.h>
using namespace std;
bool bsearch(int arr[],int n, int val)
{
	int l=0;
	int h=n-1;
	while(l <= h)
	{
		int mid = (l+h)/2;
		if(arr[mid] == val)
			return true;
		else if (arr[mid] < val)
			l = mid+1;
		else
			h = mid-1;
	}
	return false;
}
void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d\t",arr[i]);
}
int main()
{
int arr1[6] = {7,1,5,2,4,6};
int arr2[5] = {3,6,7,8,20}; //small sort
int n = 6;
int m = 5;
int u[n+m];
int i[m];
int j;
int k = 0;
int t = 0;
for(j=0;j<m;j++)
{
	u[k] = arr2[j];
	k++;
};
for(j=0;j<n;j++)
{
	if(bsearch(arr2,m,arr1[j]))
	{
		i[t] = arr1[j];
		t++;
	}
	else
	{
		u[k] = arr1[j];
		k++;
	}
}
printf("union");
print(u,k);
printf("\nintersection");
print(i,t);
}
