#include<stdio.h>
using namespace std;
int main()
{
	int arr[6] = {0,4,8,12,16,20};
	int n = 6;
	int k = 4;
/*	int l = 0;
	for(int i=0;i<n-1;i++)
	{
		l = i+1;
		while(l < n && arr[l]-arr[i] <= k)
		{
			if((arr[l]-arr[i]) == k)
				printf("%d %d\n",arr[l],arr[i]);	
			l++;	
		}
	} */
	int i;
	for(i=0;i<n-1;i++)
	{
		int l = i+1;
		int h = n-1;
		int sum = arr[i] + k;
		while(l <= h)
		{
			int mid = (l+h)/2;
			if(arr[mid] == sum)
			{
				printf("%d %d\n",arr[i],arr[mid]);
				break;
			}
			else if(mid < sum)
				h = mid-1;
			else
				l = mid+1;
			
		}
	}

}
