#include<stdio.h>
using namespace std;
void findpeak(int arr[], int l, int h,int n)
{
	int mid = (l+h)/2;
	if((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid+1] <= arr[mid])) 
	{
		printf("%d\n",arr[mid]);
		return;
	}	
	else if((mid > 0) && (arr[mid] < arr[mid-1]))
		findpeak(arr,l,(mid-1),n);
	else
	       findpeak(arr,(mid+1),h,n);	


}
int main()
{
	int n =8;
	int i;
	int arr[8] = {5,10,20,15,2,23,90,67};
	findpeak(arr,0,n-1,n);
/*	for(i = 0; i < n; i++)
	{
		if((i-1 >= 0) && (i+1 < n))
		{
			if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1])
			       printf("%d\n",arr[i]);	
		}
		else if((i-1 < 0) && (arr[i] > arr[i+1]))
				printf("%d\n",arr[i]);
		else if((i+1 == n) && (arr[i-1] < arr[i]))
	       			printf("%d\n", arr[i]);	
	}
*/			
}
