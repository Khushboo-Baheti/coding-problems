#include<stdio.h>
using namespace std;
int main()
{
	int arr[6] = {1,1,1,1,1,1};
	int n = 6;
	int l = 0;
	int h = n-1;
	int t = 0;
	while(l <= h)
	{
		int mid = (l+h)/2;
		if(arr[mid] == 1 && (mid == n-1 || (mid+1 < n && arr[mid+1] == 0)))
		{
			printf("%d\n",mid+1);
			t = 1;
			break;
		}
		else if(arr[mid] == 0)
			h = mid-1;
		else
			l = mid+1;
	}
	if(t == 0)
		printf("0\n");
}
