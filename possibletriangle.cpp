#include<stdio.h>
using namespace std;
int main()
{
	/*
	//without sort
	int arr[4] = {4,6,3,7};
	int i,j,k;
	for(i=0;i<4-2;i++)
	{
		for(j=i+1;j<4-1;j++)
		{
			for(k=j+1;k<4;k++)
			{
				if((arr[i]+arr[j] > arr[k]) && (arr[j]+arr[k] > arr[i]) && (arr[i]+arr[k] > arr[j]))
					printf("%d %d %d \n",arr[i],arr[j],arr[k]);
			}

		}
	} */
	int n = 7;
	int arr[7] = {10,21,22,100,101,200,300};
	int i,j,k,count = 0;
	for(i=0;i<n-2;i++)
	{
		k=i+2;
		for(j=i+1;j<n-1;j++)
		{
			while(k < n && arr[k] < (arr[i] + arr[j]))
			{
				if(j != k)
					printf("%d %d %d\n",arr[i],arr[j],arr[k]);
				k++;
			}
			count = count + (k-j-1);	
		}
	}
	printf("\ncount %d" ,count);
}
