#include<stdio.h>
using namespace std;
int main()
{
	int arr1[6] = {1,5,10,20,40,80};
	int arr2[5] = {6,7,20,80,100};
	int arr3[8] = {3,4,15,20,30,70,80,120};
	int n = 6;
	int m = 5;
	int p = 8;
	int i = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	while(i < (m+n+p))
	{
		if( a < n && b < m && c < p)
		{	
			if(arr1[a] == arr2[b] && arr2[b] == arr3[c])
			{
				printf("%d\n",arr1[a]);
				a++;
				b++;
				c++;
			}
			else if(arr1[a] < arr2[b] && arr1[a] < arr3[c])
				a++;
			else if(arr2[b] < arr1[a] && arr2[b] < arr3[c])
				b++;
			else if(arr3[c] < arr1[a] && arr3[c] < arr2[b])
				c++;
		}
		else
		{
			break;
		}
		i++;
	}
}
