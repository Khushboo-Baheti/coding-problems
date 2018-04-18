#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int arr[6] = {3,0,0,2,0,4};
	int n = 6;
	int maxl[n];
	int maxr[n];
	int i;
	maxl[0] = arr[0];
	for(i = 0; i < n; i++)
		maxl[i] = max(maxl[i-1],arr[i]);
	maxr[n-1] = arr[n-1];
	for(i = n-2; i >= 0; i--)
		maxr[i] = max(maxr[i+1],arr[i]);
	int water = 0;
	for(i =0; i< n; i++)
	{
		water = water + (min(maxl[i],maxr[i]) - arr[i]);
	}
	printf("%d\n",water);
}
