#include<stdio.h>
using namespace std;
int main()
{
	int arr[11] = {3,5,7,9,10,90,100,130,140,160,170};
	int val = 10;
	int l = 0;
	int h = 2;
	int i =2;
	while(l <= h)
	{
		int mid = ((l+h) /2);
		if(arr[mid] == val)
		{
			printf("%d\n",arr[mid]);
			break;
		}
		else if(arr[mid] > val )
			h = mid-1;
		else if(arr[h] < val)
		{
			l = h;
			i = i * 2;
			h = i;
		}
		else
			l = mid+1;
	}
}
